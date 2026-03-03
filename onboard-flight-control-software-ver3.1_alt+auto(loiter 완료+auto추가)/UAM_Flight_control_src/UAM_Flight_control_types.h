/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UAM_Flight_control_types.h
 *
 * Code generated for Simulink model 'UAM_Flight_control'.
 *
 * Model version                  : 1.648
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Fri Feb 27 16:23:25 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef UAM_Flight_control_types_h_
#define UAM_Flight_control_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_UAVPathManagerBus_
#define DEFINED_TYPEDEF_FOR_UAVPathManagerBus_

typedef struct {
  uint8_T mode;
  real_T position[3];
  real_T params[4];
} UAVPathManagerBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FCCData_
#define DEFINED_TYPEDEF_FOR_FCCData_

typedef struct {
  real_T roll;
  real_T pitch;
  real_T yaw;
  real_T altitude;
  real32_T target_roll;
  real32_T target_pitch;
  real32_T target_yaw;
  real32_T target_alt;
  real_T latitude;
  real_T longitude;
  real32_T dist_n;
  real32_T dist_e;
  real32_T dist_d;
  uint8_T gps_num_sv;
  real32_T roll_rate;
  real32_T pitch_rate;
  real32_T yaw_rate;
  real_T acc_x;
  real_T acc_y;
  real_T acc_z;
  real_T pressure;
  real_T vel_n;
  real_T vel_e;
  real_T vel_d;
  real_T gndspeed;
  real32_T target_x;
  real32_T target_y;
  real32_T target_z;
  real_T gyro_x;
  real_T gyro_y;
  real_T gyro_z;
  real_T mag_x;
  real_T mag_y;
  real_T mag_z;
  real_T lin_acc_ecef_x;
  real_T lin_acc_ecef_y;
  real_T lin_acc_ecef_z;
  real_T q[4];
  real_T airspeed;
  int16_T voltage;
  int16_T current;
  int16_T soc;
  int16_T temperature;
  int16_T soh;
  uint8_T gcs_link;
  uint8_T rc_link;
  uint8_T flight_mode;
  real_T m[6];
  real_T rc[16];
  real_T rpy_sp[3];
  real_T z[2];
} FCCData;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RotorParameters_
#define DEFINED_TYPEDEF_FOR_RotorParameters_

typedef struct {
  real_T w1;
  real_T w2;
  real_T w3;
  real_T w4;
  real_T c1;
} RotorParameters;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HoverSPBus_
#define DEFINED_TYPEDEF_FOR_HoverSPBus_

typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
  real_T Yaw;
} HoverSPBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FixedWingCommandBus_
#define DEFINED_TYPEDEF_FOR_FixedWingCommandBus_

typedef struct {
  real_T roll;
  real_T pitch;
  real_T yaw;
  real_T airspeed;
} FixedWingCommandBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_AAC_
#define DEFINED_TYPEDEF_FOR_AAC_

typedef struct {
  real_T airspeed;
  real_T altitude;
  real_T course;
  real_T L1;
  real_T climbrate;
} AAC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_controlMode_
#define DEFINED_TYPEDEF_FOR_controlMode_

typedef struct {
  uint8_T lateralGuidance;
  uint8_T airspeedAltitude;
  uint8_T attitude;
  uint8_T manual;
  uint8_T armed;
  uint8_T inTransition;
  uint8_T TransitionCondition;
  uint8_T TransitionStep;
  uint8_T BackTransitionCondition;
  real_T land;
} controlMode;

#endif

#ifndef DEFINED_TYPEDEF_FOR_flightState_
#define DEFINED_TYPEDEF_FOR_flightState_

typedef enum {
  Hover = 0,                           /* Default value */
  Transition,
  FixedWing,
  BackTransition
} flightState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FlightModeType_
#define DEFINED_TYPEDEF_FOR_FlightModeType_

typedef enum {
  Manual = 0,                          /* Default value */
  Auto,
  Emergecny
} FlightModeType;

#endif

#ifndef DEFINED_TYPEDEF_FOR_FixedWingCtrlBus_
#define DEFINED_TYPEDEF_FOR_FixedWingCtrlBus_

typedef struct {
  real_T dA;
  real_T dE;
  real_T dR;
  real_T dT;
} FixedWingCtrlBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GuidanceStates_
#define DEFINED_TYPEDEF_FOR_GuidanceStates_

typedef struct {
  real_T Euler[3];
  real_T pqr[3];
  real_T Ve[3];
  real_T Xe[3];
  real_T course;
  RotorParameters RotorParameters;
  real_T RC[10];
  real_T target[3];
} GuidanceStates;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GdncModeType_
#define DEFINED_TYPEDEF_FOR_GdncModeType_

typedef enum {
  GdncModeType_None = 0,               /* Default value */
  GdncModeType_Start,
  GdncModeType_PreTransition,
  GdncModeType_BackTransition,
  GdncModeType_BackCOMPLETE,
  GdncModeType_WAYPOINT,
  GdncModeType_Stabilize,
  GdncModeType_FIXEDWINGFLIGHT,
  GdncModeType_ORBIT,
  GdncModeType_HOVER_ENTRY,
  GdncModeType_WP,
  GdncModeType_Orbit,
  GdncModeType_ForwardTransition,
  GdncModeType_TransitionStep,
  GdncModeType_FWCOMPLETE,
  GdncModeType_ToLand,
  GdncModeType_Descend,
  GdncModeType_Landcommand,
  GdncModeType_Takeoff
} GdncModeType;

#endif

#ifndef DEFINED_TYPEDEF_FOR_innerLoopCmdsBus_
#define DEFINED_TYPEDEF_FOR_innerLoopCmdsBus_

typedef struct {
  real_T LAP[3];
  real_T HeadingCmd;
  real_T YawCmd;
} innerLoopCmdsBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_juMyODevdATMAXR3fdAKoC_
#define DEFINED_TYPEDEF_FOR_struct_juMyODevdATMAXR3fdAKoC_

typedef struct {
  real_T P_CLIMBRATE;
  real_T P_ALT;
  real_T P_AIRSPD;
  real_T I_AIRSPD;
  real_T D_AIRSPD;
  real_T N_AIRSPD;
  real_T P_FW_ROLL;
  real_T P_FW_PITCH;
  real_T I_FW_PITCH;
  real_T D_FW_PITCH;
  real_T N_FW_PITCH;
  real_T P_FW_ROLLRATE;
  real_T I_FW_ROLLRATE;
  real_T P_FW_PITCHRATE;
  real_T P_FW_YAWRATE;
} struct_juMyODevdATMAXR3fdAKoC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_JA0PJPSn0btjrHlwEkzrx_
#define DEFINED_TYPEDEF_FOR_struct_JA0PJPSn0btjrHlwEkzrx_

typedef struct {
  real_T turningRadius;
  real_T L1;
  real_T transitionRadius;
  real_T minThrottle;
  real_T maxThrottle;
  real_T slewRateThrottle;
  real_T slewRateServos;
  real_T maxPitch;
  real_T minPitch;
  real_T maxRoll;
  real_T minRoll;
  real_T maxRollRate;
  real_T minRollRate;
  real_T maxPitchRate;
  real_T minPitchRate;
  real_T maxClimbRate;
  real_T maxDescendRate;
  real_T stallSpeed;
  real_T cruiseSpeed;
  real_T takeoffSpeed;
  real_T takeoffNavAlt;
  real_T climboutAltMin;
  real_T climboutAlt;
  real_T landingApproachSpeed;
  real_T flarePitch;
  real_T flareAlt;
  real_T landStopVel;
  real_T finalLoiterSpeed;
} struct_JA0PJPSn0btjrHlwEkzrx;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_jpltDuhjXnkWn1F7DEW2qE_
#define DEFINED_TYPEDEF_FOR_struct_jpltDuhjXnkWn1F7DEW2qE_

typedef struct {
  real_T P_ROLL_RATE;
  real_T D_ROLL_RATE;
  real_T N_ROLL_RATE;
  real_T P_PITCH_RATE;
  real_T D_PITCH_RATE;
  real_T N_PITCH_RATE;
  real_T P_YAW_RATE;
  real_T D_YAW_RATE;
  real_T N_YAW_RATE;
  real_T P_ROLL;
  real_T P_PITCH;
  real_T P_YAW;
  real_T P_VX;
  real_T D_VX;
  real_T N_VX;
  real_T P_VY;
  real_T D_VY;
  real_T N_VY;
  real_T P_VZ;
  real_T D_VZ;
  real_T N_VZ;
  real_T P_X;
  real_T P_Y;
  real_T P_Z;
  real_T P_BACK;
  real_T RC_P_ROLL;
  real_T RC_I_ROLL;
  real_T RC_D_ROLL;
  real_T RC_N_ROLL;
  real_T RC_P_PITCH;
  real_T RC_I_PITCH;
  real_T RC_D_PITCH;
  real_T RC_N_PITCH;
  real_T RC_P_YAW;
  real_T RC_I_YAW;
  real_T RC_D_YAW;
  real_T RC_N_YAW;
  real_T RC_P_ROLL_RATE;
  real_T RC_I_ROLL_RATE;
  real_T RC_D_ROLL_RATE;
  real_T RC_N_ROLL_RATE;
  real_T RC_P_PITCH_RATE;
  real_T RC_I_PITCH_RATE;
  real_T RC_D_PITCH_RATE;
  real_T RC_N_PITCH_RATE;
  real_T RC_P_YAW_RATE;
  real_T RC_I_YAW_RATE;
  real_T RC_D_YAW_RATE;
  real_T RC_N_YAW_RATE;
  real_T I_ROLL;
  real_T D_ROLL;
  real_T N_ROLL;
  real_T I_PITCH;
  real_T D_PITCH;
  real_T N_PITCH;
  real_T I_YAW;
  real_T D_YAW;
  real_T N_YAW;
  real_T I_X;
  real_T D_X;
  real_T N_X;
  real_T I_Y;
  real_T D_Y;
  real_T N_Y;
  real_T I_Z;
  real_T D_Z;
  real_T N_Z;
  real_T I_VY;
  real_T I_VX;
  real_T I_VZ;
  real_T I_ROLL_RATE;
  real_T I_PITCH_RATE;
  real_T I_YAW_RATE;
} struct_jpltDuhjXnkWn1F7DEW2qE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nGmILHkzXdduNopEcCRSWH_
#define DEFINED_TYPEDEF_FOR_struct_nGmILHkzXdduNopEcCRSWH_

typedef struct {
  real_T rho;
  real_T CL0;
  real_T CLa;
  real_T CLa_dot;
  real_T CLq;
  real_T CLDe;
  real_T CLDa;
  real_T CDmin;
  real_T K;
  real_T CL_CDmin;
  real_T A1;
  real_T CdDe;
  real_T CdDa;
  real_T CdDr;
  real_T Cm0;
  real_T Cma;
  real_T Cmq;
  real_T CmDe;
  real_T CYb;
  real_T CYp;
  real_T CYr;
  real_T CYDr;
  real_T Clb;
  real_T Clp;
  real_T Clr;
  real_T ClDa;
  real_T ClDr;
  real_T Cnb;
  real_T Cnp;
  real_T Cnr;
  real_T CnDa;
  real_T CnDr;
  real_T dragCoeffMov;
  real_T g;
} struct_nGmILHkzXdduNopEcCRSWH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Kqzfdh58y3XYM0g99APC8B_
#define DEFINED_TYPEDEF_FOR_struct_Kqzfdh58y3XYM0g99APC8B_

typedef struct {
  real_T b;
  real_T AR;
  real_T c;
  real_T e;
  real_T RotorArm1[3];
  real_T RotorArm2[3];
  real_T RotorArm3[3];
  real_T RotorArm4[3];
  real_T Ixx;
  real_T Iyy;
  real_T Izz;
  real_T mass;
  real_T PropDiameter;
  real_T RotorArm5[3];
} struct_Kqzfdh58y3XYM0g99APC8B;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_u2xOoEtpHkUtzKIxOOJ85F_
#define DEFINED_TYPEDEF_FOR_struct_u2xOoEtpHkUtzKIxOOJ85F_

typedef struct {
  real_T RPMMAX;
  real_T tilt_trim;
} struct_u2xOoEtpHkUtzKIxOOJ85F;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_SLaD3ZMLgBBWFjFkkitV0C_
#define DEFINED_TYPEDEF_FOR_struct_SLaD3ZMLgBBWFjFkkitV0C_

typedef struct {
  struct_nGmILHkzXdduNopEcCRSWH aero;
  struct_Kqzfdh58y3XYM0g99APC8B geom;
  struct_u2xOoEtpHkUtzKIxOOJ85F motor;
} struct_SLaD3ZMLgBBWFjFkkitV0C;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_CFqOEKcDN97DaWV6hJRmHG_
#define DEFINED_TYPEDEF_FOR_struct_CFqOEKcDN97DaWV6hJRmHG_

typedef struct {
  real_T w_phi;
  real_T w_theta;
  real_T w_psi;
  real_T w_z;
  real_T l_x;
} struct_CFqOEKcDN97DaWV6hJRmHG;

#endif

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_UAM_Flight_control_T
#define typedef_cell_wrap_UAM_Flight_control_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_UAM_Flight_control_T;

#endif                              /* typedef_cell_wrap_UAM_Flight_control_T */

#ifndef struct_tag_vxlth3EMPLG7CAzUleegd
#define struct_tag_vxlth3EMPLG7CAzUleegd

struct tag_vxlth3EMPLG7CAzUleegd
{
  int32_T isInitialized;
  cell_wrap_UAM_Flight_control_T inputVarSize[3];
  real_T LookaheadDistance;
  real_T WaypointIndex;
  real_T InitYaw;
  real_T FinalYaw;
  real_T NumWaypoints;
  real_T WaypointsInternal[8];
  boolean_T LastWaypointFlag;
  boolean_T StartFlag;
  real_T InitialPose[4];
  real_T LookaheadFactor;
  uint8_T LookaheadDistFlag;
};

#endif                                 /* struct_tag_vxlth3EMPLG7CAzUleegd */

#ifndef typedef_uav_sluav_internal_system_Way_T
#define typedef_uav_sluav_internal_system_Way_T

typedef struct tag_vxlth3EMPLG7CAzUleegd uav_sluav_internal_system_Way_T;

#endif                             /* typedef_uav_sluav_internal_system_Way_T */

#ifndef struct_tag_wDrDFcl7TOMfHPqLOhcgc
#define struct_tag_wDrDFcl7TOMfHPqLOhcgc

struct tag_wDrDFcl7TOMfHPqLOhcgc
{
  int32_T isInitialized;
  real_T NumCircles;
  real_T PrevPosition[3];
  boolean_T StartFlag;
  real_T LookaheadDistance;
  boolean_T SelectTurnDirectionFlag;
  real_T TurnDirectionInternal;
  real_T OrbitCenterInternal[3];
  real_T OrbitRadiusInternal;
  uint8_T OrbitRadiusFlag;
  uint8_T LookaheadDistFlag;
  real_T PrevResetSignal;
};

#endif                                 /* struct_tag_wDrDFcl7TOMfHPqLOhcgc */

#ifndef typedef_uav_sluav_internal_system_Orb_T
#define typedef_uav_sluav_internal_system_Orb_T

typedef struct tag_wDrDFcl7TOMfHPqLOhcgc uav_sluav_internal_system_Orb_T;

#endif                             /* typedef_uav_sluav_internal_system_Orb_T */

#ifndef struct_tag_PNHAOeXMeBDLyeZaJKzdBF
#define struct_tag_PNHAOeXMeBDLyeZaJKzdBF

struct tag_PNHAOeXMeBDLyeZaJKzdBF
{
  real_T a;
  real_T b;
  real_T c;
  real_T d;
};

#endif                                 /* struct_tag_PNHAOeXMeBDLyeZaJKzdBF */

#ifndef typedef_d_quaternion_UAM_Flight_contr_T
#define typedef_d_quaternion_UAM_Flight_contr_T

typedef struct tag_PNHAOeXMeBDLyeZaJKzdBF d_quaternion_UAM_Flight_contr_T;

#endif                             /* typedef_d_quaternion_UAM_Flight_contr_T */

#ifndef struct_tag_rE0p9RRszDGqA6Mm8JUyIH
#define struct_tag_rE0p9RRszDGqA6Mm8JUyIH

struct tag_rE0p9RRszDGqA6Mm8JUyIH
{
  int32_T __dummy;
};

#endif                                 /* struct_tag_rE0p9RRszDGqA6Mm8JUyIH */

#ifndef typedef_c_fusion_internal_frames_NED__T
#define typedef_c_fusion_internal_frames_NED__T

typedef struct tag_rE0p9RRszDGqA6Mm8JUyIH c_fusion_internal_frames_NED__T;

#endif                             /* typedef_c_fusion_internal_frames_NED__T */

#ifndef struct_tag_PnnaIwx6QfMRJiuany93oF
#define struct_tag_PnnaIwx6QfMRJiuany93oF

struct tag_PnnaIwx6QfMRJiuany93oF
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_PnnaIwx6QfMRJiuany93oF */

#ifndef typedef_robotics_slcore_internal_bloc_T
#define typedef_robotics_slcore_internal_bloc_T

typedef struct tag_PnnaIwx6QfMRJiuany93oF robotics_slcore_internal_bloc_T;

#endif                             /* typedef_robotics_slcore_internal_bloc_T */

#ifndef struct_tag_ca7u59acYki0muEU4gGASF
#define struct_tag_ca7u59acYki0muEU4gGASF

struct tag_ca7u59acYki0muEU4gGASF
{
  int32_T isInitialized;
  real_T MissionPointCounter;
  UAVPathManagerBus MissionParams[2];
  UAVPathManagerBus PrevMissionPoint;
  boolean_T MissionStart;
  boolean_T PrevModeStatus;
  boolean_T PoseHoldFlag;
  boolean_T PoseRTLFlag;
  real_T HoldPose[4];
  boolean_T EnableRepeat;
  boolean_T FinalMissionPoint;
};

#endif                                 /* struct_tag_ca7u59acYki0muEU4gGASF */

#ifndef typedef_uav_sluav_internal_system_Pat_T
#define typedef_uav_sluav_internal_system_Pat_T

typedef struct tag_ca7u59acYki0muEU4gGASF uav_sluav_internal_system_Pat_T;

#endif                             /* typedef_uav_sluav_internal_system_Pat_T */

#ifndef struct_tag_Eze2x1Z3d8nruYygLKeJzB
#define struct_tag_Eze2x1Z3d8nruYygLKeJzB

struct tag_Eze2x1Z3d8nruYygLKeJzB
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  real_T AccelerometerNoise;
  real_T GyroscopeNoise;
  real_T GyroscopeDriftNoise;
  real_T LinearAccelerationNoise;
  real_T LinearAccelerationDecayFactor;
  real_T pQw[144];
  real_T pQv[36];
  d_quaternion_UAM_Flight_contr_T pOrientPost;
  boolean_T pFirstTime;
  c_fusion_internal_frames_NED__T pRefSys;
  real_T pSensorPeriod;
  real_T pKalmanPeriod;
  real_T pGyroOffset[3];
  real_T pLinAccelPost[3];
  real_T pInputPrototype[3];
  real_T MagnetometerNoise;
  real_T MagneticDisturbanceNoise;
  real_T MagneticDisturbanceDecayFactor;
  real_T ExpectedMagneticFieldStrength;
  real_T pMagVec[3];
  real_T pInclinationLimit;
};

#endif                                 /* struct_tag_Eze2x1Z3d8nruYygLKeJzB */

#ifndef typedef_fusion_simulink_ahrsfilter_UA_T
#define typedef_fusion_simulink_ahrsfilter_UA_T

typedef struct tag_Eze2x1Z3d8nruYygLKeJzB fusion_simulink_ahrsfilter_UA_T;

#endif                             /* typedef_fusion_simulink_ahrsfilter_UA_T */

#ifndef struct_tag_rjIxem9ZNbPEw52KCgcImD
#define struct_tag_rjIxem9ZNbPEw52KCgcImD

struct tag_rjIxem9ZNbPEw52KCgcImD
{
  int32_T isInitialized;
  cell_wrap_UAM_Flight_control_T inputVarSize[3];
  real_T LookaheadDistance;
  real_T WaypointIndex;
  real_T NumWaypoints;
  real_T WaypointsInternal[6];
  boolean_T LastWaypointFlag;
  boolean_T StartFlag;
  real_T InitialPose[4];
  real_T LookaheadFactor;
  uint8_T LookaheadDistFlag;
};

#endif                                 /* struct_tag_rjIxem9ZNbPEw52KCgcImD */

#ifndef typedef_uav_sluav_internal_system_W_b_T
#define typedef_uav_sluav_internal_system_W_b_T

typedef struct tag_rjIxem9ZNbPEw52KCgcImD uav_sluav_internal_system_W_b_T;

#endif                             /* typedef_uav_sluav_internal_system_W_b_T */

#ifndef struct_tag_YMR6rFOhSCamgU15cjwXe
#define struct_tag_YMR6rFOhSCamgU15cjwXe

struct tag_YMR6rFOhSCamgU15cjwXe
{
  int32_T isInitialized;
  cell_wrap_UAM_Flight_control_T inputVarSize[3];
  real_T LookaheadDistance;
  real_T WaypointIndex;
  real_T InitYaw;
  real_T FinalYaw;
  real_T NumWaypoints;
  real_T WaypointsInternal[8];
  boolean_T LastWaypointFlag;
  boolean_T StartFlag;
  real_T InitialPose[4];
  real_T LookaheadFactor;
  boolean_T SearchFlag;
  uint8_T LookaheadDistFlag;
};

#endif                                 /* struct_tag_YMR6rFOhSCamgU15cjwXe */

#ifndef typedef_uav_sluav_internal_system__by_T
#define typedef_uav_sluav_internal_system__by_T

typedef struct tag_YMR6rFOhSCamgU15cjwXe uav_sluav_internal_system__by_T;

#endif                             /* typedef_uav_sluav_internal_system__by_T */

/* Parameters for system: '<S1977>/Switch Case Action Subsystem' */
typedef struct P_SwitchCaseActionSubsystem_U_T_ P_SwitchCaseActionSubsystem_U_T;

/* Parameters for system: '<S1977>/Switch Case Action Subsystem1' */
typedef struct P_SwitchCaseActionSubsystem1__T_ P_SwitchCaseActionSubsystem1__T;

/* Parameters for system: '<S1176>/Switch Case Action Subsystem2' */
typedef struct P_SwitchCaseActionSubsystem_f_T_ P_SwitchCaseActionSubsystem_f_T;

/* Parameters for system: '<S2699>/Switch Case Action Subsystem' */
typedef struct P_SwitchCaseActionSubsystem_p_T_ P_SwitchCaseActionSubsystem_p_T;

/* Parameters (default storage) */
typedef struct P_UAM_Flight_control_T_ P_UAM_Flight_control_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_UAM_Flight_control_T RT_MODEL_UAM_Flight_control_T;

#endif                                 /* UAM_Flight_control_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
