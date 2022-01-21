/*
 * liner_control_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "liner_control".
 *
 * Model version              : 1.126
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Jan 20 12:52:32 2022
 *
 * Target selection: sbox2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "liner_control.h"
#include "liner_control_private.h"

/* Block parameters (default storage) */
P_liner_control_T liner_control_P = {
  /* Mask Parameter: DinamicFriction_ICPrevScaledInp
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S2>/UD'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/X_feedback_manualVolt'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/X_feedback_manual_switch1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/X_manual_volt'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/X_manual_switch'
   */
  0.0,

  /* Computed Parameter: icounter_P1_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: mode
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P2_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: teibai
   * Referenced by: '<S3>/icounter'
   */
  3.0,

  /* Computed Parameter: icounter_P3_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: filter
   * Referenced by: '<S3>/icounter'
   */
  0.0,

  /* Computed Parameter: icounter_P4_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: zphase
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P5_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: polarity
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P6_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: mode2
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P7_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: teibai2
   * Referenced by: '<S3>/icounter'
   */
  3.0,

  /* Computed Parameter: icounter_P8_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: filter2
   * Referenced by: '<S3>/icounter'
   */
  0.0,

  /* Computed Parameter: icounter_P9_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: zphase2
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P10_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: polarity2
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P11_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: mode3
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P12_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: teibai3
   * Referenced by: '<S3>/icounter'
   */
  3.0,

  /* Computed Parameter: icounter_P13_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: filter3
   * Referenced by: '<S3>/icounter'
   */
  0.0,

  /* Computed Parameter: icounter_P14_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: zphase3
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P15_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: polarity3
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P16_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: mode4
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P17_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: teibai4
   * Referenced by: '<S3>/icounter'
   */
  3.0,

  /* Computed Parameter: icounter_P18_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: filter4
   * Referenced by: '<S3>/icounter'
   */
  0.0,

  /* Computed Parameter: icounter_P19_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: zphase4
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P20_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: polarity4
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P21_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: mode5
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P22_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: teibai5
   * Referenced by: '<S3>/icounter'
   */
  3.0,

  /* Computed Parameter: icounter_P23_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: filter5
   * Referenced by: '<S3>/icounter'
   */
  0.0,

  /* Computed Parameter: icounter_P24_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: zphase5
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P25_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: polarity5
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P26_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: mode6
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P27_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: teibai6
   * Referenced by: '<S3>/icounter'
   */
  3.0,

  /* Computed Parameter: icounter_P28_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: filter6
   * Referenced by: '<S3>/icounter'
   */
  0.0,

  /* Computed Parameter: icounter_P29_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: zphase6
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P30_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: polarity6
   * Referenced by: '<S3>/icounter'
   */
  1.0,

  /* Computed Parameter: icounter_P31_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: dtype
   * Referenced by: '<S3>/icounter'
   */
  3.0,

  /* Computed Parameter: icounter_P32_Size
   * Referenced by: '<S3>/icounter'
   */
  { 1.0, 1.0 },

  /* Expression: sampletime
   * Referenced by: '<S3>/icounter'
   */
  -1.0,

  /* Expression: -0.0001
   * Referenced by: '<Root>/to mm'
   */
  -0.0001,

  /* Expression: 1.3
   * Referenced by: '<Root>/X_gain_P'
   */
  1.3,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  100.0,

  /* Expression: 0.25
   * Referenced by: '<Root>/X_gain_D'
   */
  0.25,

  /* Expression: 0
   * Referenced by: '<Root>/integrate_reset'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/X_gain_I'
   */
  0.0,

  /* Expression: 0.65
   * Referenced by: '<Root>/X_MAX_STATIC_FRIC'
   */
  0.65,

  /* Expression: 0.05
   * Referenced by: '<Root>/X_MAX_DYNAMIC_FRIC'
   */
  0.05,

  /* Expression: 0.01
   * Referenced by: '<Root>/X_CART_VELOCITY_THRESHOLD'
   */
  0.01,

  /* Expression: 0.5
   * Referenced by: '<Root>/X_INPUT_TORQUE_THRESHOLD'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<Root>/X_fric_comp_switch'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/X_control_switch'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<Root>/Saturation'
   */
  -5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Y1_manual_volt1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Y1_manual_switch1'
   */
  0.0,

  /* Expression: -0.0001
   * Referenced by: '<Root>/to mm1'
   */
  -0.0001,

  /* Expression: 0.7
   * Referenced by: '<Root>/Y1_gain_P'
   */
  0.7,

  /* Computed Parameter: TSamp_WtEt_f
   * Referenced by: '<S2>/TSamp'
   */
  100.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Y1_gain_D'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<Root>/integrate_reset1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Y1_gain_I'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<Root>/Y1_MAX_STATIC_FRIC'
   */
  0.3,

  /* Expression: 0.01
   * Referenced by: '<Root>/Y1_MAX_DYNAMIC_FRIC'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<Root>/Y1_CART_VELOCITY_THRESHOLD'
   */
  0.01,

  /* Expression: 0.3
   * Referenced by: '<Root>/Y1_INPUT_TORQUE_THRESHOLD'
   */
  0.3,

  /* Expression: 1
   * Referenced by: '<Root>/Y1_fric_comp_switch'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Y1_control_switch'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<Root>/Saturation1'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<Root>/Saturation1'
   */
  -5.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 9.9988
   * Referenced by: '<S4>/DAC'
   */
  9.9988,

  /* Expression: -10.0
   * Referenced by: '<S4>/DAC'
   */
  -10.0,

  /* Computed Parameter: dac_P1_Size
   * Referenced by: '<S4>/dac'
   */
  { 1.0, 1.0 },

  /* Expression: sampletime
   * Referenced by: '<S4>/dac'
   */
  -1.0,

  /* Computed Parameter: dac_P2_Size
   * Referenced by: '<S4>/dac'
   */
  { 1.0, 1.0 },

  /* Expression: daStopCtrl1
   * Referenced by: '<S4>/dac'
   */
  1.0,

  /* Computed Parameter: dac_P3_Size
   * Referenced by: '<S4>/dac'
   */
  { 1.0, 1.0 },

  /* Expression: daStopCtrl2
   * Referenced by: '<S4>/dac'
   */
  1.0,

  /* Computed Parameter: dac_P4_Size
   * Referenced by: '<S4>/dac'
   */
  { 1.0, 1.0 },

  /* Expression: daStopCtrl3
   * Referenced by: '<S4>/dac'
   */
  1.0,

  /* Computed Parameter: dac_P5_Size
   * Referenced by: '<S4>/dac'
   */
  { 1.0, 1.0 },

  /* Expression: daStopCtrl4
   * Referenced by: '<S4>/dac'
   */
  1.0,

  /* Computed Parameter: dac_P6_Size
   * Referenced by: '<S4>/dac'
   */
  { 1.0, 1.0 },

  /* Expression: daStopCtrl5
   * Referenced by: '<S4>/dac'
   */
  1.0,

  /* Computed Parameter: dac_P7_Size
   * Referenced by: '<S4>/dac'
   */
  { 1.0, 1.0 },

  /* Expression: daStopCtrl6
   * Referenced by: '<S4>/dac'
   */
  1.0,

  /* Computed Parameter: dac_P8_Size
   * Referenced by: '<S4>/dac'
   */
  { 1.0, 1.0 },

  /* Expression: daStopCtrl7
   * Referenced by: '<S4>/dac'
   */
  1.0,

  /* Computed Parameter: dac_P9_Size
   * Referenced by: '<S4>/dac'
   */
  { 1.0, 1.0 },

  /* Expression: daStopCtrl8
   * Referenced by: '<S4>/dac'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S5>/data_ch'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Computed Parameter: to_memory_rt_P1_Size
   * Referenced by: '<S5>/to_memory_rt'
   */
  { 1.0, 1.0 },

  /* Expression: data_length
   * Referenced by: '<S5>/to_memory_rt'
   */
  500.0,

  /* Computed Parameter: to_memory_rt_P2_Size
   * Referenced by: '<S5>/to_memory_rt'
   */
  { 1.0, 1.0 },

  /* Expression: pre_triger
   * Referenced by: '<S5>/to_memory_rt'
   */
  0.0,

  /* Computed Parameter: to_memory_rt_P3_Size
   * Referenced by: '<S5>/to_memory_rt'
   */
  { 1.0, 1.0 },

  /* Expression: sampletime
   * Referenced by: '<S5>/to_memory_rt'
   */
  -1.0,

  /* Computed Parameter: to_memory_rt_P4_Size
   * Referenced by: '<S5>/to_memory_rt'
   */
  { 1.0, 1.0 },

  /* Expression: save_mode
   * Referenced by: '<S5>/to_memory_rt'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S6>/input_ch'
   */
  1.0,

  /* Computed Parameter: to_host_rt_P1_Size
   * Referenced by: '<S6>/to_host_rt'
   */
  { 1.0, 1.0 },

  /* Expression: sampletime
   * Referenced by: '<S6>/to_host_rt'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Pulse Generator'
   */
  100.0,

  /* Expression: 5
   * Referenced by: '<Root>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U
};
