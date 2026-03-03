/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UAM_Flight_control_data.c
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

/* Block parameters (default storage) */
P_UAM_Flight_control_T UAM_Flight_control_P = {
  /* Variable: controlParams
   * Referenced by:
   *   '<S2081>/Derivative Gain'
   *   '<S2085>/Integral Gain'
   *   '<S2091>/Filter Coefficient'
   *   '<S2093>/Proportional Gain'
   *   '<S2159>/Proportional Gain'
   *   '<S2199>/Derivative Gain'
   *   '<S2203>/Integral Gain'
   *   '<S2209>/Filter Coefficient'
   *   '<S2211>/Proportional Gain'
   *   '<S2263>/Proportional Gain'
   *   '<S2303>/Derivative Gain'
   *   '<S2307>/Integral Gain'
   *   '<S2313>/Filter Coefficient'
   *   '<S2315>/Proportional Gain'
   *   '<S2367>/Proportional Gain'
   *   '<S2411>/Integral Gain'
   *   '<S2419>/Proportional Gain'
   *   '<S2490>/Proportional Gain'
   *   '<S2532>/Derivative Gain'
   *   '<S2536>/Integral Gain'
   *   '<S2542>/Filter Coefficient'
   *   '<S2544>/Proportional Gain'
   *   '<S2596>/Proportional Gain'
   *   '<S2638>/Derivative Gain'
   *   '<S2642>/Integral Gain'
   *   '<S2648>/Filter Coefficient'
   *   '<S2650>/Proportional Gain'
   *   '<S567>/Proportional Gain'
   *   '<S609>/Derivative Gain'
   *   '<S613>/Integral Gain'
   *   '<S619>/Filter Coefficient'
   *   '<S621>/Proportional Gain'
   *   '<S680>/Proportional Gain'
   *   '<S720>/Derivative Gain'
   *   '<S724>/Integral Gain'
   *   '<S730>/Filter Coefficient'
   *   '<S732>/Proportional Gain'
   *   '<S784>/Proportional Gain'
   *   '<S824>/Derivative Gain'
   *   '<S828>/Integral Gain'
   *   '<S834>/Filter Coefficient'
   *   '<S836>/Proportional Gain'
   *   '<S888>/Proportional Gain'
   *   '<S932>/Integral Gain'
   *   '<S940>/Proportional Gain'
   *   '<S1002>/Proportional Gain'
   *   '<S1044>/Derivative Gain'
   *   '<S1048>/Integral Gain'
   *   '<S1054>/Filter Coefficient'
   *   '<S1056>/Proportional Gain'
   *   '<S1108>/Proportional Gain'
   *   '<S1150>/Derivative Gain'
   *   '<S1154>/Integral Gain'
   *   '<S1160>/Filter Coefficient'
   *   '<S1162>/Proportional Gain'
   *   '<S1630>/Proportional Gain'
   *   '<S1670>/Derivative Gain'
   *   '<S1680>/Filter Coefficient'
   */
  {
    0.1,
    0.00302,
    100.0,
    0.1,
    0.00302,
    100.0,
    0.6,
    0.1,
    100.00000149011612,
    9.0,
    9.0,
    7.2,
    2.0,
    0.5,
    4.0,
    2.0,
    0.5,
    5.0,
    5.0,
    0.0,
    8.4215,
    1.0,
    1.0,
    1.0,
    0.1,
    9.0,
    0.0,
    0.0,
    100.0,
    9.0,
    0.0,
    0.0,
    100.0,
    7.2,
    0.0,
    0.0,
    100.0,
    0.1,
    0.1,
    0.00302,
    30.0,
    0.1,
    0.1,
    0.00302,
    30.0,
    0.6,
    0.06,
    0.0036,
    70.0,
    0.0,
    0.0,
    100.0,
    0.0,
    0.0,
    100.0,
    0.0,
    0.0,
    100.0,
    0.0,
    0.0,
    100.0,
    0.0,
    0.0,
    100.0,
    0.0,
    0.0,
    100.0,
    1.0,
    1.0,
    0.0,
    0.1,
    0.1,
    0.06
  },

  /* Variable: uavParam
   * Referenced by:
   *   '<S10>/Constant2'
   *   '<S1183>/Gain1'
   *   '<S1183>/Gain2'
   *   '<S1183>/Gain3'
   *   '<S1183>/Gain4'
   *   '<S1185>/Gain1'
   *   '<S1185>/Gain2'
   *   '<S1185>/Gain3'
   *   '<S1185>/Gain4'
   *   '<S1475>/Gain'
   *   '<S1475>/Gain1'
   *   '<S1475>/Gain2'
   *   '<S1475>/Gain3'
   *   '<S1475>/Gain4'
   *   '<S1476>/Gain1'
   *   '<S1476>/Gain2'
   *   '<S1476>/Gain3'
   *   '<S1476>/Gain5'
   */
  {
    {
      1.225,
      0.8186,
      4.0913,
      0.0,
      7.311,
      0.5079,
      -0.8529,
      0.0605,
      0.1328,
      0.4806,
      0.0,
      0.016,
      0.0921,
      0.0097,
      0.0076,
      -1.7697,
      -19.2266,
      -1.8375,
      -0.0016,
      -0.0016,
      0.1837,
      0.1289,
      -0.0016,
      -0.4758,
      0.2715,
      0.2866,
      0.0134,
      0.0918,
      -0.1327,
      -0.0883,
      0.0049,
      -0.067,
      0.027,
      9.806
    },

    {
      15.704,
      19.53,
      1.244,
      12.63,

      { 3.041, 2.591, 0.137 },

      { 3.041, -2.591, 0.137 },

      { -3.041, -2.591, 0.137 },

      { -3.041, 2.591, 0.137 },
      5970.6,
      11196.4,
      13814.0,
      2574.5,
      3.81,

      { -4.9378, 0.0, 0.3048 }
    },

    {
      10000.0,
      0.0
    }
  },

  /* Variable: control
   * Referenced by:
   *   '<S2673>/Constant'
   *   '<S2673>/Lookahead Distance'
   *   '<S2674>/Constant'
   *   '<S2674>/Lookahead Distance'
   *   '<S191>/Saturation'
   *   '<S191>/Saturation1'
   *   '<S1198>/Saturation'
   *   '<S1198>/Saturation1'
   *   '<S1706>/Saturation'
   *   '<S1706>/Saturation1'
   *   '<S125>/Saturation'
   *   '<S178>/Saturation'
   *   '<S345>/Saturation'
   *   '<S1351>/Saturation'
   *   '<S1859>/Saturation'
   */
  {
    60.0,
    60.0,
    60.0,
    0.0,
    1.0,
    1.0,
    5.0,
    0.17453292519943295,
    -0.17453292519943295,
    0.69813170079773179,
    -0.69813170079773179,
    1.2217304763960306,
    -1.2217304763960306,
    1.2217304763960306,
    -1.2217304763960306,
    3.0,
    -3.0,
    9.5,
    55.0,
    12.35,
    5.0,
    10.0,
    13.0,
    12.35,
    0.034906585039886591,
    2.0,
    1.0,
    15.0
  },

  /* Variable: FWControlParams
   * Referenced by:
   *   '<S58>/Derivative Gain'
   *   '<S62>/Integral Gain'
   *   '<S68>/Filter Coefficient'
   *   '<S70>/Proportional Gain'
   *   '<S491>/Derivative Gain'
   *   '<S495>/Integral Gain'
   *   '<S501>/Filter Coefficient'
   *   '<S503>/Proportional Gain'
   *   '<S123>/Proportional Gain'
   *   '<S176>/Proportional Gain'
   *   '<S227>/Derivative Gain'
   *   '<S231>/Integral Gain'
   *   '<S237>/Filter Coefficient'
   *   '<S239>/Proportional Gain'
   *   '<S343>/Proportional Gain'
   *   '<S395>/Proportional Gain'
   *   '<S1233>/Derivative Gain'
   *   '<S1237>/Integral Gain'
   *   '<S1243>/Filter Coefficient'
   *   '<S1245>/Proportional Gain'
   *   '<S1297>/Proportional Gain'
   *   '<S1349>/Proportional Gain'
   *   '<S1401>/Proportional Gain'
   *   '<S1741>/Derivative Gain'
   *   '<S1745>/Integral Gain'
   *   '<S1751>/Filter Coefficient'
   *   '<S1753>/Proportional Gain'
   *   '<S1805>/Proportional Gain'
   *   '<S1857>/Proportional Gain'
   *   '<S1909>/Proportional Gain'
   */
  {
    0.1,
    0.4,
    10.0,
    0.0,
    0.0,
    100.0,
    2.0,
    10.0,
    0.0,
    0.0,
    2.1893,
    0.4,
    0.8,
    0.15,
    0.01
  },

  /* Variable: Cruise_a
   * Referenced by:
   *   '<S16>/Constant5'
   *   '<S1477>/Constant5'
   *   '<S1479>/Constant5'
   */
  1.0,

  /* Variable: FWTrimSpeed
   * Referenced by:
   *   '<S10>/Constant3'
   *   '<S10>/Constant4'
   *   '<S1184>/Constant1'
   *   '<S1477>/Constant4'
   *   '<S1478>/Constant1'
   */
  261.8,

  /* Variable: Vt
   * Referenced by:
   *   '<S2667>/Guidance Mode Selector'
   *   '<S2668>/Basic Control  Switching'
   *   '<S2669>/Basic Control  Switching'
   */
  10.0,

  /* Variable: w_trim
   * Referenced by:
   *   '<S1183>/Gain1'
   *   '<S1183>/Gain2'
   *   '<S1183>/Gain3'
   *   '<S1183>/Gain4'
   *   '<S1185>/Gain1'
   *   '<S1185>/Gain2'
   *   '<S1185>/Gain3'
   *   '<S1185>/Gain4'
   *   '<S1476>/Gain1'
   *   '<S1476>/Gain2'
   *   '<S1476>/Gain3'
   *   '<S1476>/Gain5'
   *   '<S1477>/Constant'
   *   '<S1477>/Constant1'
   *   '<S1477>/Constant2'
   *   '<S1477>/Constant3'
   *   '<S1479>/Constant'
   *   '<S1479>/Constant1'
   *   '<S1479>/Constant2'
   *   '<S1479>/Constant3'
   */
  104.7,

  /* Variable: zGround
   * Referenced by: '<S2667>/Guidance Mode Selector'
   */
  0.0,

  /* Variable: FSState
   * Referenced by:
   *   '<S2667>/Constant2'
   *   '<S2668>/Hover'
   *   '<S2669>/Hover'
   */
  Hover,

  /* Mask Parameter: PitchAngleController_InitialCon
   * Referenced by: '<S1743>/Filter'
   */
  0.0,

  /* Mask Parameter: Altituderatecontroller_InitialC
   * Referenced by: '<S2083>/Filter'
   */
  0.0,

  /* Mask Parameter: Lateralvelocitycontroller_Initi
   * Referenced by: '<S2640>/Filter'
   */
  0.0,

  /* Mask Parameter: Forwardvelocitycontroller_Initi
   * Referenced by: '<S2534>/Filter'
   */
  0.0,

  /* Mask Parameter: Pitchratecontroller_InitialCond
   * Referenced by: '<S2201>/Filter'
   */
  0.0,

  /* Mask Parameter: Rollratecontroller_InitialCondi
   * Referenced by: '<S2305>/Filter'
   */
  0.0,

  /* Mask Parameter: AirspeedController_InitialCondi
   * Referenced by: '<S60>/Filter'
   */
  0.0,

  /* Mask Parameter: PitchAngleController_InitialC_p
   * Referenced by: '<S229>/Filter'
   */
  0.0,

  /* Mask Parameter: AirspeedController_InitialCon_a
   * Referenced by: '<S493>/Filter'
   */
  0.0,

  /* Mask Parameter: Altituderatecontroller1_Initial
   * Referenced by: '<S611>/Filter'
   */
  0.0,

  /* Mask Parameter: Forwardvelocitycontroller_Ini_a
   * Referenced by: '<S1046>/Filter'
   */
  0.0,

  /* Mask Parameter: Lateralvelocitycontroller_Ini_p
   * Referenced by: '<S1152>/Filter'
   */
  0.0,

  /* Mask Parameter: PitchRateController_InitialCond
   * Referenced by: '<S722>/Filter'
   */
  0.0,

  /* Mask Parameter: RollRateController_InitialCondi
   * Referenced by: '<S826>/Filter'
   */
  0.0,

  /* Mask Parameter: PitchAngleController_Initial_pa
   * Referenced by: '<S1235>/Filter'
   */
  0.0,

  /* Mask Parameter: Yawratecontroller_InitialCondit
   * Referenced by: '<S1672>/Filter'
   */
  0.0,

  /* Mask Parameter: PitchAngleController_InitialC_d
   * Referenced by: '<S1748>/Integrator'
   */
  0.0,

  /* Mask Parameter: Altituderatecontroller_Initia_j
   * Referenced by: '<S2088>/Integrator'
   */
  0.0,

  /* Mask Parameter: Lateralvelocitycontroller_Ini_k
   * Referenced by: '<S2645>/Integrator'
   */
  0.0,

  /* Mask Parameter: Forwardvelocitycontroller_Ini_i
   * Referenced by: '<S2539>/Integrator'
   */
  0.0,

  /* Mask Parameter: Yawratecontroller_InitialCond_c
   * Referenced by: '<S2414>/Integrator'
   */
  0.0,

  /* Mask Parameter: Pitchratecontroller_InitialCo_i
   * Referenced by: '<S2206>/Integrator'
   */
  0.0,

  /* Mask Parameter: Rollratecontroller_InitialCon_e
   * Referenced by: '<S2310>/Integrator'
   */
  0.0,

  /* Mask Parameter: AirspeedController_InitialCon_l
   * Referenced by: '<S65>/Integrator'
   */
  0.0,

  /* Mask Parameter: PitchAngleController_InitialC_c
   * Referenced by: '<S234>/Integrator'
   */
  0.0,

  /* Mask Parameter: AirspeedController_InitialCon_f
   * Referenced by: '<S498>/Integrator'
   */
  0.0,

  /* Mask Parameter: Altituderatecontroller1_Initi_k
   * Referenced by: '<S616>/Integrator'
   */
  0.0,

  /* Mask Parameter: Forwardvelocitycontroller_Ini_o
   * Referenced by: '<S1051>/Integrator'
   */
  0.0,

  /* Mask Parameter: Lateralvelocitycontroller_Ini_m
   * Referenced by: '<S1157>/Integrator'
   */
  0.0,

  /* Mask Parameter: Yawratecontroller_InitialCond_a
   * Referenced by: '<S935>/Integrator'
   */
  0.0,

  /* Mask Parameter: PitchRateController_InitialCo_m
   * Referenced by: '<S727>/Integrator'
   */
  0.0,

  /* Mask Parameter: RollRateController_InitialCon_j
   * Referenced by: '<S831>/Integrator'
   */
  0.0,

  /* Mask Parameter: PitchAngleController_InitialC_f
   * Referenced by: '<S1240>/Integrator'
   */
  0.0,

  /* Mask Parameter: Altituderatecontroller_LowerInt
   * Referenced by: '<S2088>/Integrator'
   */
  -1.5,

  /* Mask Parameter: Lateralvelocitycontroller_Lower
   * Referenced by: '<S2645>/Integrator'
   */
  -2.0,

  /* Mask Parameter: Forwardvelocitycontroller_Lower
   * Referenced by: '<S2539>/Integrator'
   */
  -2.0,

  /* Mask Parameter: Yawratecontroller_LowerIntegrat
   * Referenced by: '<S2414>/Integrator'
   */
  -0.3,

  /* Mask Parameter: Pitchratecontroller_LowerIntegr
   * Referenced by: '<S2206>/Integrator'
   */
  -0.3,

  /* Mask Parameter: Rollratecontroller_LowerIntegra
   * Referenced by: '<S2310>/Integrator'
   */
  -0.3,

  /* Mask Parameter: Altituderatecontroller1_LowerIn
   * Referenced by: '<S616>/Integrator'
   */
  -1.5,

  /* Mask Parameter: Forwardvelocitycontroller_Low_e
   * Referenced by: '<S1051>/Integrator'
   */
  -2.0,

  /* Mask Parameter: Lateralvelocitycontroller_Low_c
   * Referenced by: '<S1157>/Integrator'
   */
  -2.0,

  /* Mask Parameter: Yawratecontroller_LowerIntegr_o
   * Referenced by: '<S935>/Integrator'
   */
  -0.3,

  /* Mask Parameter: PitchRateController_LowerIntegr
   * Referenced by: '<S727>/Integrator'
   */
  -0.3,

  /* Mask Parameter: RollRateController_LowerIntegra
   * Referenced by: '<S831>/Integrator'
   */
  -0.3,

  /* Mask Parameter: PitchAngleController_LowerSatur
   * Referenced by:
   *   '<S1755>/Saturation'
   *   '<S1740>/DeadZone'
   */
  -INFINITY,

  /* Mask Parameter: PitchRateController_LowerSatura
   * Referenced by: '<S1807>/Saturation'
   */
  -INFINITY,

  /* Mask Parameter: RudderController_LowerSaturatio
   * Referenced by: '<S1965>/Saturation'
   */
  -1.0,

  /* Mask Parameter: RollRateController_LowerSaturat
   * Referenced by: '<S1911>/Saturation'
   */
  -1.0,

  /* Mask Parameter: Altituderatecontroller_LowerSat
   * Referenced by:
   *   '<S2095>/Saturation'
   *   '<S2080>/DeadZone'
   */
  -INFINITY,

  /* Mask Parameter: Lateralpositioncontroller_Lower
   * Referenced by: '<S2598>/Saturation'
   */
  -5.0,

  /* Mask Parameter: Lateralvelocitycontroller_Low_p
   * Referenced by:
   *   '<S2652>/Saturation'
   *   '<S2637>/DeadZone'
   */
  -5.0,

  /* Mask Parameter: Forwardvelocitycontroller_Low_p
   * Referenced by:
   *   '<S2546>/Saturation'
   *   '<S2531>/DeadZone'
   */
  -5.0,

  /* Mask Parameter: RollRateController_LowerSatur_c
   * Referenced by: '<S397>/Saturation'
   */
  -1.0,

  /* Mask Parameter: PitchAngleController_LowerSat_a
   * Referenced by:
   *   '<S241>/Saturation'
   *   '<S226>/DeadZone'
   */
  -INFINITY,

  /* Mask Parameter: PitchRateController_LowerSatu_k
   * Referenced by: '<S293>/Saturation'
   */
  -INFINITY,

  /* Mask Parameter: RudderController_LowerSaturat_e
   * Referenced by: '<S451>/Saturation'
   */
  -1.0,

  /* Mask Parameter: Altitudecontroller_LowerSaturat
   * Referenced by: '<S569>/Saturation'
   */
  -5.0,

  /* Mask Parameter: Altituderatecontroller1_LowerSa
   * Referenced by:
   *   '<S623>/Saturation'
   *   '<S608>/DeadZone'
   */
  -INFINITY,

  /* Mask Parameter: Forwardpositioncontroller_Lower
   * Referenced by: '<S1004>/Saturation'
   */
  -1.5,

  /* Mask Parameter: Lateralpositioncontroller_Low_j
   * Referenced by: '<S1110>/Saturation'
   */
  -1.5,

  /* Mask Parameter: Forwardvelocitycontroller_Lo_ei
   * Referenced by:
   *   '<S1058>/Saturation'
   *   '<S1043>/DeadZone'
   */
  -5.0,

  /* Mask Parameter: Lateralvelocitycontroller_Low_o
   * Referenced by:
   *   '<S1164>/Saturation'
   *   '<S1149>/DeadZone'
   */
  -5.0,

  /* Mask Parameter: Yawratecontroller_LowerSaturati
   * Referenced by: '<S942>/Saturation'
   */
  -0.25,

  /* Mask Parameter: PitchController_LowerSaturation
   * Referenced by: '<S682>/Saturation'
   */
  -3.839724354387525,

  /* Mask Parameter: PitchRateController_LowerSatu_h
   * Referenced by: '<S734>/Saturation'
   */
  -0.35,

  /* Mask Parameter: RollController_LowerSaturationL
   * Referenced by: '<S786>/Saturation'
   */
  -3.839724354387525,

  /* Mask Parameter: RollRateController_LowerSatur_o
   * Referenced by: '<S838>/Saturation'
   */
  -0.35,

  /* Mask Parameter: PitchAngleController_LowerSat_e
   * Referenced by:
   *   '<S1247>/Saturation'
   *   '<S1232>/DeadZone'
   */
  -INFINITY,

  /* Mask Parameter: PitchRateController_LowerSatu_o
   * Referenced by: '<S1299>/Saturation'
   */
  -INFINITY,

  /* Mask Parameter: RudderController_LowerSaturat_f
   * Referenced by: '<S1457>/Saturation'
   */
  -1.0,

  /* Mask Parameter: RollRateController_LowerSatur_g
   * Referenced by: '<S1403>/Saturation'
   */
  -1.0,

  /* Mask Parameter: RudderController_P
   * Referenced by: '<S1963>/Proportional Gain'
   */
  0.01,

  /* Mask Parameter: Altitudecontroller_P
   * Referenced by: '<S2039>/Proportional Gain'
   */
  1.0,

  /* Mask Parameter: PitchRateController_P
   * Referenced by: '<S291>/Proportional Gain'
   */
  0.7,

  /* Mask Parameter: RudderController_P_a
   * Referenced by: '<S449>/Proportional Gain'
   */
  0.01,

  /* Mask Parameter: RudderController_P_f
   * Referenced by: '<S1455>/Proportional Gain'
   */
  0.01,

  /* Mask Parameter: PitchController_P
   * Referenced by: '<S1526>/Proportional Gain'
   */
  2.0,

  /* Mask Parameter: RollController_P
   * Referenced by: '<S1578>/Proportional Gain'
   */
  2.0,

  /* Mask Parameter: Yawratecontroller_P
   * Referenced by: '<S1682>/Proportional Gain'
   */
  2.0,

  /* Mask Parameter: Altituderatecontroller_UpperInt
   * Referenced by: '<S2088>/Integrator'
   */
  2.0,

  /* Mask Parameter: Lateralvelocitycontroller_Upper
   * Referenced by: '<S2645>/Integrator'
   */
  2.0,

  /* Mask Parameter: Forwardvelocitycontroller_Upper
   * Referenced by: '<S2539>/Integrator'
   */
  2.0,

  /* Mask Parameter: Yawratecontroller_UpperIntegrat
   * Referenced by: '<S2414>/Integrator'
   */
  0.3,

  /* Mask Parameter: Pitchratecontroller_UpperIntegr
   * Referenced by: '<S2206>/Integrator'
   */
  0.3,

  /* Mask Parameter: Rollratecontroller_UpperIntegra
   * Referenced by: '<S2310>/Integrator'
   */
  0.3,

  /* Mask Parameter: Altituderatecontroller1_UpperIn
   * Referenced by: '<S616>/Integrator'
   */
  2.0,

  /* Mask Parameter: Forwardvelocitycontroller_Upp_k
   * Referenced by: '<S1051>/Integrator'
   */
  2.0,

  /* Mask Parameter: Lateralvelocitycontroller_Upp_g
   * Referenced by: '<S1157>/Integrator'
   */
  2.0,

  /* Mask Parameter: Yawratecontroller_UpperIntegr_o
   * Referenced by: '<S935>/Integrator'
   */
  0.3,

  /* Mask Parameter: PitchRateController_UpperIntegr
   * Referenced by: '<S727>/Integrator'
   */
  0.3,

  /* Mask Parameter: RollRateController_UpperIntegra
   * Referenced by: '<S831>/Integrator'
   */
  0.3,

  /* Mask Parameter: PitchAngleController_UpperSatur
   * Referenced by:
   *   '<S1755>/Saturation'
   *   '<S1740>/DeadZone'
   */
  INFINITY,

  /* Mask Parameter: PitchRateController_UpperSatura
   * Referenced by: '<S1807>/Saturation'
   */
  INFINITY,

  /* Mask Parameter: RudderController_UpperSaturatio
   * Referenced by: '<S1965>/Saturation'
   */
  1.0,

  /* Mask Parameter: RollRateController_UpperSaturat
   * Referenced by: '<S1911>/Saturation'
   */
  1.0,

  /* Mask Parameter: Altituderatecontroller_UpperSat
   * Referenced by:
   *   '<S2095>/Saturation'
   *   '<S2080>/DeadZone'
   */
  INFINITY,

  /* Mask Parameter: Lateralpositioncontroller_Upper
   * Referenced by: '<S2598>/Saturation'
   */
  5.0,

  /* Mask Parameter: Lateralvelocitycontroller_Upp_b
   * Referenced by:
   *   '<S2652>/Saturation'
   *   '<S2637>/DeadZone'
   */
  5.0,

  /* Mask Parameter: Forwardvelocitycontroller_Upp_o
   * Referenced by:
   *   '<S2546>/Saturation'
   *   '<S2531>/DeadZone'
   */
  5.0,

  /* Mask Parameter: RollRateController_UpperSatur_c
   * Referenced by: '<S397>/Saturation'
   */
  1.0,

  /* Mask Parameter: PitchAngleController_UpperSat_j
   * Referenced by:
   *   '<S241>/Saturation'
   *   '<S226>/DeadZone'
   */
  INFINITY,

  /* Mask Parameter: PitchRateController_UpperSatu_p
   * Referenced by: '<S293>/Saturation'
   */
  INFINITY,

  /* Mask Parameter: RudderController_UpperSaturat_g
   * Referenced by: '<S451>/Saturation'
   */
  1.0,

  /* Mask Parameter: Altitudecontroller_UpperSaturat
   * Referenced by: '<S569>/Saturation'
   */
  5.0,

  /* Mask Parameter: Altituderatecontroller1_UpperSa
   * Referenced by:
   *   '<S623>/Saturation'
   *   '<S608>/DeadZone'
   */
  INFINITY,

  /* Mask Parameter: Forwardpositioncontroller_Upper
   * Referenced by: '<S1004>/Saturation'
   */
  1.5,

  /* Mask Parameter: Lateralpositioncontroller_Upp_a
   * Referenced by: '<S1110>/Saturation'
   */
  1.5,

  /* Mask Parameter: Forwardvelocitycontroller_Upp_h
   * Referenced by:
   *   '<S1058>/Saturation'
   *   '<S1043>/DeadZone'
   */
  5.0,

  /* Mask Parameter: Lateralvelocitycontroller_Upp_f
   * Referenced by:
   *   '<S1164>/Saturation'
   *   '<S1149>/DeadZone'
   */
  5.0,

  /* Mask Parameter: Yawratecontroller_UpperSaturati
   * Referenced by: '<S942>/Saturation'
   */
  0.25,

  /* Mask Parameter: PitchController_UpperSaturation
   * Referenced by: '<S682>/Saturation'
   */
  3.839724354387525,

  /* Mask Parameter: PitchRateController_UpperSatu_h
   * Referenced by: '<S734>/Saturation'
   */
  0.35,

  /* Mask Parameter: RollController_UpperSaturationL
   * Referenced by: '<S786>/Saturation'
   */
  3.839724354387525,

  /* Mask Parameter: RollRateController_UpperSatu_c0
   * Referenced by: '<S838>/Saturation'
   */
  0.35,

  /* Mask Parameter: PitchAngleController_UpperSat_c
   * Referenced by:
   *   '<S1247>/Saturation'
   *   '<S1232>/DeadZone'
   */
  INFINITY,

  /* Mask Parameter: PitchRateController_UpperSatu_l
   * Referenced by: '<S1299>/Saturation'
   */
  INFINITY,

  /* Mask Parameter: RudderController_UpperSaturat_i
   * Referenced by: '<S1457>/Saturation'
   */
  1.0,

  /* Mask Parameter: RollRateController_UpperSatur_l
   * Referenced by: '<S1403>/Saturation'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S2106>/Constant'
   */
  0.05,

  /* Mask Parameter: CompareToConstant_const_i
   * Referenced by: '<S2438>/Constant'
   */
  0.05,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S2439>/Constant'
   */
  0.05,

  /* Mask Parameter: deadzone_const
   * Referenced by: '<S2434>/Constant'
   */
  0.05,

  /* Mask Parameter: disarm_const
   * Referenced by: '<S2435>/Constant'
   */
  0.0,

  /* Mask Parameter: arm_const
   * Referenced by: '<S2433>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_k
   * Referenced by: '<S522>/Constant'
   */
  1700.0,

  /* Mask Parameter: CompareToConstant1_const_f
   * Referenced by: '<S2707>/Constant'
   */
  3.0,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S2697>/Constant'
   */
  1300.0,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S2696>/Constant'
   */
  1700.0,

  /* Mask Parameter: CompareToConstant_const_d
   * Referenced by: '<S2712>/Constant'
   */
  1700.0,

  /* Mask Parameter: CompareToConstant1_const_i
   * Referenced by: '<S2713>/Constant'
   */
  1.5,

  /* Mask Parameter: DetectRisePositive_vinit
   * Referenced by: '<S2107>/Delay Input1'
   */
  false,

  /* Mask Parameter: DetectRisePositive1_vinit
   * Referenced by: '<S2108>/Delay Input1'
   */
  false,

  /* Mask Parameter: DetectRisePositive_vinit_j
   * Referenced by: '<S2663>/Delay Input1'
   */
  false,

  /* Mask Parameter: DetectRisePositive1_vinit_g
   * Referenced by: '<S2664>/Delay Input1'
   */
  false,

  /* Mask Parameter: CompareToConstant_const_a
   * Referenced by: '<S1705>/Constant'
   */
  1U,

  /* Mask Parameter: prev_is_1_const
   * Referenced by: '<S2437>/Constant'
   */
  1U,

  /* Mask Parameter: now_is_0_const
   * Referenced by: '<S2436>/Constant'
   */
  0U,

  /* Mask Parameter: CompareToConstant_const_p
   * Referenced by: '<S28>/Constant'
   */
  1U,

  /* Mask Parameter: CompareToConstant1_const_c
   * Referenced by: '<S29>/Constant'
   */
  2U,

  /* Mask Parameter: CompareToConstant_const_m
   * Referenced by: '<S189>/Constant'
   */
  1U,

  /* Mask Parameter: CompareToConstant1_const_k
   * Referenced by: '<S190>/Constant'
   */
  2U,

  /* Mask Parameter: CompareToConstant_const_e
   * Referenced by: '<S1197>/Constant'
   */
  1U,

  /* Mask Parameter: CompareToConstant_const_ko
   * Referenced by: '<S2670>/Constant'
   */
  2U,

  /* Mask Parameter: CompareToConstant_const_c
   * Referenced by: '<S2706>/Constant'
   */
  1U,

  /* Computed Parameter: UnitDelay_3_InitialCondition
   * Referenced by: '<S2>/Unit Delay'
   */
  {
    0U,                                /* mode */

    {
      0.0, 0.0, 0.0 }
    ,                                  /* position */

    {
      0.0, 0.0, 0.0, 0.0 }
    /* params */
  },

  /* Computed Parameter: UnitDelay_2_InitialCondition
   * Referenced by: '<S2>/Unit Delay'
   */
  {
    0U,                                /* mode */

    {
      0.0, 0.0, 0.0 }
    ,                                  /* position */

    {
      0.0, 0.0, 0.0, 0.0 }
    /* params */
  },

  /* Expression: TransitionMission
   * Referenced by: '<S2698>/Waypoints2'
   */
  { {
      2U,

      { 0.0, 0.1, -0.7 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.1, -0.7 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.1, -0.7 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.1, -0.7 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.1, -0.7 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.1, -0.7 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.1, -0.7 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.1, -0.7 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.1, -0.7 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 4U,
      { 0.0, 0.1, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    } },

  /* Computed Parameter: Merge_2_InitialOutput
   * Referenced by: '<S2699>/Merge'
   */
  {
    0U,                                /* mode */

    {
      0.0, 0.0, 0.0 }
    ,                                  /* position */

    {
      0.0, 0.0, 0.0, 0.0 }
    /* params */
  },

  /* Computed Parameter: Merge_3_InitialOutput
   * Referenced by: '<S2699>/Merge'
   */
  {
    0U,                                /* mode */

    {
      0.0, 0.0, 0.0 }
    ,                                  /* position */

    {
      0.0, 0.0, 0.0, 0.0 }
    /* params */
  },

  /* Computed Parameter: UnitDelay_6_InitialCondition
   * Referenced by: '<S2669>/Unit Delay'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Expression: struct('airspeed', 0.0, 'altitude', 0.0, 'course', 0.0, 'L1', 0.0, 'climbrate', 0.0)

   * Referenced by: '<S2669>/Constant2'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Computed Parameter: UnitDelay_6_InitialCondition_d
   * Referenced by: '<S2667>/Unit Delay'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Computed Parameter: UnitDelay_6_InitialCondition_l
   * Referenced by: '<S2668>/Unit Delay'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Expression: struct('airspeed', 0.0, 'altitude', 0.0, 'course', 0.0, 'L1', 0.0, 'climbrate', 0.0)

   * Referenced by: '<S2668>/Constant2'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Computed Parameter: Merge_6_InitialOutput
   * Referenced by: '<S2>/Merge'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Computed Parameter: UnitDelay1_7_InitialCondition
   * Referenced by: '<S2>/Unit Delay1'
   */
  {
    0.0,                               /* w1 */
    0.0,                               /* w2 */
    0.0,                               /* w3 */
    0.0,                               /* w4 */
    0.0                                /* c1 */
  },

  /* Computed Parameter: Merge_10_InitialOutput
   * Referenced by: '<S2699>/Merge'
   */
  {
    0.0,                               /* w1 */
    0.0,                               /* w2 */
    0.0,                               /* w3 */
    0.0,                               /* w4 */
    0.0                                /* c1 */
  },

  /* Computed Parameter: MixerCommands_Y0
   * Referenced by: '<S1698>/MixerCommands'
   */
  {
    0.0,                               /* w_phi */
    0.0,                               /* w_theta */
    0.0,                               /* w_psi */
    0.0,                               /* w_z */
    0.0                                /* l_x */
  },

  /* Computed Parameter: MixerCommands_Y0_o
   * Referenced by: '<S13>/MixerCommands'
   */
  {
    0.0,                               /* w_phi */
    0.0,                               /* w_theta */
    0.0,                               /* w_psi */
    0.0,                               /* w_z */
    0.0                                /* l_x */
  },

  /* Computed Parameter: MixerCommands_Y0_e
   * Referenced by: '<S1190>/MixerCommands'
   */
  {
    0.0,                               /* w_phi */
    0.0,                               /* w_theta */
    0.0,                               /* w_psi */
    0.0,                               /* w_z */
    0.0                                /* l_x */
  },

  /* Computed Parameter: Actuator_Outport_1_Y0
   * Referenced by:
   */
  {
    0.0,                               /* w1 */
    0.0,                               /* w2 */
    0.0,                               /* w3 */
    0.0,                               /* w4 */
    0.0                                /* c1 */
  },

  /* Computed Parameter: Actuator_Outport_1_Y0_d
   * Referenced by:
   */
  {
    0.0,                               /* w1 */
    0.0,                               /* w2 */
    0.0,                               /* w3 */
    0.0,                               /* w4 */
    0.0                                /* c1 */
  },

  /* Computed Parameter: Actuator_Outport_1_Y0_d1
   * Referenced by:
   */
  {
    0.0,                               /* w1 */
    0.0,                               /* w2 */
    0.0,                               /* w3 */
    0.0,                               /* w4 */
    0.0                                /* c1 */
  },

  /* Computed Parameter: Actuator_Outport_1_Y0_d1t
   * Referenced by:
   */
  {
    0.0,                               /* w1 */
    0.0,                               /* w2 */
    0.0,                               /* w3 */
    0.0,                               /* w4 */
    0.0                                /* c1 */
  },

  /* Computed Parameter: UnitDelay_5_InitialCondition
   * Referenced by: '<S2669>/Unit Delay'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Expression: struct('roll', 0.0, 'pitch', 0.0, 'yaw', 0.0, 'airspeed', 0.0)

   * Referenced by: '<S2669>/Constant1'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Computed Parameter: UnitDelay_5_InitialCondition_d
   * Referenced by: '<S2667>/Unit Delay'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Computed Parameter: UnitDelay_5_InitialCondition_l
   * Referenced by: '<S2668>/Unit Delay'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Expression: struct('roll', 0.0, 'pitch', 0.0, 'yaw', 0.0, 'airspeed', 0.0)

   * Referenced by: '<S2668>/Constant1'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Computed Parameter: Merge_5_InitialOutput
   * Referenced by: '<S2>/Merge'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Computed Parameter: CtrlSurfaceCommands_Y0
   * Referenced by: '<S1697>/CtrlSurfaceCommands'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S1977>/Merge'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: CtrlSurfaceCommands_Y0_h
   * Referenced by: '<S14>/CtrlSurfaceCommands'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Merge_InitialOutput_m
   * Referenced by: '<S1175>/Merge'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: CtrlSurfaceCommands_Y0_k
   * Referenced by: '<S1189>/CtrlSurfaceCommands'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Merge_InitialOutput_g
   * Referenced by: '<S1469>/Merge'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Merge_52_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Actuator_Y0
   * Referenced by: '<S1696>/Actuator'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Actuator_Y0_a
   * Referenced by: '<S1188>/Actuator'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: UnitDelay_7_InitialCondition
   * Referenced by: '<S2669>/Unit Delay'
   */
  {
    0U,                                /* lateralGuidance */
    0U,                                /* airspeedAltitude */
    0U,                                /* attitude */
    0U,                                /* manual */
    0U,                                /* armed */
    0U,                                /* inTransition */
    0U,                                /* TransitionCondition */
    0U,                                /* TransitionStep */
    0U,                                /* BackTransitionCondition */
    0.0                                /* land */
  },

  /* Computed Parameter: UnitDelay_7_InitialCondition_d
   * Referenced by: '<S2667>/Unit Delay'
   */
  {
    0U,                                /* lateralGuidance */
    0U,                                /* airspeedAltitude */
    0U,                                /* attitude */
    0U,                                /* manual */
    0U,                                /* armed */
    0U,                                /* inTransition */
    0U,                                /* TransitionCondition */
    0U,                                /* TransitionStep */
    0U,                                /* BackTransitionCondition */
    0.0                                /* land */
  },

  /* Computed Parameter: UnitDelay_7_InitialCondition_l
   * Referenced by: '<S2668>/Unit Delay'
   */
  {
    0U,                                /* lateralGuidance */
    0U,                                /* airspeedAltitude */
    0U,                                /* attitude */
    0U,                                /* manual */
    0U,                                /* armed */
    0U,                                /* inTransition */
    0U,                                /* TransitionCondition */
    0U,                                /* TransitionStep */
    0U,                                /* BackTransitionCondition */
    0.0                                /* land */
  },

  /* Computed Parameter: Merge_7_InitialOutput
   * Referenced by: '<S2>/Merge'
   */
  {
    0U,                                /* lateralGuidance */
    0U,                                /* airspeedAltitude */
    0U,                                /* attitude */
    0U,                                /* manual */
    0U,                                /* armed */
    0U,                                /* inTransition */
    0U,                                /* TransitionCondition */
    0U,                                /* TransitionStep */
    0U,                                /* BackTransitionCondition */
    0.0                                /* land */
  },

  /* Computed Parameter: AER_Y0
   * Referenced by: '<S1706>/AER'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1738>/Constant1'
   */
  0.0,

  /* Expression: [1  1;
     1 -1]

   * Referenced by: '<S1706>/Constant'
   */
  { 1.0, 1.0, 1.0, -1.0 },

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S1748>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S1743>/Filter'
   */
  0.005,

  /* Expression: 0.3
   * Referenced by: '<S1706>/Saturation2'
   */
  0.3,

  /* Expression: -0.3
   * Referenced by: '<S1706>/Saturation2'
   */
  -0.3,

  /* Expression: 0
   * Referenced by: '<S1738>/Clamping_zero'
   */
  0.0,

  /* Expression: -1000
   * Referenced by: '<S1703>/Bias'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1703>/Gain'
   */
  0.001,

  /* Expression: pi/6
   * Referenced by: '<S1703>/Gain1'
   */
  0.52359877559829882,

  /* Expression: -1000
   * Referenced by: '<S1704>/Bias'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1704>/Gain'
   */
  0.001,

  /* Expression: pi/9
   * Referenced by: '<S1704>/Gain1'
   */
  0.3490658503988659,

  /* Expression: [1 -1 -1 1; 1 1 1 1; 1 1 -1 -1; 1 -1 1 -1]
   * Referenced by: '<S1984>/Constant'
   */
  { 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, 1.0,
    -1.0, -1.0 },

  /* Expression: 0
   * Referenced by: '<S1984>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1697>/MotorActuatorCommands'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Gain1'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Constant2'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Gain3'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Constant4'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Gain5'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Constant6'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Gain7'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Constant8'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S1983>/Constant'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1983>/Saturation'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Saturation'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1983>/Saturation1'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Saturation1'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1983>/Saturation2'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Saturation2'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1983>/Saturation3'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Saturation3'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1983>/Saturation4'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1983>/Saturation4'
   */
  1000.0,

  /* Expression: 3 / 0.9
   * Referenced by: '<S1999>/throttle_up'
   */
  3.333333333333333,

  /* Expression: 1 / 0.9
   * Referenced by: '<S1999>/throttle_down'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S1999>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2078>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1989>/Gain'
   */
  -1.0,

  /* Expression: -0.5
   * Referenced by: '<S1999>/Bias'
   */
  -0.5,

  /* Expression: 2
   * Referenced by: '<S1999>/Gain3'
   */
  2.0,

  /* Expression: -0.1
   * Referenced by: '<S1999>/Dead Zone'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S1999>/Dead Zone'
   */
  0.1,

  /* Expression: 0.6
   * Referenced by: '<S1999>/Constant'
   */
  0.6,

  /* Expression: 0
   * Referenced by: '<S1999>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1989>/Gain1'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_n
   * Referenced by: '<S2088>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_e
   * Referenced by: '<S2083>/Filter'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S1989>/Unit Delay'
   */
  0.0,

  /* Expression: 1/9.81
   * Referenced by: '<S1989>/hover_thrust//g'
   */
  0.1019367991845056,

  /* Expression: 0.9
   * Referenced by: '<S1989>/Saturation1'
   */
  0.9,

  /* Expression: 0.15
   * Referenced by: '<S1989>/Saturation1'
   */
  0.15,

  /* Expression: 0
   * Referenced by: '<S2078>/Clamping_zero'
   */
  0.0,

  /* Expression: 120*pi/180
   * Referenced by: '<S2119>/yaw_max_rate'
   */
  2.0943951023931953,

  /* Expression: 10
   * Referenced by: '<S1992>/Foward Velocity Setpoint'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1992>/Foward Velocity Setpoint'
   */
  -10.0,

  /* Expression: 10
   * Referenced by: '<S1992>/Vel_manual'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<S1992>/Lateral Velocity Setpoint'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S1992>/Lateral Velocity Setpoint'
   */
  -10.0,

  /* Expression: 10
   * Referenced by: '<S1992>/Vel_manual(m//s)'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S2529>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2635>/Constant1'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S1992>/Dead Zone'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S1992>/Dead Zone'
   */
  0.1,

  /* Expression: 0.6
   * Referenced by: '<S1992>/Constant'
   */
  0.6,

  /* Expression: -0.1
   * Referenced by: '<S1992>/Dead Zone1'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S1992>/Dead Zone1'
   */
  0.1,

  /* Expression: 0.6
   * Referenced by: '<S1992>/Constant1'
   */
  0.6,

  /* Expression: 1
   * Referenced by: '<S1992>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S1992>/Rate Limiter'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1992>/Rate Limiter'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1992>/Rate Limiter'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2450>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2444>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S2450>/Unit Delay1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2446>/Gain'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_d
   * Referenced by: '<S2645>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_i
   * Referenced by: '<S2640>/Filter'
   */
  0.005,

  /* Expression: 1/9.81
   * Referenced by: '<S1992>/rad'
   */
  0.1019367991845056,

  /* Expression: 0.51
   * Referenced by: '<S1992>/Saturation1'
   */
  0.51,

  /* Expression: -0.51
   * Referenced by: '<S1992>/Saturation1'
   */
  -0.51,

  /* Expression: 0
   * Referenced by: '<S2635>/Clamping_zero'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1992>/Rate Limiter1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1992>/Rate Limiter1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1992>/Rate Limiter1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_i
   * Referenced by: '<S2539>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_j
   * Referenced by: '<S2534>/Filter'
   */
  0.005,

  /* Expression: 1/9.81
   * Referenced by: '<S1992>/Gain'
   */
  0.1019367991845056,

  /* Expression: 0.51
   * Referenced by: '<S1992>/Saturation'
   */
  0.51,

  /* Expression: -0.51
   * Referenced by: '<S1992>/Saturation'
   */
  -0.51,

  /* Expression: 0
   * Referenced by: '<S2529>/Clamping_zero'
   */
  0.0,

  /* Expression: -1000
   * Referenced by: '<S1994>/Bias1'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1994>/Gain1'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<S1994>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1994>/Saturation'
   */
  0.0,

  /* Expression: -1500
   * Referenced by: '<S1994>/Bias'
   */
  -1500.0,

  /* Expression: 1/500
   * Referenced by: '<S1994>/Gain'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S2119>/Unit Delay1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_du
   * Referenced by: '<S2414>/Integrator'
   */
  0.005,

  /* Expression: 0.4
   * Referenced by: '<S1990>/Gain1'
   */
  0.4,

  /* Computed Parameter: RefRP_InitialOutput
   * Referenced by: '<S1698>/Ref RP'
   */
  0.0,

  /* Expression: 35*pi/180
   * Referenced by: '<S1990>/Pitch_MAX_angle'
   */
  0.6108652381980153,

  /* Expression: 0.61087
   * Referenced by: '<S1990>/Saturation1'
   */
  0.61087,

  /* Expression: -0.61087
   * Referenced by: '<S1990>/Saturation1'
   */
  -0.61087,

  /* Computed Parameter: Filter_gainval_p
   * Referenced by: '<S2201>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_m
   * Referenced by: '<S2206>/Integrator'
   */
  0.005,

  /* Expression: 35*pi/180
   * Referenced by: '<S1990>/Roll_MAX_angle'
   */
  0.6108652381980153,

  /* Expression: 0.61087
   * Referenced by: '<S1990>/Saturation'
   */
  0.61087,

  /* Expression: -0.61087
   * Referenced by: '<S1990>/Saturation'
   */
  -0.61087,

  /* Computed Parameter: Filter_gainval_c
   * Referenced by: '<S2305>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_o
   * Referenced by: '<S2310>/Integrator'
   */
  0.005,

  /* Expression: 1
   * Referenced by: '<S1990>/Saturation5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1990>/Saturation5'
   */
  -1.0,

  /* Computed Parameter: Merge2_InitialOutput
   * Referenced by: '<S1698>/Merge2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1695>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1695>/Saturation'
   */
  0.0,

  /* Expression: 78.54
   * Referenced by: '<S10>/Constant6'
   */
  78.54,

  /* Expression: 1
   * Referenced by: '<S10>/Constant5'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Gain3'
   */
  0.0,

  /* Expression: 35
   * Referenced by: '<S16>/Constant3'
   */
  35.0,

  /* Expression: 10
   * Referenced by: '<S16>/Saturation1'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S16>/Saturation1'
   */
  0.0,

  /* Expression: 1/10
   * Referenced by: '<S16>/Gain3'
   */
  0.1,

  /* Expression: 65
   * Referenced by: '<S15>/Constant'
   */
  65.0,

  /* Expression: 1/20
   * Referenced by: '<S15>/Gain'
   */
  0.05,

  /* Expression: 1
   * Referenced by: '<S15>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S15>/Saturation'
   */
  0.0,

  /* Computed Parameter: ClimbRateSPMerge_InitialOutput
   * Referenced by: '<S19>/Climb Rate SP Merge'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S30>/Gain'
   */
  0.5,

  /* Computed Parameter: Filter_gainval_l
   * Referenced by: '<S60>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_j
   * Referenced by: '<S65>/Integrator'
   */
  0.0025,

  /* Expression: 0
   * Referenced by: '<S224>/Constant1'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S191>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0.3
   * Referenced by: '<S191>/Saturation2'
   */
  0.3,

  /* Expression: -0.3
   * Referenced by: '<S191>/Saturation2'
   */
  -0.3,

  /* Expression: pi/180
   * Referenced by: '<S191>/Gain2'
   */
  0.017453292519943295,

  /* Computed Parameter: Integrator_gainval_k
   * Referenced by: '<S234>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_o
   * Referenced by: '<S229>/Filter'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S224>/Clamping_zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S192>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S192>/Constant1'
   */
  0.0,

  /* Computed Parameter: Filter_gainval_g
   * Referenced by: '<S493>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S498>/Integrator'
   */
  0.0025,

  /* Expression: 0
   * Referenced by: '<S22>/IC'
   */
  0.0,

  /* Computed Parameter: ActuatordTMerge_InitialOutput
   * Referenced by: '<S17>/Actuator dT Merge'
   */
  0.0,

  /* Computed Parameter: PitchSPMerge_InitialOutput
   * Referenced by: '<S17>/Pitch SP Merge'
   */
  0.0,

  /* Computed Parameter: RollSPMerge_InitialOutput
   * Referenced by: '<S17>/Roll SP Merge'
   */
  0.0,

  /* Computed Parameter: Merge_InitialOutput_d
   * Referenced by: '<S17>/Merge'
   */
  0.0,

  /* Computed Parameter: Reference_Y0
   * Referenced by: '<S527>/Reference'
   */
  0.0,

  /* Computed Parameter: commandedthrust_Y0
   * Referenced by: '<S521>/commanded thrust'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S606>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S521>/Gain'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S521>/Gain1'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S616>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_gk
   * Referenced by: '<S611>/Filter'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S521>/Unit Delay'
   */
  0.0,

  /* Expression: 1/9.81
   * Referenced by: '<S521>/hover_thrust//g'
   */
  0.1019367991845056,

  /* Expression: 0.9
   * Referenced by: '<S521>/Saturation1'
   */
  0.9,

  /* Expression: 0.15
   * Referenced by: '<S521>/Saturation1'
   */
  0.15,

  /* Expression: 0
   * Referenced by: '<S606>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: Forwardcmd_Y0
   * Referenced by: '<S953>/Forward cmd'
   */
  0.0,

  /* Computed Parameter: SidewardCmd_Y0
   * Referenced by: '<S953>/Sideward Cmd'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1041>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1147>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S958>/Gain'
   */
  -1.0,

  /* Expression: 0.01
   * Referenced by: '<S962>/Value'
   */
  0.01,

  /* Expression: 3
   * Referenced by: '<S962>/MPC_ACC_HOR'
   */
  3.0,

  /* Expression: 4
   * Referenced by: '<S962>/Gain'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S962>/MPC_JERK_AUTO'
   */
  4.0,

  /* Expression: -2
   * Referenced by: '<S962>/Gain1'
   */
  -2.0,

  /* Expression: 4
   * Referenced by: '<S962>/Gain2'
   */
  4.0,

  /* Expression: 0.5
   * Referenced by: '<S962>/Gain3'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S962>/value'
   */
  1.0,

  /* Expression: 1.5
   * Referenced by: '<S953>/Saturation3'
   */
  1.5,

  /* Expression: -1.5
   * Referenced by: '<S953>/Saturation3'
   */
  -1.5,

  /* Computed Parameter: Integrator_gainval_nm
   * Referenced by: '<S1051>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_er
   * Referenced by: '<S1046>/Filter'
   */
  0.005,

  /* Expression: 1/9.81
   * Referenced by: '<S953>/Gain'
   */
  0.1019367991845056,

  /* Expression: 0.51
   * Referenced by: '<S953>/Saturation'
   */
  0.51,

  /* Expression: -0.51
   * Referenced by: '<S953>/Saturation'
   */
  -0.51,

  /* Expression: 0
   * Referenced by: '<S1041>/Clamping_zero'
   */
  0.0,

  /* Expression: 1.5
   * Referenced by: '<S953>/Saturation2'
   */
  1.5,

  /* Expression: -1.5
   * Referenced by: '<S953>/Saturation2'
   */
  -1.5,

  /* Expression: -1
   * Referenced by: '<S960>/Gain'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_e
   * Referenced by: '<S1157>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_gl
   * Referenced by: '<S1152>/Filter'
   */
  0.005,

  /* Expression: 1/9.81
   * Referenced by: '<S953>/rad'
   */
  0.1019367991845056,

  /* Expression: 0.51
   * Referenced by: '<S953>/Saturation1'
   */
  0.51,

  /* Expression: -0.51
   * Referenced by: '<S953>/Saturation1'
   */
  -0.51,

  /* Expression: 0
   * Referenced by: '<S1147>/Clamping_zero'
   */
  0.0,

  /* Expression: 0.75
   * Referenced by: '<S518>/Saturation'
   */
  0.75,

  /* Expression: -0.75
   * Referenced by: '<S518>/Saturation'
   */
  -0.75,

  /* Expression: 1
   * Referenced by: '<S518>/Saturation1'
   */
  1.0,

  /* Expression: -0.75
   * Referenced by: '<S518>/Saturation1'
   */
  -0.75,

  /* Expression: 0
   * Referenced by: '<S520>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S520>/Constant1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_a
   * Referenced by: '<S935>/Integrator'
   */
  0.005,

  /* Expression: 0.4
   * Referenced by: '<S523>/Gain1'
   */
  0.4,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S13>/Merge1'
   */
  0.0,

  /* Expression: 35*pi/180
   * Referenced by: '<S523>/Pitch_MAX_angle1'
   */
  0.6108652381980153,

  /* Expression: 0.61087
   * Referenced by: '<S523>/Saturation1'
   */
  0.61087,

  /* Expression: -0.61087
   * Referenced by: '<S523>/Saturation1'
   */
  -0.61087,

  /* Computed Parameter: Filter_gainval_jc
   * Referenced by: '<S722>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_on
   * Referenced by: '<S727>/Integrator'
   */
  0.005,

  /* Computed Parameter: Merge_InitialOutput_gy
   * Referenced by: '<S13>/Merge'
   */
  0.0,

  /* Expression: 35*pi/180
   * Referenced by: '<S523>/Roll_MAX_angle'
   */
  0.6108652381980153,

  /* Expression: 0.61087
   * Referenced by: '<S523>/Saturation'
   */
  0.61087,

  /* Expression: -0.61087
   * Referenced by: '<S523>/Saturation'
   */
  -0.61087,

  /* Computed Parameter: Filter_gainval_lj
   * Referenced by: '<S826>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_j5
   * Referenced by: '<S831>/Integrator'
   */
  0.005,

  /* Expression: 1
   * Referenced by: '<S523>/Saturation5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S523>/Saturation5'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1178>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1178>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1178>/Constant5'
   */
  0.0,

  /* Expression: [1 -1 -1 1; 1 1 1 1; 1 1 -1 -1; 1 -1 1 -1]
   * Referenced by: '<S1182>/Constant'
   */
  { 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, 1.0,
    -1.0, -1.0 },

  /* Expression: 0
   * Referenced by: '<S1182>/Constant4'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1183>/Saturation4'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1183>/Saturation4'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1183>/Saturation1'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1183>/Saturation1'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1183>/Saturation2'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1183>/Saturation2'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1183>/Saturation3'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1183>/Saturation3'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1185>/Saturation4'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1185>/Saturation4'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1185>/Saturation1'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1185>/Saturation1'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1185>/Saturation2'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1185>/Saturation2'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1185>/Saturation3'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1185>/Saturation3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/MotorActuatorCommands'
   */
  0.0,

  /* Computed Parameter: Merge_1_InitialOutput
   * Referenced by: '<S1176>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Gain1'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Constant2'
   */
  1000.0,

  /* Computed Parameter: Merge_2_InitialOutput_i
   * Referenced by: '<S1176>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Gain3'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Constant4'
   */
  1000.0,

  /* Computed Parameter: Merge_4_InitialOutput
   * Referenced by: '<S1176>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Gain5'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Constant6'
   */
  1000.0,

  /* Computed Parameter: Merge_3_InitialOutput_i
   * Referenced by: '<S1176>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Gain7'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Constant8'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S1181>/Constant'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1181>/Saturation'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Saturation'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1181>/Saturation1'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Saturation1'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1181>/Saturation2'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Saturation2'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1181>/Saturation3'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Saturation3'
   */
  1000.0,

  /* Computed Parameter: Merge_5_InitialOutput_i
   * Referenced by: '<S1176>/Merge'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1181>/Saturation4'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1181>/Saturation4'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S12>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Constant3'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant7'
   */
  1.0,

  /* Computed Parameter: AER_Y0_e
   * Referenced by: '<S1198>/AER'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1230>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1230>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_ap
   * Referenced by: '<S1240>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_d
   * Referenced by: '<S1235>/Filter'
   */
  0.005,

  /* Expression: 0.3
   * Referenced by: '<S1198>/Saturation2'
   */
  0.3,

  /* Expression: -0.3
   * Referenced by: '<S1198>/Saturation2'
   */
  -0.3,

  /* Expression: -1000
   * Referenced by: '<S1195>/Bias'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1195>/Gain'
   */
  0.001,

  /* Expression: pi/6
   * Referenced by: '<S1195>/Gain1'
   */
  0.52359877559829882,

  /* Expression: -1000
   * Referenced by: '<S1196>/Bias'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1196>/Gain'
   */
  0.001,

  /* Expression: pi/9
   * Referenced by: '<S1196>/Gain1'
   */
  0.3490658503988659,

  /* Expression: 1
   * Referenced by: '<S1476>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1476>/Saturation'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1476>/Saturation4'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1476>/Saturation4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1476>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1476>/Saturation1'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1476>/Saturation5'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1476>/Saturation5'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1476>/Saturation2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1476>/Saturation2'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1476>/Saturation6'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1476>/Saturation6'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1476>/Saturation3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1476>/Saturation3'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1476>/Saturation7'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1476>/Saturation7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1476>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1477>/Constant9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1477>/Constant10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1477>/Constant11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1477>/Constant8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1479>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1189>/MotorActuatorCommands'
   */
  0.0,

  /* Computed Parameter: Merge_1_InitialOutput_f
   * Referenced by: '<S1470>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Gain5'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Bias'
   */
  1000.0,

  /* Computed Parameter: Merge_2_InitialOutput_f
   * Referenced by: '<S1470>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Gain6'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Bias1'
   */
  1000.0,

  /* Computed Parameter: Merge_3_InitialOutput_f
   * Referenced by: '<S1470>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Gain7'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Bias2'
   */
  1000.0,

  /* Computed Parameter: Merge_4_InitialOutput_f
   * Referenced by: '<S1470>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Gain8'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Bias3'
   */
  1000.0,

  /* Computed Parameter: Merge_5_InitialOutput_f
   * Referenced by: '<S1470>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Gain9'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Bias4'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S1475>/Constant'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1475>/Saturation'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Saturation'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1475>/Saturation1'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Saturation1'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1475>/Saturation2'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Saturation2'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1475>/Saturation3'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Saturation3'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1475>/Saturation4'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1475>/Saturation4'
   */
  1000.0,

  /* Expression: -1500
   * Referenced by: '<S1482>/Bias'
   */
  -1500.0,

  /* Expression: 1/500
   * Referenced by: '<S1482>/Gain'
   */
  0.002,

  /* Computed Parameter: Filter_gainval_h
   * Referenced by: '<S1672>/Filter'
   */
  0.005,

  /* Expression: -1500
   * Referenced by: '<S1480>/Bias'
   */
  -1500.0,

  /* Expression: 1/500
   * Referenced by: '<S1480>/Gain'
   */
  0.002,

  /* Expression: 1
   * Referenced by: '<S1187>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1187>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2669>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2669>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2669>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2669>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2672>/Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2672>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2672>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2672>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2673>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2674>/Constant1'
   */
  0.0,

  /* Expression: [0 0 0]
   * Referenced by: '<S2675>/Constant3'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S2675>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2675>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2675>/Constant'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S2676>/Constant'
   */
  3.0,

  /* Expression: pi
   * Referenced by: '<S2676>/Hdg Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2676>/Hdg Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<S2676>/Yaw Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2676>/Yaw Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: 10
   * Referenced by: '<S2677>/Lookahead Distance'
   */
  10.0,

  /* Expression: 5
   * Referenced by: '<S2678>/Lookahead Distance'
   */
  5.0,

  /* Expression: pi
   * Referenced by: '<S2679>/Hdg. Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2679>/Hdg. Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S2679>/Constant1'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<S2679>/Yaw Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2679>/Yaw Cmd Sat'
   */
  -3.1415926535897931,

  /* Computed Parameter: HoldPositionValue_Y0
   * Referenced by: '<S2688>/HoldPositionValue'
   */
  0.0,

  /* Expression: 6
   * Referenced by: '<S2685>/Constant'
   */
  6.0,

  /* Expression: 1
   * Referenced by: '<S2680>/Lookahead Distance'
   */
  1.0,

  /* Expression: pi
   * Referenced by: '<S2680>/Yaw Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2680>/Yaw Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: inf
   * Referenced by: '<S2689>/Saturation'
   */
  INFINITY,

  /* Expression: 0.00001
   * Referenced by: '<S2689>/Saturation'
   */
  1.0E-5,

  /* Expression: 2
   * Referenced by: '<S2680>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S2667>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2667>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2667>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2667>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2668>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2668>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2668>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2668>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2668>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2668>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2668>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2668>/Constant6'
   */
  0.0,

  /* Expression: [0;0;0;0]
   * Referenced by: '<S2701>/Constant3'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [0,0,0]
   * Referenced by: '<S2701>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0.0001924722
   * Referenced by: '<S2700>/AHRS'
   */
  0.0001924722,

  /* Expression: 9.1385e-5
   * Referenced by: '<S2700>/AHRS'
   */
  9.1385E-5,

  /* Expression: 0.1
   * Referenced by: '<S2700>/AHRS'
   */
  0.1,

  /* Expression: 3.0462e-13
   * Referenced by: '<S2700>/AHRS'
   */
  3.0462E-13,

  /* Expression: 0.0096236100000000012
   * Referenced by: '<S2700>/AHRS'
   */
  0.0096236100000000012,

  /* Expression: 0.5
   * Referenced by: '<S2700>/AHRS'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S2700>/AHRS'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S2700>/AHRS'
   */
  0.5,

  /* Expression: 50
   * Referenced by: '<S2700>/AHRS'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant5'
   */
  0.0,

  /* Expression: [  0 0 0]
   * Referenced by: '<S2700>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S6>/Constant'
   */
  1.0,

  /* Expression: pi/180
   * Referenced by: '<S2709>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S2693>/Constant'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S2714>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay4'
   */
  0.0,

  /* Expression: 0.005
   * Referenced by: '<S6>/Ts'
   */
  0.005,

  /* Expression: 0.00001
   * Referenced by: '<S6>/Constant1'
   */
  1.0E-5,

  /* Expression: 0.0001
   * Referenced by: '<S6>/Constant2'
   */
  0.0001,

  /* Expression: 1
   * Referenced by: '<S6>/Constant4'
   */
  1.0,

  /* Expression: 6.25
   * Referenced by: '<S6>/R_baro'
   */
  6.25,

  /* Expression: 0.625
   * Referenced by: '<S6>/R_vgps'
   */
  0.625,

  /* Expression: 0.625
   * Referenced by: '<S6>/Rgps'
   */
  0.625,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay5'
   */
  0.0,

  /* Expression: 0.03
   * Referenced by: '<S6>/Gain2'
   */
  0.03,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay'
   */
  0.0,

  /* Expression: 0.005
   * Referenced by: '<S6>/dt1'
   */
  0.005,

  /* Expression: [1;0;0;0]
   * Referenced by: '<S2721>/Unit Delay'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Expression: [-0.000114; -0.000246; -0.001536]
   * Referenced by: '<S2721>/Gyro_bias'
   */
  { -0.000114, -0.000246, -0.001536 },

  /* Expression: 0.5
   * Referenced by: '<S2721>/Gain2'
   */
  0.5,

  /* Expression: 0.005
   * Referenced by: '<S2721>/dt'
   */
  0.005,

  /* Expression: [0;0;0]
   * Referenced by: '<S6>/bias'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 9.80665
   * Referenced by: '<S6>/g'
   */
  9.80665,

  /* Expression: 0.0000125
   * Referenced by: '<S6>/0.5*dt^2'
   */
  1.25E-5,

  /* Expression: 0.005
   * Referenced by: '<S6>/dt'
   */
  0.005,

  /* Expression: 1
   * Referenced by: '<S2700>/Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay1'
   */
  0.0,

  /* Computed Parameter: Merge_1_InitialOutput_g
   * Referenced by: '<S2>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_2_InitialOutput_g
   * Referenced by: '<S2>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_3_InitialOutput_g
   * Referenced by: '<S2>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_4_InitialOutput_g
   * Referenced by: '<S2>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_1_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_2_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_3_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_4_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_9_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_10_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_18_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_19_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_20_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_21_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_22_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_23_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_24_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_25_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_29_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_30_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_31_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_32_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_33_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_34_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_35_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_36_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_37_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_38_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_39_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_48_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_49_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_50_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_51_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_53_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2699>/ground'
   */
  0.0,

  /* Computed Parameter: Merge_11_InitialOutput
   * Referenced by: '<S2699>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_12_InitialOutput
   * Referenced by: '<S2699>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_13_InitialOutput
   * Referenced by: '<S2699>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_4_InitialOutput_l
   * Referenced by: '<S2699>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_5_InitialOutput_l
   * Referenced by: '<S2699>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_6_InitialOutput_l
   * Referenced by: '<S2699>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_7_InitialOutput_l
   * Referenced by: '<S2699>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_8_InitialOutput
   * Referenced by: '<S2699>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_9_InitialOutput_l
   * Referenced by: '<S2699>/Merge'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant7'
   */
  1.0,

  /* Expression: pi/180
   * Referenced by: '<S2722>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S2722>/Gain'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S2722>/Constant1'
   */
  0.0,

  /* Expression: flightState.Transition
   * Referenced by: '<S1695>/Constant'
   */
  Transition,

  /* Expression: flightState.BackTransition
   * Referenced by: '<S1695>/Constant1'
   */
  BackTransition,

  /* Expression: flightState.FixedWing
   * Referenced by: '<S521>/Constant4'
   */
  FixedWing,

  /* Expression: flightState.Transition
   * Referenced by: '<S10>/Constant'
   */
  Transition,

  /* Expression: flightState.Transition
   * Referenced by: '<S1187>/Constant'
   */
  Transition,

  /* Expression: flightState.BackTransition
   * Referenced by: '<S1187>/Constant1'
   */
  BackTransition,

  /* Computed Parameter: UnitDelay_8_InitialCondition
   * Referenced by: '<S2669>/Unit Delay'
   */
  Hover,

  /* Computed Parameter: UnitDelay_8_InitialCondition_d
   * Referenced by: '<S2667>/Unit Delay'
   */
  Hover,

  /* Computed Parameter: UnitDelay_8_InitialCondition_l
   * Referenced by: '<S2668>/Unit Delay'
   */
  Hover,

  /* Computed Parameter: Merge_8_InitialOutput_g
   * Referenced by: '<S2>/Merge'
   */
  Hover,

  /* Computed Parameter: Merge_5_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_6_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_7_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_8_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_11_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_12_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_13_InitialOutput_e
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_15_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_16_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_17_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_26_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_27_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_28_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0F,

  /* Computed Parameter: Merge_40_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0,

  /* Computed Parameter: Merge_41_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0,

  /* Computed Parameter: Merge_42_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0,

  /* Computed Parameter: Merge_43_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0,

  /* Computed Parameter: Merge_44_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0,

  /* Computed Parameter: Constant_Value_hf
   * Referenced by: '<S2110>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S2111>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_ga
   * Referenced by: '<S2665>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_hg
   * Referenced by: '<S2666>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_jf
   * Referenced by: '<S1738>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_h3
   * Referenced by: '<S1738>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_c
   * Referenced by: '<S1738>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_c
   * Referenced by: '<S1738>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_mm
   * Referenced by: '<S2078>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_l
   * Referenced by: '<S2078>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_h
   * Referenced by: '<S2078>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_in
   * Referenced by: '<S2078>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_pl
   * Referenced by: '<S2529>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_ah
   * Referenced by: '<S2529>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_p
   * Referenced by: '<S2529>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_m
   * Referenced by: '<S2529>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_nq
   * Referenced by: '<S2635>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_g
   * Referenced by: '<S2635>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_od
   * Referenced by: '<S2635>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_h
   * Referenced by: '<S2635>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_fs
   * Referenced by: '<S224>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_cf
   * Referenced by: '<S224>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_a
   * Referenced by: '<S224>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_a
   * Referenced by: '<S224>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_dr
   * Referenced by: '<S606>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_f2
   * Referenced by: '<S606>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_d
   * Referenced by: '<S606>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_he
   * Referenced by: '<S606>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_ln
   * Referenced by: '<S1041>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_d
   * Referenced by: '<S1041>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_k
   * Referenced by: '<S1041>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_d
   * Referenced by: '<S1041>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_al
   * Referenced by: '<S1147>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_b
   * Referenced by: '<S1147>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_ae
   * Referenced by: '<S1147>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_o
   * Referenced by: '<S1147>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_pe
   * Referenced by: '<S1230>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_bo
   * Referenced by: '<S1230>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_aq
   * Referenced by: '<S1230>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_jz
   * Referenced by: '<S1230>/Constant4'
   */
  -1,

  /* Computed Parameter: Gain1_Gain_ms
   * Referenced by: '<S1695>/Gain1'
   */
  MIN_int8_T,

  /* Computed Parameter: Gain1_Gain_dg
   * Referenced by: '<S1187>/Gain1'
   */
  MIN_int8_T,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S1695>/Discrete-Time Integrator'
   */
  0,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_l
   * Referenced by: '<S1187>/Discrete-Time Integrator'
   */
  0,

  /* Computed Parameter: Gain_Gain_ck
   * Referenced by: '<S1695>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S1187>/Gain'
   */
  128U,

  /* Computed Parameter: UnitDelay_InitialCondition_l
   * Referenced by: '<S2119>/Unit Delay'
   */
  0U,

  /* Computed Parameter: Switch_Threshold_g
   * Referenced by: '<S1990>/Switch'
   */
  0U,

  /* Computed Parameter: Switch_Threshold_c
   * Referenced by: '<S1477>/Switch'
   */
  0U,

  /* Computed Parameter: Switch1_Threshold
   * Referenced by: '<S1477>/Switch1'
   */
  0U,

  /* Computed Parameter: Switch2_Threshold
   * Referenced by: '<S1477>/Switch2'
   */
  0U,

  /* Computed Parameter: Switch4_Threshold
   * Referenced by: '<S1477>/Switch4'
   */
  0U,

  /* Computed Parameter: UnitDelay_9_InitialCondition
   * Referenced by: '<S2669>/Unit Delay'
   */
  0U,

  /* Computed Parameter: Constant3_Value_f
   * Referenced by: '<S2669>/Constant3'
   */
  0U,

  /* Computed Parameter: Constant3_Value_e
   * Referenced by: '<S2676>/Constant3'
   */
  0U,

  /* Computed Parameter: Constant_Value_j5
   * Referenced by: '<S2677>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_gm
   * Referenced by: '<S2679>/Constant'
   */
  0U,

  /* Computed Parameter: UnitDelay_9_InitialCondition_d
   * Referenced by: '<S2667>/Unit Delay'
   */
  0U,

  /* Computed Parameter: UnitDelay_9_InitialCondition_l
   * Referenced by: '<S2668>/Unit Delay'
   */
  0U,

  /* Computed Parameter: Constant3_Value_pj
   * Referenced by: '<S2668>/Constant3'
   */
  0U,

  /* Computed Parameter: Constant_Value_av
   * Referenced by: '<S2701>/Constant'
   */
  0U,

  /* Computed Parameter: IC_Value_h
   * Referenced by: '<S2701>/IC'
   */
  1U,

  /* Computed Parameter: Constant2_Value_fj
   * Referenced by: '<S2701>/Constant2'
   */
  1U,

  /* Computed Parameter: UnitDelay_1_InitialCondition_e
   * Referenced by: '<S2>/Unit Delay'
   */
  0U,

  /* Computed Parameter: Merge_14_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_45_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_46_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_47_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_9_InitialOutput_g
   * Referenced by: '<S2>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_1_InitialOutput_l
   * Referenced by: '<S2699>/Merge'
   */
  0U,

  /* Start of '<S2699>/Emergency' */
  {
    /* Expression: 	struct('mode', uint8(0), 'position', zeros(3,1), 'params', zeros(4,1))
     * Referenced by: '<S2702>/Constant1'
     */
    {
      0U,

      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    },

    /* Expression: 	struct('mode', uint8(0), 'position', zeros(3,1), 'params', zeros(4,1))
     * Referenced by: '<S2702>/Constant2'
     */
    {
      0U,

      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    },

    /* Computed Parameter: Constant3_Value
     * Referenced by: '<S2702>/Constant3'
     */
    0U
  }
  ,

  /* End of '<S2699>/Emergency' */

  /* Start of '<S2699>/Switch Case Action Subsystem' */
  {
    /* Expression: 	struct('mode', uint8(0), 'position', zeros(3,1), 'params', zeros(4,1))
     * Referenced by: '<S2703>/Constant1'
     */
    {
      0U,

      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    },

    /* Expression: 	struct('mode', uint8(0), 'position', zeros(3,1), 'params', zeros(4,1))
     * Referenced by: '<S2703>/Constant2'
     */
    {
      0U,

      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    },

    /* Computed Parameter: Constant3_Value
     * Referenced by: '<S2703>/Constant3'
     */
    0U
  }
  ,

  /* End of '<S2699>/Switch Case Action Subsystem' */

  /* Start of '<S1470>/Switch Case Action Subsystem2' */
  {
    /* Expression: Inf
     * Referenced by: '<S1478>/Saturation2'
     */
    INFINITY,

    /* Expression: 0
     * Referenced by: '<S1478>/Saturation2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1478>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1478>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1478>/Constant3'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1478>/Constant4'
     */
    0.0
  }
  ,

  /* End of '<S1470>/Switch Case Action Subsystem2' */

  /* Start of '<S1469>/Switch Case Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S1474>/Constant'
     */
    0.0,

    /* Expression: -0.7
     * Referenced by: '<S1474>/Constant1'
     */
    -0.7,

    /* Expression: 0
     * Referenced by: '<S1474>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1474>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1469>/Switch Case Action Subsystem3' */

  /* Start of '<S1469>/Switch Case Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S1472>/Constant'
     */
    0.0,

    /* Expression: -0.2
     * Referenced by: '<S1472>/Constant1'
     */
    -0.2,

    /* Expression: 0
     * Referenced by: '<S1472>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1472>/Constant3'
     */
    0.0,

    /* Computed Parameter: Switch_Threshold
     * Referenced by: '<S1472>/Switch'
     */
    0U
  }
  ,

  /* End of '<S1469>/Switch Case Action Subsystem1' */

  /* Start of '<S1469>/Switch Case Action Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S1471>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1471>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1471>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1471>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1469>/Switch Case Action Subsystem' */

  /* Start of '<S1176>/Switch Case Action Subsystem2' */
  {
    /* Expression: Inf
     * Referenced by: '<S1184>/Saturation2'
     */
    INFINITY,

    /* Expression: 0
     * Referenced by: '<S1184>/Saturation2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1184>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1184>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1184>/Constant3'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1184>/Constant4'
     */
    0.0
  }
  ,

  /* End of '<S1176>/Switch Case Action Subsystem2' */

  /* Start of '<S1175>/Switch Case Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S1180>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1180>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1180>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1180>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1175>/Switch Case Action Subsystem3' */

  /* Start of '<S1175>/Switch Case Action Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S1177>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1177>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1177>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1177>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1175>/Switch Case Action Subsystem' */

  /* Start of '<S1977>/Switch Case Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S1982>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1982>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1982>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1982>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1977>/Switch Case Action Subsystem3' */

  /* Start of '<S1977>/Switch Case Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S1980>/Constant'
     */
    0.0,

    /* Expression: -0.2
     * Referenced by: '<S1980>/Constant1'
     */
    -0.2,

    /* Expression: 0
     * Referenced by: '<S1980>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1980>/Constant3'
     */
    0.0,

    /* Computed Parameter: Switch_Threshold
     * Referenced by: '<S1980>/Switch'
     */
    0U
  }
  ,

  /* End of '<S1977>/Switch Case Action Subsystem1' */

  /* Start of '<S1977>/Switch Case Action Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S1979>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1979>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1979>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1979>/Constant3'
     */
    0.0
  }
  /* End of '<S1977>/Switch Case Action Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
