/*
 * UAM_Flight_control_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UAM_Flight_control".
 *
 * Model version              : 1.641
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Wed Feb 11 09:43:02 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(struct_juMyODevdATMAXR3fdAKoC),
  sizeof(struct_JA0PJPSn0btjrHlwEkzrx),
  sizeof(struct_jpltDuhjXnkWn1F7DEW2qE),
  sizeof(int32_T),
  sizeof(FCCData),
  sizeof(RotorParameters),
  sizeof(HoverSPBus),
  sizeof(FixedWingCommandBus),
  sizeof(AAC),
  sizeof(controlMode),
  sizeof(flightState),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(FlightModeType),
  sizeof(struct_nGmILHkzXdduNopEcCRSWH),
  sizeof(struct_Kqzfdh58y3XYM0g99APC8B),
  sizeof(struct_u2xOoEtpHkUtzKIxOOJ85F),
  sizeof(struct_SLaD3ZMLgBBWFjFkkitV0C),
  sizeof(FixedWingCtrlBus),
  sizeof(int32_T),
  sizeof(UAVPathManagerBus),
  sizeof(int32_T),
  sizeof(GuidanceStates),
  sizeof(int32_T),
  sizeof(GdncModeType),
  sizeof(innerLoopCmdsBus),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int8_T),
  sizeof(int8_T),
  sizeof(struct_CFqOEKcDN97DaWV6hJRmHG),
  sizeof(uint8_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(uav_sluav_internal_system_Orb_T),
  sizeof(uav_sluav_internal_system_Way_T),
  sizeof(uav_sluav_internal_system_W_b_T),
  sizeof(uav_sluav_internal_system__by_T),
  sizeof(uav_sluav_internal_system_Pat_T),
  sizeof(fusion_simulink_ahrsfilter_UA_T),
  sizeof(robotics_slcore_internal_bloc_T),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "struct_juMyODevdATMAXR3fdAKoC",
  "struct_JA0PJPSn0btjrHlwEkzrx",
  "struct_jpltDuhjXnkWn1F7DEW2qE",
  "struct_HFRMOmsKyFuoYmgZlAonvH",
  "FCCData",
  "RotorParameters",
  "HoverSPBus",
  "FixedWingCommandBus",
  "AAC",
  "controlMode",
  "flightState",
  "flightmode",
  "StateBus",
  "FlightModeType",
  "struct_nGmILHkzXdduNopEcCRSWH",
  "struct_Kqzfdh58y3XYM0g99APC8B",
  "struct_u2xOoEtpHkUtzKIxOOJ85F",
  "struct_SLaD3ZMLgBBWFjFkkitV0C",
  "FixedWingCtrlBus",
  "controller",
  "UAVPathManagerBus",
  "plan",
  "GuidanceStates",
  "states",
  "GdncModeType",
  "innerLoopCmdsBus",
  "struct_1uxWHtYfonJTQO4Z8sRsOG",
  "struct_wMr8ZgEArq0DOWLfj2pgjF",
  "sensorData",
  "struct_VpmgNg7cgSsEJdfj19JRpF",
  "GNCplan",
  "struct_nPRdhXQndS6c8T0fncT7vE",
  "int8_T",
  "uint8_T",
  "int8_T",
  "int8_T",
  "struct_CFqOEKcDN97DaWV6hJRmHG",
  "uint8_T",
  "int32_T",
  "struct_KkiPXJ3uuuYoh4Y94sckED",
  "struct_nmenKdWTRXbFr0Rmzr6rUB",
  "uav_sluav_internal_system_Orb_T",
  "uav_sluav_internal_system_Way_T",
  "uav_sluav_internal_system_W_b_T",
  "uav_sluav_internal_system__by_T",
  "uav_sluav_internal_system_Pat_T",
  "fusion_simulink_ahrsfilter_UA_T",
  "robotics_slcore_internal_bloc_T",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&UAM_Flight_control_B.BusConversion_InsertedFor_Basic), 39, 0, 3
  },

  { (char_T *)(&UAM_Flight_control_B.FromWP), 37, 0, 4 },

  { (char_T *)(&UAM_Flight_control_B.InnerLoopCmds), 42, 0, 1 },

  { (char_T *)(&UAM_Flight_control_B.RotorParameters_g), 22, 0, 1 },

  { (char_T *)(&UAM_Flight_control_B.AACSP), 25, 0, 2 },

  { (char_T *)(&UAM_Flight_control_B.HoverSPBUS), 23, 0, 1 },

  { (char_T *)(&UAM_Flight_control_B.CtrlSurfaceCommands), 35, 0, 7 },

  { (char_T *)(&UAM_Flight_control_B.FixedWingSP), 24, 0, 2 },

  { (char_T *)(&UAM_Flight_control_B.controlMode_h), 26, 0, 4 },

  { (char_T *)(&UAM_Flight_control_B.GPSCourse), 0, 0, 551 },

  { (char_T *)(&UAM_Flight_control_B.target_roll), 1, 0, 55 },

  { (char_T *)(&UAM_Flight_control_B.FlightMode), 27, 0, 7 },

  { (char_T *)(&UAM_Flight_control_B.voltage), 4, 0, 20 },

  { (char_T *)(&UAM_Flight_control_B.mode), 3, 0, 23 },

  { (char_T *)(&UAM_Flight_control_B.DataTypeConversion), 8, 0, 15 }
  ,

  { (char_T *)(&UAM_Flight_control_DW.obj), 63, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.obj_b), 60, 0, 2 },

  { (char_T *)(&UAM_Flight_control_DW.obj_p), 61, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.obj_c), 62, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.obj_h), 59, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.obj_o), 58, 0, 2 },

  { (char_T *)(&UAM_Flight_control_DW.UnitDelay_3_DSTATE), 37, 0, 2 },

  { (char_T *)(&UAM_Flight_control_DW.UnitDelay1_7_DSTATE), 22, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.UnitDelay_6_DSTATE), 25, 0, 3 },

  { (char_T *)(&UAM_Flight_control_DW.RateTransition1_13_Buffer), 22, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.UnitDelay_5_DSTATE), 24, 0, 3 },

  { (char_T *)(&UAM_Flight_control_DW.UnitDelay_7_DSTATE), 26, 0, 3 },

  { (char_T *)(&UAM_Flight_control_DW.UnitDelay2_DSTATE), 0, 0, 1853 },

  { (char_T *)(&UAM_Flight_control_DW.ToWorkspace_PWORK.LoggedData), 11, 0, 13 },

  { (char_T *)(&UAM_Flight_control_DW.UnitDelay_8_DSTATE), 27, 0, 3 },

  { (char_T *)(&UAM_Flight_control_DW.is_c1_UAM_Flight_control), 7, 0, 12 },

  { (char_T *)(&UAM_Flight_control_DW.temporalCounter_i1), 5, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.UnitDelay_1_DSTATE_e), 3, 0, 5 },

  { (char_T *)(&UAM_Flight_control_DW.DelayInput1_DSTATE), 8, 0, 4 },

  { (char_T *)(&UAM_Flight_control_DW.DiscreteTimeIntegrator_DSTATE), 52, 0, 71
  },

  { (char_T *)(&UAM_Flight_control_DW.last_arm), 3, 0, 6 },

  { (char_T *)(&UAM_Flight_control_DW.init), 8, 0, 18 },

  { (char_T *)
    (&UAM_Flight_control_DW.Emergency_b.SwitchCaseActionSubsystem_Subsy), 2, 0,
    1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem2_n.SwitchCaseActionSubsystem2_Subs),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem3_g.SwitchCaseActionSubsystem_Subsy),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem2_c.SwitchCaseActionSubsystem2_Subs),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem1_m.SwitchCaseActionSubsystem1_Subs),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem_e.SwitchCaseActionSubsystem_Subsy),
    2, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_j.sfEvent), 6, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_j.doneDoubleBufferReInit),
    8, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_er.sfEvent), 6, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.sf_MATLABFunction_er.doneDoubleBufferReInit), 8, 0,
    1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem2_g.SwitchCaseActionSubsystem2_Subs),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem3_j.SwitchCaseActionSubsystem_Subsy),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem_o.SwitchCaseActionSubsystem_Subsy),
    2, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_g.sfEvent), 6, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_g.doneDoubleBufferReInit),
    8, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_cg.sfEvent), 6, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.sf_MATLABFunction_cg.doneDoubleBufferReInit), 8, 0,
    1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction1_g.sfEvent), 6, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.sf_MATLABFunction1_g.doneDoubleBufferReInit), 8, 0,
    1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_b.sfEvent), 6, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_b.doneDoubleBufferReInit),
    8, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem3.SwitchCaseActionSubsystem_Subsy),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem2_f.SwitchCaseActionSubsystem2_Subs),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem1_e.SwitchCaseActionSubsystem1_Subs),
    2, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_DW.SwitchCaseActionSubsystem_kk.SwitchCaseActionSubsystem_Subsy),
    2, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_a.sfEvent), 6, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_a.doneDoubleBufferReInit),
    8, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_c.sfEvent), 6, 0, 1 },

  { (char_T *)(&UAM_Flight_control_DW.sf_MATLABFunction_c.doneDoubleBufferReInit),
    8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  67U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&UAM_Flight_control_P.controlParams), 19, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.uavParam), 34, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.control), 18, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.FWControlParams), 17, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Cruise_a), 0, 0, 5 },

  { (char_T *)(&UAM_Flight_control_P.FSState), 27, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.PitchAngleController_InitialCon), 0, 0, 108
  },

  { (char_T *)(&UAM_Flight_control_P.DetectRisePositive_vinit), 8, 0, 4 },

  { (char_T *)(&UAM_Flight_control_P.CompareToConstant_const_a), 3, 0, 10 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_3_InitialCondition), 37, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_2_InitialCondition), 37, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Waypoints2_Value[0]), 37, 0, 10 },

  { (char_T *)(&UAM_Flight_control_P.Merge_2_InitialOutput), 37, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Merge_3_InitialOutput), 37, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_6_InitialCondition), 25, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Constant2_Value), 25, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_6_InitialCondition_l), 25, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_6_InitialCondition_lw), 25, 0, 1
  },

  { (char_T *)(&UAM_Flight_control_P.Constant2_Value_i), 25, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Merge_6_InitialOutput), 25, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay1_7_InitialCondition), 22, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Merge_10_InitialOutput), 22, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.MixerCommands_Y0), 53, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.MixerCommands_Y0_b), 53, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.MixerCommands_Y0_e), 53, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Actuator_Outport_1_Y0), 22, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Actuator_Outport_1_Y0_d), 22, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Actuator_Outport_1_Y0_d1), 22, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Actuator_Outport_1_Y0_d1t), 22, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_5_InitialCondition), 24, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Constant1_Value), 24, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_5_InitialCondition_l), 24, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_5_InitialCondition_lw), 24, 0, 1
  },

  { (char_T *)(&UAM_Flight_control_P.Constant1_Value_f), 24, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Merge_5_InitialOutput), 24, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.CtrlSurfaceCommands_Y0), 35, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Merge_InitialOutput), 35, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.CtrlSurfaceCommands_Y0_a), 35, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Merge_InitialOutput_i), 35, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.CtrlSurfaceCommands_Y0_k), 35, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Merge_InitialOutput_g), 35, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Merge_52_InitialOutput), 35, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Actuator_Y0), 35, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Actuator_Y0_a), 35, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_7_InitialCondition), 26, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_7_InitialCondition_l), 26, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.UnitDelay_7_InitialCondition_lw), 26, 0, 1
  },

  { (char_T *)(&UAM_Flight_control_P.Merge_7_InitialOutput), 26, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.AER_Y0), 0, 0, 512 },

  { (char_T *)(&UAM_Flight_control_P.Constant_Value_ne), 27, 0, 10 },

  { (char_T *)(&UAM_Flight_control_P.Merge_5_InitialOutput_e), 1, 0, 13 },

  { (char_T *)(&UAM_Flight_control_P.Merge_40_InitialOutput), 4, 0, 5 },

  { (char_T *)(&UAM_Flight_control_P.Constant_Value_hf), 8, 0, 5 },

  { (char_T *)(&UAM_Flight_control_P.Constant_Value_jf), 2, 0, 28 },

  { (char_T *)(&UAM_Flight_control_P.Gain_Gain_ck), 50, 0, 26 },

  { (char_T *)(&UAM_Flight_control_P.Emergency_b.Constant1_Value), 37, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Emergency_b.Constant2_Value), 37, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.Emergency_b.Constant3_Value), 3, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem.Constant1_Value),
    37, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem.Constant2_Value),
    37, 0, 1 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem.Constant3_Value),
    3, 0, 1 },

  { (char_T *)
    (&UAM_Flight_control_P.SwitchCaseActionSubsystem2_n.Saturation2_UpperSat), 0,
    0, 6 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem3_g.Constant_Value),
    0, 0, 4 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Constant_Value),
    0, 0, 4 },

  { (char_T *)
    (&UAM_Flight_control_P.SwitchCaseActionSubsystem1_m.Switch_Threshold), 3, 0,
    1 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem_e.Constant_Value),
    0, 0, 4 },

  { (char_T *)
    (&UAM_Flight_control_P.SwitchCaseActionSubsystem2_g.Saturation2_UpperSat), 0,
    0, 6 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem3_j.Constant_Value),
    0, 0, 4 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem_o.Constant_Value),
    0, 0, 4 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem3.Constant_Value),
    0, 0, 4 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Constant_Value),
    0, 0, 4 },

  { (char_T *)
    (&UAM_Flight_control_P.SwitchCaseActionSubsystem1_e.Switch_Threshold), 3, 0,
    1 },

  { (char_T *)(&UAM_Flight_control_P.SwitchCaseActionSubsystem_kk.Constant_Value),
    0, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  73U,
  rtPTransitions
};

/* [EOF] UAM_Flight_control_dt.h */
