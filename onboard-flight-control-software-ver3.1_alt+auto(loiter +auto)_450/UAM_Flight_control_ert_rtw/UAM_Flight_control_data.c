/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: UAM_Flight_control_data.c
 *
 * Code generated for Simulink model 'UAM_Flight_control'.
 *
 * Model version                  : 1.666
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Thu Mar 12 16:50:11 2026
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
   *   '<S2089>/Derivative Gain'
   *   '<S2093>/Integral Gain'
   *   '<S2099>/Filter Coefficient'
   *   '<S2101>/Proportional Gain'
   *   '<S2167>/Proportional Gain'
   *   '<S2207>/Derivative Gain'
   *   '<S2211>/Integral Gain'
   *   '<S2217>/Filter Coefficient'
   *   '<S2219>/Proportional Gain'
   *   '<S2271>/Proportional Gain'
   *   '<S2311>/Derivative Gain'
   *   '<S2315>/Integral Gain'
   *   '<S2321>/Filter Coefficient'
   *   '<S2323>/Proportional Gain'
   *   '<S2375>/Proportional Gain'
   *   '<S2419>/Integral Gain'
   *   '<S2427>/Proportional Gain'
   *   '<S2498>/Proportional Gain'
   *   '<S2540>/Derivative Gain'
   *   '<S2544>/Integral Gain'
   *   '<S2550>/Filter Coefficient'
   *   '<S2552>/Proportional Gain'
   *   '<S2604>/Proportional Gain'
   *   '<S2646>/Derivative Gain'
   *   '<S2650>/Integral Gain'
   *   '<S2656>/Filter Coefficient'
   *   '<S2658>/Proportional Gain'
   *   '<S569>/Proportional Gain'
   *   '<S611>/Derivative Gain'
   *   '<S615>/Integral Gain'
   *   '<S621>/Filter Coefficient'
   *   '<S623>/Proportional Gain'
   *   '<S682>/Proportional Gain'
   *   '<S724>/Derivative Gain'
   *   '<S728>/Integral Gain'
   *   '<S734>/Filter Coefficient'
   *   '<S736>/Proportional Gain'
   *   '<S788>/Proportional Gain'
   *   '<S830>/Derivative Gain'
   *   '<S834>/Integral Gain'
   *   '<S840>/Filter Coefficient'
   *   '<S842>/Proportional Gain'
   *   '<S894>/Proportional Gain'
   *   '<S940>/Integral Gain'
   *   '<S948>/Proportional Gain'
   *   '<S1010>/Proportional Gain'
   *   '<S1052>/Derivative Gain'
   *   '<S1056>/Integral Gain'
   *   '<S1062>/Filter Coefficient'
   *   '<S1064>/Proportional Gain'
   *   '<S1116>/Proportional Gain'
   *   '<S1158>/Derivative Gain'
   *   '<S1162>/Integral Gain'
   *   '<S1168>/Filter Coefficient'
   *   '<S1170>/Proportional Gain'
   *   '<S1638>/Proportional Gain'
   *   '<S1678>/Derivative Gain'
   *   '<S1688>/Filter Coefficient'
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
   *   '<S1191>/Gain1'
   *   '<S1191>/Gain2'
   *   '<S1191>/Gain3'
   *   '<S1191>/Gain4'
   *   '<S1193>/Gain1'
   *   '<S1193>/Gain2'
   *   '<S1193>/Gain3'
   *   '<S1193>/Gain4'
   *   '<S1483>/Gain'
   *   '<S1483>/Gain1'
   *   '<S1483>/Gain2'
   *   '<S1483>/Gain3'
   *   '<S1483>/Gain4'
   *   '<S1484>/Gain1'
   *   '<S1484>/Gain2'
   *   '<S1484>/Gain3'
   *   '<S1484>/Gain5'
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
   *   '<S2681>/Constant'
   *   '<S2681>/Lookahead Distance'
   *   '<S2682>/Constant'
   *   '<S2682>/Lookahead Distance'
   *   '<S191>/Saturation'
   *   '<S191>/Saturation1'
   *   '<S1206>/Saturation'
   *   '<S1206>/Saturation1'
   *   '<S1714>/Saturation'
   *   '<S1714>/Saturation1'
   *   '<S125>/Saturation'
   *   '<S178>/Saturation'
   *   '<S345>/Saturation'
   *   '<S1359>/Saturation'
   *   '<S1867>/Saturation'
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
   *   '<S1241>/Derivative Gain'
   *   '<S1245>/Integral Gain'
   *   '<S1251>/Filter Coefficient'
   *   '<S1253>/Proportional Gain'
   *   '<S1305>/Proportional Gain'
   *   '<S1357>/Proportional Gain'
   *   '<S1409>/Proportional Gain'
   *   '<S1749>/Derivative Gain'
   *   '<S1753>/Integral Gain'
   *   '<S1759>/Filter Coefficient'
   *   '<S1761>/Proportional Gain'
   *   '<S1813>/Proportional Gain'
   *   '<S1865>/Proportional Gain'
   *   '<S1917>/Proportional Gain'
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
   *   '<S1485>/Constant5'
   *   '<S1487>/Constant5'
   */
  1.0,

  /* Variable: FWTrimSpeed
   * Referenced by:
   *   '<S10>/Constant3'
   *   '<S10>/Constant4'
   *   '<S1192>/Constant1'
   *   '<S1485>/Constant4'
   *   '<S1486>/Constant1'
   */
  261.8,

  /* Variable: Vt
   * Referenced by:
   *   '<S2675>/Guidance Mode Selector'
   *   '<S2676>/Basic Control  Switching'
   *   '<S2677>/Basic Control  Switching'
   */
  10.0,

  /* Variable: w_trim
   * Referenced by:
   *   '<S1191>/Gain1'
   *   '<S1191>/Gain2'
   *   '<S1191>/Gain3'
   *   '<S1191>/Gain4'
   *   '<S1193>/Gain1'
   *   '<S1193>/Gain2'
   *   '<S1193>/Gain3'
   *   '<S1193>/Gain4'
   *   '<S1484>/Gain1'
   *   '<S1484>/Gain2'
   *   '<S1484>/Gain3'
   *   '<S1484>/Gain5'
   *   '<S1485>/Constant'
   *   '<S1485>/Constant1'
   *   '<S1485>/Constant2'
   *   '<S1485>/Constant3'
   *   '<S1487>/Constant'
   *   '<S1487>/Constant1'
   *   '<S1487>/Constant2'
   *   '<S1487>/Constant3'
   */
  104.7,

  /* Variable: zGround
   * Referenced by: '<S2675>/Guidance Mode Selector'
   */
  0.0,

  /* Variable: FSState
   * Referenced by:
   *   '<S2675>/Constant2'
   *   '<S2676>/Hover'
   *   '<S2677>/Hover'
   */
  Hover,

  /* Mask Parameter: PitchAngleController_InitialCon
   * Referenced by: '<S1751>/Filter'
   */
  0.0,

  /* Mask Parameter: Altituderatecontroller_InitialC
   * Referenced by: '<S2091>/Filter'
   */
  0.0,

  /* Mask Parameter: Lateralvelocitycontroller_Initi
   * Referenced by: '<S2648>/Filter'
   */
  0.0,

  /* Mask Parameter: Forwardvelocitycontroller_Initi
   * Referenced by: '<S2542>/Filter'
   */
  0.0,

  /* Mask Parameter: Pitchratecontroller_InitialCond
   * Referenced by: '<S2209>/Filter'
   */
  0.0,

  /* Mask Parameter: Rollratecontroller_InitialCondi
   * Referenced by: '<S2313>/Filter'
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

  /* Mask Parameter: Altituderatecontroller_Initia_g
   * Referenced by: '<S613>/Filter'
   */
  0.0,

  /* Mask Parameter: Forwardvelocitycontroller_Ini_a
   * Referenced by: '<S1054>/Filter'
   */
  0.0,

  /* Mask Parameter: Lateralvelocitycontroller_Ini_p
   * Referenced by: '<S1160>/Filter'
   */
  0.0,

  /* Mask Parameter: PitchRateController_InitialCond
   * Referenced by: '<S726>/Filter'
   */
  0.0,

  /* Mask Parameter: RollRateController_InitialCondi
   * Referenced by: '<S832>/Filter'
   */
  0.0,

  /* Mask Parameter: PitchAngleController_Initial_pa
   * Referenced by: '<S1243>/Filter'
   */
  0.0,

  /* Mask Parameter: Yawratecontroller_InitialCondit
   * Referenced by: '<S1680>/Filter'
   */
  0.0,

  /* Mask Parameter: PitchAngleController_InitialC_d
   * Referenced by: '<S1756>/Integrator'
   */
  0.0,

  /* Mask Parameter: Altituderatecontroller_Initia_j
   * Referenced by: '<S2096>/Integrator'
   */
  0.0,

  /* Mask Parameter: Lateralvelocitycontroller_Ini_k
   * Referenced by: '<S2653>/Integrator'
   */
  0.0,

  /* Mask Parameter: Forwardvelocitycontroller_Ini_i
   * Referenced by: '<S2547>/Integrator'
   */
  0.0,

  /* Mask Parameter: Yawratecontroller_InitialCond_c
   * Referenced by: '<S2422>/Integrator'
   */
  0.0,

  /* Mask Parameter: Pitchratecontroller_InitialCo_i
   * Referenced by: '<S2214>/Integrator'
   */
  0.0,

  /* Mask Parameter: Rollratecontroller_InitialCon_e
   * Referenced by: '<S2318>/Integrator'
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

  /* Mask Parameter: Altituderatecontroller_Initia_k
   * Referenced by: '<S618>/Integrator'
   */
  0.0,

  /* Mask Parameter: Forwardvelocitycontroller_Ini_o
   * Referenced by: '<S1059>/Integrator'
   */
  0.0,

  /* Mask Parameter: Lateralvelocitycontroller_Ini_m
   * Referenced by: '<S1165>/Integrator'
   */
  0.0,

  /* Mask Parameter: Yawratecontroller_InitialCond_a
   * Referenced by: '<S943>/Integrator'
   */
  0.0,

  /* Mask Parameter: PitchRateController_InitialCo_m
   * Referenced by: '<S731>/Integrator'
   */
  0.0,

  /* Mask Parameter: RollRateController_InitialCon_j
   * Referenced by: '<S837>/Integrator'
   */
  0.0,

  /* Mask Parameter: PitchAngleController_InitialC_f
   * Referenced by: '<S1248>/Integrator'
   */
  0.0,

  /* Mask Parameter: Altituderatecontroller_LowerInt
   * Referenced by: '<S2096>/Integrator'
   */
  -1.5,

  /* Mask Parameter: Lateralvelocitycontroller_Lower
   * Referenced by: '<S2653>/Integrator'
   */
  -2.0,

  /* Mask Parameter: Forwardvelocitycontroller_Lower
   * Referenced by: '<S2547>/Integrator'
   */
  -2.0,

  /* Mask Parameter: Yawratecontroller_LowerIntegrat
   * Referenced by: '<S2422>/Integrator'
   */
  -0.3,

  /* Mask Parameter: Pitchratecontroller_LowerIntegr
   * Referenced by: '<S2214>/Integrator'
   */
  -0.3,

  /* Mask Parameter: Rollratecontroller_LowerIntegra
   * Referenced by: '<S2318>/Integrator'
   */
  -0.3,

  /* Mask Parameter: Altituderatecontroller_LowerI_o
   * Referenced by: '<S618>/Integrator'
   */
  -1.5,

  /* Mask Parameter: Forwardvelocitycontroller_Low_e
   * Referenced by: '<S1059>/Integrator'
   */
  -2.0,

  /* Mask Parameter: Lateralvelocitycontroller_Low_c
   * Referenced by: '<S1165>/Integrator'
   */
  -2.0,

  /* Mask Parameter: Yawratecontroller_LowerIntegr_o
   * Referenced by: '<S943>/Integrator'
   */
  -0.3,

  /* Mask Parameter: PitchRateController_LowerIntegr
   * Referenced by: '<S731>/Integrator'
   */
  -0.3,

  /* Mask Parameter: RollRateController_LowerIntegra
   * Referenced by: '<S837>/Integrator'
   */
  -0.3,

  /* Mask Parameter: PitchAngleController_LowerSatur
   * Referenced by:
   *   '<S1763>/Saturation'
   *   '<S1748>/DeadZone'
   */
  -INFINITY,

  /* Mask Parameter: PitchRateController_LowerSatura
   * Referenced by: '<S1815>/Saturation'
   */
  -INFINITY,

  /* Mask Parameter: RudderController_LowerSaturatio
   * Referenced by: '<S1973>/Saturation'
   */
  -1.0,

  /* Mask Parameter: RollRateController_LowerSaturat
   * Referenced by: '<S1919>/Saturation'
   */
  -1.0,

  /* Mask Parameter: Altituderatecontroller_LowerSat
   * Referenced by:
   *   '<S2103>/Saturation'
   *   '<S2088>/DeadZone'
   */
  -INFINITY,

  /* Mask Parameter: Lateralpositioncontroller_Lower
   * Referenced by: '<S2606>/Saturation'
   */
  -5.0,

  /* Mask Parameter: Lateralvelocitycontroller_Low_p
   * Referenced by:
   *   '<S2660>/Saturation'
   *   '<S2645>/DeadZone'
   */
  -5.0,

  /* Mask Parameter: Forwardvelocitycontroller_Low_p
   * Referenced by:
   *   '<S2554>/Saturation'
   *   '<S2539>/DeadZone'
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
   * Referenced by: '<S571>/Saturation'
   */
  -5.0,

  /* Mask Parameter: Altituderatecontroller_LowerS_h
   * Referenced by:
   *   '<S625>/Saturation'
   *   '<S610>/DeadZone'
   */
  -2.0,

  /* Mask Parameter: Forwardpositioncontroller_Lower
   * Referenced by: '<S1012>/Saturation'
   */
  -1.5,

  /* Mask Parameter: Lateralpositioncontroller_Low_j
   * Referenced by: '<S1118>/Saturation'
   */
  -1.5,

  /* Mask Parameter: Forwardvelocitycontroller_Lo_ei
   * Referenced by:
   *   '<S1066>/Saturation'
   *   '<S1051>/DeadZone'
   */
  -5.0,

  /* Mask Parameter: Lateralvelocitycontroller_Low_o
   * Referenced by:
   *   '<S1172>/Saturation'
   *   '<S1157>/DeadZone'
   */
  -5.0,

  /* Mask Parameter: Yawratecontroller_LowerSaturati
   * Referenced by:
   *   '<S950>/Saturation'
   *   '<S935>/DeadZone'
   */
  -0.25,

  /* Mask Parameter: PitchController_LowerSaturation
   * Referenced by: '<S684>/Saturation'
   */
  -3.839724354387525,

  /* Mask Parameter: PitchRateController_LowerSatu_h
   * Referenced by:
   *   '<S738>/Saturation'
   *   '<S723>/DeadZone'
   */
  -0.35,

  /* Mask Parameter: RollController_LowerSaturationL
   * Referenced by: '<S790>/Saturation'
   */
  -3.839724354387525,

  /* Mask Parameter: RollRateController_LowerSatur_o
   * Referenced by:
   *   '<S844>/Saturation'
   *   '<S829>/DeadZone'
   */
  -0.35,

  /* Mask Parameter: PitchAngleController_LowerSat_e
   * Referenced by:
   *   '<S1255>/Saturation'
   *   '<S1240>/DeadZone'
   */
  -INFINITY,

  /* Mask Parameter: PitchRateController_LowerSatu_o
   * Referenced by: '<S1307>/Saturation'
   */
  -INFINITY,

  /* Mask Parameter: RudderController_LowerSaturat_f
   * Referenced by: '<S1465>/Saturation'
   */
  -1.0,

  /* Mask Parameter: RollRateController_LowerSatur_g
   * Referenced by: '<S1411>/Saturation'
   */
  -1.0,

  /* Mask Parameter: RudderController_P
   * Referenced by: '<S1971>/Proportional Gain'
   */
  0.01,

  /* Mask Parameter: Altitudecontroller_P
   * Referenced by: '<S2047>/Proportional Gain'
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
   * Referenced by: '<S1463>/Proportional Gain'
   */
  0.01,

  /* Mask Parameter: PitchController_P
   * Referenced by: '<S1534>/Proportional Gain'
   */
  2.0,

  /* Mask Parameter: RollController_P
   * Referenced by: '<S1586>/Proportional Gain'
   */
  2.0,

  /* Mask Parameter: Yawratecontroller_P
   * Referenced by: '<S1690>/Proportional Gain'
   */
  2.0,

  /* Mask Parameter: Altituderatecontroller_UpperInt
   * Referenced by: '<S2096>/Integrator'
   */
  2.0,

  /* Mask Parameter: Lateralvelocitycontroller_Upper
   * Referenced by: '<S2653>/Integrator'
   */
  2.0,

  /* Mask Parameter: Forwardvelocitycontroller_Upper
   * Referenced by: '<S2547>/Integrator'
   */
  2.0,

  /* Mask Parameter: Yawratecontroller_UpperIntegrat
   * Referenced by: '<S2422>/Integrator'
   */
  0.3,

  /* Mask Parameter: Pitchratecontroller_UpperIntegr
   * Referenced by: '<S2214>/Integrator'
   */
  0.3,

  /* Mask Parameter: Rollratecontroller_UpperIntegra
   * Referenced by: '<S2318>/Integrator'
   */
  0.3,

  /* Mask Parameter: Altituderatecontroller_UpperI_n
   * Referenced by: '<S618>/Integrator'
   */
  2.0,

  /* Mask Parameter: Forwardvelocitycontroller_Upp_k
   * Referenced by: '<S1059>/Integrator'
   */
  2.0,

  /* Mask Parameter: Lateralvelocitycontroller_Upp_g
   * Referenced by: '<S1165>/Integrator'
   */
  2.0,

  /* Mask Parameter: Yawratecontroller_UpperIntegr_o
   * Referenced by: '<S943>/Integrator'
   */
  0.3,

  /* Mask Parameter: PitchRateController_UpperIntegr
   * Referenced by: '<S731>/Integrator'
   */
  0.3,

  /* Mask Parameter: RollRateController_UpperIntegra
   * Referenced by: '<S837>/Integrator'
   */
  0.3,

  /* Mask Parameter: PitchAngleController_UpperSatur
   * Referenced by:
   *   '<S1763>/Saturation'
   *   '<S1748>/DeadZone'
   */
  INFINITY,

  /* Mask Parameter: PitchRateController_UpperSatura
   * Referenced by: '<S1815>/Saturation'
   */
  INFINITY,

  /* Mask Parameter: RudderController_UpperSaturatio
   * Referenced by: '<S1973>/Saturation'
   */
  1.0,

  /* Mask Parameter: RollRateController_UpperSaturat
   * Referenced by: '<S1919>/Saturation'
   */
  1.0,

  /* Mask Parameter: Altituderatecontroller_UpperSat
   * Referenced by:
   *   '<S2103>/Saturation'
   *   '<S2088>/DeadZone'
   */
  INFINITY,

  /* Mask Parameter: Lateralpositioncontroller_Upper
   * Referenced by: '<S2606>/Saturation'
   */
  5.0,

  /* Mask Parameter: Lateralvelocitycontroller_Upp_b
   * Referenced by:
   *   '<S2660>/Saturation'
   *   '<S2645>/DeadZone'
   */
  5.0,

  /* Mask Parameter: Forwardvelocitycontroller_Upp_o
   * Referenced by:
   *   '<S2554>/Saturation'
   *   '<S2539>/DeadZone'
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
   * Referenced by: '<S571>/Saturation'
   */
  5.0,

  /* Mask Parameter: Altituderatecontroller_UpperS_b
   * Referenced by:
   *   '<S625>/Saturation'
   *   '<S610>/DeadZone'
   */
  2.0,

  /* Mask Parameter: Forwardpositioncontroller_Upper
   * Referenced by: '<S1012>/Saturation'
   */
  1.5,

  /* Mask Parameter: Lateralpositioncontroller_Upp_a
   * Referenced by: '<S1118>/Saturation'
   */
  1.5,

  /* Mask Parameter: Forwardvelocitycontroller_Upp_h
   * Referenced by:
   *   '<S1066>/Saturation'
   *   '<S1051>/DeadZone'
   */
  5.0,

  /* Mask Parameter: Lateralvelocitycontroller_Upp_f
   * Referenced by:
   *   '<S1172>/Saturation'
   *   '<S1157>/DeadZone'
   */
  5.0,

  /* Mask Parameter: Yawratecontroller_UpperSaturati
   * Referenced by:
   *   '<S950>/Saturation'
   *   '<S935>/DeadZone'
   */
  0.25,

  /* Mask Parameter: PitchController_UpperSaturation
   * Referenced by: '<S684>/Saturation'
   */
  3.839724354387525,

  /* Mask Parameter: PitchRateController_UpperSatu_h
   * Referenced by:
   *   '<S738>/Saturation'
   *   '<S723>/DeadZone'
   */
  0.35,

  /* Mask Parameter: RollController_UpperSaturationL
   * Referenced by: '<S790>/Saturation'
   */
  3.839724354387525,

  /* Mask Parameter: RollRateController_UpperSatu_c0
   * Referenced by:
   *   '<S844>/Saturation'
   *   '<S829>/DeadZone'
   */
  0.35,

  /* Mask Parameter: PitchAngleController_UpperSat_c
   * Referenced by:
   *   '<S1255>/Saturation'
   *   '<S1240>/DeadZone'
   */
  INFINITY,

  /* Mask Parameter: PitchRateController_UpperSatu_l
   * Referenced by: '<S1307>/Saturation'
   */
  INFINITY,

  /* Mask Parameter: RudderController_UpperSaturat_i
   * Referenced by: '<S1465>/Saturation'
   */
  1.0,

  /* Mask Parameter: RollRateController_UpperSatur_l
   * Referenced by: '<S1411>/Saturation'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S2114>/Constant'
   */
  0.05,

  /* Mask Parameter: CompareToConstant_const_i
   * Referenced by: '<S2446>/Constant'
   */
  0.05,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S2447>/Constant'
   */
  0.05,

  /* Mask Parameter: deadzone_const
   * Referenced by: '<S2442>/Constant'
   */
  0.05,

  /* Mask Parameter: disarm_const
   * Referenced by: '<S2443>/Constant'
   */
  0.0,

  /* Mask Parameter: arm_const
   * Referenced by: '<S2441>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_k
   * Referenced by: '<S526>/Constant'
   */
  1.0,

  /* Mask Parameter: CompareToConstant_const_k3
   * Referenced by: '<S522>/Constant'
   */
  1700.0,

  /* Mask Parameter: CompareToConstant1_const_f
   * Referenced by: '<S2720>/Constant'
   */
  3.0,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S2710>/Constant'
   */
  1300.0,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S2709>/Constant'
   */
  1700.0,

  /* Mask Parameter: CompareToConstant_const_d
   * Referenced by: '<S2725>/Constant'
   */
  1700.0,

  /* Mask Parameter: DetectRisePositive_vinit
   * Referenced by: '<S2115>/Delay Input1'
   */
  false,

  /* Mask Parameter: DetectRisePositive1_vinit
   * Referenced by: '<S2116>/Delay Input1'
   */
  false,

  /* Mask Parameter: DetectRisePositive_vinit_j
   * Referenced by: '<S2671>/Delay Input1'
   */
  false,

  /* Mask Parameter: DetectRisePositive1_vinit_g
   * Referenced by: '<S2672>/Delay Input1'
   */
  false,

  /* Mask Parameter: CompareToConstant_const_a
   * Referenced by: '<S1713>/Constant'
   */
  1U,

  /* Mask Parameter: prev_is_1_const
   * Referenced by: '<S2445>/Constant'
   */
  1U,

  /* Mask Parameter: now_is_0_const
   * Referenced by: '<S2444>/Constant'
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
   * Referenced by: '<S1205>/Constant'
   */
  1U,

  /* Mask Parameter: CompareToConstant_const_ko
   * Referenced by: '<S2678>/Constant'
   */
  2U,

  /* Mask Parameter: CompareToConstant_const_c
   * Referenced by: '<S2719>/Constant'
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
   * Referenced by: '<S2711>/Waypoints2'
   */
  { {
      1U,

      { 0.0, 0.0, -1.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.3, 0.0, -1.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 4U,
      { 0.3, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 6U,
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 2U,
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    }, { 4U,
      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    } },

  /* Computed Parameter: Merge_2_InitialOutput
   * Referenced by: '<S2712>/Merge'
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
   * Referenced by: '<S2712>/Merge'
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
   * Referenced by: '<S2677>/Unit Delay'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Expression: struct('airspeed', 0.0, 'altitude', 0.0, 'course', 0.0, 'L1', 0.0, 'climbrate', 0.0)

   * Referenced by: '<S2677>/Constant2'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Computed Parameter: UnitDelay_6_InitialCondition_d
   * Referenced by: '<S2675>/Unit Delay'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Computed Parameter: UnitDelay_6_InitialCondition_l
   * Referenced by: '<S2676>/Unit Delay'
   */
  {
    0.0,                               /* airspeed */
    0.0,                               /* altitude */
    0.0,                               /* course */
    0.0,                               /* L1 */
    0.0                                /* climbrate */
  },

  /* Expression: struct('airspeed', 0.0, 'altitude', 0.0, 'course', 0.0, 'L1', 0.0, 'climbrate', 0.0)

   * Referenced by: '<S2676>/Constant2'
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
   * Referenced by: '<S2712>/Merge'
   */
  {
    0.0,                               /* w1 */
    0.0,                               /* w2 */
    0.0,                               /* w3 */
    0.0,                               /* w4 */
    0.0                                /* c1 */
  },

  /* Computed Parameter: UnitDelay_7_InitialCondition
   * Referenced by: '<S2677>/Unit Delay'
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
    0.0,                               /* land */
    0.0,                               /* spoolup_active */
    0.0                                /* ramp_progress */
  },

  /* Computed Parameter: UnitDelay_7_InitialCondition_d
   * Referenced by: '<S2675>/Unit Delay'
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
    0.0,                               /* land */
    0.0,                               /* spoolup_active */
    0.0                                /* ramp_progress */
  },

  /* Computed Parameter: UnitDelay_7_InitialCondition_l
   * Referenced by: '<S2676>/Unit Delay'
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
    0.0,                               /* land */
    0.0,                               /* spoolup_active */
    0.0                                /* ramp_progress */
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
    0.0,                               /* land */
    0.0,                               /* spoolup_active */
    0.0                                /* ramp_progress */
  },

  /* Computed Parameter: MixerCommands_Y0
   * Referenced by: '<S1706>/MixerCommands'
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
   * Referenced by: '<S1198>/MixerCommands'
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
   * Referenced by: '<S2677>/Unit Delay'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Expression: struct('roll', 0.0, 'pitch', 0.0, 'yaw', 0.0, 'airspeed', 0.0)

   * Referenced by: '<S2677>/Constant1'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Computed Parameter: UnitDelay_5_InitialCondition_d
   * Referenced by: '<S2675>/Unit Delay'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Computed Parameter: UnitDelay_5_InitialCondition_l
   * Referenced by: '<S2676>/Unit Delay'
   */
  {
    0.0,                               /* roll */
    0.0,                               /* pitch */
    0.0,                               /* yaw */
    0.0                                /* airspeed */
  },

  /* Expression: struct('roll', 0.0, 'pitch', 0.0, 'yaw', 0.0, 'airspeed', 0.0)

   * Referenced by: '<S2676>/Constant1'
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
   * Referenced by: '<S1705>/CtrlSurfaceCommands'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S1985>/Merge'
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
   * Referenced by: '<S1183>/Merge'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: CtrlSurfaceCommands_Y0_k
   * Referenced by: '<S1197>/CtrlSurfaceCommands'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Merge_InitialOutput_g
   * Referenced by: '<S1477>/Merge'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Merge_68_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Actuator_Y0
   * Referenced by: '<S1704>/Actuator'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: Actuator_Y0_a
   * Referenced by: '<S1196>/Actuator'
   */
  {
    0.0,                               /* dA */
    0.0,                               /* dE */
    0.0,                               /* dR */
    0.0                                /* dT */
  },

  /* Computed Parameter: AER_Y0
   * Referenced by: '<S1714>/AER'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1746>/Constant1'
   */
  0.0,

  /* Expression: [1  1;
     1 -1]

   * Referenced by: '<S1714>/Constant'
   */
  { 1.0, 1.0, 1.0, -1.0 },

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S1756>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S1751>/Filter'
   */
  0.005,

  /* Expression: 0.3
   * Referenced by: '<S1714>/Saturation2'
   */
  0.3,

  /* Expression: -0.3
   * Referenced by: '<S1714>/Saturation2'
   */
  -0.3,

  /* Expression: 0
   * Referenced by: '<S1746>/Clamping_zero'
   */
  0.0,

  /* Expression: -1000
   * Referenced by: '<S1711>/Bias'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1711>/Gain'
   */
  0.001,

  /* Expression: pi/6
   * Referenced by: '<S1711>/Gain1'
   */
  0.52359877559829882,

  /* Expression: -1000
   * Referenced by: '<S1712>/Bias'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1712>/Gain'
   */
  0.001,

  /* Expression: pi/9
   * Referenced by: '<S1712>/Gain1'
   */
  0.3490658503988659,

  /* Expression: [1 -1 -1 1; 1 1 1 1; 1 1 -1 -1; 1 -1 1 -1]
   * Referenced by: '<S1992>/Constant'
   */
  { 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, 1.0,
    -1.0, -1.0 },

  /* Expression: 0
   * Referenced by: '<S1992>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1705>/MotorActuatorCommands'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Gain1'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Constant2'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Gain3'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Constant4'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Gain5'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Constant6'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Gain7'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Constant8'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S1991>/Constant'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1991>/Saturation'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Saturation'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1991>/Saturation1'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Saturation1'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1991>/Saturation2'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Saturation2'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1991>/Saturation3'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Saturation3'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1991>/Saturation4'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1991>/Saturation4'
   */
  1000.0,

  /* Expression: 3 / 0.9
   * Referenced by: '<S2007>/throttle_up'
   */
  3.333333333333333,

  /* Expression: 1 / 0.9
   * Referenced by: '<S2007>/throttle_down'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S2007>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2086>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1997>/Gain'
   */
  -1.0,

  /* Expression: -0.5
   * Referenced by: '<S2007>/Bias'
   */
  -0.5,

  /* Expression: 2
   * Referenced by: '<S2007>/Gain3'
   */
  2.0,

  /* Expression: -0.1
   * Referenced by: '<S2007>/Dead Zone'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S2007>/Dead Zone'
   */
  0.1,

  /* Expression: 0.6
   * Referenced by: '<S2007>/Constant'
   */
  0.6,

  /* Expression: 0
   * Referenced by: '<S2007>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S1997>/Gain1'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_n
   * Referenced by: '<S2096>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_e
   * Referenced by: '<S2091>/Filter'
   */
  0.005,

  /* Expression: 0
   * Referenced by: '<S1997>/Unit Delay'
   */
  0.0,

  /* Expression: 1/9.81
   * Referenced by: '<S1997>/hover_thrust//g'
   */
  0.1019367991845056,

  /* Expression: 0.9
   * Referenced by: '<S1997>/Saturation1'
   */
  0.9,

  /* Expression: 0.15
   * Referenced by: '<S1997>/Saturation1'
   */
  0.15,

  /* Expression: 0
   * Referenced by: '<S2086>/Clamping_zero'
   */
  0.0,

  /* Expression: 120*pi/180
   * Referenced by: '<S2127>/yaw_max_rate'
   */
  2.0943951023931953,

  /* Expression: 10
   * Referenced by: '<S2000>/Foward Velocity Setpoint'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2000>/Foward Velocity Setpoint'
   */
  -10.0,

  /* Expression: 10
   * Referenced by: '<S2000>/Vel_manual'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<S2000>/Lateral Velocity Setpoint'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S2000>/Lateral Velocity Setpoint'
   */
  -10.0,

  /* Expression: 10
   * Referenced by: '<S2000>/Vel_manual(m//s)'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S2537>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2643>/Constant1'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S2000>/Dead Zone'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S2000>/Dead Zone'
   */
  0.1,

  /* Expression: 0.6
   * Referenced by: '<S2000>/Constant'
   */
  0.6,

  /* Expression: -0.1
   * Referenced by: '<S2000>/Dead Zone1'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S2000>/Dead Zone1'
   */
  0.1,

  /* Expression: 0.6
   * Referenced by: '<S2000>/Constant1'
   */
  0.6,

  /* Expression: 1
   * Referenced by: '<S2000>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2000>/Rate Limiter'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2000>/Rate Limiter'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S2000>/Rate Limiter'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2458>/Unit Delay'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2452>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S2458>/Unit Delay1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S2454>/Gain'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_d
   * Referenced by: '<S2653>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_i
   * Referenced by: '<S2648>/Filter'
   */
  0.005,

  /* Expression: 1/9.81
   * Referenced by: '<S2000>/rad'
   */
  0.1019367991845056,

  /* Expression: 0.51
   * Referenced by: '<S2000>/Saturation1'
   */
  0.51,

  /* Expression: -0.51
   * Referenced by: '<S2000>/Saturation1'
   */
  -0.51,

  /* Expression: 0
   * Referenced by: '<S2643>/Clamping_zero'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2000>/Rate Limiter1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S2000>/Rate Limiter1'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S2000>/Rate Limiter1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_i
   * Referenced by: '<S2547>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_j
   * Referenced by: '<S2542>/Filter'
   */
  0.005,

  /* Expression: 1/9.81
   * Referenced by: '<S2000>/Gain'
   */
  0.1019367991845056,

  /* Expression: 0.51
   * Referenced by: '<S2000>/Saturation'
   */
  0.51,

  /* Expression: -0.51
   * Referenced by: '<S2000>/Saturation'
   */
  -0.51,

  /* Expression: 0
   * Referenced by: '<S2537>/Clamping_zero'
   */
  0.0,

  /* Expression: -1000
   * Referenced by: '<S2002>/Bias1'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S2002>/Gain1'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<S2002>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2002>/Saturation'
   */
  0.0,

  /* Expression: -1500
   * Referenced by: '<S2002>/Bias'
   */
  -1500.0,

  /* Expression: 1/500
   * Referenced by: '<S2002>/Gain'
   */
  0.002,

  /* Expression: 0
   * Referenced by: '<S2127>/Unit Delay1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_du
   * Referenced by: '<S2422>/Integrator'
   */
  0.005,

  /* Expression: 0.4
   * Referenced by: '<S1998>/Gain1'
   */
  0.4,

  /* Computed Parameter: RefRP_InitialOutput
   * Referenced by: '<S1706>/Ref RP'
   */
  0.0,

  /* Expression: 35*pi/180
   * Referenced by: '<S1998>/Pitch_MAX_angle'
   */
  0.6108652381980153,

  /* Expression: 0.61087
   * Referenced by: '<S1998>/Saturation1'
   */
  0.61087,

  /* Expression: -0.61087
   * Referenced by: '<S1998>/Saturation1'
   */
  -0.61087,

  /* Computed Parameter: Filter_gainval_p
   * Referenced by: '<S2209>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_m
   * Referenced by: '<S2214>/Integrator'
   */
  0.005,

  /* Expression: 35*pi/180
   * Referenced by: '<S1998>/Roll_MAX_angle'
   */
  0.6108652381980153,

  /* Expression: 0.61087
   * Referenced by: '<S1998>/Saturation'
   */
  0.61087,

  /* Expression: -0.61087
   * Referenced by: '<S1998>/Saturation'
   */
  -0.61087,

  /* Computed Parameter: Filter_gainval_c
   * Referenced by: '<S2313>/Filter'
   */
  0.005,

  /* Computed Parameter: Integrator_gainval_o
   * Referenced by: '<S2318>/Integrator'
   */
  0.005,

  /* Expression: 1
   * Referenced by: '<S1998>/Saturation5'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1998>/Saturation5'
   */
  -1.0,

  /* Computed Parameter: Merge2_InitialOutput
   * Referenced by: '<S1706>/Merge2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1703>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1703>/Saturation'
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

  /* Expression: -1
   * Referenced by: '<S521>/Gain2'
   */
  -1.0,

  /* Expression: 0.7
   * Referenced by: '<S521>/Constant2'
   */
  0.7,

  /* Computed Parameter: Reference_Y0
   * Referenced by: '<S529>/Reference'
   */
  0.0,

  /* Computed Parameter: commandedthrust_Y0
   * Referenced by: '<S521>/commanded thrust'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S608>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S521>/Gain'
   */
  -1.0,

  /* Expression: 0.7
   * Referenced by: '<S521>/Constant1'
   */
  0.7,

  /* Expression: -1
   * Referenced by: '<S521>/Gain1'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S618>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_gk
   * Referenced by: '<S613>/Filter'
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
   * Referenced by: '<S608>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: Forwardcmd_Y0
   * Referenced by: '<S961>/Forward cmd'
   */
  0.0,

  /* Computed Parameter: SidewardCmd_Y0
   * Referenced by: '<S961>/Sideward Cmd'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1049>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1155>/Constant1'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S966>/Gain'
   */
  -1.0,

  /* Expression: 0.01
   * Referenced by: '<S970>/Value'
   */
  0.01,

  /* Expression: 3
   * Referenced by: '<S970>/MPC_ACC_HOR'
   */
  3.0,

  /* Expression: 4
   * Referenced by: '<S970>/Gain'
   */
  4.0,

  /* Expression: 4
   * Referenced by: '<S970>/MPC_JERK_AUTO'
   */
  4.0,

  /* Expression: -2
   * Referenced by: '<S970>/Gain1'
   */
  -2.0,

  /* Expression: 4
   * Referenced by: '<S970>/Gain2'
   */
  4.0,

  /* Expression: 0.5
   * Referenced by: '<S970>/Gain3'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S970>/value'
   */
  1.0,

  /* Expression: 1.5
   * Referenced by: '<S961>/Saturation3'
   */
  1.5,

  /* Expression: -1.5
   * Referenced by: '<S961>/Saturation3'
   */
  -1.5,

  /* Computed Parameter: Integrator_gainval_nm
   * Referenced by: '<S1059>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_er
   * Referenced by: '<S1054>/Filter'
   */
  0.005,

  /* Expression: 1/9.81
   * Referenced by: '<S961>/Gain'
   */
  0.1019367991845056,

  /* Expression: 0.51
   * Referenced by: '<S961>/Saturation'
   */
  0.51,

  /* Expression: -0.51
   * Referenced by: '<S961>/Saturation'
   */
  -0.51,

  /* Expression: 0
   * Referenced by: '<S1049>/Clamping_zero'
   */
  0.0,

  /* Expression: 1.5
   * Referenced by: '<S961>/Saturation2'
   */
  1.5,

  /* Expression: -1.5
   * Referenced by: '<S961>/Saturation2'
   */
  -1.5,

  /* Expression: -1
   * Referenced by: '<S968>/Gain'
   */
  -1.0,

  /* Computed Parameter: Integrator_gainval_e
   * Referenced by: '<S1165>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_gl
   * Referenced by: '<S1160>/Filter'
   */
  0.005,

  /* Expression: 1/9.81
   * Referenced by: '<S961>/rad'
   */
  0.1019367991845056,

  /* Expression: 0.51
   * Referenced by: '<S961>/Saturation1'
   */
  0.51,

  /* Expression: -0.51
   * Referenced by: '<S961>/Saturation1'
   */
  -0.51,

  /* Expression: 0
   * Referenced by: '<S1155>/Clamping_zero'
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

  /* Expression: 0
   * Referenced by: '<S721>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S827>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S933>/Constant1'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_a
   * Referenced by: '<S943>/Integrator'
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

  /* Expression: 0
   * Referenced by: '<S721>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_on
   * Referenced by: '<S731>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_jc
   * Referenced by: '<S726>/Filter'
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

  /* Expression: 0
   * Referenced by: '<S827>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_j5
   * Referenced by: '<S837>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_lj
   * Referenced by: '<S832>/Filter'
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
   * Referenced by: '<S933>/Clamping_zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1186>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1186>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1186>/Constant5'
   */
  0.0,

  /* Expression: [1100 1100 1100 1100 0 0]
   * Referenced by: '<S1189>/Constant1'
   */
  { 1100.0, 1100.0, 1100.0, 1100.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S1189>/Gain'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1189>/Switch'
   */
  0.0,

  /* Expression: [1 -1 -1 1; 1 1 1 1; 1 1 -1 -1; 1 -1 1 -1]
   * Referenced by: '<S1190>/Constant'
   */
  { 1.0, 1.0, 1.0, 1.0, -1.0, 1.0, 1.0, -1.0, -1.0, 1.0, -1.0, 1.0, 1.0, 1.0,
    -1.0, -1.0 },

  /* Expression: 0
   * Referenced by: '<S1190>/Constant4'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1191>/Saturation4'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1191>/Saturation4'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1191>/Saturation1'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1191>/Saturation1'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1191>/Saturation2'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1191>/Saturation2'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1191>/Saturation3'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1191>/Saturation3'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1193>/Saturation4'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1193>/Saturation4'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1193>/Saturation1'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1193>/Saturation1'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1193>/Saturation2'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1193>/Saturation2'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1193>/Saturation3'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1193>/Saturation3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/MotorActuatorCommands'
   */
  0.0,

  /* Computed Parameter: Merge_1_InitialOutput
   * Referenced by: '<S1184>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Gain1'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Constant2'
   */
  1000.0,

  /* Computed Parameter: Merge_2_InitialOutput_i
   * Referenced by: '<S1184>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Gain3'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Constant4'
   */
  1000.0,

  /* Computed Parameter: Merge_4_InitialOutput
   * Referenced by: '<S1184>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Gain5'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Constant6'
   */
  1000.0,

  /* Computed Parameter: Merge_3_InitialOutput_i
   * Referenced by: '<S1184>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Gain7'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Constant8'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S1189>/Constant'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1189>/Saturation'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Saturation'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1189>/Saturation1'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Saturation1'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1189>/Saturation2'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Saturation2'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1189>/Saturation3'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Saturation3'
   */
  1000.0,

  /* Computed Parameter: Merge_5_InitialOutput_i
   * Referenced by: '<S1184>/Merge'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1189>/Saturation4'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1189>/Saturation4'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S1189>/Switch1'
   */
  0.0,

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
   * Referenced by: '<S1206>/AER'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1238>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1238>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_ap
   * Referenced by: '<S1248>/Integrator'
   */
  0.005,

  /* Computed Parameter: Filter_gainval_d
   * Referenced by: '<S1243>/Filter'
   */
  0.005,

  /* Expression: 0.3
   * Referenced by: '<S1206>/Saturation2'
   */
  0.3,

  /* Expression: -0.3
   * Referenced by: '<S1206>/Saturation2'
   */
  -0.3,

  /* Expression: -1000
   * Referenced by: '<S1203>/Bias'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1203>/Gain'
   */
  0.001,

  /* Expression: pi/6
   * Referenced by: '<S1203>/Gain1'
   */
  0.52359877559829882,

  /* Expression: -1000
   * Referenced by: '<S1204>/Bias'
   */
  -1000.0,

  /* Expression: 1/1000
   * Referenced by: '<S1204>/Gain'
   */
  0.001,

  /* Expression: pi/9
   * Referenced by: '<S1204>/Gain1'
   */
  0.3490658503988659,

  /* Expression: 1
   * Referenced by: '<S1484>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1484>/Saturation'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1484>/Saturation4'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1484>/Saturation4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1484>/Saturation1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1484>/Saturation1'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1484>/Saturation5'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1484>/Saturation5'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1484>/Saturation2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1484>/Saturation2'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1484>/Saturation6'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1484>/Saturation6'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1484>/Saturation3'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1484>/Saturation3'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S1484>/Saturation7'
   */
  INFINITY,

  /* Expression: 0
   * Referenced by: '<S1484>/Saturation7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1484>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1485>/Constant9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1485>/Constant10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1485>/Constant11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1485>/Constant8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1487>/Constant6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1197>/MotorActuatorCommands'
   */
  0.0,

  /* Computed Parameter: Merge_1_InitialOutput_f
   * Referenced by: '<S1478>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Gain5'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Bias'
   */
  1000.0,

  /* Computed Parameter: Merge_2_InitialOutput_f
   * Referenced by: '<S1478>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Gain6'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Bias1'
   */
  1000.0,

  /* Computed Parameter: Merge_3_InitialOutput_f
   * Referenced by: '<S1478>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Gain7'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Bias2'
   */
  1000.0,

  /* Computed Parameter: Merge_4_InitialOutput_f
   * Referenced by: '<S1478>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Gain8'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Bias3'
   */
  1000.0,

  /* Computed Parameter: Merge_5_InitialOutput_f
   * Referenced by: '<S1478>/Merge'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Gain9'
   */
  1000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Bias4'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S1483>/Constant'
   */
  0.0,

  /* Expression: 2000
   * Referenced by: '<S1483>/Saturation'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Saturation'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1483>/Saturation1'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Saturation1'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1483>/Saturation2'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Saturation2'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1483>/Saturation3'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Saturation3'
   */
  1000.0,

  /* Expression: 2000
   * Referenced by: '<S1483>/Saturation4'
   */
  2000.0,

  /* Expression: 1000
   * Referenced by: '<S1483>/Saturation4'
   */
  1000.0,

  /* Expression: -1500
   * Referenced by: '<S1490>/Bias'
   */
  -1500.0,

  /* Expression: 1/500
   * Referenced by: '<S1490>/Gain'
   */
  0.002,

  /* Computed Parameter: Filter_gainval_h
   * Referenced by: '<S1680>/Filter'
   */
  0.005,

  /* Expression: -1500
   * Referenced by: '<S1488>/Bias'
   */
  -1500.0,

  /* Expression: 1/500
   * Referenced by: '<S1488>/Gain'
   */
  0.002,

  /* Expression: 1
   * Referenced by: '<S1195>/Saturation'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1195>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2677>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2677>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2677>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2677>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2680>/Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2680>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2680>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2680>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2681>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2682>/Constant1'
   */
  0.0,

  /* Expression: [0 0 0]
   * Referenced by: '<S2683>/Constant3'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S2683>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2683>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2683>/Constant'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S2684>/Constant'
   */
  10.0,

  /* Expression: pi
   * Referenced by: '<S2684>/Hdg Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2684>/Hdg Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<S2684>/Yaw Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2684>/Yaw Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S2685>/Constant1'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<S2685>/Hdg Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2685>/Hdg Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: pi
   * Referenced by: '<S2685>/Yaw Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2685>/Yaw Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: 1
   * Referenced by: '<S2686>/Lookahead Distance'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<S2687>/Lookahead Distance'
   */
  5.0,

  /* Expression: pi
   * Referenced by: '<S2688>/Hdg. Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2688>/Hdg. Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S2688>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2688>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2688>/Switch'
   */
  0.0,

  /* Expression: pi
   * Referenced by: '<S2688>/Yaw Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2688>/Yaw Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: 1
   * Referenced by: '<S2688>/Constant2'
   */
  1.0,

  /* Computed Parameter: HoldPositionValue_Y0
   * Referenced by: '<S2701>/HoldPositionValue'
   */
  0.0,

  /* Expression: 6
   * Referenced by: '<S2698>/Constant'
   */
  6.0,

  /* Expression: 1
   * Referenced by: '<S2689>/Lookahead Distance'
   */
  1.0,

  /* Expression: pi
   * Referenced by: '<S2689>/Yaw Cmd Sat'
   */
  3.1415926535897931,

  /* Expression: -pi
   * Referenced by: '<S2689>/Yaw Cmd Sat'
   */
  -3.1415926535897931,

  /* Expression: inf
   * Referenced by: '<S2702>/Saturation'
   */
  INFINITY,

  /* Expression: 0.00001
   * Referenced by: '<S2702>/Saturation'
   */
  1.0E-5,

  /* Expression: 2
   * Referenced by: '<S2689>/Constant1'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S2675>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2675>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2675>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2675>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2676>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2676>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2676>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2676>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2676>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2676>/Constant5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2676>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2676>/Constant6'
   */
  0.0,

  /* Expression: [0;0;0;0]
   * Referenced by: '<S2714>/Constant3'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [0,0,0]
   * Referenced by: '<S2714>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 0.0001924722
   * Referenced by: '<S2713>/AHRS'
   */
  0.0001924722,

  /* Expression: 9.1385e-5
   * Referenced by: '<S2713>/AHRS'
   */
  9.1385E-5,

  /* Expression: 0.1
   * Referenced by: '<S2713>/AHRS'
   */
  0.1,

  /* Expression: 3.0462e-13
   * Referenced by: '<S2713>/AHRS'
   */
  3.0462E-13,

  /* Expression: 0.0096236100000000012
   * Referenced by: '<S2713>/AHRS'
   */
  0.0096236100000000012,

  /* Expression: 0.5
   * Referenced by: '<S2713>/AHRS'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S2713>/AHRS'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S2713>/AHRS'
   */
  0.5,

  /* Expression: 50
   * Referenced by: '<S2713>/AHRS'
   */
  50.0,

  /* Expression: [  0 0 0]
   * Referenced by: '<S2713>/Constant'
   */
  { 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<S6>/Constant'
   */
  1.0,

  /* Expression: pi/180
   * Referenced by: '<S2722>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S2706>/Constant'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S2726>/Gain1'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay6'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay8'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay12'
   */
  0.0,

  /* Expression: 0.005
   * Referenced by: '<S6>/Constant3'
   */
  0.005,

  /* Expression: 1
   * Referenced by: '<S2713>/Gain'
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

  /* Expression: 0
   * Referenced by: '<S2712>/ground'
   */
  0.0,

  /* Computed Parameter: Merge_52_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_53_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_54_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_55_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_56_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_57_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_58_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_59_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_60_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_61_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_62_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_63_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_64_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_51_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_69_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_11_InitialOutput
   * Referenced by: '<S2712>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_12_InitialOutput
   * Referenced by: '<S2712>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_13_InitialOutput
   * Referenced by: '<S2712>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_4_InitialOutput_l
   * Referenced by: '<S2712>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_5_InitialOutput_l
   * Referenced by: '<S2712>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_6_InitialOutput_l
   * Referenced by: '<S2712>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_7_InitialOutput_l
   * Referenced by: '<S2712>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_8_InitialOutput
   * Referenced by: '<S2712>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge_9_InitialOutput_l
   * Referenced by: '<S2712>/Merge'
   */
  0.0,

  /* Expression: pi/180
   * Referenced by: '<S2732>/Gain1'
   */
  0.017453292519943295,

  /* Expression: pi/180
   * Referenced by: '<S2732>/Gain'
   */
  0.017453292519943295,

  /* Expression: 0
   * Referenced by: '<S2732>/Constant1'
   */
  0.0,

  /* Expression: flightState.Transition
   * Referenced by: '<S1703>/Constant'
   */
  Transition,

  /* Expression: flightState.BackTransition
   * Referenced by: '<S1703>/Constant1'
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
   * Referenced by: '<S1195>/Constant'
   */
  Transition,

  /* Expression: flightState.BackTransition
   * Referenced by: '<S1195>/Constant1'
   */
  BackTransition,

  /* Computed Parameter: UnitDelay_8_InitialCondition
   * Referenced by: '<S2677>/Unit Delay'
   */
  Hover,

  /* Computed Parameter: UnitDelay_8_InitialCondition_d
   * Referenced by: '<S2675>/Unit Delay'
   */
  Hover,

  /* Computed Parameter: UnitDelay_8_InitialCondition_l
   * Referenced by: '<S2676>/Unit Delay'
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
   * Referenced by: '<S2118>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S2119>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_ga
   * Referenced by: '<S2673>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_hg
   * Referenced by: '<S2674>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_dq
   * Referenced by: '<S2675>/Constant'
   */
  false,

  /* Computed Parameter: Constant_Value_jf
   * Referenced by: '<S1746>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_h3
   * Referenced by: '<S1746>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_c
   * Referenced by: '<S1746>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_c
   * Referenced by: '<S1746>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_mm
   * Referenced by: '<S2086>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_lk
   * Referenced by: '<S2086>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_h
   * Referenced by: '<S2086>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_in
   * Referenced by: '<S2086>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_pl
   * Referenced by: '<S2537>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_ah
   * Referenced by: '<S2537>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_p
   * Referenced by: '<S2537>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_m
   * Referenced by: '<S2537>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_nq
   * Referenced by: '<S2643>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_g
   * Referenced by: '<S2643>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_od
   * Referenced by: '<S2643>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_h
   * Referenced by: '<S2643>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_fs
   * Referenced by: '<S224>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_c
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
   * Referenced by: '<S608>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_f2
   * Referenced by: '<S608>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_d
   * Referenced by: '<S608>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_he
   * Referenced by: '<S608>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_m0
   * Referenced by: '<S721>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_c5
   * Referenced by: '<S721>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_du
   * Referenced by: '<S721>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_ce
   * Referenced by: '<S721>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_lj
   * Referenced by: '<S827>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_b
   * Referenced by: '<S827>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_g
   * Referenced by: '<S827>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_hs
   * Referenced by: '<S827>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_ae
   * Referenced by: '<S933>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_k
   * Referenced by: '<S933>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_cl
   * Referenced by: '<S933>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_d
   * Referenced by: '<S933>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_ln
   * Referenced by: '<S1049>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_d
   * Referenced by: '<S1049>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_k5
   * Referenced by: '<S1049>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_dz
   * Referenced by: '<S1049>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_al
   * Referenced by: '<S1155>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_bh
   * Referenced by: '<S1155>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_ae
   * Referenced by: '<S1155>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_o
   * Referenced by: '<S1155>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_pe
   * Referenced by: '<S1238>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_bo
   * Referenced by: '<S1238>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_aq
   * Referenced by: '<S1238>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_jz
   * Referenced by: '<S1238>/Constant4'
   */
  -1,

  /* Computed Parameter: Gain1_Gain_ms
   * Referenced by: '<S1703>/Gain1'
   */
  MIN_int8_T,

  /* Computed Parameter: Gain1_Gain_dg
   * Referenced by: '<S1195>/Gain1'
   */
  MIN_int8_T,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S1703>/Discrete-Time Integrator'
   */
  0,

  /* Computed Parameter: DiscreteTimeIntegrator_IC_l
   * Referenced by: '<S1195>/Discrete-Time Integrator'
   */
  0,

  /* Computed Parameter: Gain_Gain_ck
   * Referenced by: '<S1703>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<S1195>/Gain'
   */
  128U,

  /* Computed Parameter: UnitDelay_InitialCondition_l
   * Referenced by: '<S2127>/Unit Delay'
   */
  0U,

  /* Computed Parameter: Switch_Threshold_g
   * Referenced by: '<S1998>/Switch'
   */
  0U,

  /* Computed Parameter: Switch_Threshold_c
   * Referenced by: '<S1485>/Switch'
   */
  0U,

  /* Computed Parameter: Switch1_Threshold_a
   * Referenced by: '<S1485>/Switch1'
   */
  0U,

  /* Computed Parameter: Switch2_Threshold
   * Referenced by: '<S1485>/Switch2'
   */
  0U,

  /* Computed Parameter: Switch4_Threshold
   * Referenced by: '<S1485>/Switch4'
   */
  0U,

  /* Computed Parameter: UnitDelay_9_InitialCondition
   * Referenced by: '<S2677>/Unit Delay'
   */
  0U,

  /* Computed Parameter: Constant3_Value_f
   * Referenced by: '<S2677>/Constant3'
   */
  0U,

  /* Computed Parameter: Constant3_Value_az
   * Referenced by: '<S2684>/Constant3'
   */
  0U,

  /* Computed Parameter: Constant3_Value_ph
   * Referenced by: '<S2685>/Constant3'
   */
  0U,

  /* Computed Parameter: Constant_Value_j5
   * Referenced by: '<S2686>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_gm
   * Referenced by: '<S2688>/Constant'
   */
  0U,

  /* Computed Parameter: UnitDelay_9_InitialCondition_d
   * Referenced by: '<S2675>/Unit Delay'
   */
  0U,

  /* Computed Parameter: UnitDelay_9_InitialCondition_l
   * Referenced by: '<S2676>/Unit Delay'
   */
  0U,

  /* Computed Parameter: Constant3_Value_pj
   * Referenced by: '<S2676>/Constant3'
   */
  0U,

  /* Computed Parameter: Constant_Value_av
   * Referenced by: '<S2714>/Constant'
   */
  0U,

  /* Computed Parameter: IC_Value_h
   * Referenced by: '<S2714>/IC'
   */
  1U,

  /* Computed Parameter: Constant2_Value_fj
   * Referenced by: '<S2714>/Constant2'
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
   * Referenced by: '<S2712>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_65_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_66_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0U,

  /* Computed Parameter: Merge_67_InitialOutput
   * Referenced by: '<S1>/Merge'
   */
  0U,

  /* Start of '<S2712>/Emergency' */
  {
    /* Expression: 	struct('mode', uint8(0), 'position', zeros(3,1), 'params', zeros(4,1))
     * Referenced by: '<S2715>/Constant1'
     */
    {
      0U,

      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    },

    /* Expression: 	struct('mode', uint8(0), 'position', zeros(3,1), 'params', zeros(4,1))
     * Referenced by: '<S2715>/Constant2'
     */
    {
      0U,

      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    },

    /* Computed Parameter: Constant3_Value
     * Referenced by: '<S2715>/Constant3'
     */
    0U
  }
  ,

  /* End of '<S2712>/Emergency' */

  /* Start of '<S2712>/Switch Case Action Subsystem' */
  {
    /* Expression: 	struct('mode', uint8(0), 'position', zeros(3,1), 'params', zeros(4,1))
     * Referenced by: '<S2716>/Constant1'
     */
    {
      0U,

      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    },

    /* Expression: 	struct('mode', uint8(0), 'position', zeros(3,1), 'params', zeros(4,1))
     * Referenced by: '<S2716>/Constant2'
     */
    {
      0U,

      { 0.0, 0.0, 0.0 },

      { 0.0, 0.0, 0.0, 0.0 }
    },

    /* Computed Parameter: Constant3_Value
     * Referenced by: '<S2716>/Constant3'
     */
    0U
  }
  ,

  /* End of '<S2712>/Switch Case Action Subsystem' */

  /* Start of '<S1478>/Switch Case Action Subsystem2' */
  {
    /* Expression: Inf
     * Referenced by: '<S1486>/Saturation2'
     */
    INFINITY,

    /* Expression: 0
     * Referenced by: '<S1486>/Saturation2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1486>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1486>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1486>/Constant3'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1486>/Constant4'
     */
    0.0
  }
  ,

  /* End of '<S1478>/Switch Case Action Subsystem2' */

  /* Start of '<S1477>/Switch Case Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S1482>/Constant'
     */
    0.0,

    /* Expression: -0.7
     * Referenced by: '<S1482>/Constant1'
     */
    -0.7,

    /* Expression: 0
     * Referenced by: '<S1482>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1482>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1477>/Switch Case Action Subsystem3' */

  /* Start of '<S1477>/Switch Case Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S1480>/Constant'
     */
    0.0,

    /* Expression: -0.2
     * Referenced by: '<S1480>/Constant1'
     */
    -0.2,

    /* Expression: 0
     * Referenced by: '<S1480>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1480>/Constant3'
     */
    0.0,

    /* Computed Parameter: Switch_Threshold
     * Referenced by: '<S1480>/Switch'
     */
    0U
  }
  ,

  /* End of '<S1477>/Switch Case Action Subsystem1' */

  /* Start of '<S1477>/Switch Case Action Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S1479>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1479>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1479>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1479>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1477>/Switch Case Action Subsystem' */

  /* Start of '<S1184>/Switch Case Action Subsystem2' */
  {
    /* Expression: Inf
     * Referenced by: '<S1192>/Saturation2'
     */
    INFINITY,

    /* Expression: 0
     * Referenced by: '<S1192>/Saturation2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1192>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1192>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1192>/Constant3'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1192>/Constant4'
     */
    0.0
  }
  ,

  /* End of '<S1184>/Switch Case Action Subsystem2' */

  /* Start of '<S1183>/Switch Case Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S1188>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1188>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1188>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1188>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1183>/Switch Case Action Subsystem3' */

  /* Start of '<S1183>/Switch Case Action Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S1185>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1185>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1185>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1185>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1183>/Switch Case Action Subsystem' */

  /* Start of '<S1985>/Switch Case Action Subsystem3' */
  {
    /* Expression: 0
     * Referenced by: '<S1990>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1990>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1990>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1990>/Constant3'
     */
    0.0
  }
  ,

  /* End of '<S1985>/Switch Case Action Subsystem3' */

  /* Start of '<S1985>/Switch Case Action Subsystem1' */
  {
    /* Expression: 0
     * Referenced by: '<S1988>/Constant'
     */
    0.0,

    /* Expression: -0.2
     * Referenced by: '<S1988>/Constant1'
     */
    -0.2,

    /* Expression: 0
     * Referenced by: '<S1988>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1988>/Constant3'
     */
    0.0,

    /* Computed Parameter: Switch_Threshold
     * Referenced by: '<S1988>/Switch'
     */
    0U
  }
  ,

  /* End of '<S1985>/Switch Case Action Subsystem1' */

  /* Start of '<S1985>/Switch Case Action Subsystem' */
  {
    /* Expression: 0
     * Referenced by: '<S1987>/Constant'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1987>/Constant1'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1987>/Constant2'
     */
    0.0,

    /* Expression: 0
     * Referenced by: '<S1987>/Constant3'
     */
    0.0
  }
  /* End of '<S1985>/Switch Case Action Subsystem' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
