function getXPlaneSensorData_sfunc(block)
    setup(block);
end

function setup(block)
    block.NumInputPorts  = 0;
    block.NumOutputPorts = 9;  

    dims = {
        [1 1],   % 1. GPS Course
        [1 1],   % 2. Ground Speed
        [1 1],   % 3. Airspeed
        [1 3],   % 4. LLA
        [1 3],   % 5. Abb (Body)
        [1 4],   % 6. Quaternion (q) [1x4] 추가
        [1 3],   % 7. Gyro
        [1 3],   % 8. GPS Velocity
        [1 3]    % 9. Abe (ENU)
    };

    for i = 1:9
        block.OutputPort(i).Dimensions   = dims{i};
        block.OutputPort(i).DatatypeID   = 0;
        block.OutputPort(i).Complexity   = 'Real';
        block.OutputPort(i).SamplingMode = 'Sample';
    end

    block.SampleTimes = [0.01 0];
    block.RegBlockMethod('Start',   @Start);
    block.RegBlockMethod('Outputs', @Outputs);
end

function Start(~)
    global global_sock
    if isempty(global_sock)
        global_sock = XPlaneConnect.openUDP('127.0.0.1', 49009);
    end
end

function Outputs(block)
    global global_sock

    refs = {
        'sim/flightmodel/position/local_vx',               
        'sim/flightmodel/position/local_vy',               
        'sim/flightmodel/position/groundspeed',            
        'sim/cockpit2/gauges/indicators/airspeed_kts_pilot',
        'sim/flightmodel/position/latitude',               
        'sim/flightmodel/position/longitude',              
        'sim/flightmodel/position/elevation',              
        'sim/flightmodel/position/local_ax',               
        'sim/flightmodel/position/local_ay',               
        'sim/flightmodel/position/local_az',               
        'sim/flightmodel/position/phi',                    
        'sim/flightmodel/position/theta',                  
        'sim/flightmodel/position/psi',                    
        'sim/flightmodel/position/q',       
        'sim/flightmodel/position/P',                      
        'sim/flightmodel/position/Q',                      
        'sim/flightmodel/position/R',                      
        'sim/time/local_date_days',                        
        'sim/flightmodel/position/local_vz',               
    };

    try
        vals = XPlaneConnect.getDREFs(refs, global_sock);

        % NaN 또는 빈 값을 -1로 치환
        for i = 1:length(vals)
            if iscell(vals)
                if isempty(vals{i}) || any(isnan(vals{i}))
                    vals{i} = -1;
                end
            elseif isnumeric(vals)
                if isnan(vals(i))
                    vals(i) = -1;
                end
            end
        end

    catch
        vals = cell(1, length(refs));
        for i = 1:length(refs)
            vals{i} = -1;
        end
    end

    % 1. GPS Course
    vx = safeVal(vals, 1);
    vy = safeVal(vals, 2);
    vz = safeVal(vals, 19);
    course_rad = atan2(vx, -vz);
    course_deg = mod(rad2deg(course_rad), 360);
    block.OutputPort(1).Data = course_deg;

    % 2. Ground Speed
    block.OutputPort(2).Data = safeVal(vals, 3);

    % 3. Airspeed
    airspeed_kts = safeVal(vals, 4);
    block.OutputPort(3).Data = airspeed_kts * 0.514444;

    % 4. LLA
    lat = safeVal(vals, 5);
    lon = safeVal(vals, 6);
    alt = safeVal(vals, 7);
    block.OutputPort(4).Data = [lat, lon, alt];

    % 5. Abb (Body)
    ax = safeVal(vals, 8); ay = safeVal(vals, 9); az = safeVal(vals, 10);
    abe = [ax; ay; az];
    phi = safeVal(vals, 11); theta = safeVal(vals, 12); psi = safeVal(vals, 13);
    R = angle2dcm(psi, theta, phi, 'ZYX');
    abb = R' * abe;
    block.OutputPort(5).Data = abb(:)';

    % 6. Quaternion (q) 
    quat = safeVal(vals, 14);  
    
    if numel(quat) == 4
        block.OutputPort(6).Data = quat.'; 
    else
        block.OutputPort(6).Data = [-1 -1 -1 -1]; 
    end

    % 7. Gyro
    block.OutputPort(7).Data = [safeVal(vals, 15), safeVal(vals, 16), safeVal(vals, 17)];

    % 8. GPS Velocity
    block.OutputPort(8).Data = [-vz, vx, -vy];

    % 9. Abe (ENU)
    block.OutputPort(9).Data = [-az, ax, -ay];
end

function val = safeVal(vals, idx)
    try
        if iscell(vals) && idx <= length(vals) && ~isempty(vals{idx})
            val = double(vals{idx});  
        elseif isnumeric(vals) && idx <= length(vals)
            val = double(vals(idx));  
        else
            val = -1;
        end
    catch
        val = -1;
    end
end
