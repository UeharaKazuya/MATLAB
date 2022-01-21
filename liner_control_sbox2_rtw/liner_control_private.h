/*
 * liner_control_private.h
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

#ifndef RTW_HEADER_liner_control_private_h_
#define RTW_HEADER_liner_control_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "liner_control.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Used by FromWorkspace Block: '<Root>/From Workspace' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

extern void udcm6_sep(SimStruct *rts);
extern void dam148ctrl(SimStruct *rts);
extern void to_memory_rt(SimStruct *rts);
extern void to_host_rt(SimStruct *rts);
extern void li_frictioncompensationbymatlab(real_T rtu_cart_vel, real_T
  rtu_input_torque, real_T rtu_MAX_STATIC_FRIC, real_T rtu_MAX_DYNAMIC_FRIC,
  real_T rtu_CART_VELOCITY_THRESHOLD, real_T rtu_INPUT_TORQUE_THRESHOLD,
  B_frictioncompensationbymatla_T *localB);

#endif                                 /* RTW_HEADER_liner_control_private_h_ */
