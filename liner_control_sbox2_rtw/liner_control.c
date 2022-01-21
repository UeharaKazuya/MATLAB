/*
 * liner_control.c
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

#include "liner_control_capi.h"
#include "liner_control.h"
#include "liner_control_private.h"

/* Block signals (default storage) */
B_liner_control_T liner_control_B;

/* Block states (default storage) */
DW_liner_control_T liner_control_DW;

/* Real-time model */
RT_MODEL_liner_control_T liner_control_M_;
RT_MODEL_liner_control_T *const liner_control_M = &liner_control_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (liner_control_M->Timing.TaskCounters.TID[1])++;
  if ((liner_control_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [1.0s, 0.0s] */
    liner_control_M->Timing.TaskCounters.TID[1] = 0;
  }

  liner_control_M->Timing.sampleHits[1] =
    (liner_control_M->Timing.TaskCounters.TID[1] == 0);
}

/*
 * Output and update for atomic system:
 *    '<Root>/friction compensation by matlab'
 *    '<Root>/friction compensation by matlab1'
 */
void li_frictioncompensationbymatlab(real_T rtu_cart_vel, real_T
  rtu_input_torque, real_T rtu_MAX_STATIC_FRIC, real_T rtu_MAX_DYNAMIC_FRIC,
  real_T rtu_CART_VELOCITY_THRESHOLD, real_T rtu_INPUT_TORQUE_THRESHOLD,
  B_frictioncompensationbymatla_T *localB)
{
  /* MATLAB Function 'friction compensation by matlab': '<S7>:1' */
  /* '<S7>:1:3' */
  localB->input_fric_compen = 0.0;
  if (fabs(rtu_cart_vel) < rtu_CART_VELOCITY_THRESHOLD) {
    /* '<S7>:1:5' */
    if (rtu_input_torque > rtu_INPUT_TORQUE_THRESHOLD) {
      /* '<S7>:1:6' */
      /* '<S7>:1:7' */
      localB->input_fric_compen = rtu_MAX_STATIC_FRIC * 0.9;
    } else if (rtu_input_torque < -rtu_INPUT_TORQUE_THRESHOLD) {
      /* '<S7>:1:9' */
      /* '<S7>:1:10' */
      localB->input_fric_compen = -rtu_MAX_STATIC_FRIC * 0.9;
    } else {
      /* '<S7>:1:12' */
      localB->input_fric_compen = 0.0;
    }
  } else if (rtu_cart_vel > 0.0) {
    /* '<S7>:1:16' */
    /* '<S7>:1:17' */
    localB->input_fric_compen = rtu_MAX_DYNAMIC_FRIC * 0.9;
  } else {
    if (rtu_cart_vel < 0.0) {
      /* '<S7>:1:18' */
      /* '<S7>:1:19' */
      localB->input_fric_compen = -rtu_MAX_DYNAMIC_FRIC * 0.9;
    }
  }
}

/* Model step function */
void liner_control_step(void)
{
  real_T y;

  /* Gain: '<Root>/X_manual_switch' incorporates:
   *  Constant: '<Root>/X_manual_volt'
   */
  liner_control_B.X_manual_switch = liner_control_P.X_manual_switch_Gain *
    liner_control_P.X_manual_volt_Value;

  /* S-Function (udcm6_sep): '<S3>/icounter' */

  /* Level2 S-Function Block: '<S3>/icounter' (udcm6_sep) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<Root>/to mm' */
  liner_control_B.X_position = liner_control_P.tomm_Gain *
    liner_control_B.icounter[0];

  /* FromWorkspace: '<Root>/From Workspace' */
  {
    real_T *pDataValues = (real_T *)
      liner_control_DW.FromWorkspace_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      liner_control_DW.FromWorkspace_PWORK.TimePtr;
    int_T currTimeIndex = liner_control_DW.FromWorkspace_IWORK.PrevIndex;
    real_T t = liner_control_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[300]) {
      currTimeIndex = 299;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    liner_control_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&liner_control_B.FromWorkspace[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 301;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&liner_control_B.FromWorkspace[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 301;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 2; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&liner_control_B.FromWorkspace[0])[elIdx] = (real_T) rtInterpolate
              (d1, d2, f1, f2);
            pDataValues += 301;
          }
        }
      }
    }
  }

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (liner_control_P.ManualSwitch_CurrentSetting == 1) {
    /* Gain: '<Root>/X_feedback_manual_switch1' incorporates:
     *  Constant: '<Root>/X_feedback_manualVolt'
     */
    liner_control_B.X_feedback_manual_switch1 =
      liner_control_P.X_feedback_manual_switch1_Gain *
      liner_control_P.X_feedback_manualVolt_Value;
    liner_control_B.ManualSwitch = liner_control_B.X_feedback_manual_switch1;
  } else {
    liner_control_B.ManualSwitch = liner_control_B.FromWorkspace[0];
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Sum: '<Root>/Sum' */
  liner_control_B.X_e_position = liner_control_B.X_position -
    liner_control_B.ManualSwitch;

  /* Gain: '<Root>/X_gain_P' */
  liner_control_B.X_input_volt_control = liner_control_P.X_gain_P_Gain *
    liner_control_B.X_e_position;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  liner_control_B.TSamp = liner_control_B.X_e_position *
    liner_control_P.TSamp_WtEt;

  /* UnitDelay: '<S1>/UD' */
  liner_control_B.Uk1 = liner_control_DW.UD_DSTATE;

  /* Sum: '<S1>/Diff' */
  liner_control_B.Diff = liner_control_B.TSamp - liner_control_B.Uk1;

  /* FromWorkspace: '<Root>/From Workspace1' */
  {
    real_T *pDataValues = (real_T *)
      liner_control_DW.FromWorkspace1_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      liner_control_DW.FromWorkspace1_PWORK.TimePtr;
    int_T currTimeIndex = liner_control_DW.FromWorkspace1_IWORK.PrevIndex;
    real_T t = liner_control_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[300]) {
      currTimeIndex = 299;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    liner_control_DW.FromWorkspace1_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&liner_control_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 301;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&liner_control_B.FromWorkspace1[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 301;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 2; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&liner_control_B.FromWorkspace1[0])[elIdx] = (real_T) rtInterpolate
              (d1, d2, f1, f2);
            pDataValues += 301;
          }
        }
      }
    }
  }

  /* Sum: '<Root>/Sum9' */
  liner_control_B.Sum9 = liner_control_B.Diff - liner_control_B.FromWorkspace1[0];

  /* Gain: '<Root>/X_gain_D' */
  liner_control_B.X_input_volt_control_a = liner_control_P.X_gain_D_Gain *
    liner_control_B.Sum9;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/integrate_reset'
   */
  if ((liner_control_P.integrate_reset_Value > 0.0) &&
      (liner_control_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    liner_control_DW.DiscreteTimeIntegrator_DSTATE =
      liner_control_P.DiscreteTimeIntegrator_IC;
  }

  liner_control_B.DiscreteTimeIntegrator =
    liner_control_P.DiscreteTimeIntegrator_gainval *
    liner_control_B.X_e_position +
    liner_control_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */

  /* Gain: '<Root>/X_gain_I' */
  liner_control_B.input_volt_control = liner_control_P.X_gain_I_Gain *
    liner_control_B.DiscreteTimeIntegrator;

  /* Sum: '<Root>/Sum2' */
  liner_control_B.X_control_input_volt = ((0.0 -
    liner_control_B.X_input_volt_control) -
    liner_control_B.X_input_volt_control_a) - liner_control_B.input_volt_control;

  /* MATLAB Function: '<Root>/friction compensation by matlab' incorporates:
   *  Constant: '<Root>/X_CART_VELOCITY_THRESHOLD'
   *  Constant: '<Root>/X_INPUT_TORQUE_THRESHOLD'
   *  Constant: '<Root>/X_MAX_DYNAMIC_FRIC'
   *  Constant: '<Root>/X_MAX_STATIC_FRIC'
   */
  li_frictioncompensationbymatlab(liner_control_B.Sum9,
    liner_control_B.X_control_input_volt,
    liner_control_P.X_MAX_STATIC_FRIC_Value,
    liner_control_P.X_MAX_DYNAMIC_FRIC_Value,
    liner_control_P.X_CART_VELOCITY_THRESHOLD_Value,
    liner_control_P.X_INPUT_TORQUE_THRESHOLD_Value,
    &liner_control_B.sf_frictioncompensationbymatlab);

  /* Gain: '<Root>/X_fric_comp_switch' */
  liner_control_B.X_fric_comp_switch = liner_control_P.X_fric_comp_switch_Gain *
    liner_control_B.sf_frictioncompensationbymatlab.input_fric_compen;

  /* Sum: '<Root>/Sum3' */
  liner_control_B.Sum3 = liner_control_B.X_control_input_volt +
    liner_control_B.X_fric_comp_switch;

  /* Gain: '<Root>/X_control_switch' */
  liner_control_B.X_control_switch = liner_control_P.X_control_switch_Gain *
    liner_control_B.Sum3;

  /* Sum: '<Root>/Sum1' */
  liner_control_B.X_input_volt = liner_control_B.X_manual_switch +
    liner_control_B.X_control_switch;

  /* Saturate: '<Root>/Saturation' */
  if (liner_control_B.X_input_volt > liner_control_P.Saturation_UpperSat) {
    liner_control_B.Saturation = liner_control_P.Saturation_UpperSat;
  } else if (liner_control_B.X_input_volt < liner_control_P.Saturation_LowerSat)
  {
    liner_control_B.Saturation = liner_control_P.Saturation_LowerSat;
  } else {
    liner_control_B.Saturation = liner_control_B.X_input_volt;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Gain: '<Root>/Y1_manual_switch1' incorporates:
   *  Constant: '<Root>/Y1_manual_volt1'
   */
  liner_control_B.Y1_manual_switch1 = liner_control_P.Y1_manual_switch1_Gain *
    liner_control_P.Y1_manual_volt1_Value;

  /* Gain: '<Root>/to mm1' */
  liner_control_B.X_position_o = liner_control_P.tomm1_Gain *
    liner_control_B.icounter[2];

  /* Sum: '<Root>/Sum4' */
  liner_control_B.X_e_position_f = liner_control_B.X_position_o -
    liner_control_B.FromWorkspace[1];

  /* Gain: '<Root>/Y1_gain_P' */
  liner_control_B.X_input_volt_control_o = liner_control_P.Y1_gain_P_Gain *
    liner_control_B.X_e_position_f;

  /* SampleTimeMath: '<S2>/TSamp'
   *
   * About '<S2>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  liner_control_B.TSamp_g = liner_control_B.X_e_position_f *
    liner_control_P.TSamp_WtEt_f;

  /* UnitDelay: '<S2>/UD' */
  liner_control_B.Uk1_a = liner_control_DW.UD_DSTATE_l;

  /* Sum: '<S2>/Diff' */
  liner_control_B.Diff_p = liner_control_B.TSamp_g - liner_control_B.Uk1_a;

  /* Sum: '<Root>/Sum10' */
  liner_control_B.Sum10 = liner_control_B.Diff_p -
    liner_control_B.FromWorkspace1[1];

  /* Gain: '<Root>/Y1_gain_D' */
  liner_control_B.X_input_volt_control_n = liner_control_P.Y1_gain_D_Gain *
    liner_control_B.Sum10;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<Root>/integrate_reset1'
   */
  if ((liner_control_P.integrate_reset1_Value > 0.0) &&
      (liner_control_DW.DiscreteTimeIntegrator1_PrevRes <= 0)) {
    liner_control_DW.DiscreteTimeIntegrator1_DSTATE =
      liner_control_P.DiscreteTimeIntegrator1_IC;
  }

  liner_control_B.DiscreteTimeIntegrator1 =
    liner_control_P.DiscreteTimeIntegrator1_gainval *
    liner_control_B.X_e_position_f +
    liner_control_DW.DiscreteTimeIntegrator1_DSTATE;

  /* End of DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */

  /* Gain: '<Root>/Y1_gain_I' */
  liner_control_B.input_volt_control_k = liner_control_P.Y1_gain_I_Gain *
    liner_control_B.DiscreteTimeIntegrator1;

  /* Sum: '<Root>/Sum6' */
  liner_control_B.X_control_input_volt_n = ((0.0 -
    liner_control_B.X_input_volt_control_o) -
    liner_control_B.X_input_volt_control_n) -
    liner_control_B.input_volt_control_k;

  /* MATLAB Function: '<Root>/friction compensation by matlab1' incorporates:
   *  Constant: '<Root>/Y1_CART_VELOCITY_THRESHOLD'
   *  Constant: '<Root>/Y1_INPUT_TORQUE_THRESHOLD'
   *  Constant: '<Root>/Y1_MAX_DYNAMIC_FRIC'
   *  Constant: '<Root>/Y1_MAX_STATIC_FRIC'
   */
  li_frictioncompensationbymatlab(liner_control_B.Diff_p,
    liner_control_B.X_control_input_volt_n,
    liner_control_P.Y1_MAX_STATIC_FRIC_Value,
    liner_control_P.Y1_MAX_DYNAMIC_FRIC_Value,
    liner_control_P.Y1_CART_VELOCITY_THRESHOLD_Valu,
    liner_control_P.Y1_INPUT_TORQUE_THRESHOLD_Value,
    &liner_control_B.sf_frictioncompensationbymatl_o);

  /* Gain: '<Root>/Y1_fric_comp_switch' */
  liner_control_B.Y1_fric_comp_switch = liner_control_P.Y1_fric_comp_switch_Gain
    * liner_control_B.sf_frictioncompensationbymatl_o.input_fric_compen;

  /* Sum: '<Root>/Sum7' */
  liner_control_B.Sum7 = liner_control_B.X_control_input_volt_n +
    liner_control_B.Y1_fric_comp_switch;

  /* Gain: '<Root>/Y1_control_switch' */
  liner_control_B.Y1_control_switch = liner_control_P.Y1_control_switch_Gain *
    liner_control_B.Sum7;

  /* Sum: '<Root>/Sum5' */
  liner_control_B.X_input_volt_e = liner_control_B.Y1_manual_switch1 +
    liner_control_B.Y1_control_switch;

  /* Saturate: '<Root>/Saturation1' */
  if (liner_control_B.X_input_volt_e > liner_control_P.Saturation1_UpperSat) {
    liner_control_B.Saturation1 = liner_control_P.Saturation1_UpperSat;
  } else if (liner_control_B.X_input_volt_e <
             liner_control_P.Saturation1_LowerSat) {
    liner_control_B.Saturation1 = liner_control_P.Saturation1_LowerSat;
  } else {
    liner_control_B.Saturation1 = liner_control_B.X_input_volt_e;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* Gain: '<Root>/Gain' */
  liner_control_B.Gain = liner_control_P.Gain_Gain * liner_control_B.Saturation1;

  /* Saturate: '<S4>/DAC' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (liner_control_B.Saturation > liner_control_P.DAC_UpperSat) {
    y = liner_control_P.DAC_UpperSat;
  } else if (liner_control_B.Saturation < liner_control_P.DAC_LowerSat) {
    y = liner_control_P.DAC_LowerSat;
  } else {
    y = liner_control_B.Saturation;
  }

  liner_control_B.DAC[0] = y;
  if (liner_control_P.Constant_Value > liner_control_P.DAC_UpperSat) {
    y = liner_control_P.DAC_UpperSat;
  } else if (liner_control_P.Constant_Value < liner_control_P.DAC_LowerSat) {
    y = liner_control_P.DAC_LowerSat;
  } else {
    y = liner_control_P.Constant_Value;
  }

  liner_control_B.DAC[1] = y;
  if (liner_control_P.Constant_Value > liner_control_P.DAC_UpperSat) {
    y = liner_control_P.DAC_UpperSat;
  } else if (liner_control_P.Constant_Value < liner_control_P.DAC_LowerSat) {
    y = liner_control_P.DAC_LowerSat;
  } else {
    y = liner_control_P.Constant_Value;
  }

  liner_control_B.DAC[2] = y;
  if (liner_control_P.Constant_Value > liner_control_P.DAC_UpperSat) {
    y = liner_control_P.DAC_UpperSat;
  } else if (liner_control_P.Constant_Value < liner_control_P.DAC_LowerSat) {
    y = liner_control_P.DAC_LowerSat;
  } else {
    y = liner_control_P.Constant_Value;
  }

  liner_control_B.DAC[3] = y;
  if (liner_control_B.Gain > liner_control_P.DAC_UpperSat) {
    y = liner_control_P.DAC_UpperSat;
  } else if (liner_control_B.Gain < liner_control_P.DAC_LowerSat) {
    y = liner_control_P.DAC_LowerSat;
  } else {
    y = liner_control_B.Gain;
  }

  liner_control_B.DAC[4] = y;
  if (liner_control_P.Constant_Value > liner_control_P.DAC_UpperSat) {
    y = liner_control_P.DAC_UpperSat;
  } else if (liner_control_P.Constant_Value < liner_control_P.DAC_LowerSat) {
    y = liner_control_P.DAC_LowerSat;
  } else {
    y = liner_control_P.Constant_Value;
  }

  liner_control_B.DAC[5] = y;
  if (liner_control_P.Constant_Value > liner_control_P.DAC_UpperSat) {
    y = liner_control_P.DAC_UpperSat;
  } else if (liner_control_P.Constant_Value < liner_control_P.DAC_LowerSat) {
    y = liner_control_P.DAC_LowerSat;
  } else {
    y = liner_control_P.Constant_Value;
  }

  liner_control_B.DAC[6] = y;
  if (liner_control_P.Constant_Value > liner_control_P.DAC_UpperSat) {
    y = liner_control_P.DAC_UpperSat;
  } else if (liner_control_P.Constant_Value < liner_control_P.DAC_LowerSat) {
    y = liner_control_P.DAC_LowerSat;
  } else {
    y = liner_control_P.Constant_Value;
  }

  liner_control_B.DAC[7] = y;

  /* End of Saturate: '<S4>/DAC' */

  /* S-Function (dam148ctrl): '<S4>/dac' */

  /* Level2 S-Function Block: '<S4>/dac' (dam148ctrl) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S5>/data_ch' */
  liner_control_B.data_ch[0] = liner_control_P.data_ch_Gain *
    liner_control_B.X_position;
  liner_control_B.data_ch[1] = liner_control_P.data_ch_Gain *
    liner_control_B.X_position_o;
  liner_control_B.data_ch[2] = liner_control_P.data_ch_Gain *
    liner_control_B.X_e_position;
  liner_control_B.data_ch[3] = liner_control_P.data_ch_Gain *
    liner_control_B.X_e_position_f;
  liner_control_B.data_ch[4] = liner_control_P.data_ch_Gain *
    liner_control_B.Saturation;
  liner_control_B.data_ch[5] = liner_control_P.data_ch_Gain *
    liner_control_B.Gain;
  liner_control_B.data_ch[6] = liner_control_P.data_ch_Gain *
    liner_control_B.Sum9;
  liner_control_B.data_ch[7] = liner_control_P.data_ch_Gain *
    liner_control_B.Diff_p;

  /* Constant: '<Root>/Constant1' */
  liner_control_B.Constant1 = liner_control_P.Constant1_Value;

  /* S-Function (to_memory_rt): '<S5>/to_memory_rt' */

  /* Level2 S-Function Block: '<S5>/to_memory_rt' (to_memory_rt) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Gain: '<S6>/input_ch' */
  liner_control_B.input_ch[0] = liner_control_P.input_ch_Gain *
    liner_control_B.X_position;
  liner_control_B.input_ch[1] = liner_control_P.input_ch_Gain *
    liner_control_B.X_position_o;
  liner_control_B.input_ch[2] = liner_control_P.input_ch_Gain *
    liner_control_B.X_e_position;
  liner_control_B.input_ch[3] = liner_control_P.input_ch_Gain *
    liner_control_B.X_e_position_f;
  liner_control_B.input_ch[4] = liner_control_P.input_ch_Gain *
    liner_control_B.Saturation;
  liner_control_B.input_ch[5] = liner_control_P.input_ch_Gain *
    liner_control_B.Gain;
  liner_control_B.input_ch[6] = liner_control_P.input_ch_Gain *
    liner_control_B.Sum9;
  liner_control_B.input_ch[7] = liner_control_P.input_ch_Gain *
    liner_control_B.Diff_p;

  /* S-Function (to_host_rt): '<S6>/to_host_rt' */

  /* Level2 S-Function Block: '<S6>/to_host_rt' (to_host_rt) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  if (liner_control_M->Timing.TaskCounters.TID[1] == 0) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    liner_control_B.PulseGenerator = (liner_control_DW.clockTickCounter <
      liner_control_P.PulseGenerator_Duty) && (liner_control_DW.clockTickCounter
      >= 0) ? liner_control_P.PulseGenerator_Amp : 0.0;
    if (liner_control_DW.clockTickCounter >=
        liner_control_P.PulseGenerator_Period - 1.0) {
      liner_control_DW.clockTickCounter = 0;
    } else {
      liner_control_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */
  }

  /* Update for UnitDelay: '<S1>/UD' */
  liner_control_DW.UD_DSTATE = liner_control_B.TSamp;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/integrate_reset'
   */
  liner_control_DW.DiscreteTimeIntegrator_DSTATE =
    liner_control_B.DiscreteTimeIntegrator;
  if (liner_control_P.integrate_reset_Value > 0.0) {
    liner_control_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (liner_control_P.integrate_reset_Value < 0.0) {
    liner_control_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (liner_control_P.integrate_reset_Value == 0.0) {
    liner_control_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    liner_control_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S2>/UD' */
  liner_control_DW.UD_DSTATE_l = liner_control_B.TSamp_g;

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' incorporates:
   *  Constant: '<Root>/integrate_reset1'
   */
  liner_control_DW.DiscreteTimeIntegrator1_DSTATE =
    liner_control_B.DiscreteTimeIntegrator1;
  if (liner_control_P.integrate_reset1_Value > 0.0) {
    liner_control_DW.DiscreteTimeIntegrator1_PrevRes = 1;
  } else if (liner_control_P.integrate_reset1_Value < 0.0) {
    liner_control_DW.DiscreteTimeIntegrator1_PrevRes = -1;
  } else if (liner_control_P.integrate_reset1_Value == 0.0) {
    liner_control_DW.DiscreteTimeIntegrator1_PrevRes = 0;
  } else {
    liner_control_DW.DiscreteTimeIntegrator1_PrevRes = 2;
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++liner_control_M->Timing.clockTick0)) {
    ++liner_control_M->Timing.clockTickH0;
  }

  liner_control_M->Timing.t[0] = liner_control_M->Timing.clockTick0 *
    liner_control_M->Timing.stepSize0 + liner_control_M->Timing.clockTickH0 *
    liner_control_M->Timing.stepSize0 * 4294967296.0;
  rate_scheduler();
}

/* Model initialize function */
void liner_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)liner_control_M, 0,
                sizeof(RT_MODEL_liner_control_T));
  rtsiSetSolverName(&liner_control_M->solverInfo,"FixedStepDiscrete");
  liner_control_M->solverInfoPtr = (&liner_control_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = liner_control_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    liner_control_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    liner_control_M->Timing.sampleTimes =
      (&liner_control_M->Timing.sampleTimesArray[0]);
    liner_control_M->Timing.offsetTimes =
      (&liner_control_M->Timing.offsetTimesArray[0]);

    /* task periods */
    liner_control_M->Timing.sampleTimes[0] = (0.01);
    liner_control_M->Timing.sampleTimes[1] = (1.0);

    /* task offsets */
    liner_control_M->Timing.offsetTimes[0] = (0.0);
    liner_control_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(liner_control_M, &liner_control_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = liner_control_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    liner_control_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(liner_control_M, -1);
  liner_control_M->Timing.stepSize0 = 0.01;
  liner_control_M->solverInfoPtr = (&liner_control_M->solverInfo);
  liner_control_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&liner_control_M->solverInfo, 0.01);
  rtsiSetSolverMode(&liner_control_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      liner_control_B.icounter[i] = 0.0;
    }

    for (i = 0; i < 8; i++) {
      liner_control_B.DAC[i] = 0.0;
    }

    for (i = 0; i < 8; i++) {
      liner_control_B.data_ch[i] = 0.0;
    }

    for (i = 0; i < 8; i++) {
      liner_control_B.input_ch[i] = 0.0;
    }

    liner_control_B.X_manual_switch = 0.0;
    liner_control_B.X_position = 0.0;
    liner_control_B.FromWorkspace[0] = 0.0;
    liner_control_B.FromWorkspace[1] = 0.0;
    liner_control_B.ManualSwitch = 0.0;
    liner_control_B.X_e_position = 0.0;
    liner_control_B.X_input_volt_control = 0.0;
    liner_control_B.TSamp = 0.0;
    liner_control_B.Uk1 = 0.0;
    liner_control_B.Diff = 0.0;
    liner_control_B.FromWorkspace1[0] = 0.0;
    liner_control_B.FromWorkspace1[1] = 0.0;
    liner_control_B.Sum9 = 0.0;
    liner_control_B.X_input_volt_control_a = 0.0;
    liner_control_B.DiscreteTimeIntegrator = 0.0;
    liner_control_B.input_volt_control = 0.0;
    liner_control_B.X_control_input_volt = 0.0;
    liner_control_B.X_fric_comp_switch = 0.0;
    liner_control_B.Sum3 = 0.0;
    liner_control_B.X_control_switch = 0.0;
    liner_control_B.X_input_volt = 0.0;
    liner_control_B.Saturation = 0.0;
    liner_control_B.Y1_manual_switch1 = 0.0;
    liner_control_B.X_position_o = 0.0;
    liner_control_B.X_e_position_f = 0.0;
    liner_control_B.X_input_volt_control_o = 0.0;
    liner_control_B.TSamp_g = 0.0;
    liner_control_B.Uk1_a = 0.0;
    liner_control_B.Diff_p = 0.0;
    liner_control_B.Sum10 = 0.0;
    liner_control_B.X_input_volt_control_n = 0.0;
    liner_control_B.DiscreteTimeIntegrator1 = 0.0;
    liner_control_B.input_volt_control_k = 0.0;
    liner_control_B.X_control_input_volt_n = 0.0;
    liner_control_B.Y1_fric_comp_switch = 0.0;
    liner_control_B.Sum7 = 0.0;
    liner_control_B.Y1_control_switch = 0.0;
    liner_control_B.X_input_volt_e = 0.0;
    liner_control_B.Saturation1 = 0.0;
    liner_control_B.Gain = 0.0;
    liner_control_B.Constant1 = 0.0;
    liner_control_B.PulseGenerator = 0.0;
    liner_control_B.X_feedback_manual_switch1 = 0.0;
    liner_control_B.sf_frictioncompensationbymatl_o.input_fric_compen = 0.0;
    liner_control_B.sf_frictioncompensationbymatlab.input_fric_compen = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&liner_control_DW, 0,
                sizeof(DW_liner_control_T));
  liner_control_DW.UD_DSTATE = 0.0;
  liner_control_DW.DiscreteTimeIntegrator_DSTATE = 0.0;
  liner_control_DW.UD_DSTATE_l = 0.0;
  liner_control_DW.DiscreteTimeIntegrator1_DSTATE = 0.0;

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  liner_control_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &liner_control_M->NonInlinedSFcns.sfcnInfo;
    liner_control_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(liner_control_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &liner_control_M->Sizes.numSampTimes);
    liner_control_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (liner_control_M)[0]);
    liner_control_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (liner_control_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,liner_control_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(liner_control_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(liner_control_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(liner_control_M));
    rtssSetStepSizePtr(sfcnInfo, &liner_control_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(liner_control_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &liner_control_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &liner_control_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &liner_control_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &liner_control_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &liner_control_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &liner_control_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &liner_control_M->solverInfoPtr);
  }

  liner_control_M->Sizes.numSFcns = (4);

  /* register each child */
  {
    (void) memset((void *)&liner_control_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  4*sizeof(SimStruct));
    liner_control_M->childSfunctions =
      (&liner_control_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    liner_control_M->childSfunctions[0] =
      (&liner_control_M->NonInlinedSFcns.childSFunctions[0]);
    liner_control_M->childSfunctions[1] =
      (&liner_control_M->NonInlinedSFcns.childSFunctions[1]);
    liner_control_M->childSfunctions[2] =
      (&liner_control_M->NonInlinedSFcns.childSFunctions[2]);
    liner_control_M->childSfunctions[3] =
      (&liner_control_M->NonInlinedSFcns.childSFunctions[3]);

    /* Level2 S-Function Block: liner_control/<S3>/icounter (udcm6_sep) */
    {
      SimStruct *rts = liner_control_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = liner_control_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = liner_control_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = liner_control_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &liner_control_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &liner_control_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, liner_control_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &liner_control_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &liner_control_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &liner_control_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &liner_control_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &liner_control_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 6);
          ssSetOutputPortSignal(rts, 0, ((real_T *) liner_control_B.icounter));
        }
      }

      /* path info */
      ssSetModelName(rts, "icounter");
      ssSetPath(rts, "liner_control/SBOX2_CNT6/icounter");
      ssSetRTModel(rts,liner_control_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &liner_control_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 32);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)liner_control_P.icounter_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)liner_control_P.icounter_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)liner_control_P.icounter_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)liner_control_P.icounter_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)liner_control_P.icounter_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)liner_control_P.icounter_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)liner_control_P.icounter_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)liner_control_P.icounter_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)liner_control_P.icounter_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)liner_control_P.icounter_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)liner_control_P.icounter_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)liner_control_P.icounter_P12_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)liner_control_P.icounter_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)liner_control_P.icounter_P14_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)liner_control_P.icounter_P15_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)liner_control_P.icounter_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)liner_control_P.icounter_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)liner_control_P.icounter_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)liner_control_P.icounter_P19_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)liner_control_P.icounter_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)liner_control_P.icounter_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)liner_control_P.icounter_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)liner_control_P.icounter_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)liner_control_P.icounter_P24_Size);
        ssSetSFcnParam(rts, 24, (mxArray*)liner_control_P.icounter_P25_Size);
        ssSetSFcnParam(rts, 25, (mxArray*)liner_control_P.icounter_P26_Size);
        ssSetSFcnParam(rts, 26, (mxArray*)liner_control_P.icounter_P27_Size);
        ssSetSFcnParam(rts, 27, (mxArray*)liner_control_P.icounter_P28_Size);
        ssSetSFcnParam(rts, 28, (mxArray*)liner_control_P.icounter_P29_Size);
        ssSetSFcnParam(rts, 29, (mxArray*)liner_control_P.icounter_P30_Size);
        ssSetSFcnParam(rts, 30, (mxArray*)liner_control_P.icounter_P31_Size);
        ssSetSFcnParam(rts, 31, (mxArray*)liner_control_P.icounter_P32_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &liner_control_DW.icounter_IWORK);
      ssSetPWork(rts, (void **) &liner_control_DW.icounter_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &liner_control_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &liner_control_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &liner_control_DW.icounter_IWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &liner_control_DW.icounter_PWORK);
      }

      /* registration */
      udcm6_sep(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: liner_control/<S4>/dac (dam148ctrl) */
    {
      SimStruct *rts = liner_control_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = liner_control_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = liner_control_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = liner_control_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &liner_control_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &liner_control_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, liner_control_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &liner_control_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &liner_control_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &liner_control_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &liner_control_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &liner_control_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, liner_control_B.DAC);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "dac");
      ssSetPath(rts, "liner_control/SBOX2_DAM148 /dac");
      ssSetRTModel(rts,liner_control_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &liner_control_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)liner_control_P.dac_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)liner_control_P.dac_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)liner_control_P.dac_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)liner_control_P.dac_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)liner_control_P.dac_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)liner_control_P.dac_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)liner_control_P.dac_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)liner_control_P.dac_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)liner_control_P.dac_P9_Size);
      }

      /* registration */
      dam148ctrl(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: liner_control/<S5>/to_memory_rt (to_memory_rt) */
    {
      SimStruct *rts = liner_control_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = liner_control_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = liner_control_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = liner_control_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &liner_control_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &liner_control_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, liner_control_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &liner_control_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &liner_control_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &liner_control_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &liner_control_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &liner_control_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, liner_control_B.data_ch);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &liner_control_B.Constant1);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "to_memory_rt");
      ssSetPath(rts, "liner_control/SBOX2_DATA_SAVE_NET/to_memory_rt");
      ssSetRTModel(rts,liner_control_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &liner_control_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)liner_control_P.to_memory_rt_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)liner_control_P.to_memory_rt_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)liner_control_P.to_memory_rt_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)liner_control_P.to_memory_rt_P4_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &liner_control_DW.to_memory_rt_IWORK);
      ssSetPWork(rts, (void **) &liner_control_DW.to_memory_rt_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &liner_control_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &liner_control_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &liner_control_DW.to_memory_rt_IWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &liner_control_DW.to_memory_rt_PWORK);
      }

      /* registration */
      to_memory_rt(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 8);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: liner_control/<S6>/to_host_rt (to_host_rt) */
    {
      SimStruct *rts = liner_control_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = liner_control_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = liner_control_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = liner_control_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &liner_control_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &liner_control_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, liner_control_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &liner_control_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &liner_control_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &liner_control_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &liner_control_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &liner_control_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &liner_control_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, liner_control_B.input_ch);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "to_host_rt");
      ssSetPath(rts, "liner_control/SBOX2_GRAPH_MONITOR/to_host_rt");
      ssSetRTModel(rts,liner_control_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &liner_control_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)liner_control_P.to_host_rt_P1_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &liner_control_DW.to_host_rt_IWORK);
      ssSetPWork(rts, (void **) &liner_control_DW.to_host_rt_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &liner_control_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &liner_control_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &liner_control_DW.to_host_rt_IWORK);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &liner_control_DW.to_host_rt_PWORK);
      }

      /* registration */
      to_host_rt(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 8);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Start for FromWorkspace: '<Root>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06,
      0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
      0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31,
      0.32, 0.33, 0.34, 0.35000000000000003, 0.36, 0.37, 0.38, 0.39, 0.4,
      0.41000000000000003, 0.42, 0.43, 0.44, 0.45, 0.46, 0.47000000000000003,
      0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57000000000000006,
      0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68,
      0.69000000000000006, 0.70000000000000007, 0.71, 0.72, 0.73, 0.74, 0.75,
      0.76, 0.77, 0.78, 0.79, 0.8, 0.81, 0.82000000000000006,
      0.83000000000000007, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94000000000000006, 0.95000000000000007, 0.96, 0.97, 0.98, 0.99,
      1.0, 1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12,
      1.1300000000000001, 1.1400000000000001, 1.1500000000000001, 1.16, 1.17,
      1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3,
      1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.3800000000000001,
      1.3900000000000001, 1.4000000000000001, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
      1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58,
      1.59, 1.5999999999999999, 1.6099999999999999, 1.6199999999999999, 1.63,
      1.64, 1.65, 1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75,
      1.76, 1.77, 1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.8499999999999999,
      1.8599999999999999, 1.8699999999999999, 1.88, 1.89, 1.9, 1.91, 1.92, 1.93,
      1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0, 2.01, 2.02, 2.0300000000000002,
      2.04, 2.05, 2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15,
      2.16, 2.17, 2.1799999999999997, 2.19, 2.2, 2.21, 2.2199999999999998, 2.23,
      2.24, 2.25, 2.26, 2.27, 2.2800000000000002, 2.29, 2.3, 2.31, 2.32, 2.33,
      2.34, 2.35, 2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.4299999999999997,
      2.44, 2.45, 2.46, 2.4699999999999998, 2.48, 2.49, 2.5, 2.51, 2.52, 2.53,
      2.54, 2.55, 2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65,
      2.66, 2.67, 2.68, 2.69, 2.7, 2.71, 2.7199999999999998, 2.73, 2.74, 2.75,
      2.76, 2.77, 2.78, 2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87,
      2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0
    } ;

    static real_T pDataValues0[] = { 0.0, 0.0013341028537814381,
      0.0026682057075628762, 0.0040023085613443143, 0.0053364114151257525,
      0.0066705142689071906, 0.0080046171226886287, 0.0093387199764700668,
      0.010672822830251505, 0.012006925684032943, 0.013341028537814381,
      0.014675131391595819, 0.016009234245377257, 0.017343337099158695,
      0.018677439952940134, 0.020011542806721572, 0.02134564566050301,
      0.022679748514284448, 0.024013851368065886, 0.025347954221847324,
      0.026682057075628762, 0.0280161599294102, 0.029350262783191639,
      0.030684365636973077, 0.032018468490754515, 0.033352571344535953,
      0.034686674198317391, 0.036020777052098829, 0.037354879905880267,
      0.038688982759661705, 0.040023085613443143, 0.041357188467224582,
      0.04269129132100602, 0.044025394174787458, 0.045359497028568896,
      0.046693599882350334, 0.048027702736131772, 0.04936180558991321,
      0.050695908443694648, 0.052030011297476086, 0.053364114151257525,
      0.054698217005038963, 0.0560323198588204, 0.057366422712601839,
      0.058700525566383277, 0.060034628420164715, 0.061368731273946153,
      0.062702834127727591, 0.064036936981509029, 0.065371039835290468,
      0.0667051426890719, 0.068039245542853344, 0.069373348396634782,
      0.07070745125041622, 0.072041554104197658, 0.0733756569579791,
      0.074709759811760534, 0.076043862665541972, 0.077377965519323411,
      0.078712068373104849, 0.080046171226886287, 0.081380274080667725,
      0.082714376934449163, 0.0840484797882306, 0.085382582642012039,
      0.086716685495793477, 0.088050788349574916, 0.089384891203356354,
      0.090718994057137792, 0.09205309691091923, 0.093387199764700668,
      0.0947213026184821, 0.096055405472263544, 0.097389508326044982,
      0.09872361117982642, 0.10005771403360786, 0.1013918168873893,
      0.10272591974117073, 0.10406002259495217, 0.10539412544873361,
      0.10672822830251505, 0.10806233115629649, 0.10939643401007793,
      0.11073053686385936, 0.1120646397176408, 0.11339874257142224,
      0.11473284542520368, 0.11606694827898512, 0.11740105113276655,
      0.11873515398654799, 0.12006925684032943, 0.12140335969411087,
      0.12273746254789231, 0.12407156540167374, 0.12540566825545518,
      0.12673977110923662, 0.12807387396301806, 0.1294079768167995,
      0.51744000010220059, 0.76436000014927785, 1.0035200001937357,
      1.235000000235619, 1.4588800002749762, 1.6752400003118533,
      1.8841600003462977, 2.0857200003783554, 2.2800000004080738,
      2.467080000435498, 2.6470400004606756, 2.819960000483654,
      2.9859200005044793, 3.1450000005231971, 3.2972800005398568,
      3.4428400005545043, 3.5817600005671828, 3.7141200005779442,
      3.8400000005868336, 3.9594800005938922, 4.0726400005991739,
      4.1795600006027218, 4.2803200006045845, 4.3750000006048069,
      4.4636800006034374, 4.5464400006005192, 4.623360000596108,
      4.6945200005902361, 4.760000000582961, 4.8198800005743294,
      4.8742400005643844, 4.923160000553171, 4.9667200005407395,
      5.0050000005271365, 5.0380800005124069, 5.0660400004965975,
      5.08896000047976, 5.1069200004619315, 5.1200000004431665,
      5.1282800004235067, 5.1318400004030043, 5.1307600003816987,
      5.1251200003596455, 5.1150000003368845, 5.1004800003134623,
      5.0816400002894273, 5.05856000026483, 5.0313200002397149,
      5.0000000002141256, 4.964680000188114, 4.92544000016172,
      4.8823600001349927, 4.8355200001079819, 4.78500000008073, 4.73088000005329,
      4.6732400000257055, 4.612159999998017, 4.5477199999702833,
      4.4799999999425371, 4.4090799999148373, 4.33503999988722,
      4.2579599998597448, 4.1779199998324472, 4.0949999998053777,
      4.0092799997785828, 3.9208399997521148, 3.8297599997260079,
      3.7361199997003194, 3.6399999996750907, 3.5414799996503739,
      3.4406399996262085, 3.3375599996026466, 3.2323199995797349,
      3.1249999995575131, 3.0156799995360366, 2.9044399995153478,
      2.7913599994954952, 2.6765199994765236, 2.5599999994584817,
      2.4418799994414133, 2.3222399994253697, 2.2011599994103905,
      2.0787199993965313, 1.9549999993838281, 1.83007999937234,
      1.7040399993621023, 1.5769599993531722, 1.448919999345585,
      1.3199999993393989, 1.19027999933465, 1.0598399993313929,
      0.92875999932966824, 0.7971199993295297, 0.6649999993310205,
      0.532479999334182, 0.39963999933907068, 0.26655999934572705,
      0.1333199993541978, -6.354685666565274E-10, -0.133320000623244,
      -0.26656000060917151, -0.39964000059331095, -0.532480000575724,
      -0.66500000055647224, -0.79712000053561738, -0.9287600005132175,
      -1.0598400004893369, -1.1902800004640337, -1.32000000043737,
      -1.4489200004094083, -1.5769600003802062, -1.7040400003498237,
      -1.8300800003183291, -1.955000000285779, -2.0787200002522339,
      -2.2011600002177549, -2.3222400001824033, -2.4418800001462397,
      -2.5600000001093264, -2.6765200000717222, -2.79136000003349,
      -2.9044399999946897, -3.0156799999553829, -3.12499999991563,
      -3.2323199998754926, -3.3375599998350305, -3.4406399997943051,
      -3.5414799997533786, -3.6399999997123107, -3.7361199996711631,
      -3.8297599996299958, -3.9208399995888708, -4.0092799995478483,
      -4.09499999950699, -4.1779199994663561, -4.2579599994260082,
      -4.3350399993860051, -4.409079999346412, -4.479999999307287,
      -4.5477199992686925, -4.6121599992306876, -4.6732399991933331,
      -4.7308799991566932, -4.7849999991208261, -4.8355199990857933,
      -4.8823599990516566, -4.925439999018475, -4.9646799989863117,
      -4.9999999989552268, -5.03131999892528, -5.0585599988965351,
      -5.08163999886905, -5.1004799988428884, -5.1149999988181083,
      -5.1251199987947738, -5.1307599987729438, -5.13183999875268,
      -5.1282799987340439, -5.1199999987170948, -5.1069199987018941,
      -5.0889599986885035, -5.0660399986769855, -5.0380799986673992,
      -5.0049999986598044, -4.9667199986542645, -4.9231599986508385,
      -4.874239998649589, -4.8198799986505749, -4.75999999865386,
      -4.6945199986595032, -4.6233599986675653, -4.5464399986781086,
      -4.4636799986911937, -4.3749999987068815, -4.2803199987252309,
      -4.1795599987463072, -4.0726399987701676, -3.9594799987968745,
      -3.8399999988264888, -3.7141199988590712, -3.5817599988946833,
      -3.4428399989333855, -3.2972799989752395, -3.144999999020305,
      -2.9859199990686438, -2.8199599991203161, -2.6470399991753886,
      -2.467079999233913, -2.2799999992959536, -2.0857199993615732,
      -1.8841599994308313, -1.675239999503789, -1.4588799995805082,
      -1.2349999996610492, -1.0035199997454725, -0.7643599998338404,
      -0.51743999992621248, -0.26268000002265079, -1.2321521580815897E-10, 0.0,
      0.0, 0.0, 0.0, 0.0, 3.0652333057936032E-5, 6.1304666115872064E-5,
      9.1956999173808089E-5, 0.00012260933223174413, 0.00015326166528968017,
      0.00018391399834761621, 0.00021456633140555224, 0.00024521866446348826,
      0.00027587099752142429, 0.00030652333057936033, 0.00033717566363729637,
      0.00036782799669523241, 0.00039848032975316845, 0.00042913266281110449,
      0.00045978499586904053, 0.00049043732892697651, 0.0005210896619849125,
      0.00055174199504284848, 0.00058239432810078446, 0.00061304666115872045,
      0.00064369899421665643, 0.00067435132727459242, 0.0007050036603325284,
      0.00073565599339046439, 0.00076630832644840037, 0.00079696065950633636,
      0.00082761299256427234, 0.00085826532562220832, 0.00088891765868014431,
      0.00091956999173808029, 0.00095022232479601628, 0.00098087465785395237,
      0.0010115269909118884, 0.0010421793239698243, 0.0010728316570277603,
      0.0011034839900856963, 0.0011341363231436323, 0.0011647886562015683,
      0.0011954409892595043, 0.0012260933223174402, 0.0012567456553753762,
      0.0012873979884333122, 0.0013180503214912482, 0.0013487026545491842,
      0.0013793549876071202, 0.0014100073206650562, 0.0014406596537229921,
      0.0014713119867809281, 0.0015019643198388641, 0.0015326166528968,
      0.0015632689859547361, 0.0015939213190126721, 0.001624573652070608,
      0.001655225985128544, 0.00168587831818648, 0.001716530651244416,
      0.001747182984302352, 0.001777835317360288, 0.001808487650418224,
      0.00183913998347616, 0.0018697923165340959, 0.0019004446495920319,
      0.0019310969826499679, 0.0019617493157079039, 0.00199240164876584,
      0.0020230539818237763, 0.0020537063148817125, 0.0020843586479396487,
      0.0021150109809975849, 0.0021456633140555211, 0.0021763156471134573,
      0.0022069679801713935, 0.0022376203132293297, 0.0022682726462872659,
      0.0022989249793452021, 0.0023295773124031383, 0.0023602296454610745,
      0.0023908819785190107, 0.0024215343115769469, 0.0024521866446348831,
      0.0024828389776928193, 0.0025134913107507555, 0.0025441436438086917,
      0.0025747959768666279, 0.0026054483099245641, 0.0026361006429825003,
      0.0026667529760404365, 0.0026974053090983727, 0.0027280576421563089,
      0.0027587099752142451, 0.0027893623082721813, 0.0028200146413301175,
      0.0028506669743880537, 0.00288131930744599, 0.0029119716405039261,
      0.0029426239735618623, 0.0029732763066197985, 0.011848084362042259,
      0.02647182681829454, 0.046735373800463144, 0.072518728565369742,
      0.10370189436983594, 0.14016487447068351, 0.18178767212473398,
      0.22845029058880917, 0.28003273311973059, 0.33641500297432003,
      0.39747710340939907, 0.46309903768178945, 0.53316080904831276,
      0.60754242076579057, 0.68612387609104464, 0.76878517828089687,
      0.85540633059216853, 0.94586733628168151, 1.040048198606258,
      1.1378289208227179, 1.2390895061878844, 1.3437099579585794,
      1.4515702793916234, 1.5625504737438392, 1.6765305442720477,
      1.7933904942330705, 1.91301032688373, 2.0352700454808468,
      2.1600496532812432, 2.2872291535417411, 2.4166885495191623,
      2.5483078444703278, 2.6819670416520593, 2.8175461443211778,
      2.9549251557345082, 3.0939840791488677, 3.2346029178210816,
      3.376661675007969, 3.520040353966353, 3.6646189579530541,
      3.810277490224895, 3.9568959540386976, 4.1043543526512831,
      4.252532689319473, 4.4013109673000885, 4.5505691898499512,
      4.7001873602258852, 4.85004548168471, 5.0000235574832468,
      5.1500015908783183, 5.2998595851267485, 5.4494775434853517,
      5.5987354692109577, 5.7475133655603843, 5.8956912357904532,
      6.0431490831579868, 6.1897669109198059, 6.3354247223327347,
      6.48000252065359, 6.6233803091392005, 6.7654380910463807,
      6.9060558696319552, 7.0451136481527472, 7.1824914298655766,
      7.3180692180272651, 7.4517270158946376, 7.5833448267245087,
      7.7128026537737018, 7.8399805002990464, 7.9647583695573578,
      8.0870162648054578, 8.20663418930017, 8.3234921462983138,
      8.4374701390567122, 8.5484481708321844, 8.65630624488156,
      8.7609243644616512, 8.8621825328292836, 8.9599607532412779,
      9.05413902895446, 9.1445973632256443, 9.2312157593116577,
      9.3138742204693212, 9.3924527499554546, 9.4668313510268813,
      9.5368900269404211, 9.6025087809529, 9.663567616321135, 9.71994653630195,
      9.7715255441521638, 9.8181846431286033, 9.8598038364880836,
      9.8962631274874333, 9.9274425193834688, 9.9532220154330151,
      9.9734816188928921, 9.98810133301992, 9.9969611610709244,
      9.9999411063027228, 9.9969611708826065, 9.9881013526197258,
      9.97348164823371, 9.9532220544441721, 9.9274425679707328,
      9.8962631855330176, 9.8598039038506453, 9.8181847196432361,
      9.7715256296304123, 9.7199466305317941, 9.663567719067002,
      9.602508891955658, 9.5368901459173827, 9.4668314776717963,
      9.3924528839385175, 9.31387436143717, 9.2312159068873747,
      9.1445975170087515, 9.0541391885209244, 8.9599609181435085,
      8.86218270259613, 8.760924538598406, 8.6563064228699584,
      8.5484483521304089, 8.43747032309938, 8.3234923324964889,
      8.2066343770413575, 8.0870164534536091, 7.9647585584528615,
      7.8399806887587369, 7.7128028410908556, 7.5833450121688415,
      7.4517271987123115, 7.3180693974408877, 7.1824916050741923,
      7.0451138183318447, 6.9060560339334671, 6.7654382485986817,
      6.6233804590471044, 6.4800026619983591, 6.3354248541720652,
      6.1897670322878469, 6.0431491930653216, 5.8956913332241108,
      5.7475134494838382, 5.5987355385641218, 5.4494775971845835,
      5.2998596220648446, 5.1500016099245238, 5.0000235574832441,
      4.8500454614606259, 4.70018731857629, 4.5505691255498562,
      4.401310879100949, 4.2525325759491857, 4.1043542128141874,
      3.9568957864155756, 3.8102772934729718, 3.664618730705997,
      3.5200400948342709, 3.3766613825774159, 3.2346025906550504,
      3.0939837157868006, 2.95492475469228, 2.8175457040911143,
      2.6819665607029215, 2.548307321247326, 2.4166879824439449,
      2.2872285410124022, 2.1600489936723171, 2.0352693371433115,
      1.9130095681450048, 1.7933896833970191, 1.6765296796189757,
      1.5625495535304939, 1.4515693018511955, 1.3437089213007012,
      1.2390884085986325, 1.1378277604646092, 1.0400469736182527,
      0.94586604477918423, 0.85540497066702414, 0.76878374800139337,
      0.686122373501913, 0.60754084388820406, 0.53315915587988671,
      0.46309730619658257, 0.39747529155791361, 0.33641310868349783,
      0.28003075429295748, 0.22844822510591367, 0.18178551784198721,
      0.14016262922079883, 0.10369955596196957, 0.072516294785120256,
      0.0467328424098717, 0.026469195555844868, 0.011845350942660588,
      0.0029813052899397416, -2.9446826967927109E-6, 0.0, 0.0, 0.0, 0.0 } ;

    liner_control_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    liner_control_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    liner_control_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<Root>/From Workspace1' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06,
      0.07, 0.08, 0.09, 0.1, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18,
      0.19, 0.2, 0.21, 0.22, 0.23, 0.24, 0.25, 0.26, 0.27, 0.28, 0.29, 0.3, 0.31,
      0.32, 0.33, 0.34, 0.35000000000000003, 0.36, 0.37, 0.38, 0.39, 0.4,
      0.41000000000000003, 0.42, 0.43, 0.44, 0.45, 0.46, 0.47000000000000003,
      0.48, 0.49, 0.5, 0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57000000000000006,
      0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68,
      0.69000000000000006, 0.70000000000000007, 0.71, 0.72, 0.73, 0.74, 0.75,
      0.76, 0.77, 0.78, 0.79, 0.8, 0.81, 0.82000000000000006,
      0.83000000000000007, 0.84, 0.85, 0.86, 0.87, 0.88, 0.89, 0.9, 0.91, 0.92,
      0.93, 0.94000000000000006, 0.95000000000000007, 0.96, 0.97, 0.98, 0.99,
      1.0, 1.01, 1.02, 1.03, 1.04, 1.05, 1.06, 1.07, 1.08, 1.09, 1.1, 1.11, 1.12,
      1.1300000000000001, 1.1400000000000001, 1.1500000000000001, 1.16, 1.17,
      1.18, 1.19, 1.2, 1.21, 1.22, 1.23, 1.24, 1.25, 1.26, 1.27, 1.28, 1.29, 1.3,
      1.31, 1.32, 1.33, 1.34, 1.35, 1.36, 1.37, 1.3800000000000001,
      1.3900000000000001, 1.4000000000000001, 1.41, 1.42, 1.43, 1.44, 1.45, 1.46,
      1.47, 1.48, 1.49, 1.5, 1.51, 1.52, 1.53, 1.54, 1.55, 1.56, 1.57, 1.58,
      1.59, 1.5999999999999999, 1.6099999999999999, 1.6199999999999999, 1.63,
      1.64, 1.65, 1.66, 1.67, 1.68, 1.69, 1.7, 1.71, 1.72, 1.73, 1.74, 1.75,
      1.76, 1.77, 1.78, 1.79, 1.8, 1.81, 1.82, 1.83, 1.84, 1.8499999999999999,
      1.8599999999999999, 1.8699999999999999, 1.88, 1.89, 1.9, 1.91, 1.92, 1.93,
      1.94, 1.95, 1.96, 1.97, 1.98, 1.99, 2.0, 2.01, 2.02, 2.0300000000000002,
      2.04, 2.05, 2.06, 2.07, 2.08, 2.09, 2.1, 2.11, 2.12, 2.13, 2.14, 2.15,
      2.16, 2.17, 2.1799999999999997, 2.19, 2.2, 2.21, 2.2199999999999998, 2.23,
      2.24, 2.25, 2.26, 2.27, 2.2800000000000002, 2.29, 2.3, 2.31, 2.32, 2.33,
      2.34, 2.35, 2.36, 2.37, 2.38, 2.39, 2.4, 2.41, 2.42, 2.4299999999999997,
      2.44, 2.45, 2.46, 2.4699999999999998, 2.48, 2.49, 2.5, 2.51, 2.52, 2.53,
      2.54, 2.55, 2.56, 2.57, 2.58, 2.59, 2.6, 2.61, 2.62, 2.63, 2.64, 2.65,
      2.66, 2.67, 2.68, 2.69, 2.7, 2.71, 2.7199999999999998, 2.73, 2.74, 2.75,
      2.76, 2.77, 2.78, 2.79, 2.8, 2.81, 2.82, 2.83, 2.84, 2.85, 2.86, 2.87,
      2.88, 2.89, 2.9, 2.91, 2.92, 2.93, 2.94, 2.95, 2.96, 2.97, 2.98, 2.99, 3.0
    } ;

    static real_T pDataValues0[] = { 0.0, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.13341028537813593, 0.13341028537813593,
      0.13341028537813593, 0.69384503973314071, 0.68707337333669283,
      0.6589171316573923, 0.63128532521870251, 0.60421841119583908,
      0.57775328534525239, 0.55192368260566982, 0.52676004070946447,
      0.502290051773663, 0.47853789791256141, 0.45552425846076394,
      0.43326608387133569, 0.41177568748047311, 0.39106068203298727,
      0.37112292374864736, 0.35195832860806986, 0.3335561572707631,
      0.31589870788922697, 0.2989608659236187, 0.28271011784849887,
      0.26710677993684856, 0.25210412440764407, 0.2376492604478658,
      0.22368389140502362, 0.21014549280646883, 0.19696857966519055,
      0.18408607652823511, 0.17143075359996968, 0.15893668502223213,
      0.14654063411624793, 0.13418297777324559, 0.12180907093121161,
      0.10936969800137933, 0.096821913342454088, 0.084129254651356067,
      0.071262061513484187, 0.058197405798007286, 0.044919042877404593,
      0.031417193628580413, 0.017688215691776588, 0.0037342798423602693,
      -0.010437043085974984, -0.024813185075681032, -0.03937701200001531,
      -0.054107251420551838, -0.068978885702496093, -0.083963590250862169,
      -0.099030107303704915, -0.11414463825553607, -0.1292712150870747,
      -0.14437201269200067, -0.159407786989674, -0.17433812736511964,
      -0.18912180634171954, -0.20371713495853283, -0.21808219332450421,
      -0.23217527417264874, -0.24595498793522849, -0.25938069281557086,
      -0.27241271047066823, -0.28501265432930023, -0.297143583127963,
      -0.30877028207663348, -0.31985952824592834, -0.33038037177700641,
      -0.34030413402097959, -0.34960483173472279, -0.35825921663005889,
      -0.3662469247313031, -0.37355082321815963, -0.380156855491357,
      -0.38605429388847146, -0.3912359324426537, -0.39569812643647739,
      -0.39944059145804939, -0.40246694673227007, -0.40478421315647012,
      -0.40640326703643037, -0.40733867031785936, -0.4076084771555234,
      -0.40723474284334016, -0.40624282433508457, -0.40466194558907376,
      -0.40252473331811817, -0.39986736600974876, -0.39672949468393065,
      -0.39315412471212463, -0.38918753073787271, -0.38487876778258268,
      -0.38028012933984273, -0.37544628567161287, -0.37043408430386449,
      -0.36530235390474725, -0.36011095507329571, -0.35492019433370936,
      -0.34979028093189657, -0.3447799177397442, -0.33994535283371469,
      -0.335339440164607, -0.33994535108109758, -0.34477986271607242,
      -0.34979027443300037, -0.35492018671510911, -0.36011094636085794,
      -0.36530234415557705, -0.37043410961021045, -0.37544627324521179,
      -0.38028016764329442, -0.38487875242684122, -0.38918751467897461,
      -0.393154105833731, -0.396729510860029, -0.39986734482575265,
      -0.40252471331695472, -0.40466192464320017, -0.40624280168977595,
      -0.40723472005268035, -0.40760850480729816, -0.40733859447463028,
      -0.40640324343468093, -0.40478418768825686, -0.402466919762705,
      -0.39944059914279084, -0.39569805104696387, -0.39123590563194355,
      -0.38605422020172747, -0.38015678318082335, -0.37355075167160845,
      -0.36624689898890161, -0.35825919167974984, -0.34960480740872452,
      -0.34030411077981121, -0.33038034937839905, -0.31985953369118308,
      -0.30877022395835407, -0.29714352724270643, -0.28501263495142615,
      -0.27241271510531229, -0.25938066634432227, -0.24595494304713181,
      -0.23217526037197816, -0.21808218100857985, -0.20371712435206335,
      -0.1891217975445407, -0.17433811890732695, -0.15940778012837947,
      -0.1443720072004421, -0.1292712107475934, -0.11414464470410568,
      -0.0990301049313672, -0.083963599578706291, -0.068978885319753575,
      -0.05410724431138008, -0.039377015572651261, -0.024813182136715017,
      -0.010437043213515238, 0.00373428059286489, 0.017688218198326073,
      0.031417195424908166, 0.044919045659600088, 0.058197415430465152,
      0.071262067619053682, 0.084129274471179377, 0.096821923725119316,
      0.10936972089116166, 0.12180909764774414, 0.13418300877196848,
      0.14654065390324345, 0.15893673019105869, 0.1714307527946827,
      0.18408610328110669, 0.19696860899030624, 0.21014557599864553,
      0.22368395587948942, 0.23764931735861936, 0.25210419525836714,
      0.26710681293722111, 0.28271015012437284, 0.29896089716910451,
      0.31589874926459988, 0.33355618403219356, 0.35195835213317045,
      0.37112294320725264, 0.39106073398741126, 0.41177573545173363,
      0.43326609216414352, 0.45552426376926808, 0.47853789857925338,
      0.50229004627217666, 0.5267600951637198, 0.55192366641036439,
      0.57775326491934842, 0.60421838653141813, 0.63128529748967543,
      0.65891709965551637, 0.687073337968993, 0.69384503419541821,
      0.82984627574325209, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.0030652333057936032, 0.0030652333057936032,
      0.0030652333057936032, 0.032541527687108884, 0.049372379901147824,
      0.064527386358078739, 0.079035239792406148, 0.0929031716649206,
      0.10614243462703879, 0.11876840645593162, 0.13080065220370851,
      0.14226317838068461, 0.1531844158298678, 0.16359735330131486,
      0.17353961778760413, 0.18305324072240114, 0.19218463592998483,
      0.20098404406586196, 0.20950518313802377, 0.21780446085959168,
      0.22594016496246727, 0.23397130290005411, 0.24195646402301543,
      0.24995260933004068, 0.25801349928672446, 0.26618855303767924,
      0.27452146130782118, 0.28304913342773325, 0.29180076894974089,
      0.30079715076499791, 0.31005022648793462, 0.31956305342795288,
      0.32933009630517329, 0.33933706769012517, 0.34956228984292842,
      0.35997660801406628, 0.37054485490287131, 0.38122622112515808,
      0.39197556968410441, 0.40274389531425292, 0.41347935816144116,
      0.42412811179629617, 0.434634700462141, 0.44494299481663463,
      0.4549965910657518, 0.46473911575098886, 0.47411510247321476,
      0.48307009010856355, 0.49155084877864796, 0.49950601996317112,
      0.50688618330118951, 0.51364420817314016, 0.51973549742638969,
      0.52511804638851478, 0.52975303190479361, 0.53360467293765346,
      0.53664053136963075, 0.53883179104522494, 0.5401531938303763,
      0.54058355502599, 0.54010540997311829, 0.53870548934297446,
      0.53637465683130947, 0.5331080979453493, 0.5289051578800682,
      0.52376944754342181, 0.51770889615507887, 0.51073580739173752,
      0.50286646775627952, 0.49412143605053926, 0.48452521425390355,
      0.47410610717434509, 0.46289632272533215, 0.45093140474378218,
      0.43825021366787104, 0.42489478975322587, 0.41091002269003912,
      0.39634308835389437, 0.38124365474042121, 0.36566300072845259,
      0.34965408984548324, 0.33327100987244607, 0.31656842818064496,
      0.29960159651447449, 0.28242537164010556, 0.26509421184326465,
      0.24766137560244308, 0.23017855300601603, 0.21269530295840938,
      0.19525844942215592, 0.17791147567694668, 0.16069372023360273,
      0.14363999216457779, 0.12677957180169366, 0.11013555066343876,
      0.093724152501036953, 0.0775538674519633, 0.061624808711053608,
      0.045928146731681517, 0.03044553004949534, 0.01514881971383047,
      1.2343352991806813E-8, -0.015148794632907595, -0.030445499902169795,
      -0.045928120340762768, -0.06162478164480608, -0.077553839676721081,
      -0.093724124002976431, -0.11013553215787532, -0.12677954161578966,
      -0.14363998076230486, -0.16069368815831006, -0.17791144297174619,
      -0.19525841508204042, -0.21269528717231942, -0.23017851697045497,
      -0.24766134018857722, -0.265094175868077, -0.28242533462193353,
      -0.29960155957887408, -0.31656843072416252, -0.33327093025613769,
      -0.34965405347687095, -0.36566296329392589, -0.38124361653332017,
      -0.39634308521957345, -0.41090993567364686, -0.42489475406624488,
      -0.43825012573281341, -0.45093131709090939, -0.46289623470864794,
      -0.474106077127552, -0.48452518652750648, -0.49412141052729969,
      -0.502866445205734, -0.5107357875792814, -0.51770892288153736,
      -0.52376937004009094, -0.52890508272193515, -0.533108089301543,
      -0.53637469689008288, -0.538705468665725, -0.54010534909618146,
      -0.5405835640012151, -0.54015320785591669, -0.53883181094407617,
      -0.53664055777574693, -0.533604701819266, -0.52975306724974225,
      -0.52511808791065606, -0.51973554479197248, -0.51364430528336913,
      -0.50688624249296066, -0.49950614999959742, -0.49155092378527793,
      -0.48307010757360569, -0.47411522972284237, -0.46473914861679055,
      -0.45499669042582092, -0.44494316033916065, -0.43463485265546592,
      -0.42412823062564337, -0.413479481429543, -0.40274406242008959,
      -0.39197570636663492, -0.38122641661892459, -0.37054500287085407,
      -0.359976794134887, -0.34956247986811512, -0.33933726206064524,
      -0.3293302594470694, -0.31956326571350108, -0.31005034941695864,
      -0.30079732193062775, -0.29180094308309168, -0.28304937960366111,
      -0.27452167820850409, -0.26618875844225531, -0.25801371759799907,
      -0.24995279041971075, -0.24195664654405988, -0.23397148722948871,
      -0.22594035970497944, -0.21780464905501215, -0.20950537373146652,
      -0.200984237358381, -0.19218485067251523, -0.18305345799663369,
      -0.17353982407224247, -0.163597565450374, -0.15318463381947561,
      -0.14226340237429286, -0.13080089928185926, -0.11876864474769747,
      -0.10614268107311668, -0.092903426679953618, -0.079035503908630067,
      -0.064527659748284436, -0.049372662959268919, -0.032541813218048922,
      -0.019066878084555209, 0.0, 0.0, 0.0, 0.0 } ;

    liner_control_DW.FromWorkspace1_PWORK.TimePtr = (void *) pTimeValues0;
    liner_control_DW.FromWorkspace1_PWORK.DataPtr = (void *) pDataValues0;
    liner_control_DW.FromWorkspace1_IWORK.PrevIndex = 0;
  }

  /* Start for Constant: '<Root>/Constant1' */
  liner_control_B.Constant1 = liner_control_P.Constant1_Value;

  /* InitializeConditions for S-Function (udcm6_sep): '<S3>/icounter' */
  /* Level2 S-Function Block: '<S3>/icounter' (udcm6_sep) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S1>/UD' */
  liner_control_DW.UD_DSTATE = liner_control_P.DinamicFriction_ICPrevScaledInp;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  liner_control_DW.DiscreteTimeIntegrator_DSTATE =
    liner_control_P.DiscreteTimeIntegrator_IC;
  liner_control_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for UnitDelay: '<S2>/UD' */
  liner_control_DW.UD_DSTATE_l = liner_control_P.DiscreteDerivative1_ICPrevScale;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  liner_control_DW.DiscreteTimeIntegrator1_DSTATE =
    liner_control_P.DiscreteTimeIntegrator1_IC;
  liner_control_DW.DiscreteTimeIntegrator1_PrevRes = 2;

  /* InitializeConditions for S-Function (dam148ctrl): '<S4>/dac' */
  /* Level2 S-Function Block: '<S4>/dac' (dam148ctrl) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (to_memory_rt): '<S5>/to_memory_rt' */
  /* Level2 S-Function Block: '<S5>/to_memory_rt' (to_memory_rt) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  liner_control_DW.clockTickCounter = 0;
}

/* Model terminate function */
void liner_control_terminate(void)
{
  /* Terminate for S-Function (udcm6_sep): '<S3>/icounter' */
  /* Level2 S-Function Block: '<S3>/icounter' (udcm6_sep) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dam148ctrl): '<S4>/dac' */
  /* Level2 S-Function Block: '<S4>/dac' (dam148ctrl) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (to_memory_rt): '<S5>/to_memory_rt' */
  /* Level2 S-Function Block: '<S5>/to_memory_rt' (to_memory_rt) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (to_host_rt): '<S6>/to_host_rt' */
  /* Level2 S-Function Block: '<S6>/to_host_rt' (to_host_rt) */
  {
    SimStruct *rts = liner_control_M->childSfunctions[3];
    sfcnTerminate(rts);
  }
}
