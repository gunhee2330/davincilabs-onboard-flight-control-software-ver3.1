/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UAM_Flight_control_private.h
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

#ifndef UAM_Flight_control_private_h_
#define UAM_Flight_control_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "UAM_Flight_control_types.h"
#include "UAM_Flight_control.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong/long check: insufficient preprocessor integer range. */

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void UAM_Flight_c_MATLABFunction(real_T rtu_rollSP, real_T rtu_pitchSP,
  real_T rtu_airSpeed, real_T *rty_rSP);
extern void UAM_Flight_MATLABFunction_a(real_T rtu_phi, real_T rtu_theta, real_T
  rty_y[9]);
extern void U_SwitchCaseActionSubsystem(FixedWingCtrlBus *rty_FixedWingControls,
  P_SwitchCaseActionSubsystem_U_T *localP);
extern void SwitchCaseActionSubsystem1(uint8_T rtu_TransitionDone,
  FixedWingCtrlBus *rty_FixedWingControls, P_SwitchCaseActionSubsystem1__T
  *localP);
extern void SwitchCaseActionSubsystem2(real_T rtu_FixedWingActuators, real_T
  rtu_FixedWingActuators_o, real_T rtu_FixedWingActuators_oe, real_T
  rtu_FixedWingActuators_of, FixedWingCtrlBus *rty_FixedWingControls);
extern void UAM_F_MATLABFunction_k_Init(DW_MATLABFunction_UAM_Fligh_p_T *localDW);
extern void UAM__MATLABFunction_p_Reset(DW_MATLABFunction_UAM_Fligh_p_T *localDW);
extern void UAM_Flight_MATLABFunction_m(real_T rtu_thrust_in, real_T rtu_vz,
  real_T rtu_az, boolean_T rtu_active, real_T *rty_hover_est,
  DW_MATLABFunction_UAM_Fligh_p_T *localDW);
extern void UAM_Flight_MATLABFunction_i(real_T rtu_x, real_T *rty_y);
extern void UAM_Flight_MATLABFunction_b(real_T rtu_u, real_T rtu_expo, real_T
  *rty_y);
extern void SwitchCaseActionSubsystem_m(const FixedWingCtrlBus
  *rtu_FixedWingCtrlBus_Inport_1, real_T *rty_Actuator_Outport_1, real_T
  *rty_Actuator_Outport_1_o, real_T *rty_Actuator_Outport_1_f, real_T
  *rty_Actuator_Outport_1_i, real_T *rty_Actuator_Outport_1_c,
  P_SwitchCaseActionSubsystem_f_T *localP);
extern void UAM_Flight_MATLABFunction_j(const real_T rtu_toWP[3], const real_T
  rtu_fromWP[3], real_T rty_wps[6], real_T *rty_alt);
extern void UAM_F_WaypointFollower_Init(DW_WaypointFollower_UAM_Fligh_T *localDW);
extern void UAM_Flight_WaypointFollower(const real_T rtu_0[4], const real_T
  rtu_1[8], real_T rtu_2, B_WaypointFollower_UAM_Flight_T *localB,
  DW_WaypointFollower_UAM_Fligh_T *localDW);
extern void SwitchCaseActionSubsystem_k(real_T rty_GNCPlan_m[3], real_T
  rtu_pose_n, real_T rtu_states_f, real_T rtu_states_d, real_T rtu_states_m,
  real_T rtu_states_c, real_T rtu_ground, uint8_T *rty_GNCPlan,
  UAVPathManagerBus *rty_GNCPlan_n, UAVPathManagerBus *rty_GNCPlan_p, real_T
  rty_GNCPlan_b[4], real_T rty_GNCPlan_o[3], real_T *rty_GNCPlan_k, real_T
  *rty_GNCPlan_kn, P_SwitchCaseActionSubsystem_p_T *localP);

#endif                                 /* UAM_Flight_control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
