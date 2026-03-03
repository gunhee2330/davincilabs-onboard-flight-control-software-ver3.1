/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UAM_Flight_control.c
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

#include "UAM_Flight_control.h"
#include "rtwtypes.h"
#include "UAM_Flight_control_types.h"
#include "UAM_Flight_control_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "zero_crossing_types.h"
#include "rt_defines.h"

/* Named constants for Chart: '<S2669>/Basic Control  Switching' */
#define UAM_Flight_c_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define UAM_Flight_co_IN_BackTransition ((uint8_T)2U)
#define UAM_Flight_contro_IN_FWCOMPLETE ((uint8_T)3U)
#define UAM_Flight_contro_IN_HVCOMPLETE ((uint8_T)5U)
#define UAM_Flight_contro_IN_Transition ((uint8_T)9U)
#define UAM_Flight_control_IN_Althold  ((uint8_T)1U)
#define UAM_Flight_control_IN_FixedWing ((uint8_T)4U)
#define UAM_Flight_control_IN_Loiter   ((uint8_T)6U)
#define UAM_Flight_control_IN_Stablized ((uint8_T)7U)
#define UAM_Flight_control_IN_Start    ((uint8_T)8U)

/* Named constants for Chart: '<S2667>/Guidance Mode Selector' */
#define UAM_Flig_IN_FIXED_WING_WAYPOINT ((uint8_T)5U)
#define UAM_Flight_IN_ForwardTransition ((uint8_T)7U)
#define UAM_Flight__IN_FIXED_WING_ENTRY ((uint8_T)3U)
#define UAM_Flight__IN_FIXED_WING_ORBIT ((uint8_T)4U)
#define UAM_Flight_c_IN_FIXEDWINGFLIGHT ((uint8_T)1U)
#define UAM_Flight_co_IN_TransitionStep ((uint8_T)15U)
#define UAM_Flight_con_IN_PreTransition ((uint8_T)12U)
#define UAM_Flight_cont_IN_BackCOMPLETE ((uint8_T)1U)
#define UAM_Flight_cont_IN_FWCOMPLETE_b ((uint8_T)6U)
#define UAM_Flight_contr_IN_HOVER_ENTRY ((uint8_T)8U)
#define UAM_Flight_contr_IN_Landcommand ((uint8_T)10U)
#define UAM_Flight_control_IN_Descend  ((uint8_T)1U)
#define UAM_Flight_control_IN_Land     ((uint8_T)9U)
#define UAM_Flight_control_IN_Orbit    ((uint8_T)11U)
#define UAM_Flight_control_IN_Stabilize ((uint8_T)2U)
#define UAM_Flight_control_IN_Start_c  ((uint8_T)13U)
#define UAM_Flight_control_IN_Takeoff  ((uint8_T)14U)
#define UAM_Flight_control_IN_ToLand   ((uint8_T)2U)
#define UAM_Flight_control_IN_WP       ((uint8_T)16U)

/* Named constants for Chart: '<S2668>/Basic Control  Switching' */
#define UAM_Flight__IN_BackTransition_a ((uint8_T)1U)
#define UAM_Flight_cont_IN_FWCOMPLETE_k ((uint8_T)2U)
#define UAM_Flight_cont_IN_Transition_o ((uint8_T)7U)
#define UAM_Flight_contr_IN_FixedWing_o ((uint8_T)3U)
#define UAM_Flight_control_IN_HOVER    ((uint8_T)4U)
#define UAM_Flight_control_IN_Start_m  ((uint8_T)6U)

/* Named constants for Chart: '<S3>/Chart1' */
#define UAM_Flight_co_IN_EmergecnyState ((uint8_T)2U)
#define UAM_Flight_contr_IN_ManualState ((uint8_T)3U)
#define UAM_Flight_control_IN_AutoState ((uint8_T)1U)
#define UAM_Flight_control_period      (0.005)

const RotorParameters UAM_Flight_control_rtZRotorParameters = {
  0.0,                                 /* w1 */
  0.0,                                 /* w2 */
  0.0,                                 /* w3 */
  0.0,                                 /* w4 */
  0.0                                  /* c1 */
};                                     /* RotorParameters ground */

const FixedWingCtrlBus UAM_Flight_control_rtZFixedWingCtrlBus = {
  0.0,                                 /* dA */
  0.0,                                 /* dE */
  0.0,                                 /* dR */
  0.0                                  /* dT */
};                                     /* FixedWingCtrlBus ground */

/* Block signals (default storage) */
B_UAM_Flight_control_T UAM_Flight_control_B;

/* Block states (default storage) */
DW_UAM_Flight_control_T UAM_Flight_control_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_UAM_Flight_control_T UAM_Flight_control_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_UAM_Flight_control_T UAM_Flight_control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_UAM_Flight_control_T UAM_Flight_control_Y;

/* Real-time model */
static RT_MODEL_UAM_Flight_control_T UAM_Flight_control_M_;
RT_MODEL_UAM_Flight_control_T *const UAM_Flight_control_M =
  &UAM_Flight_control_M_;

/* Forward declaration for local functions */
static real_T UAM_Flight_control_norm(const real_T x[3]);
static real_T UAM_Flight_control_wrapToPi(real_T theta);

/* Forward declaration for local functions */
static boolean_T UAM_Flig_transitionConditionMet(real_T alpha, real_T
  Vtransition, const GuidanceStates *BusConversion_InsertedFor_Bas_n);
static boolean_T UAM_Flight_con_backConditionMet(real_T alpha, const
  GuidanceStates *states_0);
static real_T UAM_Flight_control_norm_by(const real_T x[3]);
static real_T UAM_Flight_control_wrapToPi_b(real_T theta);
static void UAM_Flight_cont_SystemCore_step(uav_sluav_internal_system__by_T *obj,
  const real_T varargin_1[4], const real_T varargin_2[8], real_T varargin_3,
  real_T varargout_1[3], real_T *varargout_2, real_T *varargout_3, uint8_T
  *varargout_4);
static boolean_T UAM_Flight_cont_backConditioMet(real_T alpha);
static real_T UAM_Flight_control_norm_b(const real_T x[2]);
static real_T UAM_Flight_control_angdiff(real_T x, real_T y);
static void UAM_Flight_con_FIXED_WING_ENTRY(const GuidanceStates
  *BusConversion_InsertedFor_Guida, real_T *rtb_alt_k_0, real_T rtb_wps_h[6]);
static boolean_T UAM_Fl_transitionConditionMet_h(real_T alpha);
static void UAM_Flight_control_Land(const GuidanceStates
  *BusConversion_InsertedFor_Guida, real_T rtb_wps_d[8]);
static void enter_internal_FIXED_WING_ENTRY(void);
static void UAM_Flight_control_Start(const GuidanceStates
  *BusConversion_InsertedFor_Guida, real_T *rtb_alt_k_1, real_T *rtb_alt_0,
  real_T rtb_wps_d[8], real_T rtb_wps_h[6]);
static void UAM_exit_internal_GuidanceLogic(void);
static void UAM_Flight_contro_GuidanceLogic(const uint8_T *mode_prev, const
  GuidanceStates *BusConversion_InsertedFor_Guida);
static real_T UAM_Flight_control_compute_gain(const real_T dir[4], const real_T
  m[4], const real_T act_min[4], const real_T act_max[4]);
static void UAM_Flight_control_desat_axis(real_T m[4], const real_T dir[4],
  const real_T act_min[4], const real_T act_max[4], boolean_T thrust_only_down);
static void UAM_Flight_control_NED_ecompass(const real_T a[3], const real_T m[3],
  real_T R[9]);
static void UAM_Fligh_quaternion_quaternion(const real_T varargin_1[3], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d);
static void UAM_Fligh_quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T r[9]);
static void UAM_Flight_control_mrdiv_b(real_T A[72], const real_T B[36]);
static void UAM_Flight_co_SystemCore_step_b(fusion_simulink_ahrsfilter_UA_T *obj,
  const real_T varargin_1[3], const real_T varargin_2[3], const real_T
  varargin_3[3], real_T varargout_1[4], real_T varargout_2[3]);
static void UAM_Fligh_PathManager_setupImpl(uav_sluav_internal_system_Pat_T *obj);
static void UAM_Fl_AHRSFilterBase_resetImpl(fusion_simulink_ahrsfilter_UA_T *obj);

/*
 * Output and update for atomic system:
 *    '<S1711>/MATLAB Function'
 *    '<S197>/MATLAB Function'
 *    '<S1203>/MATLAB Function'
 */
void UAM_Flight_c_MATLABFunction(real_T rtu_rollSP, real_T rtu_pitchSP, real_T
  rtu_airSpeed, real_T *rty_rSP)
{
  *rty_rSP = tan(rtu_rollSP) * 9.81 / fmax(rtu_airSpeed, 5.0) * cos(rtu_pitchSP)
    * cos(rtu_rollSP);
}

/*
 * Output and update for atomic system:
 *    '<S1701>/MATLAB Function'
 *    '<S24>/MATLAB Function'
 *    '<S1193>/MATLAB Function'
 */
void UAM_Flight_MATLABFunction_a(real_T rtu_phi, real_T rtu_theta, real_T rty_y
  [9])
{
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  tmp = tan(rtu_theta);
  tmp_0 = cos(rtu_phi);
  tmp_1 = sin(rtu_phi);
  tmp_2 = cos(rtu_theta);
  rty_y[0] = 1.0;
  rty_y[3] = tmp_1 * tmp;
  rty_y[6] = tmp_0 * tmp;
  rty_y[1] = 0.0;
  rty_y[4] = tmp_0;
  rty_y[7] = -tmp_1;
  rty_y[2] = 0.0;
  rty_y[5] = tmp_1 / tmp_2;
  rty_y[8] = tmp_0 / tmp_2;
}

/*
 * Output and update for action system:
 *    '<S1977>/Switch Case Action Subsystem'
 *    '<S1977>/Switch Case Action Subsystem3'
 *    '<S1175>/Switch Case Action Subsystem'
 *    '<S1175>/Switch Case Action Subsystem3'
 *    '<S1469>/Switch Case Action Subsystem'
 *    '<S1469>/Switch Case Action Subsystem3'
 */
void U_SwitchCaseActionSubsystem(FixedWingCtrlBus *rty_FixedWingControls,
  P_SwitchCaseActionSubsystem_U_T *localP)
{
  /* BusCreator: '<S1979>/Bus Creator' incorporates:
   *  Constant: '<S1979>/Constant'
   *  Constant: '<S1979>/Constant1'
   *  Constant: '<S1979>/Constant2'
   *  Constant: '<S1979>/Constant3'
   */
  rty_FixedWingControls->dA = localP->Constant_Value;
  rty_FixedWingControls->dE = localP->Constant1_Value;
  rty_FixedWingControls->dR = localP->Constant2_Value;
  rty_FixedWingControls->dT = localP->Constant3_Value;
}

/*
 * Output and update for action system:
 *    '<S1977>/Switch Case Action Subsystem1'
 *    '<S1469>/Switch Case Action Subsystem1'
 */
void SwitchCaseActionSubsystem1(uint8_T rtu_TransitionDone, FixedWingCtrlBus
  *rty_FixedWingControls, P_SwitchCaseActionSubsystem1__T *localP)
{
  /* Switch: '<S1980>/Switch' incorporates:
   *  Constant: '<S1980>/Constant'
   *  Constant: '<S1980>/Constant1'
   *  Constant: '<S1980>/Constant2'
   *  Constant: '<S1980>/Constant3'
   */
  if (rtu_TransitionDone > localP->Switch_Threshold) {
    *rty_FixedWingControls = UAM_Flight_control_rtZFixedWingCtrlBus;
  } else {
    rty_FixedWingControls->dA = localP->Constant_Value;
    rty_FixedWingControls->dE = localP->Constant1_Value;
    rty_FixedWingControls->dR = localP->Constant2_Value;
    rty_FixedWingControls->dT = localP->Constant3_Value;
  }

  /* End of Switch: '<S1980>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S1977>/Switch Case Action Subsystem2'
 *    '<S1469>/Switch Case Action Subsystem2'
 */
void SwitchCaseActionSubsystem2(real_T rtu_FixedWingActuators, real_T
  rtu_FixedWingActuators_o, real_T rtu_FixedWingActuators_oe, real_T
  rtu_FixedWingActuators_of, FixedWingCtrlBus *rty_FixedWingControls)
{
  /* BusCreator: '<S1981>/Bus Creator' */
  rty_FixedWingControls->dA = rtu_FixedWingActuators;
  rty_FixedWingControls->dE = rtu_FixedWingActuators_o;
  rty_FixedWingControls->dR = rtu_FixedWingActuators_oe;
  rty_FixedWingControls->dT = rtu_FixedWingActuators_of;
}

/*
 * System initialize for atomic system:
 *    '<S1989>/MATLAB Function'
 *    '<S521>/MATLAB Function'
 */
void UAM_F_MATLABFunction_k_Init(DW_MATLABFunction_UAM_Fligh_p_T *localDW)
{
  localDW->hover_thrust = 0.5;
}

/*
 * System reset for atomic system:
 *    '<S1989>/MATLAB Function'
 *    '<S521>/MATLAB Function'
 */
void UAM__MATLABFunction_p_Reset(DW_MATLABFunction_UAM_Fligh_p_T *localDW)
{
  localDW->hover_thrust = 0.5;
}

/*
 * Output and update for atomic system:
 *    '<S1989>/MATLAB Function'
 *    '<S521>/MATLAB Function'
 */
void UAM_Flight_MATLABFunction_m(real_T rtu_thrust_in, real_T rtu_vz, real_T
  rtu_az, boolean_T rtu_active, real_T *rty_hover_est,
  DW_MATLABFunction_UAM_Fligh_p_T *localDW)
{
  *rty_hover_est = localDW->hover_thrust;
  if (rtu_active && ((fabs(rtu_vz) < 0.5) && (fabs(rtu_az + 9.81) < 1.0))) {
    real_T err;
    err = rtu_thrust_in - localDW->hover_thrust;
    if (err > 0.0005) {
      localDW->hover_thrust += 0.0005;
    } else if (err < -0.0005) {
      localDW->hover_thrust -= 0.0005;
    } else {
      localDW->hover_thrust = rtu_thrust_in;
    }

    localDW->hover_thrust = fmax(0.2, fmin(0.8, localDW->hover_thrust));
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S1990>/MATLAB Function'
 *    '<S523>/MATLAB Function'
 */
void UAM_Flight_MATLABFunction_i(real_T rtu_x, real_T *rty_y)
{
  *rty_y = rt_atan2d_snf(sin(rtu_x), cos(rtu_x));
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S1992>/MATLAB Function'
 *    '<S1992>/MATLAB Function1'
 */
void UAM_Flight_MATLABFunction_b(real_T rtu_u, real_T rtu_expo, real_T *rty_y)
{
  real_T tmp;
  real_T tmp_0;
  tmp = fabs(rtu_u);
  if (rtIsNaN(rtu_u)) {
    tmp_0 = (rtNaN);
  } else if (rtu_u < 0.0) {
    tmp_0 = -1.0;
  } else {
    tmp_0 = (rtu_u > 0.0);
  }

  *rty_y = ((1.0 - rtu_expo) * tmp + rtu_expo * rt_powd_snf(tmp, 3.0)) * tmp_0;
}

/*
 * Output and update for action system:
 *    '<S1176>/Switch Case Action Subsystem2'
 *    '<S1470>/Switch Case Action Subsystem2'
 */
void SwitchCaseActionSubsystem_m(const FixedWingCtrlBus
  *rtu_FixedWingCtrlBus_Inport_1, real_T *rty_Actuator_Outport_1, real_T
  *rty_Actuator_Outport_1_o, real_T *rty_Actuator_Outport_1_f, real_T
  *rty_Actuator_Outport_1_i, real_T *rty_Actuator_Outport_1_c,
  P_SwitchCaseActionSubsystem_f_T *localP)
{
  real_T u0;

  /* Sum: '<S1184>/Add2' incorporates:
   *  Constant: '<S1184>/Constant1'
   */
  u0 = UAM_Flight_control_P.FWTrimSpeed + rtu_FixedWingCtrlBus_Inport_1->dT;

  /* Saturate: '<S1184>/Saturation2' */
  if (u0 > localP->Saturation2_UpperSat) {
    *rty_Actuator_Outport_1_c = localP->Saturation2_UpperSat;
  } else if (u0 < localP->Saturation2_LowerSat) {
    *rty_Actuator_Outport_1_c = localP->Saturation2_LowerSat;
  } else {
    *rty_Actuator_Outport_1_c = u0;
  }

  /* End of Saturate: '<S1184>/Saturation2' */

  /* SignalConversion generated from: '<S1184>/Constant' incorporates:
   *  Constant: '<S1184>/Constant'
   */
  *rty_Actuator_Outport_1 = localP->Constant_Value;

  /* SignalConversion generated from: '<S1184>/Constant2' incorporates:
   *  Constant: '<S1184>/Constant2'
   */
  *rty_Actuator_Outport_1_o = localP->Constant2_Value;

  /* SignalConversion generated from: '<S1184>/Constant3' incorporates:
   *  Constant: '<S1184>/Constant3'
   */
  *rty_Actuator_Outport_1_f = localP->Constant3_Value;

  /* SignalConversion generated from: '<S1184>/Constant4' incorporates:
   *  Constant: '<S1184>/Constant4'
   */
  *rty_Actuator_Outport_1_i = localP->Constant4_Value;
}

/*
 * Output and update for atomic system:
 *    '<S2674>/MATLAB Function'
 *    '<S2675>/MATLAB Function'
 */
void UAM_Flight_MATLABFunction_j(const real_T rtu_toWP[3], const real_T
  rtu_fromWP[3], real_T rty_wps[6], real_T *rty_alt)
{
  rty_wps[0] = rtu_fromWP[0];
  rty_wps[1] = rtu_toWP[0];
  rty_wps[2] = rtu_fromWP[1];
  rty_wps[3] = rtu_toWP[1];
  rty_wps[4] = rtu_fromWP[2];
  rty_wps[5] = rtu_toWP[2];
  *rty_alt = -rtu_toWP[2];
}

static real_T UAM_Flight_control_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;

  /* Start for MATLABSystem: '<S2676>/Waypoint Follower' */
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  /* Start for MATLABSystem: '<S2676>/Waypoint Follower' */
  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  /* Start for MATLABSystem: '<S2676>/Waypoint Follower' */
  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

static real_T UAM_Flight_control_wrapToPi(real_T theta)
{
  real_T b_theta;
  b_theta = theta;

  /* Start for MATLABSystem: '<S2676>/Waypoint Follower' */
  if (fabs(theta) > 3.1415926535897931) {
    real_T thetaWrap;
    if (rtIsNaN(theta + 3.1415926535897931) || rtIsInf(theta +
         3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (theta + 3.1415926535897931 == 0.0) {
      thetaWrap = 0.0;
    } else {
      boolean_T rEQ0;
      thetaWrap = fmod(theta + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (thetaWrap == 0.0);
      if (!rEQ0) {
        real_T q;
        q = fabs((theta + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        thetaWrap = 0.0;
      } else if (thetaWrap < 0.0) {
        thetaWrap += 6.2831853071795862;
      }
    }

    if ((thetaWrap == 0.0) && (theta + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    b_theta = thetaWrap - 3.1415926535897931;
  }

  /* End of Start for MATLABSystem: '<S2676>/Waypoint Follower' */
  return b_theta;
}

/* System initialize for atomic system: */
void UAM_F_WaypointFollower_Init(DW_WaypointFollower_UAM_Fligh_T *localDW)
{
  /* Start for MATLABSystem: '<S2676>/Waypoint Follower' */
  localDW->obj.LastWaypointFlag = false;
  localDW->obj.StartFlag = true;
  localDW->obj.LookaheadFactor = 1.01;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumWaypoints = 0.0;

  /* InitializeConditions for MATLABSystem: '<S2676>/Waypoint Follower' */
  localDW->obj.WaypointIndex = 1.0;
  memset(&localDW->obj.WaypointsInternal[0], 0, sizeof(real_T) << 3U);
}

/* Output and update for atomic system: */
void UAM_Flight_WaypointFollower(const real_T rtu_0[4], const real_T rtu_1[8],
  real_T rtu_2, B_WaypointFollower_UAM_Flight_T *localB,
  DW_WaypointFollower_UAM_Fligh_T *localDW)
{
  real_T b_waypointsIn_data[8];
  real_T waypoints_data[8];
  real_T b_waypointsIn[3];
  real_T rtu_0_0[3];
  real_T unitVectorUtoV_tmp[3];
  real_T absx_tmp;
  real_T b_endWaypoint_idx_0_tmp;
  real_T b_endWaypoint_idx_1_tmp;
  real_T b_endWaypoint_idx_2_tmp;
  real_T b_startWaypoint_idx_1_tmp;
  real_T b_startWaypoint_idx_2_tmp;
  real_T currentPosition;
  real_T dist;
  real_T lookaheadDist;
  real_T r;
  real_T unitVectorUtoV_tmp_0;
  real_T y;
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T b_k;
  int32_T i;
  int32_T tmp_size_idx_1;
  int32_T waypoints_size_idx_0;
  int8_T tmp_data[2];
  boolean_T x[3];
  boolean_T distinctWptsIdx[2];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T p;
  boolean_T p_0;

  /* MATLABSystem: '<S2676>/Waypoint Follower' */
  lookaheadDist = rtu_2;
  localDW->obj.LookaheadDistFlag = 0U;
  if (rtu_2 < 0.1) {
    lookaheadDist = 0.1;
    localDW->obj.LookaheadDistFlag = 1U;
  }

  localDW->obj.InitialPose[0] = 0.0;
  localDW->obj.InitialPose[1] = 0.0;
  localDW->obj.InitialPose[2] = 0.0;
  localDW->obj.InitialPose[3] = 0.0;
  localDW->obj.NumWaypoints = 2.0;
  p = false;
  p_0 = true;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k <= 7)) {
    i = ((b_k / 2) << 1) + b_k % 2;
    if (!(localDW->obj.WaypointsInternal[i] == rtu_1[i])) {
      p_0 = false;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    memcpy(&localDW->obj.WaypointsInternal[0], &rtu_1[0], sizeof(real_T) << 3U);
    localDW->obj.WaypointIndex = 1.0;
  }

  distinctWptsIdx[1] = true;
  x[0] = (rtu_1[0] != rtu_1[1]);
  x[1] = (rtu_1[2] != rtu_1[3]);
  x[2] = (rtu_1[4] != rtu_1[5]);
  distinctWptsIdx[0] = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 3)) {
    if (x[b_k]) {
      distinctWptsIdx[0] = true;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  b_k = 0;
  for (i = 0; i < 2; i++) {
    /* MATLABSystem: '<S2676>/Waypoint Follower' */
    if (distinctWptsIdx[i]) {
      b_k++;
    }
  }

  tmp_size_idx_1 = b_k;
  b_k = 0;
  for (i = 0; i < 2; i++) {
    /* MATLABSystem: '<S2676>/Waypoint Follower' */
    if (distinctWptsIdx[i]) {
      /* Start for MATLABSystem: '<S2676>/Waypoint Follower' */
      tmp_data[b_k] = (int8_T)i;
      b_k++;
    }
  }

  /* MATLABSystem: '<S2676>/Waypoint Follower' */
  for (i = 0; i < 4; i++) {
    for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
      b_waypointsIn_data[b_k + tmp_size_idx_1 * i] = rtu_1[(i << 1) +
        tmp_data[b_k]];
    }
  }

  localDW->obj.LookaheadDistance = lookaheadDist;
  if (tmp_size_idx_1 == 0) {
    localB->LAP[0] = rtu_0[0];
    localB->LAP[1] = rtu_0[1];
    localB->LAP[2] = rtu_0[2];

    /* MATLABSystem: '<S2676>/Waypoint Follower' */
    localB->HeadingCmd = rtu_0[3];
    localB->YawCmd = rtu_0[3];
  } else {
    guard1 = false;
    if (tmp_size_idx_1 == 1) {
      if (localDW->obj.StartFlag) {
        localDW->obj.InitialPose[0] = rtu_0[0];
        localDW->obj.InitialPose[1] = rtu_0[1];
        localDW->obj.InitialPose[2] = rtu_0[2];
        localDW->obj.InitialPose[3] = rtu_0[3];
      }

      b_waypointsIn[0] = b_waypointsIn_data[0] - rtu_0[0];
      b_waypointsIn[1] = b_waypointsIn_data[1] - rtu_0[1];
      b_waypointsIn[2] = b_waypointsIn_data[2] - rtu_0[2];
      if (UAM_Flight_control_norm(b_waypointsIn) < 1.4901161193847656E-8) {
        localB->LAP[0] = rtu_0[0];
        localB->LAP[1] = rtu_0[1];
        localB->LAP[2] = rtu_0[2];

        /* MATLABSystem: '<S2676>/Waypoint Follower' */
        localB->HeadingCmd = rtu_0[3];
        localB->YawCmd = rtu_0[3];
        localDW->obj.StartFlag = false;
      } else {
        localDW->obj.StartFlag = false;
        localDW->obj.NumWaypoints = 2.0;
        waypoints_size_idx_0 = tmp_size_idx_1 + 1;
        waypoints_data[0] = localDW->obj.InitialPose[0];
        waypoints_data[tmp_size_idx_1 + 1] = localDW->obj.InitialPose[1];
        waypoints_data[(tmp_size_idx_1 + 1) << 1] = localDW->obj.InitialPose[2];
        waypoints_data[(tmp_size_idx_1 + 1) * 3] = rtu_1[tmp_data[0] + 6];
        for (i = 0; i < 4; i++) {
          for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
            waypoints_data[(b_k + (tmp_size_idx_1 + 1) * i) + 1] =
              b_waypointsIn_data[tmp_size_idx_1 * i + b_k];
          }
        }

        guard1 = true;
      }
    } else {
      waypoints_size_idx_0 = tmp_size_idx_1;
      b_k = tmp_size_idx_1 << 2;
      if (b_k - 1 >= 0) {
        memcpy(&waypoints_data[0], &b_waypointsIn_data[0], (uint32_T)b_k *
               sizeof(real_T));
      }

      guard1 = true;
    }

    if (guard1) {
      p = false;
      if (localDW->obj.WaypointIndex == 2.0) {
        p = true;
      }

      if (p) {
        localDW->obj.LastWaypointFlag = true;
        localDW->obj.WaypointIndex--;
      }

      localDW->obj.InitYaw = waypoints_data[(waypoints_size_idx_0 * 3 + (int32_T)
        localDW->obj.WaypointIndex) - 1];
      localDW->obj.FinalYaw = waypoints_data[((int32_T)
        (localDW->obj.WaypointIndex + 1.0) + waypoints_size_idx_0 * 3) - 1];
      lookaheadDist = waypoints_data[(int32_T)localDW->obj.WaypointIndex - 1];
      b_endWaypoint_idx_0_tmp = waypoints_data[(int32_T)
        (localDW->obj.WaypointIndex + 1.0) - 1];
      b_waypointsIn[0] = rtu_0[0] - b_endWaypoint_idx_0_tmp;
      b_startWaypoint_idx_1_tmp = waypoints_data[((int32_T)
        localDW->obj.WaypointIndex + waypoints_size_idx_0) - 1];
      b_endWaypoint_idx_1_tmp = waypoints_data[((int32_T)
        (localDW->obj.WaypointIndex + 1.0) + waypoints_size_idx_0) - 1];
      b_waypointsIn[1] = rtu_0[1] - b_endWaypoint_idx_1_tmp;
      b_startWaypoint_idx_2_tmp = waypoints_data[((waypoints_size_idx_0 << 1) +
        (int32_T)localDW->obj.WaypointIndex) - 1];
      b_endWaypoint_idx_2_tmp = waypoints_data[((int32_T)
        (localDW->obj.WaypointIndex + 1.0) + (waypoints_size_idx_0 << 1)) - 1];
      b_waypointsIn[2] = rtu_0[2] - b_endWaypoint_idx_2_tmp;
      y = UAM_Flight_control_norm(b_waypointsIn);
      guard2 = false;
      if (y <= 1.0) {
        guard2 = true;
      } else {
        unitVectorUtoV_tmp[0] = b_endWaypoint_idx_0_tmp - lookaheadDist;
        unitVectorUtoV_tmp[1] = b_endWaypoint_idx_1_tmp -
          b_startWaypoint_idx_1_tmp;
        unitVectorUtoV_tmp[2] = b_endWaypoint_idx_2_tmp -
          b_startWaypoint_idx_2_tmp;
        currentPosition = UAM_Flight_control_norm(unitVectorUtoV_tmp);
        unitVectorUtoV_tmp_0 = (unitVectorUtoV_tmp[0] / currentPosition *
          (b_waypointsIn[0] / y) + unitVectorUtoV_tmp[1] / currentPosition *
          (b_waypointsIn[1] / y)) + unitVectorUtoV_tmp[2] / currentPosition *
          (b_waypointsIn[2] / y);
        if (rtIsNaN(unitVectorUtoV_tmp_0) || (unitVectorUtoV_tmp_0 < 0.0)) {
        } else {
          guard2 = true;
        }
      }

      if (guard2) {
        localDW->obj.WaypointIndex++;
        p = false;
        if (localDW->obj.WaypointIndex == 2.0) {
          p = true;
        }

        if (p) {
          localDW->obj.LastWaypointFlag = true;
          localDW->obj.WaypointIndex--;
        }

        lookaheadDist = waypoints_data[(int32_T)localDW->obj.WaypointIndex - 1];
        b_endWaypoint_idx_0_tmp = waypoints_data[(int32_T)
          (localDW->obj.WaypointIndex + 1.0) - 1];
        b_startWaypoint_idx_1_tmp = waypoints_data[((int32_T)
          localDW->obj.WaypointIndex + waypoints_size_idx_0) - 1];
        b_endWaypoint_idx_1_tmp = waypoints_data[((int32_T)
          (localDW->obj.WaypointIndex + 1.0) + waypoints_size_idx_0) - 1];
        b_startWaypoint_idx_2_tmp = waypoints_data[((waypoints_size_idx_0 << 1)
          + (int32_T)localDW->obj.WaypointIndex) - 1];
        b_endWaypoint_idx_2_tmp = waypoints_data[((int32_T)
          (localDW->obj.WaypointIndex + 1.0) + (waypoints_size_idx_0 << 1)) - 1];
        localDW->obj.InitYaw = waypoints_data[(waypoints_size_idx_0 * 3 +
          (int32_T)localDW->obj.WaypointIndex) - 1];
        localDW->obj.FinalYaw = waypoints_data[((int32_T)
          (localDW->obj.WaypointIndex + 1.0) + waypoints_size_idx_0 * 3) - 1];
      }

      unitVectorUtoV_tmp_0 = rtu_0[0] - lookaheadDist;
      unitVectorUtoV_tmp[0] = unitVectorUtoV_tmp_0;
      currentPosition = b_endWaypoint_idx_0_tmp - lookaheadDist;
      b_waypointsIn[0] = currentPosition;
      dist = unitVectorUtoV_tmp_0 * currentPosition;
      y = currentPosition * currentPosition;
      unitVectorUtoV_tmp_0 = rtu_0[1] - b_startWaypoint_idx_1_tmp;
      unitVectorUtoV_tmp[1] = unitVectorUtoV_tmp_0;
      currentPosition = b_endWaypoint_idx_1_tmp - b_startWaypoint_idx_1_tmp;
      b_waypointsIn[1] = currentPosition;
      dist += unitVectorUtoV_tmp_0 * currentPosition;
      y += currentPosition * currentPosition;
      unitVectorUtoV_tmp_0 = rtu_0[2] - b_startWaypoint_idx_2_tmp;
      unitVectorUtoV_tmp[2] = unitVectorUtoV_tmp_0;
      currentPosition = b_endWaypoint_idx_2_tmp - b_startWaypoint_idx_2_tmp;
      y += currentPosition * currentPosition;
      unitVectorUtoV_tmp_0 = (unitVectorUtoV_tmp_0 * currentPosition + dist) / y;
      if (unitVectorUtoV_tmp_0 < 0.0) {
        dist = UAM_Flight_control_norm(unitVectorUtoV_tmp);
      } else if (unitVectorUtoV_tmp_0 > 1.0) {
        rtu_0_0[0] = rtu_0[0] - b_endWaypoint_idx_0_tmp;
        rtu_0_0[1] = rtu_0[1] - b_endWaypoint_idx_1_tmp;
        rtu_0_0[2] = rtu_0[2] - b_endWaypoint_idx_2_tmp;
        dist = UAM_Flight_control_norm(rtu_0_0);
      } else {
        rtu_0_0[0] = rtu_0[0] - (unitVectorUtoV_tmp_0 * b_waypointsIn[0] +
          lookaheadDist);
        rtu_0_0[1] = rtu_0[1] - (unitVectorUtoV_tmp_0 * b_waypointsIn[1] +
          b_startWaypoint_idx_1_tmp);
        rtu_0_0[2] = rtu_0[2] - (unitVectorUtoV_tmp_0 * currentPosition +
          b_startWaypoint_idx_2_tmp);
        dist = UAM_Flight_control_norm(rtu_0_0);
      }

      if (localDW->obj.LastWaypointFlag) {
        rtu_0_0[0] = rtu_0[0] - (unitVectorUtoV_tmp_0 * b_waypointsIn[0] +
          lookaheadDist);
        rtu_0_0[1] = rtu_0[1] - (unitVectorUtoV_tmp_0 * b_waypointsIn[1] +
          b_startWaypoint_idx_1_tmp);
        rtu_0_0[2] = rtu_0[2] - (unitVectorUtoV_tmp_0 * currentPosition +
          b_startWaypoint_idx_2_tmp);
        dist = UAM_Flight_control_norm(rtu_0_0);
      }

      absx_tmp = fabs(dist);
      if (rtIsInf(absx_tmp) || rtIsNaN(absx_tmp)) {
        r = (rtNaN);
        absx_tmp = (rtNaN);
      } else if (absx_tmp < 4.4501477170144028E-308) {
        r = 4.94065645841247E-324;
        absx_tmp = 4.94065645841247E-324;
      } else {
        frexp(absx_tmp, &b_exponent);
        r = ldexp(1.0, b_exponent - 53);
        frexp(absx_tmp, &b_exponent_0);
        absx_tmp = ldexp(1.0, b_exponent_0 - 53);
      }

      if (localDW->obj.LookaheadDistance <= fmax(sqrt(r), 5.0 * absx_tmp) + dist)
      {
        localDW->obj.LookaheadDistance = localDW->obj.LookaheadFactor * dist;
      }

      if (localDW->obj.LastWaypointFlag) {
        localB->LAP[0] = b_endWaypoint_idx_0_tmp;
        localB->LAP[1] = b_endWaypoint_idx_1_tmp;
        localB->LAP[2] = b_endWaypoint_idx_2_tmp;
      } else {
        unitVectorUtoV_tmp[0] = lookaheadDist - rtu_0[0];
        unitVectorUtoV_tmp[1] = b_startWaypoint_idx_1_tmp - rtu_0[1];
        unitVectorUtoV_tmp[2] = b_startWaypoint_idx_2_tmp - rtu_0[2];
        dist = ((b_waypointsIn[0] * unitVectorUtoV_tmp[0] + b_waypointsIn[1] *
                 unitVectorUtoV_tmp[1]) + currentPosition * unitVectorUtoV_tmp[2])
          * 2.0;
        r = sqrt(dist * dist - (((unitVectorUtoV_tmp[0] * unitVectorUtoV_tmp[0]
                    + unitVectorUtoV_tmp[1] * unitVectorUtoV_tmp[1]) +
                   unitVectorUtoV_tmp[2] * unitVectorUtoV_tmp[2]) -
                  localDW->obj.LookaheadDistance *
                  localDW->obj.LookaheadDistance) * (4.0 * y));
        y = fmax((-dist + r) / 2.0 / y, (-dist - r) / 2.0 / y);
        localB->LAP[0] = (1.0 - y) * lookaheadDist + y * b_endWaypoint_idx_0_tmp;
        localB->LAP[1] = (1.0 - y) * b_startWaypoint_idx_1_tmp + y *
          b_endWaypoint_idx_1_tmp;
        localB->LAP[2] = (1.0 - y) * b_startWaypoint_idx_2_tmp + y *
          b_endWaypoint_idx_2_tmp;
      }

      /* MATLABSystem: '<S2676>/Waypoint Follower' */
      localB->HeadingCmd = rt_atan2d_snf(localB->LAP[1] - rtu_0[1], localB->LAP
        [0] - rtu_0[0]);
      p = (unitVectorUtoV_tmp_0 < 0.0);
      p_0 = (unitVectorUtoV_tmp_0 > 1.0);
      if (p) {
        y = lookaheadDist;
      } else if (p_0) {
        y = b_endWaypoint_idx_0_tmp;
      } else {
        y = unitVectorUtoV_tmp_0 * b_waypointsIn[0] + lookaheadDist;
      }

      unitVectorUtoV_tmp[0] = y - lookaheadDist;
      rtu_0_0[0] = lookaheadDist - b_endWaypoint_idx_0_tmp;
      if (p) {
        y = b_startWaypoint_idx_1_tmp;
      } else if (p_0) {
        y = b_endWaypoint_idx_1_tmp;
      } else {
        y = unitVectorUtoV_tmp_0 * b_waypointsIn[1] + b_startWaypoint_idx_1_tmp;
      }

      unitVectorUtoV_tmp[1] = y - b_startWaypoint_idx_1_tmp;
      rtu_0_0[1] = b_startWaypoint_idx_1_tmp - b_endWaypoint_idx_1_tmp;
      if (p) {
        y = b_startWaypoint_idx_2_tmp;
      } else if (p_0) {
        y = b_endWaypoint_idx_2_tmp;
      } else {
        y = unitVectorUtoV_tmp_0 * currentPosition + b_startWaypoint_idx_2_tmp;
      }

      unitVectorUtoV_tmp[2] = y - b_startWaypoint_idx_2_tmp;
      rtu_0_0[2] = b_startWaypoint_idx_2_tmp - b_endWaypoint_idx_2_tmp;
      localB->YawCmd = UAM_Flight_control_wrapToPi(UAM_Flight_control_norm
        (unitVectorUtoV_tmp) / UAM_Flight_control_norm(rtu_0_0) *
        UAM_Flight_control_wrapToPi(localDW->obj.FinalYaw - localDW->obj.InitYaw)
        + localDW->obj.InitYaw);
      if (fabs(localB->YawCmd - -3.1415926535897931) < 1.4901161193847656E-8) {
        localB->YawCmd = 3.1415926535897931;
      }

      localDW->obj.LastWaypointFlag = false;
    }
  }
}

/*
 * Output and update for action system:
 *    '<S2699>/Switch Case Action Subsystem'
 *    '<S2699>/Emergency'
 */
void SwitchCaseActionSubsystem_k(real_T rty_GNCPlan_m[3], real_T rtu_pose_n,
  real_T rtu_states_f, real_T rtu_states_d, real_T rtu_states_m, real_T
  rtu_states_c, real_T rtu_ground, uint8_T *rty_GNCPlan, UAVPathManagerBus
  *rty_GNCPlan_n, UAVPathManagerBus *rty_GNCPlan_p, real_T rty_GNCPlan_b[4],
  real_T rty_GNCPlan_o[3], real_T *rty_GNCPlan_k, real_T *rty_GNCPlan_kn,
  P_SwitchCaseActionSubsystem_p_T *localP)
{
  /* SignalConversion generated from: '<S2703>/Constant2' incorporates:
   *  Constant: '<S2703>/Constant2'
   */
  *rty_GNCPlan_p = localP->Constant2_Value;

  /* SignalConversion generated from: '<S2703>/Constant1' incorporates:
   *  Constant: '<S2703>/Constant1'
   */
  *rty_GNCPlan_n = localP->Constant1_Value;

  /* SignalConversion generated from: '<S2703>/Constant3' incorporates:
   *  Constant: '<S2703>/Constant3'
   */
  *rty_GNCPlan = localP->Constant3_Value;

  /* SignalConversion generated from: '<S2703>/GNCPlan' */
  *rty_GNCPlan_kn = rtu_ground;

  /* SignalConversion generated from: '<S2703>/GNCPlan' */
  rty_GNCPlan_b[0] = rty_GNCPlan_m[0];
  rty_GNCPlan_b[1] = rty_GNCPlan_m[1];
  rty_GNCPlan_b[2] = rty_GNCPlan_m[2];
  rty_GNCPlan_b[3] = rtu_pose_n;

  /* SignalConversion generated from: '<S2703>/GNCPlan' */
  rty_GNCPlan_o[0] = rtu_states_f;
  rty_GNCPlan_o[1] = rtu_states_d;
  rty_GNCPlan_o[2] = rtu_states_m;

  /* SignalConversion generated from: '<S2703>/GNCPlan' */
  *rty_GNCPlan_k = rtu_states_c;
}

/* Function for Chart: '<S2669>/Basic Control  Switching' */
static boolean_T UAM_Flig_transitionConditionMet(real_T alpha, real_T
  Vtransition, const GuidanceStates *BusConversion_InsertedFor_Bas_n)
{
  boolean_T valid;
  if (alpha >= 1.0) {
    real_T absxk;
    real_T scale;
    real_T t;
    real_T y;
    scale = 3.3121686421112381E-170;

    /* BusCreator generated from: '<S2669>/Basic Control  Switching' incorporates:
     *  BusCreator generated from: '<S2668>/Basic Control  Switching'
     */
    absxk = fabs(BusConversion_InsertedFor_Bas_n->Ve[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }

    /* BusCreator generated from: '<S2669>/Basic Control  Switching' incorporates:
     *  BusCreator generated from: '<S2668>/Basic Control  Switching'
     */
    absxk = fabs(BusConversion_InsertedFor_Bas_n->Ve[1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    /* BusCreator generated from: '<S2669>/Basic Control  Switching' incorporates:
     *  BusCreator generated from: '<S2668>/Basic Control  Switching'
     */
    absxk = fabs(BusConversion_InsertedFor_Bas_n->Ve[2]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    valid = (scale * sqrt(y) > Vtransition);
  } else {
    valid = false;
  }

  return valid;
}

/* Function for Chart: '<S2669>/Basic Control  Switching' */
static boolean_T UAM_Flight_con_backConditionMet(real_T alpha, const
  GuidanceStates *states_0)
{
  return (alpha <= 0.01) && (fabs(states_0->Ve[0]) < 4.0);
}

static real_T UAM_Flight_control_norm_by(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;

  /* Start for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
   *  MATLABSystem: '<S2674>/Waypoint Follower'
   *  MATLABSystem: '<S2678>/UAV Orbit Follower'
   *  MATLABSystem: '<S2680>/Waypoint Follower'
   */
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  /* Start for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
   *  MATLABSystem: '<S2674>/Waypoint Follower'
   *  MATLABSystem: '<S2678>/UAV Orbit Follower'
   *  MATLABSystem: '<S2680>/Waypoint Follower'
   */
  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  /* Start for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
   *  MATLABSystem: '<S2674>/Waypoint Follower'
   *  MATLABSystem: '<S2678>/UAV Orbit Follower'
   *  MATLABSystem: '<S2680>/Waypoint Follower'
   */
  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

static real_T UAM_Flight_control_wrapToPi_b(real_T theta)
{
  real_T b_theta;
  b_theta = theta;

  /* Start for MATLABSystem: '<S2680>/Waypoint Follower' */
  if (fabs(theta) > 3.1415926535897931) {
    real_T thetaWrap;
    if (rtIsNaN(theta + 3.1415926535897931) || rtIsInf(theta +
         3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (theta + 3.1415926535897931 == 0.0) {
      thetaWrap = 0.0;
    } else {
      boolean_T rEQ0;
      thetaWrap = fmod(theta + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (thetaWrap == 0.0);
      if (!rEQ0) {
        real_T q;
        q = fabs((theta + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        thetaWrap = 0.0;
      } else if (thetaWrap < 0.0) {
        thetaWrap += 6.2831853071795862;
      }
    }

    if ((thetaWrap == 0.0) && (theta + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    b_theta = thetaWrap - 3.1415926535897931;
  }

  /* End of Start for MATLABSystem: '<S2680>/Waypoint Follower' */
  return b_theta;
}

static void UAM_Flight_cont_SystemCore_step(uav_sluav_internal_system__by_T *obj,
  const real_T varargin_1[4], const real_T varargin_2[8], real_T varargin_3,
  real_T varargout_1[3], real_T *varargout_2, real_T *varargout_3, uint8_T
  *varargout_4)
{
  real_T b_waypointsIn_data[8];
  real_T waypoints_data[8];
  real_T b_waypointsIn[3];
  real_T unitVectorUtoV_tmp[3];
  real_T varargin_1_0[3];
  real_T absx_tmp;
  real_T b_endWaypoint_idx_0_tmp;
  real_T b_endWaypoint_idx_1_tmp;
  real_T b_endWaypoint_idx_2_tmp;
  real_T b_startWaypoint_idx_1_tmp;
  real_T b_startWaypoint_idx_2_tmp;
  real_T currentPosition;
  real_T dist;
  real_T lookaheadDist_tmp;
  real_T r;
  real_T unitVectorUtoV_tmp_0;
  real_T y;
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T b_k;
  int32_T c;
  int32_T e;
  int32_T waypoints_size_idx_0;
  int8_T tmp_data[2];
  boolean_T x[3];
  boolean_T distinctWptsIdx[2];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T p;
  boolean_T p_0;

  /* Start for MATLABSystem: '<S2680>/Waypoint Follower' */
  lookaheadDist_tmp = varargin_3;
  obj->LookaheadDistFlag = 0U;
  if (varargin_3 < 0.1) {
    lookaheadDist_tmp = 0.1;
    obj->LookaheadDistFlag = 1U;
  }

  obj->InitialPose[0] = 0.0;
  obj->InitialPose[1] = 0.0;
  obj->InitialPose[2] = 0.0;
  obj->InitialPose[3] = 0.0;
  obj->NumWaypoints = 2.0;
  guard1 = false;
  if (obj->NumWaypoints != 2.0) {
    guard1 = true;
  } else {
    if (obj->NumWaypoints < 1.0) {
      c = 0;
    } else {
      c = (int32_T)obj->NumWaypoints;
    }

    if (obj->NumWaypoints < 1.0) {
      e = 0;
    } else {
      e = (int32_T)obj->NumWaypoints;
    }

    p = false;
    p_0 = false;
    if (c == e) {
      p_0 = true;
    }

    if (p_0 && (c != 0) && (e != 0)) {
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k <= (e << 2) - 1)) {
        if (!(obj->WaypointsInternal[((b_k / c) << 1) + b_k % c] == varargin_2
              [((b_k / e) << 1) + b_k % e])) {
          p_0 = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      guard1 = true;
    }
  }

  if (guard1) {
    memcpy(&obj->WaypointsInternal[0], &varargin_2[0], sizeof(real_T) << 3U);
    obj->WaypointIndex = 1.0;
    obj->SearchFlag = true;
  }

  distinctWptsIdx[1] = true;

  /* Start for MATLABSystem: '<S2680>/Waypoint Follower' */
  x[0] = (varargin_2[0] != varargin_2[1]);
  x[1] = (varargin_2[2] != varargin_2[3]);
  x[2] = (varargin_2[4] != varargin_2[5]);
  distinctWptsIdx[0] = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 3)) {
    if (x[b_k]) {
      distinctWptsIdx[0] = true;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  e = 0;
  for (c = 0; c < 2; c++) {
    if (distinctWptsIdx[c]) {
      e++;
    }
  }

  b_k = e;
  e = 0;
  for (c = 0; c < 2; c++) {
    if (distinctWptsIdx[c]) {
      /* Start for MATLABSystem: '<S2680>/Waypoint Follower' */
      tmp_data[e] = (int8_T)c;
      e++;
    }
  }

  for (c = 0; c < 4; c++) {
    for (e = 0; e < b_k; e++) {
      /* Start for MATLABSystem: '<S2680>/Waypoint Follower' */
      b_waypointsIn_data[e + b_k * c] = varargin_2[(c << 1) + tmp_data[e]];
    }
  }

  /* Start for MATLABSystem: '<S2680>/Waypoint Follower' */
  obj->LookaheadDistance = lookaheadDist_tmp;
  if (b_k == 0) {
    varargout_1[0] = varargin_1[0];
    varargout_1[1] = varargin_1[1];
    varargout_1[2] = varargin_1[2];
    *varargout_2 = varargin_1[3];
    *varargout_3 = varargin_1[3];
  } else {
    guard1 = false;
    if (b_k == 1) {
      if (obj->StartFlag) {
        obj->InitialPose[0] = varargin_1[0];
        obj->InitialPose[1] = varargin_1[1];
        obj->InitialPose[2] = varargin_1[2];
        obj->InitialPose[3] = varargin_1[3];
      }

      b_waypointsIn[0] = b_waypointsIn_data[0] - varargin_1[0];
      b_waypointsIn[1] = b_waypointsIn_data[1] - varargin_1[1];
      b_waypointsIn[2] = b_waypointsIn_data[2] - varargin_1[2];
      if (UAM_Flight_control_norm_by(b_waypointsIn) < 1.4901161193847656E-8) {
        varargout_1[0] = varargin_1[0];
        varargout_1[1] = varargin_1[1];
        varargout_1[2] = varargin_1[2];
        *varargout_2 = varargin_1[3];
        *varargout_3 = varargin_1[3];
        obj->StartFlag = false;
      } else {
        obj->StartFlag = false;
        obj->NumWaypoints = 2.0;
        waypoints_size_idx_0 = b_k + 1;
        waypoints_data[0] = obj->InitialPose[0];
        waypoints_data[b_k + 1] = obj->InitialPose[1];
        waypoints_data[(b_k + 1) << 1] = obj->InitialPose[2];
        waypoints_data[(b_k + 1) * 3] = varargin_2[tmp_data[0] + 6];
        for (c = 0; c < 4; c++) {
          for (e = 0; e < b_k; e++) {
            waypoints_data[(e + (b_k + 1) * c) + 1] = b_waypointsIn_data[b_k * c
              + e];
          }
        }

        guard1 = true;
      }
    } else {
      waypoints_size_idx_0 = b_k;
      e = b_k << 2;
      if (e - 1 >= 0) {
        memcpy(&waypoints_data[0], &b_waypointsIn_data[0], (uint32_T)e * sizeof
               (real_T));
      }

      guard1 = true;
    }

    if (guard1) {
      if (obj->SearchFlag) {
        obj->WaypointIndex = 1.0;
        obj->SearchFlag = false;
      }

      p = false;
      if (obj->WaypointIndex == obj->NumWaypoints) {
        p = true;
      }

      if (p) {
        obj->LastWaypointFlag = true;
        obj->WaypointIndex--;
      }

      obj->InitYaw = waypoints_data[(waypoints_size_idx_0 * 3 + (int32_T)
        obj->WaypointIndex) - 1];
      obj->FinalYaw = waypoints_data[((int32_T)(obj->WaypointIndex + 1.0) +
        waypoints_size_idx_0 * 3) - 1];
      lookaheadDist_tmp = waypoints_data[(int32_T)obj->WaypointIndex - 1];
      b_endWaypoint_idx_0_tmp = waypoints_data[(int32_T)(obj->WaypointIndex +
        1.0) - 1];
      b_waypointsIn[0] = varargin_1[0] - b_endWaypoint_idx_0_tmp;
      b_startWaypoint_idx_1_tmp = waypoints_data[((int32_T)obj->WaypointIndex +
        waypoints_size_idx_0) - 1];
      b_endWaypoint_idx_1_tmp = waypoints_data[((int32_T)(obj->WaypointIndex +
        1.0) + waypoints_size_idx_0) - 1];
      b_waypointsIn[1] = varargin_1[1] - b_endWaypoint_idx_1_tmp;
      b_startWaypoint_idx_2_tmp = waypoints_data[((waypoints_size_idx_0 << 1) +
        (int32_T)obj->WaypointIndex) - 1];
      b_endWaypoint_idx_2_tmp = waypoints_data[((int32_T)(obj->WaypointIndex +
        1.0) + (waypoints_size_idx_0 << 1)) - 1];
      b_waypointsIn[2] = varargin_1[2] - b_endWaypoint_idx_2_tmp;
      y = UAM_Flight_control_norm_by(b_waypointsIn);
      guard2 = false;
      if (y <= 3.0) {
        guard2 = true;
      } else {
        unitVectorUtoV_tmp[0] = b_endWaypoint_idx_0_tmp - lookaheadDist_tmp;
        unitVectorUtoV_tmp[1] = b_endWaypoint_idx_1_tmp -
          b_startWaypoint_idx_1_tmp;
        unitVectorUtoV_tmp[2] = b_endWaypoint_idx_2_tmp -
          b_startWaypoint_idx_2_tmp;
        currentPosition = UAM_Flight_control_norm_by(unitVectorUtoV_tmp);
        unitVectorUtoV_tmp_0 = (unitVectorUtoV_tmp[0] / currentPosition *
          (b_waypointsIn[0] / y) + unitVectorUtoV_tmp[1] / currentPosition *
          (b_waypointsIn[1] / y)) + unitVectorUtoV_tmp[2] / currentPosition *
          (b_waypointsIn[2] / y);
        if (rtIsNaN(unitVectorUtoV_tmp_0) || (unitVectorUtoV_tmp_0 < 0.0)) {
        } else {
          guard2 = true;
        }
      }

      if (guard2) {
        obj->WaypointIndex++;
        p = false;
        if (obj->WaypointIndex == obj->NumWaypoints) {
          p = true;
        }

        if (p) {
          obj->LastWaypointFlag = true;
          obj->WaypointIndex--;
        }

        lookaheadDist_tmp = waypoints_data[(int32_T)obj->WaypointIndex - 1];
        b_endWaypoint_idx_0_tmp = waypoints_data[(int32_T)(obj->WaypointIndex +
          1.0) - 1];
        b_startWaypoint_idx_1_tmp = waypoints_data[((int32_T)obj->WaypointIndex
          + waypoints_size_idx_0) - 1];
        b_endWaypoint_idx_1_tmp = waypoints_data[((int32_T)(obj->WaypointIndex +
          1.0) + waypoints_size_idx_0) - 1];
        b_startWaypoint_idx_2_tmp = waypoints_data[((waypoints_size_idx_0 << 1)
          + (int32_T)obj->WaypointIndex) - 1];
        b_endWaypoint_idx_2_tmp = waypoints_data[((int32_T)(obj->WaypointIndex +
          1.0) + (waypoints_size_idx_0 << 1)) - 1];
        obj->InitYaw = waypoints_data[(waypoints_size_idx_0 * 3 + (int32_T)
          obj->WaypointIndex) - 1];
        obj->FinalYaw = waypoints_data[((int32_T)(obj->WaypointIndex + 1.0) +
          waypoints_size_idx_0 * 3) - 1];
      }

      unitVectorUtoV_tmp_0 = varargin_1[0] - lookaheadDist_tmp;
      unitVectorUtoV_tmp[0] = unitVectorUtoV_tmp_0;
      currentPosition = b_endWaypoint_idx_0_tmp - lookaheadDist_tmp;
      b_waypointsIn[0] = currentPosition;
      dist = unitVectorUtoV_tmp_0 * currentPosition;
      y = currentPosition * currentPosition;
      unitVectorUtoV_tmp_0 = varargin_1[1] - b_startWaypoint_idx_1_tmp;
      unitVectorUtoV_tmp[1] = unitVectorUtoV_tmp_0;
      currentPosition = b_endWaypoint_idx_1_tmp - b_startWaypoint_idx_1_tmp;
      b_waypointsIn[1] = currentPosition;
      dist += unitVectorUtoV_tmp_0 * currentPosition;
      y += currentPosition * currentPosition;
      unitVectorUtoV_tmp_0 = varargin_1[2] - b_startWaypoint_idx_2_tmp;
      unitVectorUtoV_tmp[2] = unitVectorUtoV_tmp_0;
      currentPosition = b_endWaypoint_idx_2_tmp - b_startWaypoint_idx_2_tmp;
      y += currentPosition * currentPosition;
      unitVectorUtoV_tmp_0 = (unitVectorUtoV_tmp_0 * currentPosition + dist) / y;
      if (unitVectorUtoV_tmp_0 < 0.0) {
        dist = UAM_Flight_control_norm_by(unitVectorUtoV_tmp);
      } else if (unitVectorUtoV_tmp_0 > 1.0) {
        varargin_1_0[0] = varargin_1[0] - b_endWaypoint_idx_0_tmp;
        varargin_1_0[1] = varargin_1[1] - b_endWaypoint_idx_1_tmp;
        varargin_1_0[2] = varargin_1[2] - b_endWaypoint_idx_2_tmp;
        dist = UAM_Flight_control_norm_by(varargin_1_0);
      } else {
        varargin_1_0[0] = varargin_1[0] - (unitVectorUtoV_tmp_0 * b_waypointsIn
          [0] + lookaheadDist_tmp);
        varargin_1_0[1] = varargin_1[1] - (unitVectorUtoV_tmp_0 * b_waypointsIn
          [1] + b_startWaypoint_idx_1_tmp);
        varargin_1_0[2] = varargin_1[2] - (unitVectorUtoV_tmp_0 *
          currentPosition + b_startWaypoint_idx_2_tmp);
        dist = UAM_Flight_control_norm_by(varargin_1_0);
      }

      if (obj->LastWaypointFlag) {
        varargin_1_0[0] = varargin_1[0] - (unitVectorUtoV_tmp_0 * b_waypointsIn
          [0] + lookaheadDist_tmp);
        varargin_1_0[1] = varargin_1[1] - (unitVectorUtoV_tmp_0 * b_waypointsIn
          [1] + b_startWaypoint_idx_1_tmp);
        varargin_1_0[2] = varargin_1[2] - (unitVectorUtoV_tmp_0 *
          currentPosition + b_startWaypoint_idx_2_tmp);
        dist = UAM_Flight_control_norm_by(varargin_1_0);
      }

      absx_tmp = fabs(dist);
      if (rtIsInf(absx_tmp) || rtIsNaN(absx_tmp)) {
        r = (rtNaN);
        absx_tmp = (rtNaN);
      } else if (absx_tmp < 4.4501477170144028E-308) {
        r = 4.94065645841247E-324;
        absx_tmp = 4.94065645841247E-324;
      } else {
        frexp(absx_tmp, &b_exponent);
        r = ldexp(1.0, b_exponent - 53);
        frexp(absx_tmp, &b_exponent_0);
        absx_tmp = ldexp(1.0, b_exponent_0 - 53);
      }

      if (obj->LookaheadDistance <= fmax(sqrt(r), 5.0 * absx_tmp) + dist) {
        obj->LookaheadDistance = obj->LookaheadFactor * dist;
      }

      if (obj->LastWaypointFlag) {
        varargout_1[0] = b_endWaypoint_idx_0_tmp;
        varargout_1[1] = b_endWaypoint_idx_1_tmp;
        varargout_1[2] = b_endWaypoint_idx_2_tmp;
      } else {
        unitVectorUtoV_tmp[0] = lookaheadDist_tmp - varargin_1[0];
        unitVectorUtoV_tmp[1] = b_startWaypoint_idx_1_tmp - varargin_1[1];
        unitVectorUtoV_tmp[2] = b_startWaypoint_idx_2_tmp - varargin_1[2];
        dist = ((b_waypointsIn[0] * unitVectorUtoV_tmp[0] + b_waypointsIn[1] *
                 unitVectorUtoV_tmp[1]) + currentPosition * unitVectorUtoV_tmp[2])
          * 2.0;
        r = sqrt(dist * dist - (((unitVectorUtoV_tmp[0] * unitVectorUtoV_tmp[0]
                    + unitVectorUtoV_tmp[1] * unitVectorUtoV_tmp[1]) +
                   unitVectorUtoV_tmp[2] * unitVectorUtoV_tmp[2]) -
                  obj->LookaheadDistance * obj->LookaheadDistance) * (4.0 * y));
        y = fmax((-dist + r) / 2.0 / y, (-dist - r) / 2.0 / y);
        varargout_1[0] = (1.0 - y) * lookaheadDist_tmp + y *
          b_endWaypoint_idx_0_tmp;
        varargout_1[1] = (1.0 - y) * b_startWaypoint_idx_1_tmp + y *
          b_endWaypoint_idx_1_tmp;
        varargout_1[2] = (1.0 - y) * b_startWaypoint_idx_2_tmp + y *
          b_endWaypoint_idx_2_tmp;
      }

      *varargout_2 = rt_atan2d_snf(varargout_1[1] - varargin_1[1], varargout_1[0]
        - varargin_1[0]);
      p = (unitVectorUtoV_tmp_0 < 0.0);
      p_0 = (unitVectorUtoV_tmp_0 > 1.0);
      if (p) {
        y = lookaheadDist_tmp;
      } else if (p_0) {
        y = b_endWaypoint_idx_0_tmp;
      } else {
        y = unitVectorUtoV_tmp_0 * b_waypointsIn[0] + lookaheadDist_tmp;
      }

      unitVectorUtoV_tmp[0] = y - lookaheadDist_tmp;
      varargin_1_0[0] = lookaheadDist_tmp - b_endWaypoint_idx_0_tmp;
      if (p) {
        y = b_startWaypoint_idx_1_tmp;
      } else if (p_0) {
        y = b_endWaypoint_idx_1_tmp;
      } else {
        y = unitVectorUtoV_tmp_0 * b_waypointsIn[1] + b_startWaypoint_idx_1_tmp;
      }

      unitVectorUtoV_tmp[1] = y - b_startWaypoint_idx_1_tmp;
      varargin_1_0[1] = b_startWaypoint_idx_1_tmp - b_endWaypoint_idx_1_tmp;
      if (p) {
        y = b_startWaypoint_idx_2_tmp;
      } else if (p_0) {
        y = b_endWaypoint_idx_2_tmp;
      } else {
        y = unitVectorUtoV_tmp_0 * currentPosition + b_startWaypoint_idx_2_tmp;
      }

      unitVectorUtoV_tmp[2] = y - b_startWaypoint_idx_2_tmp;
      varargin_1_0[2] = b_startWaypoint_idx_2_tmp - b_endWaypoint_idx_2_tmp;
      *varargout_3 = UAM_Flight_control_wrapToPi_b(UAM_Flight_control_norm_by
        (unitVectorUtoV_tmp) / UAM_Flight_control_norm_by(varargin_1_0) *
        UAM_Flight_control_wrapToPi_b(obj->FinalYaw - obj->InitYaw) +
        obj->InitYaw);
      if (fabs(*varargout_3 - -3.1415926535897931) < 1.4901161193847656E-8) {
        *varargout_3 = 3.1415926535897931;
      }

      obj->LastWaypointFlag = false;
    }
  }

  *varargout_4 = obj->LookaheadDistFlag;
}

/* Function for Chart: '<S2667>/Guidance Mode Selector' */
static boolean_T UAM_Flight_cont_backConditioMet(real_T alpha)
{
  return alpha <= 0.01;
}

static real_T UAM_Flight_control_norm_b(const real_T x[2])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;

  /* Start for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
   *  MATLABSystem: '<S2678>/UAV Orbit Follower'
   */
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  /* Start for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
   *  MATLABSystem: '<S2678>/UAV Orbit Follower'
   */
  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

static real_T UAM_Flight_control_angdiff(real_T x, real_T y)
{
  real_T delta;

  /* Start for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
   *  MATLABSystem: '<S2678>/UAV Orbit Follower'
   */
  delta = y - x;
  if (fabs(delta) > 3.1415926535897931) {
    real_T thetaWrap;
    if (rtIsNaN(delta + 3.1415926535897931) || rtIsInf(delta +
         3.1415926535897931)) {
      thetaWrap = (rtNaN);
    } else if (delta + 3.1415926535897931 == 0.0) {
      thetaWrap = 0.0;
    } else {
      boolean_T rEQ0;
      thetaWrap = fmod(delta + 3.1415926535897931, 6.2831853071795862);
      rEQ0 = (thetaWrap == 0.0);
      if (!rEQ0) {
        real_T q;
        q = fabs((delta + 3.1415926535897931) / 6.2831853071795862);
        rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        thetaWrap = 0.0;
      } else if (thetaWrap < 0.0) {
        thetaWrap += 6.2831853071795862;
      }
    }

    if ((thetaWrap == 0.0) && (delta + 3.1415926535897931 > 0.0)) {
      thetaWrap = 6.2831853071795862;
    }

    delta = thetaWrap - 3.1415926535897931;
  }

  /* End of Start for MATLABSystem: '<S2673>/UAV Orbit Follower' */
  return delta;
}

/* Function for Chart: '<S2667>/Guidance Mode Selector' */
static void UAM_Flight_con_FIXED_WING_ENTRY(const GuidanceStates
  *BusConversion_InsertedFor_Guida, real_T *rtb_alt_k_0, real_T rtb_wps_h[6])
{
  real_T b_waypointsIn_data[6];
  real_T waypoints_data[6];
  real_T rtb_TmpSignalConversionAtUAVO_4[3];
  real_T turnVector[3];
  real_T u[3];
  real_T unitVectorUtoV_tmp[3];
  real_T v[3];
  real_T b_tmp[2];
  real_T rtb_TmpSignalConversionAtUAVO_3[2];
  real_T xyPose[2];
  real_T d;
  real_T distToCenter;
  real_T distToCenter_tmp;
  real_T rtb_TmpSignalConversionAtUAVO_5;
  real_T rtb_TmpSignalConversionAtUAVO_6;
  real_T turnInternal;
  real_T x2;
  real_T x2_tmp;
  real_T y2;
  real_T y2_tmp;
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T b_k;
  int32_T i;
  int32_T tmp_size_idx_1;
  int32_T waypoints_data_tmp;
  int32_T waypoints_size_idx_0;
  int8_T tmp_data[2];
  boolean_T x[3];
  boolean_T distinctWptsIdx[2];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T p;
  boolean_T p_0;
  if (UAM_Flight_control_DW.is_FIXED_WING_ENTRY ==
      UAM_Flight_c_IN_FIXEDWINGFLIGHT) {
    /* UnitDelay generated from: '<S2>/Unit Delay' incorporates:
     *  Merge: '<S2671>/ Merge '
     */
    switch (UAM_Flight_control_DW.UnitDelay_1_DSTATE_e) {
     case 3U:
      UAM_Flight_control_DW.is_FIXED_WING_ENTRY =
        UAM_Flight_c_IN_NO_ACTIVE_CHILD;
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight__IN_FIXED_WING_ORBIT;
      UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
      UAM_Flight_control_B.controlMode_n.attitude = 1U;
      UAM_Flight_control_B.controlMode_n.lateralGuidance = 1U;

      /* MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
       *  Constant: '<S2673>/Lookahead Distance'
       *  SignalConversion generated from: '<S2673>/UAV Orbit Follower'
       */
      x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0];
      UAM_Flight_control_DW.obj_jc.OrbitRadiusFlag = 0U;
      if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0] <= 60.0) {
        x2 = 60.0;
        UAM_Flight_control_DW.obj_jc.OrbitRadiusFlag = 1U;
      }

      turnInternal = UAM_Flight_control_P.control.L1;
      UAM_Flight_control_DW.obj_jc.LookaheadDistFlag = 0U;
      if (UAM_Flight_control_P.control.L1 < 60.0) {
        turnInternal = 60.0;
        UAM_Flight_control_DW.obj_jc.LookaheadDistFlag = 1U;
      }

      rtb_TmpSignalConversionAtUAVO_5 = BusConversion_InsertedFor_Guida->Xe[0] -
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
      rtb_TmpSignalConversionAtUAVO_3[0] = rtb_TmpSignalConversionAtUAVO_5;
      rtb_TmpSignalConversionAtUAVO_6 = BusConversion_InsertedFor_Guida->Xe[1] -
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
      rtb_TmpSignalConversionAtUAVO_3[1] = rtb_TmpSignalConversionAtUAVO_6;
      if (UAM_Flight_control_norm_b(rtb_TmpSignalConversionAtUAVO_3) <
          2.47032822920623E-323) {
        /* BusCreator: '<S2673>/Bus Creator' */
        UAM_Flight_control_B.aacSP.course =
          BusConversion_InsertedFor_Guida->course;
        rtb_TmpSignalConversionAtUAVO_5 =
          UAM_Flight_control_DW.obj_jc.NumCircles;
      } else {
        p = false;
        p_0 = true;
        b_k = 0;
        exitg1 = false;
        while ((!exitg1) && (b_k < 3)) {
          if (!(UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[b_k] ==
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[b_k])) {
            p_0 = false;
            exitg1 = true;
          } else {
            b_k++;
          }
        }

        if (p_0) {
          p = true;
        }

        guard1 = false;
        if (!p) {
          guard1 = true;
        } else {
          p = false;
          if (UAM_Flight_control_DW.obj_jc.OrbitRadiusInternal == x2) {
            p = true;
          }

          if (!p) {
            guard1 = true;
          }
        }

        if (guard1) {
          UAM_Flight_control_DW.obj_jc.NumCircles = 0.0;
          UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[0] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[1] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
          UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[2] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
          UAM_Flight_control_DW.obj_jc.OrbitRadiusInternal = x2;
          UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag = true;
        }

        if (turnInternal >= x2) {
          UAM_Flight_control_DW.obj_jc.LookaheadDistance = 0.9 * x2;
        } else {
          UAM_Flight_control_DW.obj_jc.LookaheadDistance = turnInternal;
        }

        b_tmp[0] = rtb_TmpSignalConversionAtUAVO_5;
        b_tmp[1] = rtb_TmpSignalConversionAtUAVO_6;
        distToCenter = sqrt(rtb_TmpSignalConversionAtUAVO_6 *
                            rtb_TmpSignalConversionAtUAVO_6 +
                            rtb_TmpSignalConversionAtUAVO_5 *
                            rtb_TmpSignalConversionAtUAVO_5);
        y2_tmp = x2 + UAM_Flight_control_DW.obj_jc.LookaheadDistance;
        y2 = fabs(y2_tmp);
        p = (rtIsInf(y2) || rtIsNaN(y2));
        if (p) {
          d = (rtNaN);
        } else if (y2 < 4.4501477170144028E-308) {
          d = 4.94065645841247E-324;
        } else {
          frexp(y2, &b_exponent);
          d = ldexp(1.0, b_exponent - 53);
        }

        guard1 = false;
        if (distToCenter >= y2_tmp - 5.0 * d) {
          guard1 = true;
        } else {
          if (p) {
            d = (rtNaN);
          } else if (y2 < 4.4501477170144028E-308) {
            d = 4.94065645841247E-324;
          } else {
            frexp(y2, &b_exponent_0);
            d = ldexp(1.0, b_exponent_0 - 53);
          }

          if (distToCenter <= (x2 -
                               UAM_Flight_control_DW.obj_jc.LookaheadDistance) +
              5.0 * d) {
            guard1 = true;
          } else {
            if (UAM_Flight_control_DW.obj_jc.StartFlag) {
              UAM_Flight_control_DW.obj_jc.PrevPosition[0] =
                BusConversion_InsertedFor_Guida->Xe[0];
              UAM_Flight_control_DW.obj_jc.PrevPosition[1] =
                BusConversion_InsertedFor_Guida->Xe[1];
              UAM_Flight_control_DW.obj_jc.StartFlag = false;
            }

            if ((UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[1] == 0.0) && (
                 !UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag)) {
              turnInternal = UAM_Flight_control_DW.obj_jc.TurnDirectionInternal;
            } else {
              turnInternal = UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[1];
            }

            xyPose[0] = rtb_TmpSignalConversionAtUAVO_5;
            turnVector[0] = UAM_Flight_control_DW.obj_jc.PrevPosition[0] -
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            xyPose[1] = rtb_TmpSignalConversionAtUAVO_6;
            turnVector[1] = UAM_Flight_control_DW.obj_jc.PrevPosition[1] -
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
            d = UAM_Flight_control_norm_b(xyPose);
            distToCenter_tmp = UAM_Flight_control_DW.obj_jc.LookaheadDistance *
              UAM_Flight_control_DW.obj_jc.LookaheadDistance;
            distToCenter = ((distToCenter_tmp - x2 * x2) + d * d) / (2.0 * d);
            x2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
              BusConversion_InsertedFor_Guida->Xe[0];
            x2 = x2_tmp * distToCenter / d + BusConversion_InsertedFor_Guida->
              Xe[0];
            y2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
              BusConversion_InsertedFor_Guida->Xe[1];
            y2 = y2_tmp * distToCenter / d + BusConversion_InsertedFor_Guida->
              Xe[1];
            distToCenter = sqrt(distToCenter_tmp - distToCenter * distToCenter);
            distToCenter_tmp = y2_tmp * distToCenter / d;
            b_tmp[0] = x2 - distToCenter_tmp;
            b_tmp[1] = distToCenter_tmp + x2;
            d = x2_tmp * distToCenter / d;
            x2 = d + y2;
            y2 -= d;
            u[0] = turnVector[0];
            u[1] = turnVector[1];
            u[2] = 0.0;
            v[0] = rtb_TmpSignalConversionAtUAVO_5;
            v[1] = rtb_TmpSignalConversionAtUAVO_6;
            v[2] = 0.0;
            if (turnInternal < 0.0) {
              u[0] = rtb_TmpSignalConversionAtUAVO_5;
              v[0] = turnVector[0];
              u[1] = rtb_TmpSignalConversionAtUAVO_6;
              v[1] = turnVector[1];
              u[2] = 0.0;
              v[2] = 0.0;
            }

            d = UAM_Flight_control_norm_by(u);
            distToCenter = UAM_Flight_control_norm_by(v);
            u[0] /= d;
            v[0] /= distToCenter;
            u[1] /= d;
            v[1] /= distToCenter;
            turnVector[2] = u[0] * v[1] - v[0] * u[1];
            UAM_Flight_control_DW.obj_jc.PrevPosition[0] =
              BusConversion_InsertedFor_Guida->Xe[0];
            UAM_Flight_control_DW.obj_jc.PrevPosition[1] =
              BusConversion_InsertedFor_Guida->Xe[1];
            UAM_Flight_control_DW.obj_jc.PrevPosition[2] =
              BusConversion_InsertedFor_Guida->Xe[2];
            UAM_Flight_control_DW.obj_jc.NumCircles += rt_atan2d_snf(turnVector
              [2], (u[0] * v[0] + u[1] * v[1]) + 0.0 / d * (0.0 / distToCenter))
              / 2.0 / 3.1415926535897931;
            rtb_TmpSignalConversionAtUAVO_5 =
              UAM_Flight_control_DW.obj_jc.NumCircles;
            if (rtIsNaN(turnInternal)) {
              d = (rtNaN);
            } else if (turnInternal < 0.0) {
              d = -1.0;
            } else {
              d = (turnInternal > 0.0);
            }

            switch ((int32_T)d) {
             case 1:
              if ((b_tmp[0] - BusConversion_InsertedFor_Guida->Xe[0]) * y2_tmp -
                  (x2 - BusConversion_InsertedFor_Guida->Xe[1]) * x2_tmp > 0.0)
              {
                distToCenter = b_tmp[0];
                y2 = x2;
              } else {
                distToCenter = b_tmp[1];
              }
              break;

             case -1:
              if ((b_tmp[0] - BusConversion_InsertedFor_Guida->Xe[0]) * y2_tmp -
                  (x2 - BusConversion_InsertedFor_Guida->Xe[1]) * x2_tmp < 0.0)
              {
                distToCenter = b_tmp[0];
                y2 = x2;
              } else {
                distToCenter = b_tmp[1];
              }
              break;

             default:
              if (fabs(UAM_Flight_control_angdiff(rt_atan2d_snf(x2 -
                     BusConversion_InsertedFor_Guida->Xe[1], b_tmp[0] -
                     BusConversion_InsertedFor_Guida->Xe[0]),
                    BusConversion_InsertedFor_Guida->course)) < fabs
                  (UAM_Flight_control_angdiff(rt_atan2d_snf(y2 -
                     BusConversion_InsertedFor_Guida->Xe[1], b_tmp[1] -
                     BusConversion_InsertedFor_Guida->Xe[0]),
                    BusConversion_InsertedFor_Guida->course))) {
                distToCenter = b_tmp[0];
                y2 = x2;
              } else {
                distToCenter = b_tmp[1];
              }

              if ((distToCenter - BusConversion_InsertedFor_Guida->Xe[0]) *
                  y2_tmp - (y2 - BusConversion_InsertedFor_Guida->Xe[1]) *
                  x2_tmp > 0.0) {
                UAM_Flight_control_DW.obj_jc.TurnDirectionInternal = 1.0;
              } else {
                UAM_Flight_control_DW.obj_jc.TurnDirectionInternal = -1.0;
              }

              UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag = false;
              break;
            }
          }
        }

        if (guard1) {
          d = UAM_Flight_control_norm_b(b_tmp);
          distToCenter = rtb_TmpSignalConversionAtUAVO_5 / d * x2 +
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          y2 = rtb_TmpSignalConversionAtUAVO_6 / d * x2 +
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
          rtb_TmpSignalConversionAtUAVO_5 =
            UAM_Flight_control_DW.obj_jc.NumCircles;
        }

        /* BusCreator: '<S2673>/Bus Creator' */
        UAM_Flight_control_B.aacSP.course = rt_atan2d_snf(y2 -
          BusConversion_InsertedFor_Guida->Xe[1], distToCenter -
          BusConversion_InsertedFor_Guida->Xe[0]);
      }

      /* BusCreator: '<S2673>/Bus Creator' incorporates:
       *  Constant: '<S2673>/Constant'
       *  Constant: '<S2673>/Constant1'
       *  Constant: '<S2673>/Lookahead Distance'
       *  UnaryMinus: '<S2673>/Unary Minus'
       */
      UAM_Flight_control_B.aacSP.airspeed =
        UAM_Flight_control_P.control.cruiseSpeed;
      UAM_Flight_control_B.aacSP.altitude =
        -UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
      UAM_Flight_control_B.aacSP.L1 = UAM_Flight_control_P.control.L1;
      UAM_Flight_control_B.aacSP.climbrate =
        UAM_Flight_control_P.Constant1_Value_m;

      /* Merge: '<S2671>/ Merge ' incorporates:
       *  Abs: '<S2673>/Abs1'
       *  DataTypeConversion: '<S2673>/Data Type Conversion'
       *  MATLABSystem: '<S2673>/UAV Orbit Follower'
       *  RelationalOperator: '<S2673>/Relational Operator'
       * */
      UAM_Flight_control_B.Status_p = (uint8_T)(fabs
        (rtb_TmpSignalConversionAtUAVO_5) >
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2]);
      break;

     case 2U:
      UAM_Flight_control_B.Status_p = 0U;
      UAM_Flight_control_DW.is_FIXED_WING_ENTRY =
        UAM_Flight_c_IN_NO_ACTIVE_CHILD;
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flig_IN_FIXED_WING_WAYPOINT;
      UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
      UAM_Flight_control_B.controlMode_n.attitude = 1U;
      UAM_Flight_control_B.controlMode_n.lateralGuidance = 1U;

      /* MATLAB Function: '<S2674>/MATLAB Function' incorporates:
       *  Merge: '<S2671>/ Merge '
       */
      UAM_Flight_MATLABFunction_j
        (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position,
         UAM_Flight_control_DW.UnitDelay_3_DSTATE.position, rtb_wps_h,
         rtb_alt_k_0);

      /* Start for MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  BusCreator: '<S2674>/Bus Creator'
       *  Constant: '<S2674>/Lookahead Distance'
       */
      y2_tmp = UAM_Flight_control_P.control.L1 * 15.0;

      /* MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  Constant: '<S2674>/Lookahead Distance'
       */
      turnInternal = y2_tmp;
      UAM_Flight_control_DW.obj_j.LookaheadDistFlag = 0U;
      if (y2_tmp < 60.0) {
        turnInternal = 60.0;
        UAM_Flight_control_DW.obj_j.LookaheadDistFlag = 1U;
      }

      UAM_Flight_control_DW.obj_j.InitialPose[0] = 0.0;
      UAM_Flight_control_DW.obj_j.InitialPose[1] = 0.0;
      UAM_Flight_control_DW.obj_j.InitialPose[2] = 0.0;
      UAM_Flight_control_DW.obj_j.InitialPose[3] = 0.0;
      UAM_Flight_control_DW.obj_j.NumWaypoints = 2.0;
      p = false;
      p_0 = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k <= 5)) {
        i = ((b_k / 2) << 1) + b_k % 2;
        if (!(UAM_Flight_control_DW.obj_j.WaypointsInternal[i] == rtb_wps_h[i]))
        {
          p_0 = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      if (p_0) {
        p = true;
      }

      if (!p) {
        for (i = 0; i < 6; i++) {
          UAM_Flight_control_DW.obj_j.WaypointsInternal[i] = rtb_wps_h[i];
        }

        UAM_Flight_control_DW.obj_j.WaypointIndex = 1.0;
      }

      distinctWptsIdx[1] = true;
      x[0] = (rtb_wps_h[0] != rtb_wps_h[1]);
      x[1] = (rtb_wps_h[2] != rtb_wps_h[3]);
      x[2] = (rtb_wps_h[4] != rtb_wps_h[5]);
      distinctWptsIdx[0] = false;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 3)) {
        if (x[b_k]) {
          distinctWptsIdx[0] = true;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      b_k = 0;
      for (i = 0; i < 2; i++) {
        if (distinctWptsIdx[i]) {
          b_k++;
        }
      }

      tmp_size_idx_1 = b_k;
      b_k = 0;
      for (i = 0; i < 2; i++) {
        if (distinctWptsIdx[i]) {
          /* Start for MATLABSystem: '<S2674>/Waypoint Follower' */
          tmp_data[b_k] = (int8_T)i;
          b_k++;
        }
      }

      /* MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  SignalConversion generated from: '<S2674>/Waypoint Follower'
       */
      for (i = 0; i < 3; i++) {
        for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
          b_waypointsIn_data[b_k + tmp_size_idx_1 * i] = rtb_wps_h[(i << 1) +
            tmp_data[b_k]];
        }
      }

      UAM_Flight_control_DW.obj_j.LookaheadDistance = turnInternal;
      if (tmp_size_idx_1 == 0) {
        /* BusCreator: '<S2674>/Bus Creator' incorporates:
         *  SignalConversion generated from: '<S2674>/Waypoint Follower'
         */
        UAM_Flight_control_B.aacSP.course =
          BusConversion_InsertedFor_Guida->course;

        /* Merge: '<S2671>/ Merge ' */
        UAM_Flight_control_B.Status_p = 1U;
      } else {
        guard1 = false;
        if (tmp_size_idx_1 == 1) {
          if (UAM_Flight_control_DW.obj_j.StartFlag) {
            UAM_Flight_control_DW.obj_j.InitialPose[0] =
              BusConversion_InsertedFor_Guida->Xe[0];
            UAM_Flight_control_DW.obj_j.InitialPose[1] =
              BusConversion_InsertedFor_Guida->Xe[1];
            UAM_Flight_control_DW.obj_j.InitialPose[2] =
              BusConversion_InsertedFor_Guida->Xe[2];
            UAM_Flight_control_DW.obj_j.InitialPose[3] =
              BusConversion_InsertedFor_Guida->course;
          }

          u[0] = b_waypointsIn_data[0] - BusConversion_InsertedFor_Guida->Xe[0];
          u[1] = b_waypointsIn_data[1] - BusConversion_InsertedFor_Guida->Xe[1];
          u[2] = b_waypointsIn_data[2] - BusConversion_InsertedFor_Guida->Xe[2];
          if (UAM_Flight_control_norm_by(u) < 1.4901161193847656E-8) {
            /* BusCreator: '<S2674>/Bus Creator' incorporates:
             *  SignalConversion generated from: '<S2674>/Waypoint Follower'
             */
            UAM_Flight_control_B.aacSP.course =
              BusConversion_InsertedFor_Guida->course;

            /* Merge: '<S2671>/ Merge ' */
            UAM_Flight_control_B.Status_p = 1U;
            UAM_Flight_control_DW.obj_j.StartFlag = false;
          } else {
            UAM_Flight_control_DW.obj_j.StartFlag = false;
            UAM_Flight_control_DW.obj_j.NumWaypoints = 2.0;
            waypoints_size_idx_0 = tmp_size_idx_1 + 1;
            for (i = 0; i < 3; i++) {
              waypoints_data_tmp = (tmp_size_idx_1 + 1) * i;
              waypoints_data[waypoints_data_tmp] =
                UAM_Flight_control_DW.obj_j.InitialPose[i];
              for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
                waypoints_data[(b_k + waypoints_data_tmp) + 1] =
                  b_waypointsIn_data[tmp_size_idx_1 * i + b_k];
              }
            }

            guard1 = true;
          }
        } else {
          waypoints_size_idx_0 = tmp_size_idx_1;
          b_k = tmp_size_idx_1 * 3;
          if (b_k - 1 >= 0) {
            memcpy(&waypoints_data[0], &b_waypointsIn_data[0], (uint32_T)b_k *
                   sizeof(real_T));
          }

          guard1 = true;
        }

        if (guard1) {
          p = false;
          if (UAM_Flight_control_DW.obj_j.WaypointIndex == 2.0) {
            p = true;
          }

          if (p) {
            UAM_Flight_control_DW.obj_j.LastWaypointFlag = true;
            UAM_Flight_control_DW.obj_j.WaypointIndex--;
          }

          x2 = waypoints_data[(int32_T)UAM_Flight_control_DW.obj_j.WaypointIndex
            - 1];
          u[0] = x2;
          turnInternal = waypoints_data[(int32_T)
            (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) - 1];
          v[0] = turnInternal;
          u[1] = waypoints_data[((int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0) -
            1];
          d = waypoints_data[((int32_T)
                              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0)
                              + waypoints_size_idx_0) - 1];
          v[1] = d;
          u[2] = waypoints_data[((waypoints_size_idx_0 << 1) + (int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
          y2 = waypoints_data[((int32_T)
                               (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0)
                               + (waypoints_size_idx_0 << 1)) - 1];
          v[2] = y2;
          turnVector[0] = BusConversion_InsertedFor_Guida->Xe[0] - turnInternal;
          turnVector[1] = BusConversion_InsertedFor_Guida->Xe[1] - d;
          turnVector[2] = BusConversion_InsertedFor_Guida->Xe[2] - y2;
          d = UAM_Flight_control_norm_by(turnVector);
          guard2 = false;
          if (d <= 10.0) {
            guard2 = true;
          } else {
            unitVectorUtoV_tmp[0] = turnInternal - x2;
            unitVectorUtoV_tmp[1] = waypoints_data[((int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              waypoints_size_idx_0) - 1] - waypoints_data[((int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0)
              - 1];
            unitVectorUtoV_tmp[2] = waypoints_data[((int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              (waypoints_size_idx_0 << 1)) - 1] - waypoints_data
              [((waypoints_size_idx_0 << 1) + (int32_T)
                UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
            distToCenter = UAM_Flight_control_norm_by(unitVectorUtoV_tmp);
            turnInternal = (unitVectorUtoV_tmp[0] / distToCenter * (turnVector[0]
              / d) + unitVectorUtoV_tmp[1] / distToCenter * (turnVector[1] / d))
              + unitVectorUtoV_tmp[2] / distToCenter * (turnVector[2] / d);
            if (rtIsNaN(turnInternal) || (turnInternal < 0.0)) {
            } else {
              guard2 = true;
            }
          }

          if (guard2) {
            UAM_Flight_control_DW.obj_j.WaypointIndex++;
            p = false;
            if (UAM_Flight_control_DW.obj_j.WaypointIndex == 2.0) {
              p = true;
            }

            if (p) {
              UAM_Flight_control_DW.obj_j.LastWaypointFlag = true;
              UAM_Flight_control_DW.obj_j.WaypointIndex--;
            }

            u[0] = waypoints_data[(int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex - 1];
            v[0] = waypoints_data[(int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) - 1];
            u[1] = waypoints_data[((int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0)
              - 1];
            v[1] = waypoints_data[((int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              waypoints_size_idx_0) - 1];
            u[2] = waypoints_data[((waypoints_size_idx_0 << 1) + (int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
            v[2] = waypoints_data[((int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              (waypoints_size_idx_0 << 1)) - 1];
          }

          turnVector[0] = BusConversion_InsertedFor_Guida->Xe[0] - u[0];
          unitVectorUtoV_tmp[0] = v[0] - u[0];
          turnVector[1] = BusConversion_InsertedFor_Guida->Xe[1] - u[1];
          unitVectorUtoV_tmp[1] = v[1] - u[1];
          turnVector[2] = BusConversion_InsertedFor_Guida->Xe[2] - u[2];
          unitVectorUtoV_tmp[2] = v[2] - u[2];
          turnInternal = (unitVectorUtoV_tmp[0] * unitVectorUtoV_tmp[0] +
                          unitVectorUtoV_tmp[1] * unitVectorUtoV_tmp[1]) +
            unitVectorUtoV_tmp[2] * unitVectorUtoV_tmp[2];
          d = ((turnVector[0] * unitVectorUtoV_tmp[0] + turnVector[1] *
                unitVectorUtoV_tmp[1]) + turnVector[2] * unitVectorUtoV_tmp[2]) /
            turnInternal;
          if (d < 0.0) {
            x2 = UAM_Flight_control_norm_by(turnVector);
          } else if (d > 1.0) {
            rtb_TmpSignalConversionAtUAVO_4[0] =
              BusConversion_InsertedFor_Guida->Xe[0] - v[0];
            rtb_TmpSignalConversionAtUAVO_4[1] =
              BusConversion_InsertedFor_Guida->Xe[1] - v[1];
            rtb_TmpSignalConversionAtUAVO_4[2] =
              BusConversion_InsertedFor_Guida->Xe[2] - v[2];
            x2 = UAM_Flight_control_norm_by(rtb_TmpSignalConversionAtUAVO_4);
          } else {
            rtb_TmpSignalConversionAtUAVO_4[0] =
              BusConversion_InsertedFor_Guida->Xe[0] - (d * unitVectorUtoV_tmp[0]
              + u[0]);
            rtb_TmpSignalConversionAtUAVO_4[1] =
              BusConversion_InsertedFor_Guida->Xe[1] - (d * unitVectorUtoV_tmp[1]
              + u[1]);
            rtb_TmpSignalConversionAtUAVO_4[2] =
              BusConversion_InsertedFor_Guida->Xe[2] - (d * unitVectorUtoV_tmp[2]
              + u[2]);
            x2 = UAM_Flight_control_norm_by(rtb_TmpSignalConversionAtUAVO_4);
          }

          if (UAM_Flight_control_DW.obj_j.LastWaypointFlag) {
            rtb_TmpSignalConversionAtUAVO_4[0] =
              BusConversion_InsertedFor_Guida->Xe[0] - (d * unitVectorUtoV_tmp[0]
              + u[0]);
            rtb_TmpSignalConversionAtUAVO_4[1] =
              BusConversion_InsertedFor_Guida->Xe[1] - (d * unitVectorUtoV_tmp[1]
              + u[1]);
            rtb_TmpSignalConversionAtUAVO_4[2] =
              BusConversion_InsertedFor_Guida->Xe[2] - (d * unitVectorUtoV_tmp[2]
              + u[2]);
            x2 = UAM_Flight_control_norm_by(rtb_TmpSignalConversionAtUAVO_4);
          }

          y2 = fabs(x2);
          if (rtIsInf(y2) || rtIsNaN(y2)) {
            d = (rtNaN);
            y2 = (rtNaN);
          } else if (y2 < 4.4501477170144028E-308) {
            d = 4.94065645841247E-324;
            y2 = 4.94065645841247E-324;
          } else {
            frexp(y2, &b_exponent);
            d = ldexp(1.0, b_exponent - 53);
            frexp(y2, &b_exponent_0);
            y2 = ldexp(1.0, b_exponent_0 - 53);
          }

          if (UAM_Flight_control_DW.obj_j.LookaheadDistance <= fmax(sqrt(d), 5.0
               * y2) + x2) {
            UAM_Flight_control_DW.obj_j.LookaheadDistance =
              UAM_Flight_control_DW.obj_j.LookaheadFactor * x2;
          }

          turnVector[0] = unitVectorUtoV_tmp[0];
          turnVector[1] = unitVectorUtoV_tmp[1];
          turnVector[2] = unitVectorUtoV_tmp[2];
          unitVectorUtoV_tmp[0] = u[0] - BusConversion_InsertedFor_Guida->Xe[0];
          unitVectorUtoV_tmp[1] = u[1] - BusConversion_InsertedFor_Guida->Xe[1];
          unitVectorUtoV_tmp[2] = u[2] - BusConversion_InsertedFor_Guida->Xe[2];
          x2 = ((turnVector[0] * unitVectorUtoV_tmp[0] + turnVector[1] *
                 unitVectorUtoV_tmp[1]) + turnVector[2] * unitVectorUtoV_tmp[2])
            * 2.0;
          d = sqrt(x2 * x2 - (((unitVectorUtoV_tmp[0] * unitVectorUtoV_tmp[0] +
                                unitVectorUtoV_tmp[1] * unitVectorUtoV_tmp[1]) +
                               unitVectorUtoV_tmp[2] * unitVectorUtoV_tmp[2]) -
                              UAM_Flight_control_DW.obj_j.LookaheadDistance *
                              UAM_Flight_control_DW.obj_j.LookaheadDistance) *
                   (4.0 * turnInternal));
          turnInternal = fmax((-x2 + d) / 2.0 / turnInternal, (-x2 - d) / 2.0 /
                              turnInternal);
          v[0] = (1.0 - turnInternal) * u[0] + turnInternal * v[0];
          v[1] = (1.0 - turnInternal) * u[1] + turnInternal * v[1];

          /* BusCreator: '<S2674>/Bus Creator' incorporates:
           *  SignalConversion generated from: '<S2674>/Waypoint Follower'
           */
          UAM_Flight_control_B.aacSP.course = rt_atan2d_snf(v[1] -
            BusConversion_InsertedFor_Guida->Xe[1], v[0] -
            BusConversion_InsertedFor_Guida->Xe[0]);
          p = false;
          if (UAM_Flight_control_DW.obj_j.LastWaypointFlag) {
            p = true;
          }

          if (p) {
            /* Merge: '<S2671>/ Merge ' */
            UAM_Flight_control_B.Status_p = 1U;
          }

          UAM_Flight_control_DW.obj_j.LastWaypointFlag = false;
        }
      }

      /* BusCreator: '<S2674>/Bus Creator' incorporates:
       *  Constant: '<S2674>/Constant'
       *  Constant: '<S2674>/Constant1'
       */
      UAM_Flight_control_B.aacSP.airspeed =
        UAM_Flight_control_P.control.cruiseSpeed;
      UAM_Flight_control_B.aacSP.altitude = *rtb_alt_k_0;
      UAM_Flight_control_B.aacSP.L1 = y2_tmp;
      UAM_Flight_control_B.aacSP.climbrate =
        UAM_Flight_control_P.Constant1_Value_ha;
      break;
    }

    /* End of UnitDelay generated from: '<S2>/Unit Delay' */

    /* case IN_Stabilize: */
  } else if (UAM_Flight_control_DW.temporalCounter_i1 >= 100) {
    UAM_Flight_control_DW.is_FIXED_WING_ENTRY = UAM_Flight_c_IN_FIXEDWINGFLIGHT;
    UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
    UAM_Flight_control_B.controlMode_n.attitude = 1U;
    UAM_Flight_control_B.controlMode_n.lateralGuidance = 1U;
    UAM_Flight_control_B.aacSP.L1 = 25.0;
    UAM_Flight_control_B.aacSP.airspeed = 14.0;
    UAM_Flight_control_B.aacSP.altitude = 0.0;
    UAM_Flight_control_B.aacSP.course = 0.0;
  }
}

/* Function for Chart: '<S2667>/Guidance Mode Selector' */
static boolean_T UAM_Fl_transitionConditionMet_h(real_T alpha)
{
  return alpha >= 1.0;
}

/* Function for Chart: '<S2667>/Guidance Mode Selector' */
static void UAM_Flight_control_Land(const GuidanceStates
  *BusConversion_InsertedFor_Guida, real_T rtb_wps_d[8])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  boolean_T out;
  if (UAM_Flight_control_DW.is_Land == UAM_Flight_control_IN_Descend) {
    /* MATLAB Function: '<S2676>/MATLAB Function' incorporates:
     *  SignalConversion generated from: '<S2683>/ SFunction '
     *  UnitDelay generated from: '<S2>/Unit Delay'
     *  UnitDelay generated from: '<S2>/Unit Delay1'
     */
    UAM_Flight_control_DW.outWPS_l[0] =
      UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
    UAM_Flight_control_DW.outWPS_l[2] =
      UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
    UAM_Flight_control_DW.outWPS_l[4] =
      UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
    UAM_Flight_control_DW.outWPS_l[6] =
      UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];
    UAM_Flight_control_DW.outWPS_l[1] =
      UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
    UAM_Flight_control_DW.outWPS_l[3] =
      UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
    UAM_Flight_control_DW.outWPS_l[5] =
      UAM_Flight_control_DW.UnitDelay1_10_DSTATE;
    UAM_Flight_control_DW.outWPS_l[7] =
      UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];

    /* UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
     *  Constant: '<S2676>/Constant'
     *  MATLAB Function: '<S2676>/MATLAB Function'
     */
    UAM_Flight_WaypointFollower(UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
      UAM_Flight_control_DW.outWPS_l, UAM_Flight_control_P.Constant_Value_g3,
      &UAM_Flight_control_B.WaypointFollower_n,
      &UAM_Flight_control_DW.WaypointFollower_n);

    /* BusCreator: '<S2676>/Bus Creator' incorporates:
     *  MATLABSystem: '<S2676>/Waypoint Follower'
     *  Merge: '<S2671>/ Merge 2'
     */
    UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
      UAM_Flight_control_B.WaypointFollower_n.LAP[0];
    UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
      UAM_Flight_control_B.WaypointFollower_n.LAP[1];
    UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
      UAM_Flight_control_B.WaypointFollower_n.LAP[2];

    /* Saturate: '<S2676>/Hdg Cmd Sat' incorporates:
     *  UnitDelay generated from: '<S2>/Unit Delay'
     */
    if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] >
        UAM_Flight_control_P.HdgCmdSat_UpperSat) {
      /* BusCreator: '<S2676>/Bus Creator' incorporates:
       *  Merge: '<S2671>/ Merge 2'
       */
      UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
        UAM_Flight_control_P.HdgCmdSat_UpperSat;
    } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] <
               UAM_Flight_control_P.HdgCmdSat_LowerSat) {
      /* BusCreator: '<S2676>/Bus Creator' incorporates:
       *  Merge: '<S2671>/ Merge 2'
       */
      UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
        UAM_Flight_control_P.HdgCmdSat_LowerSat;
    } else {
      /* BusCreator: '<S2676>/Bus Creator' incorporates:
       *  Merge: '<S2671>/ Merge 2'
       */
      UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
    }

    /* Saturate: '<S2676>/Yaw Cmd Sat' incorporates:
     *  UnitDelay generated from: '<S2>/Unit Delay'
     */
    if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] >
        UAM_Flight_control_P.YawCmdSat_UpperSat) {
      /* BusCreator: '<S2676>/Bus Creator' incorporates:
       *  Merge: '<S2671>/ Merge 2'
       */
      UAM_Flight_control_B.InnerLoopCmds.YawCmd =
        UAM_Flight_control_P.YawCmdSat_UpperSat;
    } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] <
               UAM_Flight_control_P.YawCmdSat_LowerSat) {
      /* BusCreator: '<S2676>/Bus Creator' incorporates:
       *  Merge: '<S2671>/ Merge 2'
       */
      UAM_Flight_control_B.InnerLoopCmds.YawCmd =
        UAM_Flight_control_P.YawCmdSat_LowerSat;
    } else {
      /* BusCreator: '<S2676>/Bus Creator' incorporates:
       *  Merge: '<S2671>/ Merge 2'
       */
      UAM_Flight_control_B.InnerLoopCmds.YawCmd =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
    }

    /* Merge: '<S2671>/ Merge ' incorporates:
     *  Constant: '<S2676>/Constant3'
     *  SignalConversion generated from: '<S2676>/Status'
     */
    UAM_Flight_control_B.Status_p = UAM_Flight_control_P.Constant3_Value_e;
  } else {
    /* case IN_ToLand: */
    scale = 3.3121686421112381E-170;

    /* Start for UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
     *  UnitDelay generated from: '<S2>/Unit Delay'
     */
    absxk = fabs(UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0] -
                 UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0]);
    if (absxk > 3.3121686421112381E-170) {
      y = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      y = t * t;
    }

    /* Start for UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
     *  UnitDelay generated from: '<S2>/Unit Delay'
     */
    /* BusCreator generated from: '<S2667>/Guidance Mode Selector' */
    absxk = fabs(UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1] -
                 UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1]);
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }

    y = scale * sqrt(y);
    if (y <= 30.0) {
      UAM_Flight_control_DW.is_Land = UAM_Flight_control_IN_Descend;

      /* MATLAB Function: '<S2676>/MATLAB Function' incorporates:
       *  SignalConversion generated from: '<S2683>/ SFunction '
       *  UnitDelay generated from: '<S2>/Unit Delay'
       *  UnitDelay generated from: '<S2>/Unit Delay1'
       */
      UAM_Flight_control_DW.outWPS_l[0] =
        UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
      UAM_Flight_control_DW.outWPS_l[2] =
        UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
      UAM_Flight_control_DW.outWPS_l[4] =
        UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
      UAM_Flight_control_DW.outWPS_l[6] =
        UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];
      UAM_Flight_control_DW.outWPS_l[1] =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
      UAM_Flight_control_DW.outWPS_l[3] =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
      UAM_Flight_control_DW.outWPS_l[5] =
        UAM_Flight_control_DW.UnitDelay1_10_DSTATE;
      UAM_Flight_control_DW.outWPS_l[7] =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];

      /* UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
       *  Constant: '<S2676>/Constant'
       *  MATLAB Function: '<S2676>/MATLAB Function'
       */
      UAM_Flight_WaypointFollower(UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
        UAM_Flight_control_DW.outWPS_l, UAM_Flight_control_P.Constant_Value_g3,
        &UAM_Flight_control_B.WaypointFollower_n,
        &UAM_Flight_control_DW.WaypointFollower_n);

      /* BusCreator: '<S2676>/Bus Creator' incorporates:
       *  MATLABSystem: '<S2676>/Waypoint Follower'
       *  Merge: '<S2671>/ Merge 2'
       */
      UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
        UAM_Flight_control_B.WaypointFollower_n.LAP[0];
      UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
        UAM_Flight_control_B.WaypointFollower_n.LAP[1];
      UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
        UAM_Flight_control_B.WaypointFollower_n.LAP[2];

      /* Saturate: '<S2676>/Hdg Cmd Sat' incorporates:
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] >
          UAM_Flight_control_P.HdgCmdSat_UpperSat) {
        /* BusCreator: '<S2676>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_P.HdgCmdSat_UpperSat;
      } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] <
                 UAM_Flight_control_P.HdgCmdSat_LowerSat) {
        /* BusCreator: '<S2676>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_P.HdgCmdSat_LowerSat;
      } else {
        /* BusCreator: '<S2676>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
      }

      /* Saturate: '<S2676>/Yaw Cmd Sat' incorporates:
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] >
          UAM_Flight_control_P.YawCmdSat_UpperSat) {
        /* BusCreator: '<S2676>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.YawCmdSat_UpperSat;
      } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] <
                 UAM_Flight_control_P.YawCmdSat_LowerSat) {
        /* BusCreator: '<S2676>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.YawCmdSat_LowerSat;
      } else {
        /* BusCreator: '<S2676>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
      }

      /* Merge: '<S2671>/ Merge ' incorporates:
       *  Constant: '<S2676>/Constant3'
       *  SignalConversion generated from: '<S2676>/Status'
       */
      UAM_Flight_control_B.Status_p = UAM_Flight_control_P.Constant3_Value_e;
    } else {
      if (BusConversion_InsertedFor_Guida->Ve[2] >= -1.0E-6) {
        /* BusCreator generated from: '<S2667>/Guidance Mode Selector' */
        if (!(BusConversion_InsertedFor_Guida->Ve[2] >= -1.0E-6)) {
          UAM_Flight_control_DW.durationCounter_1 = 0U;
        }

        out = (UAM_Flight_control_DW.durationCounter_1 > 1600U);
      } else {
        out = false;
      }

      if (out) {
        UAM_Flight_control_DW.is_Land = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_contr_IN_Landcommand;
        UAM_Flight_control_B.controlMode_n.land = 0.0;
      } else {
        /* MATLAB Function: '<S2677>/MATLAB Function' incorporates:
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_control_DW.outWPS_i[0] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
        UAM_Flight_control_DW.outWPS_i[2] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
        UAM_Flight_control_DW.outWPS_i[4] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
        UAM_Flight_control_DW.outWPS_i[6] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];
        UAM_Flight_control_DW.outWPS_i[1] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
        UAM_Flight_control_DW.outWPS_i[3] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
        UAM_Flight_control_DW.outWPS_i[5] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
        UAM_Flight_control_DW.outWPS_i[7] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
        memcpy(&rtb_wps_d[0], &UAM_Flight_control_DW.outWPS_i[0], sizeof(real_T)
               << 3U);

        /* UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
         *  Constant: '<S2677>/Lookahead Distance'
         */
        UAM_Flight_WaypointFollower(UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
          rtb_wps_d, UAM_Flight_control_P.LookaheadDistance_Value,
          &UAM_Flight_control_B.WaypointFollower_ni,
          &UAM_Flight_control_DW.WaypointFollower_ni);

        /* BusCreator: '<S2677>/Bus Creator1' incorporates:
         *  MATLABSystem: '<S2677>/Waypoint Follower'
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_B.WaypointFollower_ni.LAP[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_B.WaypointFollower_ni.LAP[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_B.WaypointFollower_ni.LAP[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_B.WaypointFollower_ni.HeadingCmd;
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_B.WaypointFollower_ni.YawCmd;

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  Constant: '<S2677>/Constant'
         *  SignalConversion generated from: '<S2677>/Status'
         */
        UAM_Flight_control_B.Status_p = UAM_Flight_control_P.Constant_Value_j5;
      }
    }
  }
}

/* Function for Chart: '<S2667>/Guidance Mode Selector' */
static void enter_internal_FIXED_WING_ENTRY(void)
{
  UAM_Flight_control_DW.temporalCounter_i1 = 0U;
  UAM_Flight_control_DW.is_FIXED_WING_ENTRY = UAM_Flight_control_IN_Stabilize;
  UAM_Flight_control_B.FlightMode_c = FixedWing;
  UAM_Flight_control_B.controlMode_n.attitude = 1U;
  UAM_Flight_control_B.controlMode_n.airspeedAltitude = 0U;
  UAM_Flight_control_B.controlMode_n.lateralGuidance = 0U;
  UAM_Flight_control_B.FixedWingSP_l.yaw = 0.0;
  UAM_Flight_control_B.FixedWingSP_l.pitch = 0.0;
  UAM_Flight_control_B.FixedWingSP_l.roll = 0.0;
  UAM_Flight_control_B.FixedWingSP_l.airspeed = 14.0;

  /* Merge: '<S2671>/ Merge ' */
  UAM_Flight_control_B.Status_p = 0U;
}

/* Function for Chart: '<S2667>/Guidance Mode Selector' */
static void UAM_Flight_control_Start(const GuidanceStates
  *BusConversion_InsertedFor_Guida, real_T *rtb_alt_k_1, real_T *rtb_alt_0,
  real_T rtb_wps_d[8], real_T rtb_wps_h[6])
{
  real_T rtb_wps_c[6];
  real_T waypoints_data[6];
  real_T rtb_Product_bz[3];
  real_T rtb_TmpSignalConversionAtUAVO_7[3];
  real_T turnVector[3];
  real_T unitVectorUtoV_tmp[3];
  real_T v[3];
  real_T b_tmp[2];
  real_T xyLookaheadPoint[2];
  real_T xyPose[2];
  real_T a;
  real_T a_tmp;
  real_T d;
  real_T distToCenter;
  real_T rtb_Abs;
  real_T rtb_Abs_tmp;
  real_T rtb_DotProduct;
  real_T xyLookaheadPoint_tmp;
  real_T xyLookaheadPoint_tmp_0;
  real_T y2_tmp;
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T b_k;
  int32_T i;
  int32_T tmp_size_idx_1;
  int32_T waypoints_data_tmp;
  int32_T waypoints_size_idx_0;
  int8_T tmp_data[2];
  uint8_T b_varargout_4;
  boolean_T x[3];
  boolean_T distinctWptsIdx[2];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T p;
  boolean_T rtb_Equal;

  /* UnitDelay generated from: '<S2>/Unit Delay' incorporates:
   *  BusCreator generated from: '<S2667>/Guidance Mode Selector'
   *  Constant: '<S2677>/Lookahead Distance'
   *  Merge: '<S2671>/ Merge '
   *  UnitDelay generated from: '<S2>/Unit Delay1'
   */
  if ((UAM_Flight_control_DW.UnitDelay_1_DSTATE_e == 6) &&
      (UAM_Flight_control_B.FlightMode_c == FixedWing)) {
    UAM_Flight_control_DW.temporalCounter_i1 = 0U;
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_con_IN_PreTransition;
    UAM_Flight_control_B.FlightMode_c = FixedWing;
    UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
    UAM_Flight_control_B.controlMode_n.attitude = 1U;
    UAM_Flight_control_B.controlMode_n.lateralGuidance = 1U;
    UAM_Flight_control_B.aacSP.L1 = 25.0;
    UAM_Flight_control_B.aacSP.airspeed = 14.0;
    UAM_Flight_control_B.aacSP.altitude = -BusConversion_InsertedFor_Guida->Xe[2];
    UAM_Flight_control_B.aacSP.course = BusConversion_InsertedFor_Guida->course;
  } else if ((UAM_Flight_control_DW.UnitDelay_1_DSTATE_e == 2) &&
             (UAM_Flight_control_B.FlightMode_c == FixedWing)) {
    UAM_Flight_control_B.Status_p = 0U;
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flig_IN_FIXED_WING_WAYPOINT;
    UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
    UAM_Flight_control_B.controlMode_n.attitude = 1U;
    UAM_Flight_control_B.controlMode_n.lateralGuidance = 1U;

    /* MATLAB Function: '<S2674>/MATLAB Function' incorporates:
     *  Merge: '<S2671>/ Merge '
     */
    UAM_Flight_MATLABFunction_j
      (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position,
       UAM_Flight_control_DW.UnitDelay_3_DSTATE.position, rtb_wps_h, rtb_alt_k_1);

    /* Start for MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
     *  BusCreator: '<S2674>/Bus Creator'
     *  Constant: '<S2674>/Lookahead Distance'
     */
    xyLookaheadPoint_tmp = UAM_Flight_control_P.control.L1 * 15.0;

    /* MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
     *  Constant: '<S2674>/Lookahead Distance'
     */
    rtb_DotProduct = xyLookaheadPoint_tmp;
    UAM_Flight_control_DW.obj_j.LookaheadDistFlag = 0U;
    if (xyLookaheadPoint_tmp < 60.0) {
      rtb_DotProduct = 60.0;
      UAM_Flight_control_DW.obj_j.LookaheadDistFlag = 1U;
    }

    UAM_Flight_control_DW.obj_j.InitialPose[0] = 0.0;
    UAM_Flight_control_DW.obj_j.InitialPose[1] = 0.0;
    UAM_Flight_control_DW.obj_j.InitialPose[2] = 0.0;
    UAM_Flight_control_DW.obj_j.InitialPose[3] = 0.0;
    UAM_Flight_control_DW.obj_j.NumWaypoints = 2.0;
    rtb_Equal = false;
    p = true;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= 5)) {
      i = ((b_k / 2) << 1) + b_k % 2;
      if (!(UAM_Flight_control_DW.obj_j.WaypointsInternal[i] == rtb_wps_h[i])) {
        p = false;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    if (p) {
      rtb_Equal = true;
    }

    if (!rtb_Equal) {
      for (i = 0; i < 6; i++) {
        UAM_Flight_control_DW.obj_j.WaypointsInternal[i] = rtb_wps_h[i];
      }

      UAM_Flight_control_DW.obj_j.WaypointIndex = 1.0;
    }

    distinctWptsIdx[1] = true;
    x[0] = (rtb_wps_h[0] != rtb_wps_h[1]);
    x[1] = (rtb_wps_h[2] != rtb_wps_h[3]);
    x[2] = (rtb_wps_h[4] != rtb_wps_h[5]);
    distinctWptsIdx[0] = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 3)) {
      if (x[b_k]) {
        distinctWptsIdx[0] = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    b_k = 0;
    for (i = 0; i < 2; i++) {
      if (distinctWptsIdx[i]) {
        b_k++;
      }
    }

    tmp_size_idx_1 = b_k;
    b_k = 0;
    for (i = 0; i < 2; i++) {
      if (distinctWptsIdx[i]) {
        /* Start for MATLABSystem: '<S2674>/Waypoint Follower' */
        tmp_data[b_k] = (int8_T)i;
        b_k++;
      }
    }

    /* MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
     *  SignalConversion generated from: '<S2674>/Waypoint Follower'
     */
    for (i = 0; i < 3; i++) {
      for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
        rtb_wps_c[b_k + tmp_size_idx_1 * i] = rtb_wps_h[(i << 1) + tmp_data[b_k]];
      }
    }

    UAM_Flight_control_DW.obj_j.LookaheadDistance = rtb_DotProduct;
    if (tmp_size_idx_1 == 0) {
      /* BusCreator: '<S2674>/Bus Creator' incorporates:
       *  SignalConversion generated from: '<S2674>/Waypoint Follower'
       */
      UAM_Flight_control_B.aacSP.course =
        BusConversion_InsertedFor_Guida->course;

      /* Merge: '<S2671>/ Merge ' */
      UAM_Flight_control_B.Status_p = 1U;
    } else {
      guard1 = false;
      if (tmp_size_idx_1 == 1) {
        if (UAM_Flight_control_DW.obj_j.StartFlag) {
          UAM_Flight_control_DW.obj_j.InitialPose[0] =
            BusConversion_InsertedFor_Guida->Xe[0];
          UAM_Flight_control_DW.obj_j.InitialPose[1] =
            BusConversion_InsertedFor_Guida->Xe[1];
          UAM_Flight_control_DW.obj_j.InitialPose[2] =
            BusConversion_InsertedFor_Guida->Xe[2];
          UAM_Flight_control_DW.obj_j.InitialPose[3] =
            BusConversion_InsertedFor_Guida->course;
        }

        rtb_Product_bz[0] = rtb_wps_c[0] - BusConversion_InsertedFor_Guida->Xe[0];
        rtb_Product_bz[1] = rtb_wps_c[1] - BusConversion_InsertedFor_Guida->Xe[1];
        rtb_Product_bz[2] = rtb_wps_c[2] - BusConversion_InsertedFor_Guida->Xe[2];
        if (UAM_Flight_control_norm_by(rtb_Product_bz) < 1.4901161193847656E-8)
        {
          /* BusCreator: '<S2674>/Bus Creator' incorporates:
           *  SignalConversion generated from: '<S2674>/Waypoint Follower'
           */
          UAM_Flight_control_B.aacSP.course =
            BusConversion_InsertedFor_Guida->course;

          /* Merge: '<S2671>/ Merge ' */
          UAM_Flight_control_B.Status_p = 1U;
          UAM_Flight_control_DW.obj_j.StartFlag = false;
        } else {
          UAM_Flight_control_DW.obj_j.StartFlag = false;
          UAM_Flight_control_DW.obj_j.NumWaypoints = 2.0;
          waypoints_size_idx_0 = tmp_size_idx_1 + 1;
          for (i = 0; i < 3; i++) {
            waypoints_data_tmp = (tmp_size_idx_1 + 1) * i;
            waypoints_data[waypoints_data_tmp] =
              UAM_Flight_control_DW.obj_j.InitialPose[i];
            for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
              waypoints_data[(b_k + waypoints_data_tmp) + 1] =
                rtb_wps_c[tmp_size_idx_1 * i + b_k];
            }
          }

          guard1 = true;
        }
      } else {
        waypoints_size_idx_0 = tmp_size_idx_1;
        b_k = tmp_size_idx_1 * 3;
        if (b_k - 1 >= 0) {
          memcpy(&waypoints_data[0], &rtb_wps_c[0], (uint32_T)b_k * sizeof
                 (real_T));
        }

        guard1 = true;
      }

      if (guard1) {
        rtb_Equal = false;
        if (UAM_Flight_control_DW.obj_j.WaypointIndex == 2.0) {
          rtb_Equal = true;
        }

        if (rtb_Equal) {
          UAM_Flight_control_DW.obj_j.LastWaypointFlag = true;
          UAM_Flight_control_DW.obj_j.WaypointIndex--;
        }

        rtb_DotProduct = waypoints_data[(int32_T)
          UAM_Flight_control_DW.obj_j.WaypointIndex - 1];
        rtb_Product_bz[0] = rtb_DotProduct;
        rtb_Abs = waypoints_data[(int32_T)
          (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) - 1];
        v[0] = rtb_Abs;
        rtb_Product_bz[1] = waypoints_data[((int32_T)
          UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0) - 1];
        d = waypoints_data[((int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex
          + 1.0) + waypoints_size_idx_0) - 1];
        v[1] = d;
        rtb_Product_bz[2] = waypoints_data[((waypoints_size_idx_0 << 1) +
          (int32_T)UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
        xyLookaheadPoint_tmp_0 = waypoints_data[((int32_T)
          (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
          (waypoints_size_idx_0 << 1)) - 1];
        v[2] = xyLookaheadPoint_tmp_0;
        turnVector[0] = BusConversion_InsertedFor_Guida->Xe[0] - rtb_Abs;
        turnVector[1] = BusConversion_InsertedFor_Guida->Xe[1] - d;
        turnVector[2] = BusConversion_InsertedFor_Guida->Xe[2] -
          xyLookaheadPoint_tmp_0;
        d = UAM_Flight_control_norm_by(turnVector);
        guard2 = false;
        if (d <= 10.0) {
          guard2 = true;
        } else {
          unitVectorUtoV_tmp[0] = rtb_Abs - rtb_DotProduct;
          unitVectorUtoV_tmp[1] = waypoints_data[((int32_T)
            (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
            waypoints_size_idx_0) - 1] - waypoints_data[((int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0) -
            1];
          unitVectorUtoV_tmp[2] = waypoints_data[((int32_T)
            (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
            (waypoints_size_idx_0 << 1)) - 1] - waypoints_data
            [((waypoints_size_idx_0 << 1) + (int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
          a = UAM_Flight_control_norm_by(unitVectorUtoV_tmp);
          rtb_DotProduct = (unitVectorUtoV_tmp[0] / a * (turnVector[0] / d) +
                            unitVectorUtoV_tmp[1] / a * (turnVector[1] / d)) +
            unitVectorUtoV_tmp[2] / a * (turnVector[2] / d);
          if (rtIsNaN(rtb_DotProduct) || (rtb_DotProduct < 0.0)) {
          } else {
            guard2 = true;
          }
        }

        if (guard2) {
          UAM_Flight_control_DW.obj_j.WaypointIndex++;
          rtb_Equal = false;
          if (UAM_Flight_control_DW.obj_j.WaypointIndex == 2.0) {
            rtb_Equal = true;
          }

          if (rtb_Equal) {
            UAM_Flight_control_DW.obj_j.LastWaypointFlag = true;
            UAM_Flight_control_DW.obj_j.WaypointIndex--;
          }

          rtb_Product_bz[0] = waypoints_data[(int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex - 1];
          v[0] = waypoints_data[(int32_T)
            (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) - 1];
          rtb_Product_bz[1] = waypoints_data[((int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0) -
            1];
          v[1] = waypoints_data[((int32_T)
            (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
            waypoints_size_idx_0) - 1];
          rtb_Product_bz[2] = waypoints_data[((waypoints_size_idx_0 << 1) +
            (int32_T)UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
          v[2] = waypoints_data[((int32_T)
            (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
            (waypoints_size_idx_0 << 1)) - 1];
        }

        turnVector[0] = BusConversion_InsertedFor_Guida->Xe[0] - rtb_Product_bz
          [0];
        unitVectorUtoV_tmp[0] = v[0] - rtb_Product_bz[0];
        turnVector[1] = BusConversion_InsertedFor_Guida->Xe[1] - rtb_Product_bz
          [1];
        unitVectorUtoV_tmp[1] = v[1] - rtb_Product_bz[1];
        turnVector[2] = BusConversion_InsertedFor_Guida->Xe[2] - rtb_Product_bz
          [2];
        unitVectorUtoV_tmp[2] = v[2] - rtb_Product_bz[2];
        rtb_DotProduct = (unitVectorUtoV_tmp[0] * unitVectorUtoV_tmp[0] +
                          unitVectorUtoV_tmp[1] * unitVectorUtoV_tmp[1]) +
          unitVectorUtoV_tmp[2] * unitVectorUtoV_tmp[2];
        d = ((turnVector[0] * unitVectorUtoV_tmp[0] + turnVector[1] *
              unitVectorUtoV_tmp[1]) + turnVector[2] * unitVectorUtoV_tmp[2]) /
          rtb_DotProduct;
        if (d < 0.0) {
          rtb_Abs = UAM_Flight_control_norm_by(turnVector);
        } else if (d > 1.0) {
          rtb_TmpSignalConversionAtUAVO_7[0] =
            BusConversion_InsertedFor_Guida->Xe[0] - v[0];
          rtb_TmpSignalConversionAtUAVO_7[1] =
            BusConversion_InsertedFor_Guida->Xe[1] - v[1];
          rtb_TmpSignalConversionAtUAVO_7[2] =
            BusConversion_InsertedFor_Guida->Xe[2] - v[2];
          rtb_Abs = UAM_Flight_control_norm_by(rtb_TmpSignalConversionAtUAVO_7);
        } else {
          rtb_TmpSignalConversionAtUAVO_7[0] =
            BusConversion_InsertedFor_Guida->Xe[0] - (d * unitVectorUtoV_tmp[0]
            + rtb_Product_bz[0]);
          rtb_TmpSignalConversionAtUAVO_7[1] =
            BusConversion_InsertedFor_Guida->Xe[1] - (d * unitVectorUtoV_tmp[1]
            + rtb_Product_bz[1]);
          rtb_TmpSignalConversionAtUAVO_7[2] =
            BusConversion_InsertedFor_Guida->Xe[2] - (d * unitVectorUtoV_tmp[2]
            + rtb_Product_bz[2]);
          rtb_Abs = UAM_Flight_control_norm_by(rtb_TmpSignalConversionAtUAVO_7);
        }

        if (UAM_Flight_control_DW.obj_j.LastWaypointFlag) {
          rtb_TmpSignalConversionAtUAVO_7[0] =
            BusConversion_InsertedFor_Guida->Xe[0] - (d * unitVectorUtoV_tmp[0]
            + rtb_Product_bz[0]);
          rtb_TmpSignalConversionAtUAVO_7[1] =
            BusConversion_InsertedFor_Guida->Xe[1] - (d * unitVectorUtoV_tmp[1]
            + rtb_Product_bz[1]);
          rtb_TmpSignalConversionAtUAVO_7[2] =
            BusConversion_InsertedFor_Guida->Xe[2] - (d * unitVectorUtoV_tmp[2]
            + rtb_Product_bz[2]);
          rtb_Abs = UAM_Flight_control_norm_by(rtb_TmpSignalConversionAtUAVO_7);
        }

        a = fabs(rtb_Abs);
        if (rtIsInf(a) || rtIsNaN(a)) {
          d = (rtNaN);
          distToCenter = (rtNaN);
        } else if (a < 4.4501477170144028E-308) {
          d = 4.94065645841247E-324;
          distToCenter = 4.94065645841247E-324;
        } else {
          frexp(a, &b_exponent);
          d = ldexp(1.0, b_exponent - 53);
          frexp(a, &b_exponent_0);
          distToCenter = ldexp(1.0, b_exponent_0 - 53);
        }

        if (UAM_Flight_control_DW.obj_j.LookaheadDistance <= fmax(sqrt(d), 5.0 *
             distToCenter) + rtb_Abs) {
          UAM_Flight_control_DW.obj_j.LookaheadDistance =
            UAM_Flight_control_DW.obj_j.LookaheadFactor * rtb_Abs;
        }

        turnVector[0] = unitVectorUtoV_tmp[0];
        turnVector[1] = unitVectorUtoV_tmp[1];
        turnVector[2] = unitVectorUtoV_tmp[2];
        unitVectorUtoV_tmp[0] = rtb_Product_bz[0] -
          BusConversion_InsertedFor_Guida->Xe[0];
        unitVectorUtoV_tmp[1] = rtb_Product_bz[1] -
          BusConversion_InsertedFor_Guida->Xe[1];
        unitVectorUtoV_tmp[2] = rtb_Product_bz[2] -
          BusConversion_InsertedFor_Guida->Xe[2];
        rtb_Abs = ((turnVector[0] * unitVectorUtoV_tmp[0] + turnVector[1] *
                    unitVectorUtoV_tmp[1]) + turnVector[2] * unitVectorUtoV_tmp
                   [2]) * 2.0;
        d = sqrt(rtb_Abs * rtb_Abs - (((unitVectorUtoV_tmp[0] *
                    unitVectorUtoV_tmp[0] + unitVectorUtoV_tmp[1] *
                    unitVectorUtoV_tmp[1]) + unitVectorUtoV_tmp[2] *
                   unitVectorUtoV_tmp[2]) -
                  UAM_Flight_control_DW.obj_j.LookaheadDistance *
                  UAM_Flight_control_DW.obj_j.LookaheadDistance) * (4.0 *
                  rtb_DotProduct));
        rtb_DotProduct = fmax((-rtb_Abs + d) / 2.0 / rtb_DotProduct, (-rtb_Abs -
          d) / 2.0 / rtb_DotProduct);
        v[0] = (1.0 - rtb_DotProduct) * rtb_Product_bz[0] + rtb_DotProduct * v[0];
        v[1] = (1.0 - rtb_DotProduct) * rtb_Product_bz[1] + rtb_DotProduct * v[1];

        /* BusCreator: '<S2674>/Bus Creator' incorporates:
         *  SignalConversion generated from: '<S2674>/Waypoint Follower'
         */
        UAM_Flight_control_B.aacSP.course = rt_atan2d_snf(v[1] -
          BusConversion_InsertedFor_Guida->Xe[1], v[0] -
          BusConversion_InsertedFor_Guida->Xe[0]);
        rtb_Equal = false;
        if (UAM_Flight_control_DW.obj_j.LastWaypointFlag) {
          rtb_Equal = true;
        }

        if (rtb_Equal) {
          /* Merge: '<S2671>/ Merge ' */
          UAM_Flight_control_B.Status_p = 1U;
        }

        UAM_Flight_control_DW.obj_j.LastWaypointFlag = false;
      }
    }

    /* BusCreator: '<S2674>/Bus Creator' incorporates:
     *  Constant: '<S2674>/Constant'
     *  Constant: '<S2674>/Constant1'
     */
    UAM_Flight_control_B.aacSP.airspeed =
      UAM_Flight_control_P.control.cruiseSpeed;
    UAM_Flight_control_B.aacSP.altitude = *rtb_alt_k_1;
    UAM_Flight_control_B.aacSP.L1 = xyLookaheadPoint_tmp;
    UAM_Flight_control_B.aacSP.climbrate =
      UAM_Flight_control_P.Constant1_Value_ha;
  } else {
    switch (UAM_Flight_control_B.FlightMode_c) {
     case Transition:
      UAM_Flight_control_B.controlMode_n.inTransition = 0U;
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight__IN_FIXED_WING_ENTRY;
      enter_internal_FIXED_WING_ENTRY();
      break;

     case BackTransition:
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_contr_IN_HOVER_ENTRY;
      UAM_Flight_control_B.FlightMode_c = Hover;
      UAM_Flight_control_B.controlMode_n.inTransition = 0U;
      break;

     default:
      if ((UAM_Flight_control_DW.UnitDelay_1_DSTATE_e == 1) &&
          (UAM_Flight_control_B.FlightMode_c == Hover)) {
        UAM_Flight_control_B.controlMode_n.inTransition = 0U;
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_Takeoff;

        /* BusCreator: '<S2679>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         *  SignalConversion generated from: '<S2679>/Bus Creator'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];

        /* Saturate: '<S2679>/Hdg. Cmd Sat' */
        if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] >
            UAM_Flight_control_P.HdgCmdSat_UpperSat_e) {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_P.HdgCmdSat_UpperSat_e;
        } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] <
                   UAM_Flight_control_P.HdgCmdSat_LowerSat_f) {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_P.HdgCmdSat_LowerSat_f;
        } else {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
        }

        /* End of Saturate: '<S2679>/Hdg. Cmd Sat' */

        /* Saturate: '<S2679>/Yaw Cmd Sat' incorporates:
         *  Constant: '<S2679>/Constant1'
         */
        if (UAM_Flight_control_P.Constant1_Value_b >
            UAM_Flight_control_P.YawCmdSat_UpperSat_f) {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_UpperSat_f;
        } else if (UAM_Flight_control_P.Constant1_Value_b <
                   UAM_Flight_control_P.YawCmdSat_LowerSat_p) {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_LowerSat_p;
        } else {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.Constant1_Value_b;
        }

        /* End of Saturate: '<S2679>/Yaw Cmd Sat' */

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  Constant: '<S2679>/Constant'
         *  SignalConversion generated from: '<S2679>/Status'
         */
        UAM_Flight_control_B.Status_p = UAM_Flight_control_P.Constant_Value_gm;
      } else if ((UAM_Flight_control_DW.UnitDelay_1_DSTATE_e == 3) &&
                 (UAM_Flight_control_B.FlightMode_c == FixedWing)) {
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight__IN_FIXED_WING_ORBIT;
        UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
        UAM_Flight_control_B.controlMode_n.attitude = 1U;
        UAM_Flight_control_B.controlMode_n.lateralGuidance = 1U;

        /* MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
         *  Constant: '<S2673>/Lookahead Distance'
         *  SignalConversion generated from: '<S2673>/UAV Orbit Follower'
         */
        rtb_Abs = UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0];
        UAM_Flight_control_DW.obj_jc.OrbitRadiusFlag = 0U;
        if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0] <= 60.0) {
          rtb_Abs = 60.0;
          UAM_Flight_control_DW.obj_jc.OrbitRadiusFlag = 1U;
        }

        d = UAM_Flight_control_P.control.L1;
        UAM_Flight_control_DW.obj_jc.LookaheadDistFlag = 0U;
        if (UAM_Flight_control_P.control.L1 < 60.0) {
          d = 60.0;
          UAM_Flight_control_DW.obj_jc.LookaheadDistFlag = 1U;
        }

        xyLookaheadPoint_tmp = BusConversion_InsertedFor_Guida->Xe[0] -
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
        xyLookaheadPoint[0] = xyLookaheadPoint_tmp;
        xyLookaheadPoint_tmp_0 = BusConversion_InsertedFor_Guida->Xe[1] -
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
        xyLookaheadPoint[1] = xyLookaheadPoint_tmp_0;
        if (UAM_Flight_control_norm_b(xyLookaheadPoint) < 2.47032822920623E-323)
        {
          /* BusCreator: '<S2673>/Bus Creator' */
          UAM_Flight_control_B.aacSP.course =
            BusConversion_InsertedFor_Guida->course;
          a = UAM_Flight_control_DW.obj_jc.NumCircles;
        } else {
          rtb_Equal = false;
          p = true;
          b_k = 0;
          exitg1 = false;
          while ((!exitg1) && (b_k < 3)) {
            if (!(UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[b_k] ==
                  UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[b_k])) {
              p = false;
              exitg1 = true;
            } else {
              b_k++;
            }
          }

          if (p) {
            rtb_Equal = true;
          }

          guard1 = false;
          if (!rtb_Equal) {
            guard1 = true;
          } else {
            rtb_Equal = false;
            if (UAM_Flight_control_DW.obj_jc.OrbitRadiusInternal == rtb_Abs) {
              rtb_Equal = true;
            }

            if (!rtb_Equal) {
              guard1 = true;
            }
          }

          if (guard1) {
            UAM_Flight_control_DW.obj_jc.NumCircles = 0.0;
            UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[0] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[1] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
            UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[2] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
            UAM_Flight_control_DW.obj_jc.OrbitRadiusInternal = rtb_Abs;
            UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag = true;
          }

          if (d >= rtb_Abs) {
            UAM_Flight_control_DW.obj_jc.LookaheadDistance = 0.9 * rtb_Abs;
          } else {
            UAM_Flight_control_DW.obj_jc.LookaheadDistance = d;
          }

          b_tmp[0] = xyLookaheadPoint_tmp;
          b_tmp[1] = xyLookaheadPoint_tmp_0;
          distToCenter = sqrt(xyLookaheadPoint_tmp_0 * xyLookaheadPoint_tmp_0 +
                              xyLookaheadPoint_tmp * xyLookaheadPoint_tmp);
          a_tmp = rtb_Abs + UAM_Flight_control_DW.obj_jc.LookaheadDistance;
          a = fabs(a_tmp);
          rtb_Equal = (rtIsInf(a) || rtIsNaN(a));
          if (rtb_Equal) {
            d = (rtNaN);
          } else if (a < 4.4501477170144028E-308) {
            d = 4.94065645841247E-324;
          } else {
            frexp(a, &b_exponent);
            d = ldexp(1.0, b_exponent - 53);
          }

          guard1 = false;
          if (distToCenter >= a_tmp - 5.0 * d) {
            guard1 = true;
          } else {
            if (rtb_Equal) {
              d = (rtNaN);
            } else if (a < 4.4501477170144028E-308) {
              d = 4.94065645841247E-324;
            } else {
              frexp(a, &b_exponent_0);
              d = ldexp(1.0, b_exponent_0 - 53);
            }

            if (distToCenter <= (rtb_Abs -
                                 UAM_Flight_control_DW.obj_jc.LookaheadDistance)
                + 5.0 * d) {
              guard1 = true;
            } else {
              if (UAM_Flight_control_DW.obj_jc.StartFlag) {
                UAM_Flight_control_DW.obj_jc.PrevPosition[0] =
                  BusConversion_InsertedFor_Guida->Xe[0];
                UAM_Flight_control_DW.obj_jc.PrevPosition[1] =
                  BusConversion_InsertedFor_Guida->Xe[1];
                UAM_Flight_control_DW.obj_jc.StartFlag = false;
              }

              if ((UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[1] == 0.0) &&
                  (!UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag)) {
                rtb_DotProduct =
                  UAM_Flight_control_DW.obj_jc.TurnDirectionInternal;
              } else {
                rtb_DotProduct =
                  UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[1];
              }

              xyPose[0] = xyLookaheadPoint_tmp;
              turnVector[0] = UAM_Flight_control_DW.obj_jc.PrevPosition[0] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
              xyPose[1] = xyLookaheadPoint_tmp_0;
              turnVector[1] = UAM_Flight_control_DW.obj_jc.PrevPosition[1] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
              d = UAM_Flight_control_norm_b(xyPose);
              a_tmp = UAM_Flight_control_DW.obj_jc.LookaheadDistance *
                UAM_Flight_control_DW.obj_jc.LookaheadDistance;
              a = ((a_tmp - rtb_Abs * rtb_Abs) + d * d) / (2.0 * d);
              rtb_Abs_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0]
                - BusConversion_InsertedFor_Guida->Xe[0];
              rtb_Abs = rtb_Abs_tmp * a / d +
                BusConversion_InsertedFor_Guida->Xe[0];
              y2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
                BusConversion_InsertedFor_Guida->Xe[1];
              distToCenter = y2_tmp * a / d +
                BusConversion_InsertedFor_Guida->Xe[1];
              a = sqrt(a_tmp - a * a);
              b_tmp[0] = rtb_Abs - y2_tmp * a / d;
              b_tmp[1] = y2_tmp * a / d + rtb_Abs;
              d = rtb_Abs_tmp * a / d;
              rtb_Abs = d + distToCenter;
              distToCenter -= d;
              rtb_Product_bz[0] = turnVector[0];
              rtb_Product_bz[1] = turnVector[1];
              rtb_Product_bz[2] = 0.0;
              v[0] = xyLookaheadPoint_tmp;
              v[1] = xyLookaheadPoint_tmp_0;
              v[2] = 0.0;
              if (rtb_DotProduct < 0.0) {
                rtb_Product_bz[0] = xyLookaheadPoint_tmp;
                v[0] = turnVector[0];
                rtb_Product_bz[1] = xyLookaheadPoint_tmp_0;
                v[1] = turnVector[1];
                rtb_Product_bz[2] = 0.0;
                v[2] = 0.0;
              }

              d = UAM_Flight_control_norm_by(rtb_Product_bz);
              a = UAM_Flight_control_norm_by(v);
              rtb_Product_bz[0] /= d;
              v[0] /= a;
              rtb_Product_bz[1] /= d;
              v[1] /= a;
              turnVector[2] = rtb_Product_bz[0] * v[1] - v[0] * rtb_Product_bz[1];
              UAM_Flight_control_DW.obj_jc.PrevPosition[0] =
                BusConversion_InsertedFor_Guida->Xe[0];
              UAM_Flight_control_DW.obj_jc.PrevPosition[1] =
                BusConversion_InsertedFor_Guida->Xe[1];
              UAM_Flight_control_DW.obj_jc.PrevPosition[2] =
                BusConversion_InsertedFor_Guida->Xe[2];
              UAM_Flight_control_DW.obj_jc.NumCircles += rt_atan2d_snf
                (turnVector[2], (rtb_Product_bz[0] * v[0] + rtb_Product_bz[1] *
                                 v[1]) + 0.0 / d * (0.0 / a)) / 2.0 /
                3.1415926535897931;
              a = UAM_Flight_control_DW.obj_jc.NumCircles;
              if (rtIsNaN(rtb_DotProduct)) {
                d = (rtNaN);
              } else if (rtb_DotProduct < 0.0) {
                d = -1.0;
              } else {
                d = (rtb_DotProduct > 0.0);
              }

              switch ((int32_T)d) {
               case 1:
                if ((b_tmp[0] - BusConversion_InsertedFor_Guida->Xe[0]) * y2_tmp
                    - (rtb_Abs - BusConversion_InsertedFor_Guida->Xe[1]) *
                    rtb_Abs_tmp > 0.0) {
                  rtb_DotProduct = b_tmp[0];
                  distToCenter = rtb_Abs;
                } else {
                  rtb_DotProduct = b_tmp[1];
                }
                break;

               case -1:
                if ((b_tmp[0] - BusConversion_InsertedFor_Guida->Xe[0]) * y2_tmp
                    - (rtb_Abs - BusConversion_InsertedFor_Guida->Xe[1]) *
                    rtb_Abs_tmp < 0.0) {
                  rtb_DotProduct = b_tmp[0];
                  distToCenter = rtb_Abs;
                } else {
                  rtb_DotProduct = b_tmp[1];
                }
                break;

               default:
                if (fabs(UAM_Flight_control_angdiff(rt_atan2d_snf(rtb_Abs -
                       BusConversion_InsertedFor_Guida->Xe[1], b_tmp[0] -
                       BusConversion_InsertedFor_Guida->Xe[0]),
                      BusConversion_InsertedFor_Guida->course)) < fabs
                    (UAM_Flight_control_angdiff(rt_atan2d_snf(distToCenter -
                       BusConversion_InsertedFor_Guida->Xe[1], b_tmp[1] -
                       BusConversion_InsertedFor_Guida->Xe[0]),
                      BusConversion_InsertedFor_Guida->course))) {
                  rtb_DotProduct = b_tmp[0];
                  distToCenter = rtb_Abs;
                } else {
                  rtb_DotProduct = b_tmp[1];
                }

                if ((rtb_DotProduct - BusConversion_InsertedFor_Guida->Xe[0]) *
                    y2_tmp - (distToCenter - BusConversion_InsertedFor_Guida->
                              Xe[1]) * rtb_Abs_tmp > 0.0) {
                  UAM_Flight_control_DW.obj_jc.TurnDirectionInternal = 1.0;
                } else {
                  UAM_Flight_control_DW.obj_jc.TurnDirectionInternal = -1.0;
                }

                UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag = false;
                break;
              }
            }
          }

          if (guard1) {
            d = UAM_Flight_control_norm_b(b_tmp);
            rtb_DotProduct = xyLookaheadPoint_tmp / d * rtb_Abs +
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            distToCenter = xyLookaheadPoint_tmp_0 / d * rtb_Abs +
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
            a = UAM_Flight_control_DW.obj_jc.NumCircles;
          }

          /* BusCreator: '<S2673>/Bus Creator' */
          UAM_Flight_control_B.aacSP.course = rt_atan2d_snf(distToCenter -
            BusConversion_InsertedFor_Guida->Xe[1], rtb_DotProduct -
            BusConversion_InsertedFor_Guida->Xe[0]);
        }

        /* BusCreator: '<S2673>/Bus Creator' incorporates:
         *  Constant: '<S2673>/Constant'
         *  Constant: '<S2673>/Constant1'
         *  Constant: '<S2673>/Lookahead Distance'
         *  UnaryMinus: '<S2673>/Unary Minus'
         */
        UAM_Flight_control_B.aacSP.airspeed =
          UAM_Flight_control_P.control.cruiseSpeed;
        UAM_Flight_control_B.aacSP.altitude =
          -UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
        UAM_Flight_control_B.aacSP.L1 = UAM_Flight_control_P.control.L1;
        UAM_Flight_control_B.aacSP.climbrate =
          UAM_Flight_control_P.Constant1_Value_m;

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  Abs: '<S2673>/Abs1'
         *  DataTypeConversion: '<S2673>/Data Type Conversion'
         *  MATLABSystem: '<S2673>/UAV Orbit Follower'
         *  RelationalOperator: '<S2673>/Relational Operator'
         * */
        UAM_Flight_control_B.Status_p = (uint8_T)(fabs(a) >
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2]);
      } else if (UAM_Flight_control_B.FlightMode_c == Hover) {
        UAM_Flight_control_B.controlMode_n.inTransition = 0U;
        switch (UAM_Flight_control_DW.UnitDelay_1_DSTATE_e) {
         case 2U:
          UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_WP;

          /* RelationalOperator: '<S2685>/Equal' incorporates:
           *  Constant: '<S2685>/Constant'
           */
          rtb_Equal = (UAM_Flight_control_P.Constant_Value_p ==
                       UAM_Flight_control_DW.UnitDelay_3_DSTATE.mode);

          /* Outputs for Triggered SubSystem: '<S2685>/Triggered Subsystem' incorporates:
           *  TriggerPort: '<S2688>/Trigger'
           */
          if (rtb_Equal &&
              (UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE !=
               POS_ZCSIG)) {
            /* Reshape: '<S2688>/Reshape' incorporates:
             *  UnitDelay generated from: '<S2>/Unit Delay1'
             */
            UAM_Flight_control_B.Reshape[0] =
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
            UAM_Flight_control_B.Reshape[1] =
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
            UAM_Flight_control_B.Reshape[2] =
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
          }

          UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_Equal;

          /* End of Outputs for SubSystem: '<S2685>/Triggered Subsystem' */

          /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
           *  BusCreator generated from: '<S2680>/MATLAB Function'
           */
          UAM_Flight_control_DW.outWPS[6] =
            UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];

          /* Switch: '<S2685>/Switch' incorporates:
           *  Product: '<S2689>/Product'
           *  Reshape: '<S2688>/Reshape'
           */
          if (rtb_Equal) {
            rtb_DotProduct = UAM_Flight_control_B.Reshape[0];
          } else {
            rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
          }

          rtb_Product_bz[0] = rtb_DotProduct;

          /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
           *  BusCreator generated from: '<S2680>/MATLAB Function'
           *  Product: '<S2689>/Product'
           *  UnitDelay generated from: '<S2>/Unit Delay'
           */
          UAM_Flight_control_DW.outWPS[0] = rtb_DotProduct;
          UAM_Flight_control_DW.outWPS[1] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];

          /* Switch: '<S2685>/Switch' incorporates:
           *  Product: '<S2689>/Product'
           *  Reshape: '<S2688>/Reshape'
           */
          if (rtb_Equal) {
            rtb_DotProduct = UAM_Flight_control_B.Reshape[1];
          } else {
            rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
          }

          rtb_Product_bz[1] = rtb_DotProduct;

          /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
           *  BusCreator generated from: '<S2680>/MATLAB Function'
           *  Product: '<S2689>/Product'
           *  UnitDelay generated from: '<S2>/Unit Delay'
           */
          UAM_Flight_control_DW.outWPS[2] = rtb_DotProduct;
          UAM_Flight_control_DW.outWPS[3] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];

          /* Switch: '<S2685>/Switch' incorporates:
           *  Product: '<S2689>/Product'
           *  Reshape: '<S2688>/Reshape'
           */
          if (rtb_Equal) {
            rtb_DotProduct = UAM_Flight_control_B.Reshape[2];
          } else {
            rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
          }

          /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
           *  BusCreator generated from: '<S2680>/MATLAB Function'
           *  Product: '<S2689>/Product'
           *  UnitDelay generated from: '<S2>/Unit Delay'
           */
          UAM_Flight_control_DW.outWPS[4] = rtb_DotProduct;
          UAM_Flight_control_DW.outWPS[5] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
          UAM_Flight_control_DW.outWPS[7] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];

          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Constant: '<S2680>/Lookahead Distance'
           *  MATLAB Function: '<S2680>/MATLAB Function'
           *  MATLABSystem: '<S2680>/Waypoint Follower'
           *  Merge: '<S2671>/ Merge 2'
           *  SignalConversion generated from: '<S2680>/Bus Creator'
           *  UnitDelay generated from: '<S2>/Unit Delay1'
           * */
          UAM_Flight_cont_SystemCore_step(&UAM_Flight_control_DW.obj_l,
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
            UAM_Flight_control_DW.outWPS,
            UAM_Flight_control_P.LookaheadDistance_Value_p, v,
            &UAM_Flight_control_B.InnerLoopCmds.HeadingCmd, &rtb_Abs,
            &b_varargout_4);
          UAM_Flight_control_B.InnerLoopCmds.LAP[0] = v[0];
          UAM_Flight_control_B.InnerLoopCmds.LAP[1] = v[1];
          UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];

          /* Saturate: '<S2680>/Yaw Cmd Sat' incorporates:
           *  MATLABSystem: '<S2680>/Waypoint Follower'
           * */
          if (rtb_Abs > UAM_Flight_control_P.YawCmdSat_UpperSat_o) {
            /* BusCreator: '<S2680>/Bus Creator' incorporates:
             *  Merge: '<S2671>/ Merge 2'
             */
            UAM_Flight_control_B.InnerLoopCmds.YawCmd =
              UAM_Flight_control_P.YawCmdSat_UpperSat_o;
          } else if (rtb_Abs < UAM_Flight_control_P.YawCmdSat_LowerSat_f) {
            /* BusCreator: '<S2680>/Bus Creator' incorporates:
             *  Merge: '<S2671>/ Merge 2'
             */
            UAM_Flight_control_B.InnerLoopCmds.YawCmd =
              UAM_Flight_control_P.YawCmdSat_LowerSat_f;
          } else {
            /* BusCreator: '<S2680>/Bus Creator' incorporates:
             *  Merge: '<S2671>/ Merge 2'
             */
            UAM_Flight_control_B.InnerLoopCmds.YawCmd = rtb_Abs;
          }

          /* End of Saturate: '<S2680>/Yaw Cmd Sat' */

          /* Sum: '<S2686>/Sum1' incorporates:
           *  Product: '<S2689>/Product'
           */
          rtb_Abs = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
            rtb_Product_bz[0];
          rtb_Product_bz[0] = rtb_Abs;

          /* DotProduct: '<S2689>/Dot Product1' incorporates:
           *  Product: '<S2689>/Product'
           */
          d = rtb_Abs * rtb_Abs;

          /* Sum: '<S2686>/Sum1' incorporates:
           *  Product: '<S2689>/Product'
           */
          rtb_Abs = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
            rtb_Product_bz[1];
          rtb_Product_bz[1] = rtb_Abs;

          /* DotProduct: '<S2689>/Dot Product1' incorporates:
           *  Product: '<S2689>/Product'
           */
          d += rtb_Abs * rtb_Abs;

          /* Sum: '<S2686>/Sum1' incorporates:
           *  Product: '<S2689>/Product'
           *  Switch: '<S2685>/Switch'
           */
          rtb_Abs = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] -
            rtb_DotProduct;

          /* DotProduct: '<S2689>/Dot Product1' incorporates:
           *  Product: '<S2689>/Product'
           */
          d += rtb_Abs * rtb_Abs;

          /* Saturate: '<S2689>/Saturation' incorporates:
           *  DotProduct: '<S2689>/Dot Product1'
           */
          if (d > UAM_Flight_control_P.Saturation_UpperSat_hb) {
            d = UAM_Flight_control_P.Saturation_UpperSat_hb;
          } else if (d < UAM_Flight_control_P.Saturation_LowerSat_m) {
            d = UAM_Flight_control_P.Saturation_LowerSat_m;
          }

          /* Sqrt: '<S2689>/Sqrt' incorporates:
           *  Saturate: '<S2689>/Saturation'
           */
          rtb_DotProduct = sqrt(d);

          /* Merge: '<S2671>/ Merge ' incorporates:
           *  Constant: '<S2680>/Constant1'
           *  DataTypeConversion: '<S2680>/Data Type Conversion'
           *  DotProduct: '<S2686>/Dot Product'
           *  Product: '<S2689>/Product'
           *  RelationalOperator: '<S2680>/Relational Operator'
           *  Sum: '<S2686>/Sum'
           *  Sum: '<S2686>/Sum1'
           *  UnitDelay generated from: '<S2>/Unit Delay1'
           */
          UAM_Flight_control_B.Status_p = (uint8_T)
            (UAM_Flight_control_P.Constant1_Value_n >=
             ((UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
               UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * (rtb_Product_bz[0]
               / rtb_DotProduct) +
              (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
               UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) * (rtb_Product_bz[1]
               / rtb_DotProduct)) +
             (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] -
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2]) * (rtb_Abs /
              rtb_DotProduct));
          break;

         case 3U:
          UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_Orbit;

          /* Abs: '<S2678>/Abs' */
          rtb_Abs = fabs(UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2]);

          /* Signum: '<S2678>/Sign' */
          if (rtIsNaN(UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2])) {
            rtb_DotProduct = (rtNaN);
          } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2] < 0.0) {
            rtb_DotProduct = -1.0;
          } else {
            rtb_DotProduct = (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2]
                              > 0.0);
          }

          /* End of Signum: '<S2678>/Sign' */

          /* MATLABSystem: '<S2678>/UAV Orbit Follower' incorporates:
           *  Constant: '<S2678>/Lookahead Distance'
           *  UnitDelay generated from: '<S2>/Unit Delay1'
           * */
          UAM_Flight_control_DW.obj_cg.OrbitRadiusFlag = 0U;
          if (rtb_Abs <= 1.0) {
            rtb_Abs = 1.0;
            UAM_Flight_control_DW.obj_cg.OrbitRadiusFlag = 1U;
          }

          d = UAM_Flight_control_P.LookaheadDistance_Value_l;
          UAM_Flight_control_DW.obj_cg.LookaheadDistFlag = 0U;
          if (UAM_Flight_control_P.LookaheadDistance_Value_l < 0.1) {
            d = 0.1;
            UAM_Flight_control_DW.obj_cg.LookaheadDistFlag = 1U;
          }

          xyLookaheadPoint_tmp = UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0] -
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          xyLookaheadPoint[0] = xyLookaheadPoint_tmp;
          xyLookaheadPoint_tmp_0 = UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]
            - UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
          xyLookaheadPoint[1] = xyLookaheadPoint_tmp_0;
          if (UAM_Flight_control_norm_b(xyLookaheadPoint) <
              2.47032822920623E-323) {
            /* BusCreator: '<S2678>/Bus Creator' incorporates:
             *  Merge: '<S2671>/ Merge 2'
             */
            UAM_Flight_control_B.InnerLoopCmds.LAP[0] = rtb_Abs * cos
              (UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]) +
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
            UAM_Flight_control_B.InnerLoopCmds.LAP[1] = rtb_Abs * sin
              (UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]) +
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
            UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
            UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3];
            UAM_Flight_control_B.InnerLoopCmds.YawCmd =
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3];
            a = UAM_Flight_control_DW.obj_cg.NumCircles;
          } else {
            rtb_Equal = false;
            p = true;
            b_k = 0;
            exitg1 = false;
            while ((!exitg1) && (b_k < 3)) {
              if (!(UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[b_k] ==
                    UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[b_k])) {
                p = false;
                exitg1 = true;
              } else {
                b_k++;
              }
            }

            if (p) {
              rtb_Equal = true;
            }

            guard1 = false;
            if (!rtb_Equal) {
              guard1 = true;
            } else {
              rtb_Equal = false;
              if (UAM_Flight_control_DW.obj_cg.OrbitRadiusInternal == rtb_Abs) {
                rtb_Equal = true;
              }

              if (!rtb_Equal) {
                guard1 = true;
              }
            }

            if (guard1) {
              UAM_Flight_control_DW.obj_cg.NumCircles = 0.0;
              UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[0] =
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
              UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[1] =
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
              UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[2] =
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
              UAM_Flight_control_DW.obj_cg.OrbitRadiusInternal = rtb_Abs;
              UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag = true;
            }

            if (d >= rtb_Abs) {
              UAM_Flight_control_DW.obj_cg.LookaheadDistance = 0.9 * rtb_Abs;
            } else {
              UAM_Flight_control_DW.obj_cg.LookaheadDistance = d;
            }

            b_tmp[0] = xyLookaheadPoint_tmp;
            b_tmp[1] = xyLookaheadPoint_tmp_0;
            distToCenter = sqrt(xyLookaheadPoint_tmp_0 * xyLookaheadPoint_tmp_0
                                + xyLookaheadPoint_tmp * xyLookaheadPoint_tmp);
            a_tmp = rtb_Abs + UAM_Flight_control_DW.obj_cg.LookaheadDistance;
            a = fabs(a_tmp);
            rtb_Equal = (rtIsInf(a) || rtIsNaN(a));
            if (rtb_Equal) {
              d = (rtNaN);
            } else if (a < 4.4501477170144028E-308) {
              d = 4.94065645841247E-324;
            } else {
              frexp(a, &b_exponent);
              d = ldexp(1.0, b_exponent - 53);
            }

            guard1 = false;
            if (distToCenter >= a_tmp - 5.0 * d) {
              guard1 = true;
            } else {
              if (rtb_Equal) {
                d = (rtNaN);
              } else if (a < 4.4501477170144028E-308) {
                d = 4.94065645841247E-324;
              } else {
                frexp(a, &b_exponent_0);
                d = ldexp(1.0, b_exponent_0 - 53);
              }

              if (distToCenter <= (rtb_Abs -
                                   UAM_Flight_control_DW.obj_cg.LookaheadDistance)
                  + 5.0 * d) {
                guard1 = true;
              } else {
                if (UAM_Flight_control_DW.obj_cg.StartFlag) {
                  UAM_Flight_control_DW.obj_cg.PrevPosition[0] =
                    UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
                  UAM_Flight_control_DW.obj_cg.PrevPosition[1] =
                    UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
                  UAM_Flight_control_DW.obj_cg.StartFlag = false;
                }

                if ((rtb_DotProduct == 0.0) &&
                    (!UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag)) {
                  rtb_DotProduct =
                    UAM_Flight_control_DW.obj_cg.TurnDirectionInternal;
                }

                xyPose[0] = xyLookaheadPoint_tmp;
                turnVector[0] = UAM_Flight_control_DW.obj_cg.PrevPosition[0] -
                  UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
                xyPose[1] = xyLookaheadPoint_tmp_0;
                turnVector[1] = UAM_Flight_control_DW.obj_cg.PrevPosition[1] -
                  UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
                d = UAM_Flight_control_norm_b(xyPose);
                a_tmp = UAM_Flight_control_DW.obj_cg.LookaheadDistance *
                  UAM_Flight_control_DW.obj_cg.LookaheadDistance;
                a = ((a_tmp - rtb_Abs * rtb_Abs) + d * d) / (2.0 * d);
                rtb_Abs_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position
                  [0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
                rtb_Abs = rtb_Abs_tmp * a / d +
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
                y2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
                distToCenter = y2_tmp * a / d +
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
                a = sqrt(a_tmp - a * a);
                a_tmp = y2_tmp * a / d;
                b_tmp[0] = rtb_Abs - a_tmp;
                b_tmp[1] = a_tmp + rtb_Abs;
                d = rtb_Abs_tmp * a / d;
                rtb_Abs = d + distToCenter;
                distToCenter -= d;
                rtb_Product_bz[0] = turnVector[0];
                rtb_Product_bz[1] = turnVector[1];
                rtb_Product_bz[2] = 0.0;
                v[0] = xyLookaheadPoint_tmp;
                v[1] = xyLookaheadPoint_tmp_0;
                v[2] = 0.0;
                if (rtb_DotProduct < 0.0) {
                  rtb_Product_bz[0] = xyLookaheadPoint_tmp;
                  v[0] = turnVector[0];
                  rtb_Product_bz[1] = xyLookaheadPoint_tmp_0;
                  v[1] = turnVector[1];
                  rtb_Product_bz[2] = 0.0;
                  v[2] = 0.0;
                }

                d = UAM_Flight_control_norm_by(rtb_Product_bz);
                a = UAM_Flight_control_norm_by(v);
                rtb_Product_bz[0] /= d;
                v[0] /= a;
                rtb_Product_bz[1] /= d;
                v[1] /= a;
                turnVector[2] = rtb_Product_bz[0] * v[1] - v[0] *
                  rtb_Product_bz[1];
                UAM_Flight_control_DW.obj_cg.PrevPosition[0] =
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
                UAM_Flight_control_DW.obj_cg.PrevPosition[1] =
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
                UAM_Flight_control_DW.obj_cg.PrevPosition[2] =
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
                UAM_Flight_control_DW.obj_cg.NumCircles += rt_atan2d_snf
                  (turnVector[2], (rtb_Product_bz[0] * v[0] + rtb_Product_bz[1] *
                                   v[1]) + 0.0 / d * (0.0 / a)) / 2.0 /
                  3.1415926535897931;
                a = UAM_Flight_control_DW.obj_cg.NumCircles;
                if (rtIsNaN(rtb_DotProduct)) {
                  d = (rtNaN);
                } else if (rtb_DotProduct < 0.0) {
                  d = -1.0;
                } else {
                  d = (rtb_DotProduct > 0.0);
                }

                switch ((int32_T)d) {
                 case 1:
                  if ((b_tmp[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) *
                      y2_tmp - (rtb_Abs -
                                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) *
                      rtb_Abs_tmp > 0.0) {
                    xyLookaheadPoint[0] = b_tmp[0];
                    xyLookaheadPoint[1] = rtb_Abs;
                  } else {
                    xyLookaheadPoint[0] = b_tmp[1];
                    xyLookaheadPoint[1] = distToCenter;
                  }
                  break;

                 case -1:
                  if ((b_tmp[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) *
                      y2_tmp - (rtb_Abs -
                                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) *
                      rtb_Abs_tmp < 0.0) {
                    xyLookaheadPoint[0] = b_tmp[0];
                    xyLookaheadPoint[1] = rtb_Abs;
                  } else {
                    xyLookaheadPoint[0] = b_tmp[1];
                    xyLookaheadPoint[1] = distToCenter;
                  }
                  break;

                 default:
                  if (fabs(UAM_Flight_control_angdiff(rt_atan2d_snf(rtb_Abs -
                         UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1], b_tmp[0]
                         - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]),
                        UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3])) < fabs
                      (UAM_Flight_control_angdiff(rt_atan2d_snf(distToCenter -
                         UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1], b_tmp[1]
                         - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]),
                        UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]))) {
                    xyLookaheadPoint[0] = b_tmp[0];
                    xyLookaheadPoint[1] = rtb_Abs;
                  } else {
                    xyLookaheadPoint[0] = b_tmp[1];
                    xyLookaheadPoint[1] = distToCenter;
                  }

                  if ((xyLookaheadPoint[0] -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * y2_tmp -
                      (xyLookaheadPoint[1] -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) *
                      rtb_Abs_tmp > 0.0) {
                    UAM_Flight_control_DW.obj_cg.TurnDirectionInternal = 1.0;
                  } else {
                    UAM_Flight_control_DW.obj_cg.TurnDirectionInternal = -1.0;
                  }

                  UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag = false;
                  break;
                }

                /* BusCreator: '<S2678>/Bus Creator' incorporates:
                 *  Merge: '<S2671>/ Merge 2'
                 */
                UAM_Flight_control_B.InnerLoopCmds.YawCmd = rt_atan2d_snf(y2_tmp,
                  rtb_Abs_tmp);
              }
            }

            if (guard1) {
              d = UAM_Flight_control_norm_b(b_tmp);
              xyLookaheadPoint[0] = xyLookaheadPoint_tmp / d * rtb_Abs +
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
              xyLookaheadPoint[1] = xyLookaheadPoint_tmp_0 / d * rtb_Abs +
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];

              /* BusCreator: '<S2678>/Bus Creator' incorporates:
               *  Merge: '<S2671>/ Merge 2'
               */
              UAM_Flight_control_B.InnerLoopCmds.YawCmd = rt_atan2d_snf
                (xyLookaheadPoint[1] -
                 UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1], xyLookaheadPoint
                 [0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
              a = UAM_Flight_control_DW.obj_cg.NumCircles;
            }

            /* BusCreator: '<S2678>/Bus Creator' incorporates:
             *  Merge: '<S2671>/ Merge 2'
             */
            UAM_Flight_control_B.InnerLoopCmds.LAP[0] = xyLookaheadPoint[0];
            UAM_Flight_control_B.InnerLoopCmds.LAP[1] = xyLookaheadPoint[1];
            UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
            UAM_Flight_control_B.InnerLoopCmds.HeadingCmd = rt_atan2d_snf
              (xyLookaheadPoint[1] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1],
               xyLookaheadPoint[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
          }

          /* Merge: '<S2671>/ Merge ' incorporates:
           *  DataTypeConversion: '<S2678>/Data Type Conversion'
           *  MATLABSystem: '<S2678>/UAV Orbit Follower'
           *  RelationalOperator: '<S2678>/Relational Operator'
           * */
          UAM_Flight_control_B.Status_p = (uint8_T)(a >
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0]);
          break;

         case 6U:
          UAM_Flight_control_B.FlightMode_c = Transition;
          UAM_Flight_control_B.controlMode_n.inTransition = 1U;
          UAM_Flight_control_B.controlMode_n.TransitionCondition = 0U;
          UAM_Flight_control_DW.is_GuidanceLogic =
            UAM_Flight_IN_ForwardTransition;

          /* MATLAB Function: '<S2675>/MATLAB Function' */
          UAM_Flight_MATLABFunction_j
            (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position,
             UAM_Flight_control_DW.UnitDelay_3_DSTATE.position, rtb_wps_c,
             rtb_alt_0);

          /* BusCreator: '<S2675>/Bus Creator' */
          UAM_Flight_control_B.aacSP.airspeed = 0.0;
          UAM_Flight_control_B.aacSP.altitude = *rtb_alt_0;
          UAM_Flight_control_B.aacSP.course = 0.0;
          UAM_Flight_control_B.aacSP.L1 = 0.0;
          UAM_Flight_control_B.aacSP.climbrate = 0.0;

          /* BusCreator: '<S2675>/Bus Creator1' incorporates:
           *  Constant: '<S2675>/Constant1'
           *  Constant: '<S2675>/Constant2'
           *  Constant: '<S2675>/Constant3'
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
            UAM_Flight_control_P.Constant3_Value_m[0];
          UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
            UAM_Flight_control_P.Constant3_Value_m[1];
          UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
            UAM_Flight_control_P.Constant3_Value_m[2];
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_P.Constant1_Value_ag;
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.Constant2_Value_e;

          /* DataTypeConversion: '<S2675>/Data Type Conversion' incorporates:
           *  Constant: '<S2675>/Constant'
           */
          d = floor(UAM_Flight_control_P.Constant_Value_j);
          if (rtIsNaN(d) || rtIsInf(d)) {
            d = 0.0;
          } else {
            d = fmod(d, 256.0);
          }

          /* Merge: '<S2671>/ Merge ' incorporates:
           *  DataTypeConversion: '<S2675>/Data Type Conversion'
           */
          UAM_Flight_control_B.Status_p = (uint8_T)(d < 0.0 ? (int32_T)(uint8_T)
            -(int8_T)(uint8_T)-d : (int32_T)(uint8_T)d);
          break;

         default:
          UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_Land;
          UAM_Flight_control_DW.durationCounter_1 = 0U;
          UAM_Flight_control_DW.is_Land = UAM_Flight_control_IN_ToLand;

          /* MATLAB Function: '<S2677>/MATLAB Function' incorporates:
           *  UnitDelay generated from: '<S2>/Unit Delay'
           */
          UAM_Flight_control_DW.outWPS_i[0] =
            UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
          UAM_Flight_control_DW.outWPS_i[2] =
            UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
          UAM_Flight_control_DW.outWPS_i[4] =
            UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
          UAM_Flight_control_DW.outWPS_i[6] =
            UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];
          UAM_Flight_control_DW.outWPS_i[1] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          UAM_Flight_control_DW.outWPS_i[3] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
          UAM_Flight_control_DW.outWPS_i[5] =
            UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
          UAM_Flight_control_DW.outWPS_i[7] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
          memcpy(&rtb_wps_d[0], &UAM_Flight_control_DW.outWPS_i[0], sizeof
                 (real_T) << 3U);
          UAM_Flight_WaypointFollower(UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
            rtb_wps_d, UAM_Flight_control_P.LookaheadDistance_Value,
            &UAM_Flight_control_B.WaypointFollower_ni,
            &UAM_Flight_control_DW.WaypointFollower_ni);

          /* BusCreator: '<S2677>/Bus Creator1' incorporates:
           *  Constant: '<S2677>/Lookahead Distance'
           *  MATLABSystem: '<S2677>/Waypoint Follower'
           *  Merge: '<S2671>/ Merge 2'
           *  UnitDelay generated from: '<S2>/Unit Delay1'
           */
          UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
            UAM_Flight_control_B.WaypointFollower_ni.LAP[0];
          UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
            UAM_Flight_control_B.WaypointFollower_ni.LAP[1];
          UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
            UAM_Flight_control_B.WaypointFollower_ni.LAP[2];
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_B.WaypointFollower_ni.HeadingCmd;
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_B.WaypointFollower_ni.YawCmd;

          /* Merge: '<S2671>/ Merge ' incorporates:
           *  Constant: '<S2677>/Constant'
           *  SignalConversion generated from: '<S2677>/Status'
           */
          UAM_Flight_control_B.Status_p = UAM_Flight_control_P.Constant_Value_j5;
          break;
        }
      }
      break;
    }
  }

  /* End of UnitDelay generated from: '<S2>/Unit Delay' */
}

/* Function for Chart: '<S2667>/Guidance Mode Selector' */
static void UAM_exit_internal_GuidanceLogic(void)
{
  switch (UAM_Flight_control_DW.is_GuidanceLogic) {
   case UAM_Flight_co_IN_BackTransition:
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    break;

   case UAM_Flight__IN_FIXED_WING_ORBIT:
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    break;

   case UAM_Flig_IN_FIXED_WING_WAYPOINT:
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    break;

   case UAM_Flight_IN_ForwardTransition:
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    break;

   case UAM_Flight_control_IN_Land:
    switch (UAM_Flight_control_DW.is_Land) {
     case UAM_Flight_control_IN_Descend:
      UAM_Flight_control_DW.is_Land = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
      break;

     case UAM_Flight_control_IN_ToLand:
      UAM_Flight_control_DW.is_Land = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
      break;
    }

    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    break;

   case UAM_Flight_control_IN_Orbit:
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    break;

   case UAM_Flight_control_IN_Takeoff:
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    break;

   case UAM_Flight_control_IN_WP:
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    break;

   default:
    UAM_Flight_control_DW.is_FIXED_WING_ENTRY = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_c_IN_NO_ACTIVE_CHILD;
    break;
  }
}

/* Function for Chart: '<S2667>/Guidance Mode Selector' */
static void UAM_Flight_contro_GuidanceLogic(const uint8_T *mode_prev, const
  GuidanceStates *BusConversion_InsertedFor_Guida)
{
  real_T rtb_wps_c[8];
  real_T b_waypointsIn_data[6];
  real_T rtb_wps_i[6];
  real_T rtb_Product_ov[3];
  real_T turnVector[3];
  real_T turnVector_0[3];
  real_T unitVectorUtoV_tmp[3];
  real_T v[3];
  real_T b_tmp[2];
  real_T rtb_TmpSignalConversionAtUAVO_0[2];
  real_T xyLookaheadPoint[2];
  real_T xyPose[2];
  real_T absx;
  real_T distToCenter;
  real_T distToCenter_tmp;
  real_T rtb_DotProduct;
  real_T rtb_TmpSignalConversionAtUAVO_1;
  real_T rtb_TmpSignalConversionAtUAVO_2;
  real_T x2;
  real_T x2_tmp;
  real_T y2;
  real_T y2_tmp;
  int32_T b_exponent;
  int32_T b_exponent_0;
  int32_T b_k;
  int32_T i;
  int32_T tmp_size_idx_1;
  int32_T waypoints_data_tmp;
  int32_T waypoints_size_idx_0;
  int8_T tmp_data[2];
  uint8_T b_varargout_4;
  boolean_T x[3];
  boolean_T distinctWptsIdx[2];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T p;
  boolean_T rtb_Equal;
  guard1 = false;
  if (*mode_prev != UAM_Flight_control_DW.mode_start) {
    if ((UAM_Flight_control_DW.UnitDelay_1_DSTATE_e == 6) &&
        (UAM_Flight_control_B.FlightMode_c == FixedWing)) {
      UAM_exit_internal_GuidanceLogic();
      UAM_Flight_control_DW.temporalCounter_i1 = 0U;
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_con_IN_PreTransition;
      UAM_Flight_control_B.FlightMode_c = FixedWing;
      UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
      UAM_Flight_control_B.controlMode_n.attitude = 1U;
      UAM_Flight_control_B.controlMode_n.lateralGuidance = 1U;
      UAM_Flight_control_B.aacSP.L1 = 25.0;
      UAM_Flight_control_B.aacSP.airspeed = 14.0;

      /* BusCreator generated from: '<S2667>/Guidance Mode Selector' */
      UAM_Flight_control_B.aacSP.altitude = -BusConversion_InsertedFor_Guida->
        Xe[2];
      UAM_Flight_control_B.aacSP.course =
        BusConversion_InsertedFor_Guida->course;
    } else if ((UAM_Flight_control_DW.UnitDelay_1_DSTATE_e == 2) &&
               (UAM_Flight_control_B.FlightMode_c == FixedWing)) {
      /* Merge: '<S2671>/ Merge ' */
      UAM_Flight_control_B.Status_p = 0U;
      UAM_exit_internal_GuidanceLogic();
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flig_IN_FIXED_WING_WAYPOINT;
      UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
      UAM_Flight_control_B.controlMode_n.attitude = 1U;
      UAM_Flight_control_B.controlMode_n.lateralGuidance = 1U;

      /* BusCreator: '<S2674>/Bus Creator' incorporates:
       *  MATLAB Function: '<S2674>/MATLAB Function'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      UAM_Flight_MATLABFunction_j
        (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position,
         UAM_Flight_control_DW.UnitDelay_3_DSTATE.position, rtb_wps_i,
         &UAM_Flight_control_B.aacSP.altitude);

      /* Start for MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  BusCreator: '<S2674>/Bus Creator'
       *  Constant: '<S2674>/Lookahead Distance'
       */
      rtb_TmpSignalConversionAtUAVO_1 = UAM_Flight_control_P.control.L1 * 15.0;

      /* MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  Constant: '<S2674>/Lookahead Distance'
       */
      rtb_DotProduct = rtb_TmpSignalConversionAtUAVO_1;
      UAM_Flight_control_DW.obj_j.LookaheadDistFlag = 0U;
      if (rtb_TmpSignalConversionAtUAVO_1 < 60.0) {
        rtb_DotProduct = 60.0;
        UAM_Flight_control_DW.obj_j.LookaheadDistFlag = 1U;
      }

      UAM_Flight_control_DW.obj_j.InitialPose[0] = 0.0;
      UAM_Flight_control_DW.obj_j.InitialPose[1] = 0.0;
      UAM_Flight_control_DW.obj_j.InitialPose[2] = 0.0;
      UAM_Flight_control_DW.obj_j.InitialPose[3] = 0.0;
      UAM_Flight_control_DW.obj_j.NumWaypoints = 2.0;
      rtb_Equal = false;
      p = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k <= 5)) {
        i = ((b_k / 2) << 1) + b_k % 2;
        if (!(UAM_Flight_control_DW.obj_j.WaypointsInternal[i] == rtb_wps_i[i]))
        {
          p = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      if (p) {
        rtb_Equal = true;
      }

      if (!rtb_Equal) {
        for (i = 0; i < 6; i++) {
          UAM_Flight_control_DW.obj_j.WaypointsInternal[i] = rtb_wps_i[i];
        }

        UAM_Flight_control_DW.obj_j.WaypointIndex = 1.0;
      }

      distinctWptsIdx[1] = true;
      x[0] = (rtb_wps_i[0] != rtb_wps_i[1]);
      x[1] = (rtb_wps_i[2] != rtb_wps_i[3]);
      x[2] = (rtb_wps_i[4] != rtb_wps_i[5]);
      distinctWptsIdx[0] = false;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 3)) {
        if (x[b_k]) {
          distinctWptsIdx[0] = true;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      b_k = 0;
      for (i = 0; i < 2; i++) {
        /* MATLABSystem: '<S2674>/Waypoint Follower' */
        if (distinctWptsIdx[i]) {
          b_k++;
        }
      }

      tmp_size_idx_1 = b_k;
      b_k = 0;
      for (i = 0; i < 2; i++) {
        /* MATLABSystem: '<S2674>/Waypoint Follower' */
        if (distinctWptsIdx[i]) {
          /* Start for MATLABSystem: '<S2674>/Waypoint Follower' */
          tmp_data[b_k] = (int8_T)i;
          b_k++;
        }
      }

      /* MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  SignalConversion generated from: '<S2674>/Waypoint Follower'
       */
      for (i = 0; i < 3; i++) {
        for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
          b_waypointsIn_data[b_k + tmp_size_idx_1 * i] = rtb_wps_i[(i << 1) +
            tmp_data[b_k]];
        }
      }

      UAM_Flight_control_DW.obj_j.LookaheadDistance = rtb_DotProduct;
      if (tmp_size_idx_1 == 0) {
        /* BusCreator: '<S2674>/Bus Creator' incorporates:
         *  SignalConversion generated from: '<S2674>/Waypoint Follower'
         */
        UAM_Flight_control_B.aacSP.course =
          BusConversion_InsertedFor_Guida->course;

        /* Merge: '<S2671>/ Merge ' */
        UAM_Flight_control_B.Status_p = 1U;
      } else {
        guard2 = false;
        if (tmp_size_idx_1 == 1) {
          if (UAM_Flight_control_DW.obj_j.StartFlag) {
            UAM_Flight_control_DW.obj_j.InitialPose[0] =
              BusConversion_InsertedFor_Guida->Xe[0];
            UAM_Flight_control_DW.obj_j.InitialPose[1] =
              BusConversion_InsertedFor_Guida->Xe[1];
            UAM_Flight_control_DW.obj_j.InitialPose[2] =
              BusConversion_InsertedFor_Guida->Xe[2];
            UAM_Flight_control_DW.obj_j.InitialPose[3] =
              BusConversion_InsertedFor_Guida->course;
          }

          rtb_Product_ov[0] = b_waypointsIn_data[0] -
            BusConversion_InsertedFor_Guida->Xe[0];
          rtb_Product_ov[1] = b_waypointsIn_data[1] -
            BusConversion_InsertedFor_Guida->Xe[1];
          rtb_Product_ov[2] = b_waypointsIn_data[2] -
            BusConversion_InsertedFor_Guida->Xe[2];
          if (UAM_Flight_control_norm_by(rtb_Product_ov) < 1.4901161193847656E-8)
          {
            /* BusCreator: '<S2674>/Bus Creator' incorporates:
             *  SignalConversion generated from: '<S2674>/Waypoint Follower'
             */
            UAM_Flight_control_B.aacSP.course =
              BusConversion_InsertedFor_Guida->course;

            /* Merge: '<S2671>/ Merge ' */
            UAM_Flight_control_B.Status_p = 1U;
            UAM_Flight_control_DW.obj_j.StartFlag = false;
          } else {
            UAM_Flight_control_DW.obj_j.StartFlag = false;
            UAM_Flight_control_DW.obj_j.NumWaypoints = 2.0;
            waypoints_size_idx_0 = tmp_size_idx_1 + 1;
            for (i = 0; i < 3; i++) {
              waypoints_data_tmp = (tmp_size_idx_1 + 1) * i;
              rtb_wps_i[waypoints_data_tmp] =
                UAM_Flight_control_DW.obj_j.InitialPose[i];
              for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
                rtb_wps_i[(b_k + waypoints_data_tmp) + 1] =
                  b_waypointsIn_data[tmp_size_idx_1 * i + b_k];
              }
            }

            guard2 = true;
          }
        } else {
          waypoints_size_idx_0 = tmp_size_idx_1;
          b_k = tmp_size_idx_1 * 3;
          if (b_k - 1 >= 0) {
            memcpy(&rtb_wps_i[0], &b_waypointsIn_data[0], (uint32_T)b_k * sizeof
                   (real_T));
          }

          guard2 = true;
        }

        if (guard2) {
          rtb_Equal = false;
          if (UAM_Flight_control_DW.obj_j.WaypointIndex == 2.0) {
            rtb_Equal = true;
          }

          if (rtb_Equal) {
            UAM_Flight_control_DW.obj_j.LastWaypointFlag = true;
            UAM_Flight_control_DW.obj_j.WaypointIndex--;
          }

          rtb_Product_ov[0] = rtb_wps_i[(int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex - 1];
          v[0] = rtb_wps_i[(int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex +
            1.0) - 1];
          rtb_Product_ov[1] = rtb_wps_i[((int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0) -
            1];
          v[1] = rtb_wps_i[((int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex
            + 1.0) + waypoints_size_idx_0) - 1];
          rtb_Product_ov[2] = rtb_wps_i[((waypoints_size_idx_0 << 1) + (int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
          v[2] = rtb_wps_i[((int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex
            + 1.0) + (waypoints_size_idx_0 << 1)) - 1];
          turnVector_0[0] = BusConversion_InsertedFor_Guida->Xe[0] - rtb_wps_i
            [(int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) - 1];
          turnVector_0[1] = BusConversion_InsertedFor_Guida->Xe[1] - rtb_wps_i
            [((int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              waypoints_size_idx_0) - 1];
          turnVector_0[2] = BusConversion_InsertedFor_Guida->Xe[2] - rtb_wps_i
            [((int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              (waypoints_size_idx_0 << 1)) - 1];
          guard3 = false;
          if (UAM_Flight_control_norm_by(turnVector_0) <= 10.0) {
            guard3 = true;
          } else {
            unitVectorUtoV_tmp[0] = rtb_wps_i[(int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) - 1] -
              rtb_wps_i[(int32_T)UAM_Flight_control_DW.obj_j.WaypointIndex - 1];
            turnVector[0] = BusConversion_InsertedFor_Guida->Xe[0] - rtb_wps_i
              [(int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) - 1];
            rtb_DotProduct = rtb_wps_i[((int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              waypoints_size_idx_0) - 1];
            unitVectorUtoV_tmp[1] = rtb_DotProduct - rtb_wps_i[((int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0)
              - 1];
            turnVector[1] = BusConversion_InsertedFor_Guida->Xe[1] -
              rtb_DotProduct;
            rtb_DotProduct = rtb_wps_i[((int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              (waypoints_size_idx_0 << 1)) - 1];
            unitVectorUtoV_tmp[2] = rtb_DotProduct - rtb_wps_i
              [((waypoints_size_idx_0 << 1) + (int32_T)
                UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
            turnVector[2] = BusConversion_InsertedFor_Guida->Xe[2] -
              rtb_DotProduct;
            absx = UAM_Flight_control_norm_by(unitVectorUtoV_tmp);
            distToCenter = UAM_Flight_control_norm_by(turnVector);
            rtb_DotProduct = (unitVectorUtoV_tmp[0] / absx * (turnVector[0] /
              distToCenter) + unitVectorUtoV_tmp[1] / absx * (turnVector[1] /
              distToCenter)) + unitVectorUtoV_tmp[2] / absx * (turnVector[2] /
              distToCenter);
            if (rtIsNaN(rtb_DotProduct) || (rtb_DotProduct < 0.0)) {
            } else {
              guard3 = true;
            }
          }

          if (guard3) {
            UAM_Flight_control_DW.obj_j.WaypointIndex++;
            rtb_Equal = false;
            if (UAM_Flight_control_DW.obj_j.WaypointIndex == 2.0) {
              rtb_Equal = true;
            }

            if (rtb_Equal) {
              UAM_Flight_control_DW.obj_j.LastWaypointFlag = true;
              UAM_Flight_control_DW.obj_j.WaypointIndex--;
            }

            rtb_Product_ov[0] = rtb_wps_i[(int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex - 1];
            v[0] = rtb_wps_i[(int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex
              + 1.0) - 1];
            rtb_Product_ov[1] = rtb_wps_i[((int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0)
              - 1];
            v[1] = rtb_wps_i[((int32_T)
                              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0)
                              + waypoints_size_idx_0) - 1];
            rtb_Product_ov[2] = rtb_wps_i[((waypoints_size_idx_0 << 1) +
              (int32_T)UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
            v[2] = rtb_wps_i[((int32_T)
                              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0)
                              + (waypoints_size_idx_0 << 1)) - 1];
          }

          turnVector[0] = BusConversion_InsertedFor_Guida->Xe[0] -
            rtb_Product_ov[0];
          unitVectorUtoV_tmp[0] = v[0] - rtb_Product_ov[0];
          turnVector[1] = BusConversion_InsertedFor_Guida->Xe[1] -
            rtb_Product_ov[1];
          unitVectorUtoV_tmp[1] = v[1] - rtb_Product_ov[1];
          turnVector[2] = BusConversion_InsertedFor_Guida->Xe[2] -
            rtb_Product_ov[2];
          unitVectorUtoV_tmp[2] = v[2] - rtb_Product_ov[2];
          rtb_DotProduct = (unitVectorUtoV_tmp[0] * unitVectorUtoV_tmp[0] +
                            unitVectorUtoV_tmp[1] * unitVectorUtoV_tmp[1]) +
            unitVectorUtoV_tmp[2] * unitVectorUtoV_tmp[2];
          absx = ((turnVector[0] * unitVectorUtoV_tmp[0] + turnVector[1] *
                   unitVectorUtoV_tmp[1]) + turnVector[2] * unitVectorUtoV_tmp[2])
            / rtb_DotProduct;
          if (absx < 0.0) {
            x2 = UAM_Flight_control_norm_by(turnVector);
          } else if (absx > 1.0) {
            turnVector_0[0] = BusConversion_InsertedFor_Guida->Xe[0] - v[0];
            turnVector_0[1] = BusConversion_InsertedFor_Guida->Xe[1] - v[1];
            turnVector_0[2] = BusConversion_InsertedFor_Guida->Xe[2] - v[2];
            x2 = UAM_Flight_control_norm_by(turnVector_0);
          } else {
            turnVector_0[0] = BusConversion_InsertedFor_Guida->Xe[0] - (absx *
              unitVectorUtoV_tmp[0] + rtb_Product_ov[0]);
            turnVector_0[1] = BusConversion_InsertedFor_Guida->Xe[1] - (absx *
              unitVectorUtoV_tmp[1] + rtb_Product_ov[1]);
            turnVector_0[2] = BusConversion_InsertedFor_Guida->Xe[2] - (absx *
              unitVectorUtoV_tmp[2] + rtb_Product_ov[2]);
            x2 = UAM_Flight_control_norm_by(turnVector_0);
          }

          if (UAM_Flight_control_DW.obj_j.LastWaypointFlag) {
            turnVector_0[0] = BusConversion_InsertedFor_Guida->Xe[0] - (absx *
              unitVectorUtoV_tmp[0] + rtb_Product_ov[0]);
            turnVector_0[1] = BusConversion_InsertedFor_Guida->Xe[1] - (absx *
              unitVectorUtoV_tmp[1] + rtb_Product_ov[1]);
            turnVector_0[2] = BusConversion_InsertedFor_Guida->Xe[2] - (absx *
              unitVectorUtoV_tmp[2] + rtb_Product_ov[2]);
            x2 = UAM_Flight_control_norm_by(turnVector_0);
          }

          y2 = fabs(x2);
          if (rtIsInf(y2) || rtIsNaN(y2)) {
            absx = (rtNaN);
            y2 = (rtNaN);
          } else if (y2 < 4.4501477170144028E-308) {
            absx = 4.94065645841247E-324;
            y2 = 4.94065645841247E-324;
          } else {
            frexp(y2, &b_exponent);
            absx = ldexp(1.0, b_exponent - 53);
            frexp(y2, &b_exponent_0);
            y2 = ldexp(1.0, b_exponent_0 - 53);
          }

          if (UAM_Flight_control_DW.obj_j.LookaheadDistance <= fmax(sqrt(absx),
               5.0 * y2) + x2) {
            UAM_Flight_control_DW.obj_j.LookaheadDistance =
              UAM_Flight_control_DW.obj_j.LookaheadFactor * x2;
          }

          turnVector[0] = unitVectorUtoV_tmp[0];
          turnVector[1] = unitVectorUtoV_tmp[1];
          turnVector[2] = unitVectorUtoV_tmp[2];
          unitVectorUtoV_tmp[0] = rtb_Product_ov[0] -
            BusConversion_InsertedFor_Guida->Xe[0];
          unitVectorUtoV_tmp[1] = rtb_Product_ov[1] -
            BusConversion_InsertedFor_Guida->Xe[1];
          unitVectorUtoV_tmp[2] = rtb_Product_ov[2] -
            BusConversion_InsertedFor_Guida->Xe[2];
          x2 = ((turnVector[0] * unitVectorUtoV_tmp[0] + turnVector[1] *
                 unitVectorUtoV_tmp[1]) + turnVector[2] * unitVectorUtoV_tmp[2])
            * 2.0;
          absx = sqrt(x2 * x2 - (((unitVectorUtoV_tmp[0] * unitVectorUtoV_tmp[0]
            + unitVectorUtoV_tmp[1] * unitVectorUtoV_tmp[1]) +
            unitVectorUtoV_tmp[2] * unitVectorUtoV_tmp[2]) -
            UAM_Flight_control_DW.obj_j.LookaheadDistance *
            UAM_Flight_control_DW.obj_j.LookaheadDistance) * (4.0 *
            rtb_DotProduct));
          rtb_DotProduct = fmax((-x2 + absx) / 2.0 / rtb_DotProduct, (-x2 - absx)
                                / 2.0 / rtb_DotProduct);
          v[0] = (1.0 - rtb_DotProduct) * rtb_Product_ov[0] + rtb_DotProduct *
            v[0];
          v[1] = (1.0 - rtb_DotProduct) * rtb_Product_ov[1] + rtb_DotProduct *
            v[1];

          /* BusCreator: '<S2674>/Bus Creator' incorporates:
           *  SignalConversion generated from: '<S2674>/Waypoint Follower'
           */
          UAM_Flight_control_B.aacSP.course = rt_atan2d_snf(v[1] -
            BusConversion_InsertedFor_Guida->Xe[1], v[0] -
            BusConversion_InsertedFor_Guida->Xe[0]);
          rtb_Equal = false;
          if (UAM_Flight_control_DW.obj_j.LastWaypointFlag) {
            rtb_Equal = true;
          }

          if (rtb_Equal) {
            /* Merge: '<S2671>/ Merge ' */
            UAM_Flight_control_B.Status_p = 1U;
          }

          UAM_Flight_control_DW.obj_j.LastWaypointFlag = false;
        }
      }

      /* BusCreator: '<S2674>/Bus Creator' incorporates:
       *  Constant: '<S2674>/Constant'
       *  Constant: '<S2674>/Constant1'
       */
      UAM_Flight_control_B.aacSP.airspeed =
        UAM_Flight_control_P.control.cruiseSpeed;
      UAM_Flight_control_B.aacSP.L1 = rtb_TmpSignalConversionAtUAVO_1;
      UAM_Flight_control_B.aacSP.climbrate =
        UAM_Flight_control_P.Constant1_Value_ha;
    } else if (UAM_Flight_control_B.FlightMode_c == Transition) {
      UAM_Flight_control_B.controlMode_n.inTransition = 0U;
      UAM_exit_internal_GuidanceLogic();
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight__IN_FIXED_WING_ENTRY;
      enter_internal_FIXED_WING_ENTRY();
    } else if (UAM_Flight_control_B.FlightMode_c == BackTransition) {
      UAM_exit_internal_GuidanceLogic();
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_contr_IN_HOVER_ENTRY;
      UAM_Flight_control_B.FlightMode_c = Hover;
      UAM_Flight_control_B.controlMode_n.inTransition = 0U;
    } else if ((UAM_Flight_control_DW.UnitDelay_1_DSTATE_e == 1) &&
               (UAM_Flight_control_B.FlightMode_c == Hover)) {
      UAM_Flight_control_B.controlMode_n.inTransition = 0U;
      UAM_exit_internal_GuidanceLogic();
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_Takeoff;

      /* BusCreator: '<S2679>/Bus Creator' incorporates:
       *  Merge: '<S2671>/ Merge 2'
       *  SignalConversion generated from: '<S2679>/Bus Creator'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       *  UnitDelay generated from: '<S2>/Unit Delay1'
       */
      UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
        UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
      UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
        UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
      UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];

      /* Saturate: '<S2679>/Hdg. Cmd Sat' incorporates:
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] >
          UAM_Flight_control_P.HdgCmdSat_UpperSat_e) {
        /* BusCreator: '<S2679>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_P.HdgCmdSat_UpperSat_e;
      } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] <
                 UAM_Flight_control_P.HdgCmdSat_LowerSat_f) {
        /* BusCreator: '<S2679>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_P.HdgCmdSat_LowerSat_f;
      } else {
        /* BusCreator: '<S2679>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
      }

      /* Saturate: '<S2679>/Yaw Cmd Sat' incorporates:
       *  Constant: '<S2679>/Constant1'
       */
      if (UAM_Flight_control_P.Constant1_Value_b >
          UAM_Flight_control_P.YawCmdSat_UpperSat_f) {
        /* BusCreator: '<S2679>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.YawCmdSat_UpperSat_f;
      } else if (UAM_Flight_control_P.Constant1_Value_b <
                 UAM_Flight_control_P.YawCmdSat_LowerSat_p) {
        /* BusCreator: '<S2679>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.YawCmdSat_LowerSat_p;
      } else {
        /* BusCreator: '<S2679>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.Constant1_Value_b;
      }

      /* Merge: '<S2671>/ Merge ' incorporates:
       *  Constant: '<S2679>/Constant'
       *  SignalConversion generated from: '<S2679>/Status'
       */
      UAM_Flight_control_B.Status_p = UAM_Flight_control_P.Constant_Value_gm;
    } else if ((UAM_Flight_control_DW.UnitDelay_1_DSTATE_e == 3) &&
               (UAM_Flight_control_B.FlightMode_c == FixedWing)) {
      UAM_exit_internal_GuidanceLogic();
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight__IN_FIXED_WING_ORBIT;
      UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
      UAM_Flight_control_B.controlMode_n.attitude = 1U;
      UAM_Flight_control_B.controlMode_n.lateralGuidance = 1U;

      /* MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
       *  Constant: '<S2673>/Lookahead Distance'
       *  SignalConversion generated from: '<S2673>/UAV Orbit Follower'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0];
      UAM_Flight_control_DW.obj_jc.OrbitRadiusFlag = 0U;
      if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0] <= 60.0) {
        x2 = 60.0;
        UAM_Flight_control_DW.obj_jc.OrbitRadiusFlag = 1U;
      }

      absx = UAM_Flight_control_P.control.L1;
      UAM_Flight_control_DW.obj_jc.LookaheadDistFlag = 0U;
      if (UAM_Flight_control_P.control.L1 < 60.0) {
        absx = 60.0;
        UAM_Flight_control_DW.obj_jc.LookaheadDistFlag = 1U;
      }

      rtb_TmpSignalConversionAtUAVO_1 = BusConversion_InsertedFor_Guida->Xe[0] -
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
      rtb_TmpSignalConversionAtUAVO_0[0] = rtb_TmpSignalConversionAtUAVO_1;
      rtb_TmpSignalConversionAtUAVO_2 = BusConversion_InsertedFor_Guida->Xe[1] -
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
      rtb_TmpSignalConversionAtUAVO_0[1] = rtb_TmpSignalConversionAtUAVO_2;
      if (UAM_Flight_control_norm_b(rtb_TmpSignalConversionAtUAVO_0) <
          2.47032822920623E-323) {
        /* BusCreator: '<S2673>/Bus Creator' */
        UAM_Flight_control_B.aacSP.course =
          BusConversion_InsertedFor_Guida->course;
        distToCenter = UAM_Flight_control_DW.obj_jc.NumCircles;
      } else {
        rtb_Equal = false;
        p = true;
        b_k = 0;
        exitg1 = false;
        while ((!exitg1) && (b_k < 3)) {
          if (!(UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[b_k] ==
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[b_k])) {
            p = false;
            exitg1 = true;
          } else {
            b_k++;
          }
        }

        if (p) {
          rtb_Equal = true;
        }

        guard2 = false;
        if (!rtb_Equal) {
          guard2 = true;
        } else {
          rtb_Equal = false;
          if (UAM_Flight_control_DW.obj_jc.OrbitRadiusInternal == x2) {
            rtb_Equal = true;
          }

          if (!rtb_Equal) {
            guard2 = true;
          }
        }

        if (guard2) {
          UAM_Flight_control_DW.obj_jc.NumCircles = 0.0;
          UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[0] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[1] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
          UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[2] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
          UAM_Flight_control_DW.obj_jc.OrbitRadiusInternal = x2;
          UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag = true;
        }

        if (absx >= x2) {
          UAM_Flight_control_DW.obj_jc.LookaheadDistance = 0.9 * x2;
        } else {
          UAM_Flight_control_DW.obj_jc.LookaheadDistance = absx;
        }

        b_tmp[0] = rtb_TmpSignalConversionAtUAVO_1;
        b_tmp[1] = rtb_TmpSignalConversionAtUAVO_2;
        distToCenter = sqrt(rtb_TmpSignalConversionAtUAVO_2 *
                            rtb_TmpSignalConversionAtUAVO_2 +
                            rtb_TmpSignalConversionAtUAVO_1 *
                            rtb_TmpSignalConversionAtUAVO_1);
        absx = fabs(x2 + UAM_Flight_control_DW.obj_jc.LookaheadDistance);
        if (rtIsInf(absx) || rtIsNaN(absx)) {
          absx = (rtNaN);
        } else if (absx < 4.4501477170144028E-308) {
          absx = 4.94065645841247E-324;
        } else {
          frexp(absx, &b_exponent);
          absx = ldexp(1.0, b_exponent - 53);
        }

        guard2 = false;
        if (distToCenter >= (x2 + UAM_Flight_control_DW.obj_jc.LookaheadDistance)
            - 5.0 * absx) {
          guard2 = true;
        } else {
          absx = fabs(x2 + UAM_Flight_control_DW.obj_jc.LookaheadDistance);
          if (rtIsInf(absx) || rtIsNaN(absx)) {
            absx = (rtNaN);
          } else if (absx < 4.4501477170144028E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &b_exponent_0);
            absx = ldexp(1.0, b_exponent_0 - 53);
          }

          if (distToCenter <= (x2 -
                               UAM_Flight_control_DW.obj_jc.LookaheadDistance) +
              5.0 * absx) {
            guard2 = true;
          } else {
            if (UAM_Flight_control_DW.obj_jc.StartFlag) {
              UAM_Flight_control_DW.obj_jc.PrevPosition[0] =
                BusConversion_InsertedFor_Guida->Xe[0];
              UAM_Flight_control_DW.obj_jc.PrevPosition[1] =
                BusConversion_InsertedFor_Guida->Xe[1];
              UAM_Flight_control_DW.obj_jc.StartFlag = false;
            }

            if ((UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[1] == 0.0) && (
                 !UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag)) {
              rtb_DotProduct =
                UAM_Flight_control_DW.obj_jc.TurnDirectionInternal;
            } else {
              rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[1];
            }

            rtb_Product_ov[2] = 0.0;
            xyPose[0] = rtb_TmpSignalConversionAtUAVO_1;
            rtb_Product_ov[0] = UAM_Flight_control_DW.obj_jc.PrevPosition[0] -
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            v[0] = rtb_TmpSignalConversionAtUAVO_1;
            xyPose[1] = rtb_TmpSignalConversionAtUAVO_2;
            rtb_Product_ov[1] = UAM_Flight_control_DW.obj_jc.PrevPosition[1] -
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
            v[1] = rtb_TmpSignalConversionAtUAVO_2;
            absx = UAM_Flight_control_norm_b(xyPose);
            distToCenter_tmp = UAM_Flight_control_DW.obj_jc.LookaheadDistance *
              UAM_Flight_control_DW.obj_jc.LookaheadDistance;
            distToCenter = ((distToCenter_tmp - x2 * x2) + absx * absx) / (2.0 *
              absx);
            x2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
              BusConversion_InsertedFor_Guida->Xe[0];
            x2 = x2_tmp * distToCenter / absx +
              BusConversion_InsertedFor_Guida->Xe[0];
            y2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
              BusConversion_InsertedFor_Guida->Xe[1];
            y2 = y2_tmp * distToCenter / absx +
              BusConversion_InsertedFor_Guida->Xe[1];
            distToCenter = sqrt(distToCenter_tmp - distToCenter * distToCenter);
            b_tmp[0] = x2 - y2_tmp * distToCenter / absx;
            b_tmp[1] = y2_tmp * distToCenter / absx + x2;
            absx = x2_tmp * distToCenter / absx;
            x2 = absx + y2;
            y2 -= absx;
            v[2] = 0.0;
            if (rtb_DotProduct < 0.0) {
              rtb_Product_ov[0] = rtb_TmpSignalConversionAtUAVO_1;
              rtb_Product_ov[1] = rtb_TmpSignalConversionAtUAVO_2;
              rtb_Product_ov[2] = 0.0;
              v[0] = UAM_Flight_control_DW.obj_jc.PrevPosition[0] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
              v[1] = UAM_Flight_control_DW.obj_jc.PrevPosition[1] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
              v[2] = 0.0;
            }

            absx = UAM_Flight_control_norm_by(rtb_Product_ov);
            distToCenter = UAM_Flight_control_norm_by(v);
            rtb_Product_ov[0] /= absx;
            v[0] /= distToCenter;
            rtb_Product_ov[1] /= absx;
            v[1] /= distToCenter;
            turnVector[2] = rtb_Product_ov[0] * v[1] - v[0] * rtb_Product_ov[1];
            UAM_Flight_control_DW.obj_jc.PrevPosition[0] =
              BusConversion_InsertedFor_Guida->Xe[0];
            UAM_Flight_control_DW.obj_jc.PrevPosition[1] =
              BusConversion_InsertedFor_Guida->Xe[1];
            UAM_Flight_control_DW.obj_jc.PrevPosition[2] =
              BusConversion_InsertedFor_Guida->Xe[2];
            UAM_Flight_control_DW.obj_jc.NumCircles += rt_atan2d_snf(turnVector
              [2], (rtb_Product_ov[0] * v[0] + rtb_Product_ov[1] * v[1]) + 0.0 /
              absx * (0.0 / distToCenter)) / 2.0 / 3.1415926535897931;
            distToCenter = UAM_Flight_control_DW.obj_jc.NumCircles;
            if (rtIsNaN(rtb_DotProduct)) {
              absx = (rtNaN);
            } else if (rtb_DotProduct < 0.0) {
              absx = -1.0;
            } else {
              absx = (rtb_DotProduct > 0.0);
            }

            switch ((int32_T)absx) {
             case 1:
              if ((b_tmp[0] - BusConversion_InsertedFor_Guida->Xe[0]) * y2_tmp -
                  (x2 - BusConversion_InsertedFor_Guida->Xe[1]) * x2_tmp > 0.0)
              {
                rtb_DotProduct = b_tmp[0];
                y2 = x2;
              } else {
                rtb_DotProduct = b_tmp[1];
              }
              break;

             case -1:
              if ((b_tmp[0] - BusConversion_InsertedFor_Guida->Xe[0]) * y2_tmp -
                  (x2 - BusConversion_InsertedFor_Guida->Xe[1]) * x2_tmp < 0.0)
              {
                rtb_DotProduct = b_tmp[0];
                y2 = x2;
              } else {
                rtb_DotProduct = b_tmp[1];
              }
              break;

             default:
              if (fabs(UAM_Flight_control_angdiff(rt_atan2d_snf(x2 -
                     BusConversion_InsertedFor_Guida->Xe[1], b_tmp[0] -
                     BusConversion_InsertedFor_Guida->Xe[0]),
                    BusConversion_InsertedFor_Guida->course)) < fabs
                  (UAM_Flight_control_angdiff(rt_atan2d_snf(y2 -
                     BusConversion_InsertedFor_Guida->Xe[1], b_tmp[1] -
                     BusConversion_InsertedFor_Guida->Xe[0]),
                    BusConversion_InsertedFor_Guida->course))) {
                rtb_DotProduct = b_tmp[0];
                y2 = x2;
              } else {
                rtb_DotProduct = b_tmp[1];
              }

              if ((rtb_DotProduct - BusConversion_InsertedFor_Guida->Xe[0]) *
                  y2_tmp - (y2 - BusConversion_InsertedFor_Guida->Xe[1]) *
                  x2_tmp > 0.0) {
                UAM_Flight_control_DW.obj_jc.TurnDirectionInternal = 1.0;
              } else {
                UAM_Flight_control_DW.obj_jc.TurnDirectionInternal = -1.0;
              }

              UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag = false;
              break;
            }
          }
        }

        if (guard2) {
          absx = UAM_Flight_control_norm_b(b_tmp);
          rtb_DotProduct = rtb_TmpSignalConversionAtUAVO_1 / absx * x2 +
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          y2 = rtb_TmpSignalConversionAtUAVO_2 / absx * x2 +
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
          distToCenter = UAM_Flight_control_DW.obj_jc.NumCircles;
        }

        /* BusCreator: '<S2673>/Bus Creator' */
        UAM_Flight_control_B.aacSP.course = rt_atan2d_snf(y2 -
          BusConversion_InsertedFor_Guida->Xe[1], rtb_DotProduct -
          BusConversion_InsertedFor_Guida->Xe[0]);
      }

      /* BusCreator: '<S2673>/Bus Creator' incorporates:
       *  Constant: '<S2673>/Constant'
       *  Constant: '<S2673>/Constant1'
       *  Constant: '<S2673>/Lookahead Distance'
       *  UnaryMinus: '<S2673>/Unary Minus'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      UAM_Flight_control_B.aacSP.airspeed =
        UAM_Flight_control_P.control.cruiseSpeed;
      UAM_Flight_control_B.aacSP.altitude =
        -UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
      UAM_Flight_control_B.aacSP.L1 = UAM_Flight_control_P.control.L1;
      UAM_Flight_control_B.aacSP.climbrate =
        UAM_Flight_control_P.Constant1_Value_m;

      /* Merge: '<S2671>/ Merge ' incorporates:
       *  Abs: '<S2673>/Abs1'
       *  DataTypeConversion: '<S2673>/Data Type Conversion'
       *  MATLABSystem: '<S2673>/UAV Orbit Follower'
       *  RelationalOperator: '<S2673>/Relational Operator'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       * */
      UAM_Flight_control_B.Status_p = (uint8_T)(fabs(distToCenter) >
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2]);
    } else if (UAM_Flight_control_B.FlightMode_c == Hover) {
      UAM_Flight_control_B.controlMode_n.inTransition = 0U;

      /* UnitDelay generated from: '<S2>/Unit Delay' incorporates:
       *  Constant: '<S2677>/Lookahead Distance'
       *  UnitDelay generated from: '<S2>/Unit Delay1'
       */
      switch (UAM_Flight_control_DW.UnitDelay_1_DSTATE_e) {
       case 2U:
        UAM_exit_internal_GuidanceLogic();
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_WP;

        /* RelationalOperator: '<S2685>/Equal' incorporates:
         *  Constant: '<S2685>/Constant'
         */
        rtb_Equal = (UAM_Flight_control_P.Constant_Value_p ==
                     UAM_Flight_control_DW.UnitDelay_3_DSTATE.mode);

        /* Outputs for Triggered SubSystem: '<S2685>/Triggered Subsystem' incorporates:
         *  TriggerPort: '<S2688>/Trigger'
         */
        if (rtb_Equal && (UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE
                          != POS_ZCSIG)) {
          /* Reshape: '<S2688>/Reshape' incorporates:
           *  UnitDelay generated from: '<S2>/Unit Delay1'
           */
          UAM_Flight_control_B.Reshape[0] =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
          UAM_Flight_control_B.Reshape[1] =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
          UAM_Flight_control_B.Reshape[2] =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
        }

        UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_Equal;

        /* End of Outputs for SubSystem: '<S2685>/Triggered Subsystem' */

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         */
        UAM_Flight_control_DW.outWPS[6] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];

        /* Switch: '<S2685>/Switch' incorporates:
         *  Product: '<S2689>/Product'
         *  Reshape: '<S2688>/Reshape'
         */
        if (rtb_Equal) {
          rtb_DotProduct = UAM_Flight_control_B.Reshape[0];
        } else {
          rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
        }

        rtb_Product_ov[0] = rtb_DotProduct;

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         *  Product: '<S2689>/Product'
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_control_DW.outWPS[0] = rtb_DotProduct;
        UAM_Flight_control_DW.outWPS[1] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];

        /* Switch: '<S2685>/Switch' incorporates:
         *  Product: '<S2689>/Product'
         *  Reshape: '<S2688>/Reshape'
         */
        if (rtb_Equal) {
          rtb_DotProduct = UAM_Flight_control_B.Reshape[1];
        } else {
          rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
        }

        rtb_Product_ov[1] = rtb_DotProduct;

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         *  Product: '<S2689>/Product'
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_control_DW.outWPS[2] = rtb_DotProduct;
        UAM_Flight_control_DW.outWPS[3] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];

        /* Switch: '<S2685>/Switch' incorporates:
         *  Product: '<S2689>/Product'
         *  Reshape: '<S2688>/Reshape'
         */
        if (rtb_Equal) {
          rtb_DotProduct = UAM_Flight_control_B.Reshape[2];
        } else {
          rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
        }

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         *  Product: '<S2689>/Product'
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_control_DW.outWPS[4] = rtb_DotProduct;
        UAM_Flight_control_DW.outWPS[5] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
        UAM_Flight_control_DW.outWPS[7] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];

        /* BusCreator: '<S2680>/Bus Creator' incorporates:
         *  Constant: '<S2680>/Lookahead Distance'
         *  MATLAB Function: '<S2680>/MATLAB Function'
         *  MATLABSystem: '<S2680>/Waypoint Follower'
         *  Merge: '<S2671>/ Merge 2'
         *  SignalConversion generated from: '<S2680>/Bus Creator'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         * */
        UAM_Flight_cont_SystemCore_step(&UAM_Flight_control_DW.obj_l,
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
          UAM_Flight_control_DW.outWPS,
          UAM_Flight_control_P.LookaheadDistance_Value_p, v,
          &UAM_Flight_control_B.InnerLoopCmds.HeadingCmd, &x2, &b_varargout_4);
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] = v[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] = v[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];

        /* Saturate: '<S2680>/Yaw Cmd Sat' incorporates:
         *  MATLABSystem: '<S2680>/Waypoint Follower'
         * */
        if (x2 > UAM_Flight_control_P.YawCmdSat_UpperSat_o) {
          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_UpperSat_o;
        } else if (x2 < UAM_Flight_control_P.YawCmdSat_LowerSat_f) {
          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_LowerSat_f;
        } else {
          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd = x2;
        }

        /* Sum: '<S2686>/Sum1' incorporates:
         *  Product: '<S2689>/Product'
         */
        x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
          rtb_Product_ov[0];
        rtb_Product_ov[0] = x2;

        /* DotProduct: '<S2689>/Dot Product1' incorporates:
         *  Product: '<S2689>/Product'
         */
        absx = x2 * x2;

        /* Sum: '<S2686>/Sum1' incorporates:
         *  Product: '<S2689>/Product'
         */
        x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
          rtb_Product_ov[1];
        rtb_Product_ov[1] = x2;

        /* DotProduct: '<S2689>/Dot Product1' incorporates:
         *  Product: '<S2689>/Product'
         */
        y2 = x2 * x2;

        /* Sum: '<S2686>/Sum1' incorporates:
         *  Product: '<S2689>/Product'
         *  Switch: '<S2685>/Switch'
         */
        x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] -
          rtb_DotProduct;

        /* DotProduct: '<S2689>/Dot Product1' incorporates:
         *  Product: '<S2689>/Product'
         */
        absx = x2 * x2 + (y2 + absx);

        /* Saturate: '<S2689>/Saturation' incorporates:
         *  DotProduct: '<S2689>/Dot Product1'
         */
        if (absx > UAM_Flight_control_P.Saturation_UpperSat_hb) {
          absx = UAM_Flight_control_P.Saturation_UpperSat_hb;
        } else if (absx < UAM_Flight_control_P.Saturation_LowerSat_m) {
          absx = UAM_Flight_control_P.Saturation_LowerSat_m;
        }

        /* Sqrt: '<S2689>/Sqrt' incorporates:
         *  Saturate: '<S2689>/Saturation'
         */
        rtb_DotProduct = sqrt(absx);

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  Constant: '<S2680>/Constant1'
         *  DataTypeConversion: '<S2680>/Data Type Conversion'
         *  DotProduct: '<S2686>/Dot Product'
         *  Product: '<S2689>/Product'
         *  RelationalOperator: '<S2680>/Relational Operator'
         *  Sum: '<S2686>/Sum'
         *  Sum: '<S2686>/Sum1'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         */
        UAM_Flight_control_B.Status_p = (uint8_T)
          (UAM_Flight_control_P.Constant1_Value_n >=
           ((UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
             UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * (rtb_Product_ov[0] /
             rtb_DotProduct) +
            (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
             UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) * (rtb_Product_ov[1] /
             rtb_DotProduct)) +
           (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] -
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2]) * (x2 / rtb_DotProduct));
        break;

       case 3U:
        UAM_exit_internal_GuidanceLogic();
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_Orbit;

        /* Abs: '<S2678>/Abs' */
        x2 = fabs(UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2]);

        /* Signum: '<S2678>/Sign' */
        if (rtIsNaN(UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2])) {
          rtb_DotProduct = (rtNaN);
        } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2] < 0.0) {
          rtb_DotProduct = -1.0;
        } else {
          rtb_DotProduct = (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2] >
                            0.0);
        }

        /* MATLABSystem: '<S2678>/UAV Orbit Follower' incorporates:
         *  Constant: '<S2678>/Lookahead Distance'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         * */
        UAM_Flight_control_DW.obj_cg.OrbitRadiusFlag = 0U;
        if (x2 <= 1.0) {
          x2 = 1.0;
          UAM_Flight_control_DW.obj_cg.OrbitRadiusFlag = 1U;
        }

        absx = UAM_Flight_control_P.LookaheadDistance_Value_l;
        UAM_Flight_control_DW.obj_cg.LookaheadDistFlag = 0U;
        if (UAM_Flight_control_P.LookaheadDistance_Value_l < 0.1) {
          absx = 0.1;
          UAM_Flight_control_DW.obj_cg.LookaheadDistFlag = 1U;
        }

        rtb_TmpSignalConversionAtUAVO_1 =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0] -
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
        rtb_TmpSignalConversionAtUAVO_0[0] = rtb_TmpSignalConversionAtUAVO_1;
        rtb_TmpSignalConversionAtUAVO_2 =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1] -
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
        rtb_TmpSignalConversionAtUAVO_0[1] = rtb_TmpSignalConversionAtUAVO_2;
        if (UAM_Flight_control_norm_b(rtb_TmpSignalConversionAtUAVO_0) <
            2.47032822920623E-323) {
          /* BusCreator: '<S2678>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.LAP[0] = x2 * cos
            (UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]) +
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
          UAM_Flight_control_B.InnerLoopCmds.LAP[1] = x2 * sin
            (UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]) +
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
          UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3];
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3];
          distToCenter = UAM_Flight_control_DW.obj_cg.NumCircles;
        } else {
          rtb_Equal = false;
          p = true;
          b_k = 0;
          exitg1 = false;
          while ((!exitg1) && (b_k < 3)) {
            if (!(UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[b_k] ==
                  UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[b_k])) {
              p = false;
              exitg1 = true;
            } else {
              b_k++;
            }
          }

          if (p) {
            rtb_Equal = true;
          }

          guard2 = false;
          if (!rtb_Equal) {
            guard2 = true;
          } else {
            rtb_Equal = false;
            if (UAM_Flight_control_DW.obj_cg.OrbitRadiusInternal == x2) {
              rtb_Equal = true;
            }

            if (!rtb_Equal) {
              guard2 = true;
            }
          }

          if (guard2) {
            UAM_Flight_control_DW.obj_cg.NumCircles = 0.0;
            UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[0] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[1] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
            UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[2] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
            UAM_Flight_control_DW.obj_cg.OrbitRadiusInternal = x2;
            UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag = true;
          }

          if (absx >= x2) {
            UAM_Flight_control_DW.obj_cg.LookaheadDistance = 0.9 * x2;
          } else {
            UAM_Flight_control_DW.obj_cg.LookaheadDistance = absx;
          }

          b_tmp[0] = rtb_TmpSignalConversionAtUAVO_1;
          b_tmp[1] = rtb_TmpSignalConversionAtUAVO_2;
          distToCenter = sqrt(rtb_TmpSignalConversionAtUAVO_2 *
                              rtb_TmpSignalConversionAtUAVO_2 +
                              rtb_TmpSignalConversionAtUAVO_1 *
                              rtb_TmpSignalConversionAtUAVO_1);
          absx = fabs(x2 + UAM_Flight_control_DW.obj_cg.LookaheadDistance);
          if (rtIsInf(absx) || rtIsNaN(absx)) {
            absx = (rtNaN);
          } else if (absx < 4.4501477170144028E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &b_exponent);
            absx = ldexp(1.0, b_exponent - 53);
          }

          guard2 = false;
          if (distToCenter >= (x2 +
                               UAM_Flight_control_DW.obj_cg.LookaheadDistance) -
              5.0 * absx) {
            guard2 = true;
          } else {
            absx = fabs(x2 + UAM_Flight_control_DW.obj_cg.LookaheadDistance);
            if (rtIsInf(absx) || rtIsNaN(absx)) {
              absx = (rtNaN);
            } else if (absx < 4.4501477170144028E-308) {
              absx = 4.94065645841247E-324;
            } else {
              frexp(absx, &b_exponent_0);
              absx = ldexp(1.0, b_exponent_0 - 53);
            }

            if (distToCenter <= (x2 -
                                 UAM_Flight_control_DW.obj_cg.LookaheadDistance)
                + 5.0 * absx) {
              guard2 = true;
            } else {
              if (UAM_Flight_control_DW.obj_cg.StartFlag) {
                UAM_Flight_control_DW.obj_cg.PrevPosition[0] =
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
                UAM_Flight_control_DW.obj_cg.PrevPosition[1] =
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
                UAM_Flight_control_DW.obj_cg.StartFlag = false;
              }

              if ((rtb_DotProduct == 0.0) &&
                  (!UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag)) {
                rtb_DotProduct =
                  UAM_Flight_control_DW.obj_cg.TurnDirectionInternal;
              }

              rtb_Product_ov[2] = 0.0;
              xyPose[0] = rtb_TmpSignalConversionAtUAVO_1;
              rtb_Product_ov[0] = UAM_Flight_control_DW.obj_cg.PrevPosition[0] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
              v[0] = rtb_TmpSignalConversionAtUAVO_1;
              xyPose[1] = rtb_TmpSignalConversionAtUAVO_2;
              rtb_Product_ov[1] = UAM_Flight_control_DW.obj_cg.PrevPosition[1] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
              v[1] = rtb_TmpSignalConversionAtUAVO_2;
              absx = UAM_Flight_control_norm_b(xyPose);
              distToCenter_tmp = UAM_Flight_control_DW.obj_cg.LookaheadDistance *
                UAM_Flight_control_DW.obj_cg.LookaheadDistance;
              distToCenter = ((distToCenter_tmp - x2 * x2) + absx * absx) / (2.0
                * absx);
              x2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
              x2 = x2_tmp * distToCenter / absx +
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
              y2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
              y2 = y2_tmp * distToCenter / absx +
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
              distToCenter = sqrt(distToCenter_tmp - distToCenter * distToCenter);
              distToCenter_tmp = y2_tmp * distToCenter / absx;
              b_tmp[0] = x2 - distToCenter_tmp;
              b_tmp[1] = distToCenter_tmp + x2;
              x2 = x2_tmp * distToCenter / absx + y2;
              y2 -= x2_tmp * distToCenter / absx;
              v[2] = 0.0;
              if (rtb_DotProduct < 0.0) {
                rtb_Product_ov[0] = rtb_TmpSignalConversionAtUAVO_1;
                rtb_Product_ov[1] = rtb_TmpSignalConversionAtUAVO_2;
                rtb_Product_ov[2] = 0.0;
                v[0] = UAM_Flight_control_DW.obj_cg.PrevPosition[0] -
                  UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
                v[1] = UAM_Flight_control_DW.obj_cg.PrevPosition[1] -
                  UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
                v[2] = 0.0;
              }

              absx = UAM_Flight_control_norm_by(rtb_Product_ov);
              distToCenter = UAM_Flight_control_norm_by(v);
              rtb_Product_ov[0] /= absx;
              v[0] /= distToCenter;
              rtb_Product_ov[1] /= absx;
              v[1] /= distToCenter;
              turnVector[2] = rtb_Product_ov[0] * v[1] - v[0] * rtb_Product_ov[1];
              UAM_Flight_control_DW.obj_cg.PrevPosition[0] =
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
              UAM_Flight_control_DW.obj_cg.PrevPosition[1] =
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
              UAM_Flight_control_DW.obj_cg.PrevPosition[2] =
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
              UAM_Flight_control_DW.obj_cg.NumCircles += rt_atan2d_snf
                (turnVector[2], (rtb_Product_ov[0] * v[0] + rtb_Product_ov[1] *
                                 v[1]) + 0.0 / absx * (0.0 / distToCenter)) /
                2.0 / 3.1415926535897931;
              distToCenter = UAM_Flight_control_DW.obj_cg.NumCircles;
              if (rtIsNaN(rtb_DotProduct)) {
                absx = (rtNaN);
              } else if (rtb_DotProduct < 0.0) {
                absx = -1.0;
              } else {
                absx = (rtb_DotProduct > 0.0);
              }

              switch ((int32_T)absx) {
               case 1:
                if ((b_tmp[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) *
                    y2_tmp - (x2 - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1])
                    * x2_tmp > 0.0) {
                  xyLookaheadPoint[0] = b_tmp[0];
                  xyLookaheadPoint[1] = x2;
                } else {
                  xyLookaheadPoint[0] = b_tmp[1];
                  xyLookaheadPoint[1] = y2;
                }
                break;

               case -1:
                if ((b_tmp[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) *
                    y2_tmp - (x2 - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1])
                    * x2_tmp < 0.0) {
                  xyLookaheadPoint[0] = b_tmp[0];
                  xyLookaheadPoint[1] = x2;
                } else {
                  xyLookaheadPoint[0] = b_tmp[1];
                  xyLookaheadPoint[1] = y2;
                }
                break;

               default:
                if (fabs(UAM_Flight_control_angdiff(rt_atan2d_snf(x2 -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1], b_tmp[0] -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]),
                      UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3])) < fabs
                    (UAM_Flight_control_angdiff(rt_atan2d_snf(y2 -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1], b_tmp[1] -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]),
                      UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]))) {
                  xyLookaheadPoint[0] = b_tmp[0];
                  xyLookaheadPoint[1] = x2;
                } else {
                  xyLookaheadPoint[0] = b_tmp[1];
                  xyLookaheadPoint[1] = y2;
                }

                if ((xyLookaheadPoint[0] -
                     UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * y2_tmp -
                    (xyLookaheadPoint[1] -
                     UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) * x2_tmp >
                    0.0) {
                  UAM_Flight_control_DW.obj_cg.TurnDirectionInternal = 1.0;
                } else {
                  UAM_Flight_control_DW.obj_cg.TurnDirectionInternal = -1.0;
                }

                UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag = false;
                break;
              }

              /* BusCreator: '<S2678>/Bus Creator' incorporates:
               *  Merge: '<S2671>/ Merge 2'
               */
              UAM_Flight_control_B.InnerLoopCmds.YawCmd = rt_atan2d_snf
                (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
                 UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1],
                 UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
                 UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
            }
          }

          if (guard2) {
            absx = UAM_Flight_control_norm_b(b_tmp);
            xyLookaheadPoint[0] = rtb_TmpSignalConversionAtUAVO_1 / absx * x2 +
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            xyLookaheadPoint[1] = rtb_TmpSignalConversionAtUAVO_2 / absx * x2 +
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];

            /* BusCreator: '<S2678>/Bus Creator' incorporates:
             *  Merge: '<S2671>/ Merge 2'
             */
            UAM_Flight_control_B.InnerLoopCmds.YawCmd = rt_atan2d_snf
              (xyLookaheadPoint[1] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1],
               xyLookaheadPoint[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
            distToCenter = UAM_Flight_control_DW.obj_cg.NumCircles;
          }

          /* BusCreator: '<S2678>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.LAP[0] = xyLookaheadPoint[0];
          UAM_Flight_control_B.InnerLoopCmds.LAP[1] = xyLookaheadPoint[1];
          UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd = rt_atan2d_snf
            (xyLookaheadPoint[1] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1],
             xyLookaheadPoint[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
        }

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  DataTypeConversion: '<S2678>/Data Type Conversion'
         *  MATLABSystem: '<S2678>/UAV Orbit Follower'
         *  RelationalOperator: '<S2678>/Relational Operator'
         * */
        UAM_Flight_control_B.Status_p = (uint8_T)(distToCenter >
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0]);
        break;

       case 6U:
        UAM_Flight_control_B.FlightMode_c = Transition;
        UAM_Flight_control_B.controlMode_n.inTransition = 1U;
        UAM_Flight_control_B.controlMode_n.TransitionCondition = 0U;
        UAM_exit_internal_GuidanceLogic();
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_IN_ForwardTransition;

        /* BusCreator: '<S2675>/Bus Creator' incorporates:
         *  MATLAB Function: '<S2675>/MATLAB Function'
         */
        UAM_Flight_MATLABFunction_j
          (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position,
           UAM_Flight_control_DW.UnitDelay_3_DSTATE.position, rtb_wps_i,
           &UAM_Flight_control_B.aacSP.altitude);
        UAM_Flight_control_B.aacSP.airspeed = 0.0;
        UAM_Flight_control_B.aacSP.course = 0.0;
        UAM_Flight_control_B.aacSP.L1 = 0.0;
        UAM_Flight_control_B.aacSP.climbrate = 0.0;

        /* BusCreator: '<S2675>/Bus Creator1' incorporates:
         *  Constant: '<S2675>/Constant1'
         *  Constant: '<S2675>/Constant2'
         *  Constant: '<S2675>/Constant3'
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_P.Constant3_Value_m[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_P.Constant3_Value_m[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_P.Constant3_Value_m[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_P.Constant1_Value_ag;
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.Constant2_Value_e;

        /* DataTypeConversion: '<S2675>/Data Type Conversion' incorporates:
         *  Constant: '<S2675>/Constant'
         */
        absx = floor(UAM_Flight_control_P.Constant_Value_j);
        if (rtIsNaN(absx) || rtIsInf(absx)) {
          absx = 0.0;
        } else {
          absx = fmod(absx, 256.0);
        }

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  DataTypeConversion: '<S2675>/Data Type Conversion'
         */
        UAM_Flight_control_B.Status_p = (uint8_T)(absx < 0.0 ? (int32_T)(uint8_T)
          -(int8_T)(uint8_T)-absx : (int32_T)(uint8_T)absx);
        break;

       default:
        UAM_exit_internal_GuidanceLogic();
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_Land;
        UAM_Flight_control_DW.durationCounter_1 = 0U;
        UAM_Flight_control_DW.is_Land = UAM_Flight_control_IN_ToLand;

        /* MATLAB Function: '<S2677>/MATLAB Function' incorporates:
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_control_DW.outWPS_i[0] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
        UAM_Flight_control_DW.outWPS_i[2] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
        UAM_Flight_control_DW.outWPS_i[4] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
        UAM_Flight_control_DW.outWPS_i[6] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];
        UAM_Flight_control_DW.outWPS_i[1] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
        UAM_Flight_control_DW.outWPS_i[3] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
        UAM_Flight_control_DW.outWPS_i[5] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
        UAM_Flight_control_DW.outWPS_i[7] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
        memcpy(&rtb_wps_c[0], &UAM_Flight_control_DW.outWPS_i[0], sizeof(real_T)
               << 3U);
        UAM_Flight_WaypointFollower(UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
          rtb_wps_c, UAM_Flight_control_P.LookaheadDistance_Value,
          &UAM_Flight_control_B.WaypointFollower_ni,
          &UAM_Flight_control_DW.WaypointFollower_ni);

        /* BusCreator: '<S2677>/Bus Creator1' incorporates:
         *  Constant: '<S2677>/Lookahead Distance'
         *  MATLABSystem: '<S2677>/Waypoint Follower'
         *  Merge: '<S2671>/ Merge 2'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_B.WaypointFollower_ni.LAP[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_B.WaypointFollower_ni.LAP[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_B.WaypointFollower_ni.LAP[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_B.WaypointFollower_ni.HeadingCmd;
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_B.WaypointFollower_ni.YawCmd;

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  Constant: '<S2677>/Constant'
         *  SignalConversion generated from: '<S2677>/Status'
         */
        UAM_Flight_control_B.Status_p = UAM_Flight_control_P.Constant_Value_j5;
        break;
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    switch (UAM_Flight_control_DW.is_GuidanceLogic) {
     case UAM_Flight_cont_IN_BackCOMPLETE:
      /* Merge: '<S2671>/ Merge ' */
      UAM_Flight_control_B.Status_p = 1U;
      UAM_Flight_control_B.controlMode_n.BackTransitionCondition = 1U;
      break;

     case UAM_Flight_co_IN_BackTransition:
      /* UnitDelay: '<S2>/Unit Delay2' incorporates:
       *  Merge: '<S2671>/ Merge '
       */
      if (UAM_Flight_cont_backConditioMet
          (UAM_Flight_control_DW.UnitDelay2_DSTATE_l)) {
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_cont_IN_BackCOMPLETE;
        UAM_Flight_control_B.Status_p = 1U;
        UAM_Flight_control_B.controlMode_n.BackTransitionCondition = 1U;
      } else {
        /* BusCreator: '<S2672>/Bus Creator1' incorporates:
         *  Constant: '<S2672>/Constant1'
         *  Constant: '<S2672>/Constant2'
         *  Gain: '<S2672>/Gain'
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_P.Gain_Gain_cf *
          BusConversion_InsertedFor_Guida->Xe[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_P.Gain_Gain_cf *
          BusConversion_InsertedFor_Guida->Xe[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_P.Gain_Gain_cf *
          BusConversion_InsertedFor_Guida->Xe[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_P.Constant1_Value_hc;
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.Constant2_Value_a;

        /* DataTypeConversion: '<S2672>/Data Type Conversion' incorporates:
         *  Constant: '<S2672>/Constant'
         */
        absx = floor(UAM_Flight_control_P.Constant_Value_l);
        if (rtIsNaN(absx) || rtIsInf(absx)) {
          absx = 0.0;
        } else {
          absx = fmod(absx, 256.0);
        }

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  DataTypeConversion: '<S2672>/Data Type Conversion'
         */
        UAM_Flight_control_B.Status_p = (uint8_T)(absx < 0.0 ? (int32_T)(uint8_T)
          -(int8_T)(uint8_T)-absx : (int32_T)(uint8_T)absx);
      }
      break;

     case UAM_Flight__IN_FIXED_WING_ENTRY:
      UAM_Flight_con_FIXED_WING_ENTRY(BusConversion_InsertedFor_Guida,
        &rtb_DotProduct, rtb_wps_i);
      break;

     case UAM_Flight__IN_FIXED_WING_ORBIT:
      /* MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
       *  Constant: '<S2673>/Lookahead Distance'
       *  SignalConversion generated from: '<S2673>/UAV Orbit Follower'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0];
      UAM_Flight_control_DW.obj_jc.OrbitRadiusFlag = 0U;
      if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0] <= 60.0) {
        x2 = 60.0;
        UAM_Flight_control_DW.obj_jc.OrbitRadiusFlag = 1U;
      }

      absx = UAM_Flight_control_P.control.L1;
      UAM_Flight_control_DW.obj_jc.LookaheadDistFlag = 0U;
      if (UAM_Flight_control_P.control.L1 < 60.0) {
        absx = 60.0;
        UAM_Flight_control_DW.obj_jc.LookaheadDistFlag = 1U;
      }

      rtb_TmpSignalConversionAtUAVO_1 = BusConversion_InsertedFor_Guida->Xe[0] -
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
      rtb_TmpSignalConversionAtUAVO_0[0] = rtb_TmpSignalConversionAtUAVO_1;
      rtb_TmpSignalConversionAtUAVO_2 = BusConversion_InsertedFor_Guida->Xe[1] -
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
      rtb_TmpSignalConversionAtUAVO_0[1] = rtb_TmpSignalConversionAtUAVO_2;
      if (UAM_Flight_control_norm_b(rtb_TmpSignalConversionAtUAVO_0) <
          2.47032822920623E-323) {
        /* BusCreator: '<S2673>/Bus Creator' */
        UAM_Flight_control_B.aacSP.course =
          BusConversion_InsertedFor_Guida->course;
        distToCenter = UAM_Flight_control_DW.obj_jc.NumCircles;
      } else {
        rtb_Equal = false;
        p = true;
        b_k = 0;
        exitg1 = false;
        while ((!exitg1) && (b_k < 3)) {
          if (!(UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[b_k] ==
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[b_k])) {
            p = false;
            exitg1 = true;
          } else {
            b_k++;
          }
        }

        if (p) {
          rtb_Equal = true;
        }

        guard2 = false;
        if (!rtb_Equal) {
          guard2 = true;
        } else {
          rtb_Equal = false;
          if (UAM_Flight_control_DW.obj_jc.OrbitRadiusInternal == x2) {
            rtb_Equal = true;
          }

          if (!rtb_Equal) {
            guard2 = true;
          }
        }

        if (guard2) {
          UAM_Flight_control_DW.obj_jc.NumCircles = 0.0;
          UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[0] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[1] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
          UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[2] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
          UAM_Flight_control_DW.obj_jc.OrbitRadiusInternal = x2;
          UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag = true;
        }

        if (absx >= x2) {
          UAM_Flight_control_DW.obj_jc.LookaheadDistance = 0.9 * x2;
        } else {
          UAM_Flight_control_DW.obj_jc.LookaheadDistance = absx;
        }

        b_tmp[0] = rtb_TmpSignalConversionAtUAVO_1;
        b_tmp[1] = rtb_TmpSignalConversionAtUAVO_2;
        distToCenter = sqrt(rtb_TmpSignalConversionAtUAVO_2 *
                            rtb_TmpSignalConversionAtUAVO_2 +
                            rtb_TmpSignalConversionAtUAVO_1 *
                            rtb_TmpSignalConversionAtUAVO_1);
        absx = fabs(x2 + UAM_Flight_control_DW.obj_jc.LookaheadDistance);
        if (rtIsInf(absx) || rtIsNaN(absx)) {
          absx = (rtNaN);
        } else if (absx < 4.4501477170144028E-308) {
          absx = 4.94065645841247E-324;
        } else {
          frexp(absx, &b_exponent);
          absx = ldexp(1.0, b_exponent - 53);
        }

        y2 = x2 + UAM_Flight_control_DW.obj_jc.LookaheadDistance;
        guard2 = false;
        if (distToCenter >= y2 - 5.0 * absx) {
          guard2 = true;
        } else {
          absx = fabs(y2);
          if (rtIsInf(absx) || rtIsNaN(absx)) {
            absx = (rtNaN);
          } else if (absx < 4.4501477170144028E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &b_exponent_0);
            absx = ldexp(1.0, b_exponent_0 - 53);
          }

          if (distToCenter <= (x2 -
                               UAM_Flight_control_DW.obj_jc.LookaheadDistance) +
              5.0 * absx) {
            guard2 = true;
          } else {
            if (UAM_Flight_control_DW.obj_jc.StartFlag) {
              UAM_Flight_control_DW.obj_jc.PrevPosition[0] =
                BusConversion_InsertedFor_Guida->Xe[0];
              UAM_Flight_control_DW.obj_jc.PrevPosition[1] =
                BusConversion_InsertedFor_Guida->Xe[1];
              UAM_Flight_control_DW.obj_jc.StartFlag = false;
            }

            if ((UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[1] == 0.0) && (
                 !UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag)) {
              rtb_DotProduct =
                UAM_Flight_control_DW.obj_jc.TurnDirectionInternal;
            } else {
              rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[1];
            }

            rtb_Product_ov[2] = 0.0;
            xyPose[0] = rtb_TmpSignalConversionAtUAVO_1;
            rtb_Product_ov[0] = UAM_Flight_control_DW.obj_jc.PrevPosition[0] -
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            v[0] = rtb_TmpSignalConversionAtUAVO_1;
            xyPose[1] = rtb_TmpSignalConversionAtUAVO_2;
            rtb_Product_ov[1] = UAM_Flight_control_DW.obj_jc.PrevPosition[1] -
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
            v[1] = rtb_TmpSignalConversionAtUAVO_2;
            absx = UAM_Flight_control_norm_b(xyPose);
            distToCenter_tmp = UAM_Flight_control_DW.obj_jc.LookaheadDistance *
              UAM_Flight_control_DW.obj_jc.LookaheadDistance;
            distToCenter = ((distToCenter_tmp - x2 * x2) + absx * absx) / (2.0 *
              absx);
            x2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
              BusConversion_InsertedFor_Guida->Xe[0];
            x2 = x2_tmp * distToCenter / absx +
              BusConversion_InsertedFor_Guida->Xe[0];
            y2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
              BusConversion_InsertedFor_Guida->Xe[1];
            y2 = y2_tmp * distToCenter / absx +
              BusConversion_InsertedFor_Guida->Xe[1];
            distToCenter = sqrt(distToCenter_tmp - distToCenter * distToCenter);
            b_tmp[0] = x2 - y2_tmp * distToCenter / absx;
            b_tmp[1] = y2_tmp * distToCenter / absx + x2;
            absx = x2_tmp * distToCenter / absx;
            x2 = absx + y2;
            y2 -= absx;
            v[2] = 0.0;
            if (rtb_DotProduct < 0.0) {
              rtb_Product_ov[0] = rtb_TmpSignalConversionAtUAVO_1;
              rtb_Product_ov[1] = rtb_TmpSignalConversionAtUAVO_2;
              rtb_Product_ov[2] = 0.0;
              v[0] = UAM_Flight_control_DW.obj_jc.PrevPosition[0] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
              v[1] = UAM_Flight_control_DW.obj_jc.PrevPosition[1] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
              v[2] = 0.0;
            }

            absx = UAM_Flight_control_norm_by(rtb_Product_ov);
            distToCenter = UAM_Flight_control_norm_by(v);
            rtb_Product_ov[0] /= absx;
            v[0] /= distToCenter;
            rtb_Product_ov[1] /= absx;
            v[1] /= distToCenter;
            turnVector[2] = rtb_Product_ov[0] * v[1] - v[0] * rtb_Product_ov[1];
            UAM_Flight_control_DW.obj_jc.PrevPosition[0] =
              BusConversion_InsertedFor_Guida->Xe[0];
            UAM_Flight_control_DW.obj_jc.PrevPosition[1] =
              BusConversion_InsertedFor_Guida->Xe[1];
            UAM_Flight_control_DW.obj_jc.PrevPosition[2] =
              BusConversion_InsertedFor_Guida->Xe[2];
            UAM_Flight_control_DW.obj_jc.NumCircles += rt_atan2d_snf(turnVector
              [2], (rtb_Product_ov[0] * v[0] + rtb_Product_ov[1] * v[1]) + 0.0 /
              absx * (0.0 / distToCenter)) / 2.0 / 3.1415926535897931;
            distToCenter = UAM_Flight_control_DW.obj_jc.NumCircles;
            if (rtIsNaN(rtb_DotProduct)) {
              absx = (rtNaN);
            } else if (rtb_DotProduct < 0.0) {
              absx = -1.0;
            } else {
              absx = (rtb_DotProduct > 0.0);
            }

            switch ((int32_T)absx) {
             case 1:
              if ((b_tmp[0] - BusConversion_InsertedFor_Guida->Xe[0]) * y2_tmp -
                  (x2 - BusConversion_InsertedFor_Guida->Xe[1]) * x2_tmp > 0.0)
              {
                rtb_DotProduct = b_tmp[0];
                y2 = x2;
              } else {
                rtb_DotProduct = b_tmp[1];
              }
              break;

             case -1:
              if ((b_tmp[0] - BusConversion_InsertedFor_Guida->Xe[0]) * y2_tmp -
                  (x2 - BusConversion_InsertedFor_Guida->Xe[1]) * x2_tmp < 0.0)
              {
                rtb_DotProduct = b_tmp[0];
                y2 = x2;
              } else {
                rtb_DotProduct = b_tmp[1];
              }
              break;

             default:
              if (fabs(UAM_Flight_control_angdiff(rt_atan2d_snf(x2 -
                     BusConversion_InsertedFor_Guida->Xe[1], b_tmp[0] -
                     BusConversion_InsertedFor_Guida->Xe[0]),
                    BusConversion_InsertedFor_Guida->course)) < fabs
                  (UAM_Flight_control_angdiff(rt_atan2d_snf(y2 -
                     BusConversion_InsertedFor_Guida->Xe[1], b_tmp[1] -
                     BusConversion_InsertedFor_Guida->Xe[0]),
                    BusConversion_InsertedFor_Guida->course))) {
                rtb_DotProduct = b_tmp[0];
                y2 = x2;
              } else {
                rtb_DotProduct = b_tmp[1];
              }

              if ((rtb_DotProduct - BusConversion_InsertedFor_Guida->Xe[0]) *
                  y2_tmp - (y2 - BusConversion_InsertedFor_Guida->Xe[1]) *
                  x2_tmp > 0.0) {
                UAM_Flight_control_DW.obj_jc.TurnDirectionInternal = 1.0;
              } else {
                UAM_Flight_control_DW.obj_jc.TurnDirectionInternal = -1.0;
              }

              UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag = false;
              break;
            }
          }
        }

        if (guard2) {
          absx = UAM_Flight_control_norm_b(b_tmp);
          rtb_DotProduct = rtb_TmpSignalConversionAtUAVO_1 / absx * x2 +
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          y2 = rtb_TmpSignalConversionAtUAVO_2 / absx * x2 +
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
          distToCenter = UAM_Flight_control_DW.obj_jc.NumCircles;
        }

        /* BusCreator: '<S2673>/Bus Creator' */
        UAM_Flight_control_B.aacSP.course = rt_atan2d_snf(y2 -
          BusConversion_InsertedFor_Guida->Xe[1], rtb_DotProduct -
          BusConversion_InsertedFor_Guida->Xe[0]);
      }

      /* BusCreator: '<S2673>/Bus Creator' incorporates:
       *  Constant: '<S2673>/Constant'
       *  Constant: '<S2673>/Constant1'
       *  Constant: '<S2673>/Lookahead Distance'
       *  UnaryMinus: '<S2673>/Unary Minus'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      UAM_Flight_control_B.aacSP.airspeed =
        UAM_Flight_control_P.control.cruiseSpeed;
      UAM_Flight_control_B.aacSP.altitude =
        -UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
      UAM_Flight_control_B.aacSP.L1 = UAM_Flight_control_P.control.L1;
      UAM_Flight_control_B.aacSP.climbrate =
        UAM_Flight_control_P.Constant1_Value_m;

      /* Merge: '<S2671>/ Merge ' incorporates:
       *  Abs: '<S2673>/Abs1'
       *  DataTypeConversion: '<S2673>/Data Type Conversion'
       *  MATLABSystem: '<S2673>/UAV Orbit Follower'
       *  RelationalOperator: '<S2673>/Relational Operator'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       * */
      UAM_Flight_control_B.Status_p = (uint8_T)(fabs(distToCenter) >
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2]);
      break;

     case UAM_Flig_IN_FIXED_WING_WAYPOINT:
      /* BusCreator: '<S2674>/Bus Creator' incorporates:
       *  MATLAB Function: '<S2674>/MATLAB Function'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      UAM_Flight_MATLABFunction_j
        (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position,
         UAM_Flight_control_DW.UnitDelay_3_DSTATE.position, rtb_wps_i,
         &UAM_Flight_control_B.aacSP.altitude);

      /* Start for MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  BusCreator: '<S2674>/Bus Creator'
       *  Constant: '<S2674>/Lookahead Distance'
       */
      rtb_TmpSignalConversionAtUAVO_1 = UAM_Flight_control_P.control.L1 * 15.0;

      /* MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  Constant: '<S2674>/Lookahead Distance'
       */
      rtb_DotProduct = rtb_TmpSignalConversionAtUAVO_1;
      UAM_Flight_control_DW.obj_j.LookaheadDistFlag = 0U;
      if (rtb_TmpSignalConversionAtUAVO_1 < 60.0) {
        rtb_DotProduct = 60.0;
        UAM_Flight_control_DW.obj_j.LookaheadDistFlag = 1U;
      }

      UAM_Flight_control_DW.obj_j.InitialPose[0] = 0.0;
      UAM_Flight_control_DW.obj_j.InitialPose[1] = 0.0;
      UAM_Flight_control_DW.obj_j.InitialPose[2] = 0.0;
      UAM_Flight_control_DW.obj_j.InitialPose[3] = 0.0;
      UAM_Flight_control_DW.obj_j.NumWaypoints = 2.0;
      rtb_Equal = false;
      p = true;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k <= 5)) {
        i = ((b_k / 2) << 1) + b_k % 2;
        if (!(UAM_Flight_control_DW.obj_j.WaypointsInternal[i] == rtb_wps_i[i]))
        {
          p = false;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      if (p) {
        rtb_Equal = true;
      }

      if (!rtb_Equal) {
        for (i = 0; i < 6; i++) {
          UAM_Flight_control_DW.obj_j.WaypointsInternal[i] = rtb_wps_i[i];
        }

        UAM_Flight_control_DW.obj_j.WaypointIndex = 1.0;
      }

      distinctWptsIdx[1] = true;
      x[0] = (rtb_wps_i[0] != rtb_wps_i[1]);
      x[1] = (rtb_wps_i[2] != rtb_wps_i[3]);
      x[2] = (rtb_wps_i[4] != rtb_wps_i[5]);
      distinctWptsIdx[0] = false;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 3)) {
        if (x[b_k]) {
          distinctWptsIdx[0] = true;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      b_k = 0;
      for (i = 0; i < 2; i++) {
        /* MATLABSystem: '<S2674>/Waypoint Follower' */
        if (distinctWptsIdx[i]) {
          b_k++;
        }
      }

      tmp_size_idx_1 = b_k;
      b_k = 0;
      for (i = 0; i < 2; i++) {
        /* MATLABSystem: '<S2674>/Waypoint Follower' */
        if (distinctWptsIdx[i]) {
          /* Start for MATLABSystem: '<S2674>/Waypoint Follower' */
          tmp_data[b_k] = (int8_T)i;
          b_k++;
        }
      }

      /* MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  SignalConversion generated from: '<S2674>/Waypoint Follower'
       */
      for (i = 0; i < 3; i++) {
        for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
          b_waypointsIn_data[b_k + tmp_size_idx_1 * i] = rtb_wps_i[(i << 1) +
            tmp_data[b_k]];
        }
      }

      UAM_Flight_control_DW.obj_j.LookaheadDistance = rtb_DotProduct;
      if (tmp_size_idx_1 == 0) {
        /* BusCreator: '<S2674>/Bus Creator' incorporates:
         *  SignalConversion generated from: '<S2674>/Waypoint Follower'
         */
        UAM_Flight_control_B.aacSP.course =
          BusConversion_InsertedFor_Guida->course;

        /* Merge: '<S2671>/ Merge ' */
        UAM_Flight_control_B.Status_p = 1U;
      } else {
        guard2 = false;
        if (tmp_size_idx_1 == 1) {
          if (UAM_Flight_control_DW.obj_j.StartFlag) {
            UAM_Flight_control_DW.obj_j.InitialPose[0] =
              BusConversion_InsertedFor_Guida->Xe[0];
            UAM_Flight_control_DW.obj_j.InitialPose[1] =
              BusConversion_InsertedFor_Guida->Xe[1];
            UAM_Flight_control_DW.obj_j.InitialPose[2] =
              BusConversion_InsertedFor_Guida->Xe[2];
            UAM_Flight_control_DW.obj_j.InitialPose[3] =
              BusConversion_InsertedFor_Guida->course;
          }

          rtb_Product_ov[0] = b_waypointsIn_data[0] -
            BusConversion_InsertedFor_Guida->Xe[0];
          rtb_Product_ov[1] = b_waypointsIn_data[1] -
            BusConversion_InsertedFor_Guida->Xe[1];
          rtb_Product_ov[2] = b_waypointsIn_data[2] -
            BusConversion_InsertedFor_Guida->Xe[2];
          if (UAM_Flight_control_norm_by(rtb_Product_ov) < 1.4901161193847656E-8)
          {
            /* BusCreator: '<S2674>/Bus Creator' incorporates:
             *  SignalConversion generated from: '<S2674>/Waypoint Follower'
             */
            UAM_Flight_control_B.aacSP.course =
              BusConversion_InsertedFor_Guida->course;

            /* Merge: '<S2671>/ Merge ' */
            UAM_Flight_control_B.Status_p = 1U;
            UAM_Flight_control_DW.obj_j.StartFlag = false;
          } else {
            UAM_Flight_control_DW.obj_j.StartFlag = false;
            UAM_Flight_control_DW.obj_j.NumWaypoints = 2.0;
            waypoints_size_idx_0 = tmp_size_idx_1 + 1;
            for (i = 0; i < 3; i++) {
              waypoints_data_tmp = (tmp_size_idx_1 + 1) * i;
              rtb_wps_i[waypoints_data_tmp] =
                UAM_Flight_control_DW.obj_j.InitialPose[i];
              for (b_k = 0; b_k < tmp_size_idx_1; b_k++) {
                rtb_wps_i[(b_k + waypoints_data_tmp) + 1] =
                  b_waypointsIn_data[tmp_size_idx_1 * i + b_k];
              }
            }

            guard2 = true;
          }
        } else {
          waypoints_size_idx_0 = tmp_size_idx_1;
          b_k = tmp_size_idx_1 * 3;
          if (b_k - 1 >= 0) {
            memcpy(&rtb_wps_i[0], &b_waypointsIn_data[0], (uint32_T)b_k * sizeof
                   (real_T));
          }

          guard2 = true;
        }

        if (guard2) {
          rtb_Equal = false;
          if (UAM_Flight_control_DW.obj_j.WaypointIndex == 2.0) {
            rtb_Equal = true;
          }

          if (rtb_Equal) {
            UAM_Flight_control_DW.obj_j.LastWaypointFlag = true;
            UAM_Flight_control_DW.obj_j.WaypointIndex--;
          }

          rtb_Product_ov[0] = rtb_wps_i[(int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex - 1];
          v[0] = rtb_wps_i[(int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex +
            1.0) - 1];
          rtb_Product_ov[1] = rtb_wps_i[((int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0) -
            1];
          v[1] = rtb_wps_i[((int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex
            + 1.0) + waypoints_size_idx_0) - 1];
          rtb_Product_ov[2] = rtb_wps_i[((waypoints_size_idx_0 << 1) + (int32_T)
            UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
          rtb_TmpSignalConversionAtUAVO_2 = rtb_wps_i[((int32_T)
            (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
            (waypoints_size_idx_0 << 1)) - 1];
          v[2] = rtb_TmpSignalConversionAtUAVO_2;
          rtb_DotProduct = rtb_wps_i[(int32_T)
            (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) - 1];
          turnVector_0[0] = BusConversion_InsertedFor_Guida->Xe[0] -
            rtb_DotProduct;
          turnVector_0[1] = BusConversion_InsertedFor_Guida->Xe[1] - rtb_wps_i
            [((int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              waypoints_size_idx_0) - 1];
          turnVector_0[2] = BusConversion_InsertedFor_Guida->Xe[2] -
            rtb_TmpSignalConversionAtUAVO_2;
          guard3 = false;
          if (UAM_Flight_control_norm_by(turnVector_0) <= 10.0) {
            guard3 = true;
          } else {
            unitVectorUtoV_tmp[0] = rtb_DotProduct - rtb_wps_i[(int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex - 1];
            turnVector[0] = BusConversion_InsertedFor_Guida->Xe[0] - rtb_wps_i
              [(int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) - 1];
            rtb_DotProduct = rtb_wps_i[((int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              waypoints_size_idx_0) - 1];
            unitVectorUtoV_tmp[1] = rtb_DotProduct - rtb_wps_i[((int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0)
              - 1];
            turnVector[1] = BusConversion_InsertedFor_Guida->Xe[1] -
              rtb_DotProduct;
            rtb_DotProduct = rtb_wps_i[((int32_T)
              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0) +
              (waypoints_size_idx_0 << 1)) - 1];
            unitVectorUtoV_tmp[2] = rtb_DotProduct - rtb_wps_i
              [((waypoints_size_idx_0 << 1) + (int32_T)
                UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
            turnVector[2] = BusConversion_InsertedFor_Guida->Xe[2] -
              rtb_DotProduct;
            absx = UAM_Flight_control_norm_by(unitVectorUtoV_tmp);
            distToCenter = UAM_Flight_control_norm_by(turnVector);
            rtb_DotProduct = (unitVectorUtoV_tmp[0] / absx * (turnVector[0] /
              distToCenter) + unitVectorUtoV_tmp[1] / absx * (turnVector[1] /
              distToCenter)) + unitVectorUtoV_tmp[2] / absx * (turnVector[2] /
              distToCenter);
            if (rtIsNaN(rtb_DotProduct) || (rtb_DotProduct < 0.0)) {
            } else {
              guard3 = true;
            }
          }

          if (guard3) {
            UAM_Flight_control_DW.obj_j.WaypointIndex++;
            rtb_Equal = false;
            if (UAM_Flight_control_DW.obj_j.WaypointIndex == 2.0) {
              rtb_Equal = true;
            }

            if (rtb_Equal) {
              UAM_Flight_control_DW.obj_j.LastWaypointFlag = true;
              UAM_Flight_control_DW.obj_j.WaypointIndex--;
            }

            rtb_Product_ov[0] = rtb_wps_i[(int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex - 1];
            v[0] = rtb_wps_i[(int32_T)(UAM_Flight_control_DW.obj_j.WaypointIndex
              + 1.0) - 1];
            rtb_Product_ov[1] = rtb_wps_i[((int32_T)
              UAM_Flight_control_DW.obj_j.WaypointIndex + waypoints_size_idx_0)
              - 1];
            v[1] = rtb_wps_i[((int32_T)
                              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0)
                              + waypoints_size_idx_0) - 1];
            rtb_Product_ov[2] = rtb_wps_i[((waypoints_size_idx_0 << 1) +
              (int32_T)UAM_Flight_control_DW.obj_j.WaypointIndex) - 1];
            v[2] = rtb_wps_i[((int32_T)
                              (UAM_Flight_control_DW.obj_j.WaypointIndex + 1.0)
                              + (waypoints_size_idx_0 << 1)) - 1];
          }

          turnVector[0] = BusConversion_InsertedFor_Guida->Xe[0] -
            rtb_Product_ov[0];
          unitVectorUtoV_tmp[0] = v[0] - rtb_Product_ov[0];
          turnVector[1] = BusConversion_InsertedFor_Guida->Xe[1] -
            rtb_Product_ov[1];
          unitVectorUtoV_tmp[1] = v[1] - rtb_Product_ov[1];
          turnVector[2] = BusConversion_InsertedFor_Guida->Xe[2] -
            rtb_Product_ov[2];
          unitVectorUtoV_tmp[2] = v[2] - rtb_Product_ov[2];
          rtb_DotProduct = (unitVectorUtoV_tmp[0] * unitVectorUtoV_tmp[0] +
                            unitVectorUtoV_tmp[1] * unitVectorUtoV_tmp[1]) +
            unitVectorUtoV_tmp[2] * unitVectorUtoV_tmp[2];
          absx = ((turnVector[0] * unitVectorUtoV_tmp[0] + turnVector[1] *
                   unitVectorUtoV_tmp[1]) + turnVector[2] * unitVectorUtoV_tmp[2])
            / rtb_DotProduct;
          if (absx < 0.0) {
            x2 = UAM_Flight_control_norm_by(turnVector);
          } else if (absx > 1.0) {
            turnVector_0[0] = BusConversion_InsertedFor_Guida->Xe[0] - v[0];
            turnVector_0[1] = BusConversion_InsertedFor_Guida->Xe[1] - v[1];
            turnVector_0[2] = BusConversion_InsertedFor_Guida->Xe[2] - v[2];
            x2 = UAM_Flight_control_norm_by(turnVector_0);
          } else {
            turnVector_0[0] = BusConversion_InsertedFor_Guida->Xe[0] - (absx *
              unitVectorUtoV_tmp[0] + rtb_Product_ov[0]);
            turnVector_0[1] = BusConversion_InsertedFor_Guida->Xe[1] - (absx *
              unitVectorUtoV_tmp[1] + rtb_Product_ov[1]);
            turnVector_0[2] = BusConversion_InsertedFor_Guida->Xe[2] - (absx *
              unitVectorUtoV_tmp[2] + rtb_Product_ov[2]);
            x2 = UAM_Flight_control_norm_by(turnVector_0);
          }

          if (UAM_Flight_control_DW.obj_j.LastWaypointFlag) {
            turnVector_0[0] = BusConversion_InsertedFor_Guida->Xe[0] - (absx *
              unitVectorUtoV_tmp[0] + rtb_Product_ov[0]);
            turnVector_0[1] = BusConversion_InsertedFor_Guida->Xe[1] - (absx *
              unitVectorUtoV_tmp[1] + rtb_Product_ov[1]);
            turnVector_0[2] = BusConversion_InsertedFor_Guida->Xe[2] - (absx *
              unitVectorUtoV_tmp[2] + rtb_Product_ov[2]);
            x2 = UAM_Flight_control_norm_by(turnVector_0);
          }

          y2 = fabs(x2);
          if (rtIsInf(y2) || rtIsNaN(y2)) {
            absx = (rtNaN);
            y2 = (rtNaN);
          } else if (y2 < 4.4501477170144028E-308) {
            absx = 4.94065645841247E-324;
            y2 = 4.94065645841247E-324;
          } else {
            frexp(y2, &b_exponent);
            absx = ldexp(1.0, b_exponent - 53);
            frexp(y2, &b_exponent_0);
            y2 = ldexp(1.0, b_exponent_0 - 53);
          }

          if (UAM_Flight_control_DW.obj_j.LookaheadDistance <= fmax(sqrt(absx),
               5.0 * y2) + x2) {
            UAM_Flight_control_DW.obj_j.LookaheadDistance =
              UAM_Flight_control_DW.obj_j.LookaheadFactor * x2;
          }

          turnVector[0] = unitVectorUtoV_tmp[0];
          turnVector[1] = unitVectorUtoV_tmp[1];
          turnVector[2] = unitVectorUtoV_tmp[2];
          unitVectorUtoV_tmp[0] = rtb_Product_ov[0] -
            BusConversion_InsertedFor_Guida->Xe[0];
          unitVectorUtoV_tmp[1] = rtb_Product_ov[1] -
            BusConversion_InsertedFor_Guida->Xe[1];
          unitVectorUtoV_tmp[2] = rtb_Product_ov[2] -
            BusConversion_InsertedFor_Guida->Xe[2];
          x2 = ((turnVector[0] * unitVectorUtoV_tmp[0] + turnVector[1] *
                 unitVectorUtoV_tmp[1]) + turnVector[2] * unitVectorUtoV_tmp[2])
            * 2.0;
          absx = sqrt(x2 * x2 - (((unitVectorUtoV_tmp[0] * unitVectorUtoV_tmp[0]
            + unitVectorUtoV_tmp[1] * unitVectorUtoV_tmp[1]) +
            unitVectorUtoV_tmp[2] * unitVectorUtoV_tmp[2]) -
            UAM_Flight_control_DW.obj_j.LookaheadDistance *
            UAM_Flight_control_DW.obj_j.LookaheadDistance) * (4.0 *
            rtb_DotProduct));
          rtb_DotProduct = fmax((-x2 + absx) / 2.0 / rtb_DotProduct, (-x2 - absx)
                                / 2.0 / rtb_DotProduct);
          v[0] = (1.0 - rtb_DotProduct) * rtb_Product_ov[0] + rtb_DotProduct *
            v[0];
          v[1] = (1.0 - rtb_DotProduct) * rtb_Product_ov[1] + rtb_DotProduct *
            v[1];

          /* BusCreator: '<S2674>/Bus Creator' incorporates:
           *  SignalConversion generated from: '<S2674>/Waypoint Follower'
           */
          UAM_Flight_control_B.aacSP.course = rt_atan2d_snf(v[1] -
            BusConversion_InsertedFor_Guida->Xe[1], v[0] -
            BusConversion_InsertedFor_Guida->Xe[0]);

          /* Merge: '<S2671>/ Merge ' */
          UAM_Flight_control_B.Status_p = 0U;
          rtb_Equal = false;
          if (UAM_Flight_control_DW.obj_j.LastWaypointFlag) {
            rtb_Equal = true;
          }

          if (rtb_Equal) {
            /* Merge: '<S2671>/ Merge ' */
            UAM_Flight_control_B.Status_p = 1U;
          }

          UAM_Flight_control_DW.obj_j.LastWaypointFlag = false;
        }
      }

      /* BusCreator: '<S2674>/Bus Creator' incorporates:
       *  Constant: '<S2674>/Constant'
       *  Constant: '<S2674>/Constant1'
       */
      UAM_Flight_control_B.aacSP.airspeed =
        UAM_Flight_control_P.control.cruiseSpeed;
      UAM_Flight_control_B.aacSP.L1 = rtb_TmpSignalConversionAtUAVO_1;
      UAM_Flight_control_B.aacSP.climbrate =
        UAM_Flight_control_P.Constant1_Value_ha;
      break;

     case UAM_Flight_cont_IN_FWCOMPLETE_b:
      /* Merge: '<S2671>/ Merge ' */
      UAM_Flight_control_B.Status_p = 1U;
      UAM_Flight_control_B.controlMode_n.TransitionCondition = 1U;
      break;

     case UAM_Flight_IN_ForwardTransition:
      /* UnitDelay: '<S2>/Unit Delay2' */
      if (UAM_Fl_transitionConditionMet_h
          (UAM_Flight_control_DW.UnitDelay2_DSTATE_l)) {
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_co_IN_TransitionStep;
        UAM_Flight_control_B.controlMode_n.TransitionStep = 1U;
      } else {
        /* BusCreator: '<S2675>/Bus Creator' incorporates:
         *  MATLAB Function: '<S2675>/MATLAB Function'
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_MATLABFunction_j
          (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position,
           UAM_Flight_control_DW.UnitDelay_3_DSTATE.position, rtb_wps_i,
           &UAM_Flight_control_B.aacSP.altitude);
        UAM_Flight_control_B.aacSP.airspeed = 0.0;
        UAM_Flight_control_B.aacSP.course = 0.0;
        UAM_Flight_control_B.aacSP.L1 = 0.0;
        UAM_Flight_control_B.aacSP.climbrate = 0.0;

        /* BusCreator: '<S2675>/Bus Creator1' incorporates:
         *  Constant: '<S2675>/Constant1'
         *  Constant: '<S2675>/Constant2'
         *  Constant: '<S2675>/Constant3'
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_P.Constant3_Value_m[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_P.Constant3_Value_m[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_P.Constant3_Value_m[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_P.Constant1_Value_ag;
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.Constant2_Value_e;

        /* DataTypeConversion: '<S2675>/Data Type Conversion' incorporates:
         *  Constant: '<S2675>/Constant'
         */
        absx = floor(UAM_Flight_control_P.Constant_Value_j);
        if (rtIsNaN(absx) || rtIsInf(absx)) {
          absx = 0.0;
        } else {
          absx = fmod(absx, 256.0);
        }

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  DataTypeConversion: '<S2675>/Data Type Conversion'
         */
        UAM_Flight_control_B.Status_p = (uint8_T)(absx < 0.0 ? (int32_T)(uint8_T)
          -(int8_T)(uint8_T)-absx : (int32_T)(uint8_T)absx);
      }
      break;

     case UAM_Flight_contr_IN_HOVER_ENTRY:
      /* UnitDelay generated from: '<S2>/Unit Delay' incorporates:
       *  Constant: '<S2677>/Lookahead Distance'
       *  UnitDelay generated from: '<S2>/Unit Delay1'
       */
      switch (UAM_Flight_control_DW.UnitDelay_1_DSTATE_e) {
       case 2U:
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_WP;

        /* RelationalOperator: '<S2685>/Equal' incorporates:
         *  Constant: '<S2685>/Constant'
         */
        rtb_Equal = (UAM_Flight_control_P.Constant_Value_p ==
                     UAM_Flight_control_DW.UnitDelay_3_DSTATE.mode);

        /* Outputs for Triggered SubSystem: '<S2685>/Triggered Subsystem' incorporates:
         *  TriggerPort: '<S2688>/Trigger'
         */
        if (rtb_Equal && (UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE
                          != POS_ZCSIG)) {
          /* Reshape: '<S2688>/Reshape' incorporates:
           *  UnitDelay generated from: '<S2>/Unit Delay1'
           */
          UAM_Flight_control_B.Reshape[0] =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
          UAM_Flight_control_B.Reshape[1] =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
          UAM_Flight_control_B.Reshape[2] =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
        }

        UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_Equal;

        /* End of Outputs for SubSystem: '<S2685>/Triggered Subsystem' */

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         */
        UAM_Flight_control_DW.outWPS[6] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];

        /* Switch: '<S2685>/Switch' incorporates:
         *  Product: '<S2689>/Product'
         *  Reshape: '<S2688>/Reshape'
         */
        if (rtb_Equal) {
          rtb_DotProduct = UAM_Flight_control_B.Reshape[0];
        } else {
          rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
        }

        rtb_Product_ov[0] = rtb_DotProduct;

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         *  Product: '<S2689>/Product'
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_control_DW.outWPS[0] = rtb_DotProduct;
        UAM_Flight_control_DW.outWPS[1] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];

        /* Switch: '<S2685>/Switch' incorporates:
         *  Product: '<S2689>/Product'
         *  Reshape: '<S2688>/Reshape'
         */
        if (rtb_Equal) {
          rtb_DotProduct = UAM_Flight_control_B.Reshape[1];
        } else {
          rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
        }

        rtb_Product_ov[1] = rtb_DotProduct;

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         *  Product: '<S2689>/Product'
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_control_DW.outWPS[2] = rtb_DotProduct;
        UAM_Flight_control_DW.outWPS[3] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];

        /* Switch: '<S2685>/Switch' incorporates:
         *  Product: '<S2689>/Product'
         *  Reshape: '<S2688>/Reshape'
         */
        if (rtb_Equal) {
          rtb_DotProduct = UAM_Flight_control_B.Reshape[2];
        } else {
          rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
        }

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         *  Product: '<S2689>/Product'
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_control_DW.outWPS[4] = rtb_DotProduct;
        UAM_Flight_control_DW.outWPS[5] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
        UAM_Flight_control_DW.outWPS[7] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];

        /* BusCreator: '<S2680>/Bus Creator' incorporates:
         *  Constant: '<S2680>/Lookahead Distance'
         *  MATLAB Function: '<S2680>/MATLAB Function'
         *  MATLABSystem: '<S2680>/Waypoint Follower'
         *  Merge: '<S2671>/ Merge 2'
         *  SignalConversion generated from: '<S2680>/Bus Creator'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         * */
        UAM_Flight_cont_SystemCore_step(&UAM_Flight_control_DW.obj_l,
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
          UAM_Flight_control_DW.outWPS,
          UAM_Flight_control_P.LookaheadDistance_Value_p, v,
          &UAM_Flight_control_B.InnerLoopCmds.HeadingCmd, &x2, &b_varargout_4);
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] = v[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] = v[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];

        /* Saturate: '<S2680>/Yaw Cmd Sat' incorporates:
         *  MATLABSystem: '<S2680>/Waypoint Follower'
         * */
        if (x2 > UAM_Flight_control_P.YawCmdSat_UpperSat_o) {
          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_UpperSat_o;
        } else if (x2 < UAM_Flight_control_P.YawCmdSat_LowerSat_f) {
          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_LowerSat_f;
        } else {
          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd = x2;
        }

        /* Sum: '<S2686>/Sum1' incorporates:
         *  Product: '<S2689>/Product'
         */
        x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
          rtb_Product_ov[0];
        rtb_Product_ov[0] = x2;

        /* DotProduct: '<S2689>/Dot Product1' incorporates:
         *  Product: '<S2689>/Product'
         */
        absx = x2 * x2;

        /* Sum: '<S2686>/Sum1' incorporates:
         *  Product: '<S2689>/Product'
         */
        x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
          rtb_Product_ov[1];
        rtb_Product_ov[1] = x2;

        /* DotProduct: '<S2689>/Dot Product1' incorporates:
         *  Product: '<S2689>/Product'
         */
        absx += x2 * x2;

        /* Sum: '<S2686>/Sum1' incorporates:
         *  Product: '<S2689>/Product'
         *  Switch: '<S2685>/Switch'
         */
        x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] -
          rtb_DotProduct;

        /* DotProduct: '<S2689>/Dot Product1' incorporates:
         *  Product: '<S2689>/Product'
         */
        absx += x2 * x2;

        /* Saturate: '<S2689>/Saturation' incorporates:
         *  DotProduct: '<S2689>/Dot Product1'
         */
        if (absx > UAM_Flight_control_P.Saturation_UpperSat_hb) {
          absx = UAM_Flight_control_P.Saturation_UpperSat_hb;
        } else if (absx < UAM_Flight_control_P.Saturation_LowerSat_m) {
          absx = UAM_Flight_control_P.Saturation_LowerSat_m;
        }

        /* Sqrt: '<S2689>/Sqrt' incorporates:
         *  Saturate: '<S2689>/Saturation'
         */
        rtb_DotProduct = sqrt(absx);

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  Constant: '<S2680>/Constant1'
         *  DataTypeConversion: '<S2680>/Data Type Conversion'
         *  DotProduct: '<S2686>/Dot Product'
         *  Product: '<S2689>/Product'
         *  RelationalOperator: '<S2680>/Relational Operator'
         *  Sum: '<S2686>/Sum'
         *  Sum: '<S2686>/Sum1'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         */
        UAM_Flight_control_B.Status_p = (uint8_T)
          (UAM_Flight_control_P.Constant1_Value_n >=
           ((UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
             UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * (rtb_Product_ov[0] /
             rtb_DotProduct) +
            (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
             UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) * (rtb_Product_ov[1] /
             rtb_DotProduct)) +
           (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] -
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2]) * (x2 / rtb_DotProduct));
        break;

       case 3U:
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_Orbit;

        /* Abs: '<S2678>/Abs' */
        x2 = fabs(UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2]);

        /* Signum: '<S2678>/Sign' */
        if (rtIsNaN(UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2])) {
          rtb_DotProduct = (rtNaN);
        } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2] < 0.0) {
          rtb_DotProduct = -1.0;
        } else {
          rtb_DotProduct = (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2] >
                            0.0);
        }

        /* MATLABSystem: '<S2678>/UAV Orbit Follower' incorporates:
         *  Constant: '<S2678>/Lookahead Distance'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         * */
        UAM_Flight_control_DW.obj_cg.OrbitRadiusFlag = 0U;
        if (x2 <= 1.0) {
          x2 = 1.0;
          UAM_Flight_control_DW.obj_cg.OrbitRadiusFlag = 1U;
        }

        absx = UAM_Flight_control_P.LookaheadDistance_Value_l;
        UAM_Flight_control_DW.obj_cg.LookaheadDistFlag = 0U;
        if (UAM_Flight_control_P.LookaheadDistance_Value_l < 0.1) {
          absx = 0.1;
          UAM_Flight_control_DW.obj_cg.LookaheadDistFlag = 1U;
        }

        rtb_TmpSignalConversionAtUAVO_1 =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0] -
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
        rtb_TmpSignalConversionAtUAVO_0[0] = rtb_TmpSignalConversionAtUAVO_1;
        rtb_TmpSignalConversionAtUAVO_2 =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1] -
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
        rtb_TmpSignalConversionAtUAVO_0[1] = rtb_TmpSignalConversionAtUAVO_2;
        if (UAM_Flight_control_norm_b(rtb_TmpSignalConversionAtUAVO_0) <
            2.47032822920623E-323) {
          /* BusCreator: '<S2678>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.LAP[0] = x2 * cos
            (UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]) +
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
          UAM_Flight_control_B.InnerLoopCmds.LAP[1] = x2 * sin
            (UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]) +
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
          UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3];
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3];
          distToCenter = UAM_Flight_control_DW.obj_cg.NumCircles;
        } else {
          rtb_Equal = false;
          p = true;
          b_k = 0;
          exitg1 = false;
          while ((!exitg1) && (b_k < 3)) {
            if (!(UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[b_k] ==
                  UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[b_k])) {
              p = false;
              exitg1 = true;
            } else {
              b_k++;
            }
          }

          if (p) {
            rtb_Equal = true;
          }

          guard2 = false;
          if (!rtb_Equal) {
            guard2 = true;
          } else {
            rtb_Equal = false;
            if (UAM_Flight_control_DW.obj_cg.OrbitRadiusInternal == x2) {
              rtb_Equal = true;
            }

            if (!rtb_Equal) {
              guard2 = true;
            }
          }

          if (guard2) {
            UAM_Flight_control_DW.obj_cg.NumCircles = 0.0;
            UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[0] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[1] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
            UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[2] =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
            UAM_Flight_control_DW.obj_cg.OrbitRadiusInternal = x2;
            UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag = true;
          }

          if (absx >= x2) {
            UAM_Flight_control_DW.obj_cg.LookaheadDistance = 0.9 * x2;
          } else {
            UAM_Flight_control_DW.obj_cg.LookaheadDistance = absx;
          }

          b_tmp[0] = rtb_TmpSignalConversionAtUAVO_1;
          b_tmp[1] = rtb_TmpSignalConversionAtUAVO_2;
          distToCenter = sqrt(rtb_TmpSignalConversionAtUAVO_2 *
                              rtb_TmpSignalConversionAtUAVO_2 +
                              rtb_TmpSignalConversionAtUAVO_1 *
                              rtb_TmpSignalConversionAtUAVO_1);
          y2 = x2 + UAM_Flight_control_DW.obj_cg.LookaheadDistance;
          x2_tmp = fabs(y2);
          if (rtIsInf(x2_tmp) || rtIsNaN(x2_tmp)) {
            absx = (rtNaN);
          } else if (x2_tmp < 4.4501477170144028E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(x2_tmp, &b_exponent);
            absx = ldexp(1.0, b_exponent - 53);
          }

          guard2 = false;
          if (distToCenter >= y2 - 5.0 * absx) {
            guard2 = true;
          } else {
            if (rtIsInf(x2_tmp) || rtIsNaN(x2_tmp)) {
              absx = (rtNaN);
            } else if (x2_tmp < 4.4501477170144028E-308) {
              absx = 4.94065645841247E-324;
            } else {
              frexp(x2_tmp, &b_exponent_0);
              absx = ldexp(1.0, b_exponent_0 - 53);
            }

            if (distToCenter <= (x2 -
                                 UAM_Flight_control_DW.obj_cg.LookaheadDistance)
                + 5.0 * absx) {
              guard2 = true;
            } else {
              if (UAM_Flight_control_DW.obj_cg.StartFlag) {
                UAM_Flight_control_DW.obj_cg.PrevPosition[0] =
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
                UAM_Flight_control_DW.obj_cg.PrevPosition[1] =
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
                UAM_Flight_control_DW.obj_cg.StartFlag = false;
              }

              if ((rtb_DotProduct == 0.0) &&
                  (!UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag)) {
                rtb_DotProduct =
                  UAM_Flight_control_DW.obj_cg.TurnDirectionInternal;
              }

              xyPose[0] = rtb_TmpSignalConversionAtUAVO_1;
              turnVector[0] = UAM_Flight_control_DW.obj_cg.PrevPosition[0] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
              xyPose[1] = rtb_TmpSignalConversionAtUAVO_2;
              turnVector[1] = UAM_Flight_control_DW.obj_cg.PrevPosition[1] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
              absx = UAM_Flight_control_norm_b(xyPose);
              distToCenter = ((UAM_Flight_control_DW.obj_cg.LookaheadDistance *
                               UAM_Flight_control_DW.obj_cg.LookaheadDistance -
                               x2 * x2) + absx * absx) / (2.0 * absx);
              x2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
              x2 = x2_tmp * distToCenter / absx +
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
              y2_tmp = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
              y2 = y2_tmp * distToCenter / absx +
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
              distToCenter = sqrt(UAM_Flight_control_DW.obj_cg.LookaheadDistance
                                  * UAM_Flight_control_DW.obj_cg.LookaheadDistance
                                  - distToCenter * distToCenter);
              distToCenter_tmp = y2_tmp * distToCenter / absx;
              b_tmp[0] = x2 - distToCenter_tmp;
              b_tmp[1] = distToCenter_tmp + x2;
              absx = x2_tmp * distToCenter / absx;
              x2 = absx + y2;
              y2 -= absx;
              rtb_Product_ov[0] = turnVector[0];
              rtb_Product_ov[1] = turnVector[1];
              rtb_Product_ov[2] = 0.0;
              v[0] = rtb_TmpSignalConversionAtUAVO_1;
              v[1] = rtb_TmpSignalConversionAtUAVO_2;
              v[2] = 0.0;
              if (rtb_DotProduct < 0.0) {
                rtb_Product_ov[0] = rtb_TmpSignalConversionAtUAVO_1;
                v[0] = turnVector[0];
                rtb_Product_ov[1] = rtb_TmpSignalConversionAtUAVO_2;
                v[1] = turnVector[1];
                rtb_Product_ov[2] = 0.0;
                v[2] = 0.0;
              }

              absx = UAM_Flight_control_norm_by(rtb_Product_ov);
              distToCenter = UAM_Flight_control_norm_by(v);
              rtb_Product_ov[0] /= absx;
              v[0] /= distToCenter;
              rtb_Product_ov[1] /= absx;
              v[1] /= distToCenter;
              turnVector[2] = rtb_Product_ov[0] * v[1] - v[0] * rtb_Product_ov[1];
              UAM_Flight_control_DW.obj_cg.PrevPosition[0] =
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
              UAM_Flight_control_DW.obj_cg.PrevPosition[1] =
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
              UAM_Flight_control_DW.obj_cg.PrevPosition[2] =
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
              UAM_Flight_control_DW.obj_cg.NumCircles += rt_atan2d_snf
                (turnVector[2], (rtb_Product_ov[0] * v[0] + rtb_Product_ov[1] *
                                 v[1]) + 0.0 / absx * (0.0 / distToCenter)) /
                2.0 / 3.1415926535897931;
              distToCenter = UAM_Flight_control_DW.obj_cg.NumCircles;
              if (rtIsNaN(rtb_DotProduct)) {
                absx = (rtNaN);
              } else if (rtb_DotProduct < 0.0) {
                absx = -1.0;
              } else {
                absx = (rtb_DotProduct > 0.0);
              }

              switch ((int32_T)absx) {
               case 1:
                if ((b_tmp[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) *
                    y2_tmp - (x2 - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1])
                    * x2_tmp > 0.0) {
                  xyLookaheadPoint[0] = b_tmp[0];
                  xyLookaheadPoint[1] = x2;
                } else {
                  xyLookaheadPoint[0] = b_tmp[1];
                  xyLookaheadPoint[1] = y2;
                }
                break;

               case -1:
                if ((b_tmp[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) *
                    y2_tmp - (x2 - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1])
                    * x2_tmp < 0.0) {
                  xyLookaheadPoint[0] = b_tmp[0];
                  xyLookaheadPoint[1] = x2;
                } else {
                  xyLookaheadPoint[0] = b_tmp[1];
                  xyLookaheadPoint[1] = y2;
                }
                break;

               default:
                if (fabs(UAM_Flight_control_angdiff(rt_atan2d_snf(x2 -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1], b_tmp[0] -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]),
                      UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3])) < fabs
                    (UAM_Flight_control_angdiff(rt_atan2d_snf(y2 -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1], b_tmp[1] -
                       UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]),
                      UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]))) {
                  xyLookaheadPoint[0] = b_tmp[0];
                  xyLookaheadPoint[1] = x2;
                } else {
                  xyLookaheadPoint[0] = b_tmp[1];
                  xyLookaheadPoint[1] = y2;
                }

                if ((xyLookaheadPoint[0] -
                     UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * y2_tmp -
                    (xyLookaheadPoint[1] -
                     UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) * x2_tmp >
                    0.0) {
                  UAM_Flight_control_DW.obj_cg.TurnDirectionInternal = 1.0;
                } else {
                  UAM_Flight_control_DW.obj_cg.TurnDirectionInternal = -1.0;
                }

                UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag = false;
                break;
              }

              /* BusCreator: '<S2678>/Bus Creator' incorporates:
               *  Merge: '<S2671>/ Merge 2'
               */
              UAM_Flight_control_B.InnerLoopCmds.YawCmd = rt_atan2d_snf
                (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
                 UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1],
                 UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
                 UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
            }
          }

          if (guard2) {
            absx = UAM_Flight_control_norm_b(b_tmp);
            xyLookaheadPoint[0] = rtb_TmpSignalConversionAtUAVO_1 / absx * x2 +
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            xyLookaheadPoint[1] = rtb_TmpSignalConversionAtUAVO_2 / absx * x2 +
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];

            /* BusCreator: '<S2678>/Bus Creator' incorporates:
             *  Merge: '<S2671>/ Merge 2'
             */
            UAM_Flight_control_B.InnerLoopCmds.YawCmd = rt_atan2d_snf
              (xyLookaheadPoint[1] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1],
               xyLookaheadPoint[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
            distToCenter = UAM_Flight_control_DW.obj_cg.NumCircles;
          }

          /* BusCreator: '<S2678>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.LAP[0] = xyLookaheadPoint[0];
          UAM_Flight_control_B.InnerLoopCmds.LAP[1] = xyLookaheadPoint[1];
          UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd = rt_atan2d_snf
            (xyLookaheadPoint[1] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1],
             xyLookaheadPoint[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
        }

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  DataTypeConversion: '<S2678>/Data Type Conversion'
         *  MATLABSystem: '<S2678>/UAV Orbit Follower'
         *  RelationalOperator: '<S2678>/Relational Operator'
         * */
        UAM_Flight_control_B.Status_p = (uint8_T)(distToCenter >
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0]);
        break;

       case 6U:
        UAM_Flight_control_B.FlightMode_c = Transition;
        UAM_Flight_control_B.controlMode_n.inTransition = 1U;
        UAM_Flight_control_B.controlMode_n.TransitionCondition = 0U;
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_IN_ForwardTransition;

        /* BusCreator: '<S2675>/Bus Creator' incorporates:
         *  MATLAB Function: '<S2675>/MATLAB Function'
         */
        UAM_Flight_MATLABFunction_j
          (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position,
           UAM_Flight_control_DW.UnitDelay_3_DSTATE.position, rtb_wps_i,
           &UAM_Flight_control_B.aacSP.altitude);
        UAM_Flight_control_B.aacSP.airspeed = 0.0;
        UAM_Flight_control_B.aacSP.course = 0.0;
        UAM_Flight_control_B.aacSP.L1 = 0.0;
        UAM_Flight_control_B.aacSP.climbrate = 0.0;

        /* BusCreator: '<S2675>/Bus Creator1' incorporates:
         *  Constant: '<S2675>/Constant1'
         *  Constant: '<S2675>/Constant2'
         *  Constant: '<S2675>/Constant3'
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_P.Constant3_Value_m[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_P.Constant3_Value_m[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_P.Constant3_Value_m[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_P.Constant1_Value_ag;
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.Constant2_Value_e;

        /* DataTypeConversion: '<S2675>/Data Type Conversion' incorporates:
         *  Constant: '<S2675>/Constant'
         */
        absx = floor(UAM_Flight_control_P.Constant_Value_j);
        if (rtIsNaN(absx) || rtIsInf(absx)) {
          absx = 0.0;
        } else {
          absx = fmod(absx, 256.0);
        }

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  DataTypeConversion: '<S2675>/Data Type Conversion'
         */
        UAM_Flight_control_B.Status_p = (uint8_T)(absx < 0.0 ? (int32_T)(uint8_T)
          -(int8_T)(uint8_T)-absx : (int32_T)(uint8_T)absx);
        break;

       default:
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_Land;
        UAM_Flight_control_DW.durationCounter_1 = 0U;
        UAM_Flight_control_DW.is_Land = UAM_Flight_control_IN_ToLand;

        /* MATLAB Function: '<S2677>/MATLAB Function' incorporates:
         *  UnitDelay generated from: '<S2>/Unit Delay'
         */
        UAM_Flight_control_DW.outWPS_i[0] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
        UAM_Flight_control_DW.outWPS_i[2] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
        UAM_Flight_control_DW.outWPS_i[4] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
        UAM_Flight_control_DW.outWPS_i[6] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];
        UAM_Flight_control_DW.outWPS_i[1] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
        UAM_Flight_control_DW.outWPS_i[3] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
        UAM_Flight_control_DW.outWPS_i[5] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
        UAM_Flight_control_DW.outWPS_i[7] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
        memcpy(&rtb_wps_c[0], &UAM_Flight_control_DW.outWPS_i[0], sizeof(real_T)
               << 3U);
        UAM_Flight_WaypointFollower(UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
          rtb_wps_c, UAM_Flight_control_P.LookaheadDistance_Value,
          &UAM_Flight_control_B.WaypointFollower_ni,
          &UAM_Flight_control_DW.WaypointFollower_ni);

        /* BusCreator: '<S2677>/Bus Creator1' incorporates:
         *  Constant: '<S2677>/Lookahead Distance'
         *  MATLABSystem: '<S2677>/Waypoint Follower'
         *  Merge: '<S2671>/ Merge 2'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_B.WaypointFollower_ni.LAP[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_B.WaypointFollower_ni.LAP[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_B.WaypointFollower_ni.LAP[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_B.WaypointFollower_ni.HeadingCmd;
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_B.WaypointFollower_ni.YawCmd;

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  Constant: '<S2677>/Constant'
         *  SignalConversion generated from: '<S2677>/Status'
         */
        UAM_Flight_control_B.Status_p = UAM_Flight_control_P.Constant_Value_j5;
        break;
      }
      break;

     case UAM_Flight_control_IN_Land:
      UAM_Flight_control_Land(BusConversion_InsertedFor_Guida, rtb_wps_c);
      break;

     case UAM_Flight_contr_IN_Landcommand:
      UAM_Flight_control_B.controlMode_n.land = 0.0;
      break;

     case UAM_Flight_control_IN_Orbit:
      /* Abs: '<S2678>/Abs' incorporates:
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      x2 = fabs(UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2]);

      /* Signum: '<S2678>/Sign' incorporates:
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      if (rtIsNaN(UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2])) {
        rtb_DotProduct = (rtNaN);
      } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2] < 0.0) {
        rtb_DotProduct = -1.0;
      } else {
        rtb_DotProduct = (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[2] >
                          0.0);
      }

      /* MATLABSystem: '<S2678>/UAV Orbit Follower' incorporates:
       *  Constant: '<S2678>/Lookahead Distance'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       *  UnitDelay generated from: '<S2>/Unit Delay1'
       * */
      UAM_Flight_control_DW.obj_cg.OrbitRadiusFlag = 0U;
      if (x2 <= 1.0) {
        x2 = 1.0;
        UAM_Flight_control_DW.obj_cg.OrbitRadiusFlag = 1U;
      }

      absx = UAM_Flight_control_P.LookaheadDistance_Value_l;
      UAM_Flight_control_DW.obj_cg.LookaheadDistFlag = 0U;
      if (UAM_Flight_control_P.LookaheadDistance_Value_l < 0.1) {
        absx = 0.1;
        UAM_Flight_control_DW.obj_cg.LookaheadDistFlag = 1U;
      }

      rtb_TmpSignalConversionAtUAVO_1 =
        UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0] -
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
      xyLookaheadPoint[0] = rtb_TmpSignalConversionAtUAVO_1;
      rtb_TmpSignalConversionAtUAVO_2 =
        UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1] -
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
      xyLookaheadPoint[1] = rtb_TmpSignalConversionAtUAVO_2;
      if (UAM_Flight_control_norm_b(xyLookaheadPoint) < 2.47032822920623E-323) {
        /* BusCreator: '<S2678>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] = x2 * cos
          (UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]) +
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] = x2 * sin
          (UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]) +
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3];
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3];
        distToCenter = UAM_Flight_control_DW.obj_cg.NumCircles;
      } else {
        rtb_Equal = false;
        p = true;
        b_k = 0;
        exitg1 = false;
        while ((!exitg1) && (b_k < 3)) {
          if (!(UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[b_k] ==
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[b_k])) {
            p = false;
            exitg1 = true;
          } else {
            b_k++;
          }
        }

        if (p) {
          rtb_Equal = true;
        }

        guard2 = false;
        if (!rtb_Equal) {
          guard2 = true;
        } else {
          rtb_Equal = false;
          if (UAM_Flight_control_DW.obj_cg.OrbitRadiusInternal == x2) {
            rtb_Equal = true;
          }

          if (!rtb_Equal) {
            guard2 = true;
          }
        }

        if (guard2) {
          UAM_Flight_control_DW.obj_cg.NumCircles = 0.0;
          UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[0] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[1] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
          UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[2] =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
          UAM_Flight_control_DW.obj_cg.OrbitRadiusInternal = x2;
          UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag = true;
        }

        if (absx >= x2) {
          UAM_Flight_control_DW.obj_cg.LookaheadDistance = 0.9 * x2;
        } else {
          UAM_Flight_control_DW.obj_cg.LookaheadDistance = absx;
        }

        b_tmp[0] = rtb_TmpSignalConversionAtUAVO_1;
        b_tmp[1] = rtb_TmpSignalConversionAtUAVO_2;
        distToCenter = sqrt(rtb_TmpSignalConversionAtUAVO_2 *
                            rtb_TmpSignalConversionAtUAVO_2 +
                            rtb_TmpSignalConversionAtUAVO_1 *
                            rtb_TmpSignalConversionAtUAVO_1);
        absx = fabs(x2 + UAM_Flight_control_DW.obj_cg.LookaheadDistance);
        if (rtIsInf(absx) || rtIsNaN(absx)) {
          absx = (rtNaN);
        } else if (absx < 4.4501477170144028E-308) {
          absx = 4.94065645841247E-324;
        } else {
          frexp(absx, &b_exponent);
          absx = ldexp(1.0, b_exponent - 53);
        }

        y2 = x2 + UAM_Flight_control_DW.obj_cg.LookaheadDistance;
        guard2 = false;
        if (distToCenter >= y2 - 5.0 * absx) {
          guard2 = true;
        } else {
          absx = fabs(y2);
          if (rtIsInf(absx) || rtIsNaN(absx)) {
            absx = (rtNaN);
          } else if (absx < 4.4501477170144028E-308) {
            absx = 4.94065645841247E-324;
          } else {
            frexp(absx, &b_exponent_0);
            absx = ldexp(1.0, b_exponent_0 - 53);
          }

          if (distToCenter <= (x2 -
                               UAM_Flight_control_DW.obj_cg.LookaheadDistance) +
              5.0 * absx) {
            guard2 = true;
          } else {
            if (UAM_Flight_control_DW.obj_cg.StartFlag) {
              UAM_Flight_control_DW.obj_cg.PrevPosition[0] =
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
              UAM_Flight_control_DW.obj_cg.PrevPosition[1] =
                UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
              UAM_Flight_control_DW.obj_cg.StartFlag = false;
            }

            if ((rtb_DotProduct == 0.0) &&
                (!UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag)) {
              rtb_DotProduct =
                UAM_Flight_control_DW.obj_cg.TurnDirectionInternal;
            }

            rtb_Product_ov[2] = 0.0;
            xyPose[0] = rtb_TmpSignalConversionAtUAVO_1;
            rtb_Product_ov[0] = UAM_Flight_control_DW.obj_cg.PrevPosition[0] -
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
            v[0] = rtb_TmpSignalConversionAtUAVO_1;
            xyPose[1] = rtb_TmpSignalConversionAtUAVO_2;
            rtb_Product_ov[1] = UAM_Flight_control_DW.obj_cg.PrevPosition[1] -
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
            v[1] = rtb_TmpSignalConversionAtUAVO_2;
            absx = UAM_Flight_control_norm_b(xyPose);
            distToCenter = ((UAM_Flight_control_DW.obj_cg.LookaheadDistance *
                             UAM_Flight_control_DW.obj_cg.LookaheadDistance - x2
                             * x2) + absx * absx) / (2.0 * absx);
            x2 = (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * distToCenter /
              absx + UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
            y2 = (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) * distToCenter /
              absx + UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
            distToCenter = sqrt(UAM_Flight_control_DW.obj_cg.LookaheadDistance *
                                UAM_Flight_control_DW.obj_cg.LookaheadDistance -
                                distToCenter * distToCenter);
            b_tmp[0] = x2 - (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1]
                             - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) *
              distToCenter / absx;
            b_tmp[1] = (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
                        UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) *
              distToCenter / absx + x2;
            x2 = (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
                  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * distToCenter /
              absx + y2;
            y2 -= (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
                   UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * distToCenter /
              absx;
            v[2] = 0.0;
            if (rtb_DotProduct < 0.0) {
              rtb_Product_ov[0] = rtb_TmpSignalConversionAtUAVO_1;
              rtb_Product_ov[1] = rtb_TmpSignalConversionAtUAVO_2;
              rtb_Product_ov[2] = 0.0;
              v[0] = UAM_Flight_control_DW.obj_cg.PrevPosition[0] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
              v[1] = UAM_Flight_control_DW.obj_cg.PrevPosition[1] -
                UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];
              v[2] = 0.0;
            }

            absx = UAM_Flight_control_norm_by(rtb_Product_ov);
            distToCenter = UAM_Flight_control_norm_by(v);
            rtb_Product_ov[0] /= absx;
            v[0] /= distToCenter;
            rtb_Product_ov[1] /= absx;
            v[1] /= distToCenter;
            turnVector[2] = rtb_Product_ov[0] * v[1] - v[0] * rtb_Product_ov[1];
            UAM_Flight_control_DW.obj_cg.PrevPosition[0] =
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
            UAM_Flight_control_DW.obj_cg.PrevPosition[1] =
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
            UAM_Flight_control_DW.obj_cg.PrevPosition[2] =
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
            UAM_Flight_control_DW.obj_cg.NumCircles += rt_atan2d_snf(turnVector
              [2], (rtb_Product_ov[0] * v[0] + rtb_Product_ov[1] * v[1]) + 0.0 /
              absx * (0.0 / distToCenter)) / 2.0 / 3.1415926535897931;
            distToCenter = UAM_Flight_control_DW.obj_cg.NumCircles;
            rtb_TmpSignalConversionAtUAVO_2 =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
            rtb_TmpSignalConversionAtUAVO_1 =
              UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
              UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
            if (rtIsNaN(rtb_DotProduct)) {
              absx = (rtNaN);
            } else if (rtb_DotProduct < 0.0) {
              absx = -1.0;
            } else {
              absx = (rtb_DotProduct > 0.0);
            }

            switch ((int32_T)absx) {
             case 1:
              if ((b_tmp[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) *
                  rtb_TmpSignalConversionAtUAVO_1 - (x2 -
                   UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) *
                  rtb_TmpSignalConversionAtUAVO_2 > 0.0) {
                xyLookaheadPoint[0] = b_tmp[0];
                xyLookaheadPoint[1] = x2;
              } else {
                xyLookaheadPoint[0] = b_tmp[1];
                xyLookaheadPoint[1] = y2;
              }
              break;

             case -1:
              if ((b_tmp[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) *
                  rtb_TmpSignalConversionAtUAVO_1 - (x2 -
                   UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) *
                  rtb_TmpSignalConversionAtUAVO_2 < 0.0) {
                xyLookaheadPoint[0] = b_tmp[0];
                xyLookaheadPoint[1] = x2;
              } else {
                xyLookaheadPoint[0] = b_tmp[1];
                xyLookaheadPoint[1] = y2;
              }
              break;

             default:
              if (fabs(UAM_Flight_control_angdiff(rt_atan2d_snf(x2 -
                     UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1], b_tmp[0] -
                     UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]),
                    UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3])) < fabs
                  (UAM_Flight_control_angdiff(rt_atan2d_snf(y2 -
                     UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1], b_tmp[1] -
                     UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]),
                    UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3]))) {
                xyLookaheadPoint[0] = b_tmp[0];
                xyLookaheadPoint[1] = x2;
              } else {
                xyLookaheadPoint[0] = b_tmp[1];
                xyLookaheadPoint[1] = y2;
              }

              if ((xyLookaheadPoint[0] -
                   UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) *
                  rtb_TmpSignalConversionAtUAVO_1 - (xyLookaheadPoint[1] -
                   UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) *
                  rtb_TmpSignalConversionAtUAVO_2 > 0.0) {
                UAM_Flight_control_DW.obj_cg.TurnDirectionInternal = 1.0;
              } else {
                UAM_Flight_control_DW.obj_cg.TurnDirectionInternal = -1.0;
              }

              UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag = false;
              break;
            }

            /* BusCreator: '<S2678>/Bus Creator' incorporates:
             *  Merge: '<S2671>/ Merge 2'
             */
            UAM_Flight_control_B.InnerLoopCmds.YawCmd = rt_atan2d_snf
              (rtb_TmpSignalConversionAtUAVO_1, rtb_TmpSignalConversionAtUAVO_2);
          }
        }

        if (guard2) {
          absx = UAM_Flight_control_norm_b(b_tmp);
          xyLookaheadPoint[0] = rtb_TmpSignalConversionAtUAVO_1 / absx * x2 +
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];
          xyLookaheadPoint[1] = rtb_TmpSignalConversionAtUAVO_2 / absx * x2 +
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];

          /* BusCreator: '<S2678>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd = rt_atan2d_snf
            (xyLookaheadPoint[1] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1],
             xyLookaheadPoint[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
          distToCenter = UAM_Flight_control_DW.obj_cg.NumCircles;
        }

        /* BusCreator: '<S2678>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] = xyLookaheadPoint[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] = xyLookaheadPoint[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd = rt_atan2d_snf
          (xyLookaheadPoint[1] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1],
           xyLookaheadPoint[0] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]);
      }

      /* Merge: '<S2671>/ Merge ' incorporates:
       *  DataTypeConversion: '<S2678>/Data Type Conversion'
       *  MATLABSystem: '<S2678>/UAV Orbit Follower'
       *  RelationalOperator: '<S2678>/Relational Operator'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       * */
      UAM_Flight_control_B.Status_p = (uint8_T)(distToCenter >
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[0]);
      break;

     case UAM_Flight_con_IN_PreTransition:
      if (UAM_Flight_control_DW.temporalCounter_i1 >= 1000) {
        UAM_Flight_control_B.FlightMode_c = BackTransition;
        UAM_Flight_control_B.controlMode_n.inTransition = 1U;
        UAM_Flight_control_B.controlMode_n.BackTransitionCondition = 0U;
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_co_IN_BackTransition;

        /* BusCreator: '<S2672>/Bus Creator1' incorporates:
         *  Constant: '<S2672>/Constant1'
         *  Constant: '<S2672>/Constant2'
         *  Gain: '<S2672>/Gain'
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_P.Gain_Gain_cf *
          BusConversion_InsertedFor_Guida->Xe[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_P.Gain_Gain_cf *
          BusConversion_InsertedFor_Guida->Xe[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_P.Gain_Gain_cf *
          BusConversion_InsertedFor_Guida->Xe[2];
        UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
          UAM_Flight_control_P.Constant1_Value_hc;
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.Constant2_Value_a;

        /* DataTypeConversion: '<S2672>/Data Type Conversion' incorporates:
         *  Constant: '<S2672>/Constant'
         */
        absx = floor(UAM_Flight_control_P.Constant_Value_l);
        if (rtIsNaN(absx) || rtIsInf(absx)) {
          absx = 0.0;
        } else {
          absx = fmod(absx, 256.0);
        }

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  DataTypeConversion: '<S2672>/Data Type Conversion'
         */
        UAM_Flight_control_B.Status_p = (uint8_T)(absx < 0.0 ? (int32_T)(uint8_T)
          -(int8_T)(uint8_T)-absx : (int32_T)(uint8_T)absx);
      }
      break;

     case UAM_Flight_control_IN_Start_c:
      UAM_Flight_control_Start(BusConversion_InsertedFor_Guida, &rtb_DotProduct,
        &x2, rtb_wps_c, rtb_wps_i);
      break;

     case UAM_Flight_control_IN_Takeoff:
      /* UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      if (UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2] <=
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2]) {
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_WP;

        /* RelationalOperator: '<S2685>/Equal' incorporates:
         *  Constant: '<S2685>/Constant'
         */
        rtb_Equal = (UAM_Flight_control_P.Constant_Value_p ==
                     UAM_Flight_control_DW.UnitDelay_3_DSTATE.mode);

        /* Outputs for Triggered SubSystem: '<S2685>/Triggered Subsystem' incorporates:
         *  TriggerPort: '<S2688>/Trigger'
         */
        if (rtb_Equal && (UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE
                          != POS_ZCSIG)) {
          /* Reshape: '<S2688>/Reshape' */
          UAM_Flight_control_B.Reshape[0] =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
          UAM_Flight_control_B.Reshape[1] =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
          UAM_Flight_control_B.Reshape[2] =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
        }

        UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_Equal;

        /* End of Outputs for SubSystem: '<S2685>/Triggered Subsystem' */

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         */
        UAM_Flight_control_DW.outWPS[6] =
          UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];

        /* Switch: '<S2685>/Switch' incorporates:
         *  Product: '<S2689>/Product'
         *  Reshape: '<S2688>/Reshape'
         */
        if (rtb_Equal) {
          rtb_DotProduct = UAM_Flight_control_B.Reshape[0];
        } else {
          rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
        }

        rtb_Product_ov[0] = rtb_DotProduct;

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         *  Product: '<S2689>/Product'
         */
        UAM_Flight_control_DW.outWPS[0] = rtb_DotProduct;
        UAM_Flight_control_DW.outWPS[1] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];

        /* Switch: '<S2685>/Switch' incorporates:
         *  Product: '<S2689>/Product'
         *  Reshape: '<S2688>/Reshape'
         */
        if (rtb_Equal) {
          rtb_DotProduct = UAM_Flight_control_B.Reshape[1];
        } else {
          rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
        }

        rtb_Product_ov[1] = rtb_DotProduct;

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         *  Product: '<S2689>/Product'
         */
        UAM_Flight_control_DW.outWPS[2] = rtb_DotProduct;
        UAM_Flight_control_DW.outWPS[3] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];

        /* Switch: '<S2685>/Switch' incorporates:
         *  Product: '<S2689>/Product'
         *  Reshape: '<S2688>/Reshape'
         */
        if (rtb_Equal) {
          rtb_DotProduct = UAM_Flight_control_B.Reshape[2];
        } else {
          rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
        }

        /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
         *  BusCreator generated from: '<S2680>/MATLAB Function'
         *  Product: '<S2689>/Product'
         */
        UAM_Flight_control_DW.outWPS[4] = rtb_DotProduct;
        UAM_Flight_control_DW.outWPS[5] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
        UAM_Flight_control_DW.outWPS[7] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];

        /* BusCreator: '<S2680>/Bus Creator' incorporates:
         *  Constant: '<S2680>/Lookahead Distance'
         *  MATLAB Function: '<S2680>/MATLAB Function'
         *  MATLABSystem: '<S2680>/Waypoint Follower'
         *  Merge: '<S2671>/ Merge 2'
         *  SignalConversion generated from: '<S2680>/Bus Creator'
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         * */
        UAM_Flight_cont_SystemCore_step(&UAM_Flight_control_DW.obj_l,
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE,
          UAM_Flight_control_DW.outWPS,
          UAM_Flight_control_P.LookaheadDistance_Value_p, v,
          &UAM_Flight_control_B.InnerLoopCmds.HeadingCmd, &x2, &b_varargout_4);
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] = v[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] = v[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];

        /* Saturate: '<S2680>/Yaw Cmd Sat' incorporates:
         *  MATLABSystem: '<S2680>/Waypoint Follower'
         * */
        if (x2 > UAM_Flight_control_P.YawCmdSat_UpperSat_o) {
          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_UpperSat_o;
        } else if (x2 < UAM_Flight_control_P.YawCmdSat_LowerSat_f) {
          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_LowerSat_f;
        } else {
          /* BusCreator: '<S2680>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd = x2;
        }

        /* Sum: '<S2686>/Sum1' incorporates:
         *  Product: '<S2689>/Product'
         */
        x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
          rtb_Product_ov[0];
        rtb_Product_ov[0] = x2;

        /* DotProduct: '<S2689>/Dot Product1' incorporates:
         *  Product: '<S2689>/Product'
         */
        absx = x2 * x2;

        /* Sum: '<S2686>/Sum1' incorporates:
         *  Product: '<S2689>/Product'
         */
        x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
          rtb_Product_ov[1];
        rtb_Product_ov[1] = x2;

        /* DotProduct: '<S2689>/Dot Product1' incorporates:
         *  Product: '<S2689>/Product'
         */
        absx += x2 * x2;

        /* Sum: '<S2686>/Sum1' incorporates:
         *  Product: '<S2689>/Product'
         *  Switch: '<S2685>/Switch'
         */
        x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] -
          rtb_DotProduct;

        /* DotProduct: '<S2689>/Dot Product1' incorporates:
         *  Product: '<S2689>/Product'
         */
        absx += x2 * x2;

        /* Saturate: '<S2689>/Saturation' incorporates:
         *  DotProduct: '<S2689>/Dot Product1'
         */
        if (absx > UAM_Flight_control_P.Saturation_UpperSat_hb) {
          absx = UAM_Flight_control_P.Saturation_UpperSat_hb;
        } else if (absx < UAM_Flight_control_P.Saturation_LowerSat_m) {
          absx = UAM_Flight_control_P.Saturation_LowerSat_m;
        }

        /* Sqrt: '<S2689>/Sqrt' incorporates:
         *  Saturate: '<S2689>/Saturation'
         */
        rtb_DotProduct = sqrt(absx);

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  Constant: '<S2680>/Constant1'
         *  DataTypeConversion: '<S2680>/Data Type Conversion'
         *  DotProduct: '<S2686>/Dot Product'
         *  Product: '<S2689>/Product'
         *  RelationalOperator: '<S2680>/Relational Operator'
         *  Sum: '<S2686>/Sum'
         *  Sum: '<S2686>/Sum1'
         */
        UAM_Flight_control_B.Status_p = (uint8_T)
          (UAM_Flight_control_P.Constant1_Value_n >=
           ((UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
             UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * (rtb_Product_ov[0] /
             rtb_DotProduct) +
            (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
             UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) * (rtb_Product_ov[1] /
             rtb_DotProduct)) +
           (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] -
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2]) * (x2 / rtb_DotProduct));
      } else {
        /* BusCreator: '<S2679>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         *  SignalConversion generated from: '<S2679>/Bus Creator'
         */
        UAM_Flight_control_B.InnerLoopCmds.LAP[0] =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
        UAM_Flight_control_B.InnerLoopCmds.LAP[1] =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
        UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
          UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];

        /* Saturate: '<S2679>/Hdg. Cmd Sat' */
        if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] >
            UAM_Flight_control_P.HdgCmdSat_UpperSat_e) {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_P.HdgCmdSat_UpperSat_e;
        } else if (UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3] <
                   UAM_Flight_control_P.HdgCmdSat_LowerSat_f) {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_P.HdgCmdSat_LowerSat_f;
        } else {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.HeadingCmd =
            UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];
        }

        /* Saturate: '<S2679>/Yaw Cmd Sat' incorporates:
         *  Constant: '<S2679>/Constant1'
         */
        if (UAM_Flight_control_P.Constant1_Value_b >
            UAM_Flight_control_P.YawCmdSat_UpperSat_f) {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_UpperSat_f;
        } else if (UAM_Flight_control_P.Constant1_Value_b <
                   UAM_Flight_control_P.YawCmdSat_LowerSat_p) {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.YawCmdSat_LowerSat_p;
        } else {
          /* BusCreator: '<S2679>/Bus Creator' incorporates:
           *  Merge: '<S2671>/ Merge 2'
           */
          UAM_Flight_control_B.InnerLoopCmds.YawCmd =
            UAM_Flight_control_P.Constant1_Value_b;
        }

        /* Merge: '<S2671>/ Merge ' incorporates:
         *  Constant: '<S2679>/Constant'
         *  SignalConversion generated from: '<S2679>/Status'
         */
        UAM_Flight_control_B.Status_p = UAM_Flight_control_P.Constant_Value_gm;
      }

      /* End of UnitDelay generated from: '<S2>/Unit Delay1' */
      break;

     case UAM_Flight_co_IN_TransitionStep:
      /* UnitDelay: '<S2>/Unit Delay2' incorporates:
       *  Merge: '<S2671>/ Merge '
       */
      if (UAM_Fl_transitionConditionMet_h
          (UAM_Flight_control_DW.UnitDelay2_DSTATE_l)) {
        UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_cont_IN_FWCOMPLETE_b;
        UAM_Flight_control_B.Status_p = 1U;
        UAM_Flight_control_B.controlMode_n.TransitionCondition = 1U;
      } else {
        UAM_Flight_control_B.controlMode_n.TransitionStep = 1U;
      }
      break;

     default:
      /* RelationalOperator: '<S2685>/Equal' incorporates:
       *  Constant: '<S2685>/Constant'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      /* case IN_WP: */
      rtb_Equal = (UAM_Flight_control_P.Constant_Value_p ==
                   UAM_Flight_control_DW.UnitDelay_3_DSTATE.mode);

      /* Outputs for Triggered SubSystem: '<S2685>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S2688>/Trigger'
       */
      if (rtb_Equal && (UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE
                        != POS_ZCSIG)) {
        /* Reshape: '<S2688>/Reshape' incorporates:
         *  UnitDelay generated from: '<S2>/Unit Delay1'
         */
        UAM_Flight_control_B.Reshape[0] =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
        UAM_Flight_control_B.Reshape[1] =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
        UAM_Flight_control_B.Reshape[2] =
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
      }

      UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_Equal;

      /* End of Outputs for SubSystem: '<S2685>/Triggered Subsystem' */

      /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
       *  BusCreator generated from: '<S2680>/MATLAB Function'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      UAM_Flight_control_DW.outWPS[6] =
        UAM_Flight_control_DW.UnitDelay_3_DSTATE.params[3];

      /* Switch: '<S2685>/Switch' incorporates:
       *  Product: '<S2689>/Product'
       *  Reshape: '<S2688>/Reshape'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      if (rtb_Equal) {
        rtb_DotProduct = UAM_Flight_control_B.Reshape[0];
      } else {
        rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[0];
      }

      rtb_Product_ov[0] = rtb_DotProduct;

      /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
       *  BusCreator generated from: '<S2680>/MATLAB Function'
       *  Product: '<S2689>/Product'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      UAM_Flight_control_DW.outWPS[0] = rtb_DotProduct;
      UAM_Flight_control_DW.outWPS[1] =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0];

      /* Switch: '<S2685>/Switch' incorporates:
       *  Product: '<S2689>/Product'
       *  Reshape: '<S2688>/Reshape'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      if (rtb_Equal) {
        rtb_DotProduct = UAM_Flight_control_B.Reshape[1];
      } else {
        rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[1];
      }

      rtb_Product_ov[1] = rtb_DotProduct;

      /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
       *  BusCreator generated from: '<S2680>/MATLAB Function'
       *  Product: '<S2689>/Product'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      UAM_Flight_control_DW.outWPS[2] = rtb_DotProduct;
      UAM_Flight_control_DW.outWPS[3] =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1];

      /* Switch: '<S2685>/Switch' incorporates:
       *  Product: '<S2689>/Product'
       *  Reshape: '<S2688>/Reshape'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      if (rtb_Equal) {
        rtb_DotProduct = UAM_Flight_control_B.Reshape[2];
      } else {
        rtb_DotProduct = UAM_Flight_control_DW.UnitDelay_3_DSTATE.position[2];
      }

      /* MATLAB Function: '<S2680>/MATLAB Function' incorporates:
       *  BusCreator generated from: '<S2680>/MATLAB Function'
       *  Product: '<S2689>/Product'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      UAM_Flight_control_DW.outWPS[4] = rtb_DotProduct;
      UAM_Flight_control_DW.outWPS[5] =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];
      UAM_Flight_control_DW.outWPS[7] =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.params[3];

      /* BusCreator: '<S2680>/Bus Creator' incorporates:
       *  Constant: '<S2680>/Lookahead Distance'
       *  MATLAB Function: '<S2680>/MATLAB Function'
       *  MATLABSystem: '<S2680>/Waypoint Follower'
       *  Merge: '<S2671>/ Merge 2'
       *  SignalConversion generated from: '<S2680>/Bus Creator'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       *  UnitDelay generated from: '<S2>/Unit Delay1'
       * */
      UAM_Flight_cont_SystemCore_step(&UAM_Flight_control_DW.obj_l,
        UAM_Flight_control_DW.UnitDelay1_1_DSTATE, UAM_Flight_control_DW.outWPS,
        UAM_Flight_control_P.LookaheadDistance_Value_p, v,
        &UAM_Flight_control_B.InnerLoopCmds.HeadingCmd, &x2, &b_varargout_4);
      UAM_Flight_control_B.InnerLoopCmds.LAP[0] = v[0];
      UAM_Flight_control_B.InnerLoopCmds.LAP[1] = v[1];
      UAM_Flight_control_B.InnerLoopCmds.LAP[2] =
        UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2];

      /* Saturate: '<S2680>/Yaw Cmd Sat' incorporates:
       *  MATLABSystem: '<S2680>/Waypoint Follower'
       * */
      if (x2 > UAM_Flight_control_P.YawCmdSat_UpperSat_o) {
        /* BusCreator: '<S2680>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.YawCmdSat_UpperSat_o;
      } else if (x2 < UAM_Flight_control_P.YawCmdSat_LowerSat_f) {
        /* BusCreator: '<S2680>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.YawCmd =
          UAM_Flight_control_P.YawCmdSat_LowerSat_f;
      } else {
        /* BusCreator: '<S2680>/Bus Creator' incorporates:
         *  Merge: '<S2671>/ Merge 2'
         */
        UAM_Flight_control_B.InnerLoopCmds.YawCmd = x2;
      }

      /* Sum: '<S2686>/Sum1' incorporates:
       *  Product: '<S2689>/Product'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
        rtb_Product_ov[0];
      rtb_Product_ov[0] = x2;

      /* DotProduct: '<S2689>/Dot Product1' incorporates:
       *  Product: '<S2689>/Product'
       */
      absx = x2 * x2;

      /* Sum: '<S2686>/Sum1' incorporates:
       *  Product: '<S2689>/Product'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[1] -
        rtb_Product_ov[1];
      rtb_Product_ov[1] = x2;

      /* DotProduct: '<S2689>/Dot Product1' incorporates:
       *  Product: '<S2689>/Product'
       */
      absx += x2 * x2;

      /* Sum: '<S2686>/Sum1' incorporates:
       *  Product: '<S2689>/Product'
       *  Switch: '<S2685>/Switch'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       */
      x2 = UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] - rtb_DotProduct;

      /* DotProduct: '<S2689>/Dot Product1' incorporates:
       *  Product: '<S2689>/Product'
       */
      absx += x2 * x2;

      /* Saturate: '<S2689>/Saturation' incorporates:
       *  DotProduct: '<S2689>/Dot Product1'
       */
      if (absx > UAM_Flight_control_P.Saturation_UpperSat_hb) {
        absx = UAM_Flight_control_P.Saturation_UpperSat_hb;
      } else if (absx < UAM_Flight_control_P.Saturation_LowerSat_m) {
        absx = UAM_Flight_control_P.Saturation_LowerSat_m;
      }

      /* Sqrt: '<S2689>/Sqrt' incorporates:
       *  Saturate: '<S2689>/Saturation'
       */
      rtb_DotProduct = sqrt(absx);

      /* Merge: '<S2671>/ Merge ' incorporates:
       *  Constant: '<S2680>/Constant1'
       *  DataTypeConversion: '<S2680>/Data Type Conversion'
       *  DotProduct: '<S2686>/Dot Product'
       *  Product: '<S2689>/Product'
       *  RelationalOperator: '<S2680>/Relational Operator'
       *  Sum: '<S2686>/Sum'
       *  Sum: '<S2686>/Sum1'
       *  UnitDelay generated from: '<S2>/Unit Delay'
       *  UnitDelay generated from: '<S2>/Unit Delay1'
       */
      UAM_Flight_control_B.Status_p = (uint8_T)
        (UAM_Flight_control_P.Constant1_Value_n >=
         ((UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[0] -
           UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0]) * (rtb_Product_ov[0] /
           rtb_DotProduct) + (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position
           [1] - UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1]) *
          (rtb_Product_ov[1] / rtb_DotProduct)) +
         (UAM_Flight_control_DW.UnitDelay_2_DSTATE.position[2] -
          UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2]) * (x2 / rtb_DotProduct));
      break;
    }
  }
}

/* Function for MATLAB Function: '<S1984>/Desaturation' */
static real_T UAM_Flight_control_compute_gain(const real_T dir[4], const real_T
  m[4], const real_T act_min[4], const real_T act_max[4])
{
  real_T k_max;
  real_T k_min;
  real_T ki;
  k_min = 0.0;
  k_max = 0.0;
  if (!(fabs(dir[0]) < 0.2)) {
    if (m[0] < act_min[0]) {
      ki = (act_min[0] - m[0]) / dir[0];
      k_min = fmin(0.0, ki);
      k_max = fmax(0.0, ki);
    }

    if (m[0] > act_max[0]) {
      ki = (act_max[0] - m[0]) / dir[0];
      k_min = fmin(k_min, ki);
      k_max = fmax(k_max, ki);
    }
  }

  if (!(fabs(dir[1]) < 0.2)) {
    if (m[1] < act_min[1]) {
      ki = (act_min[1] - m[1]) / dir[1];
      k_min = fmin(k_min, ki);
      k_max = fmax(k_max, ki);
    }

    if (m[1] > act_max[1]) {
      ki = (act_max[1] - m[1]) / dir[1];
      k_min = fmin(k_min, ki);
      k_max = fmax(k_max, ki);
    }
  }

  if (!(fabs(dir[2]) < 0.2)) {
    if (m[2] < act_min[2]) {
      ki = (act_min[2] - m[2]) / dir[2];
      k_min = fmin(k_min, ki);
      k_max = fmax(k_max, ki);
    }

    if (m[2] > act_max[2]) {
      ki = (act_max[2] - m[2]) / dir[2];
      k_min = fmin(k_min, ki);
      k_max = fmax(k_max, ki);
    }
  }

  if (!(fabs(dir[3]) < 0.2)) {
    if (m[3] < act_min[3]) {
      ki = (act_min[3] - m[3]) / dir[3];
      k_min = fmin(k_min, ki);
      k_max = fmax(k_max, ki);
    }

    if (m[3] > act_max[3]) {
      ki = (act_max[3] - m[3]) / dir[3];
      k_min = fmin(k_min, ki);
      k_max = fmax(k_max, ki);
    }
  }

  return k_min + k_max;
}

/* Function for MATLAB Function: '<S1984>/Desaturation' */
static void UAM_Flight_control_desat_axis(real_T m[4], const real_T dir[4],
  const real_T act_min[4], const real_T act_max[4], boolean_T thrust_only_down)
{
  real_T k;
  boolean_T tmp;
  k = UAM_Flight_control_compute_gain(dir, m, act_min, act_max);
  tmp = !thrust_only_down;
  if (tmp || (!(k > 0.0))) {
    m[0] += k * dir[0];
    m[1] += k * dir[1];
    m[2] += k * dir[2];
    m[3] += k * dir[3];
  }

  k = 0.5 * UAM_Flight_control_compute_gain(dir, m, act_min, act_max);
  if (tmp || (!(k > 0.0))) {
    m[0] += k * dir[0];
    m[1] += k * dir[1];
    m[2] += k * dir[2];
    m[3] += k * dir[3];
  }
}

static void UAM_Flight_control_NED_ecompass(const real_T a[3], const real_T m[3],
  real_T R[9])
{
  real_T x[9];
  real_T Reast[3];
  real_T R_0;
  int32_T i2;
  int32_T xpageoffset;
  boolean_T b[9];
  boolean_T y[3];
  boolean_T exitg1;
  boolean_T nanPageIdx;

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  Reast[0] = a[1] * m[2] - m[1] * a[2];
  Reast[1] = m[0] * a[2] - a[0] * m[2];
  Reast[2] = a[0] * m[1] - m[0] * a[1];
  R[6] = a[0];
  R[3] = Reast[0];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  R[7] = a[1];
  R[4] = Reast[1];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  R[8] = a[2];
  R[5] = Reast[2];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  R[0] = Reast[1] * a[2] - a[1] * Reast[2];
  R[1] = a[0] * Reast[2] - Reast[0] * a[2];
  R[2] = Reast[0] * a[1] - a[0] * Reast[1];
  for (i2 = 0; i2 < 9; i2++) {
    R_0 = R[i2];
    x[i2] = R_0 * R_0;
  }

  for (i2 = 0; i2 < 3; i2++) {
    xpageoffset = i2 * 3;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    Reast[i2] = (x[xpageoffset + 1] + x[xpageoffset]) + x[xpageoffset + 2];
  }

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  Reast[0] = sqrt(Reast[0]);
  Reast[1] = sqrt(Reast[1]);
  Reast[2] = sqrt(Reast[2]);
  memcpy(&x[0], &R[0], 9U * sizeof(real_T));
  for (i2 = 0; i2 < 3; i2++) {
    /* Start for MATLABSystem: '<S2700>/AHRS' */
    R_0 = Reast[i2];
    R[3 * i2] = x[3 * i2] / R_0;
    xpageoffset = 3 * i2 + 1;
    R[xpageoffset] = x[xpageoffset] / R_0;
    xpageoffset = 3 * i2 + 2;
    R[xpageoffset] = x[xpageoffset] / R_0;
  }

  for (i2 = 0; i2 < 9; i2++) {
    /* Start for MATLABSystem: '<S2700>/AHRS' */
    b[i2] = rtIsNaN(R[i2]);
  }

  y[0] = false;
  y[1] = false;
  y[2] = false;

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  i2 = 1;
  for (xpageoffset = 0; xpageoffset < 3; xpageoffset++) {
    int32_T i2_0;
    int32_T ix;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    i2_0 = i2;
    ix = i2;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    i2 += 3;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2_0 + 2)) {
      if (b[ix - 1]) {
        y[xpageoffset] = true;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  nanPageIdx = false;
  i2 = 0;
  exitg1 = false;
  while ((!exitg1) && (i2 < 3)) {
    if (y[i2]) {
      nanPageIdx = true;
      exitg1 = true;
    } else {
      i2++;
    }
  }

  if (nanPageIdx) {
    memset(&R[0], 0, 9U * sizeof(real_T));
    R[0] = 1.0;
    R[4] = 1.0;
    R[8] = 1.0;
  }
}

static void UAM_Fligh_quaternion_quaternion(const real_T varargin_1[3], real_T
  *obj_a, real_T *obj_b, real_T *obj_c, real_T *obj_d)
{
  real_T st;
  real_T theta;
  *obj_a = 1.0;
  *obj_b = 0.0;
  *obj_c = 0.0;
  *obj_d = 0.0;

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  theta = sqrt((varargin_1[0] * varargin_1[0] + varargin_1[1] * varargin_1[1]) +
               varargin_1[2] * varargin_1[2]);
  st = sin(theta / 2.0);
  if (theta != 0.0) {
    /* Start for MATLABSystem: '<S2700>/AHRS' */
    *obj_a = cos(theta / 2.0);
    *obj_b = varargin_1[0] / theta * st;
    *obj_c = varargin_1[1] / theta * st;
    *obj_d = varargin_1[2] / theta * st;
  }
}

static void UAM_Fligh_quaternionBase_rotmat(real_T q_a, real_T q_b, real_T q_c,
  real_T q_d, real_T r[9])
{
  real_T aasq;
  real_T ac2;
  real_T ad2;
  real_T bc2;
  real_T bd2;
  real_T cd2;
  real_T n;

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  n = sqrt(((q_a * q_a + q_b * q_b) + q_c * q_c) + q_d * q_d);
  q_a /= n;
  q_b /= n;
  q_c /= n;
  q_d /= n;

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  n = q_a * q_b * 2.0;
  ac2 = q_a * q_c * 2.0;
  ad2 = q_a * q_d * 2.0;
  bc2 = q_b * q_c * 2.0;
  bd2 = q_b * q_d * 2.0;
  cd2 = q_c * q_d * 2.0;
  aasq = q_a * q_a * 2.0 - 1.0;
  r[0] = q_b * q_b * 2.0 + aasq;
  r[3] = bc2 + ad2;
  r[6] = bd2 - ac2;
  r[1] = bc2 - ad2;
  r[4] = q_c * q_c * 2.0 + aasq;
  r[7] = cd2 + n;
  r[2] = bd2 + ac2;
  r[5] = cd2 - n;
  r[8] = q_d * q_d * 2.0 + aasq;
}

static void UAM_Flight_control_mrdiv_b(real_T A[72], const real_T B[36])
{
  real_T c_A[36];
  real_T smax;
  int32_T a;
  int32_T b_j;
  int32_T c;
  int32_T jA;
  int32_T jAcol;
  int32_T jBcol;
  int32_T jj;
  int32_T k;
  int8_T b_ipiv[6];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  memcpy(&c_A[0], &B[0], 36U * sizeof(real_T));
  for (c = 0; c < 6; c++) {
    b_ipiv[c] = (int8_T)(c + 1);
  }

  for (b_j = 0; b_j < 5; b_j++) {
    /* Start for MATLABSystem: '<S2700>/AHRS' */
    c = b_j * 7 + 2;
    jj = b_j * 7;
    jBcol = 6 - b_j;
    a = 1;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    smax = fabs(c_A[jj]);
    for (k = 2; k <= jBcol; k++) {
      real_T s;
      s = fabs(c_A[(c + k) - 3]);
      if (s > smax) {
        a = k;
        smax = s;
      }
    }

    if (c_A[(c + a) - 3] != 0.0) {
      if (a - 1 != 0) {
        a += b_j;
        b_ipiv[b_j] = (int8_T)a;
        for (k = 0; k < 6; k++) {
          jBcol = k * 6 + b_j;
          smax = c_A[jBcol];
          jAcol = (k * 6 + a) - 1;
          c_A[jBcol] = c_A[jAcol];
          c_A[jAcol] = smax;
        }
      }

      k = c - b_j;
      for (a = c; a <= k + 4; a++) {
        c_A[a - 1] /= c_A[jj];
      }
    }

    jA = jj;
    k = 5 - b_j;
    for (a = 0; a < k; a++) {
      /* Start for MATLABSystem: '<S2700>/AHRS' */
      smax = c_A[(a * 6 + jj) + 6];
      if (smax != 0.0) {
        int32_T d;

        /* Start for MATLABSystem: '<S2700>/AHRS' */
        jBcol = jA + 8;
        d = (jA - b_j) + 12;
        for (jAcol = jBcol; jAcol <= d; jAcol++) {
          /* Start for MATLABSystem: '<S2700>/AHRS' */
          c_A[jAcol - 1] += c_A[((c + jAcol) - jA) - 9] * -smax;
        }
      }

      /* Start for MATLABSystem: '<S2700>/AHRS' */
      jA += 6;
    }
  }

  for (b_j = 0; b_j < 6; b_j++) {
    jBcol = 12 * b_j - 1;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    jAcol = 6 * b_j - 1;
    for (a = 0; a < b_j; a++) {
      jA = 12 * a - 1;

      /* Start for MATLABSystem: '<S2700>/AHRS' */
      smax = c_A[(a + jAcol) + 1];
      if (smax != 0.0) {
        for (jj = 0; jj < 12; jj++) {
          c = (jj + jBcol) + 1;
          A[c] -= A[(jj + jA) + 1] * smax;
        }
      }
    }

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    smax = 1.0 / c_A[(b_j + jAcol) + 1];
    for (a = 0; a < 12; a++) {
      c = (a + jBcol) + 1;
      A[c] *= smax;
    }
  }

  for (a = 5; a >= 0; a--) {
    jBcol = 12 * a - 1;
    jAcol = 6 * a - 1;
    for (k = a + 2; k < 7; k++) {
      jA = (k - 1) * 12 - 1;

      /* Start for MATLABSystem: '<S2700>/AHRS' */
      smax = c_A[k + jAcol];
      if (smax != 0.0) {
        for (jj = 0; jj < 12; jj++) {
          c = (jj + jBcol) + 1;
          A[c] -= A[(jj + jA) + 1] * smax;
        }
      }
    }
  }

  for (a = 4; a >= 0; a--) {
    /* Start for MATLABSystem: '<S2700>/AHRS' */
    b_j = b_ipiv[a];
    if (a + 1 != b_j) {
      for (jj = 0; jj < 12; jj++) {
        jBcol = 12 * a + jj;
        smax = A[jBcol];
        c = (b_j - 1) * 12 + jj;
        A[jBcol] = A[c];
        A[c] = smax;
      }
    }
  }
}

static void UAM_Flight_co_SystemCore_step_b(fusion_simulink_ahrsfilter_UA_T *obj,
  const real_T varargin_1[3], const real_T varargin_2[3], const real_T
  varargin_3[3], real_T varargout_1[4], real_T varargout_2[3])
{
  real_T Ppost[144];
  real_T H[72];
  real_T K_tmp[72];
  real_T K_tmp_0[72];
  real_T K_tmp_1[36];
  real_T xe_post[12];
  real_T Rprior[9];
  real_T Rprior_0[9];
  real_T h2[9];
  real_T res[6];
  real_T psquared[4];
  real_T deltaAng[3];
  real_T gravityAccelGyroDiff[3];
  real_T l_tmp[3];
  real_T pLinAccelPostIn[3];
  real_T absxk;
  real_T accelMeasNoiseVar;
  real_T deltaq_a;
  real_T deltaq_b;
  real_T deltaq_c;
  real_T deltaq_d;
  real_T invpa;
  real_T invpd;
  real_T magMeasNoiseVar;
  real_T pGyroOffsetIn_idx_2;
  real_T pa;
  real_T pd;
  real_T scale;
  real_T t;
  real_T tmp;
  int32_T H_tmp;
  int32_T H_tmp_0;
  int32_T aoffset;
  int32_T b_idx;
  int32_T k;
  boolean_T isJamming;
  static const int8_T tmp_0[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T tmp_1[9] = { -1, 0, 0, 0, -1, 0, 0, 0, -1 };

  boolean_T exitg1;

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  if (obj->TunablePropsChanged) {
    obj->TunablePropsChanged = false;
    obj->pSensorPeriod = 0.005;
    obj->pKalmanPeriod = obj->pSensorPeriod;
    magMeasNoiseVar = obj->pKalmanPeriod * obj->pKalmanPeriod *
      (obj->GyroscopeDriftNoise + obj->GyroscopeNoise);
    accelMeasNoiseVar = (obj->AccelerometerNoise + obj->LinearAccelerationNoise)
      + magMeasNoiseVar;
    magMeasNoiseVar += obj->MagnetometerNoise + obj->MagneticDisturbanceNoise;
    memset(&Rprior[0], 0, 9U * sizeof(real_T));
    Rprior[0] = 1.0;
    Rprior[4] = 1.0;
    Rprior[8] = 1.0;
    memset(&obj->pQv[0], 0, 36U * sizeof(real_T));
    for (k = 0; k < 3; k++) {
      obj->pQv[6 * k] = Rprior[3 * k] * accelMeasNoiseVar;
      aoffset = (k + 3) * 6;
      obj->pQv[aoffset + 3] = (real_T)tmp_0[3 * k] * magMeasNoiseVar;
      b_idx = 3 * k + 1;
      obj->pQv[6 * k + 1] = Rprior[b_idx] * accelMeasNoiseVar;
      obj->pQv[aoffset + 4] = (real_T)tmp_0[b_idx] * magMeasNoiseVar;
      b_idx = 3 * k + 2;
      obj->pQv[6 * k + 2] = Rprior[b_idx] * accelMeasNoiseVar;
      obj->pQv[aoffset + 5] = (real_T)tmp_0[b_idx] * magMeasNoiseVar;
    }
  }

  accelMeasNoiseVar = obj->pGyroOffset[0];
  magMeasNoiseVar = obj->pGyroOffset[1];
  pGyroOffsetIn_idx_2 = obj->pGyroOffset[2];
  if (obj->pFirstTime) {
    UAM_Flight_control_NED_ecompass(varargin_1, varargin_3, Rprior);
    pd = (Rprior[0] + Rprior[4]) + Rprior[8];
    psquared[0] = (pd * 2.0 + 1.0) - pd;
    psquared[1] = (2.0 * Rprior[0] + 1.0) - pd;
    psquared[2] = (2.0 * Rprior[4] + 1.0) - pd;
    psquared[3] = (2.0 * Rprior[8] + 1.0) - pd;
    if (!rtIsNaN(psquared[0])) {
      aoffset = 1;
    } else {
      aoffset = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 5)) {
        if (!rtIsNaN(psquared[k - 1])) {
          aoffset = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (aoffset == 0) {
      pd = psquared[0];
      aoffset = 1;
    } else {
      pd = psquared[aoffset - 1];
      b_idx = aoffset;
      for (k = aoffset + 1; k < 5; k++) {
        pa = psquared[k - 1];
        if (pd < pa) {
          pd = pa;
          b_idx = k;
        }
      }

      aoffset = b_idx;
    }

    switch (aoffset) {
     case 1:
      pa = sqrt(pd);
      pd = 0.5 * pa;
      invpa = 0.5 / pa;
      pa = (Rprior[7] - Rprior[5]) * invpa;
      invpd = (Rprior[2] - Rprior[6]) * invpa;
      invpa *= Rprior[3] - Rprior[1];
      break;

     case 2:
      pd = sqrt(pd);
      pa = 0.5 * pd;
      invpa = 0.5 / pd;
      pd = (Rprior[7] - Rprior[5]) * invpa;
      invpd = (Rprior[1] + Rprior[3]) * invpa;
      invpa *= Rprior[2] + Rprior[6];
      break;

     case 3:
      pd = sqrt(pd);
      invpd = 0.5 * pd;
      invpa = 0.5 / pd;
      pd = (Rprior[2] - Rprior[6]) * invpa;
      pa = (Rprior[1] + Rprior[3]) * invpa;
      invpa *= Rprior[5] + Rprior[7];
      break;

     default:
      pd = sqrt(pd);
      invpa = 0.5 * pd;
      invpd = 0.5 / pd;
      pd = (Rprior[3] - Rprior[1]) * invpd;
      pa = (Rprior[2] + Rprior[6]) * invpd;
      invpd *= Rprior[5] + Rprior[7];
      break;
    }

    if (pd < 0.0) {
      pd = -pd;
      pa = -pa;
      invpd = -invpd;
      invpa = -invpa;
    }

    obj->pOrientPost.a = pd;
    obj->pOrientPost.b = pa;
    obj->pOrientPost.c = invpd;
    obj->pOrientPost.d = invpa;
  }

  deltaAng[0] = (varargin_2[0] - obj->pGyroOffset[0]) * obj->pSensorPeriod;
  deltaAng[1] = (varargin_2[1] - obj->pGyroOffset[1]) * obj->pSensorPeriod;
  deltaAng[2] = (varargin_2[2] - obj->pGyroOffset[2]) * obj->pSensorPeriod;
  UAM_Fligh_quaternion_quaternion(deltaAng, &deltaq_a, &deltaq_b, &deltaq_c,
    &deltaq_d);

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  pd = ((obj->pOrientPost.a * deltaq_a - obj->pOrientPost.b * deltaq_b) -
        obj->pOrientPost.c * deltaq_c) - obj->pOrientPost.d * deltaq_d;
  pa = ((obj->pOrientPost.a * deltaq_b + obj->pOrientPost.b * deltaq_a) +
        obj->pOrientPost.c * deltaq_d) - obj->pOrientPost.d * deltaq_c;
  invpd = ((obj->pOrientPost.a * deltaq_c - obj->pOrientPost.b * deltaq_d) +
           obj->pOrientPost.c * deltaq_a) + obj->pOrientPost.d * deltaq_b;
  invpa = ((obj->pOrientPost.a * deltaq_d + obj->pOrientPost.b * deltaq_c) -
           obj->pOrientPost.c * deltaq_b) + obj->pOrientPost.d * deltaq_a;
  if (pd < 0.0) {
    /* Start for MATLABSystem: '<S2700>/AHRS' */
    pd = -pd;
    pa = -pa;
    invpd = -invpd;
    invpa = -invpa;
  }

  UAM_Fligh_quaternionBase_rotmat(pd, pa, invpd, invpa, Rprior);

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  for (k = 0; k < 3; k++) {
    scale = Rprior[k + 6];
    absxk = scale * 9.81;
    deltaAng[k] = absxk;
    t = obj->LinearAccelerationDecayFactor * obj->pLinAccelPost[k];
    pLinAccelPostIn[k] = t;
    gravityAccelGyroDiff[k] = (varargin_1[k] + t) - absxk;
    l_tmp[k] = (Rprior[k + 3] * obj->pMagVec[1] + Rprior[k] * obj->pMagVec[0]) +
      scale * obj->pMagVec[2];
  }

  memset(&Rprior[0], 0, 9U * sizeof(real_T));

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  Rprior[3] = deltaAng[2];
  Rprior[6] = -deltaAng[1];
  Rprior[7] = deltaAng[0];
  for (k = 0; k < 3; k++) {
    Rprior_0[3 * k] = Rprior[3 * k];
    aoffset = 3 * k + 1;
    Rprior_0[aoffset] = Rprior[aoffset] - Rprior[k + 3];
    aoffset = 3 * k + 2;
    Rprior_0[aoffset] = Rprior[aoffset] - Rprior[k + 6];
  }

  for (k = 0; k < 9; k++) {
    Rprior[k] = Rprior_0[k];
    h2[k] = 0.0;
  }

  h2[3] = l_tmp[2];
  h2[6] = -l_tmp[1];
  h2[7] = l_tmp[0];
  for (k = 0; k < 3; k++) {
    Rprior_0[3 * k] = h2[3 * k];
    aoffset = 3 * k + 1;
    Rprior_0[aoffset] = h2[aoffset] - h2[k + 3];
    aoffset = 3 * k + 2;
    Rprior_0[aoffset] = h2[aoffset] - h2[k + 6];
  }

  memcpy(&h2[0], &Rprior_0[0], 9U * sizeof(real_T));
  for (k = 0; k < 3; k++) {
    scale = Rprior[3 * k];
    H[6 * k] = scale;
    b_idx = (k + 3) * 6;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    H[b_idx] = -scale * obj->pKalmanPeriod;
    H_tmp = (k + 6) * 6;
    H[H_tmp] = tmp_0[3 * k];
    H_tmp_0 = (k + 9) * 6;
    H[H_tmp_0] = 0.0;
    scale = h2[3 * k];
    H[6 * k + 3] = scale;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    H[b_idx + 3] = -scale * obj->pKalmanPeriod;
    H[H_tmp + 3] = 0.0;
    H[H_tmp_0 + 3] = tmp_1[3 * k];
    aoffset = 3 * k + 1;
    scale = Rprior[aoffset];
    H[6 * k + 1] = scale;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    H[b_idx + 1] = -scale * obj->pKalmanPeriod;
    H[H_tmp + 1] = tmp_0[aoffset];
    H[H_tmp_0 + 1] = 0.0;
    scale = h2[aoffset];
    H[6 * k + 4] = scale;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    H[b_idx + 4] = -scale * obj->pKalmanPeriod;
    H[H_tmp + 4] = 0.0;
    H[H_tmp_0 + 4] = tmp_1[aoffset];
    aoffset = 3 * k + 2;
    scale = Rprior[aoffset];
    H[6 * k + 2] = scale;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    H[b_idx + 2] = -scale * obj->pKalmanPeriod;
    H[H_tmp + 2] = tmp_0[aoffset];
    H[H_tmp_0 + 2] = 0.0;
    scale = h2[aoffset];
    H[6 * k + 5] = scale;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    H[b_idx + 5] = -scale * obj->pKalmanPeriod;
    H[H_tmp + 5] = 0.0;
    H[H_tmp_0 + 5] = tmp_1[aoffset];
  }

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  for (k = 0; k < 6; k++) {
    for (aoffset = 0; aoffset < 12; aoffset++) {
      H_tmp = 6 * aoffset + k;
      K_tmp[aoffset + 12 * k] = H[H_tmp];
      scale = 0.0;
      for (b_idx = 0; b_idx < 12; b_idx++) {
        scale += H[6 * b_idx + k] * obj->pQw[12 * aoffset + b_idx];
      }

      K_tmp_0[H_tmp] = scale;
    }
  }

  for (k = 0; k < 6; k++) {
    for (aoffset = 0; aoffset < 12; aoffset++) {
      scale = 0.0;
      for (b_idx = 0; b_idx < 12; b_idx++) {
        scale += obj->pQw[12 * b_idx + aoffset] * K_tmp[12 * k + b_idx];
      }

      H[aoffset + 12 * k] = scale;
    }

    for (aoffset = 0; aoffset < 6; aoffset++) {
      tmp = 0.0;
      for (b_idx = 0; b_idx < 12; b_idx++) {
        tmp += K_tmp_0[6 * b_idx + aoffset] * K_tmp[12 * k + b_idx];
      }

      K_tmp_1[k + 6 * aoffset] = obj->pQv[6 * k + aoffset] + tmp;
    }
  }

  UAM_Flight_control_mrdiv_b(H, K_tmp_1);
  res[0] = gravityAccelGyroDiff[0];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  res[3] = varargin_3[0] - l_tmp[0];
  res[1] = gravityAccelGyroDiff[1];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  res[4] = varargin_3[1] - l_tmp[1];
  res[2] = gravityAccelGyroDiff[2];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  res[5] = varargin_3[2] - l_tmp[2];
  for (k = 0; k < 3; k++) {
    deltaq_a = 0.0;
    for (aoffset = 0; aoffset < 6; aoffset++) {
      deltaq_a += H[(12 * aoffset + k) + 9] * res[aoffset];
    }

    l_tmp[k] = deltaq_a;
  }

  scale = 3.3121686421112381E-170;

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  absxk = fabs(l_tmp[0]);
  if (absxk > 3.3121686421112381E-170) {
    deltaq_a = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    deltaq_a = t * t;
  }

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  absxk = fabs(l_tmp[1]);
  if (absxk > scale) {
    t = scale / absxk;
    deltaq_a = deltaq_a * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    deltaq_a += t * t;
  }

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  absxk = fabs(l_tmp[2]);
  if (absxk > scale) {
    t = scale / absxk;
    deltaq_a = deltaq_a * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    deltaq_a += t * t;
  }

  deltaq_a = scale * sqrt(deltaq_a);

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  isJamming = (deltaq_a * deltaq_a > obj->ExpectedMagneticFieldStrength *
               obj->ExpectedMagneticFieldStrength * 4.0);
  if (isJamming) {
    /* Start for MATLABSystem: '<S2700>/AHRS' */
    scale = gravityAccelGyroDiff[1];
    absxk = gravityAccelGyroDiff[0];
    t = gravityAccelGyroDiff[2];
    for (k = 0; k < 9; k++) {
      Rprior[k] = (H[k + 12] * scale + H[k] * absxk) + H[k + 24] * t;
    }

    deltaAng[0] = Rprior[0];
    gravityAccelGyroDiff[0] = Rprior[3];
    scale = Rprior[6];
    deltaAng[1] = Rprior[1];
    gravityAccelGyroDiff[1] = Rprior[4];
    absxk = Rprior[7];
    deltaAng[2] = Rprior[2];
    gravityAccelGyroDiff[2] = Rprior[5];
    t = Rprior[8];
  } else {
    for (k = 0; k < 12; k++) {
      /* Start for MATLABSystem: '<S2700>/AHRS' */
      scale = 0.0;
      for (aoffset = 0; aoffset < 6; aoffset++) {
        /* Start for MATLABSystem: '<S2700>/AHRS' */
        scale += H[12 * aoffset + k] * res[aoffset];
      }

      /* Start for MATLABSystem: '<S2700>/AHRS' */
      xe_post[k] = scale;
    }

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    deltaAng[0] = xe_post[0];
    gravityAccelGyroDiff[0] = xe_post[3];
    scale = xe_post[6];
    deltaAng[1] = xe_post[1];
    gravityAccelGyroDiff[1] = xe_post[4];
    absxk = xe_post[7];
    deltaAng[2] = xe_post[2];
    gravityAccelGyroDiff[2] = xe_post[5];
    t = xe_post[8];
  }

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  UAM_Fligh_quaternion_quaternion(deltaAng, &deltaq_a, &deltaq_b, &deltaq_c,
    &deltaq_d);
  tmp = ((pd * deltaq_a - pa * -deltaq_b) - invpd * -deltaq_c) - invpa *
    -deltaq_d;
  obj->pOrientPost.a = tmp;
  obj->pOrientPost.b = ((pd * -deltaq_b + pa * deltaq_a) + invpd * -deltaq_d) -
    invpa * -deltaq_c;
  obj->pOrientPost.c = ((pd * -deltaq_c - pa * -deltaq_d) + invpd * deltaq_a) +
    invpa * -deltaq_b;
  obj->pOrientPost.d = ((pd * -deltaq_d + pa * -deltaq_c) - invpd * -deltaq_b) +
    invpa * deltaq_a;
  if (tmp < 0.0) {
    obj->pOrientPost.a = -obj->pOrientPost.a;
    obj->pOrientPost.b = -obj->pOrientPost.b;
    obj->pOrientPost.c = -obj->pOrientPost.c;
    obj->pOrientPost.d = -obj->pOrientPost.d;
  }

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  pd = sqrt(((obj->pOrientPost.a * obj->pOrientPost.a + obj->pOrientPost.b *
              obj->pOrientPost.b) + obj->pOrientPost.c * obj->pOrientPost.c) +
            obj->pOrientPost.d * obj->pOrientPost.d);
  obj->pOrientPost.a /= pd;
  obj->pOrientPost.b /= pd;
  obj->pOrientPost.c /= pd;
  obj->pOrientPost.d /= pd;
  UAM_Fligh_quaternionBase_rotmat(obj->pOrientPost.a, obj->pOrientPost.b,
    obj->pOrientPost.c, obj->pOrientPost.d, Rprior);
  if (!isJamming) {
    /* Start for MATLABSystem: '<S2700>/AHRS' */
    deltaq_a = l_tmp[0];
    pd = l_tmp[1];
    pa = l_tmp[2];
    for (k = 0; k < 3; k++) {
      /* Start for MATLABSystem: '<S2700>/AHRS' */
      aoffset = k * 3 - 1;
      deltaAng[k] = (Rprior[aoffset + 1] * deltaq_a + Rprior[aoffset + 2] * pd)
        + Rprior[aoffset + 3] * pa;
    }

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    obj->pMagVec[0] -= deltaAng[0];
    obj->pMagVec[1] -= deltaAng[1];
    obj->pMagVec[2] -= deltaAng[2];
    pd = rt_atan2d_snf(obj->pMagVec[2], obj->pMagVec[0]);
    if (pd < -obj->pInclinationLimit) {
      pd = -1.5707963267948966;
    }

    if (pd > obj->pInclinationLimit) {
      pd = 1.5707963267948966;
    }

    obj->pMagVec[0] = 0.0;
    obj->pMagVec[1] = 0.0;
    obj->pMagVec[2] = 0.0;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    obj->pMagVec[0] = cos(pd);
    obj->pMagVec[2] = sin(pd);
    obj->pMagVec[0] *= obj->ExpectedMagneticFieldStrength;
    obj->pMagVec[1] *= obj->ExpectedMagneticFieldStrength;
    obj->pMagVec[2] *= obj->ExpectedMagneticFieldStrength;
  }

  for (k = 0; k < 12; k++) {
    for (aoffset = 0; aoffset < 12; aoffset++) {
      tmp = 0.0;
      for (b_idx = 0; b_idx < 6; b_idx++) {
        /* Start for MATLABSystem: '<S2700>/AHRS' */
        tmp += H[12 * b_idx + k] * K_tmp_0[6 * aoffset + b_idx];
      }

      /* Start for MATLABSystem: '<S2700>/AHRS' */
      b_idx = 12 * aoffset + k;
      Ppost[b_idx] = obj->pQw[b_idx] - tmp;
    }
  }

  memset(&obj->pQw[0], 0, 144U * sizeof(real_T));

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  pd = obj->pKalmanPeriod * obj->pKalmanPeriod;
  pa = obj->GyroscopeDriftNoise + obj->GyroscopeNoise;
  obj->pQw[0] = (Ppost[39] + pa) * pd + Ppost[0];
  obj->pQw[39] = Ppost[39] + obj->GyroscopeDriftNoise;
  obj->pQw[13] = (Ppost[52] + pa) * pd + Ppost[13];
  obj->pQw[52] = Ppost[52] + obj->GyroscopeDriftNoise;
  obj->pQw[26] = (Ppost[65] + pa) * pd + Ppost[26];
  obj->pQw[65] = Ppost[65] + obj->GyroscopeDriftNoise;
  deltaAng[0] = -obj->pKalmanPeriod * obj->pQw[39];
  deltaAng[1] = -obj->pKalmanPeriod * obj->pQw[52];
  deltaAng[2] = -obj->pKalmanPeriod * obj->pQw[65];
  pd = obj->LinearAccelerationDecayFactor * obj->LinearAccelerationDecayFactor;
  pa = obj->MagneticDisturbanceDecayFactor * obj->MagneticDisturbanceDecayFactor;
  obj->pFirstTime = false;
  varargout_1[0] = obj->pOrientPost.a;
  varargout_1[1] = obj->pOrientPost.b;
  varargout_1[2] = obj->pOrientPost.c;
  varargout_1[3] = obj->pOrientPost.d;
  obj->pQw[3] = deltaAng[0];
  obj->pQw[36] = deltaAng[0];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  obj->pQw[78] = pd * Ppost[78] + obj->LinearAccelerationNoise;
  obj->pQw[117] = pa * Ppost[117] + obj->MagneticDisturbanceNoise;
  obj->pGyroOffset[0] -= gravityAccelGyroDiff[0];
  obj->pLinAccelPost[0] = pLinAccelPostIn[0] - scale;
  varargout_2[0] = varargin_2[0] - accelMeasNoiseVar;
  obj->pQw[16] = deltaAng[1];
  obj->pQw[49] = deltaAng[1];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  obj->pQw[91] = pd * Ppost[91] + obj->LinearAccelerationNoise;
  obj->pQw[130] = pa * Ppost[130] + obj->MagneticDisturbanceNoise;
  obj->pGyroOffset[1] -= gravityAccelGyroDiff[1];
  obj->pLinAccelPost[1] = pLinAccelPostIn[1] - absxk;
  varargout_2[1] = varargin_2[1] - magMeasNoiseVar;
  obj->pQw[29] = deltaAng[2];
  obj->pQw[62] = deltaAng[2];

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  obj->pQw[104] = pd * Ppost[104] + obj->LinearAccelerationNoise;
  obj->pQw[143] = pa * Ppost[143] + obj->MagneticDisturbanceNoise;
  obj->pGyroOffset[2] -= gravityAccelGyroDiff[2];
  obj->pLinAccelPost[2] = pLinAccelPostIn[2] - t;
  varargout_2[2] = varargin_2[2] - pGyroOffsetIn_idx_2;
}

static void UAM_Fligh_PathManager_setupImpl(uav_sluav_internal_system_Pat_T *obj)
{
  int32_T c_j;

  /* Start for MATLABSystem: '<S2708>/PathManagerSystemObject' */
  obj->MissionStart = true;
  obj->MissionParams[0].mode = 0U;
  obj->MissionParams[1].mode = 1U;
  for (c_j = 0; c_j < 2; c_j++) {
    obj->MissionParams[c_j].position[0] = 0.0;
    obj->MissionParams[c_j].position[1] = 0.0;
    obj->MissionParams[c_j].position[2] = 0.0;
    obj->MissionParams[c_j].params[0] = 0.0;
    obj->MissionParams[c_j].params[1] = 0.0;
    obj->MissionParams[c_j].params[2] = 0.0;
    obj->MissionParams[c_j].params[3] = 0.0;
  }

  /* Start for MATLABSystem: '<S2708>/PathManagerSystemObject' */
  obj->PrevMissionPoint.mode = 0U;
  obj->PrevMissionPoint.position[0] = 0.0;
  obj->PrevMissionPoint.position[1] = 0.0;
  obj->PrevMissionPoint.position[2] = 0.0;
  obj->PrevMissionPoint.params[0] = 0.0;
  obj->HoldPose[0] = 0.0;
  obj->PrevMissionPoint.params[1] = 0.0;
  obj->HoldPose[1] = 0.0;
  obj->PrevMissionPoint.params[2] = 0.0;
  obj->HoldPose[2] = 0.0;
  obj->PrevMissionPoint.params[3] = 0.0;
  obj->HoldPose[3] = 0.0;
}

static void UAM_Fl_AHRSFilterBase_resetImpl(fusion_simulink_ahrsfilter_UA_T *obj)
{
  real_T accelMeasNoiseVar;
  real_T magMeasNoiseVar;
  int32_T i;
  int8_T b[9];
  static const real_T tmp_1[144] = { 6.0923483957341713E-6, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.0923483957341713E-6, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.0923483957341713E-6, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.6154354946677142E-5, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.6154354946677142E-5,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    7.6154354946677142E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0096236100000000012, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.6 };

  static const int8_T tmp_2[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  obj->pOrientPost.a = 1.0;
  obj->pOrientPost.b = 0.0;
  obj->pOrientPost.c = 0.0;
  obj->pOrientPost.d = 0.0;
  obj->pGyroOffset[0] = 0.0;
  obj->pMagVec[0] = 0.0;
  obj->pGyroOffset[1] = 0.0;
  obj->pMagVec[1] = 0.0;
  obj->pGyroOffset[2] = 0.0;
  obj->pMagVec[2] = 0.0;
  obj->pMagVec[0] = obj->ExpectedMagneticFieldStrength;

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  magMeasNoiseVar = obj->pKalmanPeriod * obj->pKalmanPeriod *
    (obj->GyroscopeDriftNoise + obj->GyroscopeNoise);
  accelMeasNoiseVar = (obj->AccelerometerNoise + obj->LinearAccelerationNoise) +
    magMeasNoiseVar;
  magMeasNoiseVar += obj->MagnetometerNoise + obj->MagneticDisturbanceNoise;
  for (i = 0; i < 9; i++) {
    b[i] = 0;
  }

  b[0] = 1;
  b[4] = 1;
  b[8] = 1;

  /* Start for MATLABSystem: '<S2700>/AHRS' */
  memset(&obj->pQv[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    int32_T tmp;
    int32_T tmp_0;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    obj->pQv[6 * i] = (real_T)b[3 * i] * accelMeasNoiseVar;
    tmp_0 = (i + 3) * 6;
    obj->pQv[tmp_0 + 3] = (real_T)tmp_2[3 * i] * magMeasNoiseVar;
    tmp = 3 * i + 1;
    obj->pQv[6 * i + 1] = (real_T)b[tmp] * accelMeasNoiseVar;
    obj->pQv[tmp_0 + 4] = (real_T)tmp_2[tmp] * magMeasNoiseVar;
    tmp = 3 * i + 2;
    obj->pQv[6 * i + 2] = (real_T)b[tmp] * accelMeasNoiseVar;
    obj->pQv[tmp_0 + 5] = (real_T)tmp_2[tmp] * magMeasNoiseVar;
  }

  memcpy(&obj->pQw[0], &tmp_1[0], 144U * sizeof(real_T));
  obj->pLinAccelPost[0] = 0.0;
  obj->pLinAccelPost[1] = 0.0;
  obj->pLinAccelPost[2] = 0.0;
  obj->pFirstTime = true;
  obj->pInclinationLimit = 1.5707963267948966;
}

/* Model step function for TID0 */
void UAM_Flight_control_step0(void)    /* Sample time: [0.001s, 0.0s] */
{
  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.001s, 0.0s] to Sample time: [0.005s, 0.0s]  */
  (UAM_Flight_control_M->Timing.RateInteraction.TID0_1)++;
  if ((UAM_Flight_control_M->Timing.RateInteraction.TID0_1) > 4) {
    UAM_Flight_control_M->Timing.RateInteraction.TID0_1 = 0;
  }

  /* RateTransition generated from: '<S2700>/Rate Transition1' incorporates:
   *  Constant: '<S2700>/Constant'
   *  Constant: '<S6>/Constant'
   *  Gain: '<S2709>/Gain1'
   */
  if (UAM_Flight_control_M->Timing.RateInteraction.TID0_1 == 1) {
    UAM_Flight_control_DW.RateTransition1_1_Buffer =
      UAM_Flight_control_P.Gain1_Gain_db * UAM_Flight_control_P.Constant_Value_h;
    UAM_Flight_control_DW.RateTransition1_13_Buffer =
      UAM_Flight_control_rtZRotorParameters;
    UAM_Flight_control_DW.RateTransition1_17_Buffer[0] =
      UAM_Flight_control_P.Constant_Value_gj[0];
    UAM_Flight_control_DW.RateTransition1_17_Buffer[1] =
      UAM_Flight_control_P.Constant_Value_gj[1];
    UAM_Flight_control_DW.RateTransition1_17_Buffer[2] =
      UAM_Flight_control_P.Constant_Value_gj[2];
  }

  /* End of RateTransition generated from: '<S2700>/Rate Transition1' */
}

/* Model step function for TID1 */
void UAM_Flight_control_step1(void)    /* Sample time: [0.005s, 0.0s] */
{
  GuidanceStates BusConversion_InsertedFor_Bas_n;
  real_T rtb_R[9];
  real_T rtb_dq[4];
  real_T tmp[4];
  real_T tmp_0[4];
  real_T rtb_Abb[3];
  real_T rtb_Gain1[3];
  real_T rtb_R_0[3];
  real_T rtb_TmpSignalConversionAtSFun_g[3];
  real_T rtb_pqr[3];
  real_T Integrator_d;
  real_T P_Pa;
  real_T rtb_Bias_l;
  real_T rtb_DeadZone_b;
  real_T rtb_DeadZone_hh;
  real_T rtb_DeadZone_o;
  real_T rtb_FilterCoefficient_f;
  real_T rtb_FilterCoefficient_l5;
  real_T rtb_Gain1_l;
  real_T rtb_IntegralGain_cj;
  real_T rtb_IntegralGain_no;
  real_T rtb_Integrator_o4;
  real_T rtb_Kvz;
  real_T rtb_Kvz_a;
  real_T rtb_Kz;
  real_T rtb_Kz_f;
  real_T rtb_Mag_idx_0;
  real_T rtb_Mag_idx_1;
  real_T rtb_Mag_idx_2;
  real_T rtb_Product_i5;
  real_T rtb_Pzv_n;
  real_T rtb_Pzz_n;
  real_T rtb_Saturation1_i;
  real_T rtb_Saturation_ny;
  real_T rtb_Saturation_o;
  real_T rtb_Sum24;
  real_T rtb_hover_est;
  real_T rtb_hover_est_l;
  real_T rtb_pzv;
  real_T rtb_pzz_n;
  real_T rtb_qout_idx_0;
  real_T rtb_qout_idx_1;
  real_T rtb_qout_idx_2;
  real_T rtb_qout_idx_3;
  real_T rtb_throttle;
  real_T s;
  int32_T i;
  int8_T rtAction;
  int8_T rtb_Sum_i;
  int8_T rtb_Sum_pf;
  int8_T tmp_1;
  uint8_T mode_prev;
  uint8_T rtb_Compare;
  boolean_T c[3];
  boolean_T rtb_Compare_j0[3];
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T rtb_Compare_e5;
  boolean_T rtb_Compare_ic;
  boolean_T rtb_Compare_j;
  boolean_T rtb_Compare_l;
  boolean_T rtb_Compare_mc;
  boolean_T rtb_IsNaN;
  boolean_T rtb_IsNaN1;
  boolean_T rtb_IsNaN2;
  boolean_T rtb_XYZ_Valid;
  FlightModeType rtb_mode;

  /* RelationalOperator: '<S2697>/Compare' incorporates:
   *  Constant: '<S2697>/Constant'
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Compare_ic = (UAM_Flight_control_U.fcc.rc[6] <
                    UAM_Flight_control_P.CompareToConstant_const_g);

  /* RelationalOperator: '<S2696>/Compare' incorporates:
   *  Constant: '<S2696>/Constant'
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Compare_j = (UAM_Flight_control_U.fcc.rc[6] >
                   UAM_Flight_control_P.CompareToConstant_const_b);

  /* Chart: '<S3>/Chart1' incorporates:
   *  Constant: '<S2693>/Constant'
   *  DataTypeConversion: '<S2693>/Data Type Conversion'
   */
  if (UAM_Flight_control_DW.is_active_c1_UAM_Flight_control == 0) {
    UAM_Flight_control_DW.is_active_c1_UAM_Flight_control = 1U;
    UAM_Flight_control_DW.is_c1_UAM_Flight_control =
      UAM_Flight_contr_IN_ManualState;
    rtb_mode = Manual;
  } else {
    switch (UAM_Flight_control_DW.is_c1_UAM_Flight_control) {
     case UAM_Flight_control_IN_AutoState:
      if (rtb_Compare_ic && (!(UAM_Flight_control_P.Constant_Value_jz != 0.0)))
      {
        UAM_Flight_control_DW.is_c1_UAM_Flight_control =
          UAM_Flight_contr_IN_ManualState;
        rtb_mode = Manual;
      } else if (UAM_Flight_control_P.Constant_Value_jz != 0.0) {
        UAM_Flight_control_DW.is_c1_UAM_Flight_control =
          UAM_Flight_co_IN_EmergecnyState;
        rtb_mode = Emergecny;
      } else {
        rtb_mode = Auto;
      }
      break;

     case UAM_Flight_co_IN_EmergecnyState:
      if (rtb_Compare_ic && (!(UAM_Flight_control_P.Constant_Value_jz != 0.0)))
      {
        UAM_Flight_control_DW.is_c1_UAM_Flight_control =
          UAM_Flight_contr_IN_ManualState;
        rtb_mode = Manual;
      } else if (rtb_Compare_j && (!(UAM_Flight_control_P.Constant_Value_jz !=
                   0.0))) {
        UAM_Flight_control_DW.is_c1_UAM_Flight_control =
          UAM_Flight_control_IN_AutoState;
        rtb_mode = Auto;
      } else {
        rtb_mode = Emergecny;
      }
      break;

     default:
      /* case IN_ManualState: */
      if (rtb_Compare_j && (!(UAM_Flight_control_P.Constant_Value_jz != 0.0)) &&
          (!rtb_Compare_ic)) {
        UAM_Flight_control_DW.is_c1_UAM_Flight_control =
          UAM_Flight_control_IN_AutoState;
        rtb_mode = Auto;
      } else if (UAM_Flight_control_P.Constant_Value_jz != 0.0) {
        UAM_Flight_control_DW.is_c1_UAM_Flight_control =
          UAM_Flight_co_IN_EmergecnyState;
        rtb_mode = Emergecny;
      } else {
        rtb_mode = Manual;
      }
      break;
    }
  }

  /* End of Chart: '<S3>/Chart1' */

  /* Gain: '<S2714>/Gain1' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Gain1[0] = UAM_Flight_control_P.Gain1_Gain_n *
    UAM_Flight_control_U.fcc.yaw;
  rtb_Gain1[1] = UAM_Flight_control_P.Gain1_Gain_n *
    UAM_Flight_control_U.fcc.pitch;
  rtb_Gain1[2] = UAM_Flight_control_P.Gain1_Gain_n *
    UAM_Flight_control_U.fcc.roll;

  /* Math: '<S2700>/Transpose8' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Abb[0] = UAM_Flight_control_U.fcc.acc_x;

  /* Math: '<S2700>/Transpose9' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_pqr[0] = UAM_Flight_control_U.fcc.gyro_x;

  /* Math: '<S2700>/Transpose8' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Abb[1] = UAM_Flight_control_U.fcc.acc_y;

  /* Math: '<S2700>/Transpose9' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_pqr[1] = UAM_Flight_control_U.fcc.gyro_y;

  /* Math: '<S2700>/Transpose8' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Abb[2] = UAM_Flight_control_U.fcc.acc_z;

  /* Math: '<S2700>/Transpose9' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_pqr[2] = UAM_Flight_control_U.fcc.gyro_z;

  /* MATLAB Function: '<S6>/MATLAB Function3' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Ts'
   *  UnitDelay: '<S6>/Unit Delay2'
   *  UnitDelay: '<S6>/Unit Delay3'
   *  UnitDelay: '<S6>/Unit Delay4'
   */
  rtb_Pzz_n = ((2.0 * UAM_Flight_control_P.Ts_Value *
                UAM_Flight_control_DW.UnitDelay3_DSTATE +
                UAM_Flight_control_DW.UnitDelay2_DSTATE) +
               UAM_Flight_control_P.Ts_Value * UAM_Flight_control_P.Ts_Value *
               UAM_Flight_control_DW.UnitDelay4_DSTATE) +
    UAM_Flight_control_P.Constant1_Value_fay;
  rtb_Pzv_n = UAM_Flight_control_P.Ts_Value *
    UAM_Flight_control_DW.UnitDelay4_DSTATE +
    UAM_Flight_control_DW.UnitDelay3_DSTATE;

  /* Sum: '<S6>/Sum6' incorporates:
   *  Constant: '<S6>/R_baro'
   */
  rtb_Kvz_a = rtb_Pzz_n + UAM_Flight_control_P.R_baro_Value;

  /* Product: '<S6>/Divide' */
  rtb_Kz = rtb_Pzz_n / rtb_Kvz_a;

  /* Sum: '<S6>/Sum9' incorporates:
   *  Constant: '<S6>/Constant4'
   */
  rtb_Sum24 = UAM_Flight_control_P.Constant4_Value_g - rtb_Kz;

  /* Product: '<S6>/Product3' */
  rtb_pzz_n = rtb_Pzv_n * rtb_Sum24;

  /* Product: '<S6>/Divide1' */
  rtb_Kvz_a = rtb_Pzv_n / rtb_Kvz_a;

  /* Sum: '<S6>/Sum10' incorporates:
   *  Constant: '<S6>/Constant2'
   *  MATLAB Function: '<S6>/MATLAB Function3'
   *  Product: '<S6>/Product4'
   *  UnitDelay: '<S6>/Unit Delay4'
   */
  rtb_Pzv_n = (UAM_Flight_control_DW.UnitDelay4_DSTATE +
               UAM_Flight_control_P.Constant2_Value_c) - rtb_Pzv_n * rtb_Kvz_a;

  /* Sum: '<S6>/Sum12' incorporates:
   *  Constant: '<S6>/R_vgps'
   */
  rtb_Kz_f = UAM_Flight_control_P.R_vgps_Value + rtb_Pzv_n;

  /* Product: '<S6>/Divide3' */
  rtb_Kvz = rtb_Pzv_n / rtb_Kz_f;

  /* Sum: '<S6>/Sum16' incorporates:
   *  Product: '<S6>/Product8'
   */
  rtb_pzv = rtb_pzz_n - rtb_pzz_n * rtb_Kvz;

  /* Product: '<S6>/Divide2' */
  rtb_Kz_f = rtb_pzz_n / rtb_Kz_f;

  /* Sum: '<S6>/Sum17' incorporates:
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product7'
   */
  rtb_pzz_n = rtb_Pzz_n * rtb_Sum24 - rtb_pzz_n * rtb_Kz_f;

  /* Sum: '<S6>/Sum21' incorporates:
   *  Constant: '<S6>/Rgps'
   */
  rtb_Sum24 = rtb_pzz_n + UAM_Flight_control_P.Rgps_Value;

  /* Product: '<S6>/Divide4' */
  rtb_Pzz_n = rtb_pzv / rtb_Sum24;

  /* MATLAB Function: '<S6>/MATLAB Function4' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Compare_ic = ((!rtIsInf(UAM_Flight_control_U.fcc.altitude)) && (!rtIsNaN
    (UAM_Flight_control_U.fcc.altitude)) && (fabs
    (UAM_Flight_control_U.fcc.altitude) > 1.0));
  if ((!UAM_Flight_control_DW.ref_set) && rtb_Compare_ic) {
    UAM_Flight_control_DW.h_ref = UAM_Flight_control_U.fcc.altitude;
    UAM_Flight_control_DW.ref_set = true;
  }

  if (UAM_Flight_control_DW.ref_set && rtb_Compare_ic) {
    UAM_Flight_control_DW.last_z = -(UAM_Flight_control_U.fcc.altitude -
      UAM_Flight_control_DW.h_ref);
  }

  /* RelationalOperator: '<S2712>/Compare' incorporates:
   *  Constant: '<S2712>/Constant'
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Compare_ic = (UAM_Flight_control_U.fcc.rc[5] >
                    UAM_Flight_control_P.CompareToConstant_const_d);

  /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Inport: '<Root>/fcc'
   *  MATLAB Function: '<S6>/MATLAB Function2'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  P_Pa = UAM_Flight_control_U.fcc.pressure * 1000.0;
  if ((UAM_Flight_control_DW.last_arm == 0) && rtb_Compare_ic) {
    if ((!rtIsInf(P_Pa)) && (!rtIsNaN(P_Pa)) && (P_Pa > 0.0)) {
      UAM_Flight_control_DW.p0_Pa = P_Pa;
      UAM_Flight_control_DW.p0_set = true;
    } else {
      UAM_Flight_control_DW.p0_Pa = 0.0;
      UAM_Flight_control_DW.p0_set = false;
    }
  }

  if ((UAM_Flight_control_DW.last_arm == 1) && (!rtb_Compare_ic)) {
    UAM_Flight_control_DW.p0_set = false;
    UAM_Flight_control_DW.p0_Pa = 0.0;
  }

  UAM_Flight_control_DW.last_arm = rtb_Compare_ic;

  /* MATLAB Function: '<S6>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S6>/MATLAB Function'
   */
  if ((!UAM_Flight_control_DW.p0_set) || (UAM_Flight_control_DW.p0_Pa <= 0.0)) {
    P_Pa = 0.0;
  } else {
    P_Pa = -((1.0 - rt_powd_snf(P_Pa / UAM_Flight_control_DW.p0_Pa, 0.1903)) *
             44330.0);
  }

  /* Sum: '<S6>/Sum19' incorporates:
   *  Gain: '<S6>/Gain2'
   *  Sum: '<S6>/Sum18'
   *  UnitDelay: '<S6>/Unit Delay5'
   */
  UAM_Flight_control_DW.UnitDelay5_DSTATE += (P_Pa -
    UAM_Flight_control_DW.UnitDelay5_DSTATE) * UAM_Flight_control_P.Gain2_Gain_k;

  /* Gain: '<S2721>/dt' incorporates:
   *  Constant: '<S2721>/Gyro_bias'
   *  Gain: '<S2721>/Gain2'
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   *  Sum: '<S2721>/Sum'
   */
  rtb_Mag_idx_0 = (UAM_Flight_control_U.fcc.gyro_x -
                   UAM_Flight_control_P.Gyro_bias_Value[0]) *
    UAM_Flight_control_P.Gain2_Gain_e * UAM_Flight_control_P.dt_Gain;
  rtb_Mag_idx_1 = (UAM_Flight_control_U.fcc.gyro_y -
                   UAM_Flight_control_P.Gyro_bias_Value[1]) *
    UAM_Flight_control_P.Gain2_Gain_e * UAM_Flight_control_P.dt_Gain;
  rtb_Mag_idx_2 = (UAM_Flight_control_U.fcc.gyro_z -
                   UAM_Flight_control_P.Gyro_bias_Value[2]) *
    UAM_Flight_control_P.Gain2_Gain_e * UAM_Flight_control_P.dt_Gain;

  /* Saturate: '<S1187>/Saturation' incorporates:
   *  MATLAB Function: '<S2721>/MATLAB Function1'
   */
  UAM_Flight_control_B.a = sqrt((rtb_Mag_idx_0 * rtb_Mag_idx_0 + rtb_Mag_idx_1 *
    rtb_Mag_idx_1) + rtb_Mag_idx_2 * rtb_Mag_idx_2);

  /* MATLAB Function: '<S2721>/MATLAB Function1' */
  if (UAM_Flight_control_B.a < 1.0E-8) {
    rtb_dq[0] = 1.0;
    rtb_dq[1] = rtb_Mag_idx_0;
    rtb_dq[2] = rtb_Mag_idx_1;
    rtb_dq[3] = rtb_Mag_idx_2;
  } else {
    s = sin(UAM_Flight_control_B.a) / UAM_Flight_control_B.a;
    rtb_dq[0] = cos(UAM_Flight_control_B.a);
    rtb_dq[1] = rtb_Mag_idx_0 * s;
    rtb_dq[2] = rtb_Mag_idx_1 * s;
    rtb_dq[3] = rtb_Mag_idx_2 * s;
  }

  /* MATLAB Function: '<S2721>/MATLAB Function2' incorporates:
   *  UnitDelay: '<S2721>/Unit Delay'
   */
  rtb_qout_idx_0 = ((UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] * rtb_dq[0] -
                     UAM_Flight_control_DW.UnitDelay_DSTATE_m[1] * rtb_dq[1]) -
                    UAM_Flight_control_DW.UnitDelay_DSTATE_m[2] * rtb_dq[2]) -
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[3] * rtb_dq[3];
  rtb_qout_idx_1 = ((UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] * rtb_dq[1] +
                     rtb_dq[0] * UAM_Flight_control_DW.UnitDelay_DSTATE_m[1]) +
                    UAM_Flight_control_DW.UnitDelay_DSTATE_m[2] * rtb_dq[3]) -
    rtb_dq[2] * UAM_Flight_control_DW.UnitDelay_DSTATE_m[3];
  rtb_qout_idx_2 = ((UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] * rtb_dq[2] -
                     UAM_Flight_control_DW.UnitDelay_DSTATE_m[1] * rtb_dq[3]) +
                    rtb_dq[0] * UAM_Flight_control_DW.UnitDelay_DSTATE_m[2]) +
    rtb_dq[1] * UAM_Flight_control_DW.UnitDelay_DSTATE_m[3];
  rtb_qout_idx_3 = ((UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] * rtb_dq[3] +
                     UAM_Flight_control_DW.UnitDelay_DSTATE_m[1] * rtb_dq[2]) -
                    rtb_dq[1] * UAM_Flight_control_DW.UnitDelay_DSTATE_m[2]) +
    rtb_dq[0] * UAM_Flight_control_DW.UnitDelay_DSTATE_m[3];

  /* MATLAB Function: '<S2721>/normalize' incorporates:
   *  UnitDelay: '<S2721>/Unit Delay'
   */
  rtb_Mag_idx_0 = sqrt(((rtb_qout_idx_0 * rtb_qout_idx_0 + rtb_qout_idx_1 *
    rtb_qout_idx_1) + rtb_qout_idx_2 * rtb_qout_idx_2) + rtb_qout_idx_3 *
                       rtb_qout_idx_3);
  if (rtb_Mag_idx_0 > 0.0) {
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] = rtb_qout_idx_0 / rtb_Mag_idx_0;
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[1] = rtb_qout_idx_1 / rtb_Mag_idx_0;
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[2] = rtb_qout_idx_2 / rtb_Mag_idx_0;
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[3] = rtb_qout_idx_3 / rtb_Mag_idx_0;
  } else {
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] = 1.0;
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[1] = 0.0;
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[2] = 0.0;
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[3] = 0.0;
  }

  /* End of MATLAB Function: '<S2721>/normalize' */

  /* MATLAB Function: '<S6>/MATLAB Function1' incorporates:
   *  UnitDelay: '<S2721>/Unit Delay'
   */
  rtb_Mag_idx_2 = UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[0];
  s = UAM_Flight_control_DW.UnitDelay_DSTATE_m[1] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[1];
  rtb_Mag_idx_0 = UAM_Flight_control_DW.UnitDelay_DSTATE_m[2] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[2];
  rtb_Mag_idx_1 = UAM_Flight_control_DW.UnitDelay_DSTATE_m[3] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[3];
  rtb_R[0] = ((rtb_Mag_idx_2 + s) - rtb_Mag_idx_0) - rtb_Mag_idx_1;
  rtb_Bias_l = UAM_Flight_control_DW.UnitDelay_DSTATE_m[1] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[2];
  rtb_qout_idx_0 = UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[3];
  rtb_R[3] = (rtb_Bias_l - rtb_qout_idx_0) * 2.0;
  rtb_qout_idx_1 = UAM_Flight_control_DW.UnitDelay_DSTATE_m[1] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[3];
  rtb_qout_idx_2 = UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[2];
  rtb_R[6] = (rtb_qout_idx_1 + rtb_qout_idx_2) * 2.0;
  rtb_R[1] = (rtb_Bias_l + rtb_qout_idx_0) * 2.0;
  rtb_Mag_idx_2 -= s;
  rtb_R[4] = (rtb_Mag_idx_2 + rtb_Mag_idx_0) - rtb_Mag_idx_1;
  rtb_Bias_l = UAM_Flight_control_DW.UnitDelay_DSTATE_m[2] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[3];
  rtb_qout_idx_0 = UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] *
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[1];
  rtb_R[7] = (rtb_Bias_l - rtb_qout_idx_0) * 2.0;
  rtb_R[2] = (rtb_qout_idx_1 - rtb_qout_idx_2) * 2.0;
  rtb_R[5] = (rtb_Bias_l + rtb_qout_idx_0) * 2.0;
  rtb_R[8] = (rtb_Mag_idx_2 - rtb_Mag_idx_0) + rtb_Mag_idx_1;

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/bias'
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Mag_idx_0 = UAM_Flight_control_U.fcc.acc_x -
    UAM_Flight_control_P.bias_Value[0];
  rtb_Mag_idx_1 = UAM_Flight_control_U.fcc.acc_y -
    UAM_Flight_control_P.bias_Value[1];
  rtb_Mag_idx_2 = UAM_Flight_control_U.fcc.acc_z -
    UAM_Flight_control_P.bias_Value[2];

  /* Product: '<S6>/Matrix Multiply1' */
  for (i = 0; i < 3; i++) {
    rtb_R_0[i] = (rtb_R[i + 3] * rtb_Mag_idx_1 + rtb_R[i] * rtb_Mag_idx_0) +
      rtb_R[i + 6] * rtb_Mag_idx_2;
  }

  /* End of Product: '<S6>/Matrix Multiply1' */

  /* Sum: '<S6>/Sum1' incorporates:
   *  Constant: '<S6>/g'
   */
  rtb_Mag_idx_2 = rtb_R_0[2] + UAM_Flight_control_P.g_Value;

  /* Sum: '<S6>/Sum4' incorporates:
   *  Gain: '<S6>/0.5*dt^2'
   *  Gain: '<S6>/dt1'
   *  Sum: '<S6>/Sum3'
   *  UnitDelay: '<S6>/Unit Delay'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  rtb_Mag_idx_0 = (UAM_Flight_control_P.dt1_Gain *
                   UAM_Flight_control_DW.UnitDelay_DSTATE +
                   UAM_Flight_control_DW.UnitDelay1_DSTATE) +
    UAM_Flight_control_P.u5dt2_Gain * rtb_Mag_idx_2;

  /* Sum: '<S6>/Sum5' incorporates:
   *  UnitDelay: '<S6>/Unit Delay5'
   */
  rtb_Mag_idx_1 = UAM_Flight_control_DW.UnitDelay5_DSTATE - rtb_Mag_idx_0;

  /* Switch: '<S6>/Switch' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S2713>/Constant'
   *  Constant: '<S6>/Constant5'
   *  RelationalOperator: '<S2713>/Compare'
   */
  if (fabs(rtb_Mag_idx_1) > UAM_Flight_control_P.CompareToConstant1_const_i) {
    rtb_Mag_idx_1 = UAM_Flight_control_P.Constant5_Value_h;
  }

  /* End of Switch: '<S6>/Switch' */

  /* Sum: '<S6>/Sum8' incorporates:
   *  Gain: '<S6>/dt'
   *  Product: '<S6>/Product1'
   *  Sum: '<S6>/Sum2'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  rtb_Kvz_a = (UAM_Flight_control_P.dt_Gain_g * rtb_Mag_idx_2 +
               UAM_Flight_control_DW.UnitDelay_DSTATE) + rtb_Kvz_a *
    rtb_Mag_idx_1;

  /* Sum: '<S6>/Sum11' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_Mag_idx_2 = UAM_Flight_control_U.fcc.vel_d - rtb_Kvz_a;

  /* Sum: '<S6>/Sum13' incorporates:
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product5'
   *  Sum: '<S6>/Sum7'
   */
  rtb_Mag_idx_1 = (rtb_Kz * rtb_Mag_idx_1 + rtb_Mag_idx_0) + rtb_Kz_f *
    rtb_Mag_idx_2;

  /* Sum: '<S6>/Sum20' incorporates:
   *  MATLAB Function: '<S6>/MATLAB Function4'
   */
  rtb_Mag_idx_0 = UAM_Flight_control_DW.last_z - rtb_Mag_idx_1;

  /* Sum: '<S6>/Sum23' incorporates:
   *  Product: '<S6>/Product10'
   *  Product: '<S6>/Product6'
   *  Sum: '<S6>/Sum14'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  UAM_Flight_control_DW.UnitDelay_DSTATE = (rtb_Kvz * rtb_Mag_idx_2 + rtb_Kvz_a)
    + rtb_Pzz_n * rtb_Mag_idx_0;

  /* Math: '<S2700>/Transpose4' incorporates:
   *  Gain: '<S2700>/Gain'
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   *  SignalConversion generated from: '<S2700>/Transpose11'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  rtb_Kz = UAM_Flight_control_P.Gain_Gain_iq * UAM_Flight_control_U.fcc.vel_n;
  rtb_Kz_f = UAM_Flight_control_P.Gain_Gain_iq * UAM_Flight_control_U.fcc.vel_e;
  rtb_Kvz_a = UAM_Flight_control_P.Gain_Gain_iq *
    UAM_Flight_control_DW.UnitDelay_DSTATE;

  /* Product: '<S6>/Divide5' */
  rtb_Sum24 = rtb_pzz_n / rtb_Sum24;

  /* Sum: '<S6>/Sum22' incorporates:
   *  Product: '<S6>/Product11'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  UAM_Flight_control_DW.UnitDelay1_DSTATE = rtb_Sum24 * rtb_Mag_idx_0 +
    rtb_Mag_idx_1;

  /* SignalConversion generated from: '<S2711>/ SFunction ' incorporates:
   *  Inport: '<Root>/fcc'
   *  MATLAB Function: '<S2710>/MATLAB Function'
   *  SignalConversion generated from: '<Root>/fcc'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  rtb_TmpSignalConversionAtSFun_g[0] = UAM_Flight_control_U.fcc.latitude;
  rtb_TmpSignalConversionAtSFun_g[1] = UAM_Flight_control_U.fcc.longitude;
  rtb_TmpSignalConversionAtSFun_g[2] = UAM_Flight_control_DW.UnitDelay1_DSTATE;

  /* MATLAB Function: '<S2710>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   *  SignalConversion generated from: '<S2711>/ SFunction '
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  if ((UAM_Flight_control_DW.prevArming == 0.0) && rtb_Compare_ic) {
    rtb_Compare_j0[0] = !rtIsInf(UAM_Flight_control_U.fcc.latitude);
    c[0] = !rtIsNaN(UAM_Flight_control_U.fcc.latitude);
    rtb_Compare_j0[1] = !rtIsInf(UAM_Flight_control_U.fcc.longitude);
    c[1] = !rtIsNaN(UAM_Flight_control_U.fcc.longitude);
    rtb_Compare_j0[2] = !rtIsInf(UAM_Flight_control_DW.UnitDelay1_DSTATE);
    c[2] = !rtIsNaN(UAM_Flight_control_DW.UnitDelay1_DSTATE);
    rtb_Compare_j = true;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i < 3)) {
      if ((!rtb_Compare_j0[i]) || (!c[i])) {
        rtb_Compare_j = false;
        exitg1 = true;
      } else {
        i++;
      }
    }

    if (rtb_Compare_j) {
      rtb_Compare_j = false;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i < 3)) {
        if (rtb_TmpSignalConversionAtSFun_g[i] != 0.0) {
          rtb_Compare_j = true;
          exitg1 = true;
        } else {
          i++;
        }
      }

      if (rtb_Compare_j) {
        UAM_Flight_control_DW.homeLLA[0] = UAM_Flight_control_U.fcc.latitude;
        UAM_Flight_control_DW.homeLLA[1] = UAM_Flight_control_U.fcc.longitude;
        UAM_Flight_control_DW.homeLLA[2] =
          UAM_Flight_control_DW.UnitDelay1_DSTATE;
        UAM_Flight_control_DW.isSet = true;
      }
    }
  }

  if (!UAM_Flight_control_DW.isSet) {
    rtb_Mag_idx_0 = 0.0;
    rtb_Mag_idx_1 = 0.0;
    rtb_Mag_idx_2 = 0.0;
    UAM_Flight_control_DW.prevArming = rtb_Compare_ic;
  } else {
    rtb_Mag_idx_1 = 0.017453292519943295 * UAM_Flight_control_DW.homeLLA[0];
    rtb_Mag_idx_0 = sin(rtb_Mag_idx_1);
    rtb_Mag_idx_0 = 1.0 - 0.0066943799901413165 * rtb_Mag_idx_0 * rtb_Mag_idx_0;
    rtb_Mag_idx_2 = 6.378137E+6 / sqrt(rtb_Mag_idx_0);
    rtb_Mag_idx_0 = rtb_Mag_idx_2 * 0.99330562000985867 / rtb_Mag_idx_0 *
      ((UAM_Flight_control_U.fcc.latitude - UAM_Flight_control_DW.homeLLA[0]) *
       0.017453292519943295);
    rtb_Mag_idx_1 = (UAM_Flight_control_U.fcc.longitude -
                     UAM_Flight_control_DW.homeLLA[1]) * 0.017453292519943295 *
      (rtb_Mag_idx_2 * cos(rtb_Mag_idx_1));
    rtb_Mag_idx_2 = UAM_Flight_control_DW.UnitDelay1_DSTATE;
    UAM_Flight_control_DW.prevArming = rtb_Compare_ic;
  }

  /* SwitchCase: '<S2>/Switch Case' */
  switch (rtb_mode) {
   case Manual:
    rtAction = 0;
    break;

   case Auto:
    rtAction = 1;
    break;

   default:
    rtAction = 2;
    break;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S2>/Manual' incorporates:
     *  ActionPort: '<S2669>/Action Port'
     */
    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2669>/Unit Delay'
     */
    UAM_Flight_control_B.X = UAM_Flight_control_DW.UnitDelay_1_DSTATE_f;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2669>/Unit Delay'
     */
    UAM_Flight_control_B.Y = UAM_Flight_control_DW.UnitDelay_2_DSTATE_gq;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2669>/Unit Delay'
     */
    UAM_Flight_control_B.Z = UAM_Flight_control_DW.UnitDelay_3_DSTATE_o;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2669>/Unit Delay'
     */
    UAM_Flight_control_B.Yaw = UAM_Flight_control_DW.UnitDelay_4_DSTATE_a;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2669>/Unit Delay'
     */
    UAM_Flight_control_B.FixedWingSP =
      UAM_Flight_control_DW.UnitDelay_5_DSTATE_h;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2669>/Unit Delay'
     */
    UAM_Flight_control_B.AACSP = UAM_Flight_control_DW.UnitDelay_6_DSTATE_b;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2669>/Unit Delay'
     */
    UAM_Flight_control_B.controlMode_h =
      UAM_Flight_control_DW.UnitDelay_7_DSTATE_b;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2669>/Unit Delay'
     */
    UAM_Flight_control_B.FlightMode = UAM_Flight_control_DW.UnitDelay_8_DSTATE_p;

    /* BusCreator generated from: '<S2669>/Basic Control  Switching' incorporates:
     *  UnitDelay generated from: '<S2>/Unit Delay1'
     */
    BusConversion_InsertedFor_Bas_n.Euler[0] =
      UAM_Flight_control_DW.UnitDelay1_2_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.pqr[0] =
      UAM_Flight_control_DW.UnitDelay1_3_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.Ve[0] =
      UAM_Flight_control_DW.UnitDelay1_4_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.Xe[0] =
      UAM_Flight_control_DW.UnitDelay1_5_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.Euler[1] =
      UAM_Flight_control_DW.UnitDelay1_2_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.pqr[1] =
      UAM_Flight_control_DW.UnitDelay1_3_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.Ve[1] =
      UAM_Flight_control_DW.UnitDelay1_4_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.Xe[1] =
      UAM_Flight_control_DW.UnitDelay1_5_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.Euler[2] =
      UAM_Flight_control_DW.UnitDelay1_2_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.pqr[2] =
      UAM_Flight_control_DW.UnitDelay1_3_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.Ve[2] =
      UAM_Flight_control_DW.UnitDelay1_4_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.Xe[2] =
      UAM_Flight_control_DW.UnitDelay1_5_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.course =
      UAM_Flight_control_DW.UnitDelay1_6_DSTATE;
    BusConversion_InsertedFor_Bas_n.RotorParameters =
      UAM_Flight_control_DW.UnitDelay1_7_DSTATE;
    memcpy(&BusConversion_InsertedFor_Bas_n.RC[0],
           &UAM_Flight_control_DW.UnitDelay1_8_DSTATE[0], 10U * sizeof(real_T));
    BusConversion_InsertedFor_Bas_n.target[0] =
      UAM_Flight_control_DW.UnitDelay1_9_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.target[1] =
      UAM_Flight_control_DW.UnitDelay1_9_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.target[2] =
      UAM_Flight_control_DW.UnitDelay1_9_DSTATE[2];

    /* Chart: '<S2669>/Basic Control  Switching' incorporates:
     *  BusCreator generated from: '<S2669>/Basic Control  Switching'
     *  Constant: '<S2669>/Hover'
     *  UnitDelay generated from: '<S2>/Unit Delay1'
     *  UnitDelay: '<S2>/Unit Delay2'
     */
    if (UAM_Flight_control_DW.is_active_c12_UAM_Flight_contro == 0) {
      UAM_Flight_control_DW.is_active_c12_UAM_Flight_contro = 1U;
      UAM_Flight_control_DW.is_STATE_MACHINE_f = UAM_Flight_control_IN_Start;
      UAM_Flight_control_B.flightMode_c = UAM_Flight_control_P.FSState;
      UAM_Flight_control_B.controlMode_l.lateralGuidance = 0U;
      UAM_Flight_control_B.controlMode_l.airspeedAltitude = 0U;
      UAM_Flight_control_B.controlMode_l.attitude = 0U;
      UAM_Flight_control_B.controlMode_l.manual = 1U;
      UAM_Flight_control_B.controlMode_l.armed = 0U;
      UAM_Flight_control_B.controlMode_l.inTransition = 0U;
      UAM_Flight_control_B.controlMode_l.TransitionCondition = 0U;
      UAM_Flight_control_B.controlMode_l.BackTransitionCondition = 0U;
    } else {
      switch (UAM_Flight_control_DW.is_STATE_MACHINE_f) {
       case UAM_Flight_control_IN_Althold:
        if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] < 1300.0) &&
            (UAM_Flight_control_B.flightMode_c == Hover)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_control_IN_Stablized;
          UAM_Flight_control_B.flightMode_c = Hover;
          UAM_Flight_control_B.HoverSPBUS.X = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Y = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Z = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Yaw = (rtNaN);
        } else if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] >= 1700.0) &&
                   (UAM_Flight_control_B.flightMode_c == Hover)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_control_IN_Loiter;
          UAM_Flight_control_B.flightMode_c = Hover;
          UAM_Flight_control_B.HoverSPBUS.X =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
          UAM_Flight_control_B.HoverSPBUS.Y =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
          UAM_Flight_control_B.HoverSPBUS.Z =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
          UAM_Flight_control_B.HoverSPBUS.Yaw = (rtNaN);
        }
        break;

       case UAM_Flight_co_IN_BackTransition:
        if (UAM_Flight_con_backConditionMet
            (UAM_Flight_control_DW.UnitDelay2_DSTATE_l,
             &BusConversion_InsertedFor_Bas_n)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_contro_IN_HVCOMPLETE;
          UAM_Flight_control_B.controlMode_l.inTransition = 0U;
          UAM_Flight_control_B.controlMode_l.BackTransitionCondition = 1U;
          UAM_Flight_control_B.flightMode_c = Hover;
        }
        break;

       case UAM_Flight_contro_IN_FWCOMPLETE:
       case UAM_Flight_contro_IN_HVCOMPLETE:
        break;

       case UAM_Flight_control_IN_FixedWing:
        if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[6] < 15000.0) &&
            (UAM_Flight_control_B.flightMode_c == FixedWing)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_co_IN_BackTransition;
          UAM_Flight_control_B.flightMode_c = BackTransition;
          UAM_Flight_control_B.controlMode_l.inTransition = 1U;
          UAM_Flight_control_B.controlMode_l.BackTransitionCondition = 0U;
        }
        break;

       case UAM_Flight_control_IN_Loiter:
        if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] >= 1300.0) &&
            ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] < 1700.0) &&
             (UAM_Flight_control_B.flightMode_c == Hover))) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_control_IN_Althold;
          UAM_Flight_control_B.flightMode_c = Hover;
          UAM_Flight_control_B.HoverSPBUS.X = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Y = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Z =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
          UAM_Flight_control_B.HoverSPBUS.Yaw = (rtNaN);
        } else if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] < 1300.0) &&
                   (UAM_Flight_control_B.flightMode_c == Hover)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_control_IN_Stablized;
          UAM_Flight_control_B.flightMode_c = Hover;
          UAM_Flight_control_B.HoverSPBUS.X = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Y = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Z = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Yaw = (rtNaN);
        }
        break;

       case UAM_Flight_control_IN_Stablized:
        if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] >= 1300.0) &&
            ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] < 1700.0) &&
             (UAM_Flight_control_B.flightMode_c == Hover))) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_control_IN_Althold;
          UAM_Flight_control_B.flightMode_c = Hover;
          UAM_Flight_control_B.HoverSPBUS.X = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Y = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Z =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
          UAM_Flight_control_B.HoverSPBUS.Yaw = (rtNaN);
        } else if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] > 1700.0) &&
                   (UAM_Flight_control_B.flightMode_c == Hover)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_control_IN_Loiter;
          UAM_Flight_control_B.flightMode_c = Hover;
          UAM_Flight_control_B.HoverSPBUS.X =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0];
          UAM_Flight_control_B.HoverSPBUS.Y =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1];
          UAM_Flight_control_B.HoverSPBUS.Z =
            UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2];
          UAM_Flight_control_B.HoverSPBUS.Yaw = (rtNaN);
        } else if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[6] >= 1500.0) &&
                   (UAM_Flight_control_B.flightMode_c == Hover)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_contro_IN_Transition;
          UAM_Flight_control_B.flightMode_c = Transition;
          UAM_Flight_control_B.controlMode_l.inTransition = 1U;
          UAM_Flight_control_B.controlMode_l.TransitionCondition = 0U;
        }
        break;

       case UAM_Flight_control_IN_Start:
        if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[6] < 1500.0) &&
            (UAM_Flight_control_B.flightMode_c == Hover)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_control_IN_Stablized;
          UAM_Flight_control_B.flightMode_c = Hover;
          UAM_Flight_control_B.HoverSPBUS.X = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Y = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Z = (rtNaN);
          UAM_Flight_control_B.HoverSPBUS.Yaw = (rtNaN);
        } else if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[6] >= 1500.0) &&
                   (UAM_Flight_control_B.flightMode_c == FixedWing)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_control_IN_FixedWing;
          UAM_Flight_control_B.flightMode_c = FixedWing;
          UAM_Flight_control_B.controlMode_l.attitude = 1U;
          UAM_Flight_control_B.controlMode_l.inTransition = 0U;
          UAM_Flight_control_B.controlMode_l.TransitionCondition = 1U;
        }
        break;

       default:
        /* case IN_Transition: */
        if (UAM_Flig_transitionConditionMet
            (UAM_Flight_control_DW.UnitDelay2_DSTATE_l, UAM_Flight_control_P.Vt,
             &BusConversion_InsertedFor_Bas_n)) {
          UAM_Flight_control_DW.is_STATE_MACHINE_f =
            UAM_Flight_contro_IN_FWCOMPLETE;
          UAM_Flight_control_B.controlMode_l.TransitionCondition = 1U;
          UAM_Flight_control_B.flightMode_c = FixedWing;
        }
        break;
      }
    }

    /* End of Chart: '<S2669>/Basic Control  Switching' */

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2669>/Unit Delay'
     */
    UAM_Flight_control_B.Status = UAM_Flight_control_DW.UnitDelay_9_DSTATE_h;

    /* Update for UnitDelay generated from: '<S2669>/Unit Delay' incorporates:
     *  SignalConversion generated from: '<S2669>/Bus Selector1'
     */
    UAM_Flight_control_DW.UnitDelay_1_DSTATE_f =
      UAM_Flight_control_B.HoverSPBUS.X;

    /* Update for UnitDelay generated from: '<S2669>/Unit Delay' incorporates:
     *  SignalConversion generated from: '<S2669>/Bus Selector1'
     */
    UAM_Flight_control_DW.UnitDelay_2_DSTATE_gq =
      UAM_Flight_control_B.HoverSPBUS.Y;

    /* Update for UnitDelay generated from: '<S2669>/Unit Delay' incorporates:
     *  SignalConversion generated from: '<S2669>/Bus Selector1'
     */
    UAM_Flight_control_DW.UnitDelay_3_DSTATE_o =
      UAM_Flight_control_B.HoverSPBUS.Z;

    /* Update for UnitDelay generated from: '<S2669>/Unit Delay' incorporates:
     *  SignalConversion generated from: '<S2669>/Bus Selector1'
     */
    UAM_Flight_control_DW.UnitDelay_4_DSTATE_a =
      UAM_Flight_control_B.HoverSPBUS.Yaw;

    /* Update for UnitDelay generated from: '<S2669>/Unit Delay' incorporates:
     *  Constant: '<S2669>/Constant1'
     */
    UAM_Flight_control_DW.UnitDelay_5_DSTATE_h =
      UAM_Flight_control_P.Constant1_Value;

    /* Update for UnitDelay generated from: '<S2669>/Unit Delay' incorporates:
     *  Constant: '<S2669>/Constant2'
     */
    UAM_Flight_control_DW.UnitDelay_6_DSTATE_b =
      UAM_Flight_control_P.Constant2_Value;

    /* Update for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_7_DSTATE_b =
      UAM_Flight_control_B.controlMode_l;

    /* Update for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_8_DSTATE_p =
      UAM_Flight_control_B.flightMode_c;

    /* Update for UnitDelay generated from: '<S2669>/Unit Delay' incorporates:
     *  Constant: '<S2669>/Constant3'
     */
    UAM_Flight_control_DW.UnitDelay_9_DSTATE_h =
      UAM_Flight_control_P.Constant3_Value_f;

    /* End of Outputs for SubSystem: '<S2>/Manual' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/Auto' incorporates:
     *  ActionPort: '<S2667>/Action Port'
     */
    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2667>/Unit Delay'
     */
    UAM_Flight_control_B.X = UAM_Flight_control_DW.UnitDelay_1_DSTATE_b;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2667>/Unit Delay'
     */
    UAM_Flight_control_B.Y = UAM_Flight_control_DW.UnitDelay_2_DSTATE_k;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2667>/Unit Delay'
     */
    UAM_Flight_control_B.Z = UAM_Flight_control_DW.UnitDelay_3_DSTATE_b;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2667>/Unit Delay'
     */
    UAM_Flight_control_B.Yaw = UAM_Flight_control_DW.UnitDelay_4_DSTATE_f;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2667>/Unit Delay'
     */
    UAM_Flight_control_B.FixedWingSP =
      UAM_Flight_control_DW.UnitDelay_5_DSTATE_p;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2667>/Unit Delay'
     */
    UAM_Flight_control_B.AACSP = UAM_Flight_control_DW.UnitDelay_6_DSTATE_h;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2667>/Unit Delay'
     */
    UAM_Flight_control_B.controlMode_h =
      UAM_Flight_control_DW.UnitDelay_7_DSTATE_i;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2667>/Unit Delay'
     */
    UAM_Flight_control_B.FlightMode = UAM_Flight_control_DW.UnitDelay_8_DSTATE_d;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2667>/Unit Delay'
     */
    UAM_Flight_control_B.Status = UAM_Flight_control_DW.UnitDelay_9_DSTATE_e;

    /* BusCreator generated from: '<S2667>/Guidance Mode Selector' incorporates:
     *  UnitDelay generated from: '<S2>/Unit Delay1'
     */
    BusConversion_InsertedFor_Bas_n.Ve[0] =
      UAM_Flight_control_DW.UnitDelay1_4_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.Xe[0] =
      UAM_Flight_control_DW.UnitDelay1_5_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.Ve[1] =
      UAM_Flight_control_DW.UnitDelay1_4_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.Xe[1] =
      UAM_Flight_control_DW.UnitDelay1_5_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.Ve[2] =
      UAM_Flight_control_DW.UnitDelay1_4_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.Xe[2] =
      UAM_Flight_control_DW.UnitDelay1_5_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.course =
      UAM_Flight_control_DW.UnitDelay1_6_DSTATE;

    /* Chart: '<S2667>/Guidance Mode Selector' incorporates:
     *  BusCreator generated from: '<S2667>/Guidance Mode Selector'
     *  Constant: '<S2667>/Constant2'
     *  Merge: '<S2671>/ Merge 2'
     *  UnitDelay generated from: '<S2>/Unit Delay'
     *  UnitDelay generated from: '<S2>/Unit Delay1'
     */
    if (UAM_Flight_control_DW.temporalCounter_i1 < 1023) {
      UAM_Flight_control_DW.temporalCounter_i1++;
    }

    mode_prev = UAM_Flight_control_DW.mode_start;
    UAM_Flight_control_DW.mode_start =
      UAM_Flight_control_DW.UnitDelay_1_DSTATE_e;
    if (UAM_Flight_control_DW.is_active_c3_UAM_Flight_control == 0) {
      UAM_Flight_control_DW.is_active_c3_UAM_Flight_control = 1U;
      UAM_Flight_control_DW.is_GuidanceLogic = UAM_Flight_control_IN_Start_c;
      UAM_Flight_control_B.FlightMode_c = UAM_Flight_control_P.FSState;
      UAM_Flight_control_B.controlMode_n.airspeedAltitude = 1U;
      UAM_Flight_control_B.controlMode_n.attitude = 1U;
      UAM_Flight_control_B.controlMode_n.lateralGuidance = 0U;
      UAM_Flight_control_B.controlMode_n.TransitionCondition = 0U;
      UAM_Flight_control_B.controlMode_n.BackTransitionCondition = 0U;
      UAM_Flight_control_B.controlMode_n.land = 1.0;
      UAM_Flight_control_B.FixedWingSP_l.yaw = 0.0;
      UAM_Flight_control_B.FixedWingSP_l.pitch = 0.0;
      UAM_Flight_control_B.FixedWingSP_l.roll = 0.0;
      UAM_Flight_control_B.FixedWingSP_l.airspeed = 14.0;
      UAM_Flight_control_B.aacSP.L1 = 25.0;
      UAM_Flight_control_B.aacSP.airspeed = 14.0;
      UAM_Flight_control_B.aacSP.altitude = 0.0;
      UAM_Flight_control_B.aacSP.course = 0.0;
      UAM_Flight_control_B.InnerLoopCmds.YawCmd = 0.0;
    } else {
      UAM_Flight_contro_GuidanceLogic(&mode_prev,
        &BusConversion_InsertedFor_Bas_n);
    }

    if (UAM_Flight_control_DW.UnitDelay1_4_DSTATE[2] >= -1.0E-6) {
      UAM_Flight_control_DW.durationCounter_1++;
    } else {
      UAM_Flight_control_DW.durationCounter_1 = 0U;
    }

    /* End of Chart: '<S2667>/Guidance Mode Selector' */

    /* Stop: '<S2667>/Stop Simulation' incorporates:
     *  Constant: '<S2670>/Constant'
     *  RelationalOperator: '<S2670>/Compare'
     */
    if (UAM_Flight_control_B.Status_p ==
        UAM_Flight_control_P.CompareToConstant_const_ko) {
      rtmSetStopRequested(UAM_Flight_control_M, 1);
    }

    /* End of Stop: '<S2667>/Stop Simulation' */

    /* Update for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_1_DSTATE_b =
      UAM_Flight_control_B.InnerLoopCmds.LAP[0];

    /* Update for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_2_DSTATE_k =
      UAM_Flight_control_B.InnerLoopCmds.LAP[1];

    /* Update for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_3_DSTATE_b =
      UAM_Flight_control_B.InnerLoopCmds.LAP[2];

    /* Update for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_4_DSTATE_f =
      UAM_Flight_control_B.InnerLoopCmds.YawCmd;

    /* Update for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_5_DSTATE_p =
      UAM_Flight_control_B.FixedWingSP_l;

    /* Update for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_6_DSTATE_h = UAM_Flight_control_B.aacSP;

    /* Update for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_7_DSTATE_i =
      UAM_Flight_control_B.controlMode_n;

    /* Update for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_8_DSTATE_d =
      UAM_Flight_control_B.FlightMode_c;

    /* Update for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_9_DSTATE_e = UAM_Flight_control_B.Status_p;

    /* End of Outputs for SubSystem: '<S2>/Auto' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2>/Emergency' incorporates:
     *  ActionPort: '<S2668>/Action Port'
     */
    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2668>/Unit Delay'
     */
    UAM_Flight_control_B.X = UAM_Flight_control_DW.UnitDelay_1_DSTATE;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2668>/Unit Delay'
     */
    UAM_Flight_control_B.Y = UAM_Flight_control_DW.UnitDelay_2_DSTATE_g;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2668>/Unit Delay'
     */
    UAM_Flight_control_B.Z = UAM_Flight_control_DW.UnitDelay_3_DSTATE_i;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2668>/Unit Delay'
     */
    UAM_Flight_control_B.Yaw = UAM_Flight_control_DW.UnitDelay_4_DSTATE;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2668>/Unit Delay'
     */
    UAM_Flight_control_B.FixedWingSP = UAM_Flight_control_DW.UnitDelay_5_DSTATE;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2668>/Unit Delay'
     */
    UAM_Flight_control_B.AACSP = UAM_Flight_control_DW.UnitDelay_6_DSTATE;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2668>/Unit Delay'
     */
    UAM_Flight_control_B.controlMode_h =
      UAM_Flight_control_DW.UnitDelay_7_DSTATE;

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2668>/Unit Delay'
     */
    UAM_Flight_control_B.FlightMode = UAM_Flight_control_DW.UnitDelay_8_DSTATE;

    /* BusCreator generated from: '<S2668>/Basic Control  Switching' incorporates:
     *  UnitDelay generated from: '<S2>/Unit Delay1'
     */
    BusConversion_InsertedFor_Bas_n.Euler[0] =
      UAM_Flight_control_DW.UnitDelay1_2_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.pqr[0] =
      UAM_Flight_control_DW.UnitDelay1_3_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.Ve[0] =
      UAM_Flight_control_DW.UnitDelay1_4_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.Xe[0] =
      UAM_Flight_control_DW.UnitDelay1_5_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.Euler[1] =
      UAM_Flight_control_DW.UnitDelay1_2_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.pqr[1] =
      UAM_Flight_control_DW.UnitDelay1_3_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.Ve[1] =
      UAM_Flight_control_DW.UnitDelay1_4_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.Xe[1] =
      UAM_Flight_control_DW.UnitDelay1_5_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.Euler[2] =
      UAM_Flight_control_DW.UnitDelay1_2_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.pqr[2] =
      UAM_Flight_control_DW.UnitDelay1_3_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.Ve[2] =
      UAM_Flight_control_DW.UnitDelay1_4_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.Xe[2] =
      UAM_Flight_control_DW.UnitDelay1_5_DSTATE[2];
    BusConversion_InsertedFor_Bas_n.course =
      UAM_Flight_control_DW.UnitDelay1_6_DSTATE;
    BusConversion_InsertedFor_Bas_n.RotorParameters =
      UAM_Flight_control_DW.UnitDelay1_7_DSTATE;
    memcpy(&BusConversion_InsertedFor_Bas_n.RC[0],
           &UAM_Flight_control_DW.UnitDelay1_8_DSTATE[0], 10U * sizeof(real_T));
    BusConversion_InsertedFor_Bas_n.target[0] =
      UAM_Flight_control_DW.UnitDelay1_9_DSTATE[0];
    BusConversion_InsertedFor_Bas_n.target[1] =
      UAM_Flight_control_DW.UnitDelay1_9_DSTATE[1];
    BusConversion_InsertedFor_Bas_n.target[2] =
      UAM_Flight_control_DW.UnitDelay1_9_DSTATE[2];

    /* Chart: '<S2668>/Basic Control  Switching' incorporates:
     *  BusCreator generated from: '<S2668>/Basic Control  Switching'
     *  Constant: '<S2668>/Hover'
     *  UnitDelay generated from: '<S2>/Unit Delay1'
     *  UnitDelay: '<S2>/Unit Delay2'
     */
    if (UAM_Flight_control_DW.is_active_c11_UAM_Flight_contro == 0) {
      UAM_Flight_control_DW.is_active_c11_UAM_Flight_contro = 1U;
      UAM_Flight_control_DW.is_STATE_MACHINE = UAM_Flight_control_IN_Start_m;
      UAM_Flight_control_B.flightMode = UAM_Flight_control_P.FSState;
      UAM_Flight_control_B.controlMode_o.lateralGuidance = 0U;
      UAM_Flight_control_B.controlMode_o.airspeedAltitude = 0U;
      UAM_Flight_control_B.controlMode_o.attitude = 0U;
      UAM_Flight_control_B.controlMode_o.manual = 1U;
      UAM_Flight_control_B.controlMode_o.armed = 0U;
      UAM_Flight_control_B.controlMode_o.inTransition = 0U;
      UAM_Flight_control_B.controlMode_o.TransitionCondition = 0U;
      UAM_Flight_control_B.controlMode_o.BackTransitionCondition = 0U;
    } else {
      switch (UAM_Flight_control_DW.is_STATE_MACHINE) {
       case UAM_Flight__IN_BackTransition_a:
        if (UAM_Flight_con_backConditionMet
            (UAM_Flight_control_DW.UnitDelay2_DSTATE_l,
             &BusConversion_InsertedFor_Bas_n)) {
          UAM_Flight_control_DW.is_STATE_MACHINE =
            UAM_Flight_contro_IN_HVCOMPLETE;
          UAM_Flight_control_B.controlMode_o.inTransition = 0U;
          UAM_Flight_control_B.controlMode_o.BackTransitionCondition = 1U;
          UAM_Flight_control_B.flightMode = Hover;
        }
        break;

       case UAM_Flight_cont_IN_FWCOMPLETE_k:
       case UAM_Flight_contro_IN_HVCOMPLETE:
        break;

       case UAM_Flight_contr_IN_FixedWing_o:
        if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] < 1500.0) &&
            (UAM_Flight_control_B.flightMode == FixedWing)) {
          UAM_Flight_control_DW.is_STATE_MACHINE =
            UAM_Flight__IN_BackTransition_a;
          UAM_Flight_control_B.flightMode = BackTransition;
          UAM_Flight_control_B.controlMode_o.inTransition = 1U;
          UAM_Flight_control_B.controlMode_o.BackTransitionCondition = 0U;
        }
        break;

       case UAM_Flight_control_IN_HOVER:
        if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] >= 1500.0) &&
            (UAM_Flight_control_B.flightMode == Hover)) {
          UAM_Flight_control_DW.is_STATE_MACHINE =
            UAM_Flight_cont_IN_Transition_o;
          UAM_Flight_control_B.flightMode = Transition;
          UAM_Flight_control_B.controlMode_o.inTransition = 1U;
          UAM_Flight_control_B.controlMode_o.TransitionCondition = 0U;
        }
        break;

       case UAM_Flight_control_IN_Start_m:
        if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] < 1500.0) &&
            (UAM_Flight_control_B.flightMode == Hover)) {
          UAM_Flight_control_DW.is_STATE_MACHINE = UAM_Flight_control_IN_HOVER;
          UAM_Flight_control_B.flightMode = Hover;
        } else if ((UAM_Flight_control_DW.UnitDelay1_8_DSTATE[4] >= 1500.0) &&
                   (UAM_Flight_control_B.flightMode == FixedWing)) {
          UAM_Flight_control_DW.is_STATE_MACHINE =
            UAM_Flight_contr_IN_FixedWing_o;
          UAM_Flight_control_B.flightMode = FixedWing;
          UAM_Flight_control_B.controlMode_o.attitude = 1U;
          UAM_Flight_control_B.controlMode_o.inTransition = 0U;
          UAM_Flight_control_B.controlMode_o.TransitionCondition = 1U;
        }
        break;

       default:
        /* case IN_Transition: */
        if (UAM_Flig_transitionConditionMet
            (UAM_Flight_control_DW.UnitDelay2_DSTATE_l, UAM_Flight_control_P.Vt,
             &BusConversion_InsertedFor_Bas_n)) {
          UAM_Flight_control_DW.is_STATE_MACHINE =
            UAM_Flight_cont_IN_FWCOMPLETE_k;
          UAM_Flight_control_B.controlMode_o.TransitionCondition = 1U;
          UAM_Flight_control_B.flightMode = FixedWing;
        }
        break;
      }
    }

    /* End of Chart: '<S2668>/Basic Control  Switching' */

    /* Merge generated from: '<S2>/Merge' incorporates:
     *  UnitDelay generated from: '<S2668>/Unit Delay'
     */
    UAM_Flight_control_B.Status = UAM_Flight_control_DW.UnitDelay_9_DSTATE;

    /* Update for UnitDelay generated from: '<S2668>/Unit Delay' incorporates:
     *  Constant: '<S2668>/Constant'
     */
    UAM_Flight_control_DW.UnitDelay_1_DSTATE =
      UAM_Flight_control_P.Constant_Value_f;

    /* Update for UnitDelay generated from: '<S2668>/Unit Delay' incorporates:
     *  Constant: '<S2668>/Constant4'
     */
    UAM_Flight_control_DW.UnitDelay_2_DSTATE_g =
      UAM_Flight_control_P.Constant4_Value_k;

    /* Update for UnitDelay generated from: '<S2668>/Unit Delay' incorporates:
     *  Constant: '<S2668>/Constant5'
     */
    UAM_Flight_control_DW.UnitDelay_3_DSTATE_i =
      UAM_Flight_control_P.Constant5_Value_d;

    /* Update for UnitDelay generated from: '<S2668>/Unit Delay' incorporates:
     *  Constant: '<S2668>/Constant6'
     */
    UAM_Flight_control_DW.UnitDelay_4_DSTATE =
      UAM_Flight_control_P.Constant6_Value_a;

    /* Update for UnitDelay generated from: '<S2668>/Unit Delay' incorporates:
     *  Constant: '<S2668>/Constant1'
     */
    UAM_Flight_control_DW.UnitDelay_5_DSTATE =
      UAM_Flight_control_P.Constant1_Value_f;

    /* Update for UnitDelay generated from: '<S2668>/Unit Delay' incorporates:
     *  Constant: '<S2668>/Constant2'
     */
    UAM_Flight_control_DW.UnitDelay_6_DSTATE =
      UAM_Flight_control_P.Constant2_Value_i;

    /* Update for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_7_DSTATE =
      UAM_Flight_control_B.controlMode_o;

    /* Update for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_8_DSTATE = UAM_Flight_control_B.flightMode;

    /* Update for UnitDelay generated from: '<S2668>/Unit Delay' incorporates:
     *  Constant: '<S2668>/Constant3'
     */
    UAM_Flight_control_DW.UnitDelay_9_DSTATE =
      UAM_Flight_control_P.Constant3_Value_pj;

    /* End of Outputs for SubSystem: '<S2>/Emergency' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Concatenate: '<S1181>/Vector Concatenate'
   *  Concatenate: '<S1475>/Vector Concatenate'
   *  Concatenate: '<S1983>/Vector Concatenate'
   *  Constant: '<S1181>/Constant'
   *  Constant: '<S1197>/Constant'
   *  Constant: '<S1475>/Constant'
   *  Constant: '<S1705>/Constant'
   *  Constant: '<S189>/Constant'
   *  Constant: '<S190>/Constant'
   *  Constant: '<S1983>/Constant'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S522>/Constant'
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Inport: '<Root>/fcc'
   *  Logic: '<S13>/NOT1'
   *  Logic: '<S1698>/OR'
   *  Logic: '<S1698>/OR1'
   *  Logic: '<S17>/NOT1'
   *  Logic: '<S17>/NOT2'
   *  RelationalOperator: '<S1197>/Compare'
   *  RelationalOperator: '<S1705>/Compare'
   *  RelationalOperator: '<S189>/Compare'
   *  RelationalOperator: '<S190>/Compare'
   *  RelationalOperator: '<S28>/Compare'
   *  RelationalOperator: '<S29>/Compare'
   *  RelationalOperator: '<S522>/Compare'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtAction = UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m;
  switch (rtb_mode) {
   case Manual:
    UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m = 0;
    break;

   case Auto:
    UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m = 1;
    break;

   default:
    UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m = 2;
    break;
  }

  if (rtAction != UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m) {
    switch (rtAction) {
     case 0:
      /* Disable for Enabled SubSystem: '<S9>/multicopter Controller' */
      if (UAM_Flight_control_DW.multicopterController_MODE) {
        /* Disable for Enabled SubSystem: '<S1698>/Altitude Control1' */
        UAM_Flight_control_DW.AltitudeControl1_MODE = false;

        /* End of Disable for SubSystem: '<S1698>/Altitude Control1' */

        /* Disable for Enabled SubSystem: '<S1698>/Horizontal Position Control1' */
        UAM_Flight_control_DW.HorizontalPositionControl1_MODE = false;

        /* End of Disable for SubSystem: '<S1698>/Horizontal Position Control1' */
        UAM_Flight_control_DW.multicopterController_MODE = false;
      }

      /* End of Disable for SubSystem: '<S9>/multicopter Controller' */

      /* Disable for Enabled SubSystem: '<S9>/Scheduler' */
      if (UAM_Flight_control_DW.Scheduler_MODE_p) {
        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cv2z =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nw2 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_adlp =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_jx3i =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_mqvj = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_kewq = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ahl1 = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_e1ub = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_oniv =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_daxi =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bawm = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_edgh = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_nlya = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dq0y = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kbh = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mey = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ps2n = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ezp =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dec =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gbt =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_i0g =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dgzi =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ae0 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bjh =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jjd =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ajjw = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_hwn = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pgbn = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_n2x4 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_gx0x =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bbr4 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pyg =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pdsb =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fsn =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_by1n =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cr0 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_duzz =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[0] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[1] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[2] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[3] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_awya =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_l5c = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bkn5 = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_irme = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_exub = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ouuy = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_k55z = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_odds = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_a2gj = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        for (i = 0; i < 6; i++) {
          /* Disable for Concatenate: '<S1983>/Vector Concatenate' incorporates:
           *  Outport: '<S1697>/MotorActuatorCommands'
           * */
          UAM_Flight_control_B.VectorConcatenate_c[i] =
            UAM_Flight_control_P.MotorActuatorCommands_Y0;
        }

        for (i = 0; i < 16; i++) {
          /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
           *  Outport: '<S1697>/MotorActuatorCommands'
           * */
          UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cvbt[i] =
            UAM_Flight_control_P.MotorActuatorCommands_Y0;
        }

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[0] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[1] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[2] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1697>/CtrlSurfaceCommands' incorporates:
         *  Outport: '<S1697>/CtrlSurfaceCommands'
         * */
        UAM_Flight_control_B.OutportBufferForCtrlSurfaceC_i5 =
          UAM_Flight_control_P.CtrlSurfaceCommands_Y0;
        UAM_Flight_control_DW.Scheduler_MODE_p = false;
      }

      /* End of Disable for SubSystem: '<S9>/Scheduler' */
      break;

     case 1:
      /* Disable for Enabled SubSystem: '<S7>/Multicopter Controller' */
      if (UAM_Flight_control_DW.MulticopterController_MODE) {
        /* Disable for Enabled SubSystem: '<S517>/Altitude Control' */
        UAM_Flight_control_DW.AltitudeControl_MODE = false;

        /* End of Disable for SubSystem: '<S517>/Altitude Control' */

        /* Disable for Enabled SubSystem: '<S13>/Horizontal Position Control' */
        if (UAM_Flight_control_DW.HorizontalPositionControl_MODE) {
          /* Disable for Enabled SubSystem: '<S518>/XY Controller' */
          UAM_Flight_control_DW.XYController_MODE = false;

          /* End of Disable for SubSystem: '<S518>/XY Controller' */
          UAM_Flight_control_DW.HorizontalPositionControl_MODE = false;
        }

        /* End of Disable for SubSystem: '<S13>/Horizontal Position Control' */
        UAM_Flight_control_DW.MulticopterController_MODE = false;
      }

      /* End of Disable for SubSystem: '<S7>/Multicopter Controller' */

      /* Disable for Enabled SubSystem: '<S7>/Scheduler' */
      if (UAM_Flight_control_DW.Scheduler_MODE_g) {
        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cv2 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nw =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_adl =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jx3 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mqv = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kew = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ahl = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_e1u = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_oni =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dax =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_baw = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_edg = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nly = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dq0 = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_kb = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_me = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ps2 = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ez =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_de =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gb =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_i0 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dgz =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ae =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bj =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jj =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ajj = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_hw = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pgb = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_n2x =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gx0 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bbr =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_py =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pds =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fs =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_by1 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cr =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_duz =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[0] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[1] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[2] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[3] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_awy =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_l5 = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bkn = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_irm = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_exu = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ouu = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_k55 = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_odd = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_a2g = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
        for (i = 0; i < 6; i++) {
          /* Disable for Concatenate: '<S1181>/Vector Concatenate' incorporates:
           *  Outport: '<S14>/MotorActuatorCommands'
           * */
          UAM_Flight_control_B.VectorConcatenate_f[i] =
            UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
        }

        for (i = 0; i < 16; i++) {
          /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
           *  Outport: '<S14>/MotorActuatorCommands'
           * */
          UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cvb[i] =
            UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
        }

        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[0] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[1] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[2] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

        /* Disable for SignalConversion generated from: '<S14>/CtrlSurfaceCommands' incorporates:
         *  Outport: '<S14>/CtrlSurfaceCommands'
         * */
        UAM_Flight_control_B.OutportBufferForCtrlSurfaceCo_i =
          UAM_Flight_control_P.CtrlSurfaceCommands_Y0_h;
        UAM_Flight_control_DW.Scheduler_MODE_g = false;
      }

      /* End of Disable for SubSystem: '<S7>/Scheduler' */
      break;

     case 2:
      /* Disable for Enabled SubSystem: '<S8>/Scheduler' */
      if (UAM_Flight_control_DW.Scheduler_MODE) {
        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreator_ =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_n =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ad =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jx =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_mq = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ke = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ah = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_e1 = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_on =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_da =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ba = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ed = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nl = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dq = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_k = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_m = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ps = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_e =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_d =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_g =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_i =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dg =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_a =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_b =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_j =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aj = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_h = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pg = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_n2 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gx =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bb =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_p =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pd =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_f =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_by =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_c =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_du =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[0] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[1] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[2] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[3] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aw =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_l = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bk = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ir = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ex = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ou = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_k5 = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_od = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_a2 = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
        for (i = 0; i < 6; i++) {
          /* Disable for Concatenate: '<S1475>/Vector Concatenate' incorporates:
           *  Outport: '<S1189>/MotorActuatorCommands'
           * */
          UAM_Flight_control_B.VectorConcatenate[i] =
            UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
        }

        for (i = 0; i < 16; i++) {
          /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
           *  Outport: '<S1189>/MotorActuatorCommands'
           * */
          UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cv[i] =
            UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
        }

        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[0] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[1] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[2] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

        /* Disable for SignalConversion generated from: '<S1189>/CtrlSurfaceCommands' incorporates:
         *  Outport: '<S1189>/CtrlSurfaceCommands'
         * */
        UAM_Flight_control_B.OutportBufferForCtrlSurfaceComm =
          UAM_Flight_control_P.CtrlSurfaceCommands_Y0_k;
        UAM_Flight_control_DW.Scheduler_MODE = false;
      }

      /* End of Disable for SubSystem: '<S8>/Scheduler' */
      break;
    }
  }

  switch (UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Manual' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Outputs for Enabled SubSystem: '<S9>/Scheduler' incorporates:
     *  EnablePort: '<S1697>/Actuator Armed'
     */
    /* Outputs for Enabled SubSystem: '<S9>/FixedWing Controller' incorporates:
     *  EnablePort: '<S1696>/Actuator Armed'
     */
    /* Outputs for Enabled SubSystem: '<S9>/multicopter Controller' incorporates:
     *  EnablePort: '<S1698>/Actuator Armed'
     */
    if (rtb_Compare_ic) {
      UAM_Flight_control_DW.multicopterController_MODE = true;

      /* RelationalOperator: '<S1698>/IsNaN2' */
      rtb_IsNaN2 = rtIsNaN(UAM_Flight_control_B.X);

      /* RelationalOperator: '<S1698>/IsNaN1' */
      rtb_IsNaN1 = rtIsNaN(UAM_Flight_control_B.Y);

      /* RelationalOperator: '<S1698>/IsNaN' */
      rtb_IsNaN = rtIsNaN(UAM_Flight_control_B.Z);

      /* Logic: '<S1698>/NOT' incorporates:
       *  Logic: '<S1698>/NOT3'
       */
      rtb_XYZ_Valid = !rtb_IsNaN;

      /* Logic: '<S1698>/AND1' incorporates:
       *  Logic: '<S1698>/NOT'
       *  Logic: '<S1698>/OR2'
       */
      rtb_Compare_j = ((rtb_IsNaN2 || rtb_IsNaN1) && rtb_XYZ_Valid);

      /* Gain: '<S1994>/Gain1' incorporates:
       *  Bias: '<S1994>/Bias1'
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      s = (UAM_Flight_control_U.fcc.rc[2] + UAM_Flight_control_P.Bias1_Bias) *
        UAM_Flight_control_P.Gain1_Gain_k;

      /* Saturate: '<S1994>/Saturation' */
      if (s > UAM_Flight_control_P.Saturation_UpperSat_f) {
        s = UAM_Flight_control_P.Saturation_UpperSat_f;
      } else if (s < UAM_Flight_control_P.Saturation_LowerSat_e) {
        s = UAM_Flight_control_P.Saturation_LowerSat_e;
      }

      /* End of Saturate: '<S1994>/Saturation' */

      /* Logic: '<S1698>/XYZ_Valid' incorporates:
       *  Logic: '<S1698>/NOT1'
       *  Logic: '<S1698>/NOT2'
       */
      rtb_XYZ_Valid = ((!rtb_IsNaN2) && (!rtb_IsNaN1) && rtb_XYZ_Valid);

      /* Outputs for Enabled SubSystem: '<S1698>/Altitude Control1' incorporates:
       *  EnablePort: '<S1989>/Enable'
       */
      if (rtb_XYZ_Valid || rtb_Compare_j) {
        if (!UAM_Flight_control_DW.AltitudeControl1_MODE) {
          /* InitializeConditions for UnitDelay: '<S2107>/Delay Input1'
           *
           * Block description for '<S2107>/Delay Input1':
           *
           *  Store in Global RAM
           */
          UAM_Flight_control_DW.DelayInput1_DSTATE_b =
            UAM_Flight_control_P.DetectRisePositive_vinit;

          /* InitializeConditions for UnitDelay: '<S2108>/Delay Input1'
           *
           * Block description for '<S2108>/Delay Input1':
           *
           *  Store in Global RAM
           */
          UAM_Flight_control_DW.DelayInput1_DSTATE_f =
            UAM_Flight_control_P.DetectRisePositive1_vinit;

          /* InitializeConditions for UnitDelay: '<S1999>/Unit Delay' */
          UAM_Flight_control_DW.UnitDelay_DSTATE_e =
            UAM_Flight_control_P.UnitDelay_InitialCondition;

          /* InitializeConditions for DiscreteIntegrator: '<S2088>/Integrator' */
          UAM_Flight_control_DW.Integrator_DSTATE_a2 =
            UAM_Flight_control_P.Altituderatecontroller_Initia_j;
          UAM_Flight_control_DW.Integrator_PrevResetState_f = 2;

          /* InitializeConditions for DiscreteIntegrator: '<S2083>/Filter' */
          UAM_Flight_control_DW.Filter_DSTATE_f =
            UAM_Flight_control_P.Altituderatecontroller_InitialC;
          UAM_Flight_control_DW.Filter_PrevResetState_m = 2;

          /* InitializeConditions for Product: '<S1989>/Divide' incorporates:
           *  UnitDelay: '<S1989>/Unit Delay'
           */
          UAM_Flight_control_DW.UnitDelay_DSTATE_g =
            UAM_Flight_control_P.UnitDelay_InitialCondition_k;

          /* SystemReset for MATLAB Function: '<S1989>/MATLAB Function' */
          UAM__MATLABFunction_p_Reset
            (&UAM_Flight_control_DW.sf_MATLABFunction_mi);
          UAM_Flight_control_DW.AltitudeControl1_MODE = true;
        }

        /* Gain: '<S1989>/Gain' */
        rtb_Integrator_o4 = UAM_Flight_control_P.Gain_Gain_b * rtb_Mag_idx_2;

        /* Gain: '<S1999>/Gain3' incorporates:
         *  Bias: '<S1999>/Bias'
         */
        rtb_IntegralGain_no = (s + UAM_Flight_control_P.Bias_Bias_h) *
          UAM_Flight_control_P.Gain3_Gain_h;

        /* DeadZone: '<S1999>/Dead Zone' */
        if (rtb_IntegralGain_no > UAM_Flight_control_P.DeadZone_End) {
          rtb_throttle = rtb_IntegralGain_no - UAM_Flight_control_P.DeadZone_End;
        } else if (rtb_IntegralGain_no >= UAM_Flight_control_P.DeadZone_Start) {
          rtb_throttle = 0.0;
        } else {
          rtb_throttle = rtb_IntegralGain_no -
            UAM_Flight_control_P.DeadZone_Start;
        }

        /* End of DeadZone: '<S1999>/Dead Zone' */

        /* MATLAB Function: '<S1999>/MATLAB Function' incorporates:
         *  Constant: '<S1999>/Constant'
         */
        rtb_IntegralGain_no = fabs(rtb_throttle);
        if (rtIsNaN(rtb_throttle)) {
          rtb_Bias_l = (rtNaN);
        } else if (rtb_throttle < 0.0) {
          rtb_Bias_l = -1.0;
        } else {
          rtb_Bias_l = (rtb_throttle > 0.0);
        }

        rtb_IntegralGain_no = ((1.0 - UAM_Flight_control_P.Constant_Value_o) *
          rtb_IntegralGain_no + UAM_Flight_control_P.Constant_Value_o *
          rt_powd_snf(rtb_IntegralGain_no, 3.0)) * rtb_Bias_l;

        /* End of MATLAB Function: '<S1999>/MATLAB Function' */

        /* RelationalOperator: '<S2106>/Compare' incorporates:
         *  Abs: '<S1999>/Abs'
         *  Constant: '<S2106>/Constant'
         */
        rtb_Compare_e5 = (fabs(rtb_IntegralGain_no) <
                          UAM_Flight_control_P.CompareToConstant_const);

        /* RelationalOperator: '<S2110>/Compare' incorporates:
         *  Constant: '<S2110>/Constant'
         */
        rtb_Compare_mc = ((int32_T)rtb_Compare_e5 > (int32_T)
                          UAM_Flight_control_P.Constant_Value_hf);

        /* RelationalOperator: '<S2111>/Compare' incorporates:
         *  Constant: '<S2111>/Constant'
         */
        rtb_Compare_l = !UAM_Flight_control_P.Constant_Value_a;

        /* Switch: '<S1999>/Switch1' incorporates:
         *  Logic: '<S1999>/OR'
         *  RelationalOperator: '<S2107>/FixPt Relational Operator'
         *  RelationalOperator: '<S2108>/FixPt Relational Operator'
         *  UnitDelay: '<S1999>/Unit Delay'
         *  UnitDelay: '<S2107>/Delay Input1'
         *  UnitDelay: '<S2108>/Delay Input1'
         *
         * Block description for '<S2107>/Delay Input1':
         *
         *  Store in Global RAM
         *
         * Block description for '<S2108>/Delay Input1':
         *
         *  Store in Global RAM
         */
        if (((int32_T)rtb_Compare_mc > (int32_T)
             UAM_Flight_control_DW.DelayInput1_DSTATE_b) || ((int32_T)
             rtb_Compare_l > (int32_T)UAM_Flight_control_DW.DelayInput1_DSTATE_f))
        {
          UAM_Flight_control_DW.UnitDelay_DSTATE_e = rtb_Integrator_o4;
        }

        /* End of Switch: '<S1999>/Switch1' */

        /* Gain: '<S1989>/Gain1' */
        rtb_throttle = UAM_Flight_control_P.Gain1_Gain_p * rtb_Kvz_a;

        /* Switch: '<S1989>/Switch' incorporates:
         *  Gain: '<S1999>/throttle_down'
         *  Gain: '<S2039>/Proportional Gain'
         *  Sum: '<S1989>/Sum'
         *  Switch: '<S1999>/Switch'
         *  UnitDelay: '<S1999>/Unit Delay'
         */
        if (rtb_Compare_e5) {
          rtb_Bias_l = (UAM_Flight_control_DW.UnitDelay_DSTATE_e -
                        rtb_Integrator_o4) *
            UAM_Flight_control_P.Altitudecontroller_P;
        } else if (rtb_IntegralGain_no >= UAM_Flight_control_P.Switch_Threshold)
        {
          /* Switch: '<S1999>/Switch' incorporates:
           *  Gain: '<S1999>/throttle_up'
           */
          rtb_Bias_l = UAM_Flight_control_P.throttle_up_Gain *
            rtb_IntegralGain_no;
        } else {
          rtb_Bias_l = UAM_Flight_control_P.throttle_down_Gain *
            rtb_IntegralGain_no;
        }

        /* Sum: '<S1989>/Sum1' incorporates:
         *  Switch: '<S1989>/Switch'
         */
        rtb_IntegralGain_no = rtb_Bias_l - rtb_throttle;

        /* DiscreteIntegrator: '<S2088>/Integrator' */
        if (UAM_Flight_control_DW.Integrator_PrevResetState_f <= 0) {
          UAM_Flight_control_DW.Integrator_DSTATE_a2 =
            UAM_Flight_control_P.Altituderatecontroller_Initia_j;
        }

        /* DiscreteIntegrator: '<S2083>/Filter' */
        if (UAM_Flight_control_DW.Filter_PrevResetState_m <= 0) {
          UAM_Flight_control_DW.Filter_DSTATE_f =
            UAM_Flight_control_P.Altituderatecontroller_InitialC;
        }

        /* Gain: '<S2091>/Filter Coefficient' incorporates:
         *  DiscreteIntegrator: '<S2083>/Filter'
         *  Gain: '<S2081>/Derivative Gain'
         *  Sum: '<S2083>/SumD'
         */
        rtb_Integrator_o4 = (UAM_Flight_control_P.controlParams.D_VZ *
                             rtb_IntegralGain_no -
                             UAM_Flight_control_DW.Filter_DSTATE_f) *
          UAM_Flight_control_P.controlParams.N_VZ;

        /* Sum: '<S2097>/Sum' incorporates:
         *  DiscreteIntegrator: '<S2088>/Integrator'
         *  Gain: '<S2093>/Proportional Gain'
         */
        rtb_DeadZone_o = (UAM_Flight_control_P.controlParams.P_VZ *
                          rtb_IntegralGain_no +
                          UAM_Flight_control_DW.Integrator_DSTATE_a2) +
          rtb_Integrator_o4;

        /* MATLAB Function: '<S1989>/MATLAB Function' incorporates:
         *  Inport: '<Root>/fcc'
         *  SignalConversion generated from: '<Root>/fcc'
         *  UnitDelay: '<S1989>/Unit Delay'
         */
        UAM_Flight_MATLABFunction_m(UAM_Flight_control_DW.UnitDelay_DSTATE_g,
          rtb_throttle, UAM_Flight_control_U.fcc.acc_z, true, &rtb_hover_est_l,
          &UAM_Flight_control_DW.sf_MATLABFunction_mi);

        /* Saturate: '<S2095>/Saturation' */
        if (rtb_DeadZone_o >
            UAM_Flight_control_P.Altituderatecontroller_UpperSat) {
          rtb_Bias_l = UAM_Flight_control_P.Altituderatecontroller_UpperSat;
        } else if (rtb_DeadZone_o <
                   UAM_Flight_control_P.Altituderatecontroller_LowerSat) {
          rtb_Bias_l = UAM_Flight_control_P.Altituderatecontroller_LowerSat;
        } else {
          rtb_Bias_l = rtb_DeadZone_o;
        }

        /* Product: '<S1989>/Divide' incorporates:
         *  Gain: '<S1989>/hover_thrust//g'
         *  Product: '<S1989>/Product'
         *  Product: '<S1989>/Product1'
         *  Saturate: '<S2095>/Saturation'
         *  Sum: '<S1989>/Sum3'
         *  Trigonometry: '<S1989>/Cos'
         *  Trigonometry: '<S1989>/Cos1'
         */
        UAM_Flight_control_DW.UnitDelay_DSTATE_g = (rtb_hover_est_l * rtb_Bias_l
          * UAM_Flight_control_P.hover_thrustg_Gain + rtb_hover_est_l) / (cos
          (rtb_Gain1[2]) * cos(rtb_Gain1[1]));

        /* Saturate: '<S1989>/Saturation1' */
        if (UAM_Flight_control_DW.UnitDelay_DSTATE_g >
            UAM_Flight_control_P.Saturation1_UpperSat_p) {
          /* Product: '<S1989>/Divide' */
          UAM_Flight_control_DW.UnitDelay_DSTATE_g =
            UAM_Flight_control_P.Saturation1_UpperSat_p;
        } else if (UAM_Flight_control_DW.UnitDelay_DSTATE_g <
                   UAM_Flight_control_P.Saturation1_LowerSat_i) {
          /* Product: '<S1989>/Divide' */
          UAM_Flight_control_DW.UnitDelay_DSTATE_g =
            UAM_Flight_control_P.Saturation1_LowerSat_i;
        }

        /* End of Saturate: '<S1989>/Saturation1' */

        /* Merge: '<S1698>/Merge2' incorporates:
         *  SignalConversion generated from: '<S1989>/commanded thrust'
         *  UnitDelay: '<S1989>/Unit Delay'
         */
        UAM_Flight_control_B.Merge2 = UAM_Flight_control_DW.UnitDelay_DSTATE_g;

        /* DeadZone: '<S2080>/DeadZone' */
        if (rtb_DeadZone_o >
            UAM_Flight_control_P.Altituderatecontroller_UpperSat) {
          rtb_DeadZone_o -= UAM_Flight_control_P.Altituderatecontroller_UpperSat;
        } else if (rtb_DeadZone_o >=
                   UAM_Flight_control_P.Altituderatecontroller_LowerSat) {
          rtb_DeadZone_o = 0.0;
        } else {
          rtb_DeadZone_o -= UAM_Flight_control_P.Altituderatecontroller_LowerSat;
        }

        /* End of DeadZone: '<S2080>/DeadZone' */

        /* Gain: '<S2085>/Integral Gain' */
        rtb_IntegralGain_no *= UAM_Flight_control_P.controlParams.I_VZ;

        /* Update for UnitDelay: '<S2107>/Delay Input1'
         *
         * Block description for '<S2107>/Delay Input1':
         *
         *  Store in Global RAM
         */
        UAM_Flight_control_DW.DelayInput1_DSTATE_b = rtb_Compare_mc;

        /* Update for UnitDelay: '<S2108>/Delay Input1'
         *
         * Block description for '<S2108>/Delay Input1':
         *
         *  Store in Global RAM
         */
        UAM_Flight_control_DW.DelayInput1_DSTATE_f = rtb_Compare_l;

        /* Switch: '<S2078>/Switch1' incorporates:
         *  Constant: '<S2078>/Clamping_zero'
         *  Constant: '<S2078>/Constant'
         *  Constant: '<S2078>/Constant2'
         *  RelationalOperator: '<S2078>/fix for DT propagation issue'
         */
        if (rtb_DeadZone_o > UAM_Flight_control_P.Clamping_zero_Value_n) {
          rtAction = UAM_Flight_control_P.Constant_Value_mm;
        } else {
          rtAction = UAM_Flight_control_P.Constant2_Value_l;
        }

        /* Switch: '<S2078>/Switch2' incorporates:
         *  Constant: '<S2078>/Clamping_zero'
         *  Constant: '<S2078>/Constant3'
         *  Constant: '<S2078>/Constant4'
         *  RelationalOperator: '<S2078>/fix for DT propagation issue1'
         */
        if (rtb_IntegralGain_no > UAM_Flight_control_P.Clamping_zero_Value_n) {
          tmp_1 = UAM_Flight_control_P.Constant3_Value_h;
        } else {
          tmp_1 = UAM_Flight_control_P.Constant4_Value_in;
        }

        /* Switch: '<S2078>/Switch' incorporates:
         *  Constant: '<S2078>/Clamping_zero'
         *  Constant: '<S2078>/Constant1'
         *  Logic: '<S2078>/AND3'
         *  RelationalOperator: '<S2078>/Equal1'
         *  RelationalOperator: '<S2078>/Relational Operator'
         *  Switch: '<S2078>/Switch1'
         *  Switch: '<S2078>/Switch2'
         */
        if ((UAM_Flight_control_P.Clamping_zero_Value_n != rtb_DeadZone_o) &&
            (rtAction == tmp_1)) {
          rtb_IntegralGain_no = UAM_Flight_control_P.Constant1_Value_p;
        }

        /* Update for DiscreteIntegrator: '<S2088>/Integrator' incorporates:
         *  Switch: '<S2078>/Switch'
         */
        UAM_Flight_control_DW.Integrator_DSTATE_a2 +=
          UAM_Flight_control_P.Integrator_gainval_n * rtb_IntegralGain_no;
        if (UAM_Flight_control_DW.Integrator_DSTATE_a2 >
            UAM_Flight_control_P.Altituderatecontroller_UpperInt) {
          UAM_Flight_control_DW.Integrator_DSTATE_a2 =
            UAM_Flight_control_P.Altituderatecontroller_UpperInt;
        } else if (UAM_Flight_control_DW.Integrator_DSTATE_a2 <
                   UAM_Flight_control_P.Altituderatecontroller_LowerInt) {
          UAM_Flight_control_DW.Integrator_DSTATE_a2 =
            UAM_Flight_control_P.Altituderatecontroller_LowerInt;
        }

        UAM_Flight_control_DW.Integrator_PrevResetState_f = 1;

        /* End of Update for DiscreteIntegrator: '<S2088>/Integrator' */

        /* Update for DiscreteIntegrator: '<S2083>/Filter' */
        UAM_Flight_control_DW.Filter_DSTATE_f +=
          UAM_Flight_control_P.Filter_gainval_e * rtb_Integrator_o4;
        UAM_Flight_control_DW.Filter_PrevResetState_m = 1;
      } else {
        UAM_Flight_control_DW.AltitudeControl1_MODE = false;
      }

      /* End of Outputs for SubSystem: '<S1698>/Altitude Control1' */

      /* Gain: '<S1994>/Gain' incorporates:
       *  Bias: '<S1994>/Bias'
       *  Inport: '<Root>/fcc'
       *  Logic: '<S1698>/OR1'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      rtb_TmpSignalConversionAtSFun_g[0] = (UAM_Flight_control_U.fcc.rc[0] +
        UAM_Flight_control_P.Bias_Bias_j) * UAM_Flight_control_P.Gain_Gain_c;
      rtb_TmpSignalConversionAtSFun_g[1] = (UAM_Flight_control_U.fcc.rc[1] +
        UAM_Flight_control_P.Bias_Bias_j) * UAM_Flight_control_P.Gain_Gain_c;
      rtb_TmpSignalConversionAtSFun_g[2] = (UAM_Flight_control_U.fcc.rc[3] +
        UAM_Flight_control_P.Bias_Bias_j) * UAM_Flight_control_P.Gain_Gain_c;

      /* RelationalOperator: '<S2434>/Compare' incorporates:
       *  Abs: '<S2119>/Abs'
       *  Constant: '<S2434>/Constant'
       */
      rtb_Compare = (uint8_T)(fabs(rtb_TmpSignalConversionAtSFun_g[2]) >
        UAM_Flight_control_P.deadzone_const);

      /* MATLAB Function: '<S2119>/MATLAB Function' incorporates:
       *  Constant: '<S2433>/Constant'
       *  Constant: '<S2435>/Constant'
       *  Constant: '<S2436>/Constant'
       *  Constant: '<S2437>/Constant'
       *  Constant: '<S2712>/Constant'
       *  Inport: '<Root>/fcc'
       *  Logic: '<S2119>/AND'
       *  Logic: '<S2119>/OR'
       *  Logic: '<S2119>/edge_falling'
       *  RelationalOperator: '<S2433>/Compare'
       *  RelationalOperator: '<S2435>/Compare'
       *  RelationalOperator: '<S2436>/Compare'
       *  RelationalOperator: '<S2437>/Compare'
       *  RelationalOperator: '<S2712>/Compare'
       *  SignalConversion generated from: '<Root>/fcc'
       *  UnitDelay: '<S2119>/Unit Delay'
       *  UnitDelay: '<S2119>/Unit Delay1'
       */
      if (((UAM_Flight_control_DW.UnitDelay_DSTATE_d ==
            UAM_Flight_control_P.prev_is_1_const) && (rtb_Compare ==
            UAM_Flight_control_P.now_is_0_const)) ||
          ((UAM_Flight_control_DW.UnitDelay1_DSTATE_l ==
            UAM_Flight_control_P.disarm_const) && ((UAM_Flight_control_U.fcc.rc
             [5] > UAM_Flight_control_P.CompareToConstant_const_d) ==
            UAM_Flight_control_P.arm_const))) {
        UAM_Flight_control_DW.last_yaw_sp = rtb_Gain1[0];
      }

      /* MATLAB Function: '<S1990>/MATLAB Function' incorporates:
       *  MATLAB Function: '<S2119>/MATLAB Function'
       *  Sum: '<S1990>/Sum4'
       */
      UAM_Flight_MATLABFunction_i(UAM_Flight_control_DW.last_yaw_sp - rtb_Gain1
        [0], &rtb_IntegralGain_no);

      /* Switch: '<S1990>/Switch' incorporates:
       *  Gain: '<S2119>/yaw_max_rate'
       *  Gain: '<S2367>/Proportional Gain'
       */
      if (rtb_Compare > UAM_Flight_control_P.Switch_Threshold_g) {
        rtb_Bias_l = UAM_Flight_control_P.yaw_max_rate_Gain *
          rtb_TmpSignalConversionAtSFun_g[2];
      } else {
        rtb_Bias_l = UAM_Flight_control_P.controlParams.RC_P_YAW *
          rtb_IntegralGain_no;
      }

      /* Sum: '<S1990>/Sum3' incorporates:
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       *  Switch: '<S1990>/Switch'
       */
      rtb_qout_idx_0 = rtb_Bias_l - UAM_Flight_control_U.fcc.gyro_z;

      /* Outputs for Enabled SubSystem: '<S1698>/Horizontal Position Control1' incorporates:
       *  EnablePort: '<S1992>/Enable'
       */
      if (rtb_XYZ_Valid) {
        if (!UAM_Flight_control_DW.HorizontalPositionControl1_MODE) {
          /* InitializeConditions for RateLimiter: '<S1992>/Rate Limiter' */
          UAM_Flight_control_DW.PrevY = UAM_Flight_control_P.RateLimiter_IC;

          /* InitializeConditions for UnitDelay: '<S2663>/Delay Input1'
           *
           * Block description for '<S2663>/Delay Input1':
           *
           *  Store in Global RAM
           */
          UAM_Flight_control_DW.DelayInput1_DSTATE =
            UAM_Flight_control_P.DetectRisePositive_vinit_j;

          /* InitializeConditions for UnitDelay: '<S2664>/Delay Input1'
           *
           * Block description for '<S2664>/Delay Input1':
           *
           *  Store in Global RAM
           */
          UAM_Flight_control_DW.DelayInput1_DSTATE_e =
            UAM_Flight_control_P.DetectRisePositive1_vinit_g;

          /* InitializeConditions for UnitDelay: '<S2450>/Unit Delay' */
          UAM_Flight_control_DW.UnitDelay_DSTATE_i =
            UAM_Flight_control_P.UnitDelay_InitialCondition_o;

          /* InitializeConditions for UnitDelay: '<S2450>/Unit Delay1' */
          UAM_Flight_control_DW.UnitDelay1_DSTATE_p =
            UAM_Flight_control_P.UnitDelay1_InitialCondition;

          /* InitializeConditions for DiscreteIntegrator: '<S2645>/Integrator' */
          UAM_Flight_control_DW.Integrator_DSTATE_f =
            UAM_Flight_control_P.Lateralvelocitycontroller_Ini_k;
          UAM_Flight_control_DW.Integrator_PrevResetState_i = 2;

          /* InitializeConditions for DiscreteIntegrator: '<S2640>/Filter' */
          UAM_Flight_control_DW.Filter_DSTATE_mr =
            UAM_Flight_control_P.Lateralvelocitycontroller_Initi;
          UAM_Flight_control_DW.Filter_PrevResetState_l = 2;

          /* InitializeConditions for RateLimiter: '<S1992>/Rate Limiter1' */
          UAM_Flight_control_DW.PrevY_i = UAM_Flight_control_P.RateLimiter1_IC;

          /* InitializeConditions for DiscreteIntegrator: '<S2539>/Integrator' */
          UAM_Flight_control_DW.Integrator_DSTATE_j3 =
            UAM_Flight_control_P.Forwardvelocitycontroller_Ini_i;
          UAM_Flight_control_DW.Integrator_PrevResetState_pz = 2;

          /* InitializeConditions for DiscreteIntegrator: '<S2534>/Filter' */
          UAM_Flight_control_DW.Filter_DSTATE_a4 =
            UAM_Flight_control_P.Forwardvelocitycontroller_Initi;
          UAM_Flight_control_DW.Filter_PrevResetState_c = 2;
          UAM_Flight_control_DW.HorizontalPositionControl1_MODE = true;
        }

        /* DeadZone: '<S1992>/Dead Zone' */
        if (rtb_TmpSignalConversionAtSFun_g[0] >
            UAM_Flight_control_P.DeadZone_End_h) {
          rtb_Bias_l = rtb_TmpSignalConversionAtSFun_g[0] -
            UAM_Flight_control_P.DeadZone_End_h;
        } else if (rtb_TmpSignalConversionAtSFun_g[0] >=
                   UAM_Flight_control_P.DeadZone_Start_b) {
          rtb_Bias_l = 0.0;
        } else {
          rtb_Bias_l = rtb_TmpSignalConversionAtSFun_g[0] -
            UAM_Flight_control_P.DeadZone_Start_b;
        }

        /* MATLAB Function: '<S1992>/MATLAB Function' incorporates:
         *  Constant: '<S1992>/Constant'
         *  DeadZone: '<S1992>/Dead Zone'
         */
        UAM_Flight_MATLABFunction_b(rtb_Bias_l,
          UAM_Flight_control_P.Constant_Value_k, &rtb_hover_est_l);

        /* DeadZone: '<S1992>/Dead Zone1' */
        if (rtb_TmpSignalConversionAtSFun_g[1] >
            UAM_Flight_control_P.DeadZone1_End) {
          rtb_Bias_l = rtb_TmpSignalConversionAtSFun_g[1] -
            UAM_Flight_control_P.DeadZone1_End;
        } else if (rtb_TmpSignalConversionAtSFun_g[1] >=
                   UAM_Flight_control_P.DeadZone1_Start) {
          rtb_Bias_l = 0.0;
        } else {
          rtb_Bias_l = rtb_TmpSignalConversionAtSFun_g[1] -
            UAM_Flight_control_P.DeadZone1_Start;
        }

        /* MATLAB Function: '<S1992>/MATLAB Function1' incorporates:
         *  Constant: '<S1992>/Constant1'
         *  DeadZone: '<S1992>/Dead Zone1'
         */
        UAM_Flight_MATLABFunction_b(rtb_Bias_l,
          UAM_Flight_control_P.Constant1_Value_o, &rtb_qout_idx_1);

        /* MinMax: '<S1992>/Min' incorporates:
         *  Constant: '<S1992>/Constant2'
         *  Math: '<S1992>/Math Function'
         *  Math: '<S1992>/Math Function1'
         *  Sqrt: '<S1992>/Sqrt'
         *  Sum: '<S1992>/Sum3'
         */
        rtb_qout_idx_2 = fmax(sqrt(rtb_hover_est_l * rtb_hover_est_l +
          rtb_qout_idx_1 * rtb_qout_idx_1),
                              UAM_Flight_control_P.Constant2_Value_n);

        /* Product: '<S1992>/Divide' */
        rtb_qout_idx_3 = rtb_hover_est_l / rtb_qout_idx_2;

        /* RateLimiter: '<S1992>/Rate Limiter' */
        rtb_Bias_l = rtb_qout_idx_3 - UAM_Flight_control_DW.PrevY;
        if (rtb_Bias_l > UAM_Flight_control_P.RateLimiter_RisingLim *
            UAM_Flight_control_period) {
          /* RateLimiter: '<S1992>/Rate Limiter' */
          UAM_Flight_control_DW.PrevY +=
            UAM_Flight_control_P.RateLimiter_RisingLim *
            UAM_Flight_control_period;
        } else if (rtb_Bias_l < UAM_Flight_control_P.RateLimiter_FallingLim *
                   UAM_Flight_control_period) {
          /* RateLimiter: '<S1992>/Rate Limiter' */
          UAM_Flight_control_DW.PrevY +=
            UAM_Flight_control_P.RateLimiter_FallingLim *
            UAM_Flight_control_period;
        } else {
          /* RateLimiter: '<S1992>/Rate Limiter' */
          UAM_Flight_control_DW.PrevY = rtb_qout_idx_3;
        }

        /* End of RateLimiter: '<S1992>/Rate Limiter' */

        /* Logic: '<S1992>/AND' incorporates:
         *  Abs: '<S1992>/Abs'
         *  Abs: '<S1992>/Abs1'
         *  Constant: '<S2438>/Constant'
         *  Constant: '<S2439>/Constant'
         *  RelationalOperator: '<S2438>/Compare'
         *  RelationalOperator: '<S2439>/Compare'
         */
        rtb_XYZ_Valid = ((fabs(rtb_hover_est_l) <
                          UAM_Flight_control_P.CompareToConstant_const_i) &&
                         (fabs(rtb_qout_idx_1) <
                          UAM_Flight_control_P.CompareToConstant1_const));

        /* Trigonometry: '<S1992>/SinCos' */
        rtb_qout_idx_3 = sin(rtb_Gain1[0]);
        rtb_Product_i5 = cos(rtb_Gain1[0]);

        /* RelationalOperator: '<S2665>/Compare' incorporates:
         *  Constant: '<S2665>/Constant'
         */
        rtb_Compare_e5 = !UAM_Flight_control_P.Constant_Value_ga;

        /* RelationalOperator: '<S2666>/Compare' incorporates:
         *  Constant: '<S2666>/Constant'
         */
        rtb_Compare_mc = ((int32_T)rtb_XYZ_Valid > (int32_T)
                          UAM_Flight_control_P.Constant_Value_hg);

        /* Switch: '<S2450>/Switch2' incorporates:
         *  Logic: '<S2450>/OR'
         *  RelationalOperator: '<S2663>/FixPt Relational Operator'
         *  RelationalOperator: '<S2664>/FixPt Relational Operator'
         *  Switch: '<S2450>/Switch1'
         *  UnitDelay: '<S2450>/Unit Delay'
         *  UnitDelay: '<S2450>/Unit Delay1'
         *  UnitDelay: '<S2663>/Delay Input1'
         *  UnitDelay: '<S2664>/Delay Input1'
         *
         * Block description for '<S2663>/Delay Input1':
         *
         *  Store in Global RAM
         *
         * Block description for '<S2664>/Delay Input1':
         *
         *  Store in Global RAM
         */
        if (((int32_T)rtb_Compare_e5 > (int32_T)
             UAM_Flight_control_DW.DelayInput1_DSTATE) || ((int32_T)
             rtb_Compare_mc > (int32_T)
             UAM_Flight_control_DW.DelayInput1_DSTATE_e)) {
          UAM_Flight_control_DW.UnitDelay_DSTATE_i = rtb_Mag_idx_0;
          UAM_Flight_control_DW.UnitDelay1_DSTATE_p = rtb_Mag_idx_1;
        }

        /* End of Switch: '<S2450>/Switch2' */

        /* Sum: '<S1992>/Sum1' incorporates:
         *  UnitDelay: '<S2450>/Unit Delay'
         */
        rtb_hover_est_l = UAM_Flight_control_DW.UnitDelay_DSTATE_i -
          rtb_Mag_idx_0;

        /* Sum: '<S1992>/Sum' incorporates:
         *  UnitDelay: '<S2450>/Unit Delay1'
         */
        rtb_IntegralGain_no = UAM_Flight_control_DW.UnitDelay1_DSTATE_p -
          rtb_Mag_idx_1;

        /* Switch: '<S1992>/Switch' incorporates:
         *  Gain: '<S1992>/Vel_manual(m//s)'
         */
        if (rtb_XYZ_Valid) {
          /* Gain: '<S2596>/Proportional Gain' incorporates:
           *  Gain: '<S2444>/Gain'
           *  Product: '<S2444>/Product'
           *  Product: '<S2444>/Product1'
           *  Sum: '<S2444>/Add'
           */
          rtb_throttle = (rtb_qout_idx_3 * rtb_hover_est_l *
                          UAM_Flight_control_P.Gain_Gain_i + rtb_IntegralGain_no
                          * rtb_Product_i5) *
            UAM_Flight_control_P.controlParams.P_Y;

          /* Saturate: '<S2598>/Saturation' */
          if (rtb_throttle >
              UAM_Flight_control_P.Lateralpositioncontroller_Upper) {
            rtb_throttle = UAM_Flight_control_P.Lateralpositioncontroller_Upper;
          } else if (rtb_throttle <
                     UAM_Flight_control_P.Lateralpositioncontroller_Lower) {
            rtb_throttle = UAM_Flight_control_P.Lateralpositioncontroller_Lower;
          }

          /* End of Saturate: '<S2598>/Saturation' */

          /* Saturate: '<S1992>/Lateral Velocity Setpoint' */
          if (rtb_throttle >
              UAM_Flight_control_P.LateralVelocitySetpoint_UpperSa) {
            rtb_throttle = UAM_Flight_control_P.LateralVelocitySetpoint_UpperSa;
          } else if (rtb_throttle <
                     UAM_Flight_control_P.LateralVelocitySetpoint_LowerSa) {
            rtb_throttle = UAM_Flight_control_P.LateralVelocitySetpoint_LowerSa;
          }

          /* End of Saturate: '<S1992>/Lateral Velocity Setpoint' */
        } else {
          rtb_throttle = UAM_Flight_control_P.Vel_manualms_Gain *
            UAM_Flight_control_DW.PrevY;
        }

        /* End of Switch: '<S1992>/Switch' */

        /* Sum: '<S1992>/Sum5' incorporates:
         *  Gain: '<S2446>/Gain'
         *  Product: '<S2446>/Product'
         *  Product: '<S2446>/Product1'
         *  Sum: '<S2446>/Add'
         */
        rtb_throttle -= rtb_qout_idx_3 * rtb_Kz *
          UAM_Flight_control_P.Gain_Gain_ig + rtb_Kz_f * rtb_Product_i5;

        /* DiscreteIntegrator: '<S2645>/Integrator' */
        if (UAM_Flight_control_DW.Integrator_PrevResetState_i <= 0) {
          UAM_Flight_control_DW.Integrator_DSTATE_f =
            UAM_Flight_control_P.Lateralvelocitycontroller_Ini_k;
        }

        /* DiscreteIntegrator: '<S2640>/Filter' */
        if (UAM_Flight_control_DW.Filter_PrevResetState_l <= 0) {
          UAM_Flight_control_DW.Filter_DSTATE_mr =
            UAM_Flight_control_P.Lateralvelocitycontroller_Initi;
        }

        /* Gain: '<S2648>/Filter Coefficient' incorporates:
         *  DiscreteIntegrator: '<S2640>/Filter'
         *  Gain: '<S2638>/Derivative Gain'
         *  Sum: '<S2640>/SumD'
         */
        rtb_Integrator_o4 = (UAM_Flight_control_P.controlParams.D_VY *
                             rtb_throttle -
                             UAM_Flight_control_DW.Filter_DSTATE_mr) *
          UAM_Flight_control_P.controlParams.N_VY;

        /* Sum: '<S2654>/Sum' incorporates:
         *  DiscreteIntegrator: '<S2645>/Integrator'
         *  Gain: '<S2650>/Proportional Gain'
         */
        rtb_DeadZone_o = (UAM_Flight_control_P.controlParams.P_VY * rtb_throttle
                          + UAM_Flight_control_DW.Integrator_DSTATE_f) +
          rtb_Integrator_o4;

        /* Saturate: '<S2652>/Saturation' */
        if (rtb_DeadZone_o >
            UAM_Flight_control_P.Lateralvelocitycontroller_Upp_b) {
          rtb_Bias_l = UAM_Flight_control_P.Lateralvelocitycontroller_Upp_b;
        } else if (rtb_DeadZone_o <
                   UAM_Flight_control_P.Lateralvelocitycontroller_Low_p) {
          rtb_Bias_l = UAM_Flight_control_P.Lateralvelocitycontroller_Low_p;
        } else {
          rtb_Bias_l = rtb_DeadZone_o;
        }

        /* Gain: '<S1992>/rad' incorporates:
         *  Saturate: '<S2652>/Saturation'
         */
        rtb_Bias_l *= UAM_Flight_control_P.rad_Gain;

        /* Saturate: '<S1992>/Saturation1' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation1_UpperSat_a) {
          /* SignalConversion generated from: '<S1992>/Roll Cmd' incorporates:
           *  Merge: '<S1698>/Ref RP'
           */
          UAM_Flight_control_B.RefRP[0] =
            UAM_Flight_control_P.Saturation1_UpperSat_a;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation1_LowerSat_m) {
          /* SignalConversion generated from: '<S1992>/Roll Cmd' incorporates:
           *  Merge: '<S1698>/Ref RP'
           */
          UAM_Flight_control_B.RefRP[0] =
            UAM_Flight_control_P.Saturation1_LowerSat_m;
        } else {
          /* SignalConversion generated from: '<S1992>/Roll Cmd' incorporates:
           *  Merge: '<S1698>/Ref RP'
           */
          UAM_Flight_control_B.RefRP[0] = rtb_Bias_l;
        }

        /* End of Saturate: '<S1992>/Saturation1' */

        /* DeadZone: '<S2637>/DeadZone' */
        if (rtb_DeadZone_o >
            UAM_Flight_control_P.Lateralvelocitycontroller_Upp_b) {
          rtb_DeadZone_o -= UAM_Flight_control_P.Lateralvelocitycontroller_Upp_b;
        } else if (rtb_DeadZone_o >=
                   UAM_Flight_control_P.Lateralvelocitycontroller_Low_p) {
          rtb_DeadZone_o = 0.0;
        } else {
          rtb_DeadZone_o -= UAM_Flight_control_P.Lateralvelocitycontroller_Low_p;
        }

        /* End of DeadZone: '<S2637>/DeadZone' */

        /* Gain: '<S2642>/Integral Gain' */
        rtb_throttle *= UAM_Flight_control_P.controlParams.I_VY;

        /* Product: '<S1992>/Divide1' */
        rtb_qout_idx_2 = rtb_qout_idx_1 / rtb_qout_idx_2;

        /* RateLimiter: '<S1992>/Rate Limiter1' */
        rtb_Bias_l = rtb_qout_idx_2 - UAM_Flight_control_DW.PrevY_i;
        if (rtb_Bias_l > UAM_Flight_control_P.RateLimiter1_RisingLim *
            UAM_Flight_control_period) {
          rtb_qout_idx_2 = UAM_Flight_control_P.RateLimiter1_RisingLim *
            UAM_Flight_control_period + UAM_Flight_control_DW.PrevY_i;
        } else if (rtb_Bias_l < UAM_Flight_control_P.RateLimiter1_FallingLim *
                   UAM_Flight_control_period) {
          rtb_qout_idx_2 = UAM_Flight_control_P.RateLimiter1_FallingLim *
            UAM_Flight_control_period + UAM_Flight_control_DW.PrevY_i;
        }

        UAM_Flight_control_DW.PrevY_i = rtb_qout_idx_2;

        /* End of RateLimiter: '<S1992>/Rate Limiter1' */

        /* Switch: '<S1992>/Switch1' incorporates:
         *  Gain: '<S1992>/Vel_manual'
         */
        if (rtb_XYZ_Valid) {
          /* Gain: '<S2490>/Proportional Gain' incorporates:
           *  Product: '<S2440>/Product'
           *  Product: '<S2440>/Product1'
           *  Sum: '<S2440>/Add'
           */
          rtb_hover_est_l = (rtb_Product_i5 * rtb_hover_est_l +
                             rtb_IntegralGain_no * rtb_qout_idx_3) *
            UAM_Flight_control_P.controlParams.P_X;

          /* Saturate: '<S1992>/Foward Velocity Setpoint' */
          if (rtb_hover_est_l >
              UAM_Flight_control_P.FowardVelocitySetpoint_UpperSat) {
            rtb_hover_est_l =
              UAM_Flight_control_P.FowardVelocitySetpoint_UpperSat;
          } else if (rtb_hover_est_l <
                     UAM_Flight_control_P.FowardVelocitySetpoint_LowerSat) {
            rtb_hover_est_l =
              UAM_Flight_control_P.FowardVelocitySetpoint_LowerSat;
          }

          /* End of Saturate: '<S1992>/Foward Velocity Setpoint' */
        } else {
          rtb_hover_est_l = UAM_Flight_control_P.Vel_manual_Gain *
            rtb_qout_idx_2;
        }

        /* End of Switch: '<S1992>/Switch1' */

        /* Sum: '<S1992>/Sum4' incorporates:
         *  Product: '<S2442>/Product'
         *  Product: '<S2442>/Product1'
         *  Sum: '<S2442>/Add'
         */
        rtb_hover_est_l -= rtb_Product_i5 * rtb_Kz + rtb_Kz_f * rtb_qout_idx_3;

        /* DiscreteIntegrator: '<S2539>/Integrator' */
        if (UAM_Flight_control_DW.Integrator_PrevResetState_pz <= 0) {
          UAM_Flight_control_DW.Integrator_DSTATE_j3 =
            UAM_Flight_control_P.Forwardvelocitycontroller_Ini_i;
        }

        /* DiscreteIntegrator: '<S2534>/Filter' */
        if (UAM_Flight_control_DW.Filter_PrevResetState_c <= 0) {
          UAM_Flight_control_DW.Filter_DSTATE_a4 =
            UAM_Flight_control_P.Forwardvelocitycontroller_Initi;
        }

        /* Gain: '<S2542>/Filter Coefficient' incorporates:
         *  DiscreteIntegrator: '<S2534>/Filter'
         *  Gain: '<S2532>/Derivative Gain'
         *  Sum: '<S2534>/SumD'
         */
        rtb_qout_idx_1 = (UAM_Flight_control_P.controlParams.D_VX *
                          rtb_hover_est_l -
                          UAM_Flight_control_DW.Filter_DSTATE_a4) *
          UAM_Flight_control_P.controlParams.N_VX;

        /* Sum: '<S2548>/Sum' incorporates:
         *  DiscreteIntegrator: '<S2539>/Integrator'
         *  Gain: '<S2544>/Proportional Gain'
         */
        rtb_IntegralGain_no = (UAM_Flight_control_P.controlParams.P_VX *
          rtb_hover_est_l + UAM_Flight_control_DW.Integrator_DSTATE_j3) +
          rtb_qout_idx_1;

        /* Saturate: '<S2546>/Saturation' */
        if (rtb_IntegralGain_no >
            UAM_Flight_control_P.Forwardvelocitycontroller_Upp_o) {
          rtb_Bias_l = UAM_Flight_control_P.Forwardvelocitycontroller_Upp_o;
        } else if (rtb_IntegralGain_no <
                   UAM_Flight_control_P.Forwardvelocitycontroller_Low_p) {
          rtb_Bias_l = UAM_Flight_control_P.Forwardvelocitycontroller_Low_p;
        } else {
          rtb_Bias_l = rtb_IntegralGain_no;
        }

        /* Gain: '<S1992>/Gain' incorporates:
         *  Saturate: '<S2546>/Saturation'
         */
        rtb_Bias_l *= UAM_Flight_control_P.Gain_Gain_j;

        /* Saturate: '<S1992>/Saturation' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation_UpperSat_e) {
          /* SignalConversion generated from: '<S1992>/Pitch Cmd' incorporates:
           *  Merge: '<S1698>/Ref RP'
           */
          UAM_Flight_control_B.RefRP[1] =
            UAM_Flight_control_P.Saturation_UpperSat_e;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation_LowerSat_f) {
          /* SignalConversion generated from: '<S1992>/Pitch Cmd' incorporates:
           *  Merge: '<S1698>/Ref RP'
           */
          UAM_Flight_control_B.RefRP[1] =
            UAM_Flight_control_P.Saturation_LowerSat_f;
        } else {
          /* SignalConversion generated from: '<S1992>/Pitch Cmd' incorporates:
           *  Merge: '<S1698>/Ref RP'
           */
          UAM_Flight_control_B.RefRP[1] = rtb_Bias_l;
        }

        /* End of Saturate: '<S1992>/Saturation' */

        /* DeadZone: '<S2531>/DeadZone' */
        if (rtb_IntegralGain_no >
            UAM_Flight_control_P.Forwardvelocitycontroller_Upp_o) {
          rtb_IntegralGain_no -=
            UAM_Flight_control_P.Forwardvelocitycontroller_Upp_o;
        } else if (rtb_IntegralGain_no >=
                   UAM_Flight_control_P.Forwardvelocitycontroller_Low_p) {
          rtb_IntegralGain_no = 0.0;
        } else {
          rtb_IntegralGain_no -=
            UAM_Flight_control_P.Forwardvelocitycontroller_Low_p;
        }

        /* End of DeadZone: '<S2531>/DeadZone' */

        /* Gain: '<S2536>/Integral Gain' */
        rtb_hover_est_l *= UAM_Flight_control_P.controlParams.I_VX;

        /* Update for UnitDelay: '<S2663>/Delay Input1'
         *
         * Block description for '<S2663>/Delay Input1':
         *
         *  Store in Global RAM
         */
        UAM_Flight_control_DW.DelayInput1_DSTATE = rtb_Compare_e5;

        /* Update for UnitDelay: '<S2664>/Delay Input1'
         *
         * Block description for '<S2664>/Delay Input1':
         *
         *  Store in Global RAM
         */
        UAM_Flight_control_DW.DelayInput1_DSTATE_e = rtb_Compare_mc;

        /* Switch: '<S2635>/Switch1' incorporates:
         *  Constant: '<S2635>/Clamping_zero'
         *  Constant: '<S2635>/Constant'
         *  Constant: '<S2635>/Constant2'
         *  RelationalOperator: '<S2635>/fix for DT propagation issue'
         */
        if (rtb_DeadZone_o > UAM_Flight_control_P.Clamping_zero_Value_b) {
          rtAction = UAM_Flight_control_P.Constant_Value_nq;
        } else {
          rtAction = UAM_Flight_control_P.Constant2_Value_g;
        }

        /* Switch: '<S2635>/Switch2' incorporates:
         *  Constant: '<S2635>/Clamping_zero'
         *  Constant: '<S2635>/Constant3'
         *  Constant: '<S2635>/Constant4'
         *  RelationalOperator: '<S2635>/fix for DT propagation issue1'
         */
        if (rtb_throttle > UAM_Flight_control_P.Clamping_zero_Value_b) {
          tmp_1 = UAM_Flight_control_P.Constant3_Value_od;
        } else {
          tmp_1 = UAM_Flight_control_P.Constant4_Value_h;
        }

        /* Switch: '<S2635>/Switch' incorporates:
         *  Constant: '<S2635>/Clamping_zero'
         *  Constant: '<S2635>/Constant1'
         *  Logic: '<S2635>/AND3'
         *  RelationalOperator: '<S2635>/Equal1'
         *  RelationalOperator: '<S2635>/Relational Operator'
         *  Switch: '<S2635>/Switch1'
         *  Switch: '<S2635>/Switch2'
         */
        if ((UAM_Flight_control_P.Clamping_zero_Value_b != rtb_DeadZone_o) &&
            (rtAction == tmp_1)) {
          rtb_throttle = UAM_Flight_control_P.Constant1_Value_h;
        }

        /* Update for DiscreteIntegrator: '<S2645>/Integrator' incorporates:
         *  Switch: '<S2635>/Switch'
         */
        UAM_Flight_control_DW.Integrator_DSTATE_f +=
          UAM_Flight_control_P.Integrator_gainval_d * rtb_throttle;
        if (UAM_Flight_control_DW.Integrator_DSTATE_f >
            UAM_Flight_control_P.Lateralvelocitycontroller_Upper) {
          UAM_Flight_control_DW.Integrator_DSTATE_f =
            UAM_Flight_control_P.Lateralvelocitycontroller_Upper;
        } else if (UAM_Flight_control_DW.Integrator_DSTATE_f <
                   UAM_Flight_control_P.Lateralvelocitycontroller_Lower) {
          UAM_Flight_control_DW.Integrator_DSTATE_f =
            UAM_Flight_control_P.Lateralvelocitycontroller_Lower;
        }

        UAM_Flight_control_DW.Integrator_PrevResetState_i = 1;

        /* End of Update for DiscreteIntegrator: '<S2645>/Integrator' */

        /* Update for DiscreteIntegrator: '<S2640>/Filter' */
        UAM_Flight_control_DW.Filter_DSTATE_mr +=
          UAM_Flight_control_P.Filter_gainval_i * rtb_Integrator_o4;
        UAM_Flight_control_DW.Filter_PrevResetState_l = 1;

        /* Switch: '<S2529>/Switch1' incorporates:
         *  Constant: '<S2529>/Clamping_zero'
         *  Constant: '<S2529>/Constant'
         *  Constant: '<S2529>/Constant2'
         *  RelationalOperator: '<S2529>/fix for DT propagation issue'
         */
        if (rtb_IntegralGain_no > UAM_Flight_control_P.Clamping_zero_Value_p) {
          rtAction = UAM_Flight_control_P.Constant_Value_pl;
        } else {
          rtAction = UAM_Flight_control_P.Constant2_Value_ah;
        }

        /* Switch: '<S2529>/Switch2' incorporates:
         *  Constant: '<S2529>/Clamping_zero'
         *  Constant: '<S2529>/Constant3'
         *  Constant: '<S2529>/Constant4'
         *  RelationalOperator: '<S2529>/fix for DT propagation issue1'
         */
        if (rtb_hover_est_l > UAM_Flight_control_P.Clamping_zero_Value_p) {
          tmp_1 = UAM_Flight_control_P.Constant3_Value_p;
        } else {
          tmp_1 = UAM_Flight_control_P.Constant4_Value_m;
        }

        /* Switch: '<S2529>/Switch' incorporates:
         *  Constant: '<S2529>/Clamping_zero'
         *  Constant: '<S2529>/Constant1'
         *  Logic: '<S2529>/AND3'
         *  RelationalOperator: '<S2529>/Equal1'
         *  RelationalOperator: '<S2529>/Relational Operator'
         *  Switch: '<S2529>/Switch1'
         *  Switch: '<S2529>/Switch2'
         */
        if ((UAM_Flight_control_P.Clamping_zero_Value_p != rtb_IntegralGain_no) &&
            (rtAction == tmp_1)) {
          rtb_hover_est_l = UAM_Flight_control_P.Constant1_Value_g;
        }

        /* Update for DiscreteIntegrator: '<S2539>/Integrator' incorporates:
         *  Switch: '<S2529>/Switch'
         */
        UAM_Flight_control_DW.Integrator_DSTATE_j3 +=
          UAM_Flight_control_P.Integrator_gainval_i * rtb_hover_est_l;
        if (UAM_Flight_control_DW.Integrator_DSTATE_j3 >
            UAM_Flight_control_P.Forwardvelocitycontroller_Upper) {
          UAM_Flight_control_DW.Integrator_DSTATE_j3 =
            UAM_Flight_control_P.Forwardvelocitycontroller_Upper;
        } else if (UAM_Flight_control_DW.Integrator_DSTATE_j3 <
                   UAM_Flight_control_P.Forwardvelocitycontroller_Lower) {
          UAM_Flight_control_DW.Integrator_DSTATE_j3 =
            UAM_Flight_control_P.Forwardvelocitycontroller_Lower;
        }

        UAM_Flight_control_DW.Integrator_PrevResetState_pz = 1;

        /* End of Update for DiscreteIntegrator: '<S2539>/Integrator' */

        /* Update for DiscreteIntegrator: '<S2534>/Filter' */
        UAM_Flight_control_DW.Filter_DSTATE_a4 +=
          UAM_Flight_control_P.Filter_gainval_j * rtb_qout_idx_1;
        UAM_Flight_control_DW.Filter_PrevResetState_c = 1;
      } else {
        UAM_Flight_control_DW.HorizontalPositionControl1_MODE = false;
      }

      /* End of Outputs for SubSystem: '<S1698>/Horizontal Position Control1' */

      /* Logic: '<S1698>/XYZ_nan' */
      rtb_IsNaN2 = (rtb_IsNaN2 && rtb_IsNaN1 && rtb_IsNaN);

      /* Outputs for Enabled SubSystem: '<S1698>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S1991>/Enable'
       */
      if (rtb_Compare_j || rtb_IsNaN2) {
        /* SignalConversion generated from: '<S1991>/Roll Cmd' incorporates:
         *  Merge: '<S1698>/Ref RP'
         *  SignalConversion generated from: '<S1991>/XRef'
         */
        UAM_Flight_control_B.RefRP[0] = rtb_TmpSignalConversionAtSFun_g[0];

        /* SignalConversion generated from: '<S1991>/Pitch Cmd' incorporates:
         *  Merge: '<S1698>/Ref RP'
         *  SignalConversion generated from: '<S1991>/YRef'
         */
        UAM_Flight_control_B.RefRP[1] = rtb_TmpSignalConversionAtSFun_g[1];
      }

      /* End of Outputs for SubSystem: '<S1698>/Enabled Subsystem' */

      /* Gain: '<S1990>/Pitch_MAX_angle' incorporates:
       *  Logic: '<S1698>/OR'
       */
      rtb_Bias_l = UAM_Flight_control_P.Pitch_MAX_angle_Gain *
        UAM_Flight_control_B.RefRP[1];

      /* Saturate: '<S1990>/Saturation1' */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation1_UpperSat_g) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation1_UpperSat_g;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation1_LowerSat_b) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation1_LowerSat_b;
      }

      /* Sum: '<S1990>/Sum2' incorporates:
       *  Gain: '<S2159>/Proportional Gain'
       *  Inport: '<Root>/fcc'
       *  Saturate: '<S1990>/Saturation1'
       *  SignalConversion generated from: '<Root>/fcc'
       *  Sum: '<S1990>/Sum5'
       *  UnaryMinus: '<S1990>/Unary Minus'
       *  UnaryMinus: '<S1990>/Unary Minus1'
       */
      rtb_qout_idx_1 = (rtb_Bias_l - (-rtb_Gain1[1])) *
        UAM_Flight_control_P.controlParams.RC_P_PITCH -
        (-UAM_Flight_control_U.fcc.gyro_y);

      /* Gain: '<S2203>/Integral Gain' */
      rtb_IntegralGain_no = UAM_Flight_control_P.controlParams.RC_I_PITCH_RATE *
        rtb_qout_idx_1;

      /* Gain: '<S2209>/Filter Coefficient' incorporates:
       *  DiscreteIntegrator: '<S2201>/Filter'
       *  Gain: '<S2199>/Derivative Gain'
       *  Sum: '<S2201>/SumD'
       */
      rtb_throttle = (UAM_Flight_control_P.controlParams.RC_D_PITCH_RATE *
                      rtb_qout_idx_1 - UAM_Flight_control_DW.Filter_DSTATE_c5) *
        UAM_Flight_control_P.controlParams.RC_N_PITCH_RATE;

      /* Gain: '<S1990>/Roll_MAX_angle' */
      rtb_Bias_l = UAM_Flight_control_P.Roll_MAX_angle_Gain *
        UAM_Flight_control_B.RefRP[0];

      /* Saturate: '<S1990>/Saturation' */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation_UpperSat_d) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation_UpperSat_d;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation_LowerSat_p) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation_LowerSat_p;
      }

      /* Sum: '<S1990>/Sum1' incorporates:
       *  Gain: '<S2263>/Proportional Gain'
       *  Inport: '<Root>/fcc'
       *  Saturate: '<S1990>/Saturation'
       *  SignalConversion generated from: '<Root>/fcc'
       *  Sum: '<S1990>/Sum'
       */
      rtb_Bias_l = (rtb_Bias_l - rtb_Gain1[2]) *
        UAM_Flight_control_P.controlParams.RC_P_ROLL -
        UAM_Flight_control_U.fcc.gyro_x;

      /* Gain: '<S2307>/Integral Gain' */
      rtb_Integrator_o4 = UAM_Flight_control_P.controlParams.RC_I_ROLL_RATE *
        rtb_Bias_l;

      /* Gain: '<S2313>/Filter Coefficient' incorporates:
       *  DiscreteIntegrator: '<S2305>/Filter'
       *  Gain: '<S2303>/Derivative Gain'
       *  Sum: '<S2305>/SumD'
       */
      rtb_DeadZone_o = (UAM_Flight_control_P.controlParams.RC_D_ROLL_RATE *
                        rtb_Bias_l - UAM_Flight_control_DW.Filter_DSTATE_nj) *
        UAM_Flight_control_P.controlParams.RC_N_ROLL_RATE;

      /* Gain: '<S2411>/Integral Gain' */
      rtb_hover_est_l = UAM_Flight_control_P.controlParams.RC_I_YAW_RATE *
        rtb_qout_idx_0;

      /* SignalConversion generated from: '<S1698>/MixerCommands' incorporates:
       *  DiscreteIntegrator: '<S2310>/Integrator'
       *  Gain: '<S2315>/Proportional Gain'
       *  Sum: '<S2319>/Sum'
       */
      UAM_Flight_control_B.w_phi_d =
        (UAM_Flight_control_P.controlParams.RC_P_ROLL_RATE * rtb_Bias_l +
         UAM_Flight_control_DW.Integrator_DSTATE_m) + rtb_DeadZone_o;

      /* SignalConversion generated from: '<S1698>/MixerCommands' incorporates:
       *  DiscreteIntegrator: '<S2206>/Integrator'
       *  Gain: '<S2211>/Proportional Gain'
       *  Sum: '<S2215>/Sum'
       */
      UAM_Flight_control_B.w_theta_i =
        (UAM_Flight_control_P.controlParams.RC_P_PITCH_RATE * rtb_qout_idx_1 +
         UAM_Flight_control_DW.Integrator_DSTATE_jv) + rtb_throttle;

      /* Gain: '<S1990>/Gain1' incorporates:
       *  DiscreteIntegrator: '<S2414>/Integrator'
       *  Gain: '<S2419>/Proportional Gain'
       *  Sum: '<S2423>/Sum'
       */
      UAM_Flight_control_B.w_psi_f =
        (UAM_Flight_control_P.controlParams.RC_P_YAW_RATE * rtb_qout_idx_0 +
         UAM_Flight_control_DW.Integrator_DSTATE_n) *
        UAM_Flight_control_P.Gain1_Gain_k5;

      /* Saturate: '<S1990>/Saturation5' */
      if (UAM_Flight_control_B.w_psi_f >
          UAM_Flight_control_P.Saturation5_UpperSat) {
        /* Gain: '<S1990>/Gain1' incorporates:
         *  SignalConversion generated from: '<S1698>/MixerCommands'
         */
        UAM_Flight_control_B.w_psi_f = UAM_Flight_control_P.Saturation5_UpperSat;
      } else if (UAM_Flight_control_B.w_psi_f <
                 UAM_Flight_control_P.Saturation5_LowerSat) {
        /* Gain: '<S1990>/Gain1' incorporates:
         *  SignalConversion generated from: '<S1698>/MixerCommands'
         */
        UAM_Flight_control_B.w_psi_f = UAM_Flight_control_P.Saturation5_LowerSat;
      }

      /* End of Saturate: '<S1990>/Saturation5' */

      /* Outputs for Enabled SubSystem: '<S1698>/Subsystem' incorporates:
       *  EnablePort: '<S1995>/Enable'
       */
      if (rtb_IsNaN2) {
        /* Merge: '<S1698>/Merge2' incorporates:
         *  SignalConversion generated from: '<S1995>/In1'
         *  SignalConversion generated from: '<S1995>/Out1'
         */
        UAM_Flight_control_B.Merge2 = s;
      }

      /* End of Outputs for SubSystem: '<S1698>/Subsystem' */

      /* SignalConversion generated from: '<S1698>/MixerCommands' */
      UAM_Flight_control_B.w_z_c = UAM_Flight_control_B.Merge2;

      /* MATLAB Function: '<S1701>/MATLAB Function' */
      UAM_Flight_MATLABFunction_a(rtb_Gain1[2], rtb_Gain1[1], rtb_R);

      /* Outputs for Enabled SubSystem: '<S1699>/Attitude Controller' incorporates:
       *  EnablePort: '<S1700>/Enable'
       */
      if (UAM_Flight_control_B.controlMode_h.attitude > 0) {
        /* Outputs for Enabled SubSystem: '<S1700>/Pitch Roll Controller' incorporates:
         *  EnablePort: '<S1706>/Enable'
         */
        if (UAM_Flight_control_B.controlMode_h.attitude ==
            UAM_Flight_control_P.CompareToConstant_const_a) {
          /* Gain: '<S1704>/Gain1' incorporates:
           *  Bias: '<S1704>/Bias'
           *  Gain: '<S1704>/Gain'
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           */
          rtb_qout_idx_2 = (UAM_Flight_control_U.fcc.rc[1] +
                            UAM_Flight_control_P.Bias_Bias_k) *
            UAM_Flight_control_P.Gain_Gain_g * UAM_Flight_control_P.Gain1_Gain_d;

          /* Saturate: '<S1706>/Saturation1' */
          if (rtb_qout_idx_2 > UAM_Flight_control_P.control.maxPitch) {
            rtb_qout_idx_2 = UAM_Flight_control_P.control.maxPitch;
          } else if (rtb_qout_idx_2 < UAM_Flight_control_P.control.minPitch) {
            rtb_qout_idx_2 = UAM_Flight_control_P.control.minPitch;
          }

          /* End of Saturate: '<S1706>/Saturation1' */

          /* Sum: '<S1706>/Sum' */
          s = rtb_qout_idx_2 - rtb_Gain1[1];

          /* Gain: '<S1751>/Filter Coefficient' incorporates:
           *  DiscreteIntegrator: '<S1743>/Filter'
           *  Gain: '<S1741>/Derivative Gain'
           *  Sum: '<S1743>/SumD'
           */
          rtb_qout_idx_0 = (UAM_Flight_control_P.FWControlParams.D_FW_PITCH * s
                            - UAM_Flight_control_DW.Filter_DSTATE_px) *
            UAM_Flight_control_P.FWControlParams.N_FW_PITCH;

          /* Sum: '<S1757>/Sum' incorporates:
           *  DiscreteIntegrator: '<S1748>/Integrator'
           *  Gain: '<S1753>/Proportional Gain'
           */
          rtb_qout_idx_1 = (UAM_Flight_control_P.FWControlParams.P_FW_PITCH * s
                            + UAM_Flight_control_DW.Integrator_DSTATE_p) +
            rtb_qout_idx_0;

          /* Saturate: '<S1755>/Saturation' */
          if (rtb_qout_idx_1 >
              UAM_Flight_control_P.PitchAngleController_UpperSatur) {
            rtb_Bias_l = UAM_Flight_control_P.PitchAngleController_UpperSatur;
          } else if (rtb_qout_idx_1 <
                     UAM_Flight_control_P.PitchAngleController_LowerSatur) {
            rtb_Bias_l = UAM_Flight_control_P.PitchAngleController_LowerSatur;
          } else {
            rtb_Bias_l = rtb_qout_idx_1;
          }

          /* Gain: '<S1805>/Proportional Gain' incorporates:
           *  Inport: '<Root>/fcc'
           *  Saturate: '<S1755>/Saturation'
           *  SignalConversion generated from: '<Root>/fcc'
           *  Sum: '<S1706>/Sum3'
           */
          rtb_Bias_l = (rtb_Bias_l - UAM_Flight_control_U.fcc.gyro_y) *
            UAM_Flight_control_P.FWControlParams.P_FW_PITCHRATE;

          /* Saturate: '<S1807>/Saturation' */
          if (rtb_Bias_l > UAM_Flight_control_P.PitchRateController_UpperSatura)
          {
            rtb_Bias_l = UAM_Flight_control_P.PitchRateController_UpperSatura;
          } else if (rtb_Bias_l <
                     UAM_Flight_control_P.PitchRateController_LowerSatura) {
            rtb_Bias_l = UAM_Flight_control_P.PitchRateController_LowerSatura;
          }

          /* End of Saturate: '<S1807>/Saturation' */

          /* UnaryMinus: '<S1706>/Unary Minus1' */
          rtb_qout_idx_3 = -rtb_Bias_l;

          /* Gain: '<S1703>/Gain1' incorporates:
           *  Bias: '<S1703>/Bias'
           *  Gain: '<S1703>/Gain'
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           */
          rtb_Product_i5 = (UAM_Flight_control_U.fcc.rc[0] +
                            UAM_Flight_control_P.Bias_Bias) *
            UAM_Flight_control_P.Gain_Gain * UAM_Flight_control_P.Gain1_Gain;

          /* Saturate: '<S1706>/Saturation' */
          if (rtb_Product_i5 > UAM_Flight_control_P.control.maxRoll) {
            rtb_Product_i5 = UAM_Flight_control_P.control.maxRoll;
          } else if (rtb_Product_i5 < UAM_Flight_control_P.control.minRoll) {
            rtb_Product_i5 = UAM_Flight_control_P.control.minRoll;
          }

          /* End of Saturate: '<S1706>/Saturation' */

          /* MATLAB Function: '<S1711>/MATLAB Function' incorporates:
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           */
          UAM_Flight_c_MATLABFunction(rtb_Product_i5, rtb_qout_idx_2,
            UAM_Flight_control_U.fcc.airspeed, &rtb_Bias_l);

          /* Gain: '<S1963>/Proportional Gain' incorporates:
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           *  Sum: '<S1711>/Sum'
           */
          rtb_Bias_l = (rtb_Bias_l - UAM_Flight_control_U.fcc.gyro_z) *
            UAM_Flight_control_P.RudderController_P;

          /* Saturate: '<S1965>/Saturation' */
          if (rtb_Bias_l > UAM_Flight_control_P.RudderController_UpperSaturatio)
          {
            rtb_Bias_l = UAM_Flight_control_P.RudderController_UpperSaturatio;
          } else if (rtb_Bias_l <
                     UAM_Flight_control_P.RudderController_LowerSaturatio) {
            rtb_Bias_l = UAM_Flight_control_P.RudderController_LowerSaturatio;
          }

          /* Product: '<S1706>/Matrix Multiply' incorporates:
           *  Constant: '<S1706>/Constant'
           *  Saturate: '<S1965>/Saturation'
           *  SignalConversion generated from: '<S1706>/Matrix Multiply'
           */
          UAM_Flight_control_B.MatrixMultiply[0] =
            UAM_Flight_control_P.Constant_Value[0] * rtb_qout_idx_3 +
            UAM_Flight_control_P.Constant_Value[2] * rtb_Bias_l;
          UAM_Flight_control_B.MatrixMultiply[1] =
            UAM_Flight_control_P.Constant_Value[1] * rtb_qout_idx_3 +
            UAM_Flight_control_P.Constant_Value[3] * rtb_Bias_l;

          /* Gain: '<S1857>/Proportional Gain' incorporates:
           *  Sum: '<S1706>/Sum1'
           */
          rtb_Bias_l = (rtb_Product_i5 - rtb_Gain1[2]) *
            UAM_Flight_control_P.FWControlParams.P_FW_ROLL;

          /* Saturate: '<S1859>/Saturation' */
          if (rtb_Bias_l > UAM_Flight_control_P.control.maxRollRate) {
            rtb_Bias_l = UAM_Flight_control_P.control.maxRollRate;
          } else if (rtb_Bias_l < UAM_Flight_control_P.control.minRollRate) {
            rtb_Bias_l = UAM_Flight_control_P.control.minRollRate;
          }

          /* Gain: '<S1909>/Proportional Gain' incorporates:
           *  Inport: '<Root>/fcc'
           *  Saturate: '<S1859>/Saturation'
           *  SignalConversion generated from: '<Root>/fcc'
           *  Sum: '<S1706>/Sum2'
           */
          UAM_Flight_control_B.Saturation2_n = (rtb_Bias_l -
            UAM_Flight_control_U.fcc.gyro_x) *
            UAM_Flight_control_P.FWControlParams.P_FW_ROLLRATE;

          /* Saturate: '<S1911>/Saturation' */
          if (UAM_Flight_control_B.Saturation2_n >
              UAM_Flight_control_P.RollRateController_UpperSaturat) {
            /* Gain: '<S1909>/Proportional Gain' */
            UAM_Flight_control_B.Saturation2_n =
              UAM_Flight_control_P.RollRateController_UpperSaturat;
          } else if (UAM_Flight_control_B.Saturation2_n <
                     UAM_Flight_control_P.RollRateController_LowerSaturat) {
            /* Gain: '<S1909>/Proportional Gain' */
            UAM_Flight_control_B.Saturation2_n =
              UAM_Flight_control_P.RollRateController_LowerSaturat;
          }

          /* End of Saturate: '<S1911>/Saturation' */

          /* Saturate: '<S1706>/Saturation2' */
          if (UAM_Flight_control_B.Saturation2_n >
              UAM_Flight_control_P.Saturation2_UpperSat) {
            /* Gain: '<S1909>/Proportional Gain' incorporates:
             *  Saturate: '<S1706>/Saturation2'
             */
            UAM_Flight_control_B.Saturation2_n =
              UAM_Flight_control_P.Saturation2_UpperSat;
          } else if (UAM_Flight_control_B.Saturation2_n <
                     UAM_Flight_control_P.Saturation2_LowerSat) {
            /* Gain: '<S1909>/Proportional Gain' incorporates:
             *  Saturate: '<S1706>/Saturation2'
             */
            UAM_Flight_control_B.Saturation2_n =
              UAM_Flight_control_P.Saturation2_LowerSat;
          }

          /* End of Saturate: '<S1706>/Saturation2' */

          /* DeadZone: '<S1740>/DeadZone' */
          if (rtb_qout_idx_1 >
              UAM_Flight_control_P.PitchAngleController_UpperSatur) {
            rtb_qout_idx_1 -=
              UAM_Flight_control_P.PitchAngleController_UpperSatur;
          } else if (rtb_qout_idx_1 >=
                     UAM_Flight_control_P.PitchAngleController_LowerSatur) {
            rtb_qout_idx_1 = 0.0;
          } else {
            rtb_qout_idx_1 -=
              UAM_Flight_control_P.PitchAngleController_LowerSatur;
          }

          /* End of DeadZone: '<S1740>/DeadZone' */

          /* Gain: '<S1745>/Integral Gain' */
          s *= UAM_Flight_control_P.FWControlParams.I_FW_PITCH;

          /* Switch: '<S1738>/Switch1' incorporates:
           *  Constant: '<S1738>/Clamping_zero'
           *  Constant: '<S1738>/Constant'
           *  Constant: '<S1738>/Constant2'
           *  RelationalOperator: '<S1738>/fix for DT propagation issue'
           */
          if (rtb_qout_idx_1 > UAM_Flight_control_P.Clamping_zero_Value) {
            rtAction = UAM_Flight_control_P.Constant_Value_jf;
          } else {
            rtAction = UAM_Flight_control_P.Constant2_Value_h3;
          }

          /* Switch: '<S1738>/Switch2' incorporates:
           *  Constant: '<S1738>/Clamping_zero'
           *  Constant: '<S1738>/Constant3'
           *  Constant: '<S1738>/Constant4'
           *  RelationalOperator: '<S1738>/fix for DT propagation issue1'
           */
          if (s > UAM_Flight_control_P.Clamping_zero_Value) {
            tmp_1 = UAM_Flight_control_P.Constant3_Value_c;
          } else {
            tmp_1 = UAM_Flight_control_P.Constant4_Value_c;
          }

          /* Switch: '<S1738>/Switch' incorporates:
           *  Constant: '<S1738>/Clamping_zero'
           *  Constant: '<S1738>/Constant1'
           *  Logic: '<S1738>/AND3'
           *  RelationalOperator: '<S1738>/Equal1'
           *  RelationalOperator: '<S1738>/Relational Operator'
           *  Switch: '<S1738>/Switch1'
           *  Switch: '<S1738>/Switch2'
           */
          if ((UAM_Flight_control_P.Clamping_zero_Value != rtb_qout_idx_1) &&
              (rtAction == tmp_1)) {
            s = UAM_Flight_control_P.Constant1_Value_l;
          }

          /* Update for DiscreteIntegrator: '<S1748>/Integrator' incorporates:
           *  Switch: '<S1738>/Switch'
           */
          UAM_Flight_control_DW.Integrator_DSTATE_p +=
            UAM_Flight_control_P.Integrator_gainval * s;

          /* Update for DiscreteIntegrator: '<S1743>/Filter' */
          UAM_Flight_control_DW.Filter_DSTATE_px +=
            UAM_Flight_control_P.Filter_gainval * rtb_qout_idx_0;
        }

        /* End of Outputs for SubSystem: '<S1700>/Pitch Roll Controller' */
      }

      /* End of Outputs for SubSystem: '<S1699>/Attitude Controller' */

      /* SignalConversion generated from: '<S1696>/Actuator' incorporates:
       *  Constant: '<S1705>/Constant'
       *  RelationalOperator: '<S1705>/Compare'
       */
      UAM_Flight_control_B.dA_n = UAM_Flight_control_B.Saturation2_n;

      /* SignalConversion generated from: '<S1696>/Actuator' */
      UAM_Flight_control_B.dE_a = UAM_Flight_control_B.MatrixMultiply[0];

      /* SignalConversion generated from: '<S1696>/Actuator' */
      UAM_Flight_control_B.dR_g = UAM_Flight_control_B.MatrixMultiply[1];

      /* SignalConversion generated from: '<S1696>/Actuator' incorporates:
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      UAM_Flight_control_B.dT_i = UAM_Flight_control_U.fcc.rc[2];
      UAM_Flight_control_DW.Scheduler_MODE_p = true;

      /* SwitchCase: '<S1977>/Switch Case' */
      switch (UAM_Flight_control_B.FlightMode) {
       case Hover:
        /* Outputs for IfAction SubSystem: '<S1977>/Switch Case Action Subsystem' incorporates:
         *  ActionPort: '<S1979>/Action Port'
         */
        U_SwitchCaseActionSubsystem(&UAM_Flight_control_B.Merge_d,
          &UAM_Flight_control_P.SwitchCaseActionSubsystem_kk);

        /* End of Outputs for SubSystem: '<S1977>/Switch Case Action Subsystem' */
        break;

       case Transition:
        /* Outputs for IfAction SubSystem: '<S1977>/Switch Case Action Subsystem1' incorporates:
         *  ActionPort: '<S1980>/Action Port'
         */
        SwitchCaseActionSubsystem1
          (UAM_Flight_control_B.controlMode_h.TransitionCondition,
           &UAM_Flight_control_B.Merge_d,
           &UAM_Flight_control_P.SwitchCaseActionSubsystem1_e);

        /* End of Outputs for SubSystem: '<S1977>/Switch Case Action Subsystem1' */
        break;

       case FixedWing:
        /* Outputs for IfAction SubSystem: '<S1977>/Switch Case Action Subsystem2' incorporates:
         *  ActionPort: '<S1981>/Action Port'
         */
        SwitchCaseActionSubsystem2(UAM_Flight_control_B.dA_n,
          UAM_Flight_control_B.dE_a, UAM_Flight_control_B.dR_g,
          UAM_Flight_control_B.dT_i, &UAM_Flight_control_B.Merge_d);

        /* End of Outputs for SubSystem: '<S1977>/Switch Case Action Subsystem2' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S1977>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S1982>/Action Port'
         */
        U_SwitchCaseActionSubsystem(&UAM_Flight_control_B.Merge_d,
          &UAM_Flight_control_P.SwitchCaseActionSubsystem3);

        /* End of Outputs for SubSystem: '<S1977>/Switch Case Action Subsystem3' */
        break;
      }

      /* End of SwitchCase: '<S1977>/Switch Case' */

      /* SignalConversion generated from: '<S1697>/CtrlSurfaceCommands' */
      UAM_Flight_control_B.OutportBufferForCtrlSurfaceC_i5 =
        UAM_Flight_control_B.Merge_d;

      /* SwitchCase: '<S1978>/Switch Case' */
      if (UAM_Flight_control_B.FlightMode == Hover) {
        /* Outputs for IfAction SubSystem: '<S1978>/Switch Case Action Subsystem' incorporates:
         *  ActionPort: '<S1984>/Action Port'
         */
        /* MATLAB Function: '<S1984>/Desaturation' incorporates:
         *  Constant: '<S1984>/Constant'
         *  Product: '<S1984>/Matrix Multiply'
         *  SignalConversion generated from: '<S1984>/Matrix Multiply'
         */
        for (i = 0; i < 4; i++) {
          rtb_dq[i] = ((UAM_Flight_control_P.Constant_Value_m[i + 4] *
                        UAM_Flight_control_B.w_phi_d +
                        UAM_Flight_control_P.Constant_Value_m[i] *
                        UAM_Flight_control_B.w_z_c) +
                       UAM_Flight_control_P.Constant_Value_m[i + 8] *
                       UAM_Flight_control_B.w_theta_i) +
            UAM_Flight_control_P.Constant_Value_m[i + 12] *
            UAM_Flight_control_B.w_psi_f;
          tmp[i] = 0.0;
          tmp_0[i] = 1.0;
        }

        UAM_Flight_control_desat_axis(rtb_dq,
          &UAM_Flight_control_P.Constant_Value_m[0], tmp, tmp_0, false);
        tmp[0] = 0.0;
        tmp_0[0] = 1.15;
        tmp[1] = 0.0;
        tmp_0[1] = 1.15;
        tmp[2] = 0.0;
        tmp_0[2] = 1.15;
        tmp[3] = 0.0;
        tmp_0[3] = 1.15;
        UAM_Flight_control_desat_axis(rtb_dq,
          &UAM_Flight_control_P.Constant_Value_m[12], tmp, tmp_0, false);
        tmp[0] = 0.0;
        tmp_0[0] = 1.0;
        tmp[1] = 0.0;
        tmp_0[1] = 1.0;
        tmp[2] = 0.0;
        tmp_0[2] = 1.0;
        tmp[3] = 0.0;
        tmp_0[3] = 1.0;
        UAM_Flight_control_desat_axis(rtb_dq,
          &UAM_Flight_control_P.Constant_Value_m[0], tmp, tmp_0, true);
        UAM_Flight_control_B.m_out[0] = fmax(0.0, fmin(1.0, rtb_dq[0]));
        UAM_Flight_control_B.m_out[1] = fmax(0.0, fmin(1.0, rtb_dq[1]));
        UAM_Flight_control_B.m_out[2] = fmax(0.0, fmin(1.0, rtb_dq[2]));
        UAM_Flight_control_B.m_out[3] = fmax(0.0, fmin(1.0, rtb_dq[3]));

        /* End of MATLAB Function: '<S1984>/Desaturation' */

        /* SignalConversion generated from: '<S1984>/Constant4' incorporates:
         *  Constant: '<S1984>/Constant4'
         */
        UAM_Flight_control_B.TmpBufferAtConstant4Outport1 =
          UAM_Flight_control_P.Constant4_Value;

        /* End of Outputs for SubSystem: '<S1978>/Switch Case Action Subsystem' */
      }

      /* End of SwitchCase: '<S1978>/Switch Case' */
      UAM_Flight_control_B.VectorConcatenate_c[5] =
        UAM_Flight_control_P.Constant_Value_d;

      /* Sum: '<S1983>/Add1' incorporates:
       *  Concatenate: '<S1983>/Vector Concatenate'
       *  Constant: '<S1983>/Constant'
       *  Constant: '<S1983>/Constant2'
       *  Gain: '<S1983>/Gain1'
       */
      rtb_Bias_l = UAM_Flight_control_P.Gain1_Gain_e *
        UAM_Flight_control_B.m_out[0] + UAM_Flight_control_P.Constant2_Value_j;

      /* Saturate: '<S1983>/Saturation' incorporates:
       *  Concatenate: '<S1983>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation_UpperSat) {
        UAM_Flight_control_B.VectorConcatenate_c[0] =
          UAM_Flight_control_P.Saturation_UpperSat;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation_LowerSat) {
        UAM_Flight_control_B.VectorConcatenate_c[0] =
          UAM_Flight_control_P.Saturation_LowerSat;
      } else {
        UAM_Flight_control_B.VectorConcatenate_c[0] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1983>/Saturation' */

      /* Sum: '<S1983>/Add3' incorporates:
       *  Constant: '<S1983>/Constant4'
       *  Gain: '<S1983>/Gain3'
       */
      rtb_Bias_l = UAM_Flight_control_P.Gain3_Gain * UAM_Flight_control_B.m_out
        [1] + UAM_Flight_control_P.Constant4_Value_i;

      /* Saturate: '<S1983>/Saturation1' incorporates:
       *  Concatenate: '<S1983>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation1_UpperSat) {
        UAM_Flight_control_B.VectorConcatenate_c[1] =
          UAM_Flight_control_P.Saturation1_UpperSat;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation1_LowerSat) {
        UAM_Flight_control_B.VectorConcatenate_c[1] =
          UAM_Flight_control_P.Saturation1_LowerSat;
      } else {
        UAM_Flight_control_B.VectorConcatenate_c[1] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1983>/Saturation1' */

      /* Sum: '<S1983>/Add7' incorporates:
       *  Constant: '<S1983>/Constant8'
       *  Gain: '<S1983>/Gain7'
       */
      rtb_Bias_l = UAM_Flight_control_P.Gain7_Gain * UAM_Flight_control_B.m_out
        [2] + UAM_Flight_control_P.Constant8_Value;

      /* Saturate: '<S1983>/Saturation2' incorporates:
       *  Concatenate: '<S1983>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation2_UpperSat_b) {
        UAM_Flight_control_B.VectorConcatenate_c[2] =
          UAM_Flight_control_P.Saturation2_UpperSat_b;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation2_LowerSat_n) {
        UAM_Flight_control_B.VectorConcatenate_c[2] =
          UAM_Flight_control_P.Saturation2_LowerSat_n;
      } else {
        UAM_Flight_control_B.VectorConcatenate_c[2] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1983>/Saturation2' */

      /* Sum: '<S1983>/Add5' incorporates:
       *  Constant: '<S1983>/Constant6'
       *  Gain: '<S1983>/Gain5'
       */
      rtb_Bias_l = UAM_Flight_control_P.Gain5_Gain * UAM_Flight_control_B.m_out
        [3] + UAM_Flight_control_P.Constant6_Value;

      /* Saturate: '<S1983>/Saturation3' incorporates:
       *  Concatenate: '<S1983>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation3_UpperSat) {
        UAM_Flight_control_B.VectorConcatenate_c[3] =
          UAM_Flight_control_P.Saturation3_UpperSat;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation3_LowerSat) {
        UAM_Flight_control_B.VectorConcatenate_c[3] =
          UAM_Flight_control_P.Saturation3_LowerSat;
      } else {
        UAM_Flight_control_B.VectorConcatenate_c[3] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1983>/Saturation3' */

      /* Saturate: '<S1983>/Saturation4' incorporates:
       *  Concatenate: '<S1983>/Vector Concatenate'
       */
      if (UAM_Flight_control_B.TmpBufferAtConstant4Outport1 >
          UAM_Flight_control_P.Saturation4_UpperSat) {
        UAM_Flight_control_B.VectorConcatenate_c[4] =
          UAM_Flight_control_P.Saturation4_UpperSat;
      } else if (UAM_Flight_control_B.TmpBufferAtConstant4Outport1 <
                 UAM_Flight_control_P.Saturation4_LowerSat) {
        UAM_Flight_control_B.VectorConcatenate_c[4] =
          UAM_Flight_control_P.Saturation4_LowerSat;
      } else {
        UAM_Flight_control_B.VectorConcatenate_c[4] =
          UAM_Flight_control_B.TmpBufferAtConstant4Outport1;
      }

      /* End of Saturate: '<S1983>/Saturation4' */

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cv2z = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bawm = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_edgh = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_nlya = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dq0y = 0U;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kbh = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mey = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ps2n = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ezp = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dec = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gbt = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nw2 = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_i0g = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dgzi = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ae0 = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bjh = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jjd = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ajjw = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_hwn = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pgbn = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_n2x4 = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_gx0x = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_adlp = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bbr4 = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pyg = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pdsb = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fsn = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_by1n = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cr0 = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_duzz = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[0] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[1] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[2] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[3] = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_awya = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_l5c = 0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_jx3i = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bkn5 = 0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_irme = 0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_exub = 0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ouuy = 0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_k55z = 0U;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_odds = 0U;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_a2gj = 0U;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      memset(&UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cvbt[0], 0, sizeof
             (real_T) << 4U);

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[0] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[1] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[2] = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_mqvj = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_kewq = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ahl1 = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_e1ub = 0.0F;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_oniv = 0.0;

      /* SignalConversion generated from: '<S1983>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_daxi = 0.0;
    } else {
      if (UAM_Flight_control_DW.multicopterController_MODE) {
        /* Disable for Enabled SubSystem: '<S1698>/Altitude Control1' */
        UAM_Flight_control_DW.AltitudeControl1_MODE = false;

        /* End of Disable for SubSystem: '<S1698>/Altitude Control1' */

        /* Disable for Enabled SubSystem: '<S1698>/Horizontal Position Control1' */
        UAM_Flight_control_DW.HorizontalPositionControl1_MODE = false;

        /* End of Disable for SubSystem: '<S1698>/Horizontal Position Control1' */
        UAM_Flight_control_DW.multicopterController_MODE = false;
      }

      if (UAM_Flight_control_DW.Scheduler_MODE_p) {
        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cv2z =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nw2 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_adlp =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_jx3i =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_mqvj = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_kewq = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ahl1 = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_e1ub = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_oniv =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_daxi =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bawm = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_edgh = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_nlya = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dq0y = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kbh = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mey = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ps2n = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ezp =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dec =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gbt =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_i0g =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dgzi =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ae0 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bjh =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jjd =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ajjw = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_hwn = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pgbn = (real32_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_n2x4 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_gx0x =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bbr4 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pyg =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pdsb =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fsn =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_by1n =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cr0 =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_duzz =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[0] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[1] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[2] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[3] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_awya =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_l5c = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bkn5 = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_irme = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_exub = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ouuy = (int16_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_k55z = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_odds = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_a2gj = (uint8_T)
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        for (i = 0; i < 6; i++) {
          /* Disable for Concatenate: '<S1983>/Vector Concatenate' incorporates:
           *  Outport: '<S1697>/MotorActuatorCommands'
           * */
          UAM_Flight_control_B.VectorConcatenate_c[i] =
            UAM_Flight_control_P.MotorActuatorCommands_Y0;
        }

        for (i = 0; i < 16; i++) {
          /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
           *  Outport: '<S1697>/MotorActuatorCommands'
           * */
          UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cvbt[i] =
            UAM_Flight_control_P.MotorActuatorCommands_Y0;
        }

        /* Disable for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1697>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[0] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[1] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;
        UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[2] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0;

        /* Disable for SignalConversion generated from: '<S1697>/CtrlSurfaceCommands' incorporates:
         *  Outport: '<S1697>/CtrlSurfaceCommands'
         * */
        UAM_Flight_control_B.OutportBufferForCtrlSurfaceC_i5 =
          UAM_Flight_control_P.CtrlSurfaceCommands_Y0;
        UAM_Flight_control_DW.Scheduler_MODE_p = false;
      }
    }

    /* End of Outputs for SubSystem: '<S9>/multicopter Controller' */
    /* End of Outputs for SubSystem: '<S9>/FixedWing Controller' */
    /* End of Outputs for SubSystem: '<S9>/Scheduler' */

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  Concatenate: '<S1983>/Vector Concatenate'
     *  Constant: '<S1705>/Constant'
     *  Constant: '<S1983>/Constant'
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     *  Logic: '<S1698>/OR'
     *  Logic: '<S1698>/OR1'
     *  RelationalOperator: '<S1705>/Compare'
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.roll =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cv2z;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.pitch =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nw2;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.dist_n =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bawm;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.dist_e =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_edgh;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.dist_d =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_nlya;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.gps_num_sv =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dq0y;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.roll_rate =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kbh;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.pitch_rate =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mey;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.yaw_rate =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ps2n;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.acc_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ezp;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.acc_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dec;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.acc_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gbt;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.yaw =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_adlp;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.pressure =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_i0g;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.vel_n =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dgzi;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.vel_e =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ae0;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.vel_d =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bjh;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.gndspeed =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jjd;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.target_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ajjw;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.target_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_hwn;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.target_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pgbn;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.gyro_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_n2x4;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.gyro_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_gx0x;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.altitude =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_jx3i;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.gyro_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bbr4;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.mag_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pyg;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.mag_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pdsb;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.mag_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fsn;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.lin_acc_ecef_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_by1n;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.lin_acc_ecef_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cr0;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.lin_acc_ecef_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_duzz;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.q[0] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[0];
    UAM_Flight_control_B.q[1] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[1];
    UAM_Flight_control_B.q[2] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[2];
    UAM_Flight_control_B.q[3] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[3];

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.airspeed =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_awya;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.voltage =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_l5c;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.target_roll =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_mqvj;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.current =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bkn5;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.soc =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_irme;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.temperature =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_exub;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.soh =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ouuy;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.gcs_link =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_k55z;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.rc_link =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_odds;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.flight_mode =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_a2gj;
    for (i = 0; i < 6; i++) {
      /* Merge generated from: '<S1>/Merge' incorporates:
       *  SignalConversion generated from: '<S9>/Controller'
       */
      UAM_Flight_control_B.m[i] = UAM_Flight_control_B.VectorConcatenate_c[i];
    }

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    memcpy(&UAM_Flight_control_B.rc[0],
           &UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cvbt[0], sizeof
           (real_T) << 4U);

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.rpy_sp[0] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[0];
    UAM_Flight_control_B.rpy_sp[1] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[1];
    UAM_Flight_control_B.rpy_sp[2] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[2];

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.target_pitch =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_kewq;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.target_yaw =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ahl1;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.target_alt =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_e1ub;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.latitude =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_oniv;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.longitude =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_daxi;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S9>/Controller'
     */
    UAM_Flight_control_B.CtrlSurfaceCommands =
      UAM_Flight_control_B.OutportBufferForCtrlSurfaceC_i5;

    /* Sum: '<S1695>/Sum' incorporates:
     *  Constant: '<S1695>/Constant'
     *  Constant: '<S1695>/Constant1'
     *  Gain: '<S1695>/Gain'
     *  Gain: '<S1695>/Gain1'
     *  RelationalOperator: '<S1695>/Relational Operator'
     *  RelationalOperator: '<S1695>/Relational Operator1'
     */
    rtb_Sum_pf = (int8_T)(((UAM_Flight_control_B.FlightMode ==
      UAM_Flight_control_P.Constant_Value_n ? (int32_T)
      UAM_Flight_control_P.Gain_Gain_ck : 0) + (UAM_Flight_control_B.FlightMode ==
      UAM_Flight_control_P.Constant1_Value_k2 ? (int32_T)
      UAM_Flight_control_P.Gain1_Gain_ms : 0)) >> 1);

    /* Saturate: '<S1187>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S1695>/Discrete-Time Integrator'
     *  Saturate: '<S1695>/Saturation'
     */
    UAM_Flight_control_B.a = (real_T)
      UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE_i * 7.8125E-7;

    /* Saturate: '<S1695>/Saturation' */
    if (UAM_Flight_control_B.a > UAM_Flight_control_P.Saturation_UpperSat_n) {
      /* Saturate: '<S1187>/Saturation' incorporates:
       *  Merge generated from: '<S1>/Merge'
       *  SignalConversion generated from: '<S9>/Controller'
       */
      UAM_Flight_control_B.a = UAM_Flight_control_P.Saturation_UpperSat_n;
    } else if (UAM_Flight_control_B.a <
               UAM_Flight_control_P.Saturation_LowerSat_b) {
      /* Saturate: '<S1187>/Saturation' incorporates:
       *  Merge generated from: '<S1>/Merge'
       *  SignalConversion generated from: '<S9>/Controller'
       */
      UAM_Flight_control_B.a = UAM_Flight_control_P.Saturation_LowerSat_b;
    }

    /* End of Outputs for SubSystem: '<S1>/Manual' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Auto1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* RelationalOperator: '<S10>/Relational Operator' incorporates:
     *  Constant: '<S10>/Constant'
     */
    rtb_Compare_j = (UAM_Flight_control_B.FlightMode ==
                     UAM_Flight_control_P.Constant_Value_l5);

    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S16>/Constant5'
     *  Gain: '<S16>/Gain3'
     *  Saturate: '<S16>/Saturation1'
     *  Sum: '<S16>/1-a'
     */
    if (rtb_Compare_j) {
      /* Sum: '<S16>/Sum2' incorporates:
       *  Constant: '<S16>/Constant3'
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      rtb_Bias_l = UAM_Flight_control_U.fcc.airspeed -
        UAM_Flight_control_P.Constant3_Value;

      /* Saturate: '<S16>/Saturation1' */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation1_UpperSat_f) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation1_UpperSat_f;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation1_LowerSat_a) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation1_LowerSat_a;
      }

      s = UAM_Flight_control_P.Cruise_a - UAM_Flight_control_P.Gain3_Gain_g *
        rtb_Bias_l;
    } else {
      /* Outputs for Atomic SubSystem: '<S10>/BTalpha' */
      /* Gain: '<S15>/Gain' incorporates:
       *  Constant: '<S15>/Constant'
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       *  Sum: '<S15>/Subtract'
       */
      s = (UAM_Flight_control_P.Constant_Value_g -
           UAM_Flight_control_U.fcc.airspeed) * UAM_Flight_control_P.Gain_Gain_k;

      /* Saturate: '<S15>/Saturation' */
      if (s > UAM_Flight_control_P.Saturation_UpperSat_i) {
        s = UAM_Flight_control_P.Saturation_UpperSat_i;
      } else if (s < UAM_Flight_control_P.Saturation_LowerSat_l) {
        s = UAM_Flight_control_P.Saturation_LowerSat_l;
      }

      /* End of Saturate: '<S15>/Saturation' */
      /* End of Outputs for SubSystem: '<S10>/BTalpha' */
    }

    /* End of Switch: '<S10>/Switch' */

    /* Outputs for Enabled SubSystem: '<S7>/Multicopter Controller' incorporates:
     *  EnablePort: '<S13>/ Armed'
     */
    if (rtb_Compare_ic) {
      UAM_Flight_control_DW.MulticopterController_MODE = true;

      /* Outputs for Enabled SubSystem: '<S517>/Altitude Control' incorporates:
       *  EnablePort: '<S521>/Enable'
       */
      if (UAM_Flight_control_U.fcc.rc[6] >
          UAM_Flight_control_P.CompareToConstant_const_k) {
        if (!UAM_Flight_control_DW.AltitudeControl_MODE) {
          /* InitializeConditions for DiscreteIntegrator: '<S616>/Integrator' */
          UAM_Flight_control_DW.Integrator_DSTATE_o =
            UAM_Flight_control_P.Altituderatecontroller1_Initi_k;
          UAM_Flight_control_DW.Integrator_PrevResetState_p = 2;

          /* InitializeConditions for DiscreteIntegrator: '<S611>/Filter' */
          UAM_Flight_control_DW.Filter_DSTATE_n =
            UAM_Flight_control_P.Altituderatecontroller1_Initial;
          UAM_Flight_control_DW.Filter_PrevResetState_e = 2;

          /* InitializeConditions for Sum: '<S521>/Sum3' incorporates:
           *  UnitDelay: '<S521>/Unit Delay'
           */
          UAM_Flight_control_DW.UnitDelay_DSTATE_f =
            UAM_Flight_control_P.UnitDelay_InitialCondition_b;

          /* SystemReset for MATLAB Function: '<S521>/MATLAB Function' */
          UAM__MATLABFunction_p_Reset
            (&UAM_Flight_control_DW.sf_MATLABFunction_ac);
          UAM_Flight_control_DW.AltitudeControl_MODE = true;
        }

        /* Outputs for Triggered SubSystem: '<S521>/Triggered Subsystem' incorporates:
         *  TriggerPort: '<S527>/Trigger'
         */
        if ((UAM_Flight_control_B.controlMode_h.inTransition > 0) &&
            (UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE_o !=
             POS_ZCSIG)) {
          /* SignalConversion generated from: '<S527>/AltHold' */
          UAM_Flight_control_B.AltHold = rtb_Mag_idx_2;
        }

        UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE_o = (ZCSigState)
          (UAM_Flight_control_B.controlMode_h.inTransition > 0);

        /* End of Outputs for SubSystem: '<S521>/Triggered Subsystem' */

        /* Gain: '<S521>/Gain1' */
        rtb_Gain1_l = UAM_Flight_control_P.Gain1_Gain_h * rtb_Kvz_a;

        /* Switch: '<S521>/Switch' incorporates:
         *  Logic: '<S521>/NOT'
         */
        if (UAM_Flight_control_B.controlMode_h.inTransition == 0) {
          /* Switch: '<S521>/Switch1' incorporates:
           *  Constant: '<S521>/Constant4'
           *  RelationalOperator: '<S521>/Equal'
           */
          if (UAM_Flight_control_P.Constant4_Value_ib ==
              UAM_Flight_control_B.FlightMode) {
            rtb_Bias_l = UAM_Flight_control_B.AltHold;
          } else {
            rtb_Bias_l = UAM_Flight_control_B.Z;
          }

          /* End of Switch: '<S521>/Switch1' */
        } else {
          rtb_Bias_l = UAM_Flight_control_B.AltHold;
        }

        /* Gain: '<S567>/Proportional Gain' incorporates:
         *  Gain: '<S521>/Gain'
         *  Sum: '<S521>/Sum'
         *  Switch: '<S521>/Switch'
         *  UnaryMinus: '<S521>/Unary Minus'
         */
        rtb_Bias_l = (-rtb_Bias_l - UAM_Flight_control_P.Gain_Gain_h *
                      rtb_Mag_idx_2) * UAM_Flight_control_P.controlParams.P_Z;

        /* Saturate: '<S569>/Saturation' */
        if (rtb_Bias_l > UAM_Flight_control_P.Altitudecontroller_UpperSaturat) {
          rtb_Bias_l = UAM_Flight_control_P.Altitudecontroller_UpperSaturat;
        } else if (rtb_Bias_l <
                   UAM_Flight_control_P.Altitudecontroller_LowerSaturat) {
          rtb_Bias_l = UAM_Flight_control_P.Altitudecontroller_LowerSaturat;
        }

        /* Sum: '<S521>/Sum1' incorporates:
         *  Saturate: '<S569>/Saturation'
         */
        rtb_IntegralGain_cj = rtb_Bias_l - rtb_Gain1_l;

        /* DiscreteIntegrator: '<S616>/Integrator' */
        if (UAM_Flight_control_DW.Integrator_PrevResetState_p <= 0) {
          UAM_Flight_control_DW.Integrator_DSTATE_o =
            UAM_Flight_control_P.Altituderatecontroller1_Initi_k;
        }

        /* DiscreteIntegrator: '<S611>/Filter' */
        if (UAM_Flight_control_DW.Filter_PrevResetState_e <= 0) {
          UAM_Flight_control_DW.Filter_DSTATE_n =
            UAM_Flight_control_P.Altituderatecontroller1_Initial;
        }

        /* Gain: '<S619>/Filter Coefficient' incorporates:
         *  DiscreteIntegrator: '<S611>/Filter'
         *  Gain: '<S609>/Derivative Gain'
         *  Sum: '<S611>/SumD'
         */
        rtb_FilterCoefficient_f = (UAM_Flight_control_P.controlParams.D_VZ *
          rtb_IntegralGain_cj - UAM_Flight_control_DW.Filter_DSTATE_n) *
          UAM_Flight_control_P.controlParams.N_VZ;

        /* Sum: '<S625>/Sum' incorporates:
         *  DiscreteIntegrator: '<S616>/Integrator'
         *  Gain: '<S621>/Proportional Gain'
         */
        rtb_DeadZone_hh = (UAM_Flight_control_P.controlParams.P_VZ *
                           rtb_IntegralGain_cj +
                           UAM_Flight_control_DW.Integrator_DSTATE_o) +
          rtb_FilterCoefficient_f;

        /* MATLAB Function: '<S521>/MATLAB Function' incorporates:
         *  UnitDelay: '<S521>/Unit Delay'
         */
        UAM_Flight_MATLABFunction_m(UAM_Flight_control_DW.UnitDelay_DSTATE_f,
          rtb_Gain1_l, UAM_Flight_control_U.fcc.acc_z, true, &rtb_hover_est,
          &UAM_Flight_control_DW.sf_MATLABFunction_ac);

        /* Saturate: '<S623>/Saturation' */
        if (rtb_DeadZone_hh >
            UAM_Flight_control_P.Altituderatecontroller1_UpperSa) {
          rtb_Bias_l = UAM_Flight_control_P.Altituderatecontroller1_UpperSa;
        } else if (rtb_DeadZone_hh <
                   UAM_Flight_control_P.Altituderatecontroller1_LowerSa) {
          rtb_Bias_l = UAM_Flight_control_P.Altituderatecontroller1_LowerSa;
        } else {
          rtb_Bias_l = rtb_DeadZone_hh;
        }

        /* Sum: '<S521>/Sum3' incorporates:
         *  Gain: '<S521>/hover_thrust//g'
         *  Product: '<S521>/Product1'
         *  Saturate: '<S623>/Saturation'
         */
        UAM_Flight_control_DW.UnitDelay_DSTATE_f = rtb_hover_est * rtb_Bias_l *
          UAM_Flight_control_P.hover_thrustg_Gain_m + rtb_hover_est;

        /* Saturate: '<S521>/Saturation1' */
        if (UAM_Flight_control_DW.UnitDelay_DSTATE_f >
            UAM_Flight_control_P.Saturation1_UpperSat_fd) {
          /* Sum: '<S521>/Sum3' */
          UAM_Flight_control_DW.UnitDelay_DSTATE_f =
            UAM_Flight_control_P.Saturation1_UpperSat_fd;
        } else if (UAM_Flight_control_DW.UnitDelay_DSTATE_f <
                   UAM_Flight_control_P.Saturation1_LowerSat_my) {
          /* Sum: '<S521>/Sum3' */
          UAM_Flight_control_DW.UnitDelay_DSTATE_f =
            UAM_Flight_control_P.Saturation1_LowerSat_my;
        }

        /* End of Saturate: '<S521>/Saturation1' */

        /* DeadZone: '<S608>/DeadZone' */
        if (rtb_DeadZone_hh >
            UAM_Flight_control_P.Altituderatecontroller1_UpperSa) {
          rtb_DeadZone_hh -=
            UAM_Flight_control_P.Altituderatecontroller1_UpperSa;
        } else if (rtb_DeadZone_hh >=
                   UAM_Flight_control_P.Altituderatecontroller1_LowerSa) {
          rtb_DeadZone_hh = 0.0;
        } else {
          rtb_DeadZone_hh -=
            UAM_Flight_control_P.Altituderatecontroller1_LowerSa;
        }

        /* End of DeadZone: '<S608>/DeadZone' */

        /* Gain: '<S613>/Integral Gain' */
        rtb_IntegralGain_cj *= UAM_Flight_control_P.controlParams.I_VZ;

        /* Switch: '<S606>/Switch1' incorporates:
         *  Constant: '<S606>/Clamping_zero'
         *  Constant: '<S606>/Constant'
         *  Constant: '<S606>/Constant2'
         *  RelationalOperator: '<S606>/fix for DT propagation issue'
         */
        if (rtb_DeadZone_hh > UAM_Flight_control_P.Clamping_zero_Value_g) {
          rtAction = UAM_Flight_control_P.Constant_Value_dr;
        } else {
          rtAction = UAM_Flight_control_P.Constant2_Value_f2;
        }

        /* Switch: '<S606>/Switch2' incorporates:
         *  Constant: '<S606>/Clamping_zero'
         *  Constant: '<S606>/Constant3'
         *  Constant: '<S606>/Constant4'
         *  RelationalOperator: '<S606>/fix for DT propagation issue1'
         */
        if (rtb_IntegralGain_cj > UAM_Flight_control_P.Clamping_zero_Value_g) {
          tmp_1 = UAM_Flight_control_P.Constant3_Value_d;
        } else {
          tmp_1 = UAM_Flight_control_P.Constant4_Value_he;
        }

        /* Switch: '<S606>/Switch' incorporates:
         *  Constant: '<S606>/Clamping_zero'
         *  Constant: '<S606>/Constant1'
         *  Logic: '<S606>/AND3'
         *  RelationalOperator: '<S606>/Equal1'
         *  RelationalOperator: '<S606>/Relational Operator'
         *  Switch: '<S606>/Switch1'
         *  Switch: '<S606>/Switch2'
         */
        if ((UAM_Flight_control_P.Clamping_zero_Value_g != rtb_DeadZone_hh) &&
            (rtAction == tmp_1)) {
          rtb_IntegralGain_cj = UAM_Flight_control_P.Constant1_Value_j;
        }

        /* Update for DiscreteIntegrator: '<S616>/Integrator' incorporates:
         *  Switch: '<S606>/Switch'
         */
        UAM_Flight_control_DW.Integrator_DSTATE_o +=
          UAM_Flight_control_P.Integrator_gainval_p * rtb_IntegralGain_cj;
        if (UAM_Flight_control_DW.Integrator_DSTATE_o >
            UAM_Flight_control_P.Altituderatecontroller1_UpperIn) {
          UAM_Flight_control_DW.Integrator_DSTATE_o =
            UAM_Flight_control_P.Altituderatecontroller1_UpperIn;
        } else if (UAM_Flight_control_DW.Integrator_DSTATE_o <
                   UAM_Flight_control_P.Altituderatecontroller1_LowerIn) {
          UAM_Flight_control_DW.Integrator_DSTATE_o =
            UAM_Flight_control_P.Altituderatecontroller1_LowerIn;
        }

        UAM_Flight_control_DW.Integrator_PrevResetState_p = 1;

        /* End of Update for DiscreteIntegrator: '<S616>/Integrator' */

        /* Update for DiscreteIntegrator: '<S611>/Filter' */
        UAM_Flight_control_DW.Filter_DSTATE_n +=
          UAM_Flight_control_P.Filter_gainval_gk * rtb_FilterCoefficient_f;
        UAM_Flight_control_DW.Filter_PrevResetState_e = 1;
      } else {
        UAM_Flight_control_DW.AltitudeControl_MODE = false;
      }

      /* End of Outputs for SubSystem: '<S517>/Altitude Control' */

      /* MATLAB Function: '<S523>/MATLAB Function' incorporates:
       *  Constant: '<S522>/Constant'
       *  Inport: '<Root>/fcc'
       *  RelationalOperator: '<S522>/Compare'
       *  SignalConversion generated from: '<Root>/fcc'
       *  Sum: '<S523>/Sum6'
       */
      UAM_Flight_MATLABFunction_i(UAM_Flight_control_B.Yaw - rtb_Gain1[0],
        &rtb_Gain1_l);

      /* Sum: '<S523>/Sum3' incorporates:
       *  Gain: '<S888>/Proportional Gain'
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      rtb_qout_idx_0 = UAM_Flight_control_P.controlParams.P_YAW * rtb_Gain1_l -
        UAM_Flight_control_U.fcc.gyro_z;

      /* Outputs for Enabled SubSystem: '<S13>/Horizontal Position Control' incorporates:
       *  EnablePort: '<S518>/Enable'
       */
      if (UAM_Flight_control_B.controlMode_h.inTransition == 0) {
        UAM_Flight_control_DW.HorizontalPositionControl_MODE = true;

        /* Outputs for Enabled SubSystem: '<S518>/XY Controller' incorporates:
         *  EnablePort: '<S953>/Enable'
         */
        if (!UAM_Flight_control_DW.XYController_MODE) {
          /* InitializeConditions for DiscreteIntegrator: '<S1051>/Integrator' */
          UAM_Flight_control_DW.Integrator_DSTATE_j =
            UAM_Flight_control_P.Forwardvelocitycontroller_Ini_o;
          UAM_Flight_control_DW.Integrator_PrevResetState = 2;

          /* InitializeConditions for DiscreteIntegrator: '<S1046>/Filter' */
          UAM_Flight_control_DW.Filter_DSTATE_c =
            UAM_Flight_control_P.Forwardvelocitycontroller_Ini_a;
          UAM_Flight_control_DW.Filter_PrevResetState = 2;

          /* InitializeConditions for DiscreteIntegrator: '<S1157>/Integrator' */
          UAM_Flight_control_DW.Integrator_DSTATE_hy =
            UAM_Flight_control_P.Lateralvelocitycontroller_Ini_m;
          UAM_Flight_control_DW.Integrator_PrevResetState_n = 2;

          /* InitializeConditions for DiscreteIntegrator: '<S1152>/Filter' */
          UAM_Flight_control_DW.Filter_DSTATE_lq =
            UAM_Flight_control_P.Lateralvelocitycontroller_Ini_p;
          UAM_Flight_control_DW.Filter_PrevResetState_p = 2;
          UAM_Flight_control_DW.XYController_MODE = true;
        }

        /* Trigonometry: '<S953>/SinCos' */
        rtb_DeadZone_hh = sin(rtb_Gain1[0]);
        rtb_hover_est = cos(rtb_Gain1[0]);

        /* Sum: '<S953>/Sum' */
        rtb_Gain1_l = UAM_Flight_control_B.X - rtb_Mag_idx_0;

        /* Sum: '<S953>/Sum1' */
        rtb_Bias_l = UAM_Flight_control_B.Y - rtb_Mag_idx_1;

        /* Sum: '<S954>/Add' incorporates:
         *  Product: '<S954>/Product'
         *  Product: '<S954>/Product1'
         */
        rtb_qout_idx_1 = rtb_hover_est * rtb_Gain1_l + rtb_Bias_l *
          rtb_DeadZone_hh;

        /* Gain: '<S1002>/Proportional Gain' */
        rtb_IntegralGain_cj = UAM_Flight_control_P.controlParams.P_X *
          rtb_qout_idx_1;

        /* Saturate: '<S1004>/Saturation' */
        if (rtb_IntegralGain_cj >
            UAM_Flight_control_P.Forwardpositioncontroller_Upper) {
          rtb_IntegralGain_cj =
            UAM_Flight_control_P.Forwardpositioncontroller_Upper;
        } else if (rtb_IntegralGain_cj <
                   UAM_Flight_control_P.Forwardpositioncontroller_Lower) {
          rtb_IntegralGain_cj =
            UAM_Flight_control_P.Forwardpositioncontroller_Lower;
        }

        /* End of Saturate: '<S1004>/Saturation' */

        /* Sum: '<S958>/Add' incorporates:
         *  Gain: '<S958>/Gain'
         *  Product: '<S958>/Product'
         *  Product: '<S958>/Product1'
         */
        rtb_Bias_l = rtb_DeadZone_hh * rtb_Gain1_l *
          UAM_Flight_control_P.Gain_Gain_f + rtb_Bias_l * rtb_hover_est;

        /* Gain: '<S1108>/Proportional Gain' */
        rtb_Gain1_l = UAM_Flight_control_P.controlParams.P_Y * rtb_Bias_l;

        /* Saturate: '<S1110>/Saturation' */
        if (rtb_Gain1_l > UAM_Flight_control_P.Lateralpositioncontroller_Upp_a)
        {
          rtb_Gain1_l = UAM_Flight_control_P.Lateralpositioncontroller_Upp_a;
        } else if (rtb_Gain1_l <
                   UAM_Flight_control_P.Lateralpositioncontroller_Low_j) {
          rtb_Gain1_l = UAM_Flight_control_P.Lateralpositioncontroller_Low_j;
        }

        /* End of Saturate: '<S1110>/Saturation' */

        /* Product: '<S962>/Divide' incorporates:
         *  Constant: '<S962>/MPC_ACC_HOR'
         *  Constant: '<S962>/MPC_JERK_AUTO'
         *  Gain: '<S962>/Gain'
         *  Math: '<S962>/Square'
         */
        rtb_FilterCoefficient_f = UAM_Flight_control_P.MPC_ACC_HOR_Value *
          UAM_Flight_control_P.MPC_ACC_HOR_Value *
          UAM_Flight_control_P.Gain_Gain_a /
          UAM_Flight_control_P.MPC_JERK_AUTO_Value;

        /* MinMax: '<S962>/MinMax' incorporates:
         *  Constant: '<S962>/MPC_ACC_HOR'
         *  Constant: '<S962>/Value'
         *  Constant: '<S962>/value'
         *  Gain: '<S962>/Gain1'
         *  Gain: '<S962>/Gain2'
         *  Gain: '<S962>/Gain3'
         *  Math: '<S962>/Square1'
         *  Math: '<S962>/fe_sq'
         *  Math: '<S962>/le_sq'
         *  Math: '<S962>/vf_sq'
         *  Math: '<S962>/vl_sq'
         *  MinMax: '<S962>/MinMax1'
         *  Product: '<S962>/Divide1'
         *  Product: '<S962>/Product'
         *  Sqrt: '<S962>/Sqrt'
         *  Sqrt: '<S962>/Sqrt1'
         *  Sqrt: '<S962>/disc_sqrt'
         *  Sum: '<S962>/Sum'
         *  Sum: '<S962>/Sum1'
         *  Sum: '<S962>/Sum2'
         *  Sum: '<S962>/Sum3'
         */
        rtb_FilterCoefficient_f = fmin((sqrt(rtb_FilterCoefficient_f *
          rtb_FilterCoefficient_f - sqrt(rtb_Bias_l * rtb_Bias_l +
          rtb_qout_idx_1 * rtb_qout_idx_1) *
          UAM_Flight_control_P.MPC_ACC_HOR_Value *
          UAM_Flight_control_P.Gain1_Gain_hd * UAM_Flight_control_P.Gain2_Gain_a)
          - rtb_FilterCoefficient_f) * UAM_Flight_control_P.Gain3_Gain_i / fmax
          (sqrt(rtb_Gain1_l * rtb_Gain1_l + rtb_IntegralGain_cj *
                rtb_IntegralGain_cj), UAM_Flight_control_P.Value_Value),
          UAM_Flight_control_P.value_Value);

        /* Product: '<S962>/Product2' */
        rtb_Bias_l = rtb_FilterCoefficient_f * rtb_IntegralGain_cj;

        /* Saturate: '<S953>/Saturation3' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation3_UpperSat_c) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation3_UpperSat_c;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation3_LowerSat_k) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation3_LowerSat_k;
        }

        /* Sum: '<S953>/Sum4' incorporates:
         *  Product: '<S956>/Product'
         *  Product: '<S956>/Product1'
         *  Saturate: '<S953>/Saturation3'
         *  Sum: '<S956>/Add'
         */
        rtb_IntegralGain_cj = rtb_Bias_l - (rtb_hover_est * rtb_Kz + rtb_Kz_f *
          rtb_DeadZone_hh);

        /* DiscreteIntegrator: '<S1051>/Integrator' */
        if (UAM_Flight_control_DW.Integrator_PrevResetState <= 0) {
          UAM_Flight_control_DW.Integrator_DSTATE_j =
            UAM_Flight_control_P.Forwardvelocitycontroller_Ini_o;
        }

        /* DiscreteIntegrator: '<S1046>/Filter' */
        if (UAM_Flight_control_DW.Filter_PrevResetState <= 0) {
          UAM_Flight_control_DW.Filter_DSTATE_c =
            UAM_Flight_control_P.Forwardvelocitycontroller_Ini_a;
        }

        /* Gain: '<S1054>/Filter Coefficient' incorporates:
         *  DiscreteIntegrator: '<S1046>/Filter'
         *  Gain: '<S1044>/Derivative Gain'
         *  Sum: '<S1046>/SumD'
         */
        rtb_qout_idx_1 = (UAM_Flight_control_P.controlParams.D_VX *
                          rtb_IntegralGain_cj -
                          UAM_Flight_control_DW.Filter_DSTATE_c) *
          UAM_Flight_control_P.controlParams.N_VX;

        /* Sum: '<S1060>/Sum' incorporates:
         *  DiscreteIntegrator: '<S1051>/Integrator'
         *  Gain: '<S1056>/Proportional Gain'
         */
        rtb_qout_idx_2 = (UAM_Flight_control_P.controlParams.P_VX *
                          rtb_IntegralGain_cj +
                          UAM_Flight_control_DW.Integrator_DSTATE_j) +
          rtb_qout_idx_1;

        /* Saturate: '<S1058>/Saturation' */
        if (rtb_qout_idx_2 >
            UAM_Flight_control_P.Forwardvelocitycontroller_Upp_h) {
          rtb_Bias_l = UAM_Flight_control_P.Forwardvelocitycontroller_Upp_h;
        } else if (rtb_qout_idx_2 <
                   UAM_Flight_control_P.Forwardvelocitycontroller_Lo_ei) {
          rtb_Bias_l = UAM_Flight_control_P.Forwardvelocitycontroller_Lo_ei;
        } else {
          rtb_Bias_l = rtb_qout_idx_2;
        }

        /* Gain: '<S953>/Gain' incorporates:
         *  Saturate: '<S1058>/Saturation'
         */
        UAM_Flight_control_B.Saturation_g = UAM_Flight_control_P.Gain_Gain_at *
          rtb_Bias_l;

        /* Saturate: '<S953>/Saturation' */
        if (UAM_Flight_control_B.Saturation_g >
            UAM_Flight_control_P.Saturation_UpperSat_o) {
          /* Gain: '<S953>/Gain' incorporates:
           *  Saturate: '<S953>/Saturation'
           */
          UAM_Flight_control_B.Saturation_g =
            UAM_Flight_control_P.Saturation_UpperSat_o;
        } else if (UAM_Flight_control_B.Saturation_g <
                   UAM_Flight_control_P.Saturation_LowerSat_j) {
          /* Gain: '<S953>/Gain' incorporates:
           *  Saturate: '<S953>/Saturation'
           */
          UAM_Flight_control_B.Saturation_g =
            UAM_Flight_control_P.Saturation_LowerSat_j;
        }

        /* End of Saturate: '<S953>/Saturation' */

        /* DeadZone: '<S1043>/DeadZone' */
        if (rtb_qout_idx_2 >
            UAM_Flight_control_P.Forwardvelocitycontroller_Upp_h) {
          rtb_qout_idx_2 -= UAM_Flight_control_P.Forwardvelocitycontroller_Upp_h;
        } else if (rtb_qout_idx_2 >=
                   UAM_Flight_control_P.Forwardvelocitycontroller_Lo_ei) {
          rtb_qout_idx_2 = 0.0;
        } else {
          rtb_qout_idx_2 -= UAM_Flight_control_P.Forwardvelocitycontroller_Lo_ei;
        }

        /* End of DeadZone: '<S1043>/DeadZone' */

        /* Gain: '<S1048>/Integral Gain' */
        rtb_IntegralGain_cj *= UAM_Flight_control_P.controlParams.I_VX;

        /* Product: '<S962>/Product1' */
        rtb_Bias_l = rtb_Gain1_l * rtb_FilterCoefficient_f;

        /* Saturate: '<S953>/Saturation2' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation2_UpperSat_j) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation2_UpperSat_j;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation2_LowerSat_e0) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation2_LowerSat_e0;
        }

        /* Sum: '<S953>/Sum5' incorporates:
         *  Gain: '<S960>/Gain'
         *  Product: '<S960>/Product'
         *  Product: '<S960>/Product1'
         *  Saturate: '<S953>/Saturation2'
         *  Sum: '<S960>/Add'
         */
        rtb_Gain1_l = rtb_Bias_l - (rtb_DeadZone_hh * rtb_Kz *
          UAM_Flight_control_P.Gain_Gain_cg + rtb_Kz_f * rtb_hover_est);

        /* DiscreteIntegrator: '<S1157>/Integrator' */
        if (UAM_Flight_control_DW.Integrator_PrevResetState_n <= 0) {
          UAM_Flight_control_DW.Integrator_DSTATE_hy =
            UAM_Flight_control_P.Lateralvelocitycontroller_Ini_m;
        }

        /* DiscreteIntegrator: '<S1152>/Filter' */
        if (UAM_Flight_control_DW.Filter_PrevResetState_p <= 0) {
          UAM_Flight_control_DW.Filter_DSTATE_lq =
            UAM_Flight_control_P.Lateralvelocitycontroller_Ini_p;
        }

        /* Gain: '<S1160>/Filter Coefficient' incorporates:
         *  DiscreteIntegrator: '<S1152>/Filter'
         *  Gain: '<S1150>/Derivative Gain'
         *  Sum: '<S1152>/SumD'
         */
        rtb_DeadZone_hh = (UAM_Flight_control_P.controlParams.D_VY * rtb_Gain1_l
                           - UAM_Flight_control_DW.Filter_DSTATE_lq) *
          UAM_Flight_control_P.controlParams.N_VY;

        /* Sum: '<S1166>/Sum' incorporates:
         *  DiscreteIntegrator: '<S1157>/Integrator'
         *  Gain: '<S1162>/Proportional Gain'
         */
        rtb_FilterCoefficient_f = (UAM_Flight_control_P.controlParams.P_VY *
          rtb_Gain1_l + UAM_Flight_control_DW.Integrator_DSTATE_hy) +
          rtb_DeadZone_hh;

        /* Saturate: '<S1164>/Saturation' */
        if (rtb_FilterCoefficient_f >
            UAM_Flight_control_P.Lateralvelocitycontroller_Upp_f) {
          rtb_Bias_l = UAM_Flight_control_P.Lateralvelocitycontroller_Upp_f;
        } else if (rtb_FilterCoefficient_f <
                   UAM_Flight_control_P.Lateralvelocitycontroller_Low_o) {
          rtb_Bias_l = UAM_Flight_control_P.Lateralvelocitycontroller_Low_o;
        } else {
          rtb_Bias_l = rtb_FilterCoefficient_f;
        }

        /* Gain: '<S953>/rad' incorporates:
         *  Saturate: '<S1164>/Saturation'
         */
        UAM_Flight_control_B.Saturation1 = UAM_Flight_control_P.rad_Gain_k *
          rtb_Bias_l;

        /* Saturate: '<S953>/Saturation1' */
        if (UAM_Flight_control_B.Saturation1 >
            UAM_Flight_control_P.Saturation1_UpperSat_n) {
          /* Gain: '<S953>/rad' incorporates:
           *  Saturate: '<S953>/Saturation1'
           */
          UAM_Flight_control_B.Saturation1 =
            UAM_Flight_control_P.Saturation1_UpperSat_n;
        } else if (UAM_Flight_control_B.Saturation1 <
                   UAM_Flight_control_P.Saturation1_LowerSat_o) {
          /* Gain: '<S953>/rad' incorporates:
           *  Saturate: '<S953>/Saturation1'
           */
          UAM_Flight_control_B.Saturation1 =
            UAM_Flight_control_P.Saturation1_LowerSat_o;
        }

        /* End of Saturate: '<S953>/Saturation1' */

        /* DeadZone: '<S1149>/DeadZone' */
        if (rtb_FilterCoefficient_f >
            UAM_Flight_control_P.Lateralvelocitycontroller_Upp_f) {
          rtb_FilterCoefficient_f -=
            UAM_Flight_control_P.Lateralvelocitycontroller_Upp_f;
        } else if (rtb_FilterCoefficient_f >=
                   UAM_Flight_control_P.Lateralvelocitycontroller_Low_o) {
          rtb_FilterCoefficient_f = 0.0;
        } else {
          rtb_FilterCoefficient_f -=
            UAM_Flight_control_P.Lateralvelocitycontroller_Low_o;
        }

        /* End of DeadZone: '<S1149>/DeadZone' */

        /* Gain: '<S1154>/Integral Gain' */
        rtb_Gain1_l *= UAM_Flight_control_P.controlParams.I_VY;

        /* Switch: '<S1041>/Switch1' incorporates:
         *  Constant: '<S1041>/Clamping_zero'
         *  Constant: '<S1041>/Constant'
         *  Constant: '<S1041>/Constant2'
         *  RelationalOperator: '<S1041>/fix for DT propagation issue'
         */
        if (rtb_qout_idx_2 > UAM_Flight_control_P.Clamping_zero_Value_p2) {
          rtAction = UAM_Flight_control_P.Constant_Value_ln;
        } else {
          rtAction = UAM_Flight_control_P.Constant2_Value_d;
        }

        /* Switch: '<S1041>/Switch2' incorporates:
         *  Constant: '<S1041>/Clamping_zero'
         *  Constant: '<S1041>/Constant3'
         *  Constant: '<S1041>/Constant4'
         *  RelationalOperator: '<S1041>/fix for DT propagation issue1'
         */
        if (rtb_IntegralGain_cj > UAM_Flight_control_P.Clamping_zero_Value_p2) {
          tmp_1 = UAM_Flight_control_P.Constant3_Value_k;
        } else {
          tmp_1 = UAM_Flight_control_P.Constant4_Value_d;
        }

        /* Switch: '<S1041>/Switch' incorporates:
         *  Constant: '<S1041>/Clamping_zero'
         *  Constant: '<S1041>/Constant1'
         *  Logic: '<S1041>/AND3'
         *  RelationalOperator: '<S1041>/Equal1'
         *  RelationalOperator: '<S1041>/Relational Operator'
         *  Switch: '<S1041>/Switch1'
         *  Switch: '<S1041>/Switch2'
         */
        if ((UAM_Flight_control_P.Clamping_zero_Value_p2 != rtb_qout_idx_2) &&
            (rtAction == tmp_1)) {
          rtb_IntegralGain_cj = UAM_Flight_control_P.Constant1_Value_i;
        }

        /* Update for DiscreteIntegrator: '<S1051>/Integrator' incorporates:
         *  Switch: '<S1041>/Switch'
         */
        UAM_Flight_control_DW.Integrator_DSTATE_j +=
          UAM_Flight_control_P.Integrator_gainval_nm * rtb_IntegralGain_cj;
        if (UAM_Flight_control_DW.Integrator_DSTATE_j >
            UAM_Flight_control_P.Forwardvelocitycontroller_Upp_k) {
          UAM_Flight_control_DW.Integrator_DSTATE_j =
            UAM_Flight_control_P.Forwardvelocitycontroller_Upp_k;
        } else if (UAM_Flight_control_DW.Integrator_DSTATE_j <
                   UAM_Flight_control_P.Forwardvelocitycontroller_Low_e) {
          UAM_Flight_control_DW.Integrator_DSTATE_j =
            UAM_Flight_control_P.Forwardvelocitycontroller_Low_e;
        }

        UAM_Flight_control_DW.Integrator_PrevResetState = 1;

        /* End of Update for DiscreteIntegrator: '<S1051>/Integrator' */

        /* Update for DiscreteIntegrator: '<S1046>/Filter' */
        UAM_Flight_control_DW.Filter_DSTATE_c +=
          UAM_Flight_control_P.Filter_gainval_er * rtb_qout_idx_1;
        UAM_Flight_control_DW.Filter_PrevResetState = 1;

        /* Switch: '<S1147>/Switch1' incorporates:
         *  Constant: '<S1147>/Clamping_zero'
         *  Constant: '<S1147>/Constant'
         *  Constant: '<S1147>/Constant2'
         *  RelationalOperator: '<S1147>/fix for DT propagation issue'
         */
        if (rtb_FilterCoefficient_f > UAM_Flight_control_P.Clamping_zero_Value_h)
        {
          rtAction = UAM_Flight_control_P.Constant_Value_al;
        } else {
          rtAction = UAM_Flight_control_P.Constant2_Value_b;
        }

        /* Switch: '<S1147>/Switch2' incorporates:
         *  Constant: '<S1147>/Clamping_zero'
         *  Constant: '<S1147>/Constant3'
         *  Constant: '<S1147>/Constant4'
         *  RelationalOperator: '<S1147>/fix for DT propagation issue1'
         */
        if (rtb_Gain1_l > UAM_Flight_control_P.Clamping_zero_Value_h) {
          tmp_1 = UAM_Flight_control_P.Constant3_Value_ae;
        } else {
          tmp_1 = UAM_Flight_control_P.Constant4_Value_o;
        }

        /* Switch: '<S1147>/Switch' incorporates:
         *  Constant: '<S1147>/Clamping_zero'
         *  Constant: '<S1147>/Constant1'
         *  Logic: '<S1147>/AND3'
         *  RelationalOperator: '<S1147>/Equal1'
         *  RelationalOperator: '<S1147>/Relational Operator'
         *  Switch: '<S1147>/Switch1'
         *  Switch: '<S1147>/Switch2'
         */
        if ((UAM_Flight_control_P.Clamping_zero_Value_h !=
             rtb_FilterCoefficient_f) && (rtAction == tmp_1)) {
          rtb_Gain1_l = UAM_Flight_control_P.Constant1_Value_d;
        }

        /* Update for DiscreteIntegrator: '<S1157>/Integrator' incorporates:
         *  Switch: '<S1147>/Switch'
         */
        UAM_Flight_control_DW.Integrator_DSTATE_hy +=
          UAM_Flight_control_P.Integrator_gainval_e * rtb_Gain1_l;
        if (UAM_Flight_control_DW.Integrator_DSTATE_hy >
            UAM_Flight_control_P.Lateralvelocitycontroller_Upp_g) {
          UAM_Flight_control_DW.Integrator_DSTATE_hy =
            UAM_Flight_control_P.Lateralvelocitycontroller_Upp_g;
        } else if (UAM_Flight_control_DW.Integrator_DSTATE_hy <
                   UAM_Flight_control_P.Lateralvelocitycontroller_Low_c) {
          UAM_Flight_control_DW.Integrator_DSTATE_hy =
            UAM_Flight_control_P.Lateralvelocitycontroller_Low_c;
        }

        UAM_Flight_control_DW.Integrator_PrevResetState_n = 1;

        /* End of Update for DiscreteIntegrator: '<S1157>/Integrator' */

        /* Update for DiscreteIntegrator: '<S1152>/Filter' */
        UAM_Flight_control_DW.Filter_DSTATE_lq +=
          UAM_Flight_control_P.Filter_gainval_gl * rtb_DeadZone_hh;
        UAM_Flight_control_DW.Filter_PrevResetState_p = 1;

        /* End of Outputs for SubSystem: '<S518>/XY Controller' */

        /* Saturate: '<S518>/Saturation' */
        if (UAM_Flight_control_B.Saturation1 >
            UAM_Flight_control_P.Saturation_UpperSat_dd) {
          /* Merge: '<S13>/Merge' incorporates:
           *  SignalConversion: '<S518>/Signal Conversion1'
           */
          UAM_Flight_control_B.Merge_d5 =
            UAM_Flight_control_P.Saturation_UpperSat_dd;
        } else if (UAM_Flight_control_B.Saturation1 <
                   UAM_Flight_control_P.Saturation_LowerSat_j2) {
          /* Merge: '<S13>/Merge' incorporates:
           *  SignalConversion: '<S518>/Signal Conversion1'
           */
          UAM_Flight_control_B.Merge_d5 =
            UAM_Flight_control_P.Saturation_LowerSat_j2;
        } else {
          /* Merge: '<S13>/Merge' incorporates:
           *  SignalConversion: '<S518>/Signal Conversion1'
           */
          UAM_Flight_control_B.Merge_d5 = UAM_Flight_control_B.Saturation1;
        }

        /* End of Saturate: '<S518>/Saturation' */

        /* Saturate: '<S518>/Saturation1' */
        if (UAM_Flight_control_B.Saturation_g >
            UAM_Flight_control_P.Saturation1_UpperSat_c) {
          /* Merge: '<S13>/Merge1' incorporates:
           *  SignalConversion: '<S518>/Signal Conversion'
           */
          UAM_Flight_control_B.Merge1 =
            UAM_Flight_control_P.Saturation1_UpperSat_c;
        } else if (UAM_Flight_control_B.Saturation_g <
                   UAM_Flight_control_P.Saturation1_LowerSat_oz) {
          /* Merge: '<S13>/Merge1' incorporates:
           *  SignalConversion: '<S518>/Signal Conversion'
           */
          UAM_Flight_control_B.Merge1 =
            UAM_Flight_control_P.Saturation1_LowerSat_oz;
        } else {
          /* Merge: '<S13>/Merge1' incorporates:
           *  SignalConversion: '<S518>/Signal Conversion'
           */
          UAM_Flight_control_B.Merge1 = UAM_Flight_control_B.Saturation_g;
        }

        /* End of Saturate: '<S518>/Saturation1' */
      } else if (UAM_Flight_control_DW.HorizontalPositionControl_MODE) {
        /* Disable for Enabled SubSystem: '<S518>/XY Controller' */
        UAM_Flight_control_DW.XYController_MODE = false;

        /* End of Disable for SubSystem: '<S518>/XY Controller' */
        UAM_Flight_control_DW.HorizontalPositionControl_MODE = false;
      }

      /* End of Outputs for SubSystem: '<S13>/Horizontal Position Control' */

      /* Outputs for Enabled SubSystem: '<S13>/transition controller' incorporates:
       *  EnablePort: '<S520>/Enable'
       */
      if (UAM_Flight_control_B.controlMode_h.inTransition > 0) {
        /* Merge: '<S13>/Merge' incorporates:
         *  Constant: '<S520>/Constant'
         *  SignalConversion generated from: '<S520>/Rollcmd'
         */
        UAM_Flight_control_B.Merge_d5 = UAM_Flight_control_P.Constant_Value_b;

        /* Merge: '<S13>/Merge1' incorporates:
         *  Constant: '<S520>/Constant1'
         *  SignalConversion generated from: '<S520>/Pitchcmd'
         */
        UAM_Flight_control_B.Merge1 = UAM_Flight_control_P.Constant1_Value_a;
      }

      /* End of Outputs for SubSystem: '<S13>/transition controller' */

      /* Gain: '<S523>/Pitch_MAX_angle1' incorporates:
       *  Logic: '<S13>/NOT1'
       */
      rtb_Bias_l = UAM_Flight_control_P.Pitch_MAX_angle1_Gain *
        UAM_Flight_control_B.Merge1;

      /* Saturate: '<S523>/Saturation1' */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation1_UpperSat_l) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation1_UpperSat_l;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation1_LowerSat_n) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation1_LowerSat_n;
      }

      /* Gain: '<S680>/Proportional Gain' incorporates:
       *  Saturate: '<S523>/Saturation1'
       *  Sum: '<S523>/Sum5'
       *  UnaryMinus: '<S523>/Unary Minus'
       */
      rtb_Bias_l = (rtb_Bias_l - (-rtb_Gain1[1])) *
        UAM_Flight_control_P.controlParams.P_PITCH;

      /* Saturate: '<S682>/Saturation' */
      if (rtb_Bias_l > UAM_Flight_control_P.PitchController_UpperSaturation) {
        rtb_Bias_l = UAM_Flight_control_P.PitchController_UpperSaturation;
      } else if (rtb_Bias_l <
                 UAM_Flight_control_P.PitchController_LowerSaturation) {
        rtb_Bias_l = UAM_Flight_control_P.PitchController_LowerSaturation;
      }

      /* Sum: '<S523>/Sum2' incorporates:
       *  Inport: '<Root>/fcc'
       *  Saturate: '<S682>/Saturation'
       *  SignalConversion generated from: '<Root>/fcc'
       *  UnaryMinus: '<S523>/Unary Minus1'
       */
      rtb_qout_idx_1 = rtb_Bias_l - (-UAM_Flight_control_U.fcc.gyro_y);

      /* Gain: '<S724>/Integral Gain' */
      rtb_Gain1_l = UAM_Flight_control_P.controlParams.I_PITCH_RATE *
        rtb_qout_idx_1;

      /* Gain: '<S730>/Filter Coefficient' incorporates:
       *  DiscreteIntegrator: '<S722>/Filter'
       *  Gain: '<S720>/Derivative Gain'
       *  Sum: '<S722>/SumD'
       */
      rtb_IntegralGain_cj = (UAM_Flight_control_P.controlParams.D_PITCH_RATE *
        rtb_qout_idx_1 - UAM_Flight_control_DW.Filter_DSTATE_m) *
        (UAM_Flight_control_P.controlParams.N_PITCH_RATE / 2.7);

      /* Gain: '<S523>/Roll_MAX_angle' */
      rtb_Bias_l = UAM_Flight_control_P.Roll_MAX_angle_Gain_n *
        UAM_Flight_control_B.Merge_d5;

      /* Saturate: '<S523>/Saturation' */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation_UpperSat_e4) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation_UpperSat_e4;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation_LowerSat_o) {
        rtb_Bias_l = UAM_Flight_control_P.Saturation_LowerSat_o;
      }

      /* Gain: '<S784>/Proportional Gain' incorporates:
       *  Saturate: '<S523>/Saturation'
       *  Sum: '<S523>/Sum4'
       */
      rtb_Bias_l = (rtb_Bias_l - rtb_Gain1[2]) *
        UAM_Flight_control_P.controlParams.P_ROLL;

      /* Saturate: '<S786>/Saturation' */
      if (rtb_Bias_l > UAM_Flight_control_P.RollController_UpperSaturationL) {
        rtb_Bias_l = UAM_Flight_control_P.RollController_UpperSaturationL;
      } else if (rtb_Bias_l <
                 UAM_Flight_control_P.RollController_LowerSaturationL) {
        rtb_Bias_l = UAM_Flight_control_P.RollController_LowerSaturationL;
      }

      /* Sum: '<S523>/Sum1' incorporates:
       *  Inport: '<Root>/fcc'
       *  Saturate: '<S786>/Saturation'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      rtb_Bias_l -= UAM_Flight_control_U.fcc.gyro_x;

      /* Gain: '<S828>/Integral Gain' */
      rtb_FilterCoefficient_f = UAM_Flight_control_P.controlParams.I_ROLL_RATE *
        rtb_Bias_l;

      /* Gain: '<S834>/Filter Coefficient' incorporates:
       *  DiscreteIntegrator: '<S826>/Filter'
       *  Gain: '<S824>/Derivative Gain'
       *  Sum: '<S826>/SumD'
       */
      rtb_DeadZone_hh = (UAM_Flight_control_P.controlParams.D_ROLL_RATE *
                         rtb_Bias_l - UAM_Flight_control_DW.Filter_DSTATE_lr) *
        (UAM_Flight_control_P.controlParams.N_ROLL_RATE / 3.5);

      /* Gain: '<S932>/Integral Gain' */
      rtb_hover_est = UAM_Flight_control_P.controlParams.I_YAW_RATE *
        rtb_qout_idx_0;

      /* Sum: '<S840>/Sum' incorporates:
       *  DiscreteIntegrator: '<S831>/Integrator'
       *  Gain: '<S836>/Proportional Gain'
       */
      UAM_Flight_control_B.w_phi =
        (UAM_Flight_control_P.controlParams.P_ROLL_RATE * rtb_Bias_l +
         UAM_Flight_control_DW.Integrator_DSTATE_c) + rtb_DeadZone_hh;

      /* Saturate: '<S838>/Saturation' */
      if (UAM_Flight_control_B.w_phi >
          UAM_Flight_control_P.RollRateController_UpperSatu_c0) {
        /* Sum: '<S840>/Sum' incorporates:
         *  SignalConversion generated from: '<S13>/MixerCommands'
         */
        UAM_Flight_control_B.w_phi =
          UAM_Flight_control_P.RollRateController_UpperSatu_c0;
      } else if (UAM_Flight_control_B.w_phi <
                 UAM_Flight_control_P.RollRateController_LowerSatur_o) {
        /* Sum: '<S840>/Sum' incorporates:
         *  SignalConversion generated from: '<S13>/MixerCommands'
         */
        UAM_Flight_control_B.w_phi =
          UAM_Flight_control_P.RollRateController_LowerSatur_o;
      }

      /* End of Saturate: '<S838>/Saturation' */

      /* Sum: '<S736>/Sum' incorporates:
       *  DiscreteIntegrator: '<S727>/Integrator'
       *  Gain: '<S732>/Proportional Gain'
       */
      UAM_Flight_control_B.w_theta =
        (UAM_Flight_control_P.controlParams.P_PITCH_RATE * rtb_qout_idx_1 +
         UAM_Flight_control_DW.Integrator_DSTATE_h) + rtb_IntegralGain_cj;

      /* Saturate: '<S734>/Saturation' */
      if (UAM_Flight_control_B.w_theta >
          UAM_Flight_control_P.PitchRateController_UpperSatu_h) {
        /* Sum: '<S736>/Sum' incorporates:
         *  SignalConversion generated from: '<S13>/MixerCommands'
         */
        UAM_Flight_control_B.w_theta =
          UAM_Flight_control_P.PitchRateController_UpperSatu_h;
      } else if (UAM_Flight_control_B.w_theta <
                 UAM_Flight_control_P.PitchRateController_LowerSatu_h) {
        /* Sum: '<S736>/Sum' incorporates:
         *  SignalConversion generated from: '<S13>/MixerCommands'
         */
        UAM_Flight_control_B.w_theta =
          UAM_Flight_control_P.PitchRateController_LowerSatu_h;
      }

      /* End of Saturate: '<S734>/Saturation' */

      /* Sum: '<S944>/Sum' incorporates:
       *  DiscreteIntegrator: '<S935>/Integrator'
       *  Gain: '<S940>/Proportional Gain'
       */
      rtb_Bias_l = UAM_Flight_control_P.controlParams.P_YAW_RATE *
        rtb_qout_idx_0 + UAM_Flight_control_DW.Integrator_DSTATE_a;

      /* Saturate: '<S942>/Saturation' */
      if (rtb_Bias_l > UAM_Flight_control_P.Yawratecontroller_UpperSaturati) {
        rtb_Bias_l = UAM_Flight_control_P.Yawratecontroller_UpperSaturati;
      } else if (rtb_Bias_l <
                 UAM_Flight_control_P.Yawratecontroller_LowerSaturati) {
        rtb_Bias_l = UAM_Flight_control_P.Yawratecontroller_LowerSaturati;
      }

      /* Gain: '<S523>/Gain1' incorporates:
       *  Saturate: '<S942>/Saturation'
       */
      UAM_Flight_control_B.w_psi = UAM_Flight_control_P.Gain1_Gain_j *
        rtb_Bias_l;

      /* Saturate: '<S523>/Saturation5' */
      if (UAM_Flight_control_B.w_psi >
          UAM_Flight_control_P.Saturation5_UpperSat_n) {
        /* Gain: '<S523>/Gain1' incorporates:
         *  SignalConversion generated from: '<S13>/MixerCommands'
         */
        UAM_Flight_control_B.w_psi = UAM_Flight_control_P.Saturation5_UpperSat_n;
      } else if (UAM_Flight_control_B.w_psi <
                 UAM_Flight_control_P.Saturation5_LowerSat_o) {
        /* Gain: '<S523>/Gain1' incorporates:
         *  SignalConversion generated from: '<S13>/MixerCommands'
         */
        UAM_Flight_control_B.w_psi = UAM_Flight_control_P.Saturation5_LowerSat_o;
      }

      /* End of Saturate: '<S523>/Saturation5' */

      /* SignalConversion generated from: '<S13>/MixerCommands' incorporates:
       *  UnitDelay: '<S521>/Unit Delay'
       */
      UAM_Flight_control_B.w_z = UAM_Flight_control_DW.UnitDelay_DSTATE_f;
    } else if (UAM_Flight_control_DW.MulticopterController_MODE) {
      /* Disable for Enabled SubSystem: '<S517>/Altitude Control' */
      UAM_Flight_control_DW.AltitudeControl_MODE = false;

      /* End of Disable for SubSystem: '<S517>/Altitude Control' */

      /* Disable for Enabled SubSystem: '<S13>/Horizontal Position Control' */
      if (UAM_Flight_control_DW.HorizontalPositionControl_MODE) {
        /* Disable for Enabled SubSystem: '<S518>/XY Controller' */
        UAM_Flight_control_DW.XYController_MODE = false;

        /* End of Disable for SubSystem: '<S518>/XY Controller' */
        UAM_Flight_control_DW.HorizontalPositionControl_MODE = false;
      }

      /* End of Disable for SubSystem: '<S13>/Horizontal Position Control' */
      UAM_Flight_control_DW.MulticopterController_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S7>/Multicopter Controller' */

    /* Product: '<S10>/Product2' incorporates:
     *  Constant: '<S10>/Constant2'
     *  Constant: '<S522>/Constant'
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     *  Inport: '<Root>/fcc'
     *  Logic: '<S13>/NOT1'
     *  RelationalOperator: '<S522>/Compare'
     *  SignalConversion generated from: '<Root>/fcc'
     *  Sum: '<S10>/Sum1'
     */
    rtb_qout_idx_0 = UAM_Flight_control_B.w_phi * s;
    rtb_qout_idx_1 = UAM_Flight_control_B.w_theta * s;
    rtb_qout_idx_2 = UAM_Flight_control_B.w_psi * s;
    rtb_qout_idx_3 = (0.25 * UAM_Flight_control_P.uavParam.geom.mass * 9.81 +
                      UAM_Flight_control_B.w_z) * s;

    /* Outputs for Enabled SubSystem: '<S7>/Scheduler' incorporates:
     *  EnablePort: '<S14>/ Armed'
     */
    /* Outputs for Enabled SubSystem: '<S7>/Fixed Wing Controller' incorporates:
     *  EnablePort: '<S11>/Actuator Armed'
     */
    if (rtb_Compare_ic) {
      /* Outputs for Enabled SubSystem: '<S17>/AER from Path Manager' incorporates:
       *  EnablePort: '<S18>/Enable'
       */
      if (UAM_Flight_control_B.controlMode_h.attitude == 0) {
        /* Merge: '<S17>/Merge' incorporates:
         *  Constant: '<S12>/Constant'
         *  Constant: '<S12>/Constant2'
         *  Constant: '<S12>/Constant3'
         *  SignalConversion generated from: '<S18>/In1'
         */
        UAM_Flight_control_B.Merge_p[0] = UAM_Flight_control_P.Constant_Value_i;
        UAM_Flight_control_B.Merge_p[1] = UAM_Flight_control_P.Constant2_Value_f;
        UAM_Flight_control_B.Merge_p[2] = UAM_Flight_control_P.Constant3_Value_o;
      }

      /* End of Outputs for SubSystem: '<S17>/AER from Path Manager' */

      /* Outputs for Enabled SubSystem: '<S17>/Airspeed-Altitude Controller' incorporates:
       *  EnablePort: '<S19>/Control Mode'
       */
      if (UAM_Flight_control_B.controlMode_h.airspeedAltitude > 0) {
        /* Outputs for Enabled SubSystem: '<S19>/Altitude controller' incorporates:
         *  EnablePort: '<S26>/Enable'
         */
        if (UAM_Flight_control_B.controlMode_h.airspeedAltitude ==
            UAM_Flight_control_P.CompareToConstant_const_p) {
          /* Gain: '<S123>/Proportional Gain' incorporates:
           *  SignalConversion generated from: '<S17>/AAC SP_BusSelector'
           *  Sum: '<S26>/Sum'
           *  UnaryMinus: '<S26>/Unary Minus'
           */
          UAM_Flight_control_B.ClimbRateSPMerge =
            (UAM_Flight_control_B.AACSP.altitude - (-rtb_Mag_idx_2)) *
            UAM_Flight_control_P.FWControlParams.P_ALT;

          /* Saturate: '<S125>/Saturation' */
          rtb_Bias_l = UAM_Flight_control_P.control.maxDescendRate * 10.0;
          rtb_Product_i5 = UAM_Flight_control_P.control.maxClimbRate * 10.0;
          if (UAM_Flight_control_B.ClimbRateSPMerge > rtb_Product_i5) {
            /* Gain: '<S123>/Proportional Gain' incorporates:
             *  Merge: '<S19>/Climb Rate SP Merge'
             *  SignalConversion generated from: '<S26>/Climb Rate SP'
             */
            UAM_Flight_control_B.ClimbRateSPMerge = rtb_Product_i5;
          } else if (UAM_Flight_control_B.ClimbRateSPMerge < rtb_Bias_l) {
            /* Gain: '<S123>/Proportional Gain' incorporates:
             *  Merge: '<S19>/Climb Rate SP Merge'
             *  SignalConversion generated from: '<S26>/Climb Rate SP'
             */
            UAM_Flight_control_B.ClimbRateSPMerge = rtb_Bias_l;
          }

          /* End of Saturate: '<S125>/Saturation' */
        }

        /* End of Outputs for SubSystem: '<S19>/Altitude controller' */

        /* Outputs for Enabled SubSystem: '<S19>/Climb Rate SP from Guidance' incorporates:
         *  EnablePort: '<S27>/Enable'
         */
        if (UAM_Flight_control_B.controlMode_h.airspeedAltitude ==
            UAM_Flight_control_P.CompareToConstant1_const_c) {
          /* Gain: '<S123>/Proportional Gain' incorporates:
           *  Merge: '<S19>/Climb Rate SP Merge'
           *  RateTransition generated from: '<S2700>/Rate Transition1'
           *  SignalConversion generated from: '<S27>/Climb Rate SP'
           */
          UAM_Flight_control_B.ClimbRateSPMerge =
            UAM_Flight_control_DW.RateTransition1_1_Buffer;
        }

        /* End of Outputs for SubSystem: '<S19>/Climb Rate SP from Guidance' */

        /* Gain: '<S176>/Proportional Gain' incorporates:
         *  Constant: '<S28>/Constant'
         *  Constant: '<S29>/Constant'
         *  Gain: '<S30>/Gain'
         *  RelationalOperator: '<S28>/Compare'
         *  RelationalOperator: '<S29>/Compare'
         *  SignalConversion generated from: '<S2700>/Transpose11'
         *  Sum: '<S30>/Sum2'
         *  UnaryMinus: '<S30>/Unary Minus'
         *  UnitDelay: '<S6>/Unit Delay'
         */
        UAM_Flight_control_B.PitchSPMerge =
          (UAM_Flight_control_B.ClimbRateSPMerge -
           UAM_Flight_control_P.Gain_Gain_js *
           -UAM_Flight_control_DW.UnitDelay_DSTATE) *
          UAM_Flight_control_P.FWControlParams.P_CLIMBRATE;

        /* Saturate: '<S178>/Saturation' */
        if (UAM_Flight_control_B.PitchSPMerge >
            UAM_Flight_control_P.control.maxPitch) {
          /* Gain: '<S176>/Proportional Gain' incorporates:
           *  Merge: '<S17>/Pitch SP Merge'
           *  SignalConversion generated from: '<S19>/Pitch SP'
           */
          UAM_Flight_control_B.PitchSPMerge =
            UAM_Flight_control_P.control.maxPitch;
        } else if (UAM_Flight_control_B.PitchSPMerge <
                   UAM_Flight_control_P.control.minPitch) {
          /* Gain: '<S176>/Proportional Gain' incorporates:
           *  Merge: '<S17>/Pitch SP Merge'
           *  SignalConversion generated from: '<S19>/Pitch SP'
           */
          UAM_Flight_control_B.PitchSPMerge =
            UAM_Flight_control_P.control.minPitch;
        }

        /* End of Saturate: '<S178>/Saturation' */

        /* Sum: '<S19>/Sum1' incorporates:
         *  Inport: '<Root>/fcc'
         *  SignalConversion generated from: '<Root>/fcc'
         */
        rtb_Product_i5 = UAM_Flight_control_B.AACSP.airspeed -
          UAM_Flight_control_U.fcc.airspeed;

        /* Gain: '<S62>/Integral Gain' */
        rtb_Bias_l = UAM_Flight_control_P.FWControlParams.I_AIRSPD *
          rtb_Product_i5;

        /* DiscreteIntegrator: '<S65>/Integrator' */
        Integrator_d = UAM_Flight_control_P.Integrator_gainval_j * rtb_Bias_l +
          UAM_Flight_control_DW.Integrator_DSTATE_cj;

        /* Gain: '<S68>/Filter Coefficient' incorporates:
         *  DiscreteIntegrator: '<S60>/Filter'
         *  Gain: '<S58>/Derivative Gain'
         *  Sum: '<S60>/SumD'
         */
        rtb_FilterCoefficient_l5 =
          (UAM_Flight_control_P.FWControlParams.D_AIRSPD * rtb_Product_i5 -
           UAM_Flight_control_DW.Filter_DSTATE_mx) *
          UAM_Flight_control_P.FWControlParams.N_AIRSPD;

        /* Merge: '<S17>/Actuator dT Merge' incorporates:
         *  Gain: '<S70>/Proportional Gain'
         *  Sum: '<S74>/Sum'
         */
        UAM_Flight_control_B.ActuatordTMerge =
          (UAM_Flight_control_P.FWControlParams.P_AIRSPD * rtb_Product_i5 +
           Integrator_d) + rtb_FilterCoefficient_l5;

        /* Update for DiscreteIntegrator: '<S60>/Filter' */
        UAM_Flight_control_DW.Filter_DSTATE_mx +=
          UAM_Flight_control_P.Filter_gainval_l * rtb_FilterCoefficient_l5;

        /* Update for DiscreteIntegrator: '<S65>/Integrator' */
        UAM_Flight_control_DW.Integrator_DSTATE_cj =
          UAM_Flight_control_P.Integrator_gainval_j * rtb_Bias_l + Integrator_d;
      }

      /* End of Outputs for SubSystem: '<S17>/Airspeed-Altitude Controller' */

      /* Outputs for Enabled SubSystem: '<S17>/Pitch, Airspeed SP from Controller' incorporates:
       *  EnablePort: '<S22>/Enable'
       */
      if (UAM_Flight_control_B.controlMode_h.airspeedAltitude == 0) {
        /* Sum: '<S22>/Sum1' incorporates:
         *  Inport: '<Root>/fcc'
         *  SignalConversion generated from: '<Root>/fcc'
         */
        rtb_FilterCoefficient_l5 = UAM_Flight_control_B.FixedWingSP.airspeed -
          UAM_Flight_control_U.fcc.airspeed;

        /* Gain: '<S501>/Filter Coefficient' incorporates:
         *  DiscreteIntegrator: '<S493>/Filter'
         *  Gain: '<S491>/Derivative Gain'
         *  Sum: '<S493>/SumD'
         */
        rtb_Bias_l = (UAM_Flight_control_P.FWControlParams.D_AIRSPD * 0.0 *
                      rtb_FilterCoefficient_l5 -
                      UAM_Flight_control_DW.Filter_DSTATE_a) *
          UAM_Flight_control_P.FWControlParams.N_AIRSPD;

        /* Gain: '<S495>/Integral Gain' */
        rtb_Product_i5 = UAM_Flight_control_P.FWControlParams.I_AIRSPD * 0.0 *
          rtb_FilterCoefficient_l5;

        /* DiscreteIntegrator: '<S498>/Integrator' */
        Integrator_d = UAM_Flight_control_P.Integrator_gainval_l *
          rtb_Product_i5 + UAM_Flight_control_DW.Integrator_DSTATE_on;

        /* Merge: '<S17>/Actuator dT Merge' incorporates:
         *  Gain: '<S503>/Proportional Gain'
         *  Sum: '<S507>/Sum'
         */
        UAM_Flight_control_B.ActuatordTMerge =
          (UAM_Flight_control_P.FWControlParams.P_AIRSPD *
           rtb_FilterCoefficient_l5 + Integrator_d) + rtb_Bias_l;

        /* InitialCondition: '<S22>/IC' */
        if (UAM_Flight_control_DW.IC_FirstOutputTime_a) {
          UAM_Flight_control_DW.IC_FirstOutputTime_a = false;

          /* Gain: '<S176>/Proportional Gain' incorporates:
           *  InitialCondition: '<S22>/IC'
           *  Merge: '<S17>/Pitch SP Merge'
           */
          UAM_Flight_control_B.PitchSPMerge = UAM_Flight_control_P.IC_Value;
        } else {
          /* Gain: '<S176>/Proportional Gain' incorporates:
           *  Merge: '<S17>/Pitch SP Merge'
           */
          UAM_Flight_control_B.PitchSPMerge =
            UAM_Flight_control_B.FixedWingSP.pitch;
        }

        /* End of InitialCondition: '<S22>/IC' */

        /* Update for DiscreteIntegrator: '<S493>/Filter' */
        UAM_Flight_control_DW.Filter_DSTATE_a +=
          UAM_Flight_control_P.Filter_gainval_g * rtb_Bias_l;

        /* Update for DiscreteIntegrator: '<S498>/Integrator' */
        UAM_Flight_control_DW.Integrator_DSTATE_on =
          UAM_Flight_control_P.Integrator_gainval_l * rtb_Product_i5 +
          Integrator_d;
      }

      /* End of Outputs for SubSystem: '<S17>/Pitch, Airspeed SP from Controller' */

      /* Outputs for Enabled SubSystem: '<S17>/Lateral Guidance Logic' incorporates:
       *  EnablePort: '<S21>/Enable'
       */
      if (UAM_Flight_control_B.controlMode_h.lateralGuidance > 0) {
        /* MATLAB Function: '<S21>/MATLAB Function' incorporates:
         *  RateTransition generated from: '<S2700>/Rate Transition1'
         *  SignalConversion generated from: '<S17>/AAC SP_BusSelector'
         */
        rtb_Product_i5 = UAM_Flight_control_B.AACSP.course -
          UAM_Flight_control_DW.RateTransition1_1_Buffer;
        if (rtIsNaN(rtb_Product_i5)) {
          rtb_Bias_l = (rtNaN);
        } else if (rtIsInf(rtb_Product_i5)) {
          rtb_Bias_l = (rtNaN);
        } else if (rtb_Product_i5 == 0.0) {
          rtb_Bias_l = 0.0;
        } else {
          rtb_Bias_l = fmod(rtb_Product_i5, 6.2831853071795862);
          rtb_IsNaN2 = (rtb_Bias_l == 0.0);
          if (!rtb_IsNaN2) {
            rtb_Product_i5 = fabs(rtb_Product_i5 / 6.2831853071795862);
            rtb_IsNaN2 = !(fabs(rtb_Product_i5 - floor(rtb_Product_i5 + 0.5)) >
                           2.2204460492503131E-16 * rtb_Product_i5);
          }

          if (rtb_IsNaN2) {
            rtb_Bias_l = 0.0;
          } else if (rtb_Bias_l < 0.0) {
            rtb_Bias_l += 6.2831853071795862;
          }
        }

        if (rtb_Bias_l > 3.1415926535897931) {
          rtb_Bias_l -= 6.2831853071795862;
        }

        /* Merge: '<S17>/Roll SP Merge' incorporates:
         *  Inport: '<Root>/fcc'
         *  MATLAB Function: '<S21>/MATLAB Function'
         *  SignalConversion generated from: '<Root>/fcc'
         *  SignalConversion generated from: '<S17>/AAC SP_BusSelector'
         *  SignalConversion generated from: '<S21>/Roll SP'
         */
        UAM_Flight_control_B.RollSPMerge = atan
          (UAM_Flight_control_U.fcc.gndspeed * UAM_Flight_control_U.fcc.gndspeed
           * 2.0 / UAM_Flight_control_B.AACSP.L1 * sin(fmax(fmin(rtb_Bias_l,
              1.5707963267948966), -1.5707963267948966)) / 9.81);
      }

      /* End of Outputs for SubSystem: '<S17>/Lateral Guidance Logic' */

      /* Outputs for Enabled SubSystem: '<S17>/Attitude Controller' incorporates:
       *  EnablePort: '<S20>/Enable'
       */
      if (UAM_Flight_control_B.controlMode_h.attitude > 0) {
        /* Outputs for Enabled SubSystem: '<S20>/Pitch Roll Controller' incorporates:
         *  EnablePort: '<S191>/Enable'
         */
        if (UAM_Flight_control_B.controlMode_h.attitude ==
            UAM_Flight_control_P.CompareToConstant_const_m) {
          /* Saturate: '<S191>/Saturation' */
          if (UAM_Flight_control_B.RollSPMerge >
              UAM_Flight_control_P.control.maxRoll) {
            rtb_Saturation_ny = UAM_Flight_control_P.control.maxRoll;
          } else if (UAM_Flight_control_B.RollSPMerge <
                     UAM_Flight_control_P.control.minRoll) {
            rtb_Saturation_ny = UAM_Flight_control_P.control.minRoll;
          } else {
            rtb_Saturation_ny = UAM_Flight_control_B.RollSPMerge;
          }

          /* End of Saturate: '<S191>/Saturation' */

          /* Gain: '<S191>/Gain2' incorporates:
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           */
          rtb_Product_i5 = UAM_Flight_control_P.Gain2_Gain *
            UAM_Flight_control_U.fcc.gyro_y;

          /* Saturate: '<S191>/Saturation1' */
          if (UAM_Flight_control_B.PitchSPMerge >
              UAM_Flight_control_P.control.maxPitch) {
            rtb_Saturation1_i = UAM_Flight_control_P.control.maxPitch;
          } else if (UAM_Flight_control_B.PitchSPMerge <
                     UAM_Flight_control_P.control.minPitch) {
            rtb_Saturation1_i = UAM_Flight_control_P.control.minPitch;
          } else {
            rtb_Saturation1_i = UAM_Flight_control_B.PitchSPMerge;
          }

          /* End of Saturate: '<S191>/Saturation1' */

          /* Sum: '<S191>/Sum' */
          Integrator_d = rtb_Saturation1_i - rtb_Gain1[1];

          /* Gain: '<S237>/Filter Coefficient' incorporates:
           *  DiscreteIntegrator: '<S229>/Filter'
           *  Gain: '<S227>/Derivative Gain'
           *  Sum: '<S229>/SumD'
           */
          rtb_FilterCoefficient_l5 =
            (UAM_Flight_control_P.FWControlParams.D_FW_PITCH * Integrator_d -
             UAM_Flight_control_DW.Filter_DSTATE_p) *
            UAM_Flight_control_P.FWControlParams.N_FW_PITCH;

          /* Sum: '<S243>/Sum' incorporates:
           *  DiscreteIntegrator: '<S234>/Integrator'
           *  Gain: '<S239>/Proportional Gain'
           */
          rtb_DeadZone_b = (UAM_Flight_control_P.FWControlParams.P_FW_PITCH *
                            Integrator_d +
                            UAM_Flight_control_DW.Integrator_DSTATE_d) +
            rtb_FilterCoefficient_l5;

          /* Saturate: '<S241>/Saturation' */
          if (rtb_DeadZone_b >
              UAM_Flight_control_P.PitchAngleController_UpperSat_j) {
            rtb_Bias_l = UAM_Flight_control_P.PitchAngleController_UpperSat_j;
          } else if (rtb_DeadZone_b <
                     UAM_Flight_control_P.PitchAngleController_LowerSat_a) {
            rtb_Bias_l = UAM_Flight_control_P.PitchAngleController_LowerSat_a;
          } else {
            rtb_Bias_l = rtb_DeadZone_b;
          }

          /* Gain: '<S291>/Proportional Gain' incorporates:
           *  Saturate: '<S241>/Saturation'
           *  Sum: '<S191>/Sum3'
           */
          rtb_Saturation_o = (rtb_Bias_l - rtb_Product_i5) *
            UAM_Flight_control_P.PitchRateController_P;

          /* MATLAB Function: '<S197>/MATLAB Function' incorporates:
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           */
          UAM_Flight_c_MATLABFunction(rtb_Saturation_ny, rtb_Saturation1_i,
            UAM_Flight_control_U.fcc.airspeed, &rtb_Product_i5);

          /* Gain: '<S343>/Proportional Gain' incorporates:
           *  Sum: '<S191>/Sum1'
           */
          rtb_Bias_l = (rtb_Saturation_ny - rtb_Gain1[2]) *
            UAM_Flight_control_P.FWControlParams.P_FW_ROLL;

          /* Saturate: '<S345>/Saturation' */
          if (rtb_Bias_l > UAM_Flight_control_P.control.maxRollRate) {
            rtb_Bias_l = UAM_Flight_control_P.control.maxRollRate;
          } else if (rtb_Bias_l < UAM_Flight_control_P.control.minRollRate) {
            rtb_Bias_l = UAM_Flight_control_P.control.minRollRate;
          }

          /* Gain: '<S395>/Proportional Gain' incorporates:
           *  Gain: '<S191>/Gain1'
           *  Inport: '<Root>/fcc'
           *  Saturate: '<S345>/Saturation'
           *  SignalConversion generated from: '<Root>/fcc'
           *  Sum: '<S191>/Sum2'
           */
          rtb_Bias_l = (rtb_Bias_l - UAM_Flight_control_P.Gain1_Gain_m *
                        UAM_Flight_control_U.fcc.gyro_x) *
            UAM_Flight_control_P.FWControlParams.P_FW_ROLLRATE;

          /* Saturate: '<S397>/Saturation' */
          if (rtb_Bias_l > UAM_Flight_control_P.RollRateController_UpperSatur_c)
          {
            rtb_Bias_l = UAM_Flight_control_P.RollRateController_UpperSatur_c;
          } else if (rtb_Bias_l <
                     UAM_Flight_control_P.RollRateController_LowerSatur_c) {
            rtb_Bias_l = UAM_Flight_control_P.RollRateController_LowerSatur_c;
          }

          /* End of Saturate: '<S397>/Saturation' */

          /* Saturate: '<S191>/Saturation2' */
          if (rtb_Bias_l > UAM_Flight_control_P.Saturation2_UpperSat_p) {
            /* Merge: '<S17>/Merge' incorporates:
             *  SignalConversion generated from: '<S191>/AER'
             */
            UAM_Flight_control_B.Merge_p[0] =
              UAM_Flight_control_P.Saturation2_UpperSat_p;
          } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation2_LowerSat_e) {
            /* Merge: '<S17>/Merge' incorporates:
             *  SignalConversion generated from: '<S191>/AER'
             */
            UAM_Flight_control_B.Merge_p[0] =
              UAM_Flight_control_P.Saturation2_LowerSat_e;
          } else {
            /* Merge: '<S17>/Merge' incorporates:
             *  SignalConversion generated from: '<S191>/AER'
             */
            UAM_Flight_control_B.Merge_p[0] = rtb_Bias_l;
          }

          /* End of Saturate: '<S191>/Saturation2' */

          /* Saturate: '<S293>/Saturation' */
          if (rtb_Saturation_o >
              UAM_Flight_control_P.PitchRateController_UpperSatu_p) {
            /* Merge: '<S17>/Merge' incorporates:
             *  SignalConversion generated from: '<S191>/AER'
             */
            UAM_Flight_control_B.Merge_p[1] =
              UAM_Flight_control_P.PitchRateController_UpperSatu_p;
          } else if (rtb_Saturation_o <
                     UAM_Flight_control_P.PitchRateController_LowerSatu_k) {
            /* Merge: '<S17>/Merge' incorporates:
             *  SignalConversion generated from: '<S191>/AER'
             */
            UAM_Flight_control_B.Merge_p[1] =
              UAM_Flight_control_P.PitchRateController_LowerSatu_k;
          } else {
            /* Merge: '<S17>/Merge' incorporates:
             *  SignalConversion generated from: '<S191>/AER'
             */
            UAM_Flight_control_B.Merge_p[1] = rtb_Saturation_o;
          }

          /* End of Saturate: '<S293>/Saturation' */

          /* Gain: '<S449>/Proportional Gain' incorporates:
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           *  Sum: '<S197>/Sum'
           */
          rtb_Bias_l = (rtb_Product_i5 - UAM_Flight_control_U.fcc.gyro_z) *
            UAM_Flight_control_P.RudderController_P_a;

          /* Saturate: '<S451>/Saturation' */
          if (rtb_Bias_l > UAM_Flight_control_P.RudderController_UpperSaturat_g)
          {
            /* Merge: '<S17>/Merge' incorporates:
             *  SignalConversion generated from: '<S191>/AER'
             */
            UAM_Flight_control_B.Merge_p[2] =
              UAM_Flight_control_P.RudderController_UpperSaturat_g;
          } else if (rtb_Bias_l <
                     UAM_Flight_control_P.RudderController_LowerSaturat_e) {
            /* Merge: '<S17>/Merge' incorporates:
             *  SignalConversion generated from: '<S191>/AER'
             */
            UAM_Flight_control_B.Merge_p[2] =
              UAM_Flight_control_P.RudderController_LowerSaturat_e;
          } else {
            /* Merge: '<S17>/Merge' incorporates:
             *  SignalConversion generated from: '<S191>/AER'
             */
            UAM_Flight_control_B.Merge_p[2] = rtb_Bias_l;
          }

          /* End of Saturate: '<S451>/Saturation' */

          /* DeadZone: '<S226>/DeadZone' */
          if (rtb_DeadZone_b >
              UAM_Flight_control_P.PitchAngleController_UpperSat_j) {
            rtb_DeadZone_b -=
              UAM_Flight_control_P.PitchAngleController_UpperSat_j;
          } else if (rtb_DeadZone_b >=
                     UAM_Flight_control_P.PitchAngleController_LowerSat_a) {
            rtb_DeadZone_b = 0.0;
          } else {
            rtb_DeadZone_b -=
              UAM_Flight_control_P.PitchAngleController_LowerSat_a;
          }

          /* End of DeadZone: '<S226>/DeadZone' */

          /* Gain: '<S231>/Integral Gain' */
          Integrator_d *= UAM_Flight_control_P.FWControlParams.I_FW_PITCH;

          /* Switch: '<S224>/Switch1' incorporates:
           *  Constant: '<S224>/Clamping_zero'
           *  Constant: '<S224>/Constant'
           *  Constant: '<S224>/Constant2'
           *  RelationalOperator: '<S224>/fix for DT propagation issue'
           */
          if (rtb_DeadZone_b > UAM_Flight_control_P.Clamping_zero_Value_ba) {
            rtAction = UAM_Flight_control_P.Constant_Value_fs;
          } else {
            rtAction = UAM_Flight_control_P.Constant2_Value_cf;
          }

          /* Switch: '<S224>/Switch2' incorporates:
           *  Constant: '<S224>/Clamping_zero'
           *  Constant: '<S224>/Constant3'
           *  Constant: '<S224>/Constant4'
           *  RelationalOperator: '<S224>/fix for DT propagation issue1'
           */
          if (Integrator_d > UAM_Flight_control_P.Clamping_zero_Value_ba) {
            tmp_1 = UAM_Flight_control_P.Constant3_Value_a;
          } else {
            tmp_1 = UAM_Flight_control_P.Constant4_Value_a;
          }

          /* Switch: '<S224>/Switch' incorporates:
           *  Constant: '<S224>/Clamping_zero'
           *  Constant: '<S224>/Constant1'
           *  Logic: '<S224>/AND3'
           *  RelationalOperator: '<S224>/Equal1'
           *  RelationalOperator: '<S224>/Relational Operator'
           *  Switch: '<S224>/Switch1'
           *  Switch: '<S224>/Switch2'
           */
          if ((UAM_Flight_control_P.Clamping_zero_Value_ba != rtb_DeadZone_b) &&
              (rtAction == tmp_1)) {
            Integrator_d = UAM_Flight_control_P.Constant1_Value_le;
          }

          /* Update for DiscreteIntegrator: '<S234>/Integrator' incorporates:
           *  Switch: '<S224>/Switch'
           */
          UAM_Flight_control_DW.Integrator_DSTATE_d +=
            UAM_Flight_control_P.Integrator_gainval_k * Integrator_d;

          /* Update for DiscreteIntegrator: '<S229>/Filter' */
          UAM_Flight_control_DW.Filter_DSTATE_p +=
            UAM_Flight_control_P.Filter_gainval_o * rtb_FilterCoefficient_l5;
        }

        /* End of Outputs for SubSystem: '<S20>/Pitch Roll Controller' */

        /* Outputs for Enabled SubSystem: '<S20>/Rudder Heading Controller' incorporates:
         *  EnablePort: '<S192>/Enable'
         */
        if (UAM_Flight_control_B.controlMode_h.attitude ==
            UAM_Flight_control_P.CompareToConstant1_const_k) {
          /* Merge: '<S17>/Merge' incorporates:
           *  Constant: '<S192>/Constant'
           *  Constant: '<S192>/Constant1'
           *  SignalConversion generated from: '<S192>/AER'
           */
          UAM_Flight_control_B.Merge_p[0] =
            UAM_Flight_control_P.Constant_Value_c;
          UAM_Flight_control_B.Merge_p[1] =
            UAM_Flight_control_P.Constant_Value_c;
          UAM_Flight_control_B.Merge_p[2] =
            UAM_Flight_control_P.Constant1_Value_k;
        }

        /* End of Outputs for SubSystem: '<S20>/Rudder Heading Controller' */
      }

      /* End of Outputs for SubSystem: '<S17>/Attitude Controller' */

      /* MATLAB Function: '<S24>/MATLAB Function' incorporates:
       *  Constant: '<S189>/Constant'
       *  Constant: '<S190>/Constant'
       *  Constant: '<S28>/Constant'
       *  Constant: '<S29>/Constant'
       *  Logic: '<S17>/NOT1'
       *  Logic: '<S17>/NOT2'
       *  RelationalOperator: '<S189>/Compare'
       *  RelationalOperator: '<S190>/Compare'
       *  RelationalOperator: '<S28>/Compare'
       *  RelationalOperator: '<S29>/Compare'
       */
      UAM_Flight_MATLABFunction_a(rtb_Gain1[2], rtb_Gain1[1], rtb_R);
      UAM_Flight_control_DW.Scheduler_MODE_g = true;

      /* SwitchCase: '<S1175>/Switch Case' */
      switch (UAM_Flight_control_B.FlightMode) {
       case Hover:
        /* Outputs for IfAction SubSystem: '<S1175>/Switch Case Action Subsystem' incorporates:
         *  ActionPort: '<S1177>/Action Port'
         */
        U_SwitchCaseActionSubsystem(&UAM_Flight_control_B.Merge_b,
          &UAM_Flight_control_P.SwitchCaseActionSubsystem_g);

        /* End of Outputs for SubSystem: '<S1175>/Switch Case Action Subsystem' */
        break;

       case Transition:
        /* Outputs for IfAction SubSystem: '<S1175>/Switch Case Action Subsystem1' incorporates:
         *  ActionPort: '<S1178>/Action Port'
         */
        /* BusCreator: '<S1178>/Bus Creator1' incorporates:
         *  Constant: '<S1178>/Constant4'
         *  Constant: '<S1178>/Constant5'
         *  Constant: '<S1178>/Constant6'
         */
        UAM_Flight_control_B.Merge_b.dA = UAM_Flight_control_P.Constant6_Value_o;
        UAM_Flight_control_B.Merge_b.dE = UAM_Flight_control_B.Merge_p[1];
        UAM_Flight_control_B.Merge_b.dR = UAM_Flight_control_P.Constant4_Value_e;
        UAM_Flight_control_B.Merge_b.dT = UAM_Flight_control_P.Constant5_Value_l;

        /* End of Outputs for SubSystem: '<S1175>/Switch Case Action Subsystem1' */
        break;

       case FixedWing:
        /* Outputs for IfAction SubSystem: '<S1175>/Switch Case Action Subsystem2' incorporates:
         *  ActionPort: '<S1179>/Action Port'
         */
        /* BusCreator: '<S1179>/Bus Creator1' */
        UAM_Flight_control_B.Merge_b.dA = UAM_Flight_control_B.Merge_p[0];
        UAM_Flight_control_B.Merge_b.dE = UAM_Flight_control_B.Merge_p[1];
        UAM_Flight_control_B.Merge_b.dR = UAM_Flight_control_B.Merge_p[2];
        UAM_Flight_control_B.Merge_b.dT = UAM_Flight_control_B.ActuatordTMerge;

        /* End of Outputs for SubSystem: '<S1175>/Switch Case Action Subsystem2' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S1175>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S1180>/Action Port'
         */
        U_SwitchCaseActionSubsystem(&UAM_Flight_control_B.Merge_b,
          &UAM_Flight_control_P.SwitchCaseActionSubsystem3_e);

        /* End of Outputs for SubSystem: '<S1175>/Switch Case Action Subsystem3' */
        break;
      }

      /* End of SwitchCase: '<S1175>/Switch Case' */

      /* SignalConversion generated from: '<S14>/CtrlSurfaceCommands' */
      UAM_Flight_control_B.OutportBufferForCtrlSurfaceCo_i =
        UAM_Flight_control_B.Merge_b;

      /* SwitchCase: '<S1176>/Switch Case' */
      switch (UAM_Flight_control_B.FlightMode) {
       case Hover:
        /* Outputs for IfAction SubSystem: '<S1176>/Switch Case Action Subsystem' incorporates:
         *  ActionPort: '<S1182>/Action Port'
         */
        /* MATLAB Function: '<S1182>/Desaturation' incorporates:
         *  Constant: '<S1182>/Constant'
         *  Product: '<S1182>/Matrix Multiply'
         *  SignalConversion generated from: '<S1182>/Matrix Multiply'
         */
        for (i = 0; i < 4; i++) {
          rtb_dq[i] = ((UAM_Flight_control_P.Constant_Value_k5[i + 4] *
                        rtb_qout_idx_0 +
                        UAM_Flight_control_P.Constant_Value_k5[i] *
                        rtb_qout_idx_3) +
                       UAM_Flight_control_P.Constant_Value_k5[i + 8] *
                       rtb_qout_idx_1) +
            UAM_Flight_control_P.Constant_Value_k5[i + 12] * rtb_qout_idx_2;
          tmp[i] = 0.0;
          tmp_0[i] = 1.0;
        }

        UAM_Flight_control_desat_axis(rtb_dq,
          &UAM_Flight_control_P.Constant_Value_k5[0], tmp, tmp_0, false);
        tmp[0] = 0.0;
        tmp_0[0] = 1.15;
        tmp[1] = 0.0;
        tmp_0[1] = 1.15;
        tmp[2] = 0.0;
        tmp_0[2] = 1.15;
        tmp[3] = 0.0;
        tmp_0[3] = 1.15;
        UAM_Flight_control_desat_axis(rtb_dq,
          &UAM_Flight_control_P.Constant_Value_k5[12], tmp, tmp_0, false);
        tmp[0] = 0.0;
        tmp_0[0] = 1.0;
        tmp[1] = 0.0;
        tmp_0[1] = 1.0;
        tmp[2] = 0.0;
        tmp_0[2] = 1.0;
        tmp[3] = 0.0;
        tmp_0[3] = 1.0;
        UAM_Flight_control_desat_axis(rtb_dq,
          &UAM_Flight_control_P.Constant_Value_k5[0], tmp, tmp_0, true);
        rtb_dq[0] = fmax(0.0, fmin(1.0, rtb_dq[0]));
        rtb_dq[1] = fmax(0.0, fmin(1.0, rtb_dq[1]));
        rtb_dq[2] = fmax(0.0, fmin(1.0, rtb_dq[2]));

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  SignalConversion generated from: '<S1182>/Actuator_Outport_1'
         */
        UAM_Flight_control_B.w1_j = rtb_dq[0];

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  SignalConversion generated from: '<S1182>/Actuator_Outport_1'
         */
        UAM_Flight_control_B.w2_i = rtb_dq[1];

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  SignalConversion generated from: '<S1182>/Actuator_Outport_1'
         */
        UAM_Flight_control_B.w3_o = rtb_dq[2];

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  MATLAB Function: '<S1182>/Desaturation'
         *  SignalConversion generated from: '<S1182>/Actuator_Outport_1'
         */
        UAM_Flight_control_B.w4_g = fmax(0.0, fmin(1.0, rtb_dq[3]));

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  Constant: '<S1182>/Constant4'
         *  SignalConversion generated from: '<S1182>/Actuator_Outport_1'
         */
        UAM_Flight_control_B.c1_i = UAM_Flight_control_P.Constant4_Value_j;

        /* End of Outputs for SubSystem: '<S1176>/Switch Case Action Subsystem' */
        break;

       case Transition:
        /* Outputs for IfAction SubSystem: '<S1176>/Switch Case Action Subsystem1' incorporates:
         *  ActionPort: '<S1183>/Action Port'
         */
        /* Sum: '<S1183>/Add' incorporates:
         *  Sum: '<S1183>/Add2'
         */
        rtb_Product_i5 = rtb_qout_idx_3 - rtb_qout_idx_2;
        rtb_Bias_l = (rtb_Product_i5 - rtb_qout_idx_0) - rtb_qout_idx_1;

        /* Saturate: '<S1183>/Saturation4' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation4_UpperSat_g) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation4_UpperSat_g;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation4_LowerSat_m) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation4_LowerSat_m;
        }

        /* End of Saturate: '<S1183>/Saturation4' */

        /* Sqrt: '<S1183>/Sqrt1'
         *
         * About '<S1183>/Sqrt1':
         *  Operator: signedSqrt
         */
        if (rtb_Bias_l < 0.0) {
          rtb_Bias_l = -sqrt(fabs(rtb_Bias_l));
        } else {
          rtb_Bias_l = sqrt(rtb_Bias_l);
        }

        /* Gain: '<S1183>/Gain1' incorporates:
         *  Gain: '<S1183>/Gain2'
         *  Gain: '<S1183>/Gain3'
         *  Gain: '<S1183>/Gain4'
         */
        Integrator_d = UAM_Flight_control_P.w_trim / sqrt(0.25 *
          UAM_Flight_control_P.uavParam.geom.mass * 9.81);

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  Gain: '<S1183>/Gain1'
         *  SignalConversion generated from: '<S1183>/Actuator_Outport_1'
         *  Sqrt: '<S1183>/Sqrt1'
         *
         * About '<S1183>/Sqrt1':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w1_j = Integrator_d * rtb_Bias_l;

        /* Sum: '<S1183>/Add1' incorporates:
         *  Sum: '<S1183>/Add3'
         */
        rtb_qout_idx_2 += rtb_qout_idx_3;
        rtb_Bias_l = (rtb_qout_idx_2 + rtb_qout_idx_0) - rtb_qout_idx_1;

        /* Saturate: '<S1183>/Saturation1' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation1_UpperSat_nf) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation1_UpperSat_nf;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation1_LowerSat_h) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation1_LowerSat_h;
        }

        /* End of Saturate: '<S1183>/Saturation1' */

        /* Sqrt: '<S1183>/Sqrt2'
         *
         * About '<S1183>/Sqrt2':
         *  Operator: signedSqrt
         */
        if (rtb_Bias_l < 0.0) {
          rtb_Bias_l = -sqrt(fabs(rtb_Bias_l));
        } else {
          rtb_Bias_l = sqrt(rtb_Bias_l);
        }

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  Gain: '<S1183>/Gain2'
         *  SignalConversion generated from: '<S1183>/Actuator_Outport_1'
         *  Sqrt: '<S1183>/Sqrt2'
         *
         * About '<S1183>/Sqrt2':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w2_i = Integrator_d * rtb_Bias_l;

        /* Sum: '<S1183>/Add2' */
        rtb_Bias_l = (rtb_Product_i5 + rtb_qout_idx_0) + rtb_qout_idx_1;

        /* Saturate: '<S1183>/Saturation2' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation2_UpperSat_a) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation2_UpperSat_a;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation2_LowerSat_d) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation2_LowerSat_d;
        }

        /* End of Saturate: '<S1183>/Saturation2' */

        /* Sqrt: '<S1183>/Sqrt3'
         *
         * About '<S1183>/Sqrt3':
         *  Operator: signedSqrt
         */
        if (rtb_Bias_l < 0.0) {
          rtb_Bias_l = -sqrt(fabs(rtb_Bias_l));
        } else {
          rtb_Bias_l = sqrt(rtb_Bias_l);
        }

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  Gain: '<S1183>/Gain3'
         *  SignalConversion generated from: '<S1183>/Actuator_Outport_1'
         *  Sqrt: '<S1183>/Sqrt3'
         *
         * About '<S1183>/Sqrt3':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w3_o = Integrator_d * rtb_Bias_l;

        /* Sum: '<S1183>/Add3' */
        rtb_Bias_l = (rtb_qout_idx_2 - rtb_qout_idx_0) + rtb_qout_idx_1;

        /* Saturate: '<S1183>/Saturation3' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation3_UpperSat_g) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation3_UpperSat_g;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation3_LowerSat_p) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation3_LowerSat_p;
        }

        /* End of Saturate: '<S1183>/Saturation3' */

        /* Sqrt: '<S1183>/Sqrt4'
         *
         * About '<S1183>/Sqrt4':
         *  Operator: signedSqrt
         */
        if (rtb_Bias_l < 0.0) {
          rtb_Bias_l = -sqrt(fabs(rtb_Bias_l));
        } else {
          rtb_Bias_l = sqrt(rtb_Bias_l);
        }

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  Gain: '<S1183>/Gain4'
         *  SignalConversion generated from: '<S1183>/Actuator_Outport_1'
         *  Sqrt: '<S1183>/Sqrt4'
         *
         * About '<S1183>/Sqrt4':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w4_g = Integrator_d * rtb_Bias_l;

        /* End of Outputs for SubSystem: '<S1176>/Switch Case Action Subsystem1' */

        /* Switch: '<S10>/Switch1' */
        if (rtb_Compare_j) {
          /* Outputs for IfAction SubSystem: '<S1176>/Switch Case Action Subsystem1' incorporates:
           *  ActionPort: '<S1183>/Action Port'
           */
          /* Merge generated from: '<S1176>/Merge' incorporates:
           *  Constant: '<S10>/Constant4'
           *  Constant: '<S10>/Constant6'
           *  Product: '<S10>/Product1'
           *  SignalConversion generated from: '<S1183>/Actuator_Outport_1'
           *  Sum: '<S10>/Sum3'
           */
          UAM_Flight_control_B.c1_i = UAM_Flight_control_P.FWTrimSpeed -
            UAM_Flight_control_P.Constant6_Value_h * s;

          /* End of Outputs for SubSystem: '<S1176>/Switch Case Action Subsystem1' */
        } else {
          /* Outputs for IfAction SubSystem: '<S1176>/Switch Case Action Subsystem1' incorporates:
           *  ActionPort: '<S1183>/Action Port'
           */
          /* Merge generated from: '<S1176>/Merge' incorporates:
           *  Constant: '<S10>/Constant3'
           *  Constant: '<S10>/Constant5'
           *  Gain: '<S10>/Gain3'
           *  Product: '<S10>/Product3'
           *  SignalConversion generated from: '<S1183>/Actuator_Outport_1'
           *  Sum: '<S10>/Subtract'
           */
          UAM_Flight_control_B.c1_i = UAM_Flight_control_P.Gain3_Gain_l *
            UAM_Flight_control_P.FWTrimSpeed *
            (UAM_Flight_control_P.Constant5_Value - s);

          /* End of Outputs for SubSystem: '<S1176>/Switch Case Action Subsystem1' */
        }
        break;

       case FixedWing:
        /* Outputs for IfAction SubSystem: '<S1176>/Switch Case Action Subsystem2' incorporates:
         *  ActionPort: '<S1184>/Action Port'
         */
        SwitchCaseActionSubsystem_m(&UAM_Flight_control_B.Merge_b,
          &UAM_Flight_control_B.w1_j, &UAM_Flight_control_B.w2_i,
          &UAM_Flight_control_B.w3_o, &UAM_Flight_control_B.w4_g,
          &UAM_Flight_control_B.c1_i,
          &UAM_Flight_control_P.SwitchCaseActionSubsystem2_m);

        /* End of Outputs for SubSystem: '<S1176>/Switch Case Action Subsystem2' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S1176>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S1185>/Action Port'
         */
        /* Sum: '<S1185>/Add' incorporates:
         *  Sum: '<S1185>/Add2'
         */
        rtb_Product_i5 = rtb_qout_idx_3 - rtb_qout_idx_2;
        rtb_Bias_l = (rtb_Product_i5 - rtb_qout_idx_0) - rtb_qout_idx_1;

        /* Saturate: '<S1185>/Saturation4' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation4_UpperSat_m) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation4_UpperSat_m;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation4_LowerSat_a) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation4_LowerSat_a;
        }

        /* End of Saturate: '<S1185>/Saturation4' */

        /* Sqrt: '<S1185>/Sqrt1'
         *
         * About '<S1185>/Sqrt1':
         *  Operator: signedSqrt
         */
        if (rtb_Bias_l < 0.0) {
          rtb_Bias_l = -sqrt(fabs(rtb_Bias_l));
        } else {
          rtb_Bias_l = sqrt(rtb_Bias_l);
        }

        /* Gain: '<S1185>/Gain1' incorporates:
         *  Gain: '<S1185>/Gain2'
         *  Gain: '<S1185>/Gain3'
         *  Gain: '<S1185>/Gain4'
         */
        Integrator_d = UAM_Flight_control_P.w_trim / sqrt(0.25 *
          UAM_Flight_control_P.uavParam.geom.mass * 9.81);

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  Gain: '<S1185>/Gain1'
         *  SignalConversion generated from: '<S1185>/Actuator_Outport_1'
         *  Sqrt: '<S1185>/Sqrt1'
         *
         * About '<S1185>/Sqrt1':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w1_j = Integrator_d * rtb_Bias_l;

        /* Sum: '<S1185>/Add1' incorporates:
         *  Sum: '<S1185>/Add3'
         */
        rtb_qout_idx_2 += rtb_qout_idx_3;
        rtb_Bias_l = (rtb_qout_idx_2 + rtb_qout_idx_0) - rtb_qout_idx_1;

        /* Saturate: '<S1185>/Saturation1' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation1_UpperSat_b) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation1_UpperSat_b;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation1_LowerSat_ir) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation1_LowerSat_ir;
        }

        /* End of Saturate: '<S1185>/Saturation1' */

        /* Sqrt: '<S1185>/Sqrt2'
         *
         * About '<S1185>/Sqrt2':
         *  Operator: signedSqrt
         */
        if (rtb_Bias_l < 0.0) {
          rtb_Bias_l = -sqrt(fabs(rtb_Bias_l));
        } else {
          rtb_Bias_l = sqrt(rtb_Bias_l);
        }

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  Gain: '<S1185>/Gain2'
         *  SignalConversion generated from: '<S1185>/Actuator_Outport_1'
         *  Sqrt: '<S1185>/Sqrt2'
         *
         * About '<S1185>/Sqrt2':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w2_i = Integrator_d * rtb_Bias_l;

        /* Sum: '<S1185>/Add2' */
        rtb_Bias_l = (rtb_Product_i5 + rtb_qout_idx_0) + rtb_qout_idx_1;

        /* Saturate: '<S1185>/Saturation2' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation2_UpperSat_n) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation2_UpperSat_n;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation2_LowerSat_g) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation2_LowerSat_g;
        }

        /* End of Saturate: '<S1185>/Saturation2' */

        /* Sqrt: '<S1185>/Sqrt3'
         *
         * About '<S1185>/Sqrt3':
         *  Operator: signedSqrt
         */
        if (rtb_Bias_l < 0.0) {
          rtb_Bias_l = -sqrt(fabs(rtb_Bias_l));
        } else {
          rtb_Bias_l = sqrt(rtb_Bias_l);
        }

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  Gain: '<S1185>/Gain3'
         *  SignalConversion generated from: '<S1185>/Actuator_Outport_1'
         *  Sqrt: '<S1185>/Sqrt3'
         *
         * About '<S1185>/Sqrt3':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w3_o = Integrator_d * rtb_Bias_l;

        /* Sum: '<S1185>/Add3' */
        rtb_Bias_l = (rtb_qout_idx_2 - rtb_qout_idx_0) + rtb_qout_idx_1;

        /* Saturate: '<S1185>/Saturation3' */
        if (rtb_Bias_l > UAM_Flight_control_P.Saturation3_UpperSat_k) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation3_UpperSat_k;
        } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation3_LowerSat_n) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation3_LowerSat_n;
        }

        /* End of Saturate: '<S1185>/Saturation3' */

        /* Sqrt: '<S1185>/Sqrt4'
         *
         * About '<S1185>/Sqrt4':
         *  Operator: signedSqrt
         */
        if (rtb_Bias_l < 0.0) {
          rtb_Bias_l = -sqrt(fabs(rtb_Bias_l));
        } else {
          rtb_Bias_l = sqrt(rtb_Bias_l);
        }

        /* Merge generated from: '<S1176>/Merge' incorporates:
         *  Gain: '<S1185>/Gain4'
         *  SignalConversion generated from: '<S1185>/Actuator_Outport_1'
         *  Sqrt: '<S1185>/Sqrt4'
         *
         * About '<S1185>/Sqrt4':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w4_g = Integrator_d * rtb_Bias_l;

        /* End of Outputs for SubSystem: '<S1176>/Switch Case Action Subsystem3' */

        /* Switch: '<S10>/Switch1' */
        if (rtb_Compare_j) {
          /* Outputs for IfAction SubSystem: '<S1176>/Switch Case Action Subsystem3' incorporates:
           *  ActionPort: '<S1185>/Action Port'
           */
          /* Merge generated from: '<S1176>/Merge' incorporates:
           *  Constant: '<S10>/Constant4'
           *  Constant: '<S10>/Constant6'
           *  Product: '<S10>/Product1'
           *  SignalConversion generated from: '<S1185>/Actuator_Outport_1'
           *  Sum: '<S10>/Sum3'
           */
          UAM_Flight_control_B.c1_i = UAM_Flight_control_P.FWTrimSpeed -
            UAM_Flight_control_P.Constant6_Value_h * s;

          /* End of Outputs for SubSystem: '<S1176>/Switch Case Action Subsystem3' */
        } else {
          /* Outputs for IfAction SubSystem: '<S1176>/Switch Case Action Subsystem3' incorporates:
           *  ActionPort: '<S1185>/Action Port'
           */
          /* Merge generated from: '<S1176>/Merge' incorporates:
           *  Constant: '<S10>/Constant3'
           *  Constant: '<S10>/Constant5'
           *  Gain: '<S10>/Gain3'
           *  Product: '<S10>/Product3'
           *  SignalConversion generated from: '<S1185>/Actuator_Outport_1'
           *  Sum: '<S10>/Subtract'
           */
          UAM_Flight_control_B.c1_i = UAM_Flight_control_P.Gain3_Gain_l *
            UAM_Flight_control_P.FWTrimSpeed *
            (UAM_Flight_control_P.Constant5_Value - s);

          /* End of Outputs for SubSystem: '<S1176>/Switch Case Action Subsystem3' */
        }
        break;
      }

      /* End of SwitchCase: '<S1176>/Switch Case' */
      UAM_Flight_control_B.VectorConcatenate_f[5] =
        UAM_Flight_control_P.Constant_Value_gi;

      /* Sum: '<S1181>/Add1' incorporates:
       *  Concatenate: '<S1181>/Vector Concatenate'
       *  Constant: '<S1181>/Constant'
       *  Constant: '<S1181>/Constant2'
       *  Gain: '<S1181>/Gain1'
       */
      rtb_Bias_l = UAM_Flight_control_P.Gain1_Gain_c * UAM_Flight_control_B.w1_j
        + UAM_Flight_control_P.Constant2_Value_h;

      /* Saturate: '<S1181>/Saturation' incorporates:
       *  Concatenate: '<S1181>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation_UpperSat_h) {
        UAM_Flight_control_B.VectorConcatenate_f[0] =
          UAM_Flight_control_P.Saturation_UpperSat_h;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation_LowerSat_ff) {
        UAM_Flight_control_B.VectorConcatenate_f[0] =
          UAM_Flight_control_P.Saturation_LowerSat_ff;
      } else {
        UAM_Flight_control_B.VectorConcatenate_f[0] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1181>/Saturation' */

      /* Sum: '<S1181>/Add3' incorporates:
       *  Constant: '<S1181>/Constant4'
       *  Gain: '<S1181>/Gain3'
       */
      rtb_Bias_l = UAM_Flight_control_P.Gain3_Gain_a * UAM_Flight_control_B.w2_i
        + UAM_Flight_control_P.Constant4_Value_je;

      /* Saturate: '<S1181>/Saturation1' incorporates:
       *  Concatenate: '<S1181>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation1_UpperSat_d) {
        UAM_Flight_control_B.VectorConcatenate_f[1] =
          UAM_Flight_control_P.Saturation1_UpperSat_d;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation1_LowerSat_d) {
        UAM_Flight_control_B.VectorConcatenate_f[1] =
          UAM_Flight_control_P.Saturation1_LowerSat_d;
      } else {
        UAM_Flight_control_B.VectorConcatenate_f[1] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1181>/Saturation1' */

      /* Sum: '<S1181>/Add7' incorporates:
       *  Constant: '<S1181>/Constant8'
       *  Gain: '<S1181>/Gain7'
       */
      rtb_Bias_l = UAM_Flight_control_P.Gain7_Gain_j * UAM_Flight_control_B.w3_o
        + UAM_Flight_control_P.Constant8_Value_a;

      /* Saturate: '<S1181>/Saturation2' incorporates:
       *  Concatenate: '<S1181>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation2_UpperSat_pi) {
        UAM_Flight_control_B.VectorConcatenate_f[2] =
          UAM_Flight_control_P.Saturation2_UpperSat_pi;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation2_LowerSat_l) {
        UAM_Flight_control_B.VectorConcatenate_f[2] =
          UAM_Flight_control_P.Saturation2_LowerSat_l;
      } else {
        UAM_Flight_control_B.VectorConcatenate_f[2] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1181>/Saturation2' */

      /* Sum: '<S1181>/Add5' incorporates:
       *  Constant: '<S1181>/Constant6'
       *  Gain: '<S1181>/Gain5'
       */
      rtb_Bias_l = UAM_Flight_control_P.Gain5_Gain_a * UAM_Flight_control_B.w4_g
        + UAM_Flight_control_P.Constant6_Value_b;

      /* Saturate: '<S1181>/Saturation3' incorporates:
       *  Concatenate: '<S1181>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation3_UpperSat_a) {
        UAM_Flight_control_B.VectorConcatenate_f[3] =
          UAM_Flight_control_P.Saturation3_UpperSat_a;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation3_LowerSat_l) {
        UAM_Flight_control_B.VectorConcatenate_f[3] =
          UAM_Flight_control_P.Saturation3_LowerSat_l;
      } else {
        UAM_Flight_control_B.VectorConcatenate_f[3] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1181>/Saturation3' */

      /* Saturate: '<S1181>/Saturation4' incorporates:
       *  Concatenate: '<S1181>/Vector Concatenate'
       */
      if (UAM_Flight_control_B.c1_i >
          UAM_Flight_control_P.Saturation4_UpperSat_i) {
        UAM_Flight_control_B.VectorConcatenate_f[4] =
          UAM_Flight_control_P.Saturation4_UpperSat_i;
      } else if (UAM_Flight_control_B.c1_i <
                 UAM_Flight_control_P.Saturation4_LowerSat_g) {
        UAM_Flight_control_B.VectorConcatenate_f[4] =
          UAM_Flight_control_P.Saturation4_LowerSat_g;
      } else {
        UAM_Flight_control_B.VectorConcatenate_f[4] = UAM_Flight_control_B.c1_i;
      }

      /* End of Saturate: '<S1181>/Saturation4' */

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cv2 = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_baw = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_edg = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nly = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dq0 = 0U;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_kb = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_me = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ps2 = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ez = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_de = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gb = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nw = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_i0 = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dgz = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ae = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bj = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jj = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ajj = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_hw = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pgb = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_n2x = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gx0 = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_adl = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bbr = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_py = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pds = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fs = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_by1 = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cr = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_duz = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[0] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[1] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[2] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[3] = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_awy = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_l5 = 0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jx3 = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bkn = 0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_irm = 0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_exu = 0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ouu = 0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_k55 = 0U;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_odd = 0U;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_a2g = 0U;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      memset(&UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cvb[0], 0, sizeof
             (real_T) << 4U);

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[0] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[1] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[2] = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mqv = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kew = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ahl = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_e1u = 0.0F;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_oni = 0.0;

      /* SignalConversion generated from: '<S1181>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dax = 0.0;
    } else if (UAM_Flight_control_DW.Scheduler_MODE_g) {
      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cv2 =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nw =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_adl =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jx3 =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mqv = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kew = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ahl = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_e1u = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_oni =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dax =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_baw = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_edg = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nly = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dq0 = (uint8_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_kb = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_me = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ps2 = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ez =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_de =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gb =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_i0 =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dgz =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ae =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bj =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jj =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ajj = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_hw = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pgb = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_n2x =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gx0 =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bbr =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_py =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pds =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fs =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_by1 =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cr =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_duz =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[0] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[1] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[2] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[3] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_awy =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_l5 = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bkn = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_irm = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_exu = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ouu = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_k55 = (uint8_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_odd = (uint8_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_a2g = (uint8_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
      for (i = 0; i < 6; i++) {
        /* Disable for Concatenate: '<S1181>/Vector Concatenate' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.VectorConcatenate_f[i] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
      }

      for (i = 0; i < 16; i++) {
        /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
         *  Outport: '<S14>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cvb[i] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
      }

      /* Disable for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[0] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[1] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[2] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

      /* Disable for SignalConversion generated from: '<S14>/CtrlSurfaceCommands' incorporates:
       *  Outport: '<S14>/CtrlSurfaceCommands'
       * */
      UAM_Flight_control_B.OutportBufferForCtrlSurfaceCo_i =
        UAM_Flight_control_P.CtrlSurfaceCommands_Y0_h;
      UAM_Flight_control_DW.Scheduler_MODE_g = false;
    }

    /* End of Outputs for SubSystem: '<S7>/Fixed Wing Controller' */
    /* End of Outputs for SubSystem: '<S7>/Scheduler' */

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  Concatenate: '<S1181>/Vector Concatenate'
     *  Constant: '<S1181>/Constant'
     *  Constant: '<S189>/Constant'
     *  Constant: '<S190>/Constant'
     *  Constant: '<S28>/Constant'
     *  Constant: '<S29>/Constant'
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     *  Logic: '<S17>/NOT1'
     *  Logic: '<S17>/NOT2'
     *  RelationalOperator: '<S189>/Compare'
     *  RelationalOperator: '<S190>/Compare'
     *  RelationalOperator: '<S28>/Compare'
     *  RelationalOperator: '<S29>/Compare'
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.roll =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cv2;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.pitch =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nw;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.dist_n =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_baw;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.dist_e =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_edg;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.dist_d =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nly;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.gps_num_sv =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dq0;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.roll_rate =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_kb;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.pitch_rate =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_me;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.yaw_rate =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ps2;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.acc_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ez;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.acc_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_de;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.acc_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gb;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.yaw =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_adl;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.pressure =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_i0;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.vel_n =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dgz;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.vel_e =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ae;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.vel_d =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bj;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.gndspeed =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jj;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.target_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ajj;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.target_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_hw;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.target_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pgb;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.gyro_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_n2x;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.gyro_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gx0;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.altitude =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jx3;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.gyro_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bbr;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.mag_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_py;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.mag_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pds;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.mag_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fs;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.lin_acc_ecef_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_by1;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.lin_acc_ecef_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cr;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.lin_acc_ecef_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_duz;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.q[0] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[0];
    UAM_Flight_control_B.q[1] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[1];
    UAM_Flight_control_B.q[2] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[2];
    UAM_Flight_control_B.q[3] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[3];

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.airspeed =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_awy;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.voltage =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_l5;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.target_roll =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mqv;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.current =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bkn;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.soc =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_irm;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.temperature =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_exu;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.soh =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ouu;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.gcs_link =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_k55;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.rc_link =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_odd;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.flight_mode =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_a2g;
    for (i = 0; i < 6; i++) {
      /* Merge generated from: '<S1>/Merge' incorporates:
       *  SignalConversion generated from: '<S7>/Controller'
       */
      UAM_Flight_control_B.m[i] = UAM_Flight_control_B.VectorConcatenate_f[i];
    }

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    memcpy(&UAM_Flight_control_B.rc[0],
           &UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cvb[0], sizeof
           (real_T) << 4U);

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.rpy_sp[0] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[0];
    UAM_Flight_control_B.rpy_sp[1] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[1];
    UAM_Flight_control_B.rpy_sp[2] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[2];

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.target_pitch =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kew;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.target_yaw =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ahl;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.target_alt =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_e1u;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.latitude =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_oni;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.longitude =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dax;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S7>/Controller'
     */
    UAM_Flight_control_B.CtrlSurfaceCommands =
      UAM_Flight_control_B.OutportBufferForCtrlSurfaceCo_i;

    /* Saturate: '<S1187>/Saturation' incorporates:
     *  Constant: '<S10>/Constant7'
     *  Merge generated from: '<S1>/Merge'
     *  SignalConversion generated from: '<S7>/Controller'
     *  Sum: '<S10>/Subtract1'
     */
    UAM_Flight_control_B.a = UAM_Flight_control_P.Constant7_Value - s;

    /* End of Outputs for SubSystem: '<S1>/Auto1' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Emergency' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Saturate: '<S1187>/Saturation' incorporates:
     *  DiscreteIntegrator: '<S1187>/Discrete-Time Integrator'
     */
    UAM_Flight_control_B.a = (real_T)
      UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE * 7.8125E-7;

    /* Saturate: '<S1187>/Saturation' */
    if (UAM_Flight_control_B.a > UAM_Flight_control_P.Saturation_UpperSat_j) {
      /* Saturate: '<S1187>/Saturation' */
      UAM_Flight_control_B.a = UAM_Flight_control_P.Saturation_UpperSat_j;
    } else if (UAM_Flight_control_B.a <
               UAM_Flight_control_P.Saturation_LowerSat_bu) {
      /* Saturate: '<S1187>/Saturation' */
      UAM_Flight_control_B.a = UAM_Flight_control_P.Saturation_LowerSat_bu;
    }

    /* Outputs for Enabled SubSystem: '<S8>/Scheduler' incorporates:
     *  EnablePort: '<S1189>/Actuator Armed'
     */
    /* Outputs for Enabled SubSystem: '<S8>/FixedWing Controller' incorporates:
     *  EnablePort: '<S1188>/Actuator Armed'
     */
    /* Outputs for Enabled SubSystem: '<S8>/multicopter Controller' incorporates:
     *  EnablePort: '<S1190>/Actuator Armed'
     */
    if (rtb_Compare_ic) {
      /* Sum: '<S1482>/Sum2' incorporates:
       *  Bias: '<S1482>/Bias'
       *  Gain: '<S1482>/Gain'
       *  Gain: '<S1526>/Proportional Gain'
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      UAM_Flight_control_B.e_q = (UAM_Flight_control_U.fcc.rc[1] +
        UAM_Flight_control_P.Bias_Bias_a) * UAM_Flight_control_P.Gain_Gain_b4 *
        UAM_Flight_control_P.PitchController_P - UAM_Flight_control_U.fcc.gyro_y;

      /* Sum: '<S1482>/Sum1' incorporates:
       *  Bias: '<S1482>/Bias'
       *  Gain: '<S1482>/Gain'
       *  Gain: '<S1578>/Proportional Gain'
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      UAM_Flight_control_B.t_p = (UAM_Flight_control_U.fcc.rc[0] +
        UAM_Flight_control_P.Bias_Bias_a) * UAM_Flight_control_P.Gain_Gain_b4 *
        UAM_Flight_control_P.RollController_P - UAM_Flight_control_U.fcc.gyro_x;

      /* Sum: '<S1482>/Sum3' incorporates:
       *  Bias: '<S1482>/Bias'
       *  Gain: '<S1482>/Gain'
       *  Gain: '<S1630>/Proportional Gain'
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      rtb_Bias_l = (UAM_Flight_control_U.fcc.rc[3] +
                    UAM_Flight_control_P.Bias_Bias_a) *
        UAM_Flight_control_P.Gain_Gain_b4 *
        UAM_Flight_control_P.controlParams.P_YAW -
        UAM_Flight_control_U.fcc.gyro_z;

      /* Gain: '<S1680>/Filter Coefficient' incorporates:
       *  DiscreteIntegrator: '<S1672>/Filter'
       *  Gain: '<S1670>/Derivative Gain'
       *  Sum: '<S1672>/SumD'
       */
      s = (UAM_Flight_control_P.controlParams.D_YAW_RATE * rtb_Bias_l -
           UAM_Flight_control_DW.Filter_DSTATE) *
        UAM_Flight_control_P.controlParams.N_YAW_RATE;

      /* Sum: '<S1686>/Sum' incorporates:
       *  Gain: '<S1682>/Proportional Gain'
       */
      UAM_Flight_control_B.Sum = UAM_Flight_control_P.Yawratecontroller_P *
        rtb_Bias_l + s;

      /* Gain: '<S1480>/Gain' incorporates:
       *  Bias: '<S1480>/Bias'
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      UAM_Flight_control_B.Gain = (UAM_Flight_control_U.fcc.rc[2] +
        UAM_Flight_control_P.Bias_Bias_d) * UAM_Flight_control_P.Gain_Gain_d;

      /* Update for DiscreteIntegrator: '<S1672>/Filter' */
      UAM_Flight_control_DW.Filter_DSTATE +=
        UAM_Flight_control_P.Filter_gainval_h * s;

      /* MATLAB Function: '<S1193>/MATLAB Function' */
      UAM_Flight_MATLABFunction_a(rtb_Gain1[2], rtb_Gain1[1], rtb_R);

      /* Outputs for Enabled SubSystem: '<S1191>/Attitude Controller' incorporates:
       *  EnablePort: '<S1192>/Enable'
       */
      if (UAM_Flight_control_B.controlMode_h.attitude > 0) {
        /* Outputs for Enabled SubSystem: '<S1192>/Pitch Roll Controller' incorporates:
         *  EnablePort: '<S1198>/Enable'
         */
        if (UAM_Flight_control_B.controlMode_h.attitude ==
            UAM_Flight_control_P.CompareToConstant_const_e) {
          /* Gain: '<S1196>/Gain1' incorporates:
           *  Bias: '<S1196>/Bias'
           *  Gain: '<S1196>/Gain'
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           */
          rtb_qout_idx_1 = (UAM_Flight_control_U.fcc.rc[1] +
                            UAM_Flight_control_P.Bias_Bias_g) *
            UAM_Flight_control_P.Gain_Gain_m *
            UAM_Flight_control_P.Gain1_Gain_hk;

          /* Saturate: '<S1198>/Saturation1' */
          if (rtb_qout_idx_1 > UAM_Flight_control_P.control.maxPitch) {
            rtb_qout_idx_1 = UAM_Flight_control_P.control.maxPitch;
          } else if (rtb_qout_idx_1 < UAM_Flight_control_P.control.minPitch) {
            rtb_qout_idx_1 = UAM_Flight_control_P.control.minPitch;
          }

          /* End of Saturate: '<S1198>/Saturation1' */

          /* Sum: '<S1198>/Sum' */
          rtb_Bias_l = rtb_qout_idx_1 - rtb_Gain1[1];

          /* Gain: '<S1237>/Integral Gain' */
          s = UAM_Flight_control_P.FWControlParams.I_FW_PITCH * rtb_Bias_l;

          /* Gain: '<S1243>/Filter Coefficient' incorporates:
           *  DiscreteIntegrator: '<S1235>/Filter'
           *  Gain: '<S1233>/Derivative Gain'
           *  Sum: '<S1235>/SumD'
           */
          rtb_qout_idx_0 = (UAM_Flight_control_P.FWControlParams.D_FW_PITCH *
                            rtb_Bias_l - UAM_Flight_control_DW.Filter_DSTATE_l) *
            UAM_Flight_control_P.FWControlParams.N_FW_PITCH;

          /* Sum: '<S1249>/Sum' incorporates:
           *  DiscreteIntegrator: '<S1240>/Integrator'
           *  Gain: '<S1245>/Proportional Gain'
           */
          rtb_qout_idx_2 = (UAM_Flight_control_P.FWControlParams.P_FW_PITCH *
                            rtb_Bias_l + UAM_Flight_control_DW.Integrator_DSTATE)
            + rtb_qout_idx_0;

          /* DeadZone: '<S1232>/DeadZone' */
          if (rtb_qout_idx_2 >
              UAM_Flight_control_P.PitchAngleController_UpperSat_c) {
            rtb_Bias_l = rtb_qout_idx_2 -
              UAM_Flight_control_P.PitchAngleController_UpperSat_c;
          } else if (rtb_qout_idx_2 >=
                     UAM_Flight_control_P.PitchAngleController_LowerSat_e) {
            rtb_Bias_l = 0.0;
          } else {
            rtb_Bias_l = rtb_qout_idx_2 -
              UAM_Flight_control_P.PitchAngleController_LowerSat_e;
          }

          /* End of DeadZone: '<S1232>/DeadZone' */

          /* Switch: '<S1230>/Switch1' incorporates:
           *  Constant: '<S1230>/Clamping_zero'
           *  Constant: '<S1230>/Constant'
           *  Constant: '<S1230>/Constant2'
           *  RelationalOperator: '<S1230>/fix for DT propagation issue'
           */
          if (rtb_Bias_l > UAM_Flight_control_P.Clamping_zero_Value_bh) {
            rtAction = UAM_Flight_control_P.Constant_Value_pe;
          } else {
            rtAction = UAM_Flight_control_P.Constant2_Value_bo;
          }

          /* Switch: '<S1230>/Switch2' incorporates:
           *  Constant: '<S1230>/Clamping_zero'
           *  Constant: '<S1230>/Constant3'
           *  Constant: '<S1230>/Constant4'
           *  RelationalOperator: '<S1230>/fix for DT propagation issue1'
           */
          if (s > UAM_Flight_control_P.Clamping_zero_Value_bh) {
            tmp_1 = UAM_Flight_control_P.Constant3_Value_aq;
          } else {
            tmp_1 = UAM_Flight_control_P.Constant4_Value_jz;
          }

          /* Logic: '<S1230>/AND3' incorporates:
           *  Constant: '<S1230>/Clamping_zero'
           *  RelationalOperator: '<S1230>/Equal1'
           *  RelationalOperator: '<S1230>/Relational Operator'
           *  Switch: '<S1230>/Switch1'
           *  Switch: '<S1230>/Switch2'
           */
          rtb_Compare_j = ((UAM_Flight_control_P.Clamping_zero_Value_bh !=
                            rtb_Bias_l) && (rtAction == tmp_1));

          /* Saturate: '<S1247>/Saturation' */
          if (rtb_qout_idx_2 >
              UAM_Flight_control_P.PitchAngleController_UpperSat_c) {
            rtb_qout_idx_2 =
              UAM_Flight_control_P.PitchAngleController_UpperSat_c;
          } else if (rtb_qout_idx_2 <
                     UAM_Flight_control_P.PitchAngleController_LowerSat_e) {
            rtb_qout_idx_2 =
              UAM_Flight_control_P.PitchAngleController_LowerSat_e;
          }

          /* Gain: '<S1297>/Proportional Gain' incorporates:
           *  Inport: '<Root>/fcc'
           *  Saturate: '<S1247>/Saturation'
           *  SignalConversion generated from: '<Root>/fcc'
           *  Sum: '<S1198>/Sum3'
           */
          rtb_Bias_l = (rtb_qout_idx_2 - UAM_Flight_control_U.fcc.gyro_y) *
            UAM_Flight_control_P.FWControlParams.P_FW_PITCHRATE;

          /* Saturate: '<S1299>/Saturation' */
          if (rtb_Bias_l > UAM_Flight_control_P.PitchRateController_UpperSatu_l)
          {
            /* UnaryMinus: '<S1198>/Unary Minus1' */
            UAM_Flight_control_B.dE_j =
              -UAM_Flight_control_P.PitchRateController_UpperSatu_l;
          } else if (rtb_Bias_l <
                     UAM_Flight_control_P.PitchRateController_LowerSatu_o) {
            /* UnaryMinus: '<S1198>/Unary Minus1' */
            UAM_Flight_control_B.dE_j =
              -UAM_Flight_control_P.PitchRateController_LowerSatu_o;
          } else {
            /* UnaryMinus: '<S1198>/Unary Minus1' */
            UAM_Flight_control_B.dE_j = -rtb_Bias_l;
          }

          /* End of Saturate: '<S1299>/Saturation' */

          /* Gain: '<S1195>/Gain1' incorporates:
           *  Bias: '<S1195>/Bias'
           *  Gain: '<S1195>/Gain'
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           */
          rtb_qout_idx_2 = (UAM_Flight_control_U.fcc.rc[0] +
                            UAM_Flight_control_P.Bias_Bias_b) *
            UAM_Flight_control_P.Gain_Gain_ag *
            UAM_Flight_control_P.Gain1_Gain_dd;

          /* Saturate: '<S1198>/Saturation' */
          if (rtb_qout_idx_2 > UAM_Flight_control_P.control.maxRoll) {
            rtb_qout_idx_2 = UAM_Flight_control_P.control.maxRoll;
          } else if (rtb_qout_idx_2 < UAM_Flight_control_P.control.minRoll) {
            rtb_qout_idx_2 = UAM_Flight_control_P.control.minRoll;
          }

          /* End of Saturate: '<S1198>/Saturation' */

          /* MATLAB Function: '<S1203>/MATLAB Function' incorporates:
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           */
          UAM_Flight_c_MATLABFunction(rtb_qout_idx_2, rtb_qout_idx_1,
            UAM_Flight_control_U.fcc.airspeed, &rtb_Bias_l);

          /* Gain: '<S1455>/Proportional Gain' incorporates:
           *  Inport: '<Root>/fcc'
           *  SignalConversion generated from: '<Root>/fcc'
           *  Sum: '<S1203>/Sum'
           */
          UAM_Flight_control_B.Saturation = (rtb_Bias_l -
            UAM_Flight_control_U.fcc.gyro_z) *
            UAM_Flight_control_P.RudderController_P_f;

          /* Saturate: '<S1457>/Saturation' */
          if (UAM_Flight_control_B.Saturation >
              UAM_Flight_control_P.RudderController_UpperSaturat_i) {
            /* Gain: '<S1455>/Proportional Gain' incorporates:
             *  Saturate: '<S1457>/Saturation'
             */
            UAM_Flight_control_B.Saturation =
              UAM_Flight_control_P.RudderController_UpperSaturat_i;
          } else if (UAM_Flight_control_B.Saturation <
                     UAM_Flight_control_P.RudderController_LowerSaturat_f) {
            /* Gain: '<S1455>/Proportional Gain' incorporates:
             *  Saturate: '<S1457>/Saturation'
             */
            UAM_Flight_control_B.Saturation =
              UAM_Flight_control_P.RudderController_LowerSaturat_f;
          }

          /* End of Saturate: '<S1457>/Saturation' */

          /* Gain: '<S1349>/Proportional Gain' incorporates:
           *  Sum: '<S1198>/Sum1'
           */
          rtb_Bias_l = (rtb_qout_idx_2 - rtb_Gain1[2]) *
            UAM_Flight_control_P.FWControlParams.P_FW_ROLL;

          /* Saturate: '<S1351>/Saturation' */
          if (rtb_Bias_l > UAM_Flight_control_P.control.maxRollRate) {
            rtb_Bias_l = UAM_Flight_control_P.control.maxRollRate;
          } else if (rtb_Bias_l < UAM_Flight_control_P.control.minRollRate) {
            rtb_Bias_l = UAM_Flight_control_P.control.minRollRate;
          }

          /* Gain: '<S1401>/Proportional Gain' incorporates:
           *  Inport: '<Root>/fcc'
           *  Saturate: '<S1351>/Saturation'
           *  SignalConversion generated from: '<Root>/fcc'
           *  Sum: '<S1198>/Sum2'
           */
          UAM_Flight_control_B.Saturation2 = (rtb_Bias_l -
            UAM_Flight_control_U.fcc.gyro_x) *
            UAM_Flight_control_P.FWControlParams.P_FW_ROLLRATE;

          /* Saturate: '<S1403>/Saturation' */
          if (UAM_Flight_control_B.Saturation2 >
              UAM_Flight_control_P.RollRateController_UpperSatur_l) {
            /* Gain: '<S1401>/Proportional Gain' */
            UAM_Flight_control_B.Saturation2 =
              UAM_Flight_control_P.RollRateController_UpperSatur_l;
          } else if (UAM_Flight_control_B.Saturation2 <
                     UAM_Flight_control_P.RollRateController_LowerSatur_g) {
            /* Gain: '<S1401>/Proportional Gain' */
            UAM_Flight_control_B.Saturation2 =
              UAM_Flight_control_P.RollRateController_LowerSatur_g;
          }

          /* End of Saturate: '<S1403>/Saturation' */

          /* Saturate: '<S1198>/Saturation2' */
          if (UAM_Flight_control_B.Saturation2 >
              UAM_Flight_control_P.Saturation2_UpperSat_ad) {
            /* Gain: '<S1401>/Proportional Gain' incorporates:
             *  Saturate: '<S1198>/Saturation2'
             */
            UAM_Flight_control_B.Saturation2 =
              UAM_Flight_control_P.Saturation2_UpperSat_ad;
          } else if (UAM_Flight_control_B.Saturation2 <
                     UAM_Flight_control_P.Saturation2_LowerSat_i) {
            /* Gain: '<S1401>/Proportional Gain' incorporates:
             *  Saturate: '<S1198>/Saturation2'
             */
            UAM_Flight_control_B.Saturation2 =
              UAM_Flight_control_P.Saturation2_LowerSat_i;
          }

          /* End of Saturate: '<S1198>/Saturation2' */

          /* Switch: '<S1230>/Switch' incorporates:
           *  Constant: '<S1230>/Constant1'
           */
          if (rtb_Compare_j) {
            s = UAM_Flight_control_P.Constant1_Value_fa;
          }

          /* Update for DiscreteIntegrator: '<S1240>/Integrator' incorporates:
           *  Switch: '<S1230>/Switch'
           */
          UAM_Flight_control_DW.Integrator_DSTATE +=
            UAM_Flight_control_P.Integrator_gainval_ap * s;

          /* Update for DiscreteIntegrator: '<S1235>/Filter' */
          UAM_Flight_control_DW.Filter_DSTATE_l +=
            UAM_Flight_control_P.Filter_gainval_d * rtb_qout_idx_0;
        }

        /* End of Outputs for SubSystem: '<S1192>/Pitch Roll Controller' */
      }

      /* End of Outputs for SubSystem: '<S1191>/Attitude Controller' */

      /* SignalConversion generated from: '<S1188>/Actuator' incorporates:
       *  Constant: '<S1197>/Constant'
       *  RelationalOperator: '<S1197>/Compare'
       */
      UAM_Flight_control_B.dA = UAM_Flight_control_B.Saturation2;

      /* SignalConversion generated from: '<S1188>/Actuator' */
      UAM_Flight_control_B.dE = UAM_Flight_control_B.dE_j;

      /* SignalConversion generated from: '<S1188>/Actuator' */
      UAM_Flight_control_B.dR = UAM_Flight_control_B.Saturation;

      /* SignalConversion generated from: '<S1188>/Actuator' incorporates:
       *  Inport: '<Root>/fcc'
       *  SignalConversion generated from: '<Root>/fcc'
       */
      UAM_Flight_control_B.dT = UAM_Flight_control_U.fcc.rc[2];
      UAM_Flight_control_DW.Scheduler_MODE = true;

      /* SwitchCase: '<S1469>/Switch Case' */
      switch (UAM_Flight_control_B.FlightMode) {
       case Hover:
        /* Outputs for IfAction SubSystem: '<S1469>/Switch Case Action Subsystem' incorporates:
         *  ActionPort: '<S1471>/Action Port'
         */
        U_SwitchCaseActionSubsystem(&UAM_Flight_control_B.Merge,
          &UAM_Flight_control_P.SwitchCaseActionSubsystem_e);

        /* End of Outputs for SubSystem: '<S1469>/Switch Case Action Subsystem' */
        break;

       case Transition:
        /* Outputs for IfAction SubSystem: '<S1469>/Switch Case Action Subsystem1' incorporates:
         *  ActionPort: '<S1472>/Action Port'
         */
        SwitchCaseActionSubsystem1
          (UAM_Flight_control_B.controlMode_h.TransitionCondition,
           &UAM_Flight_control_B.Merge,
           &UAM_Flight_control_P.SwitchCaseActionSubsystem1_m);

        /* End of Outputs for SubSystem: '<S1469>/Switch Case Action Subsystem1' */
        break;

       case FixedWing:
        /* Outputs for IfAction SubSystem: '<S1469>/Switch Case Action Subsystem2' incorporates:
         *  ActionPort: '<S1473>/Action Port'
         */
        SwitchCaseActionSubsystem2(UAM_Flight_control_B.dA,
          UAM_Flight_control_B.dE, UAM_Flight_control_B.dR,
          UAM_Flight_control_B.dT, &UAM_Flight_control_B.Merge);

        /* End of Outputs for SubSystem: '<S1469>/Switch Case Action Subsystem2' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S1469>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S1474>/Action Port'
         */
        U_SwitchCaseActionSubsystem(&UAM_Flight_control_B.Merge,
          &UAM_Flight_control_P.SwitchCaseActionSubsystem3_g);

        /* End of Outputs for SubSystem: '<S1469>/Switch Case Action Subsystem3' */
        break;
      }

      /* End of SwitchCase: '<S1469>/Switch Case' */

      /* SignalConversion generated from: '<S1189>/CtrlSurfaceCommands' */
      UAM_Flight_control_B.OutportBufferForCtrlSurfaceComm =
        UAM_Flight_control_B.Merge;

      /* SwitchCase: '<S1470>/Switch Case' */
      switch (UAM_Flight_control_B.FlightMode) {
       case Hover:
        /* Outputs for IfAction SubSystem: '<S1470>/Switch Case Action Subsystem' incorporates:
         *  ActionPort: '<S1476>/Action Port'
         */
        /* Saturate: '<S1476>/Saturation' */
        if (UAM_Flight_control_B.Gain >
            UAM_Flight_control_P.Saturation_UpperSat_hi) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation_UpperSat_hi;
        } else if (UAM_Flight_control_B.Gain <
                   UAM_Flight_control_P.Saturation_LowerSat_i) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation_LowerSat_i;
        } else {
          rtb_Bias_l = UAM_Flight_control_B.Gain;
        }

        /* Sum: '<S1476>/Add' incorporates:
         *  Saturate: '<S1476>/Saturation'
         */
        s = ((UAM_Flight_control_B.Sum + rtb_Bias_l) + UAM_Flight_control_B.t_p)
          - UAM_Flight_control_B.e_q;

        /* Saturate: '<S1476>/Saturation4' */
        if (s > UAM_Flight_control_P.Saturation4_UpperSat_d) {
          s = UAM_Flight_control_P.Saturation4_UpperSat_d;
        } else if (s < UAM_Flight_control_P.Saturation4_LowerSat_gy) {
          s = UAM_Flight_control_P.Saturation4_LowerSat_gy;
        }

        /* End of Saturate: '<S1476>/Saturation4' */

        /* Sqrt: '<S1476>/Sqrt5'
         *
         * About '<S1476>/Sqrt5':
         *  Operator: signedSqrt
         */
        if (s < 0.0) {
          rtb_Bias_l = -sqrt(fabs(s));
        } else {
          rtb_Bias_l = sqrt(s);
        }

        /* Gain: '<S1476>/Gain5' incorporates:
         *  Gain: '<S1476>/Gain1'
         *  Gain: '<S1476>/Gain2'
         *  Gain: '<S1476>/Gain3'
         */
        rtb_qout_idx_0 = UAM_Flight_control_P.w_trim / sqrt(0.25 *
          UAM_Flight_control_P.uavParam.geom.mass * 9.81);

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Gain: '<S1476>/Gain5'
         *  SignalConversion generated from: '<S1476>/Actuator_Outport_1'
         *  Sqrt: '<S1476>/Sqrt5'
         *
         * About '<S1476>/Sqrt5':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w2 = rtb_qout_idx_0 * rtb_Bias_l;

        /* Saturate: '<S1476>/Saturation1' */
        if (UAM_Flight_control_B.Gain >
            UAM_Flight_control_P.Saturation1_UpperSat_i) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation1_UpperSat_i;
        } else if (UAM_Flight_control_B.Gain <
                   UAM_Flight_control_P.Saturation1_LowerSat_g) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation1_LowerSat_g;
        } else {
          rtb_Bias_l = UAM_Flight_control_B.Gain;
        }

        /* Sum: '<S1476>/Add1' incorporates:
         *  Saturate: '<S1476>/Saturation1'
         */
        s = ((rtb_Bias_l - UAM_Flight_control_B.Sum) - UAM_Flight_control_B.t_p)
          - UAM_Flight_control_B.e_q;

        /* Saturate: '<S1476>/Saturation5' */
        if (s > UAM_Flight_control_P.Saturation5_UpperSat_c) {
          s = UAM_Flight_control_P.Saturation5_UpperSat_c;
        } else if (s < UAM_Flight_control_P.Saturation5_LowerSat_b) {
          s = UAM_Flight_control_P.Saturation5_LowerSat_b;
        }

        /* End of Saturate: '<S1476>/Saturation5' */

        /* Sqrt: '<S1476>/Sqrt1'
         *
         * About '<S1476>/Sqrt1':
         *  Operator: signedSqrt
         */
        if (s < 0.0) {
          rtb_Bias_l = -sqrt(fabs(s));
        } else {
          rtb_Bias_l = sqrt(s);
        }

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Gain: '<S1476>/Gain1'
         *  SignalConversion generated from: '<S1476>/Actuator_Outport_1'
         *  Sqrt: '<S1476>/Sqrt1'
         *
         * About '<S1476>/Sqrt1':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w1 = rtb_qout_idx_0 * rtb_Bias_l;

        /* Saturate: '<S1476>/Saturation2' */
        if (UAM_Flight_control_B.Gain >
            UAM_Flight_control_P.Saturation2_UpperSat_f) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation2_UpperSat_f;
        } else if (UAM_Flight_control_B.Gain <
                   UAM_Flight_control_P.Saturation2_LowerSat_j) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation2_LowerSat_j;
        } else {
          rtb_Bias_l = UAM_Flight_control_B.Gain;
        }

        /* Sum: '<S1476>/Add2' incorporates:
         *  Saturate: '<S1476>/Saturation2'
         */
        s = ((UAM_Flight_control_B.Sum + rtb_Bias_l) - UAM_Flight_control_B.t_p)
          + UAM_Flight_control_B.e_q;

        /* Saturate: '<S1476>/Saturation6' */
        if (s > UAM_Flight_control_P.Saturation6_UpperSat) {
          s = UAM_Flight_control_P.Saturation6_UpperSat;
        } else if (s < UAM_Flight_control_P.Saturation6_LowerSat) {
          s = UAM_Flight_control_P.Saturation6_LowerSat;
        }

        /* End of Saturate: '<S1476>/Saturation6' */

        /* Sqrt: '<S1476>/Sqrt2'
         *
         * About '<S1476>/Sqrt2':
         *  Operator: signedSqrt
         */
        if (s < 0.0) {
          rtb_Bias_l = -sqrt(fabs(s));
        } else {
          rtb_Bias_l = sqrt(s);
        }

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Gain: '<S1476>/Gain2'
         *  SignalConversion generated from: '<S1476>/Actuator_Outport_1'
         *  Sqrt: '<S1476>/Sqrt2'
         *
         * About '<S1476>/Sqrt2':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w4 = rtb_qout_idx_0 * rtb_Bias_l;

        /* Saturate: '<S1476>/Saturation3' */
        if (UAM_Flight_control_B.Gain >
            UAM_Flight_control_P.Saturation3_UpperSat_i) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation3_UpperSat_i;
        } else if (UAM_Flight_control_B.Gain <
                   UAM_Flight_control_P.Saturation3_LowerSat_c) {
          rtb_Bias_l = UAM_Flight_control_P.Saturation3_LowerSat_c;
        } else {
          rtb_Bias_l = UAM_Flight_control_B.Gain;
        }

        /* Sum: '<S1476>/Add3' incorporates:
         *  Saturate: '<S1476>/Saturation3'
         */
        s = ((rtb_Bias_l - UAM_Flight_control_B.Sum) + UAM_Flight_control_B.t_p)
          + UAM_Flight_control_B.e_q;

        /* Saturate: '<S1476>/Saturation7' */
        if (s > UAM_Flight_control_P.Saturation7_UpperSat) {
          s = UAM_Flight_control_P.Saturation7_UpperSat;
        } else if (s < UAM_Flight_control_P.Saturation7_LowerSat) {
          s = UAM_Flight_control_P.Saturation7_LowerSat;
        }

        /* End of Saturate: '<S1476>/Saturation7' */

        /* Sqrt: '<S1476>/Sqrt3'
         *
         * About '<S1476>/Sqrt3':
         *  Operator: signedSqrt
         */
        if (s < 0.0) {
          rtb_Bias_l = -sqrt(fabs(s));
        } else {
          rtb_Bias_l = sqrt(s);
        }

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Gain: '<S1476>/Gain3'
         *  SignalConversion generated from: '<S1476>/Actuator_Outport_1'
         *  Sqrt: '<S1476>/Sqrt3'
         *
         * About '<S1476>/Sqrt3':
         *  Operator: signedSqrt
         */
        UAM_Flight_control_B.w3 = rtb_qout_idx_0 * rtb_Bias_l;

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Constant: '<S1476>/Constant4'
         *  SignalConversion generated from: '<S1476>/Actuator_Outport_1'
         */
        UAM_Flight_control_B.c1 = UAM_Flight_control_P.Constant4_Value_il;

        /* End of Outputs for SubSystem: '<S1470>/Switch Case Action Subsystem' */
        break;

       case Transition:
        /* Outputs for IfAction SubSystem: '<S1470>/Switch Case Action Subsystem1' incorporates:
         *  ActionPort: '<S1477>/Action Port'
         */
        /* Sum: '<S1477>/1-a' incorporates:
         *  Constant: '<S1477>/Constant5'
         */
        s = UAM_Flight_control_P.Cruise_a - UAM_Flight_control_B.a;

        /* Switch: '<S1477>/Switch' */
        if (UAM_Flight_control_B.controlMode_h.TransitionCondition >
            UAM_Flight_control_P.Switch_Threshold_c) {
          /* Merge generated from: '<S1470>/Merge' incorporates:
           *  Constant: '<S1477>/Constant'
           *  Product: '<S1477>/Product1'
           *  Sum: '<S1477>/Add'
           */
          UAM_Flight_control_B.w1 = (((UAM_Flight_control_P.w_trim +
            UAM_Flight_control_B.Gain) - UAM_Flight_control_B.t_p) +
            UAM_Flight_control_B.e_q) * s;
        } else {
          /* Merge generated from: '<S1470>/Merge' incorporates:
           *  Constant: '<S1477>/Constant8'
           */
          UAM_Flight_control_B.w1 = UAM_Flight_control_P.Constant8_Value_i;
        }

        /* End of Switch: '<S1477>/Switch' */

        /* Switch: '<S1477>/Switch1' */
        if (UAM_Flight_control_B.controlMode_h.TransitionCondition >
            UAM_Flight_control_P.Switch1_Threshold) {
          /* Merge generated from: '<S1470>/Merge' incorporates:
           *  Constant: '<S1477>/Constant1'
           *  Product: '<S1477>/Product2'
           *  Sum: '<S1477>/Add1'
           */
          UAM_Flight_control_B.w2 = (((UAM_Flight_control_P.w_trim +
            UAM_Flight_control_B.Gain) + UAM_Flight_control_B.t_p) +
            UAM_Flight_control_B.e_q) * s;
        } else {
          /* Merge generated from: '<S1470>/Merge' incorporates:
           *  Constant: '<S1477>/Constant9'
           */
          UAM_Flight_control_B.w2 = UAM_Flight_control_P.Constant9_Value;
        }

        /* End of Switch: '<S1477>/Switch1' */

        /* Switch: '<S1477>/Switch2' */
        if (UAM_Flight_control_B.controlMode_h.TransitionCondition >
            UAM_Flight_control_P.Switch2_Threshold) {
          /* Merge generated from: '<S1470>/Merge' incorporates:
           *  Constant: '<S1477>/Constant2'
           *  Product: '<S1477>/Product3'
           *  Sum: '<S1477>/Add2'
           */
          UAM_Flight_control_B.w3 = (((UAM_Flight_control_P.w_trim +
            UAM_Flight_control_B.Gain) + UAM_Flight_control_B.t_p) -
            UAM_Flight_control_B.e_q) * s;
        } else {
          /* Merge generated from: '<S1470>/Merge' incorporates:
           *  Constant: '<S1477>/Constant10'
           */
          UAM_Flight_control_B.w3 = UAM_Flight_control_P.Constant10_Value;
        }

        /* End of Switch: '<S1477>/Switch2' */

        /* Switch: '<S1477>/Switch4' */
        if (UAM_Flight_control_B.controlMode_h.TransitionCondition >
            UAM_Flight_control_P.Switch4_Threshold) {
          /* Merge generated from: '<S1470>/Merge' incorporates:
           *  Constant: '<S1477>/Constant3'
           *  Product: '<S1477>/Product4'
           *  Sum: '<S1477>/Add3'
           */
          UAM_Flight_control_B.w4 = (((UAM_Flight_control_P.w_trim +
            UAM_Flight_control_B.Gain) - UAM_Flight_control_B.t_p) -
            UAM_Flight_control_B.e_q) * s;
        } else {
          /* Merge generated from: '<S1470>/Merge' incorporates:
           *  Constant: '<S1477>/Constant11'
           */
          UAM_Flight_control_B.w4 = UAM_Flight_control_P.Constant11_Value;
        }

        /* End of Switch: '<S1477>/Switch4' */

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Constant: '<S1477>/Constant4'
         *  Product: '<S1477>/Product'
         *  Sum: '<S1477>/Add4'
         */
        UAM_Flight_control_B.c1 = (UAM_Flight_control_P.FWTrimSpeed +
          UAM_Flight_control_B.Merge.dT) * UAM_Flight_control_B.a;

        /* End of Outputs for SubSystem: '<S1470>/Switch Case Action Subsystem1' */
        break;

       case FixedWing:
        /* Outputs for IfAction SubSystem: '<S1470>/Switch Case Action Subsystem2' incorporates:
         *  ActionPort: '<S1478>/Action Port'
         */
        SwitchCaseActionSubsystem_m(&UAM_Flight_control_B.Merge,
          &UAM_Flight_control_B.w1, &UAM_Flight_control_B.w2,
          &UAM_Flight_control_B.w3, &UAM_Flight_control_B.w4,
          &UAM_Flight_control_B.c1,
          &UAM_Flight_control_P.SwitchCaseActionSubsystem2_n);

        /* End of Outputs for SubSystem: '<S1470>/Switch Case Action Subsystem2' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S1470>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S1479>/Action Port'
         */
        /* Sum: '<S1479>/1-a' incorporates:
         *  Constant: '<S1479>/Constant5'
         */
        s = UAM_Flight_control_P.Cruise_a - UAM_Flight_control_B.a;

        /* Sum: '<S1479>/Add' incorporates:
         *  Constant: '<S1479>/Constant'
         *  Sum: '<S1479>/Add1'
         *  Sum: '<S1479>/Add3'
         */
        rtb_qout_idx_0 = UAM_Flight_control_P.w_trim + UAM_Flight_control_B.Gain;
        rtb_Bias_l = rtb_qout_idx_0 - UAM_Flight_control_B.t_p;

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Product: '<S1479>/Product1'
         *  Sum: '<S1479>/Add'
         */
        UAM_Flight_control_B.w1 = (rtb_Bias_l + UAM_Flight_control_B.e_q) * s;

        /* Sum: '<S1479>/Add1' incorporates:
         *  Sum: '<S1479>/Add2'
         */
        rtb_qout_idx_0 += UAM_Flight_control_B.t_p;

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Product: '<S1479>/Product2'
         *  Sum: '<S1479>/Add1'
         */
        UAM_Flight_control_B.w2 = (rtb_qout_idx_0 + UAM_Flight_control_B.e_q) *
          s;

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Product: '<S1479>/Product3'
         *  Sum: '<S1479>/Add2'
         */
        UAM_Flight_control_B.w3 = (rtb_qout_idx_0 - UAM_Flight_control_B.e_q) *
          s;

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Product: '<S1479>/Product4'
         *  Sum: '<S1479>/Add3'
         */
        UAM_Flight_control_B.w4 = (rtb_Bias_l - UAM_Flight_control_B.e_q) * s;

        /* Merge generated from: '<S1470>/Merge' incorporates:
         *  Constant: '<S1479>/Constant6'
         *  SignalConversion generated from: '<S1479>/Constant6'
         */
        UAM_Flight_control_B.c1 = UAM_Flight_control_P.Constant6_Value_n;

        /* End of Outputs for SubSystem: '<S1470>/Switch Case Action Subsystem3' */
        break;
      }

      /* End of SwitchCase: '<S1470>/Switch Case' */
      UAM_Flight_control_B.VectorConcatenate[5] =
        UAM_Flight_control_P.Constant_Value_ob;

      /* Gain: '<S1475>/Gain' incorporates:
       *  Concatenate: '<S1475>/Vector Concatenate'
       *  Constant: '<S1475>/Constant'
       *  Gain: '<S1475>/Gain1'
       *  Gain: '<S1475>/Gain2'
       *  Gain: '<S1475>/Gain3'
       *  Gain: '<S1475>/Gain4'
       */
      s = 1.0 / (UAM_Flight_control_P.uavParam.motor.RPMMAX / 360.0);

      /* Bias: '<S1475>/Bias' incorporates:
       *  Gain: '<S1475>/Gain'
       *  Gain: '<S1475>/Gain5'
       */
      rtb_Bias_l = s * UAM_Flight_control_B.w1 *
        UAM_Flight_control_P.Gain5_Gain_g + UAM_Flight_control_P.Bias_Bias_be;

      /* Saturate: '<S1475>/Saturation' incorporates:
       *  Concatenate: '<S1475>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation_UpperSat_b) {
        UAM_Flight_control_B.VectorConcatenate[0] =
          UAM_Flight_control_P.Saturation_UpperSat_b;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation_LowerSat_d) {
        UAM_Flight_control_B.VectorConcatenate[0] =
          UAM_Flight_control_P.Saturation_LowerSat_d;
      } else {
        UAM_Flight_control_B.VectorConcatenate[0] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1475>/Saturation' */

      /* Bias: '<S1475>/Bias1' incorporates:
       *  Gain: '<S1475>/Gain4'
       *  Gain: '<S1475>/Gain6'
       */
      rtb_Bias_l = s * UAM_Flight_control_B.w2 * UAM_Flight_control_P.Gain6_Gain
        + UAM_Flight_control_P.Bias1_Bias_p;

      /* Saturate: '<S1475>/Saturation1' incorporates:
       *  Concatenate: '<S1475>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation1_UpperSat_cc) {
        UAM_Flight_control_B.VectorConcatenate[1] =
          UAM_Flight_control_P.Saturation1_UpperSat_cc;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation1_LowerSat_bx) {
        UAM_Flight_control_B.VectorConcatenate[1] =
          UAM_Flight_control_P.Saturation1_LowerSat_bx;
      } else {
        UAM_Flight_control_B.VectorConcatenate[1] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1475>/Saturation1' */

      /* Bias: '<S1475>/Bias2' incorporates:
       *  Gain: '<S1475>/Gain1'
       *  Gain: '<S1475>/Gain7'
       */
      rtb_Bias_l = s * UAM_Flight_control_B.w3 *
        UAM_Flight_control_P.Gain7_Gain_c + UAM_Flight_control_P.Bias2_Bias;

      /* Saturate: '<S1475>/Saturation2' incorporates:
       *  Concatenate: '<S1475>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation2_UpperSat_bs) {
        UAM_Flight_control_B.VectorConcatenate[2] =
          UAM_Flight_control_P.Saturation2_UpperSat_bs;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation2_LowerSat_h) {
        UAM_Flight_control_B.VectorConcatenate[2] =
          UAM_Flight_control_P.Saturation2_LowerSat_h;
      } else {
        UAM_Flight_control_B.VectorConcatenate[2] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1475>/Saturation2' */

      /* Bias: '<S1475>/Bias3' incorporates:
       *  Gain: '<S1475>/Gain2'
       *  Gain: '<S1475>/Gain8'
       */
      rtb_Bias_l = s * UAM_Flight_control_B.w4 * UAM_Flight_control_P.Gain8_Gain
        + UAM_Flight_control_P.Bias3_Bias;

      /* Saturate: '<S1475>/Saturation3' incorporates:
       *  Concatenate: '<S1475>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation3_UpperSat_f) {
        UAM_Flight_control_B.VectorConcatenate[3] =
          UAM_Flight_control_P.Saturation3_UpperSat_f;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation3_LowerSat_j) {
        UAM_Flight_control_B.VectorConcatenate[3] =
          UAM_Flight_control_P.Saturation3_LowerSat_j;
      } else {
        UAM_Flight_control_B.VectorConcatenate[3] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1475>/Saturation3' */

      /* Bias: '<S1475>/Bias4' incorporates:
       *  Gain: '<S1475>/Gain3'
       *  Gain: '<S1475>/Gain9'
       */
      rtb_Bias_l = s * UAM_Flight_control_B.c1 * UAM_Flight_control_P.Gain9_Gain
        + UAM_Flight_control_P.Bias4_Bias;

      /* Saturate: '<S1475>/Saturation4' incorporates:
       *  Concatenate: '<S1475>/Vector Concatenate'
       */
      if (rtb_Bias_l > UAM_Flight_control_P.Saturation4_UpperSat_b) {
        UAM_Flight_control_B.VectorConcatenate[4] =
          UAM_Flight_control_P.Saturation4_UpperSat_b;
      } else if (rtb_Bias_l < UAM_Flight_control_P.Saturation4_LowerSat_c) {
        UAM_Flight_control_B.VectorConcatenate[4] =
          UAM_Flight_control_P.Saturation4_LowerSat_c;
      } else {
        UAM_Flight_control_B.VectorConcatenate[4] = rtb_Bias_l;
      }

      /* End of Saturate: '<S1475>/Saturation4' */

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreator_ = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ba = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ed = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nl = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dq = 0U;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_k = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_m = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ps = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_e = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_d = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_g = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_n = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_i = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dg = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_a = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_b = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_j = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aj = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_h = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pg = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_n2 = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gx = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ad = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bb = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_p = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pd = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_f = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_by = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_c = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_du = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[0] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[1] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[2] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[3] = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aw = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_l = 0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jx = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bk = 0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ir = 0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ex = 0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ou = 0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_k5 = 0U;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_od = 0U;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_a2 = 0U;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      memset(&UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cv[0], 0, sizeof
             (real_T) << 4U);

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[0] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[1] = 0.0;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[2] = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_mq = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ke = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ah = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_e1 = 0.0F;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_on = 0.0;

      /* SignalConversion generated from: '<S1475>/Actuator_BusCreator' */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_da = 0.0;
    } else if (UAM_Flight_control_DW.Scheduler_MODE) {
      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreator_ =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_n =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ad =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jx =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_mq = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ke = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ah = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_e1 = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_on =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_da =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ba = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ed = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nl = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dq = (uint8_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_k = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_m = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ps = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_e =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_d =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_g =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_i =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dg =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_a =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_b =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_j =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aj = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_h = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pg = (real32_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_n2 =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gx =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bb =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_p =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pd =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_f =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_by =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_c =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_du =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[0] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[1] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[2] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[3] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aw =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_l = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bk = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ir = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ex = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ou = (int16_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_k5 = (uint8_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_od = (uint8_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_a2 = (uint8_T)
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
      for (i = 0; i < 6; i++) {
        /* Disable for Concatenate: '<S1475>/Vector Concatenate' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.VectorConcatenate[i] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
      }

      for (i = 0; i < 16; i++) {
        /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
         *  Outport: '<S1189>/MotorActuatorCommands'
         * */
        UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cv[i] =
          UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
      }

      /* Disable for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       * */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[0] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[1] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[2] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

      /* Disable for SignalConversion generated from: '<S1189>/CtrlSurfaceCommands' incorporates:
       *  Outport: '<S1189>/CtrlSurfaceCommands'
       * */
      UAM_Flight_control_B.OutportBufferForCtrlSurfaceComm =
        UAM_Flight_control_P.CtrlSurfaceCommands_Y0_k;
      UAM_Flight_control_DW.Scheduler_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S8>/multicopter Controller' */
    /* End of Outputs for SubSystem: '<S8>/FixedWing Controller' */
    /* End of Outputs for SubSystem: '<S8>/Scheduler' */

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  Concatenate: '<S1475>/Vector Concatenate'
     *  Constant: '<S1197>/Constant'
     *  Constant: '<S1475>/Constant'
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     *  RelationalOperator: '<S1197>/Compare'
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.roll =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreator_;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.pitch =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_n;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.dist_n =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ba;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.dist_e =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ed;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.dist_d =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nl;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.gps_num_sv =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dq;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.roll_rate =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_k;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.pitch_rate =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_m;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.yaw_rate =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ps;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.acc_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_e;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.acc_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_d;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.acc_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_g;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.yaw =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ad;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.pressure =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_i;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.vel_n =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dg;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.vel_e =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_a;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.vel_d =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_b;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.gndspeed =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_j;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.target_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aj;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.target_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_h;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.target_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pg;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.gyro_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_n2;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.gyro_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gx;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.altitude =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jx;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.gyro_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bb;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.mag_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_p;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.mag_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pd;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.mag_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_f;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.lin_acc_ecef_x =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_by;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.lin_acc_ecef_y =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_c;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.lin_acc_ecef_z =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_du;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.q[0] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[0];
    UAM_Flight_control_B.q[1] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[1];
    UAM_Flight_control_B.q[2] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[2];
    UAM_Flight_control_B.q[3] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[3];

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.airspeed =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aw;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.voltage =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_l;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.target_roll =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_mq;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.current =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bk;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.soc =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ir;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.temperature =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ex;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.soh =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ou;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.gcs_link =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_k5;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.rc_link =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_od;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.flight_mode =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_a2;
    for (i = 0; i < 6; i++) {
      /* Merge generated from: '<S1>/Merge' incorporates:
       *  SignalConversion generated from: '<S8>/Controller'
       */
      UAM_Flight_control_B.m[i] = UAM_Flight_control_B.VectorConcatenate[i];
    }

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    memcpy(&UAM_Flight_control_B.rc[0],
           &UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cv[0], sizeof
           (real_T) << 4U);

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.rpy_sp[0] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[0];
    UAM_Flight_control_B.rpy_sp[1] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[1];
    UAM_Flight_control_B.rpy_sp[2] =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[2];

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.target_pitch =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ke;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.target_yaw =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ah;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.target_alt =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_e1;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.latitude =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_on;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.longitude =
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_da;

    /* Merge generated from: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S8>/Controller'
     */
    UAM_Flight_control_B.CtrlSurfaceCommands =
      UAM_Flight_control_B.OutportBufferForCtrlSurfaceComm;

    /* Sum: '<S1187>/Sum' incorporates:
     *  Constant: '<S1187>/Constant'
     *  Constant: '<S1187>/Constant1'
     *  Gain: '<S1187>/Gain'
     *  Gain: '<S1187>/Gain1'
     *  RelationalOperator: '<S1187>/Relational Operator'
     *  RelationalOperator: '<S1187>/Relational Operator1'
     */
    rtb_Sum_i = (int8_T)(((UAM_Flight_control_B.FlightMode ==
      UAM_Flight_control_P.Constant_Value_ie ? (int32_T)
      UAM_Flight_control_P.Gain_Gain_o : 0) + (UAM_Flight_control_B.FlightMode ==
      UAM_Flight_control_P.Constant1_Value_gz ? (int32_T)
      UAM_Flight_control_P.Gain1_Gain_dg : 0)) >> 1);

    /* End of Outputs for SubSystem: '<S1>/Emergency' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Outport: '<Root>/Out1' incorporates:
   *  BusCreator generated from: '<Root>/Out1'
   *  UnitDelay: '<S6>/Unit Delay'
   *  UnitDelay: '<S6>/Unit Delay1'
   */
  UAM_Flight_control_Y.Out1.roll = UAM_Flight_control_B.roll;
  UAM_Flight_control_Y.Out1.pitch = UAM_Flight_control_B.pitch;
  UAM_Flight_control_Y.Out1.yaw = UAM_Flight_control_B.yaw;
  UAM_Flight_control_Y.Out1.altitude = UAM_Flight_control_B.altitude;
  UAM_Flight_control_Y.Out1.target_roll = UAM_Flight_control_B.target_roll;
  UAM_Flight_control_Y.Out1.target_pitch = UAM_Flight_control_B.target_pitch;
  UAM_Flight_control_Y.Out1.target_yaw = UAM_Flight_control_B.target_yaw;
  UAM_Flight_control_Y.Out1.target_alt = UAM_Flight_control_B.target_alt;
  UAM_Flight_control_Y.Out1.latitude = UAM_Flight_control_B.latitude;
  UAM_Flight_control_Y.Out1.longitude = UAM_Flight_control_B.longitude;
  UAM_Flight_control_Y.Out1.dist_n = UAM_Flight_control_B.dist_n;
  UAM_Flight_control_Y.Out1.dist_e = UAM_Flight_control_B.dist_e;
  UAM_Flight_control_Y.Out1.dist_d = UAM_Flight_control_B.dist_d;
  UAM_Flight_control_Y.Out1.gps_num_sv = UAM_Flight_control_B.gps_num_sv;
  UAM_Flight_control_Y.Out1.roll_rate = UAM_Flight_control_B.roll_rate;
  UAM_Flight_control_Y.Out1.pitch_rate = UAM_Flight_control_B.pitch_rate;
  UAM_Flight_control_Y.Out1.yaw_rate = UAM_Flight_control_B.yaw_rate;
  UAM_Flight_control_Y.Out1.acc_x = UAM_Flight_control_B.acc_x;
  UAM_Flight_control_Y.Out1.acc_y = UAM_Flight_control_B.acc_y;
  UAM_Flight_control_Y.Out1.acc_z = UAM_Flight_control_B.acc_z;
  UAM_Flight_control_Y.Out1.pressure = UAM_Flight_control_B.pressure;
  UAM_Flight_control_Y.Out1.vel_n = UAM_Flight_control_B.vel_n;
  UAM_Flight_control_Y.Out1.vel_e = UAM_Flight_control_B.vel_e;
  UAM_Flight_control_Y.Out1.vel_d = UAM_Flight_control_B.vel_d;
  UAM_Flight_control_Y.Out1.gndspeed = UAM_Flight_control_B.gndspeed;
  UAM_Flight_control_Y.Out1.target_x = UAM_Flight_control_B.target_x;
  UAM_Flight_control_Y.Out1.target_y = UAM_Flight_control_B.target_y;
  UAM_Flight_control_Y.Out1.target_z = UAM_Flight_control_B.target_z;
  UAM_Flight_control_Y.Out1.gyro_x = UAM_Flight_control_B.gyro_x;
  UAM_Flight_control_Y.Out1.gyro_y = UAM_Flight_control_B.gyro_y;
  UAM_Flight_control_Y.Out1.gyro_z = UAM_Flight_control_B.gyro_z;
  UAM_Flight_control_Y.Out1.mag_x = UAM_Flight_control_B.mag_x;
  UAM_Flight_control_Y.Out1.mag_y = UAM_Flight_control_B.mag_y;
  UAM_Flight_control_Y.Out1.mag_z = UAM_Flight_control_B.mag_z;
  UAM_Flight_control_Y.Out1.lin_acc_ecef_x = UAM_Flight_control_B.lin_acc_ecef_x;
  UAM_Flight_control_Y.Out1.lin_acc_ecef_y = UAM_Flight_control_B.lin_acc_ecef_y;
  UAM_Flight_control_Y.Out1.lin_acc_ecef_z = UAM_Flight_control_B.lin_acc_ecef_z;
  UAM_Flight_control_Y.Out1.q[0] = UAM_Flight_control_B.q[0];
  UAM_Flight_control_Y.Out1.q[1] = UAM_Flight_control_B.q[1];
  UAM_Flight_control_Y.Out1.q[2] = UAM_Flight_control_B.q[2];
  UAM_Flight_control_Y.Out1.q[3] = UAM_Flight_control_B.q[3];
  UAM_Flight_control_Y.Out1.airspeed = UAM_Flight_control_B.airspeed;
  UAM_Flight_control_Y.Out1.voltage = UAM_Flight_control_B.voltage;
  UAM_Flight_control_Y.Out1.current = UAM_Flight_control_B.current;
  UAM_Flight_control_Y.Out1.soc = UAM_Flight_control_B.soc;
  UAM_Flight_control_Y.Out1.temperature = UAM_Flight_control_B.temperature;
  UAM_Flight_control_Y.Out1.soh = UAM_Flight_control_B.soh;
  UAM_Flight_control_Y.Out1.gcs_link = UAM_Flight_control_B.gcs_link;
  UAM_Flight_control_Y.Out1.rc_link = UAM_Flight_control_B.rc_link;
  UAM_Flight_control_Y.Out1.flight_mode = UAM_Flight_control_B.flight_mode;
  for (i = 0; i < 6; i++) {
    UAM_Flight_control_Y.Out1.m[i] = UAM_Flight_control_B.m[i];
  }

  memcpy(&UAM_Flight_control_Y.Out1.rc[0], &UAM_Flight_control_B.rc[0], sizeof
         (real_T) << 4U);
  UAM_Flight_control_Y.Out1.rpy_sp[0] = UAM_Flight_control_B.rpy_sp[0];
  UAM_Flight_control_Y.Out1.rpy_sp[1] = UAM_Flight_control_B.rpy_sp[1];
  UAM_Flight_control_Y.Out1.rpy_sp[2] = UAM_Flight_control_B.rpy_sp[2];
  UAM_Flight_control_Y.Out1.z[0] = UAM_Flight_control_DW.UnitDelay1_DSTATE;
  UAM_Flight_control_Y.Out1.z[1] = UAM_Flight_control_DW.UnitDelay_DSTATE;

  /* End of Outport: '<Root>/Out1' */

  /* Outport: '<Root>/CtrlSurfaceCmds' */
  UAM_Flight_control_Y.CtrlSurfaceCmds =
    UAM_Flight_control_B.CtrlSurfaceCommands;

  /* Trigonometry: '<S2699>/Atan2' */
  s = rt_atan2d_snf(rtb_Kz_f, rtb_Kz);

  /* SwitchCase: '<S2699>/Switch Case' incorporates:
   *  Constant: '<S2699>/ground'
   *  Inport: '<Root>/fcc'
   *  RateTransition generated from: '<S2700>/Rate Transition1'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  switch (rtb_mode) {
   case Manual:
    /* Outputs for IfAction SubSystem: '<S2699>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S2703>/Action Port'
     */
    UAM_Flight_control_B.pqr[0] = UAM_Flight_control_U.fcc.gyro_x;
    UAM_Flight_control_B.Ve[0] = rtb_Kz;
    UAM_Flight_control_B.Xe[0] = rtb_Mag_idx_0;
    UAM_Flight_control_B.pqr[1] = UAM_Flight_control_U.fcc.gyro_y;
    UAM_Flight_control_B.Ve[1] = rtb_Kz_f;
    UAM_Flight_control_B.Xe[1] = rtb_Mag_idx_1;
    UAM_Flight_control_B.pqr[2] = UAM_Flight_control_U.fcc.gyro_z;
    UAM_Flight_control_B.Ve[2] = rtb_Kvz_a;
    UAM_Flight_control_B.Xe[2] = rtb_Mag_idx_2;
    UAM_Flight_control_B.RotorParameters_g =
      UAM_Flight_control_DW.RateTransition1_13_Buffer;
    memcpy(&UAM_Flight_control_B.RC_a[0], &UAM_Flight_control_U.fcc.rc[0], 10U *
           sizeof(real_T));
    UAM_Flight_control_B.target[0] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[0];
    UAM_Flight_control_B.target[1] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[1];
    UAM_Flight_control_B.target[2] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[2];
    SwitchCaseActionSubsystem_k(UAM_Flight_control_B.Xe, s, rtb_Gain1[2],
      rtb_Gain1[1], rtb_Gain1[0], UAM_Flight_control_DW.RateTransition1_1_Buffer,
      UAM_Flight_control_P.ground_Value, &UAM_Flight_control_B.mode_j,
      &UAM_Flight_control_B.ToWP_b, &UAM_Flight_control_B.FromWP_k,
      UAM_Flight_control_B.pose_h, UAM_Flight_control_B.Euler,
      &UAM_Flight_control_B.course, &UAM_Flight_control_B.ground_o,
      &UAM_Flight_control_P.SwitchCaseActionSubsystem);

    /* End of Outputs for SubSystem: '<S2699>/Switch Case Action Subsystem' */
    break;

   case Auto:
    /* Outputs for IfAction SubSystem: '<S2699>/Auto' incorporates:
     *  ActionPort: '<S2701>/Action Port'
     */
    /* SignalConversion generated from: '<S2708>/PathManagerSystemObject' */
    UAM_Flight_control_B.pose_h[3] = s;
    UAM_Flight_control_B.pose_h[0] = rtb_Mag_idx_0;
    UAM_Flight_control_B.pose_h[1] = rtb_Mag_idx_1;
    UAM_Flight_control_B.pose_h[2] = rtb_Mag_idx_2;

    /* RelationalOperator: '<S2706>/Compare' incorporates:
     *  Constant: '<S2706>/Constant'
     */
    rtb_Compare_j = (UAM_Flight_control_B.Status ==
                     UAM_Flight_control_P.CompareToConstant_const_c);

    /* MATLABSystem: '<S2708>/PathManagerSystemObject' incorporates:
     *  Constant: '<S2698>/Waypoints2'
     *  Constant: '<S2701>/Constant'
     *  Constant: '<S2701>/Constant1'
     * */
    if (UAM_Flight_control_DW.obj_c.MissionStart) {
      UAM_Flight_control_DW.obj_c.PrevMissionPoint.mode = 0U;
      UAM_Flight_control_DW.obj_c.PrevMissionPoint.position[0] =
        UAM_Flight_control_B.pose_h[0];
      UAM_Flight_control_DW.obj_c.PrevMissionPoint.position[1] =
        UAM_Flight_control_B.pose_h[1];
      UAM_Flight_control_DW.obj_c.PrevMissionPoint.position[2] =
        UAM_Flight_control_B.pose_h[2];
      UAM_Flight_control_DW.obj_c.PrevMissionPoint.params[0] = -1.0;
      UAM_Flight_control_DW.obj_c.PrevMissionPoint.params[1] = -1.0;
      UAM_Flight_control_DW.obj_c.PrevMissionPoint.params[2] = -1.0;
      UAM_Flight_control_DW.obj_c.PrevMissionPoint.params[3] = -1.0;
      UAM_Flight_control_DW.obj_c.MissionStart = false;
    }

    if ((rtb_Compare_j != UAM_Flight_control_DW.obj_c.PrevModeStatus) &&
        rtb_Compare_j && (UAM_Flight_control_P.Waypoints2_Value[(int32_T)
                          UAM_Flight_control_DW.obj_c.MissionPointCounter - 1].
                          mode != 7) && (UAM_Flight_control_P.Constant_Value_av
         != 1) && (UAM_Flight_control_P.Constant_Value_av != 3)) {
      UAM_Flight_control_DW.obj_c.PrevMissionPoint =
        UAM_Flight_control_P.Waypoints2_Value[(int32_T)
        UAM_Flight_control_DW.obj_c.MissionPointCounter - 1];
      if (UAM_Flight_control_DW.obj_c.MissionPointCounter == 10.0) {
        UAM_Flight_control_DW.obj_c.FinalMissionPoint = true;
        switch (UAM_Flight_control_P.Waypoints2_Value[9].mode) {
         case 1U:
         case 2U:
         case 3U:
         case 6U:
          UAM_Flight_control_DW.obj_c.MissionParams[0].mode = 7U;
          UAM_Flight_control_DW.obj_c.MissionParams[0].position[0] =
            UAM_Flight_control_B.pose_h[0];
          UAM_Flight_control_DW.obj_c.MissionParams[0].position[1] =
            UAM_Flight_control_B.pose_h[1];
          UAM_Flight_control_DW.obj_c.MissionParams[0].position[2] =
            UAM_Flight_control_B.pose_h[2];
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[0] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[1] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[2] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[3] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[1] =
            UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          break;

         case 4U:
          UAM_Flight_control_DW.obj_c.MissionParams[0] =
            UAM_Flight_control_P.Waypoints2_Value[(int32_T)
            UAM_Flight_control_DW.obj_c.MissionPointCounter - 1];
          UAM_Flight_control_DW.obj_c.MissionParams[1] =
            UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          break;

         case 5U:
          UAM_Flight_control_DW.obj_c.MissionParams[0].mode = 5U;
          UAM_Flight_control_DW.obj_c.MissionParams[0].position[0] =
            UAM_Flight_control_P.Constant1_Value_kd[0];
          UAM_Flight_control_DW.obj_c.MissionParams[0].position[1] =
            UAM_Flight_control_P.Constant1_Value_kd[1];
          UAM_Flight_control_DW.obj_c.MissionParams[0].position[2] =
            UAM_Flight_control_P.Constant1_Value_kd[2];
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[0] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[1] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[2] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[3] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[1] =
            UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          break;
        }

        UAM_Flight_control_DW.obj_c.EnableRepeat = true;
        UAM_Flight_control_DW.obj_c.MissionPointCounter--;
      }

      UAM_Flight_control_DW.obj_c.MissionPointCounter++;
    }

    guard1 = false;
    switch (UAM_Flight_control_P.Constant_Value_av) {
     case 0U:
      UAM_Flight_control_DW.obj_c.PoseHoldFlag = true;
      UAM_Flight_control_DW.obj_c.PoseRTLFlag = true;
      guard1 = true;
      break;

     case 1U:
      if (UAM_Flight_control_DW.obj_c.PoseHoldFlag) {
        UAM_Flight_control_DW.obj_c.HoldPose[0] = UAM_Flight_control_B.pose_h[0];
        UAM_Flight_control_DW.obj_c.HoldPose[1] = UAM_Flight_control_B.pose_h[1];
        UAM_Flight_control_DW.obj_c.HoldPose[2] = UAM_Flight_control_B.pose_h[2];
        UAM_Flight_control_DW.obj_c.HoldPose[3] = UAM_Flight_control_B.pose_h[3];
        UAM_Flight_control_DW.obj_c.PoseHoldFlag = false;
      }

      UAM_Flight_control_DW.obj_c.MissionParams[0].mode = 7U;
      UAM_Flight_control_DW.obj_c.MissionParams[0].position[0] =
        UAM_Flight_control_DW.obj_c.HoldPose[0];
      UAM_Flight_control_DW.obj_c.MissionParams[0].position[1] =
        UAM_Flight_control_DW.obj_c.HoldPose[1];
      UAM_Flight_control_DW.obj_c.MissionParams[0].position[2] =
        UAM_Flight_control_DW.obj_c.HoldPose[2];
      UAM_Flight_control_DW.obj_c.MissionParams[0].params[0] = -1.0;
      UAM_Flight_control_DW.obj_c.MissionParams[0].params[1] = -1.0;
      UAM_Flight_control_DW.obj_c.MissionParams[0].params[2] = -1.0;
      UAM_Flight_control_DW.obj_c.MissionParams[0].params[3] = -1.0;
      UAM_Flight_control_DW.obj_c.MissionParams[1] =
        UAM_Flight_control_DW.obj_c.PrevMissionPoint;
      UAM_Flight_control_DW.obj_c.PrevModeStatus = rtb_Compare_j;
      UAM_Flight_control_DW.obj_c.PoseRTLFlag = true;
      break;

     case 2U:
      if (UAM_Flight_control_DW.obj_c.EnableRepeat) {
        UAM_Flight_control_DW.obj_c.MissionPointCounter = 1.0;
        UAM_Flight_control_DW.obj_c.PoseHoldFlag = true;
        UAM_Flight_control_DW.obj_c.PoseRTLFlag = true;
        UAM_Flight_control_DW.obj_c.EnableRepeat = false;
        UAM_Flight_control_DW.obj_c.FinalMissionPoint = false;
      }

      guard1 = true;
      break;

     case 3U:
      if (UAM_Flight_control_DW.obj_c.PoseRTLFlag) {
        UAM_Flight_control_DW.obj_c.HoldPose[0] = UAM_Flight_control_B.pose_h[0];
        UAM_Flight_control_DW.obj_c.HoldPose[1] = UAM_Flight_control_B.pose_h[1];
        UAM_Flight_control_DW.obj_c.HoldPose[2] = UAM_Flight_control_B.pose_h[2];
        UAM_Flight_control_DW.obj_c.HoldPose[3] = UAM_Flight_control_B.pose_h[3];
        UAM_Flight_control_DW.obj_c.PoseRTLFlag = false;
        UAM_Flight_control_DW.obj_c.PrevMissionPoint.mode = 5U;
        UAM_Flight_control_DW.obj_c.PrevMissionPoint.position[0] =
          UAM_Flight_control_B.pose_h[0];
        UAM_Flight_control_DW.obj_c.PrevMissionPoint.position[1] =
          UAM_Flight_control_B.pose_h[1];
        UAM_Flight_control_DW.obj_c.PrevMissionPoint.position[2] =
          UAM_Flight_control_B.pose_h[2];
        UAM_Flight_control_DW.obj_c.PrevMissionPoint.params[0] = -1.0;
        UAM_Flight_control_DW.obj_c.PrevMissionPoint.params[1] = -1.0;
        UAM_Flight_control_DW.obj_c.PrevMissionPoint.params[2] = -1.0;
        UAM_Flight_control_DW.obj_c.PrevMissionPoint.params[3] = -1.0;
      }

      UAM_Flight_control_DW.obj_c.MissionParams[0].mode = 5U;
      UAM_Flight_control_DW.obj_c.MissionParams[0].position[0] =
        UAM_Flight_control_P.Constant1_Value_kd[0];
      UAM_Flight_control_DW.obj_c.MissionParams[0].position[1] =
        UAM_Flight_control_P.Constant1_Value_kd[1];
      UAM_Flight_control_DW.obj_c.MissionParams[0].position[2] =
        UAM_Flight_control_P.Constant1_Value_kd[2];
      UAM_Flight_control_DW.obj_c.MissionParams[0].params[0] = -1.0;
      UAM_Flight_control_DW.obj_c.MissionParams[0].params[1] = -1.0;
      UAM_Flight_control_DW.obj_c.MissionParams[0].params[2] = -1.0;
      UAM_Flight_control_DW.obj_c.MissionParams[0].params[3] = -1.0;
      UAM_Flight_control_DW.obj_c.MissionParams[1] =
        UAM_Flight_control_DW.obj_c.PrevMissionPoint;
      UAM_Flight_control_DW.obj_c.PoseHoldFlag = true;
      UAM_Flight_control_DW.obj_c.PrevModeStatus = rtb_Compare_j;
      break;

     default:
      guard1 = true;
      break;
    }

    if (guard1) {
      if (!UAM_Flight_control_DW.obj_c.FinalMissionPoint) {
        switch (UAM_Flight_control_P.Waypoints2_Value[(int32_T)
                UAM_Flight_control_DW.obj_c.MissionPointCounter - 1].mode) {
         case 6U:
          UAM_Flight_control_DW.obj_c.MissionParams[0] =
            UAM_Flight_control_P.Waypoints2_Value[(int32_T)
            UAM_Flight_control_DW.obj_c.MissionPointCounter - 1];
          UAM_Flight_control_DW.obj_c.MissionParams[1] =
            UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          break;

         case 1U:
          UAM_Flight_control_DW.obj_c.MissionParams[0] =
            UAM_Flight_control_P.Waypoints2_Value[(int32_T)
            UAM_Flight_control_DW.obj_c.MissionPointCounter - 1];
          UAM_Flight_control_DW.obj_c.MissionParams[1] =
            UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          break;

         case 2U:
          rtb_IsNaN2 = false;
          if (UAM_Flight_control_DW.obj_c.PrevMissionPoint.mode == 2) {
            rtb_IsNaN2 = true;
          }

          if (rtb_IsNaN2) {
            UAM_Flight_control_DW.obj_c.MissionParams[1] =
              UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          } else {
            UAM_Flight_control_DW.obj_c.MissionParams[1].mode =
              UAM_Flight_control_DW.obj_c.PrevMissionPoint.mode;
            UAM_Flight_control_DW.obj_c.MissionParams[1].position[0] =
              UAM_Flight_control_DW.obj_c.PrevMissionPoint.position[0];
            UAM_Flight_control_DW.obj_c.MissionParams[1].position[1] =
              UAM_Flight_control_DW.obj_c.PrevMissionPoint.position[1];
            UAM_Flight_control_DW.obj_c.MissionParams[1].position[2] =
              UAM_Flight_control_DW.obj_c.PrevMissionPoint.position[2];
            UAM_Flight_control_DW.obj_c.MissionParams[1].params[0] =
              rt_atan2d_snf(UAM_Flight_control_P.Waypoints2_Value[(int32_T)
                            UAM_Flight_control_DW.obj_c.MissionPointCounter - 1]
                            .position[1] -
                            UAM_Flight_control_DW.obj_c.PrevMissionPoint.position
                            [1], UAM_Flight_control_P.Waypoints2_Value[(int32_T)
                            UAM_Flight_control_DW.obj_c.MissionPointCounter - 1]
                            .position[0] -
                            UAM_Flight_control_DW.obj_c.PrevMissionPoint.position
                            [0]);
            UAM_Flight_control_DW.obj_c.MissionParams[1].params[1] = 25.0;
            UAM_Flight_control_DW.obj_c.MissionParams[1].params[2] = -1.0;
            UAM_Flight_control_DW.obj_c.MissionParams[1].params[3] = -1.0;
          }

          UAM_Flight_control_DW.obj_c.MissionParams[0] =
            UAM_Flight_control_P.Waypoints2_Value[(int32_T)
            UAM_Flight_control_DW.obj_c.MissionPointCounter - 1];
          break;

         case 3U:
          UAM_Flight_control_DW.obj_c.MissionParams[0] =
            UAM_Flight_control_P.Waypoints2_Value[(int32_T)
            UAM_Flight_control_DW.obj_c.MissionPointCounter - 1];
          UAM_Flight_control_DW.obj_c.MissionParams[1] =
            UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          break;

         case 4U:
          UAM_Flight_control_DW.obj_c.MissionParams[0] =
            UAM_Flight_control_P.Waypoints2_Value[(int32_T)
            UAM_Flight_control_DW.obj_c.MissionPointCounter - 1];
          UAM_Flight_control_DW.obj_c.MissionParams[1] =
            UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          break;

         case 5U:
          UAM_Flight_control_DW.obj_c.MissionParams[0].mode = 5U;
          UAM_Flight_control_DW.obj_c.MissionParams[0].position[0] =
            UAM_Flight_control_P.Constant1_Value_kd[0];
          UAM_Flight_control_DW.obj_c.MissionParams[0].position[1] =
            UAM_Flight_control_P.Constant1_Value_kd[1];
          UAM_Flight_control_DW.obj_c.MissionParams[0].position[2] =
            UAM_Flight_control_P.Constant1_Value_kd[2];
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[0] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[1] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[2] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[0].params[3] = -1.0;
          UAM_Flight_control_DW.obj_c.MissionParams[1] =
            UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          break;

         default:
          UAM_Flight_control_DW.obj_c.MissionParams[0] =
            UAM_Flight_control_P.Waypoints2_Value[(int32_T)
            UAM_Flight_control_DW.obj_c.MissionPointCounter - 1];
          UAM_Flight_control_DW.obj_c.MissionParams[1] =
            UAM_Flight_control_DW.obj_c.PrevMissionPoint;
          break;
        }
      }

      UAM_Flight_control_DW.obj_c.PrevModeStatus = rtb_Compare_j;
    }

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  MATLABSystem: '<S2708>/PathManagerSystemObject'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     * */
    UAM_Flight_control_B.FromWP_k = UAM_Flight_control_DW.obj_c.MissionParams[1];

    /* InitialCondition: '<S2701>/IC' */
    if (UAM_Flight_control_DW.IC_FirstOutputTime) {
      UAM_Flight_control_DW.IC_FirstOutputTime = false;

      /* Merge generated from: '<S2699>/Merge' incorporates:
       *  InitialCondition: '<S2701>/IC'
       */
      UAM_Flight_control_B.mode_j = UAM_Flight_control_P.IC_Value_h;
    } else {
      /* Merge generated from: '<S2699>/Merge' incorporates:
       *  MATLABSystem: '<S2708>/PathManagerSystemObject'
       * */
      UAM_Flight_control_B.mode_j = UAM_Flight_control_DW.obj_c.MissionParams[0]
        .mode;
    }

    /* End of InitialCondition: '<S2701>/IC' */

    /* BusCreator: '<S2701>/Bus Creator1' incorporates:
     *  Constant: '<S2701>/Constant2'
     *  Constant: '<S2701>/Constant3'
     *  Merge generated from: '<S2699>/Merge'
     *  RateTransition generated from: '<S2700>/Rate Transition1'
     *  Switch: '<S2701>/Switch'
     */
    UAM_Flight_control_B.ToWP_b.mode = UAM_Flight_control_P.Constant2_Value_fj;
    UAM_Flight_control_B.ToWP_b.position[0] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[0];
    UAM_Flight_control_B.ToWP_b.position[1] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[1];
    UAM_Flight_control_B.ToWP_b.position[2] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[2];
    UAM_Flight_control_B.ToWP_b.params[0] =
      UAM_Flight_control_P.Constant3_Value_ol[0];
    UAM_Flight_control_B.ToWP_b.params[1] =
      UAM_Flight_control_P.Constant3_Value_ol[1];
    UAM_Flight_control_B.ToWP_b.params[2] =
      UAM_Flight_control_P.Constant3_Value_ol[2];
    UAM_Flight_control_B.ToWP_b.params[3] =
      UAM_Flight_control_P.Constant3_Value_ol[3];

    /* Switch: '<S2701>/Switch' incorporates:
     *  Constant: '<S2707>/Constant'
     *  Logic: '<S2701>/Logical Operator'
     *  RateTransition generated from: '<S2700>/Rate Transition1'
     *  RelationalOperator: '<S2707>/Compare'
     */
    if ((!(UAM_Flight_control_DW.RateTransition1_17_Buffer[0] >=
           UAM_Flight_control_P.CompareToConstant1_const_f)) &&
        (!(UAM_Flight_control_DW.RateTransition1_17_Buffer[1] >=
           UAM_Flight_control_P.CompareToConstant1_const_f)) &&
        (!(UAM_Flight_control_DW.RateTransition1_17_Buffer[2] >=
           UAM_Flight_control_P.CompareToConstant1_const_f))) {
      /* Merge generated from: '<S2699>/Merge' incorporates:
       *  MATLABSystem: '<S2708>/PathManagerSystemObject'
       * */
      UAM_Flight_control_B.ToWP_b = UAM_Flight_control_DW.obj_c.MissionParams[0];
    }

    /* End of Switch: '<S2701>/Switch' */

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  RateTransition generated from: '<S2700>/Rate Transition1'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.RotorParameters_g =
      UAM_Flight_control_DW.RateTransition1_13_Buffer;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  Inport: '<Root>/fcc'
     *  SignalConversion generated from: '<Root>/fcc'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    memcpy(&UAM_Flight_control_B.RC_a[0], &UAM_Flight_control_U.fcc.rc[0], 10U *
           sizeof(real_T));

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  Constant: '<S2699>/ground'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.ground_o = UAM_Flight_control_P.ground_Value;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.Euler[0] = rtb_Gain1[2];
    UAM_Flight_control_B.Euler[1] = rtb_Gain1[1];
    UAM_Flight_control_B.Euler[2] = rtb_Gain1[0];

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  RateTransition generated from: '<S2700>/Rate Transition1'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.target[0] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[0];

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  Inport: '<Root>/fcc'
     *  SignalConversion generated from: '<Root>/fcc'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.pqr[0] = UAM_Flight_control_U.fcc.gyro_x;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.Ve[0] = rtb_Kz;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.Xe[0] = rtb_Mag_idx_0;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  RateTransition generated from: '<S2700>/Rate Transition1'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.target[1] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[1];

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  Inport: '<Root>/fcc'
     *  SignalConversion generated from: '<Root>/fcc'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.pqr[1] = UAM_Flight_control_U.fcc.gyro_y;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.Ve[1] = rtb_Kz_f;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.Xe[1] = rtb_Mag_idx_1;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  RateTransition generated from: '<S2700>/Rate Transition1'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.target[2] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[2];

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  Inport: '<Root>/fcc'
     *  SignalConversion generated from: '<Root>/fcc'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.pqr[2] = UAM_Flight_control_U.fcc.gyro_z;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.Ve[2] = rtb_Kvz_a;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.Xe[2] = rtb_Mag_idx_2;

    /* Merge generated from: '<S2699>/Merge' incorporates:
     *  RateTransition generated from: '<S2700>/Rate Transition1'
     *  SignalConversion generated from: '<S2701>/GNCPlan'
     */
    UAM_Flight_control_B.course = UAM_Flight_control_DW.RateTransition1_1_Buffer;

    /* End of Outputs for SubSystem: '<S2699>/Auto' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S2699>/Emergency' incorporates:
     *  ActionPort: '<S2702>/Action Port'
     */
    UAM_Flight_control_B.pqr[0] = UAM_Flight_control_U.fcc.gyro_x;
    UAM_Flight_control_B.Ve[0] = rtb_Kz;
    UAM_Flight_control_B.Xe[0] = rtb_Mag_idx_0;
    UAM_Flight_control_B.pqr[1] = UAM_Flight_control_U.fcc.gyro_y;
    UAM_Flight_control_B.Ve[1] = rtb_Kz_f;
    UAM_Flight_control_B.Xe[1] = rtb_Mag_idx_1;
    UAM_Flight_control_B.pqr[2] = UAM_Flight_control_U.fcc.gyro_z;
    UAM_Flight_control_B.Ve[2] = rtb_Kvz_a;
    UAM_Flight_control_B.Xe[2] = rtb_Mag_idx_2;
    UAM_Flight_control_B.RotorParameters_g =
      UAM_Flight_control_DW.RateTransition1_13_Buffer;
    memcpy(&UAM_Flight_control_B.RC_a[0], &UAM_Flight_control_U.fcc.rc[0], 10U *
           sizeof(real_T));
    UAM_Flight_control_B.target[0] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[0];
    UAM_Flight_control_B.target[1] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[1];
    UAM_Flight_control_B.target[2] =
      UAM_Flight_control_DW.RateTransition1_17_Buffer[2];
    SwitchCaseActionSubsystem_k(UAM_Flight_control_B.Xe, s, rtb_Gain1[2],
      rtb_Gain1[1], rtb_Gain1[0], UAM_Flight_control_DW.RateTransition1_1_Buffer,
      UAM_Flight_control_P.ground_Value, &UAM_Flight_control_B.mode_j,
      &UAM_Flight_control_B.ToWP_b, &UAM_Flight_control_B.FromWP_k,
      UAM_Flight_control_B.pose_h, UAM_Flight_control_B.Euler,
      &UAM_Flight_control_B.course, &UAM_Flight_control_B.ground_o,
      &UAM_Flight_control_P.Emergency_b);

    /* End of Outputs for SubSystem: '<S2699>/Emergency' */
    break;
  }

  /* End of SwitchCase: '<S2699>/Switch Case' */

  /* MATLABSystem: '<S2700>/AHRS' */
  if (UAM_Flight_control_DW.obj.AccelerometerNoise !=
      UAM_Flight_control_P.AHRS_AccelerometerNoise) {
    if (UAM_Flight_control_DW.obj.isInitialized == 1) {
      UAM_Flight_control_DW.obj.TunablePropsChanged = true;
    }

    UAM_Flight_control_DW.obj.AccelerometerNoise =
      UAM_Flight_control_P.AHRS_AccelerometerNoise;
  }

  if (UAM_Flight_control_DW.obj.GyroscopeNoise !=
      UAM_Flight_control_P.AHRS_GyroscopeNoise) {
    if (UAM_Flight_control_DW.obj.isInitialized == 1) {
      UAM_Flight_control_DW.obj.TunablePropsChanged = true;
    }

    UAM_Flight_control_DW.obj.GyroscopeNoise =
      UAM_Flight_control_P.AHRS_GyroscopeNoise;
  }

  if (UAM_Flight_control_DW.obj.MagnetometerNoise !=
      UAM_Flight_control_P.AHRS_MagnetometerNoise) {
    if (UAM_Flight_control_DW.obj.isInitialized == 1) {
      UAM_Flight_control_DW.obj.TunablePropsChanged = true;
    }

    UAM_Flight_control_DW.obj.MagnetometerNoise =
      UAM_Flight_control_P.AHRS_MagnetometerNoise;
  }

  if (UAM_Flight_control_DW.obj.GyroscopeDriftNoise !=
      UAM_Flight_control_P.AHRS_GyroscopeDriftNoise) {
    if (UAM_Flight_control_DW.obj.isInitialized == 1) {
      UAM_Flight_control_DW.obj.TunablePropsChanged = true;
    }

    UAM_Flight_control_DW.obj.GyroscopeDriftNoise =
      UAM_Flight_control_P.AHRS_GyroscopeDriftNoise;
  }

  if (UAM_Flight_control_DW.obj.LinearAccelerationNoise !=
      UAM_Flight_control_P.AHRS_LinearAccelerationNoise) {
    if (UAM_Flight_control_DW.obj.isInitialized == 1) {
      UAM_Flight_control_DW.obj.TunablePropsChanged = true;
    }

    UAM_Flight_control_DW.obj.LinearAccelerationNoise =
      UAM_Flight_control_P.AHRS_LinearAccelerationNoise;
  }

  if (UAM_Flight_control_DW.obj.MagneticDisturbanceNoise !=
      UAM_Flight_control_P.AHRS_MagneticDisturbanceNoise) {
    if (UAM_Flight_control_DW.obj.isInitialized == 1) {
      UAM_Flight_control_DW.obj.TunablePropsChanged = true;
    }

    UAM_Flight_control_DW.obj.MagneticDisturbanceNoise =
      UAM_Flight_control_P.AHRS_MagneticDisturbanceNoise;
  }

  if (UAM_Flight_control_DW.obj.LinearAccelerationDecayFactor !=
      UAM_Flight_control_P.AHRS_LinearAccelerationDecayFac) {
    if (UAM_Flight_control_DW.obj.isInitialized == 1) {
      UAM_Flight_control_DW.obj.TunablePropsChanged = true;
    }

    UAM_Flight_control_DW.obj.LinearAccelerationDecayFactor =
      UAM_Flight_control_P.AHRS_LinearAccelerationDecayFac;
  }

  if (UAM_Flight_control_DW.obj.MagneticDisturbanceDecayFactor !=
      UAM_Flight_control_P.AHRS_MagneticDisturbanceDecayFa) {
    if (UAM_Flight_control_DW.obj.isInitialized == 1) {
      UAM_Flight_control_DW.obj.TunablePropsChanged = true;
    }

    UAM_Flight_control_DW.obj.MagneticDisturbanceDecayFactor =
      UAM_Flight_control_P.AHRS_MagneticDisturbanceDecayFa;
  }

  if (UAM_Flight_control_DW.obj.ExpectedMagneticFieldStrength !=
      UAM_Flight_control_P.AHRS_ExpectedMagneticFieldStren) {
    if (UAM_Flight_control_DW.obj.isInitialized == 1) {
      UAM_Flight_control_DW.obj.TunablePropsChanged = true;
    }

    UAM_Flight_control_DW.obj.ExpectedMagneticFieldStrength =
      UAM_Flight_control_P.AHRS_ExpectedMagneticFieldStren;
  }

  /* Start for MATLABSystem: '<S2700>/AHRS' incorporates:
   *  Inport: '<Root>/fcc'
   *  SignalConversion generated from: '<Root>/fcc'
   */
  rtb_R_0[0] = UAM_Flight_control_U.fcc.mag_x;
  rtb_R_0[1] = UAM_Flight_control_U.fcc.mag_y;
  rtb_R_0[2] = UAM_Flight_control_U.fcc.mag_z;

  /* MATLABSystem: '<S2700>/AHRS' incorporates:
   *  Math: '<S2700>/Transpose8'
   *  Math: '<S2700>/Transpose9'
   */
  UAM_Flight_co_SystemCore_step_b(&UAM_Flight_control_DW.obj, rtb_Abb, rtb_pqr,
    rtb_R_0, rtb_dq, rtb_Gain1);

  /* MATLAB Function: '<S6>/MATLAB Function5' incorporates:
   *  MATLAB Function: '<S6>/MATLAB Function'
   */
  if ((!UAM_Flight_control_DW.p0_set) || (rtIsInf(P_Pa) || rtIsNaN(P_Pa))) {
    UAM_Flight_control_DW.y = 0.0;
    UAM_Flight_control_DW.init = false;
  } else if (!UAM_Flight_control_DW.init) {
    UAM_Flight_control_DW.y = P_Pa;
    UAM_Flight_control_DW.init = true;
  } else {
    UAM_Flight_control_DW.y += (P_Pa - UAM_Flight_control_DW.y) *
      0.030927573695189392;
  }

  /* End of MATLAB Function: '<S6>/MATLAB Function5' */

  /* Sum: '<S6>/Sum24' incorporates:
   *  Constant: '<S6>/Constant7'
   */
  rtb_Sum24 = UAM_Flight_control_P.Constant7_Value_o - rtb_Sum24;

  /* Product: '<S6>/Product12' incorporates:
   *  UnitDelay: '<S6>/Unit Delay2'
   */
  UAM_Flight_control_DW.UnitDelay2_DSTATE = rtb_pzz_n * rtb_Sum24;

  /* Product: '<S6>/Product13' incorporates:
   *  UnitDelay: '<S6>/Unit Delay3'
   */
  UAM_Flight_control_DW.UnitDelay3_DSTATE = rtb_pzv * rtb_Sum24;

  /* Sum: '<S6>/Sum25' incorporates:
   *  Product: '<S6>/Product14'
   *  Product: '<S6>/Product9'
   *  Sum: '<S6>/Sum15'
   *  UnitDelay: '<S6>/Unit Delay4'
   */
  UAM_Flight_control_DW.UnitDelay4_DSTATE = (rtb_Pzv_n - rtb_Pzv_n * rtb_Kvz) -
    rtb_pzv * rtb_Pzz_n;

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_9_DSTATE[0] = UAM_Flight_control_B.target[0];
  UAM_Flight_control_DW.UnitDelay1_9_DSTATE[1] = UAM_Flight_control_B.target[1];
  UAM_Flight_control_DW.UnitDelay1_9_DSTATE[2] = UAM_Flight_control_B.target[2];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  memcpy(&UAM_Flight_control_DW.UnitDelay1_8_DSTATE[0],
         &UAM_Flight_control_B.RC_a[0], 10U * sizeof(real_T));

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_7_DSTATE =
    UAM_Flight_control_B.RotorParameters_g;

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_6_DSTATE = UAM_Flight_control_B.course;

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_5_DSTATE[0] = UAM_Flight_control_B.Xe[0];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_4_DSTATE[0] = UAM_Flight_control_B.Ve[0];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
   *  Merge generated from: '<S2699>/Merge'
   */
  UAM_Flight_control_DW.UnitDelay1_3_DSTATE[0] = UAM_Flight_control_B.pqr[0];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_2_DSTATE[0] = UAM_Flight_control_B.Euler[0];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_5_DSTATE[1] = UAM_Flight_control_B.Xe[1];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_4_DSTATE[1] = UAM_Flight_control_B.Ve[1];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
   *  Merge generated from: '<S2699>/Merge'
   */
  UAM_Flight_control_DW.UnitDelay1_3_DSTATE[1] = UAM_Flight_control_B.pqr[1];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_2_DSTATE[1] = UAM_Flight_control_B.Euler[1];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_5_DSTATE[2] = UAM_Flight_control_B.Xe[2];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_4_DSTATE[2] = UAM_Flight_control_B.Ve[2];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
   *  Merge generated from: '<S2699>/Merge'
   */
  UAM_Flight_control_DW.UnitDelay1_3_DSTATE[2] = UAM_Flight_control_B.pqr[2];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_2_DSTATE[2] = UAM_Flight_control_B.Euler[2];

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' incorporates:
   *  Merge generated from: '<S2699>/Merge'
   */
  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0] = UAM_Flight_control_B.pose_h[0];
  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1] = UAM_Flight_control_B.pose_h[1];
  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2] = UAM_Flight_control_B.pose_h[2];
  UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3] = UAM_Flight_control_B.pose_h[3];

  /* Update for UnitDelay: '<S2>/Unit Delay2' */
  UAM_Flight_control_DW.UnitDelay2_DSTATE_l = UAM_Flight_control_B.a;

  /* Update for UnitDelay generated from: '<S2>/Unit Delay' incorporates:
   *  Merge generated from: '<S2699>/Merge'
   */
  UAM_Flight_control_DW.UnitDelay_3_DSTATE = UAM_Flight_control_B.FromWP_k;

  /* Update for UnitDelay generated from: '<S2>/Unit Delay' incorporates:
   *  Merge generated from: '<S2699>/Merge'
   */
  UAM_Flight_control_DW.UnitDelay_2_DSTATE = UAM_Flight_control_B.ToWP_b;

  /* Update for UnitDelay generated from: '<S2>/Unit Delay' */
  UAM_Flight_control_DW.UnitDelay_1_DSTATE_e = UAM_Flight_control_B.mode_j;

  /* Update for UnitDelay generated from: '<S2>/Unit Delay1' */
  UAM_Flight_control_DW.UnitDelay1_10_DSTATE = UAM_Flight_control_B.ground_o;

  /* Update for SwitchCase: '<S1>/Switch Case' */
  switch (UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m) {
   case 0:
    /* Update for IfAction SubSystem: '<S1>/Manual' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Update for Enabled SubSystem: '<S9>/multicopter Controller' incorporates:
     *  EnablePort: '<S1698>/Actuator Armed'
     */
    if (UAM_Flight_control_DW.multicopterController_MODE) {
      /* Update for UnitDelay: '<S2119>/Unit Delay' */
      UAM_Flight_control_DW.UnitDelay_DSTATE_d = rtb_Compare;

      /* Update for UnitDelay: '<S2119>/Unit Delay1' incorporates:
       *  DataTypeConversion: '<S6>/Data Type Conversion'
       */
      UAM_Flight_control_DW.UnitDelay1_DSTATE_l = rtb_Compare_ic;

      /* Update for DiscreteIntegrator: '<S2414>/Integrator' */
      UAM_Flight_control_DW.Integrator_DSTATE_n +=
        UAM_Flight_control_P.Integrator_gainval_du * rtb_hover_est_l;
      if (UAM_Flight_control_DW.Integrator_DSTATE_n >
          UAM_Flight_control_P.Yawratecontroller_UpperIntegrat) {
        UAM_Flight_control_DW.Integrator_DSTATE_n =
          UAM_Flight_control_P.Yawratecontroller_UpperIntegrat;
      } else if (UAM_Flight_control_DW.Integrator_DSTATE_n <
                 UAM_Flight_control_P.Yawratecontroller_LowerIntegrat) {
        UAM_Flight_control_DW.Integrator_DSTATE_n =
          UAM_Flight_control_P.Yawratecontroller_LowerIntegrat;
      }

      /* End of Update for DiscreteIntegrator: '<S2414>/Integrator' */

      /* Update for DiscreteIntegrator: '<S2201>/Filter' */
      UAM_Flight_control_DW.Filter_DSTATE_c5 +=
        UAM_Flight_control_P.Filter_gainval_p * rtb_throttle;

      /* Update for DiscreteIntegrator: '<S2206>/Integrator' */
      UAM_Flight_control_DW.Integrator_DSTATE_jv +=
        UAM_Flight_control_P.Integrator_gainval_m * rtb_IntegralGain_no;
      if (UAM_Flight_control_DW.Integrator_DSTATE_jv >
          UAM_Flight_control_P.Pitchratecontroller_UpperIntegr) {
        UAM_Flight_control_DW.Integrator_DSTATE_jv =
          UAM_Flight_control_P.Pitchratecontroller_UpperIntegr;
      } else if (UAM_Flight_control_DW.Integrator_DSTATE_jv <
                 UAM_Flight_control_P.Pitchratecontroller_LowerIntegr) {
        UAM_Flight_control_DW.Integrator_DSTATE_jv =
          UAM_Flight_control_P.Pitchratecontroller_LowerIntegr;
      }

      /* End of Update for DiscreteIntegrator: '<S2206>/Integrator' */

      /* Update for DiscreteIntegrator: '<S2305>/Filter' */
      UAM_Flight_control_DW.Filter_DSTATE_nj +=
        UAM_Flight_control_P.Filter_gainval_c * rtb_DeadZone_o;

      /* Update for DiscreteIntegrator: '<S2310>/Integrator' */
      UAM_Flight_control_DW.Integrator_DSTATE_m +=
        UAM_Flight_control_P.Integrator_gainval_o * rtb_Integrator_o4;
      if (UAM_Flight_control_DW.Integrator_DSTATE_m >
          UAM_Flight_control_P.Rollratecontroller_UpperIntegra) {
        UAM_Flight_control_DW.Integrator_DSTATE_m =
          UAM_Flight_control_P.Rollratecontroller_UpperIntegra;
      } else if (UAM_Flight_control_DW.Integrator_DSTATE_m <
                 UAM_Flight_control_P.Rollratecontroller_LowerIntegra) {
        UAM_Flight_control_DW.Integrator_DSTATE_m =
          UAM_Flight_control_P.Rollratecontroller_LowerIntegra;
      }

      /* End of Update for DiscreteIntegrator: '<S2310>/Integrator' */
    }

    /* End of Update for SubSystem: '<S9>/multicopter Controller' */

    /* Update for DiscreteIntegrator: '<S1695>/Discrete-Time Integrator' incorporates:
     *  Sum: '<S1695>/Sum'
     */
    UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE_i += rtb_Sum_pf;

    /* End of Update for SubSystem: '<S1>/Manual' */
    break;

   case 1:
    /* Update for IfAction SubSystem: '<S1>/Auto1' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    /* Update for Enabled SubSystem: '<S7>/Multicopter Controller' incorporates:
     *  EnablePort: '<S13>/ Armed'
     */
    if (UAM_Flight_control_DW.MulticopterController_MODE) {
      /* Update for DiscreteIntegrator: '<S935>/Integrator' */
      UAM_Flight_control_DW.Integrator_DSTATE_a +=
        UAM_Flight_control_P.Integrator_gainval_a * rtb_hover_est;
      if (UAM_Flight_control_DW.Integrator_DSTATE_a >
          UAM_Flight_control_P.Yawratecontroller_UpperIntegr_o) {
        UAM_Flight_control_DW.Integrator_DSTATE_a =
          UAM_Flight_control_P.Yawratecontroller_UpperIntegr_o;
      } else if (UAM_Flight_control_DW.Integrator_DSTATE_a <
                 UAM_Flight_control_P.Yawratecontroller_LowerIntegr_o) {
        UAM_Flight_control_DW.Integrator_DSTATE_a =
          UAM_Flight_control_P.Yawratecontroller_LowerIntegr_o;
      }

      /* End of Update for DiscreteIntegrator: '<S935>/Integrator' */

      /* Update for DiscreteIntegrator: '<S722>/Filter' */
      UAM_Flight_control_DW.Filter_DSTATE_m +=
        UAM_Flight_control_P.Filter_gainval_jc * rtb_IntegralGain_cj;

      /* Update for DiscreteIntegrator: '<S727>/Integrator' */
      UAM_Flight_control_DW.Integrator_DSTATE_h +=
        UAM_Flight_control_P.Integrator_gainval_on * rtb_Gain1_l;
      if (UAM_Flight_control_DW.Integrator_DSTATE_h >
          UAM_Flight_control_P.PitchRateController_UpperIntegr) {
        UAM_Flight_control_DW.Integrator_DSTATE_h =
          UAM_Flight_control_P.PitchRateController_UpperIntegr;
      } else if (UAM_Flight_control_DW.Integrator_DSTATE_h <
                 UAM_Flight_control_P.PitchRateController_LowerIntegr) {
        UAM_Flight_control_DW.Integrator_DSTATE_h =
          UAM_Flight_control_P.PitchRateController_LowerIntegr;
      }

      /* End of Update for DiscreteIntegrator: '<S727>/Integrator' */

      /* Update for DiscreteIntegrator: '<S826>/Filter' */
      UAM_Flight_control_DW.Filter_DSTATE_lr +=
        UAM_Flight_control_P.Filter_gainval_lj * rtb_DeadZone_hh;

      /* Update for DiscreteIntegrator: '<S831>/Integrator' */
      UAM_Flight_control_DW.Integrator_DSTATE_c +=
        UAM_Flight_control_P.Integrator_gainval_j5 * rtb_FilterCoefficient_f;
      if (UAM_Flight_control_DW.Integrator_DSTATE_c >
          UAM_Flight_control_P.RollRateController_UpperIntegra) {
        UAM_Flight_control_DW.Integrator_DSTATE_c =
          UAM_Flight_control_P.RollRateController_UpperIntegra;
      } else if (UAM_Flight_control_DW.Integrator_DSTATE_c <
                 UAM_Flight_control_P.RollRateController_LowerIntegra) {
        UAM_Flight_control_DW.Integrator_DSTATE_c =
          UAM_Flight_control_P.RollRateController_LowerIntegra;
      }

      /* End of Update for DiscreteIntegrator: '<S831>/Integrator' */
    }

    /* End of Update for SubSystem: '<S7>/Multicopter Controller' */
    /* End of Update for SubSystem: '<S1>/Auto1' */
    break;

   case 2:
    /* Update for IfAction SubSystem: '<S1>/Emergency' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Update for DiscreteIntegrator: '<S1187>/Discrete-Time Integrator' incorporates:
     *  Sum: '<S1187>/Sum'
     */
    UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE += rtb_Sum_i;

    /* End of Update for SubSystem: '<S1>/Emergency' */
    break;
  }

  /* End of Update for SwitchCase: '<S1>/Switch Case' */
}

/* Model initialize function */
void UAM_Flight_control_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (UAM_Flight_control_M)->Timing.TaskCounters.cLimit[0] = 1;
  (UAM_Flight_control_M)->Timing.TaskCounters.cLimit[1] = 5;

  {
    int32_T i;

    /* Start for SwitchCase: '<S1>/Switch Case' */
    UAM_Flight_control_DW.SwitchCase_ActiveSubsystem_m = -1;
    UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE_o = POS_ZCSIG;
    UAM_Flight_control_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay2' */
    UAM_Flight_control_DW.UnitDelay2_DSTATE =
      UAM_Flight_control_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay3' */
    UAM_Flight_control_DW.UnitDelay3_DSTATE =
      UAM_Flight_control_P.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay4' */
    UAM_Flight_control_DW.UnitDelay4_DSTATE =
      UAM_Flight_control_P.UnitDelay4_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay5' */
    UAM_Flight_control_DW.UnitDelay5_DSTATE =
      UAM_Flight_control_P.UnitDelay5_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_DSTATE =
      UAM_Flight_control_P.UnitDelay1_InitialCondition_j;

    /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_DSTATE =
      UAM_Flight_control_P.UnitDelay_InitialCondition_bd;

    /* InitializeConditions for UnitDelay: '<S2721>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[0] =
      UAM_Flight_control_P.UnitDelay_InitialCondition_f[0];
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[1] =
      UAM_Flight_control_P.UnitDelay_InitialCondition_f[1];
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[2] =
      UAM_Flight_control_P.UnitDelay_InitialCondition_f[2];
    UAM_Flight_control_DW.UnitDelay_DSTATE_m[3] =
      UAM_Flight_control_P.UnitDelay_InitialCondition_f[3];

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_9_DSTATE[0] =
      UAM_Flight_control_P.UnitDelay1_9_InitialCondition;
    UAM_Flight_control_DW.UnitDelay1_9_DSTATE[1] =
      UAM_Flight_control_P.UnitDelay1_9_InitialCondition;
    UAM_Flight_control_DW.UnitDelay1_9_DSTATE[2] =
      UAM_Flight_control_P.UnitDelay1_9_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    for (i = 0; i < 10; i++) {
      UAM_Flight_control_DW.UnitDelay1_8_DSTATE[i] =
        UAM_Flight_control_P.UnitDelay1_8_InitialCondition;
    }

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_7_DSTATE =
      UAM_Flight_control_P.UnitDelay1_7_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_6_DSTATE =
      UAM_Flight_control_P.UnitDelay1_6_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_5_DSTATE[0] =
      UAM_Flight_control_P.UnitDelay1_5_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_4_DSTATE[0] =
      UAM_Flight_control_P.UnitDelay1_4_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_3_DSTATE[0] =
      UAM_Flight_control_P.UnitDelay1_3_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_2_DSTATE[0] =
      UAM_Flight_control_P.UnitDelay1_2_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_5_DSTATE[1] =
      UAM_Flight_control_P.UnitDelay1_5_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_4_DSTATE[1] =
      UAM_Flight_control_P.UnitDelay1_4_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_3_DSTATE[1] =
      UAM_Flight_control_P.UnitDelay1_3_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_2_DSTATE[1] =
      UAM_Flight_control_P.UnitDelay1_2_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_5_DSTATE[2] =
      UAM_Flight_control_P.UnitDelay1_5_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_4_DSTATE[2] =
      UAM_Flight_control_P.UnitDelay1_4_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_3_DSTATE[2] =
      UAM_Flight_control_P.UnitDelay1_3_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_2_DSTATE[2] =
      UAM_Flight_control_P.UnitDelay1_2_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_1_DSTATE[0] =
      UAM_Flight_control_P.UnitDelay1_1_InitialCondition;
    UAM_Flight_control_DW.UnitDelay1_1_DSTATE[1] =
      UAM_Flight_control_P.UnitDelay1_1_InitialCondition;
    UAM_Flight_control_DW.UnitDelay1_1_DSTATE[2] =
      UAM_Flight_control_P.UnitDelay1_1_InitialCondition;
    UAM_Flight_control_DW.UnitDelay1_1_DSTATE[3] =
      UAM_Flight_control_P.UnitDelay1_1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay2' */
    UAM_Flight_control_DW.UnitDelay2_DSTATE_l =
      UAM_Flight_control_P.UnitDelay2_InitialCondition_g;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_3_DSTATE =
      UAM_Flight_control_P.UnitDelay_3_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_2_DSTATE =
      UAM_Flight_control_P.UnitDelay_2_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_1_DSTATE_e =
      UAM_Flight_control_P.UnitDelay_1_InitialCondition_e;

    /* InitializeConditions for UnitDelay generated from: '<S2>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_10_DSTATE =
      UAM_Flight_control_P.UnitDelay1_10_InitialCondition;

    /* SystemInitialize for IfAction SubSystem: '<S1>/Auto1' */
    /* SystemInitialize for Enabled SubSystem: '<S7>/Fixed Wing Controller' */
    /* SystemInitialize for Enabled SubSystem: '<S17>/Airspeed-Altitude Controller' */
    /* InitializeConditions for DiscreteIntegrator: '<S60>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_mx =
      UAM_Flight_control_P.AirspeedController_InitialCondi;

    /* InitializeConditions for DiscreteIntegrator: '<S65>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_cj =
      UAM_Flight_control_P.AirspeedController_InitialCon_l;

    /* SystemInitialize for Gain: '<S123>/Proportional Gain' incorporates:
     *  Merge: '<S19>/Climb Rate SP Merge'
     */
    UAM_Flight_control_B.ClimbRateSPMerge =
      UAM_Flight_control_P.ClimbRateSPMerge_InitialOutput;

    /* End of SystemInitialize for SubSystem: '<S17>/Airspeed-Altitude Controller' */

    /* SystemInitialize for Enabled SubSystem: '<S17>/Pitch, Airspeed SP from Controller' */
    /* Start for InitialCondition: '<S22>/IC' */
    UAM_Flight_control_DW.IC_FirstOutputTime_a = true;

    /* InitializeConditions for DiscreteIntegrator: '<S493>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_a =
      UAM_Flight_control_P.AirspeedController_InitialCon_a;

    /* InitializeConditions for DiscreteIntegrator: '<S498>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_on =
      UAM_Flight_control_P.AirspeedController_InitialCon_f;

    /* End of SystemInitialize for SubSystem: '<S17>/Pitch, Airspeed SP from Controller' */

    /* SystemInitialize for Merge: '<S17>/Actuator dT Merge' */
    UAM_Flight_control_B.ActuatordTMerge =
      UAM_Flight_control_P.ActuatordTMerge_InitialOutput;

    /* SystemInitialize for Enabled SubSystem: '<S17>/Attitude Controller' */
    /* SystemInitialize for Enabled SubSystem: '<S20>/Pitch Roll Controller' */
    /* InitializeConditions for DiscreteIntegrator: '<S234>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_d =
      UAM_Flight_control_P.PitchAngleController_InitialC_c;

    /* InitializeConditions for DiscreteIntegrator: '<S229>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_p =
      UAM_Flight_control_P.PitchAngleController_InitialC_p;

    /* End of SystemInitialize for SubSystem: '<S20>/Pitch Roll Controller' */
    /* End of SystemInitialize for SubSystem: '<S17>/Attitude Controller' */

    /* SystemInitialize for Merge: '<S17>/Merge' */
    UAM_Flight_control_B.Merge_p[0] = UAM_Flight_control_P.Merge_InitialOutput_d;
    UAM_Flight_control_B.Merge_p[1] = UAM_Flight_control_P.Merge_InitialOutput_d;
    UAM_Flight_control_B.Merge_p[2] = UAM_Flight_control_P.Merge_InitialOutput_d;

    /* SystemInitialize for Gain: '<S176>/Proportional Gain' incorporates:
     *  Merge: '<S17>/Pitch SP Merge'
     */
    UAM_Flight_control_B.PitchSPMerge =
      UAM_Flight_control_P.PitchSPMerge_InitialOutput;

    /* SystemInitialize for Merge: '<S17>/Roll SP Merge' */
    UAM_Flight_control_B.RollSPMerge =
      UAM_Flight_control_P.RollSPMerge_InitialOutput;

    /* End of SystemInitialize for SubSystem: '<S7>/Fixed Wing Controller' */

    /* SystemInitialize for Enabled SubSystem: '<S7>/Multicopter Controller' */
    /* InitializeConditions for DiscreteIntegrator: '<S935>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_a =
      UAM_Flight_control_P.Yawratecontroller_InitialCond_a;

    /* InitializeConditions for DiscreteIntegrator: '<S722>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_m =
      UAM_Flight_control_P.PitchRateController_InitialCond;

    /* InitializeConditions for DiscreteIntegrator: '<S727>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_h =
      UAM_Flight_control_P.PitchRateController_InitialCo_m;

    /* InitializeConditions for DiscreteIntegrator: '<S826>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_lr =
      UAM_Flight_control_P.RollRateController_InitialCondi;

    /* InitializeConditions for DiscreteIntegrator: '<S831>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_c =
      UAM_Flight_control_P.RollRateController_InitialCon_j;

    /* SystemInitialize for Enabled SubSystem: '<S517>/Altitude Control' */
    /* InitializeConditions for DiscreteIntegrator: '<S616>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_o =
      UAM_Flight_control_P.Altituderatecontroller1_Initi_k;
    UAM_Flight_control_DW.Integrator_PrevResetState_p = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S611>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_n =
      UAM_Flight_control_P.Altituderatecontroller1_Initial;
    UAM_Flight_control_DW.Filter_PrevResetState_e = 2;

    /* SystemInitialize for MATLAB Function: '<S521>/MATLAB Function' */
    UAM_F_MATLABFunction_k_Init(&UAM_Flight_control_DW.sf_MATLABFunction_ac);

    /* SystemInitialize for Triggered SubSystem: '<S521>/Triggered Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S527>/AltHold' incorporates:
     *  Outport: '<S527>/Reference'
     */
    UAM_Flight_control_B.AltHold = UAM_Flight_control_P.Reference_Y0;

    /* End of SystemInitialize for SubSystem: '<S521>/Triggered Subsystem' */

    /* SystemInitialize for Sum: '<S521>/Sum3' incorporates:
     *  Outport: '<S521>/commanded thrust'
     *  Saturate: '<S521>/Saturation1'
     *  UnitDelay: '<S521>/Unit Delay'
     */
    UAM_Flight_control_DW.UnitDelay_DSTATE_f =
      UAM_Flight_control_P.commandedthrust_Y0;

    /* End of SystemInitialize for SubSystem: '<S517>/Altitude Control' */

    /* SystemInitialize for Enabled SubSystem: '<S13>/Horizontal Position Control' */
    /* SystemInitialize for Enabled SubSystem: '<S518>/XY Controller' */
    /* InitializeConditions for DiscreteIntegrator: '<S1051>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_j =
      UAM_Flight_control_P.Forwardvelocitycontroller_Ini_o;
    UAM_Flight_control_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S1046>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_c =
      UAM_Flight_control_P.Forwardvelocitycontroller_Ini_a;
    UAM_Flight_control_DW.Filter_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S1157>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_hy =
      UAM_Flight_control_P.Lateralvelocitycontroller_Ini_m;
    UAM_Flight_control_DW.Integrator_PrevResetState_n = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S1152>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_lq =
      UAM_Flight_control_P.Lateralvelocitycontroller_Ini_p;
    UAM_Flight_control_DW.Filter_PrevResetState_p = 2;

    /* SystemInitialize for Gain: '<S953>/Gain' incorporates:
     *  Outport: '<S953>/Forward cmd'
     *  Saturate: '<S953>/Saturation'
     */
    UAM_Flight_control_B.Saturation_g = UAM_Flight_control_P.Forwardcmd_Y0;

    /* SystemInitialize for Gain: '<S953>/rad' incorporates:
     *  Outport: '<S953>/Sideward Cmd'
     *  Saturate: '<S953>/Saturation1'
     */
    UAM_Flight_control_B.Saturation1 = UAM_Flight_control_P.SidewardCmd_Y0;

    /* End of SystemInitialize for SubSystem: '<S518>/XY Controller' */
    /* End of SystemInitialize for SubSystem: '<S13>/Horizontal Position Control' */

    /* SystemInitialize for Merge: '<S13>/Merge' */
    UAM_Flight_control_B.Merge_d5 = UAM_Flight_control_P.Merge_InitialOutput_gy;

    /* SystemInitialize for Merge: '<S13>/Merge1' */
    UAM_Flight_control_B.Merge1 = UAM_Flight_control_P.Merge1_InitialOutput;

    /* SystemInitialize for Sum: '<S840>/Sum' incorporates:
     *  Outport: '<S13>/MixerCommands'
     *  SignalConversion generated from: '<S13>/MixerCommands'
     */
    UAM_Flight_control_B.w_phi = UAM_Flight_control_P.MixerCommands_Y0_o.w_phi;

    /* SystemInitialize for Sum: '<S736>/Sum' incorporates:
     *  Outport: '<S13>/MixerCommands'
     *  SignalConversion generated from: '<S13>/MixerCommands'
     */
    UAM_Flight_control_B.w_theta =
      UAM_Flight_control_P.MixerCommands_Y0_o.w_theta;

    /* SystemInitialize for Gain: '<S523>/Gain1' incorporates:
     *  Outport: '<S13>/MixerCommands'
     *  SignalConversion generated from: '<S13>/MixerCommands'
     */
    UAM_Flight_control_B.w_psi = UAM_Flight_control_P.MixerCommands_Y0_o.w_psi;

    /* SystemInitialize for SignalConversion generated from: '<S13>/MixerCommands' incorporates:
     *  Outport: '<S13>/MixerCommands'
     */
    UAM_Flight_control_B.w_z = UAM_Flight_control_P.MixerCommands_Y0_o.w_z;

    /* End of SystemInitialize for SubSystem: '<S7>/Multicopter Controller' */

    /* SystemInitialize for Enabled SubSystem: '<S7>/Scheduler' */
    /* SystemInitialize for Merge: '<S1175>/Merge' */
    UAM_Flight_control_B.Merge_b = UAM_Flight_control_P.Merge_InitialOutput_m;

    /* SystemInitialize for Merge generated from: '<S1176>/Merge' */
    UAM_Flight_control_B.w1_j = UAM_Flight_control_P.Merge_1_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1176>/Merge' */
    UAM_Flight_control_B.w2_i = UAM_Flight_control_P.Merge_2_InitialOutput_i;

    /* SystemInitialize for Merge generated from: '<S1176>/Merge' */
    UAM_Flight_control_B.w3_o = UAM_Flight_control_P.Merge_3_InitialOutput_i;

    /* SystemInitialize for Merge generated from: '<S1176>/Merge' */
    UAM_Flight_control_B.w4_g = UAM_Flight_control_P.Merge_4_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1176>/Merge' */
    UAM_Flight_control_B.c1_i = UAM_Flight_control_P.Merge_5_InitialOutput_i;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cv2 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nw =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_adl =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jx3 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mqv = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kew = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ahl = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_e1u = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_oni =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dax =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_baw = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_edg = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nly = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dq0 = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_kb = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_me = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ps2 = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ez =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_de =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gb =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_i0 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dgz =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ae =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bj =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jj =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ajj = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_hw = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pgb = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_n2x =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gx0 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bbr =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_py =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pds =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fs =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_by1 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cr =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_duz =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[0] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[1] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[2] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_b55[3] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_awy =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_l5 = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bkn = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_irm = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_exu = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ouu = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_k55 = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_odd = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_a2g = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
    for (i = 0; i < 6; i++) {
      /* SystemInitialize for Concatenate: '<S1181>/Vector Concatenate' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       */
      UAM_Flight_control_B.VectorConcatenate_f[i] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
    }

    for (i = 0; i < 16; i++) {
      /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
       *  Outport: '<S14>/MotorActuatorCommands'
       */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cvb[i] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
    }

    /* SystemInitialize for SignalConversion generated from: '<S1181>/Actuator_BusCreator' incorporates:
     *  Outport: '<S14>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[0] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[1] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fp5[2] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_f;

    /* SystemInitialize for SignalConversion generated from: '<S14>/CtrlSurfaceCommands' incorporates:
     *  Outport: '<S14>/CtrlSurfaceCommands'
     */
    UAM_Flight_control_B.OutportBufferForCtrlSurfaceCo_i =
      UAM_Flight_control_P.CtrlSurfaceCommands_Y0_h;

    /* End of SystemInitialize for SubSystem: '<S7>/Scheduler' */
    /* End of SystemInitialize for SubSystem: '<S1>/Auto1' */

    /* SystemInitialize for IfAction SubSystem: '<S1>/Emergency' */
    /* InitializeConditions for DiscreteIntegrator: '<S1187>/Discrete-Time Integrator' */
    UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE =
      UAM_Flight_control_P.DiscreteTimeIntegrator_IC_l;

    /* SystemInitialize for Enabled SubSystem: '<S8>/FixedWing Controller' */
    /* SystemInitialize for Enabled SubSystem: '<S1191>/Attitude Controller' */
    /* SystemInitialize for Enabled SubSystem: '<S1192>/Pitch Roll Controller' */
    /* InitializeConditions for DiscreteIntegrator: '<S1240>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE =
      UAM_Flight_control_P.PitchAngleController_InitialC_f;

    /* InitializeConditions for DiscreteIntegrator: '<S1235>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_l =
      UAM_Flight_control_P.PitchAngleController_Initial_pa;

    /* SystemInitialize for Gain: '<S1401>/Proportional Gain' incorporates:
     *  Outport: '<S1198>/AER'
     *  Saturate: '<S1198>/Saturation2'
     */
    UAM_Flight_control_B.Saturation2 = UAM_Flight_control_P.AER_Y0_e;

    /* SystemInitialize for UnaryMinus: '<S1198>/Unary Minus1' incorporates:
     *  Outport: '<S1198>/AER'
     */
    UAM_Flight_control_B.dE_j = UAM_Flight_control_P.AER_Y0_e;

    /* SystemInitialize for Gain: '<S1455>/Proportional Gain' incorporates:
     *  Outport: '<S1198>/AER'
     *  Saturate: '<S1457>/Saturation'
     */
    UAM_Flight_control_B.Saturation = UAM_Flight_control_P.AER_Y0_e;

    /* End of SystemInitialize for SubSystem: '<S1192>/Pitch Roll Controller' */
    /* End of SystemInitialize for SubSystem: '<S1191>/Attitude Controller' */

    /* SystemInitialize for SignalConversion generated from: '<S1188>/Actuator' incorporates:
     *  Outport: '<S1188>/Actuator'
     */
    UAM_Flight_control_B.dA = UAM_Flight_control_P.Actuator_Y0_a.dA;

    /* SystemInitialize for SignalConversion generated from: '<S1188>/Actuator' incorporates:
     *  Outport: '<S1188>/Actuator'
     */
    UAM_Flight_control_B.dE = UAM_Flight_control_P.Actuator_Y0_a.dE;

    /* SystemInitialize for SignalConversion generated from: '<S1188>/Actuator' incorporates:
     *  Outport: '<S1188>/Actuator'
     */
    UAM_Flight_control_B.dR = UAM_Flight_control_P.Actuator_Y0_a.dR;

    /* SystemInitialize for SignalConversion generated from: '<S1188>/Actuator' incorporates:
     *  Outport: '<S1188>/Actuator'
     */
    UAM_Flight_control_B.dT = UAM_Flight_control_P.Actuator_Y0_a.dT;

    /* End of SystemInitialize for SubSystem: '<S8>/FixedWing Controller' */

    /* SystemInitialize for Enabled SubSystem: '<S8>/Scheduler' */
    /* SystemInitialize for Merge: '<S1469>/Merge' */
    UAM_Flight_control_B.Merge = UAM_Flight_control_P.Merge_InitialOutput_g;

    /* SystemInitialize for Merge generated from: '<S1470>/Merge' */
    UAM_Flight_control_B.w1 = UAM_Flight_control_P.Merge_1_InitialOutput_f;

    /* SystemInitialize for Merge generated from: '<S1470>/Merge' */
    UAM_Flight_control_B.w2 = UAM_Flight_control_P.Merge_2_InitialOutput_f;

    /* SystemInitialize for Merge generated from: '<S1470>/Merge' */
    UAM_Flight_control_B.w3 = UAM_Flight_control_P.Merge_3_InitialOutput_f;

    /* SystemInitialize for Merge generated from: '<S1470>/Merge' */
    UAM_Flight_control_B.w4 = UAM_Flight_control_P.Merge_4_InitialOutput_f;

    /* SystemInitialize for Merge generated from: '<S1470>/Merge' */
    UAM_Flight_control_B.c1 = UAM_Flight_control_P.Merge_5_InitialOutput_f;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreator_ =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_n =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ad =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_jx =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_mq = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ke = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ah = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_e1 = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_on =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_da =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ba = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ed = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_nl = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dq = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_k = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_m = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ps = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_e =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_d =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_g =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_i =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_dg =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_a =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_b =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_j =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aj = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_h = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pg = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_n2 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_gx =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bb =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_p =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_pd =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_f =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_by =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_c =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_du =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[0] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[1] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[2] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_b5[3] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_aw =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreato_l = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_bk = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ir = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ex = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_ou = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_k5 = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_od = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_a2 = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
    for (i = 0; i < 6; i++) {
      /* SystemInitialize for Concatenate: '<S1475>/Vector Concatenate' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       */
      UAM_Flight_control_B.VectorConcatenate[i] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
    }

    for (i = 0; i < 16; i++) {
      /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1189>/MotorActuatorCommands'
       */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_cv[i] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
    }

    /* SystemInitialize for SignalConversion generated from: '<S1475>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1189>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[0] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[1] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCreat_fp[2] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0_j;

    /* SystemInitialize for SignalConversion generated from: '<S1189>/CtrlSurfaceCommands' incorporates:
     *  Outport: '<S1189>/CtrlSurfaceCommands'
     */
    UAM_Flight_control_B.OutportBufferForCtrlSurfaceComm =
      UAM_Flight_control_P.CtrlSurfaceCommands_Y0_k;

    /* End of SystemInitialize for SubSystem: '<S8>/Scheduler' */

    /* SystemInitialize for Enabled SubSystem: '<S8>/multicopter Controller' */
    /* InitializeConditions for DiscreteIntegrator: '<S1672>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE =
      UAM_Flight_control_P.Yawratecontroller_InitialCondit;

    /* SystemInitialize for Sum: '<S1482>/Sum1' incorporates:
     *  Outport: '<S1190>/MixerCommands'
     */
    UAM_Flight_control_B.t_p = UAM_Flight_control_P.MixerCommands_Y0_e.w_phi;

    /* SystemInitialize for Sum: '<S1482>/Sum2' incorporates:
     *  Outport: '<S1190>/MixerCommands'
     */
    UAM_Flight_control_B.e_q = UAM_Flight_control_P.MixerCommands_Y0_e.w_theta;

    /* SystemInitialize for Sum: '<S1686>/Sum' incorporates:
     *  Outport: '<S1190>/MixerCommands'
     */
    UAM_Flight_control_B.Sum = UAM_Flight_control_P.MixerCommands_Y0_e.w_psi;

    /* SystemInitialize for Gain: '<S1480>/Gain' incorporates:
     *  Outport: '<S1190>/MixerCommands'
     */
    UAM_Flight_control_B.Gain = UAM_Flight_control_P.MixerCommands_Y0_e.w_z;

    /* End of SystemInitialize for SubSystem: '<S8>/multicopter Controller' */
    /* End of SystemInitialize for SubSystem: '<S1>/Emergency' */

    /* SystemInitialize for IfAction SubSystem: '<S1>/Manual' */
    /* InitializeConditions for DiscreteIntegrator: '<S1695>/Discrete-Time Integrator' */
    UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE_i =
      UAM_Flight_control_P.DiscreteTimeIntegrator_IC;

    /* SystemInitialize for Enabled SubSystem: '<S9>/FixedWing Controller' */
    /* SystemInitialize for Enabled SubSystem: '<S1699>/Attitude Controller' */
    /* SystemInitialize for Enabled SubSystem: '<S1700>/Pitch Roll Controller' */
    /* InitializeConditions for DiscreteIntegrator: '<S1748>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_p =
      UAM_Flight_control_P.PitchAngleController_InitialC_d;

    /* InitializeConditions for DiscreteIntegrator: '<S1743>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_px =
      UAM_Flight_control_P.PitchAngleController_InitialCon;

    /* SystemInitialize for Gain: '<S1909>/Proportional Gain' incorporates:
     *  Outport: '<S1706>/AER'
     *  Saturate: '<S1706>/Saturation2'
     */
    UAM_Flight_control_B.Saturation2_n = UAM_Flight_control_P.AER_Y0;

    /* SystemInitialize for Product: '<S1706>/Matrix Multiply' incorporates:
     *  Outport: '<S1706>/AER'
     */
    UAM_Flight_control_B.MatrixMultiply[0] = UAM_Flight_control_P.AER_Y0;
    UAM_Flight_control_B.MatrixMultiply[1] = UAM_Flight_control_P.AER_Y0;

    /* End of SystemInitialize for SubSystem: '<S1700>/Pitch Roll Controller' */
    /* End of SystemInitialize for SubSystem: '<S1699>/Attitude Controller' */

    /* SystemInitialize for SignalConversion generated from: '<S1696>/Actuator' incorporates:
     *  Outport: '<S1696>/Actuator'
     */
    UAM_Flight_control_B.dA_n = UAM_Flight_control_P.Actuator_Y0.dA;

    /* SystemInitialize for SignalConversion generated from: '<S1696>/Actuator' incorporates:
     *  Outport: '<S1696>/Actuator'
     */
    UAM_Flight_control_B.dE_a = UAM_Flight_control_P.Actuator_Y0.dE;

    /* SystemInitialize for SignalConversion generated from: '<S1696>/Actuator' incorporates:
     *  Outport: '<S1696>/Actuator'
     */
    UAM_Flight_control_B.dR_g = UAM_Flight_control_P.Actuator_Y0.dR;

    /* SystemInitialize for SignalConversion generated from: '<S1696>/Actuator' incorporates:
     *  Outport: '<S1696>/Actuator'
     */
    UAM_Flight_control_B.dT_i = UAM_Flight_control_P.Actuator_Y0.dT;

    /* End of SystemInitialize for SubSystem: '<S9>/FixedWing Controller' */

    /* SystemInitialize for Enabled SubSystem: '<S9>/Scheduler' */
    /* SystemInitialize for Merge: '<S1977>/Merge' */
    UAM_Flight_control_B.Merge_d = UAM_Flight_control_P.Merge_InitialOutput;

    /* SystemInitialize for IfAction SubSystem: '<S1978>/Switch Case Action Subsystem' */
    /* SystemInitialize for Outport: '<S1984>/Actuator_Outport_1' */
    UAM_Flight_control_B.m_out[0] =
      UAM_Flight_control_P.Actuator_Outport_1_Y0.w1;
    UAM_Flight_control_B.m_out[1] =
      UAM_Flight_control_P.Actuator_Outport_1_Y0.w2;
    UAM_Flight_control_B.m_out[2] =
      UAM_Flight_control_P.Actuator_Outport_1_Y0.w3;
    UAM_Flight_control_B.m_out[3] =
      UAM_Flight_control_P.Actuator_Outport_1_Y0.w4;

    /* SystemInitialize for SignalConversion generated from: '<S1984>/Constant4' incorporates:
     *  Outport: '<S1984>/Actuator_Outport_1'
     */
    UAM_Flight_control_B.TmpBufferAtConstant4Outport1 =
      UAM_Flight_control_P.Actuator_Outport_1_Y0.c1;

    /* End of SystemInitialize for SubSystem: '<S1978>/Switch Case Action Subsystem' */

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cv2z =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_nw2 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_adlp =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_jx3i =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_mqvj = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_kewq = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ahl1 = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_e1ub = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_oniv =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_daxi =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bawm = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_edgh = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_nlya = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dq0y = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_kbh = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_mey = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ps2n = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ezp =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_dec =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_gbt =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_i0g =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_dgzi =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_ae0 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_bjh =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_jjd =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ajjw = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_hwn = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pgbn = (real32_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_n2x4 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_gx0x =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bbr4 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_pyg =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_pdsb =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_fsn =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_by1n =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_cr0 =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_duzz =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[0] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[1] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[2] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_b55m[3] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_awya =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCrea_l5c = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_bkn5 = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_irme = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_exub = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_ouuy = (int16_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_k55z = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_odds = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_a2gj = (uint8_T)
      UAM_Flight_control_P.MotorActuatorCommands_Y0;
    for (i = 0; i < 6; i++) {
      /* SystemInitialize for Concatenate: '<S1983>/Vector Concatenate' incorporates:
       *  Outport: '<S1697>/MotorActuatorCommands'
       */
      UAM_Flight_control_B.VectorConcatenate_c[i] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0;
    }

    for (i = 0; i < 16; i++) {
      /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
       *  Outport: '<S1697>/MotorActuatorCommands'
       */
      UAM_Flight_control_B.TmpBufferAtActuator_BusCre_cvbt[i] =
        UAM_Flight_control_P.MotorActuatorCommands_Y0;
    }

    /* SystemInitialize for SignalConversion generated from: '<S1983>/Actuator_BusCreator' incorporates:
     *  Outport: '<S1697>/MotorActuatorCommands'
     */
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[0] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[1] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;
    UAM_Flight_control_B.TmpBufferAtActuator_BusCre_fp5m[2] =
      UAM_Flight_control_P.MotorActuatorCommands_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S1697>/CtrlSurfaceCommands' incorporates:
     *  Outport: '<S1697>/CtrlSurfaceCommands'
     */
    UAM_Flight_control_B.OutportBufferForCtrlSurfaceC_i5 =
      UAM_Flight_control_P.CtrlSurfaceCommands_Y0;

    /* End of SystemInitialize for SubSystem: '<S9>/Scheduler' */

    /* SystemInitialize for Enabled SubSystem: '<S9>/multicopter Controller' */
    /* InitializeConditions for UnitDelay: '<S2119>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_DSTATE_d =
      UAM_Flight_control_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S2119>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_DSTATE_l =
      UAM_Flight_control_P.UnitDelay1_InitialCondition_p;

    /* InitializeConditions for DiscreteIntegrator: '<S2414>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_n =
      UAM_Flight_control_P.Yawratecontroller_InitialCond_c;

    /* InitializeConditions for DiscreteIntegrator: '<S2201>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_c5 =
      UAM_Flight_control_P.Pitchratecontroller_InitialCond;

    /* InitializeConditions for DiscreteIntegrator: '<S2206>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_jv =
      UAM_Flight_control_P.Pitchratecontroller_InitialCo_i;

    /* InitializeConditions for DiscreteIntegrator: '<S2305>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_nj =
      UAM_Flight_control_P.Rollratecontroller_InitialCondi;

    /* InitializeConditions for DiscreteIntegrator: '<S2310>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_m =
      UAM_Flight_control_P.Rollratecontroller_InitialCon_e;

    /* SystemInitialize for Enabled SubSystem: '<S1698>/Altitude Control1' */
    /* InitializeConditions for UnitDelay: '<S2107>/Delay Input1'
     *
     * Block description for '<S2107>/Delay Input1':
     *
     *  Store in Global RAM
     */
    UAM_Flight_control_DW.DelayInput1_DSTATE_b =
      UAM_Flight_control_P.DetectRisePositive_vinit;

    /* InitializeConditions for UnitDelay: '<S2108>/Delay Input1'
     *
     * Block description for '<S2108>/Delay Input1':
     *
     *  Store in Global RAM
     */
    UAM_Flight_control_DW.DelayInput1_DSTATE_f =
      UAM_Flight_control_P.DetectRisePositive1_vinit;

    /* InitializeConditions for UnitDelay: '<S1999>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_DSTATE_e =
      UAM_Flight_control_P.UnitDelay_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S2088>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_a2 =
      UAM_Flight_control_P.Altituderatecontroller_Initia_j;
    UAM_Flight_control_DW.Integrator_PrevResetState_f = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S2083>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_f =
      UAM_Flight_control_P.Altituderatecontroller_InitialC;
    UAM_Flight_control_DW.Filter_PrevResetState_m = 2;

    /* InitializeConditions for Product: '<S1989>/Divide' incorporates:
     *  UnitDelay: '<S1989>/Unit Delay'
     */
    UAM_Flight_control_DW.UnitDelay_DSTATE_g =
      UAM_Flight_control_P.UnitDelay_InitialCondition_k;

    /* SystemInitialize for MATLAB Function: '<S1989>/MATLAB Function' */
    UAM_F_MATLABFunction_k_Init(&UAM_Flight_control_DW.sf_MATLABFunction_mi);

    /* End of SystemInitialize for SubSystem: '<S1698>/Altitude Control1' */

    /* SystemInitialize for Enabled SubSystem: '<S1698>/Horizontal Position Control1' */
    /* InitializeConditions for RateLimiter: '<S1992>/Rate Limiter' */
    UAM_Flight_control_DW.PrevY = UAM_Flight_control_P.RateLimiter_IC;

    /* InitializeConditions for UnitDelay: '<S2663>/Delay Input1'
     *
     * Block description for '<S2663>/Delay Input1':
     *
     *  Store in Global RAM
     */
    UAM_Flight_control_DW.DelayInput1_DSTATE =
      UAM_Flight_control_P.DetectRisePositive_vinit_j;

    /* InitializeConditions for UnitDelay: '<S2664>/Delay Input1'
     *
     * Block description for '<S2664>/Delay Input1':
     *
     *  Store in Global RAM
     */
    UAM_Flight_control_DW.DelayInput1_DSTATE_e =
      UAM_Flight_control_P.DetectRisePositive1_vinit_g;

    /* InitializeConditions for UnitDelay: '<S2450>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_DSTATE_i =
      UAM_Flight_control_P.UnitDelay_InitialCondition_o;

    /* InitializeConditions for UnitDelay: '<S2450>/Unit Delay1' */
    UAM_Flight_control_DW.UnitDelay1_DSTATE_p =
      UAM_Flight_control_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for DiscreteIntegrator: '<S2645>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_f =
      UAM_Flight_control_P.Lateralvelocitycontroller_Ini_k;
    UAM_Flight_control_DW.Integrator_PrevResetState_i = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S2640>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_mr =
      UAM_Flight_control_P.Lateralvelocitycontroller_Initi;
    UAM_Flight_control_DW.Filter_PrevResetState_l = 2;

    /* InitializeConditions for RateLimiter: '<S1992>/Rate Limiter1' */
    UAM_Flight_control_DW.PrevY_i = UAM_Flight_control_P.RateLimiter1_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S2539>/Integrator' */
    UAM_Flight_control_DW.Integrator_DSTATE_j3 =
      UAM_Flight_control_P.Forwardvelocitycontroller_Ini_i;
    UAM_Flight_control_DW.Integrator_PrevResetState_pz = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S2534>/Filter' */
    UAM_Flight_control_DW.Filter_DSTATE_a4 =
      UAM_Flight_control_P.Forwardvelocitycontroller_Initi;
    UAM_Flight_control_DW.Filter_PrevResetState_c = 2;

    /* End of SystemInitialize for SubSystem: '<S1698>/Horizontal Position Control1' */

    /* SystemInitialize for Merge: '<S1698>/Merge2' */
    UAM_Flight_control_B.Merge2 = UAM_Flight_control_P.Merge2_InitialOutput;

    /* SystemInitialize for Merge: '<S1698>/Ref RP' */
    UAM_Flight_control_B.RefRP[0] = UAM_Flight_control_P.RefRP_InitialOutput;
    UAM_Flight_control_B.RefRP[1] = UAM_Flight_control_P.RefRP_InitialOutput;

    /* SystemInitialize for SignalConversion generated from: '<S1698>/MixerCommands' incorporates:
     *  Outport: '<S1698>/MixerCommands'
     */
    UAM_Flight_control_B.w_phi_d = UAM_Flight_control_P.MixerCommands_Y0.w_phi;

    /* SystemInitialize for SignalConversion generated from: '<S1698>/MixerCommands' incorporates:
     *  Outport: '<S1698>/MixerCommands'
     */
    UAM_Flight_control_B.w_theta_i =
      UAM_Flight_control_P.MixerCommands_Y0.w_theta;

    /* SystemInitialize for Gain: '<S1990>/Gain1' incorporates:
     *  Outport: '<S1698>/MixerCommands'
     *  SignalConversion generated from: '<S1698>/MixerCommands'
     */
    UAM_Flight_control_B.w_psi_f = UAM_Flight_control_P.MixerCommands_Y0.w_psi;

    /* SystemInitialize for SignalConversion generated from: '<S1698>/MixerCommands' incorporates:
     *  Outport: '<S1698>/MixerCommands'
     */
    UAM_Flight_control_B.w_z_c = UAM_Flight_control_P.MixerCommands_Y0.w_z;

    /* End of SystemInitialize for SubSystem: '<S9>/multicopter Controller' */
    /* End of SystemInitialize for SubSystem: '<S1>/Manual' */

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.roll = UAM_Flight_control_P.Merge_1_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.longitude =
      UAM_Flight_control_P.Merge_10_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.dist_n = UAM_Flight_control_P.Merge_11_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.dist_e = UAM_Flight_control_P.Merge_12_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.dist_d = UAM_Flight_control_P.Merge_13_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.gps_num_sv =
      UAM_Flight_control_P.Merge_14_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.roll_rate = UAM_Flight_control_P.Merge_15_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.pitch_rate =
      UAM_Flight_control_P.Merge_16_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.yaw_rate = UAM_Flight_control_P.Merge_17_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.acc_x = UAM_Flight_control_P.Merge_18_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.acc_y = UAM_Flight_control_P.Merge_19_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.pitch = UAM_Flight_control_P.Merge_2_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.acc_z = UAM_Flight_control_P.Merge_20_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.pressure = UAM_Flight_control_P.Merge_21_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.vel_n = UAM_Flight_control_P.Merge_22_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.vel_e = UAM_Flight_control_P.Merge_23_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.vel_d = UAM_Flight_control_P.Merge_24_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.gndspeed = UAM_Flight_control_P.Merge_25_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.target_x = UAM_Flight_control_P.Merge_26_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.target_y = UAM_Flight_control_P.Merge_27_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.target_z = UAM_Flight_control_P.Merge_28_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.gyro_x = UAM_Flight_control_P.Merge_29_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.yaw = UAM_Flight_control_P.Merge_3_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.gyro_y = UAM_Flight_control_P.Merge_30_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.gyro_z = UAM_Flight_control_P.Merge_31_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.mag_x = UAM_Flight_control_P.Merge_32_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.mag_y = UAM_Flight_control_P.Merge_33_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.mag_z = UAM_Flight_control_P.Merge_34_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.lin_acc_ecef_x =
      UAM_Flight_control_P.Merge_35_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.lin_acc_ecef_y =
      UAM_Flight_control_P.Merge_36_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.lin_acc_ecef_z =
      UAM_Flight_control_P.Merge_37_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.q[0] = UAM_Flight_control_P.Merge_38_InitialOutput;
    UAM_Flight_control_B.q[1] = UAM_Flight_control_P.Merge_38_InitialOutput;
    UAM_Flight_control_B.q[2] = UAM_Flight_control_P.Merge_38_InitialOutput;
    UAM_Flight_control_B.q[3] = UAM_Flight_control_P.Merge_38_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.airspeed = UAM_Flight_control_P.Merge_39_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.altitude = UAM_Flight_control_P.Merge_4_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.voltage = UAM_Flight_control_P.Merge_40_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.current = UAM_Flight_control_P.Merge_41_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.soc = UAM_Flight_control_P.Merge_42_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.temperature =
      UAM_Flight_control_P.Merge_43_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.soh = UAM_Flight_control_P.Merge_44_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.gcs_link = UAM_Flight_control_P.Merge_45_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.rc_link = UAM_Flight_control_P.Merge_46_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.flight_mode =
      UAM_Flight_control_P.Merge_47_InitialOutput;
    for (i = 0; i < 6; i++) {
      /* SystemInitialize for Merge generated from: '<S1>/Merge' */
      UAM_Flight_control_B.m[i] = UAM_Flight_control_P.Merge_48_InitialOutput;
    }

    for (i = 0; i < 16; i++) {
      /* SystemInitialize for Merge generated from: '<S1>/Merge' */
      UAM_Flight_control_B.rc[i] = UAM_Flight_control_P.Merge_49_InitialOutput;
    }

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.target_roll =
      UAM_Flight_control_P.Merge_5_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.CtrlSurfaceCommands =
      UAM_Flight_control_P.Merge_52_InitialOutput;

    /* SystemInitialize for Saturate: '<S1187>/Saturation' incorporates:
     *  Merge generated from: '<S1>/Merge'
     */
    UAM_Flight_control_B.a = UAM_Flight_control_P.Merge_53_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.target_pitch =
      UAM_Flight_control_P.Merge_6_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.target_yaw =
      UAM_Flight_control_P.Merge_7_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.target_alt =
      UAM_Flight_control_P.Merge_8_InitialOutput_e;

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.latitude = UAM_Flight_control_P.Merge_9_InitialOutput;

    /* SystemInitialize for IfAction SubSystem: '<S2>/Auto' */
    /* InitializeConditions for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_1_DSTATE_b =
      UAM_Flight_control_P.UnitDelay_1_InitialCondition_d;

    /* InitializeConditions for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_2_DSTATE_k =
      UAM_Flight_control_P.UnitDelay_2_InitialCondition_d;

    /* InitializeConditions for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_3_DSTATE_b =
      UAM_Flight_control_P.UnitDelay_3_InitialCondition_d;

    /* InitializeConditions for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_4_DSTATE_f =
      UAM_Flight_control_P.UnitDelay_4_InitialCondition_d;

    /* InitializeConditions for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_5_DSTATE_p =
      UAM_Flight_control_P.UnitDelay_5_InitialCondition_d;

    /* InitializeConditions for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_6_DSTATE_h =
      UAM_Flight_control_P.UnitDelay_6_InitialCondition_d;

    /* InitializeConditions for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_7_DSTATE_i =
      UAM_Flight_control_P.UnitDelay_7_InitialCondition_d;

    /* InitializeConditions for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_8_DSTATE_d =
      UAM_Flight_control_P.UnitDelay_8_InitialCondition_d;

    /* InitializeConditions for UnitDelay generated from: '<S2667>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_9_DSTATE_e =
      UAM_Flight_control_P.UnitDelay_9_InitialCondition_d;

    /* End of SystemInitialize for SubSystem: '<S2>/Auto' */

    /* SystemInitialize for Merge generated from: '<S1>/Merge' */
    UAM_Flight_control_B.rpy_sp[0] = UAM_Flight_control_P.Merge_50_InitialOutput;
    UAM_Flight_control_B.rpy_sp[1] = UAM_Flight_control_P.Merge_50_InitialOutput;
    UAM_Flight_control_B.rpy_sp[2] = UAM_Flight_control_P.Merge_50_InitialOutput;

    /* SystemInitialize for IfAction SubSystem: '<S2>/Auto' */
    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.FIXED_WING_WAYPOINT.WAYPOINT' */
    /* Start for MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_j.LastWaypointFlag = false;
    UAM_Flight_control_DW.obj_j.StartFlag = true;
    UAM_Flight_control_DW.obj_j.LookaheadFactor = 1.01;
    UAM_Flight_control_DW.obj_j.isInitialized = 1;
    UAM_Flight_control_DW.obj_j.NumWaypoints = 0.0;

    /* InitializeConditions for MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_j.WaypointIndex = 1.0;
    for (i = 0; i < 6; i++) {
      /* InitializeConditions for MATLABSystem: '<S2674>/Waypoint Follower' incorporates:
       *  Chart: '<S2667>/Guidance Mode Selector'
       */
      UAM_Flight_control_DW.obj_j.WaypointsInternal[i] = 0.0;
    }

    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.FIXED_WING_WAYPOINT.WAYPOINT' */

    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.FIXED_WING_ORBIT.ORBIT' */
    /* Start for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_jc.isInitialized = 1;

    /* InitializeConditions for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_jc.OrbitRadiusInternal = 0.0;
    UAM_Flight_control_DW.obj_jc.PrevResetSignal = 0.0;
    UAM_Flight_control_DW.obj_jc.NumCircles = 0.0;
    UAM_Flight_control_DW.obj_jc.StartFlag = true;
    UAM_Flight_control_DW.obj_jc.SelectTurnDirectionFlag = true;
    UAM_Flight_control_DW.obj_jc.TurnDirectionInternal = 1.0;
    UAM_Flight_control_DW.obj_jc.OrbitRadiusFlag = 0U;
    UAM_Flight_control_DW.obj_jc.LookaheadDistFlag = 0U;
    UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[0] = 0.0;
    UAM_Flight_control_DW.obj_jc.PrevPosition[0] = 0.0;

    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.FIXED_WING_ORBIT.ORBIT' */

    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.WP' */
    /* SystemInitialize for Triggered SubSystem: '<S2685>/Triggered Subsystem' */
    /* SystemInitialize for Reshape: '<S2688>/Reshape' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     *  Outport: '<S2688>/HoldPositionValue'
     */
    UAM_Flight_control_B.Reshape[0] = UAM_Flight_control_P.HoldPositionValue_Y0;

    /* End of SystemInitialize for SubSystem: '<S2685>/Triggered Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.WP' */

    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.FIXED_WING_ORBIT.ORBIT' */
    /* InitializeConditions for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[1] = 0.0;
    UAM_Flight_control_DW.obj_jc.PrevPosition[1] = 0.0;

    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.FIXED_WING_ORBIT.ORBIT' */

    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.WP' */
    /* SystemInitialize for Triggered SubSystem: '<S2685>/Triggered Subsystem' */
    /* SystemInitialize for Reshape: '<S2688>/Reshape' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     *  Outport: '<S2688>/HoldPositionValue'
     */
    UAM_Flight_control_B.Reshape[1] = UAM_Flight_control_P.HoldPositionValue_Y0;

    /* End of SystemInitialize for SubSystem: '<S2685>/Triggered Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.WP' */

    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.FIXED_WING_ORBIT.ORBIT' */
    /* InitializeConditions for MATLABSystem: '<S2673>/UAV Orbit Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_jc.OrbitCenterInternal[2] = 0.0;
    UAM_Flight_control_DW.obj_jc.PrevPosition[2] = 0.0;

    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.FIXED_WING_ORBIT.ORBIT' */

    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.WP' */
    /* SystemInitialize for Triggered SubSystem: '<S2685>/Triggered Subsystem' */
    /* SystemInitialize for Reshape: '<S2688>/Reshape' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     *  Outport: '<S2688>/HoldPositionValue'
     */
    UAM_Flight_control_B.Reshape[2] = UAM_Flight_control_P.HoldPositionValue_Y0;

    /* End of SystemInitialize for SubSystem: '<S2685>/Triggered Subsystem' */

    /* Start for MATLABSystem: '<S2680>/Waypoint Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_l.LastWaypointFlag = false;
    UAM_Flight_control_DW.obj_l.StartFlag = true;
    UAM_Flight_control_DW.obj_l.LookaheadFactor = 1.01;
    UAM_Flight_control_DW.obj_l.SearchFlag = true;
    UAM_Flight_control_DW.obj_l.isInitialized = 1;
    UAM_Flight_control_DW.obj_l.NumWaypoints = 0.0;

    /* InitializeConditions for MATLABSystem: '<S2680>/Waypoint Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_l.WaypointIndex = 1.0;
    memset(&UAM_Flight_control_DW.obj_l.WaypointsInternal[0], 0, sizeof(real_T) <<
           3U);

    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.WP' */

    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.Orbit' */
    /* Start for MATLABSystem: '<S2678>/UAV Orbit Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_cg.isInitialized = 1;

    /* InitializeConditions for MATLABSystem: '<S2678>/UAV Orbit Follower' incorporates:
     *  Chart: '<S2667>/Guidance Mode Selector'
     */
    UAM_Flight_control_DW.obj_cg.OrbitRadiusInternal = 0.0;
    UAM_Flight_control_DW.obj_cg.PrevResetSignal = 0.0;
    UAM_Flight_control_DW.obj_cg.NumCircles = 0.0;
    UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[0] = 0.0;
    UAM_Flight_control_DW.obj_cg.PrevPosition[0] = 0.0;
    UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[1] = 0.0;
    UAM_Flight_control_DW.obj_cg.PrevPosition[1] = 0.0;
    UAM_Flight_control_DW.obj_cg.OrbitCenterInternal[2] = 0.0;
    UAM_Flight_control_DW.obj_cg.PrevPosition[2] = 0.0;
    UAM_Flight_control_DW.obj_cg.StartFlag = true;
    UAM_Flight_control_DW.obj_cg.SelectTurnDirectionFlag = true;
    UAM_Flight_control_DW.obj_cg.TurnDirectionInternal = 1.0;
    UAM_Flight_control_DW.obj_cg.OrbitRadiusFlag = 0U;
    UAM_Flight_control_DW.obj_cg.LookaheadDistFlag = 0U;

    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.Orbit' */

    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.Land.Descend' */
    /* SystemInitialize for Chart: '<S2667>/Guidance Mode Selector' */
    UAM_F_WaypointFollower_Init(&UAM_Flight_control_DW.WaypointFollower_n);

    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.Land.Descend' */

    /* SystemInitialize for IfAction SubSystem: '<S2671>/GuidanceLogic.Land.ToLand' */
    UAM_F_WaypointFollower_Init(&UAM_Flight_control_DW.WaypointFollower_ni);

    /* End of SystemInitialize for SubSystem: '<S2671>/GuidanceLogic.Land.ToLand' */
    /* End of SystemInitialize for SubSystem: '<S2>/Auto' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/Emergency' */
    /* InitializeConditions for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_1_DSTATE =
      UAM_Flight_control_P.UnitDelay_1_InitialCondition_l;

    /* InitializeConditions for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_2_DSTATE_g =
      UAM_Flight_control_P.UnitDelay_2_InitialCondition_l;

    /* InitializeConditions for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_3_DSTATE_i =
      UAM_Flight_control_P.UnitDelay_3_InitialCondition_l;

    /* InitializeConditions for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_4_DSTATE =
      UAM_Flight_control_P.UnitDelay_4_InitialCondition_l;

    /* InitializeConditions for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_5_DSTATE =
      UAM_Flight_control_P.UnitDelay_5_InitialCondition_l;

    /* InitializeConditions for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_6_DSTATE =
      UAM_Flight_control_P.UnitDelay_6_InitialCondition_l;

    /* InitializeConditions for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_7_DSTATE =
      UAM_Flight_control_P.UnitDelay_7_InitialCondition_l;

    /* InitializeConditions for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_8_DSTATE =
      UAM_Flight_control_P.UnitDelay_8_InitialCondition_l;

    /* InitializeConditions for UnitDelay generated from: '<S2668>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_9_DSTATE =
      UAM_Flight_control_P.UnitDelay_9_InitialCondition_l;

    /* End of SystemInitialize for SubSystem: '<S2>/Emergency' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/Manual' */
    /* InitializeConditions for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_1_DSTATE_f =
      UAM_Flight_control_P.UnitDelay_1_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_2_DSTATE_gq =
      UAM_Flight_control_P.UnitDelay_2_InitialCondition_g;

    /* InitializeConditions for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_3_DSTATE_o =
      UAM_Flight_control_P.UnitDelay_3_InitialCondition_g;

    /* InitializeConditions for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_4_DSTATE_a =
      UAM_Flight_control_P.UnitDelay_4_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_5_DSTATE_h =
      UAM_Flight_control_P.UnitDelay_5_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_6_DSTATE_b =
      UAM_Flight_control_P.UnitDelay_6_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_7_DSTATE_b =
      UAM_Flight_control_P.UnitDelay_7_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_8_DSTATE_p =
      UAM_Flight_control_P.UnitDelay_8_InitialCondition;

    /* InitializeConditions for UnitDelay generated from: '<S2669>/Unit Delay' */
    UAM_Flight_control_DW.UnitDelay_9_DSTATE_h =
      UAM_Flight_control_P.UnitDelay_9_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S2>/Manual' */

    /* SystemInitialize for Merge generated from: '<S2>/Merge' */
    UAM_Flight_control_B.X = UAM_Flight_control_P.Merge_1_InitialOutput_g;

    /* SystemInitialize for Merge generated from: '<S2>/Merge' */
    UAM_Flight_control_B.Y = UAM_Flight_control_P.Merge_2_InitialOutput_g;

    /* SystemInitialize for Merge generated from: '<S2>/Merge' */
    UAM_Flight_control_B.Z = UAM_Flight_control_P.Merge_3_InitialOutput_g;

    /* SystemInitialize for Merge generated from: '<S2>/Merge' */
    UAM_Flight_control_B.Yaw = UAM_Flight_control_P.Merge_4_InitialOutput_g;

    /* SystemInitialize for Merge generated from: '<S2>/Merge' */
    UAM_Flight_control_B.FixedWingSP =
      UAM_Flight_control_P.Merge_5_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S2>/Merge' */
    UAM_Flight_control_B.AACSP = UAM_Flight_control_P.Merge_6_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S2>/Merge' */
    UAM_Flight_control_B.controlMode_h =
      UAM_Flight_control_P.Merge_7_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S2>/Merge' */
    UAM_Flight_control_B.FlightMode =
      UAM_Flight_control_P.Merge_8_InitialOutput_g;

    /* SystemInitialize for Merge generated from: '<S2>/Merge' */
    UAM_Flight_control_B.Status = UAM_Flight_control_P.Merge_9_InitialOutput_g;

    /* SystemInitialize for IfAction SubSystem: '<S2699>/Auto' */
    /* Start for InitialCondition: '<S2701>/IC' */
    UAM_Flight_control_DW.IC_FirstOutputTime = true;

    /* Start for MATLABSystem: '<S2708>/PathManagerSystemObject' */
    UAM_Flight_control_DW.obj_c.PoseRTLFlag = true;
    UAM_Flight_control_DW.obj_c.isInitialized = 1;
    UAM_Fligh_PathManager_setupImpl(&UAM_Flight_control_DW.obj_c);

    /* InitializeConditions for MATLABSystem: '<S2708>/PathManagerSystemObject' */
    UAM_Flight_control_DW.obj_c.MissionPointCounter = 1.0;
    UAM_Flight_control_DW.obj_c.MissionStart = true;
    UAM_Flight_control_DW.obj_c.PrevModeStatus = false;
    UAM_Flight_control_DW.obj_c.PoseHoldFlag = true;
    UAM_Flight_control_DW.obj_c.EnableRepeat = false;
    UAM_Flight_control_DW.obj_c.FinalMissionPoint = false;

    /* End of SystemInitialize for SubSystem: '<S2699>/Auto' */

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.mode_j = UAM_Flight_control_P.Merge_1_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.RotorParameters_g =
      UAM_Flight_control_P.Merge_10_InitialOutput;
    for (i = 0; i < 10; i++) {
      /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
      UAM_Flight_control_B.RC_a[i] = UAM_Flight_control_P.Merge_11_InitialOutput;
    }

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.target[0] = UAM_Flight_control_P.Merge_12_InitialOutput;
    UAM_Flight_control_B.target[1] = UAM_Flight_control_P.Merge_12_InitialOutput;
    UAM_Flight_control_B.target[2] = UAM_Flight_control_P.Merge_12_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.ground_o = UAM_Flight_control_P.Merge_13_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.ToWP_b = UAM_Flight_control_P.Merge_2_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.FromWP_k = UAM_Flight_control_P.Merge_3_InitialOutput;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.pose_h[0] =
      UAM_Flight_control_P.Merge_4_InitialOutput_l;
    UAM_Flight_control_B.pose_h[1] =
      UAM_Flight_control_P.Merge_4_InitialOutput_l;
    UAM_Flight_control_B.pose_h[2] =
      UAM_Flight_control_P.Merge_4_InitialOutput_l;
    UAM_Flight_control_B.pose_h[3] =
      UAM_Flight_control_P.Merge_4_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.course = UAM_Flight_control_P.Merge_9_InitialOutput_l;

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    UAM_Flight_control_DW.obj.AccelerometerNoise =
      UAM_Flight_control_P.AHRS_AccelerometerNoise;
    UAM_Flight_control_DW.obj.GyroscopeNoise =
      UAM_Flight_control_P.AHRS_GyroscopeNoise;
    UAM_Flight_control_DW.obj.MagnetometerNoise =
      UAM_Flight_control_P.AHRS_MagnetometerNoise;
    UAM_Flight_control_DW.obj.GyroscopeDriftNoise =
      UAM_Flight_control_P.AHRS_GyroscopeDriftNoise;
    UAM_Flight_control_DW.obj.LinearAccelerationNoise =
      UAM_Flight_control_P.AHRS_LinearAccelerationNoise;
    UAM_Flight_control_DW.obj.MagneticDisturbanceNoise =
      UAM_Flight_control_P.AHRS_MagneticDisturbanceNoise;
    UAM_Flight_control_DW.obj.LinearAccelerationDecayFactor =
      UAM_Flight_control_P.AHRS_LinearAccelerationDecayFac;
    UAM_Flight_control_DW.obj.MagneticDisturbanceDecayFactor =
      UAM_Flight_control_P.AHRS_MagneticDisturbanceDecayFa;
    UAM_Flight_control_DW.obj.ExpectedMagneticFieldStrength =
      UAM_Flight_control_P.AHRS_ExpectedMagneticFieldStren;
    UAM_Flight_control_DW.obj.isInitialized = 1;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.Euler[0] = UAM_Flight_control_P.Merge_5_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.pqr[0] = UAM_Flight_control_P.Merge_6_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.Ve[0] = UAM_Flight_control_P.Merge_7_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.Xe[0] = UAM_Flight_control_P.Merge_8_InitialOutput;

    /* SystemInitialize for MATLAB Function: '<S2710>/MATLAB Function' */
    UAM_Flight_control_DW.homeLLA[0] = (rtNaN);

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    UAM_Flight_control_DW.obj.pInputPrototype[0] = 0.0;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.Euler[1] = UAM_Flight_control_P.Merge_5_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.pqr[1] = UAM_Flight_control_P.Merge_6_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.Ve[1] = UAM_Flight_control_P.Merge_7_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.Xe[1] = UAM_Flight_control_P.Merge_8_InitialOutput;

    /* SystemInitialize for MATLAB Function: '<S2710>/MATLAB Function' */
    UAM_Flight_control_DW.homeLLA[1] = (rtNaN);

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    UAM_Flight_control_DW.obj.pInputPrototype[1] = 0.0;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.Euler[2] = UAM_Flight_control_P.Merge_5_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.pqr[2] = UAM_Flight_control_P.Merge_6_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.Ve[2] = UAM_Flight_control_P.Merge_7_InitialOutput_l;

    /* SystemInitialize for Merge generated from: '<S2699>/Merge' */
    UAM_Flight_control_B.Xe[2] = UAM_Flight_control_P.Merge_8_InitialOutput;

    /* SystemInitialize for MATLAB Function: '<S2710>/MATLAB Function' */
    UAM_Flight_control_DW.homeLLA[2] = (rtNaN);

    /* Start for MATLABSystem: '<S2700>/AHRS' */
    UAM_Flight_control_DW.obj.pInputPrototype[2] = 0.0;
    UAM_Flight_control_DW.obj.pSensorPeriod = 0.005;
    UAM_Flight_control_DW.obj.pKalmanPeriod = 0.005;
    UAM_Flight_control_DW.obj.TunablePropsChanged = false;

    /* InitializeConditions for MATLABSystem: '<S2700>/AHRS' */
    UAM_Fl_AHRSFilterBase_resetImpl(&UAM_Flight_control_DW.obj);
  }
}

/* Model terminate function */
void UAM_Flight_control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
