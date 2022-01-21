/*
 * liner_control_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "liner_control".
 *
 * Model version              : 1.127
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Jan 21 09:42:26 2022
 *
 * Target selection: sbox2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "liner_control_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "liner_control.h"
#include "liner_control_capi.h"
#include "liner_control_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 2, TARGET_STRING("liner_control/friction compensation by matlab"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 3, TARGET_STRING("liner_control/friction compensation by matlab1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("liner_control/Constant1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("liner_control/Discrete-Time Integrator"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("liner_control/Discrete-Time Integrator1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("liner_control/Pulse Generator"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 6, 0, TARGET_STRING("liner_control/From Workspace"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 7, 0, TARGET_STRING("liner_control/From Workspace1"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 8, 0, TARGET_STRING("liner_control/Gain"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("liner_control/X_control_switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 1, TARGET_STRING("liner_control/X_feedback_manual_switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("liner_control/X_fric_comp_switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("liner_control/X_gain_D"),
    TARGET_STRING("X_input_volt_control"), 0, 0, 0, 0, 0 },

  { 13, 0, TARGET_STRING("liner_control/X_gain_I"),
    TARGET_STRING("input_volt_control"), 0, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING("liner_control/X_gain_P"),
    TARGET_STRING("X_input_volt_control"), 0, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("liner_control/X_manual_switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 16, 0, TARGET_STRING("liner_control/Y1_control_switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("liner_control/Y1_fric_comp_switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 18, 0, TARGET_STRING("liner_control/Y1_gain_D"),
    TARGET_STRING("X_input_volt_control"), 0, 0, 0, 0, 0 },

  { 19, 0, TARGET_STRING("liner_control/Y1_gain_I"),
    TARGET_STRING("input_volt_control"), 0, 0, 0, 0, 0 },

  { 20, 0, TARGET_STRING("liner_control/Y1_gain_P"),
    TARGET_STRING("X_input_volt_control"), 0, 0, 0, 0, 0 },

  { 21, 0, TARGET_STRING("liner_control/Y1_manual_switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 22, 0, TARGET_STRING("liner_control/to mm"),
    TARGET_STRING("X_position"), 0, 0, 0, 0, 0 },

  { 23, 0, TARGET_STRING("liner_control/to mm1"),
    TARGET_STRING("X_position"), 0, 0, 0, 0, 0 },

  { 24, 0, TARGET_STRING("liner_control/Saturation"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 25, 0, TARGET_STRING("liner_control/Saturation1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 26, 0, TARGET_STRING("liner_control/Sum"),
    TARGET_STRING("X_e_position"), 0, 0, 0, 0, 0 },

  { 27, 0, TARGET_STRING("liner_control/Sum1"),
    TARGET_STRING("X_input_volt"), 0, 0, 0, 0, 0 },

  { 28, 0, TARGET_STRING("liner_control/Sum10"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 29, 0, TARGET_STRING("liner_control/Sum2"),
    TARGET_STRING("X_control_input_volt"), 0, 0, 0, 0, 0 },

  { 30, 0, TARGET_STRING("liner_control/Sum3"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 31, 0, TARGET_STRING("liner_control/Sum4"),
    TARGET_STRING("X_e_position"), 0, 0, 0, 0, 0 },

  { 32, 0, TARGET_STRING("liner_control/Sum5"),
    TARGET_STRING("X_input_volt"), 0, 0, 0, 0, 0 },

  { 33, 0, TARGET_STRING("liner_control/Sum6"),
    TARGET_STRING("X_control_input_volt"), 0, 0, 0, 0, 0 },

  { 34, 0, TARGET_STRING("liner_control/Sum7"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 35, 0, TARGET_STRING("liner_control/Sum9"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 36, 0, TARGET_STRING("liner_control/Manual Switch"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 37, 0, TARGET_STRING("liner_control/DinamicFriction/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 38, 0, TARGET_STRING("liner_control/DinamicFriction/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 39, 0, TARGET_STRING("liner_control/DinamicFriction/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 40, 0, TARGET_STRING("liner_control/Discrete Derivative1/Diff"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 41, 0, TARGET_STRING("liner_control/Discrete Derivative1/TSamp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 42, 0, TARGET_STRING("liner_control/Discrete Derivative1/UD"),
    TARGET_STRING("U(k-1)"), 0, 0, 0, 0, 0 },

  { 43, 0, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING(""), 0, 0, 2, 0, 0 },

  { 44, 0, TARGET_STRING("liner_control/SBOX2_DAM148 /DAC"),
    TARGET_STRING(""), 0, 0, 3, 0, 0 },

  { 45, 0, TARGET_STRING("liner_control/SBOX2_DATA_SAVE_NET/data_ch"),
    TARGET_STRING(""), 0, 0, 3, 0, 0 },

  { 46, 0, TARGET_STRING("liner_control/SBOX2_GRAPH_MONITOR/input_ch"),
    TARGET_STRING(""), 0, 0, 3, 0, 0 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 47, TARGET_STRING("liner_control/DinamicFriction"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 48, TARGET_STRING("liner_control/Discrete Derivative1"),
    TARGET_STRING("ICPrevScaledInput"), 0, 0, 0 },

  { 49, TARGET_STRING("liner_control/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 50, TARGET_STRING("liner_control/Constant1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 51, TARGET_STRING("liner_control/X_CART_VELOCITY_THRESHOLD"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 52, TARGET_STRING("liner_control/X_INPUT_TORQUE_THRESHOLD"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 53, TARGET_STRING("liner_control/X_MAX_DYNAMIC_FRIC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 54, TARGET_STRING("liner_control/X_MAX_STATIC_FRIC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 55, TARGET_STRING("liner_control/X_feedback_manualVolt"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 56, TARGET_STRING("liner_control/X_manual_volt"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 57, TARGET_STRING("liner_control/Y1_CART_VELOCITY_THRESHOLD"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 58, TARGET_STRING("liner_control/Y1_INPUT_TORQUE_THRESHOLD"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 59, TARGET_STRING("liner_control/Y1_MAX_DYNAMIC_FRIC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 60, TARGET_STRING("liner_control/Y1_MAX_STATIC_FRIC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 61, TARGET_STRING("liner_control/Y1_manual_volt1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 62, TARGET_STRING("liner_control/integrate_reset"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 63, TARGET_STRING("liner_control/integrate_reset1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 64, TARGET_STRING("liner_control/Discrete-Time Integrator"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 65, TARGET_STRING("liner_control/Discrete-Time Integrator"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 66, TARGET_STRING("liner_control/Discrete-Time Integrator1"),
    TARGET_STRING("gainval"), 0, 0, 0 },

  { 67, TARGET_STRING("liner_control/Discrete-Time Integrator1"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 68, TARGET_STRING("liner_control/Pulse Generator"),
    TARGET_STRING("Amplitude"), 0, 0, 0 },

  { 69, TARGET_STRING("liner_control/Pulse Generator"),
    TARGET_STRING("Period"), 0, 0, 0 },

  { 70, TARGET_STRING("liner_control/Pulse Generator"),
    TARGET_STRING("PulseWidth"), 0, 0, 0 },

  { 71, TARGET_STRING("liner_control/Pulse Generator"),
    TARGET_STRING("PhaseDelay"), 0, 0, 0 },

  { 72, TARGET_STRING("liner_control/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 73, TARGET_STRING("liner_control/X_control_switch"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 74, TARGET_STRING("liner_control/X_feedback_manual_switch1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 75, TARGET_STRING("liner_control/X_fric_comp_switch"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 76, TARGET_STRING("liner_control/X_gain_D"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 77, TARGET_STRING("liner_control/X_gain_I"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 78, TARGET_STRING("liner_control/X_gain_P"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 79, TARGET_STRING("liner_control/X_manual_switch"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 80, TARGET_STRING("liner_control/Y1_control_switch"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 81, TARGET_STRING("liner_control/Y1_fric_comp_switch"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 82, TARGET_STRING("liner_control/Y1_gain_D"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 83, TARGET_STRING("liner_control/Y1_gain_I"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 84, TARGET_STRING("liner_control/Y1_gain_P"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 85, TARGET_STRING("liner_control/Y1_manual_switch1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 86, TARGET_STRING("liner_control/to mm"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 87, TARGET_STRING("liner_control/to mm1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 88, TARGET_STRING("liner_control/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 89, TARGET_STRING("liner_control/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 90, TARGET_STRING("liner_control/Saturation1"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 91, TARGET_STRING("liner_control/Saturation1"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 92, TARGET_STRING("liner_control/Manual Switch"),
    TARGET_STRING("CurrentSetting"), 1, 0, 0 },

  { 93, TARGET_STRING("liner_control/DinamicFriction/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 94, TARGET_STRING("liner_control/Discrete Derivative1/TSamp"),
    TARGET_STRING("WtEt"), 0, 0, 0 },

  { 95, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 96, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 97, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 98, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 99, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 100, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 101, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 102, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 103, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 104, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 105, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 106, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P12"), 0, 0, 0 },

  { 107, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P13"), 0, 0, 0 },

  { 108, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P14"), 0, 0, 0 },

  { 109, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P15"), 0, 0, 0 },

  { 110, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P16"), 0, 0, 0 },

  { 111, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P17"), 0, 0, 0 },

  { 112, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P18"), 0, 0, 0 },

  { 113, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P19"), 0, 0, 0 },

  { 114, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P20"), 0, 0, 0 },

  { 115, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P21"), 0, 0, 0 },

  { 116, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P22"), 0, 0, 0 },

  { 117, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P23"), 0, 0, 0 },

  { 118, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P24"), 0, 0, 0 },

  { 119, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P25"), 0, 0, 0 },

  { 120, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P26"), 0, 0, 0 },

  { 121, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P27"), 0, 0, 0 },

  { 122, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P28"), 0, 0, 0 },

  { 123, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P29"), 0, 0, 0 },

  { 124, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P30"), 0, 0, 0 },

  { 125, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P31"), 0, 0, 0 },

  { 126, TARGET_STRING("liner_control/SBOX2_CNT6/icounter"),
    TARGET_STRING("P32"), 0, 0, 0 },

  { 127, TARGET_STRING("liner_control/SBOX2_DAM148 /DAC"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 128, TARGET_STRING("liner_control/SBOX2_DAM148 /DAC"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 129, TARGET_STRING("liner_control/SBOX2_DAM148 /dac"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 130, TARGET_STRING("liner_control/SBOX2_DAM148 /dac"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 131, TARGET_STRING("liner_control/SBOX2_DAM148 /dac"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 132, TARGET_STRING("liner_control/SBOX2_DAM148 /dac"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 133, TARGET_STRING("liner_control/SBOX2_DAM148 /dac"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 134, TARGET_STRING("liner_control/SBOX2_DAM148 /dac"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 135, TARGET_STRING("liner_control/SBOX2_DAM148 /dac"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 136, TARGET_STRING("liner_control/SBOX2_DAM148 /dac"),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 137, TARGET_STRING("liner_control/SBOX2_DAM148 /dac"),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 138, TARGET_STRING("liner_control/SBOX2_DATA_SAVE_NET/data_ch"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 139, TARGET_STRING("liner_control/SBOX2_DATA_SAVE_NET/to_memory_rt"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 140, TARGET_STRING("liner_control/SBOX2_DATA_SAVE_NET/to_memory_rt"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 141, TARGET_STRING("liner_control/SBOX2_DATA_SAVE_NET/to_memory_rt"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 142, TARGET_STRING("liner_control/SBOX2_DATA_SAVE_NET/to_memory_rt"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 143, TARGET_STRING("liner_control/SBOX2_GRAPH_MONITOR/input_ch"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 144, TARGET_STRING("liner_control/SBOX2_GRAPH_MONITOR/to_host_rt"),
    TARGET_STRING("P1"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &liner_control_B.sf_frictioncompensationbymatlab.input_fric_compen,/* 0: Signal */
  &liner_control_B.sf_frictioncompensationbymatl_o.input_fric_compen,/* 1: Signal */
  &liner_control_B.Constant1,          /* 2: Signal */
  &liner_control_B.DiscreteTimeIntegrator,/* 3: Signal */
  &liner_control_B.DiscreteTimeIntegrator1,/* 4: Signal */
  &liner_control_B.PulseGenerator,     /* 5: Signal */
  &liner_control_B.FromWorkspace[0],   /* 6: Signal */
  &liner_control_B.FromWorkspace1[0],  /* 7: Signal */
  &liner_control_B.Gain,               /* 8: Signal */
  &liner_control_B.X_control_switch,   /* 9: Signal */
  &liner_control_B.X_feedback_manual_switch1,/* 10: Signal */
  &liner_control_B.X_fric_comp_switch, /* 11: Signal */
  &liner_control_B.X_input_volt_control_a,/* 12: Signal */
  &liner_control_B.input_volt_control, /* 13: Signal */
  &liner_control_B.X_input_volt_control,/* 14: Signal */
  &liner_control_B.X_manual_switch,    /* 15: Signal */
  &liner_control_B.Y1_control_switch,  /* 16: Signal */
  &liner_control_B.Y1_fric_comp_switch,/* 17: Signal */
  &liner_control_B.X_input_volt_control_n,/* 18: Signal */
  &liner_control_B.input_volt_control_k,/* 19: Signal */
  &liner_control_B.X_input_volt_control_o,/* 20: Signal */
  &liner_control_B.Y1_manual_switch1,  /* 21: Signal */
  &liner_control_B.X_position,         /* 22: Signal */
  &liner_control_B.X_position_o,       /* 23: Signal */
  &liner_control_B.Saturation,         /* 24: Signal */
  &liner_control_B.Saturation1,        /* 25: Signal */
  &liner_control_B.X_e_position,       /* 26: Signal */
  &liner_control_B.X_input_volt,       /* 27: Signal */
  &liner_control_B.Sum10,              /* 28: Signal */
  &liner_control_B.X_control_input_volt,/* 29: Signal */
  &liner_control_B.Sum3,               /* 30: Signal */
  &liner_control_B.X_e_position_f,     /* 31: Signal */
  &liner_control_B.X_input_volt_e,     /* 32: Signal */
  &liner_control_B.X_control_input_volt_n,/* 33: Signal */
  &liner_control_B.Sum7,               /* 34: Signal */
  &liner_control_B.Sum9,               /* 35: Signal */
  &liner_control_B.ManualSwitch,       /* 36: Signal */
  &liner_control_B.Diff,               /* 37: Signal */
  &liner_control_B.TSamp,              /* 38: Signal */
  &liner_control_B.Uk1,                /* 39: Signal */
  &liner_control_B.Diff_p,             /* 40: Signal */
  &liner_control_B.TSamp_g,            /* 41: Signal */
  &liner_control_B.Uk1_a,              /* 42: Signal */
  &liner_control_B.icounter[0],        /* 43: Signal */
  &liner_control_B.DAC[0],             /* 44: Signal */
  &liner_control_B.data_ch[0],         /* 45: Signal */
  &liner_control_B.input_ch[0],        /* 46: Signal */
  &liner_control_P.DinamicFriction_ICPrevScaledInp,/* 47: Mask Parameter */
  &liner_control_P.DiscreteDerivative1_ICPrevScale,/* 48: Mask Parameter */
  &liner_control_P.Constant_Value,     /* 49: Block Parameter */
  &liner_control_P.Constant1_Value,    /* 50: Block Parameter */
  &liner_control_P.X_CART_VELOCITY_THRESHOLD_Value,/* 51: Block Parameter */
  &liner_control_P.X_INPUT_TORQUE_THRESHOLD_Value,/* 52: Block Parameter */
  &liner_control_P.X_MAX_DYNAMIC_FRIC_Value,/* 53: Block Parameter */
  &liner_control_P.X_MAX_STATIC_FRIC_Value,/* 54: Block Parameter */
  &liner_control_P.X_feedback_manualVolt_Value,/* 55: Block Parameter */
  &liner_control_P.X_manual_volt_Value,/* 56: Block Parameter */
  &liner_control_P.Y1_CART_VELOCITY_THRESHOLD_Valu,/* 57: Block Parameter */
  &liner_control_P.Y1_INPUT_TORQUE_THRESHOLD_Value,/* 58: Block Parameter */
  &liner_control_P.Y1_MAX_DYNAMIC_FRIC_Value,/* 59: Block Parameter */
  &liner_control_P.Y1_MAX_STATIC_FRIC_Value,/* 60: Block Parameter */
  &liner_control_P.Y1_manual_volt1_Value,/* 61: Block Parameter */
  &liner_control_P.integrate_reset_Value,/* 62: Block Parameter */
  &liner_control_P.integrate_reset1_Value,/* 63: Block Parameter */
  &liner_control_P.DiscreteTimeIntegrator_gainval,/* 64: Block Parameter */
  &liner_control_P.DiscreteTimeIntegrator_IC,/* 65: Block Parameter */
  &liner_control_P.DiscreteTimeIntegrator1_gainval,/* 66: Block Parameter */
  &liner_control_P.DiscreteTimeIntegrator1_IC,/* 67: Block Parameter */
  &liner_control_P.PulseGenerator_Amp, /* 68: Block Parameter */
  &liner_control_P.PulseGenerator_Period,/* 69: Block Parameter */
  &liner_control_P.PulseGenerator_Duty,/* 70: Block Parameter */
  &liner_control_P.PulseGenerator_PhaseDelay,/* 71: Block Parameter */
  &liner_control_P.Gain_Gain,          /* 72: Block Parameter */
  &liner_control_P.X_control_switch_Gain,/* 73: Block Parameter */
  &liner_control_P.X_feedback_manual_switch1_Gain,/* 74: Block Parameter */
  &liner_control_P.X_fric_comp_switch_Gain,/* 75: Block Parameter */
  &liner_control_P.X_gain_D_Gain,      /* 76: Block Parameter */
  &liner_control_P.X_gain_I_Gain,      /* 77: Block Parameter */
  &liner_control_P.X_gain_P_Gain,      /* 78: Block Parameter */
  &liner_control_P.X_manual_switch_Gain,/* 79: Block Parameter */
  &liner_control_P.Y1_control_switch_Gain,/* 80: Block Parameter */
  &liner_control_P.Y1_fric_comp_switch_Gain,/* 81: Block Parameter */
  &liner_control_P.Y1_gain_D_Gain,     /* 82: Block Parameter */
  &liner_control_P.Y1_gain_I_Gain,     /* 83: Block Parameter */
  &liner_control_P.Y1_gain_P_Gain,     /* 84: Block Parameter */
  &liner_control_P.Y1_manual_switch1_Gain,/* 85: Block Parameter */
  &liner_control_P.tomm_Gain,          /* 86: Block Parameter */
  &liner_control_P.tomm1_Gain,         /* 87: Block Parameter */
  &liner_control_P.Saturation_UpperSat,/* 88: Block Parameter */
  &liner_control_P.Saturation_LowerSat,/* 89: Block Parameter */
  &liner_control_P.Saturation1_UpperSat,/* 90: Block Parameter */
  &liner_control_P.Saturation1_LowerSat,/* 91: Block Parameter */
  &liner_control_P.ManualSwitch_CurrentSetting,/* 92: Block Parameter */
  &liner_control_P.TSamp_WtEt,         /* 93: Block Parameter */
  &liner_control_P.TSamp_WtEt_f,       /* 94: Block Parameter */
  &liner_control_P.icounter_P1,        /* 95: Block Parameter */
  &liner_control_P.icounter_P2,        /* 96: Block Parameter */
  &liner_control_P.icounter_P3,        /* 97: Block Parameter */
  &liner_control_P.icounter_P4,        /* 98: Block Parameter */
  &liner_control_P.icounter_P5,        /* 99: Block Parameter */
  &liner_control_P.icounter_P6,        /* 100: Block Parameter */
  &liner_control_P.icounter_P7,        /* 101: Block Parameter */
  &liner_control_P.icounter_P8,        /* 102: Block Parameter */
  &liner_control_P.icounter_P9,        /* 103: Block Parameter */
  &liner_control_P.icounter_P10,       /* 104: Block Parameter */
  &liner_control_P.icounter_P11,       /* 105: Block Parameter */
  &liner_control_P.icounter_P12,       /* 106: Block Parameter */
  &liner_control_P.icounter_P13,       /* 107: Block Parameter */
  &liner_control_P.icounter_P14,       /* 108: Block Parameter */
  &liner_control_P.icounter_P15,       /* 109: Block Parameter */
  &liner_control_P.icounter_P16,       /* 110: Block Parameter */
  &liner_control_P.icounter_P17,       /* 111: Block Parameter */
  &liner_control_P.icounter_P18,       /* 112: Block Parameter */
  &liner_control_P.icounter_P19,       /* 113: Block Parameter */
  &liner_control_P.icounter_P20,       /* 114: Block Parameter */
  &liner_control_P.icounter_P21,       /* 115: Block Parameter */
  &liner_control_P.icounter_P22,       /* 116: Block Parameter */
  &liner_control_P.icounter_P23,       /* 117: Block Parameter */
  &liner_control_P.icounter_P24,       /* 118: Block Parameter */
  &liner_control_P.icounter_P25,       /* 119: Block Parameter */
  &liner_control_P.icounter_P26,       /* 120: Block Parameter */
  &liner_control_P.icounter_P27,       /* 121: Block Parameter */
  &liner_control_P.icounter_P28,       /* 122: Block Parameter */
  &liner_control_P.icounter_P29,       /* 123: Block Parameter */
  &liner_control_P.icounter_P30,       /* 124: Block Parameter */
  &liner_control_P.icounter_P31,       /* 125: Block Parameter */
  &liner_control_P.icounter_P32,       /* 126: Block Parameter */
  &liner_control_P.DAC_UpperSat,       /* 127: Block Parameter */
  &liner_control_P.DAC_LowerSat,       /* 128: Block Parameter */
  &liner_control_P.dac_P1,             /* 129: Block Parameter */
  &liner_control_P.dac_P2,             /* 130: Block Parameter */
  &liner_control_P.dac_P3,             /* 131: Block Parameter */
  &liner_control_P.dac_P4,             /* 132: Block Parameter */
  &liner_control_P.dac_P5,             /* 133: Block Parameter */
  &liner_control_P.dac_P6,             /* 134: Block Parameter */
  &liner_control_P.dac_P7,             /* 135: Block Parameter */
  &liner_control_P.dac_P8,             /* 136: Block Parameter */
  &liner_control_P.dac_P9,             /* 137: Block Parameter */
  &liner_control_P.data_ch_Gain,       /* 138: Block Parameter */
  &liner_control_P.to_memory_rt_P1,    /* 139: Block Parameter */
  &liner_control_P.to_memory_rt_P2,    /* 140: Block Parameter */
  &liner_control_P.to_memory_rt_P3,    /* 141: Block Parameter */
  &liner_control_P.to_memory_rt_P4,    /* 142: Block Parameter */
  &liner_control_P.input_ch_Gain,      /* 143: Block Parameter */
  &liner_control_P.to_host_rt_P1,      /* 144: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  2,                                   /* 2 */
  1,                                   /* 3 */
  6,                                   /* 4 */
  1,                                   /* 5 */
  8,                                   /* 6 */
  1                                    /* 7 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.01, 0.0, 1.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 47,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 98,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 3200377329U,
    3950328209U,
    631183050U,
    3526865835U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  liner_control_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void liner_control_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(liner_control_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(liner_control_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(liner_control_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(liner_control_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(liner_control_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(liner_control_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(liner_control_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(liner_control_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void liner_control_host_InitializeDataMapInfo(liner_control_host_DataMapInfo_T
    *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: liner_control_capi.c */
