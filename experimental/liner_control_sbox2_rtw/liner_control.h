/*
 * liner_control.h
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

#ifndef RTW_HEADER_liner_control_h_
#define RTW_HEADER_liner_control_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef liner_control_COMMON_INCLUDES_
# define liner_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* liner_control_COMMON_INCLUDES_ */

#include "liner_control_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals for system '<Root>/friction compensation by matlab' */
typedef struct {
  real_T input_fric_compen;       /* '<Root>/friction compensation by matlab' */
} B_frictioncompensationbymatla_T;

/* Block signals (default storage) */
typedef struct {
  real_T X_manual_switch;              /* '<Root>/X_manual_switch' */
  real_T icounter[6];                  /* '<S3>/icounter' */
  real_T X_position;                   /* '<Root>/to mm' */
  real_T FromWorkspace[2];             /* '<Root>/From Workspace' */
  real_T ManualSwitch;                 /* '<Root>/Manual Switch' */
  real_T X_e_position;                 /* '<Root>/Sum' */
  real_T X_input_volt_control;         /* '<Root>/X_gain_P' */
  real_T TSamp;                        /* '<S1>/TSamp' */
  real_T Uk1;                          /* '<S1>/UD' */
  real_T Diff;                         /* '<S1>/Diff' */
  real_T X_input_volt_control_a;       /* '<Root>/X_gain_D' */
  real_T DiscreteTimeIntegrator;       /* '<Root>/Discrete-Time Integrator' */
  real_T input_volt_control;           /* '<Root>/X_gain_I' */
  real_T X_control_input_volt;         /* '<Root>/Sum2' */
  real_T X_fric_comp_switch;           /* '<Root>/X_fric_comp_switch' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T X_control_switch;             /* '<Root>/X_control_switch' */
  real_T X_input_volt;                 /* '<Root>/Sum1' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Y1_manual_switch1;            /* '<Root>/Y1_manual_switch1' */
  real_T X_position_o;                 /* '<Root>/to mm1' */
  real_T X_e_position_f;               /* '<Root>/Sum4' */
  real_T X_input_volt_control_o;       /* '<Root>/Y1_gain_P' */
  real_T TSamp_g;                      /* '<S2>/TSamp' */
  real_T Uk1_a;                        /* '<S2>/UD' */
  real_T Diff_p;                       /* '<S2>/Diff' */
  real_T X_input_volt_control_n;       /* '<Root>/Y1_gain_D' */
  real_T DiscreteTimeIntegrator1;      /* '<Root>/Discrete-Time Integrator1' */
  real_T input_volt_control_k;         /* '<Root>/Y1_gain_I' */
  real_T X_control_input_volt_n;       /* '<Root>/Sum6' */
  real_T Y1_fric_comp_switch;          /* '<Root>/Y1_fric_comp_switch' */
  real_T Sum7;                         /* '<Root>/Sum7' */
  real_T Y1_control_switch;            /* '<Root>/Y1_control_switch' */
  real_T X_input_volt_e;               /* '<Root>/Sum5' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T Gain;                         /* '<Root>/Gain' */
  real_T DAC[8];                       /* '<S4>/DAC' */
  real_T data_ch[8];                   /* '<S5>/data_ch' */
  real_T Constant1;                    /* '<Root>/Constant1' */
  real_T input_ch[8];                  /* '<S6>/input_ch' */
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
  real_T X_feedback_manual_switch1;    /* '<Root>/X_feedback_manual_switch1' */
  B_frictioncompensationbymatla_T sf_frictioncompensationbymatl_o;
                                 /* '<Root>/friction compensation by matlab1' */
  B_frictioncompensationbymatla_T sf_frictioncompensationbymatlab;
                                  /* '<Root>/friction compensation by matlab' */
} B_liner_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T UD_DSTATE_l;                  /* '<S2>/UD' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  void *icounter_PWORK;                /* '<S3>/icounter' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<Root>/From Workspace' */

  void *to_memory_rt_PWORK;            /* '<S5>/to_memory_rt' */
  void *to_host_rt_PWORK;              /* '<S6>/to_host_rt' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int_T icounter_IWORK;                /* '<S3>/icounter' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<Root>/From Workspace' */

  int_T to_memory_rt_IWORK;            /* '<S5>/to_memory_rt' */
  int_T to_host_rt_IWORK;              /* '<S6>/to_host_rt' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<Root>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<Root>/Discrete-Time Integrator1' */
} DW_liner_control_T;

/* Parameters (default storage) */
struct P_liner_control_T_ {
  real_T DinamicFriction_ICPrevScaledInp;
                              /* Mask Parameter: DinamicFriction_ICPrevScaledInp
                               * Referenced by: '<S1>/UD'
                               */
  real_T DiscreteDerivative1_ICPrevScale;
                              /* Mask Parameter: DiscreteDerivative1_ICPrevScale
                               * Referenced by: '<S2>/UD'
                               */
  real_T X_feedback_manualVolt_Value;  /* Expression: 0
                                        * Referenced by: '<Root>/X_feedback_manualVolt'
                                        */
  real_T X_feedback_manual_switch1_Gain;/* Expression: 0
                                         * Referenced by: '<Root>/X_feedback_manual_switch1'
                                         */
  real_T X_manual_volt_Value;          /* Expression: 0
                                        * Referenced by: '<Root>/X_manual_volt'
                                        */
  real_T X_manual_switch_Gain;         /* Expression: 0
                                        * Referenced by: '<Root>/X_manual_switch'
                                        */
  real_T icounter_P1_Size[2];          /* Computed Parameter: icounter_P1_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P1;                  /* Expression: mode
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P2_Size[2];          /* Computed Parameter: icounter_P2_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P2;                  /* Expression: teibai
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P3_Size[2];          /* Computed Parameter: icounter_P3_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P3;                  /* Expression: filter
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P4_Size[2];          /* Computed Parameter: icounter_P4_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P4;                  /* Expression: zphase
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P5_Size[2];          /* Computed Parameter: icounter_P5_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P5;                  /* Expression: polarity
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P6_Size[2];          /* Computed Parameter: icounter_P6_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P6;                  /* Expression: mode2
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P7_Size[2];          /* Computed Parameter: icounter_P7_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P7;                  /* Expression: teibai2
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P8_Size[2];          /* Computed Parameter: icounter_P8_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P8;                  /* Expression: filter2
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P9_Size[2];          /* Computed Parameter: icounter_P9_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P9;                  /* Expression: zphase2
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P10_Size[2];         /* Computed Parameter: icounter_P10_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P10;                 /* Expression: polarity2
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P11_Size[2];         /* Computed Parameter: icounter_P11_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P11;                 /* Expression: mode3
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P12_Size[2];         /* Computed Parameter: icounter_P12_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P12;                 /* Expression: teibai3
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P13_Size[2];         /* Computed Parameter: icounter_P13_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P13;                 /* Expression: filter3
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P14_Size[2];         /* Computed Parameter: icounter_P14_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P14;                 /* Expression: zphase3
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P15_Size[2];         /* Computed Parameter: icounter_P15_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P15;                 /* Expression: polarity3
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P16_Size[2];         /* Computed Parameter: icounter_P16_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P16;                 /* Expression: mode4
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P17_Size[2];         /* Computed Parameter: icounter_P17_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P17;                 /* Expression: teibai4
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P18_Size[2];         /* Computed Parameter: icounter_P18_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P18;                 /* Expression: filter4
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P19_Size[2];         /* Computed Parameter: icounter_P19_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P19;                 /* Expression: zphase4
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P20_Size[2];         /* Computed Parameter: icounter_P20_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P20;                 /* Expression: polarity4
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P21_Size[2];         /* Computed Parameter: icounter_P21_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P21;                 /* Expression: mode5
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P22_Size[2];         /* Computed Parameter: icounter_P22_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P22;                 /* Expression: teibai5
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P23_Size[2];         /* Computed Parameter: icounter_P23_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P23;                 /* Expression: filter5
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P24_Size[2];         /* Computed Parameter: icounter_P24_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P24;                 /* Expression: zphase5
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P25_Size[2];         /* Computed Parameter: icounter_P25_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P25;                 /* Expression: polarity5
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P26_Size[2];         /* Computed Parameter: icounter_P26_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P26;                 /* Expression: mode6
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P27_Size[2];         /* Computed Parameter: icounter_P27_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P27;                 /* Expression: teibai6
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P28_Size[2];         /* Computed Parameter: icounter_P28_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P28;                 /* Expression: filter6
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P29_Size[2];         /* Computed Parameter: icounter_P29_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P29;                 /* Expression: zphase6
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P30_Size[2];         /* Computed Parameter: icounter_P30_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P30;                 /* Expression: polarity6
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P31_Size[2];         /* Computed Parameter: icounter_P31_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P31;                 /* Expression: dtype
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P32_Size[2];         /* Computed Parameter: icounter_P32_Size
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T icounter_P32;                 /* Expression: sampletime
                                        * Referenced by: '<S3>/icounter'
                                        */
  real_T tomm_Gain;                    /* Expression: -0.0001
                                        * Referenced by: '<Root>/to mm'
                                        */
  real_T X_gain_P_Gain;                /* Expression: 1.3
                                        * Referenced by: '<Root>/X_gain_P'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real_T X_gain_D_Gain;                /* Expression: 0.25
                                        * Referenced by: '<Root>/X_gain_D'
                                        */
  real_T integrate_reset_Value;        /* Expression: 0
                                        * Referenced by: '<Root>/integrate_reset'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T X_gain_I_Gain;                /* Expression: 0
                                        * Referenced by: '<Root>/X_gain_I'
                                        */
  real_T X_MAX_STATIC_FRIC_Value;      /* Expression: 0.65
                                        * Referenced by: '<Root>/X_MAX_STATIC_FRIC'
                                        */
  real_T X_MAX_DYNAMIC_FRIC_Value;     /* Expression: 0.05
                                        * Referenced by: '<Root>/X_MAX_DYNAMIC_FRIC'
                                        */
  real_T X_CART_VELOCITY_THRESHOLD_Value;/* Expression: 0.01
                                          * Referenced by: '<Root>/X_CART_VELOCITY_THRESHOLD'
                                          */
  real_T X_INPUT_TORQUE_THRESHOLD_Value;/* Expression: 0.5
                                         * Referenced by: '<Root>/X_INPUT_TORQUE_THRESHOLD'
                                         */
  real_T X_fric_comp_switch_Gain;      /* Expression: 1
                                        * Referenced by: '<Root>/X_fric_comp_switch'
                                        */
  real_T X_control_switch_Gain;        /* Expression: 0
                                        * Referenced by: '<Root>/X_control_switch'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Y1_manual_volt1_Value;        /* Expression: 0
                                        * Referenced by: '<Root>/Y1_manual_volt1'
                                        */
  real_T Y1_manual_switch1_Gain;       /* Expression: 0
                                        * Referenced by: '<Root>/Y1_manual_switch1'
                                        */
  real_T tomm1_Gain;                   /* Expression: -0.0001
                                        * Referenced by: '<Root>/to mm1'
                                        */
  real_T Y1_gain_P_Gain;               /* Expression: 0.7
                                        * Referenced by: '<Root>/Y1_gain_P'
                                        */
  real_T TSamp_WtEt_f;                 /* Computed Parameter: TSamp_WtEt_f
                                        * Referenced by: '<S2>/TSamp'
                                        */
  real_T Y1_gain_D_Gain;               /* Expression: 0.1
                                        * Referenced by: '<Root>/Y1_gain_D'
                                        */
  real_T integrate_reset1_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/integrate_reset1'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  real_T Y1_gain_I_Gain;               /* Expression: 0
                                        * Referenced by: '<Root>/Y1_gain_I'
                                        */
  real_T Y1_MAX_STATIC_FRIC_Value;     /* Expression: 0.3
                                        * Referenced by: '<Root>/Y1_MAX_STATIC_FRIC'
                                        */
  real_T Y1_MAX_DYNAMIC_FRIC_Value;    /* Expression: 0.01
                                        * Referenced by: '<Root>/Y1_MAX_DYNAMIC_FRIC'
                                        */
  real_T Y1_CART_VELOCITY_THRESHOLD_Valu;/* Expression: 0.01
                                          * Referenced by: '<Root>/Y1_CART_VELOCITY_THRESHOLD'
                                          */
  real_T Y1_INPUT_TORQUE_THRESHOLD_Value;/* Expression: 0.3
                                          * Referenced by: '<Root>/Y1_INPUT_TORQUE_THRESHOLD'
                                          */
  real_T Y1_fric_comp_switch_Gain;     /* Expression: 1
                                        * Referenced by: '<Root>/Y1_fric_comp_switch'
                                        */
  real_T Y1_control_switch_Gain;       /* Expression: 0
                                        * Referenced by: '<Root>/Y1_control_switch'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 5
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -5
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T DAC_UpperSat;                 /* Expression: 9.9988
                                        * Referenced by: '<S4>/DAC'
                                        */
  real_T DAC_LowerSat;                 /* Expression: -10.0
                                        * Referenced by: '<S4>/DAC'
                                        */
  real_T dac_P1_Size[2];               /* Computed Parameter: dac_P1_Size
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P1;                       /* Expression: sampletime
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P2_Size[2];               /* Computed Parameter: dac_P2_Size
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P2;                       /* Expression: daStopCtrl1
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P3_Size[2];               /* Computed Parameter: dac_P3_Size
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P3;                       /* Expression: daStopCtrl2
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P4_Size[2];               /* Computed Parameter: dac_P4_Size
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P4;                       /* Expression: daStopCtrl3
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P5_Size[2];               /* Computed Parameter: dac_P5_Size
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P5;                       /* Expression: daStopCtrl4
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P6_Size[2];               /* Computed Parameter: dac_P6_Size
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P6;                       /* Expression: daStopCtrl5
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P7_Size[2];               /* Computed Parameter: dac_P7_Size
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P7;                       /* Expression: daStopCtrl6
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P8_Size[2];               /* Computed Parameter: dac_P8_Size
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P8;                       /* Expression: daStopCtrl7
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P9_Size[2];               /* Computed Parameter: dac_P9_Size
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T dac_P9;                       /* Expression: daStopCtrl8
                                        * Referenced by: '<S4>/dac'
                                        */
  real_T data_ch_Gain;                 /* Expression: 1
                                        * Referenced by: '<S5>/data_ch'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T to_memory_rt_P1_Size[2];    /* Computed Parameter: to_memory_rt_P1_Size
                                      * Referenced by: '<S5>/to_memory_rt'
                                      */
  real_T to_memory_rt_P1;              /* Expression: data_length
                                        * Referenced by: '<S5>/to_memory_rt'
                                        */
  real_T to_memory_rt_P2_Size[2];    /* Computed Parameter: to_memory_rt_P2_Size
                                      * Referenced by: '<S5>/to_memory_rt'
                                      */
  real_T to_memory_rt_P2;              /* Expression: pre_triger
                                        * Referenced by: '<S5>/to_memory_rt'
                                        */
  real_T to_memory_rt_P3_Size[2];    /* Computed Parameter: to_memory_rt_P3_Size
                                      * Referenced by: '<S5>/to_memory_rt'
                                      */
  real_T to_memory_rt_P3;              /* Expression: sampletime
                                        * Referenced by: '<S5>/to_memory_rt'
                                        */
  real_T to_memory_rt_P4_Size[2];    /* Computed Parameter: to_memory_rt_P4_Size
                                      * Referenced by: '<S5>/to_memory_rt'
                                      */
  real_T to_memory_rt_P4;              /* Expression: save_mode
                                        * Referenced by: '<S5>/to_memory_rt'
                                        */
  real_T input_ch_Gain;                /* Expression: 1
                                        * Referenced by: '<S6>/input_ch'
                                        */
  real_T to_host_rt_P1_Size[2];        /* Computed Parameter: to_host_rt_P1_Size
                                        * Referenced by: '<S6>/to_host_rt'
                                        */
  real_T to_host_rt_P1;                /* Expression: sampletime
                                        * Referenced by: '<S6>/to_host_rt'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 100
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_liner_control_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[4];
    SimStruct *childSFunctionPtrs[4];
    struct _ssBlkInfo2 blkInfo2[4];
    struct _ssSFcnModelMethods2 methods2[4];
    struct _ssSFcnModelMethods3 methods3[4];
    struct _ssSFcnModelMethods4 methods4[4];
    struct _ssStatesInfo2 statesInfo2[4];
    ssPeriodicStatesInfo periodicStatesInfo[4];
    struct _ssPortInfo2 inputOutputPortInfo2[4];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[32];
      mxArray *params[32];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      uint_T attribs[9];
      mxArray *params[9];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn3;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_liner_control_T liner_control_P;

/* Block signals (default storage) */
extern B_liner_control_T liner_control_B;

/* Block states (default storage) */
extern DW_liner_control_T liner_control_DW;

/* Model entry point functions */
extern void liner_control_initialize(void);
extern void liner_control_step(void);
extern void liner_control_terminate(void);

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  liner_control_GetCAPIStaticMap(void);

/* Real-time Model object */
extern RT_MODEL_liner_control_T *const liner_control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'liner_control'
 * '<S1>'   : 'liner_control/DinamicFriction'
 * '<S2>'   : 'liner_control/Discrete Derivative1'
 * '<S3>'   : 'liner_control/SBOX2_CNT6'
 * '<S4>'   : 'liner_control/SBOX2_DAM148 '
 * '<S5>'   : 'liner_control/SBOX2_DATA_SAVE_NET'
 * '<S6>'   : 'liner_control/SBOX2_GRAPH_MONITOR'
 * '<S7>'   : 'liner_control/friction compensation by matlab'
 * '<S8>'   : 'liner_control/friction compensation by matlab1'
 */
#endif                                 /* RTW_HEADER_liner_control_h_ */
