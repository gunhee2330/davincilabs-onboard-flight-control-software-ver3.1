function [pos_out, vel_out, quat_out, gyro_bias_out, accel_bias_out, ...
          pos_var_out, vel_var_out, P_out, baro_bias_out] = ...
    EKF2_Main(acc, gyro, gps_lat, gps_lon, gps_alt, gps_vel, baro_alt, mag, ...
              quat_prev, vel_prev, pos_prev, gyro_bias_prev, accel_bias_prev, ...
              P_prev, baro_bias_prev, dt, ref_lat, ref_lon, ref_alt)
%% PX4 EKF2 Style Extended Kalman Filter
%% 24-state Error-State EKF Implementation
%% 
%% State Vector (24 states):
%%   [0-2]:   Quaternion error (3 DOF)
%%   [3-5]:   Velocity NED (m/s)
%%   [6-8]:   Position NED (m)
%%   [9-11]:  Gyro bias (rad/s)
%%   [12-14]: Accel bias (m/s^2)
%%   [15-17]: Mag field I (Gauss)
%%   [18-20]: Mag bias B (Gauss)
%%   [21-22]: Wind velocity NE (m/s)
%%   [23]:    Terrain height (m)

%% ========== Parameters (PX4 EKF2 defaults) ==========
EKF2_GYR_NOISE = 0.015;     %% rad/s
EKF2_ACC_NOISE = 0.35;      %% m/s^2
EKF2_GYR_B_NOISE = 0.001;   %% rad/s^2
EKF2_ACC_B_NOISE = 0.01;    %% m/s^3
EKF2_BARO_NOISE = 2.0;      %% m
EKF2_GPS_P_NOISE = 0.5;     %% m
EKF2_GPS_V_NOISE = 0.3;     %% m/s
EKF2_MAG_NOISE = 0.05;      %% Gauss
INNOV_GATE = 5.0;           %% Innovation gate
g = 9.81;                   %% gravity

%% Initialize outputs
quat_out = quat_prev;
vel_out = vel_prev;
pos_out = pos_prev;
gyro_bias_out = gyro_bias_prev;
accel_bias_out = accel_bias_prev;
P_out = P_prev;
baro_bias_out = baro_bias_prev;

%% ========== 1. State Prediction ==========
%% Correct IMU measurements for bias
gyro_corrected = gyro - gyro_bias_prev;
acc_corrected = acc - accel_bias_prev;

%% Quaternion update
q = quat_prev;
omega = gyro_corrected;

%% Quaternion derivative: q_dot = 0.5 * Omega * q
q_dot = 0.5 * [0, -omega(1), -omega(2), -omega(3);
               omega(1), 0, omega(3), -omega(2);
               omega(2), -omega(3), 0, omega(1);
               omega(3), omega(2), -omega(1), 0] * q;

%% Euler integration
quat_pred = q + q_dot * dt;

%% Normalize quaternion
quat_pred = quat_pred / norm(quat_pred);

%% Rotation matrix from body to NED
q0 = quat_pred(1); q1 = quat_pred(2); q2 = quat_pred(3); q3 = quat_pred(4);
R_bn = [q0^2+q1^2-q2^2-q3^2, 2*(q1*q2-q0*q3), 2*(q1*q3+q0*q2);
        2*(q1*q2+q0*q3), q0^2-q1^2+q2^2-q3^2, 2*(q2*q3-q0*q1);
        2*(q1*q3-q0*q2), 2*(q2*q3+q0*q1), q0^2-q1^2-q2^2+q3^2];

%% Velocity prediction (Body accel to NED + gravity)
acc_ned = R_bn * acc_corrected;
vel_pred = vel_prev + (acc_ned + [0; 0; g]) * dt;

%% Position prediction
pos_pred = pos_prev + vel_prev * dt + 0.5 * (acc_ned + [0; 0; g]) * dt^2;

%% ========== 2. Covariance Prediction ==========
%% Process noise
Q = zeros(24, 24);
Q(1:3, 1:3) = eye(3) * EKF2_GYR_NOISE^2 * dt^2;   %% attitude
Q(4:6, 4:6) = eye(3) * EKF2_ACC_NOISE^2 * dt^2;   %% velocity
Q(7:9, 7:9) = eye(3) * EKF2_ACC_NOISE^2 * dt^4/4; %% position
Q(10:12, 10:12) = eye(3) * EKF2_GYR_B_NOISE^2 * dt^2; %% gyro bias
Q(13:15, 13:15) = eye(3) * EKF2_ACC_B_NOISE^2 * dt^2; %% accel bias

%% State transition matrix (simplified)
F = eye(24);
F(4:6, 1:3) = -R_bn * skew(acc_corrected) * dt;   %% vel <- att
F(7:9, 4:6) = eye(3) * dt;                        %% pos <- vel
F(4:6, 13:15) = -R_bn * dt;                       %% vel <- acc_bias
F(1:3, 10:12) = -eye(3) * dt;                     %% att <- gyro_bias

%% Covariance prediction: P = F*P*F' + Q
P_pred = F * P_prev * F' + Q;

%% ========== 3. Measurement Updates ==========
%% 3.1 Barometer Height Fusion
R_baro = EKF2_BARO_NOISE^2;
H_baro = zeros(1, 24);
H_baro(9) = -1;  %% Down position (negative altitude)

%% Innovation
z_baro = -(baro_alt - ref_alt) - baro_bias_prev;  %% observed down position
innov_baro = z_baro - pos_pred(3);
innov_var_baro = H_baro * P_pred * H_baro' + R_baro;

%% Innovation gate check
if abs(innov_baro) < INNOV_GATE * sqrt(innov_var_baro)
    %% Kalman gain
    K_baro = P_pred * H_baro' / innov_var_baro;
    
    %% State update
    dx = K_baro * innov_baro;
    
    %% Apply error state
    quat_pred = quat_pred + 0.5 * [0; dx(1:3)] .* quat_pred;
    quat_pred = quat_pred / norm(quat_pred);
    vel_pred = vel_pred + dx(4:6);
    pos_pred = pos_pred + dx(7:9);
    
    %% Covariance update
    P_pred = (eye(24) - K_baro * H_baro) * P_pred;
end

%% 3.2 GPS Position Fusion
R_gps_pos = EKF2_GPS_P_NOISE^2;

%% LLA to NED conversion
Re = 6378137.0;  %% Earth radius
lat_rad = ref_lat * pi / 180;
dN = (gps_lat - ref_lat) * pi / 180 * Re;
dE = (gps_lon - ref_lon) * pi / 180 * Re * cos(lat_rad);

for i = 1:2
    H_pos = zeros(1, 24);
    H_pos(6+i) = 1;  %% N or E position
    
    if i == 1
        innov_pos = dN - pos_pred(1);
    else
        innov_pos = dE - pos_pred(2);
    end
    
    innov_var_pos = H_pos * P_pred * H_pos' + R_gps_pos;
    
    if abs(innov_pos) < INNOV_GATE * sqrt(innov_var_pos)
        K_pos = P_pred * H_pos' / innov_var_pos;
        dx = K_pos * innov_pos;
        
        quat_pred = quat_pred + 0.5 * [0; dx(1:3)] .* quat_pred;
        quat_pred = quat_pred / norm(quat_pred);
        vel_pred = vel_pred + dx(4:6);
        pos_pred = pos_pred + dx(7:9);
        
        P_pred = (eye(24) - K_pos * H_pos) * P_pred;
    end
end

%% 3.3 GPS Velocity Fusion
R_gps_vel = EKF2_GPS_V_NOISE^2;

for i = 1:3
    H_vel = zeros(1, 24);
    H_vel(3+i) = 1;  %% N, E, D velocity
    
    innov_vel = gps_vel(i) - vel_pred(i);
    innov_var_vel = H_vel * P_pred * H_vel' + R_gps_vel;
    
    if abs(innov_vel) < INNOV_GATE * sqrt(innov_var_vel)
        K_vel = P_pred * H_vel' / innov_var_vel;
        dx = K_vel * innov_vel;
        
        quat_pred = quat_pred + 0.5 * [0; dx(1:3)] .* quat_pred;
        quat_pred = quat_pred / norm(quat_pred);
        vel_pred = vel_pred + dx(4:6);
        pos_pred = pos_pred + dx(7:9);
        
        P_pred = (eye(24) - K_vel * H_vel) * P_pred;
    end
end

%% ========== 4. Baro Bias Estimation ==========
%% Simple bias estimator
alpha_baro = 0.01;  %% Low-pass filter coefficient
baro_meas = -(baro_alt - ref_alt);
baro_bias_out = baro_bias_prev + alpha_baro * (baro_meas + pos_pred(3) - baro_bias_prev);

%% ========== 5. Output ==========
quat_out = quat_pred;
vel_out = vel_pred;
pos_out = pos_pred;
gyro_bias_out = gyro_bias_prev;   %% Bias update can be added
accel_bias_out = accel_bias_prev; %% Bias update can be added
P_out = P_pred;

%% Variance outputs
pos_var_out = [P_out(7,7); P_out(8,8); P_out(9,9)];
vel_var_out = [P_out(4,4); P_out(5,5); P_out(6,6)];

end

%% Helper function: Skew-symmetric matrix
function S = skew(v)
    S = [0, -v(3), v(2);
         v(3), 0, -v(1);
         -v(2), v(1), 0];
end
