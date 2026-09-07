/*
 * IBR_Control_2024b.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "IBR_Control_2024b".
 *
 * Model version              : 17.24
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Mon Sep  7 15:25:20 2026
 *
 * Target selection: IEC61400_27_DLL.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IBR_Control_2024b.h"
#include "IBR_Control_2024b_private.h"
#include <math.h>
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <float.h>

/* Block signals (default storage) */
B_IBR_Control_2024b_T IBR_Control_2024b_B;

/* Block states (default storage) */
DW_IBR_Control_2024b_T IBR_Control_2024b_DW;

/* External inputs (root inport signals with default storage) */
ExtU_IBR_Control_2024b_T IBR_Control_2024b_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_IBR_Control_2024b_T IBR_Control_2024b_Y;

/* Real-time model */
static RT_MODEL_IBR_Control_2024b_T IBR_Control_2024b_M_;
RT_MODEL_IBR_Control_2024b_T *const IBR_Control_2024b_M = &IBR_Control_2024b_M_;
real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model output function */
static void IBR_Control_2024b_output(void)
{
  real_T rtb_VectorConcatenate1_b[3];
  real_T rtb_currentclarketransformation[2];
  real_T rtb_Integrator_d;
  real_T rtb_ProportionalGain;
  real_T rtb_VectorConcatenate1_c;
  real_T rtb_VectorConcatenate1_idx_0;
  real_T rtb_VectorConcatenate1_idx_1;
  real_T rtb_VectorConcatenate2_idx_0;
  real_T rtb_VectorConcatenate2_idx_1;
  real_T rtb_currentclarketransformati_0;
  int32_T i;

  /* Math: '<S6>/Mod' incorporates:
   *  Constant: '<S6>/2pi'
   */
  rtb_Integrator_d = rt_modd_snf(IBR_Control_2024b_DW.Integrator_DSTATE,
    IBR_Control_2024b_P.upi_Value);

  /* Trigonometry: '<S115>/COS' incorporates:
   *  Trigonometry: '<S115>/COS1'
   */
  rtb_VectorConcatenate2_idx_0 = cos(rtb_Integrator_d);

  /* Trigonometry: '<S115>/SIN' incorporates:
   *  Trigonometry: '<S115>/SIN1'
   */
  rtb_VectorConcatenate2_idx_1 = sin(rtb_Integrator_d);

  /* Trigonometry: '<S115>/SIN1' */
  rtb_ProportionalGain = rtb_VectorConcatenate2_idx_1;

  /* Gain: '<S115>/Gain' */
  rtb_VectorConcatenate1_idx_0 = IBR_Control_2024b_P.Gain_Gain *
    rtb_ProportionalGain;

  /* Trigonometry: '<S115>/COS1' */
  rtb_VectorConcatenate1_idx_1 = rtb_VectorConcatenate2_idx_0;

  /* Concatenate: '<S115>/Vector Concatenate3' incorporates:
   *  Concatenate: '<S114>/Vector Concatenate1'
   *  Concatenate: '<S114>/Vector Concatenate2'
   */
  IBR_Control_2024b_B.VectorConcatenate3[0] = rtb_VectorConcatenate2_idx_0;
  IBR_Control_2024b_B.VectorConcatenate3[1] = rtb_VectorConcatenate1_idx_0;
  IBR_Control_2024b_B.VectorConcatenate3[2] = rtb_VectorConcatenate2_idx_1;
  IBR_Control_2024b_B.VectorConcatenate3[3] = rtb_VectorConcatenate1_idx_1;

  /* Gain: '<S1>/k' incorporates:
   *  Constant: '<S1>/phase correction'
   */
  rtb_ProportionalGain = 6.2831853071795862 * IBR_Control_2024b_P.Fn *
    IBR_Control_2024b_P.Ts;
  rtb_ProportionalGain *= IBR_Control_2024b_P.phasecorrection_Value;

  /* Sum: '<S1>/Sum' */
  rtb_ProportionalGain += rtb_Integrator_d;

  /* Trigonometry: '<S114>/COS' incorporates:
   *  Trigonometry: '<S114>/COS1'
   */
  rtb_VectorConcatenate1_idx_0 = cos(rtb_ProportionalGain);

  /* Trigonometry: '<S114>/SIN' incorporates:
   *  Trigonometry: '<S114>/SIN1'
   */
  rtb_Integrator_d = sin(rtb_ProportionalGain);

  /* Gain: '<S114>/Gain' */
  rtb_VectorConcatenate1_idx_1 = IBR_Control_2024b_P.Gain_Gain_m *
    rtb_Integrator_d;

  /* Trigonometry: '<S114>/SIN1' */
  rtb_VectorConcatenate2_idx_0 = rtb_Integrator_d;

  /* Trigonometry: '<S114>/COS1' */
  rtb_VectorConcatenate2_idx_1 = rtb_VectorConcatenate1_idx_0;

  /* Concatenate: '<S114>/Vector Concatenate3' incorporates:
   *  Concatenate: '<S114>/Vector Concatenate1'
   *  Concatenate: '<S114>/Vector Concatenate2'
   */
  IBR_Control_2024b_B.VectorConcatenate3_n[0] = rtb_VectorConcatenate1_idx_0;
  IBR_Control_2024b_B.VectorConcatenate3_n[1] = rtb_VectorConcatenate2_idx_0;
  IBR_Control_2024b_B.VectorConcatenate3_n[2] = rtb_VectorConcatenate1_idx_1;
  IBR_Control_2024b_B.VectorConcatenate3_n[3] = rtb_VectorConcatenate2_idx_1;

  /* Clock: '<S170>/Time' incorporates:
   *  Clock: '<S169>/Time'
   */
  rtb_Integrator_d = IBR_Control_2024b_M->Timing.t[0];
  rtb_VectorConcatenate1_idx_0 = rtb_Integrator_d;

  /* Sum: '<S170>/Sum' incorporates:
   *  Constant: '<S170>/Constant'
   */
  rtb_VectorConcatenate1_idx_0 -= IBR_Control_2024b_P.Ts;

  /* Gain: '<S170>/speed' */
  rtb_ProportionalGain = 6.2831853071795862 * IBR_Control_2024b_P.Fn;
  rtb_VectorConcatenate1_idx_0 *= rtb_ProportionalGain;

  /* Gain: '<S170>/sqrt(2)//sqrt(3)1' */
  rtb_ProportionalGain = 6.2831853071795862 * IBR_Control_2024b_P.Fn *
    IBR_Control_2024b_P.Ts;

  /* Gain: '<S170>/sqrt(2)//sqrt(3)1' incorporates:
   *  Constant: '<S170>/phase correction'
   */
  IBR_Control_2024b_B.sqrt2sqrt31 = rtb_ProportionalGain *
    IBR_Control_2024b_P.phasecorrection_Value_l;

  /* Sum: '<S170>/Sum3' incorporates:
   *  Constant: '<S170>/Vang0_pcc'
   */
  rtb_VectorConcatenate2_idx_0 = (rtb_VectorConcatenate1_idx_0 +
    IBR_Control_2024b_P.Vang0_pcc) - IBR_Control_2024b_B.sqrt2sqrt31;

  /* Gain: '<S170>/sqrt(2)//sqrt(3)' incorporates:
   *  Constant: '<S170>/Vmag0_pcc'
   */
  IBR_Control_2024b_B.sqrt2sqrt3 = IBR_Control_2024b_P.sqrt2sqrt3_Gain *
    IBR_Control_2024b_P.Vmag0_pcc;

  /* Step: '<S2>/Step' */
  rtb_VectorConcatenate1_idx_0 = IBR_Control_2024b_M->Timing.t[0];
  rtb_ProportionalGain = 3.0 * IBR_Control_2024b_P.Ts;
  if (rtb_VectorConcatenate1_idx_0 < rtb_ProportionalGain) {
    rtb_VectorConcatenate1_idx_0 = IBR_Control_2024b_P.Step_Y0;
  } else {
    rtb_VectorConcatenate1_idx_0 = IBR_Control_2024b_P.Step_YFinal;
  }

  /* End of Step: '<S2>/Step' */

  /* Switch: '<S170>/Switch6' incorporates:
   *  Inport: '<Root>/in_voltage_a'
   */
  if (rtb_VectorConcatenate1_idx_0 > IBR_Control_2024b_P.Switch6_Threshold) {
    /* Trigonometry: '<S170>/Cos3' */
    rtb_VectorConcatenate2_idx_1 = cos(rtb_VectorConcatenate2_idx_0);

    /* Product: '<S170>/Product3' */
    rtb_VectorConcatenate2_idx_1 *= IBR_Control_2024b_B.sqrt2sqrt3;
    rtb_VectorConcatenate1_b[0] = rtb_VectorConcatenate2_idx_1;
  } else {
    rtb_VectorConcatenate1_b[0] = IBR_Control_2024b_U.in_voltage_a;
  }

  /* End of Switch: '<S170>/Switch6' */

  /* Switch: '<S170>/Switch2' incorporates:
   *  Inport: '<Root>/in_voltage_b'
   */
  if (rtb_VectorConcatenate1_idx_0 > IBR_Control_2024b_P.Switch2_Threshold) {
    /* Sum: '<S170>/Sum4' incorporates:
     *  Constant: '<S170>/2//3*pi'
     */
    rtb_VectorConcatenate2_idx_1 = rtb_VectorConcatenate2_idx_0 -
      IBR_Control_2024b_P.u3pi_Value;

    /* Trigonometry: '<S170>/Cos4' */
    rtb_VectorConcatenate2_idx_1 = cos(rtb_VectorConcatenate2_idx_1);

    /* Product: '<S170>/Product4' */
    rtb_VectorConcatenate2_idx_1 *= IBR_Control_2024b_B.sqrt2sqrt3;
    rtb_VectorConcatenate1_b[1] = rtb_VectorConcatenate2_idx_1;
  } else {
    rtb_VectorConcatenate1_b[1] = IBR_Control_2024b_U.in_voltage_b;
  }

  /* End of Switch: '<S170>/Switch2' */

  /* Switch: '<S170>/Switch1' incorporates:
   *  Inport: '<Root>/in_voltage_c'
   */
  if (rtb_VectorConcatenate1_idx_0 > IBR_Control_2024b_P.Switch1_Threshold) {
    /* Sum: '<S170>/Sum5' incorporates:
     *  Constant: '<S170>/4//3*pi'
     */
    rtb_VectorConcatenate2_idx_0 -= IBR_Control_2024b_P.u3pi_Value_e;

    /* Trigonometry: '<S170>/Cos5' */
    rtb_VectorConcatenate2_idx_0 = cos(rtb_VectorConcatenate2_idx_0);

    /* Product: '<S170>/Product5' */
    rtb_VectorConcatenate2_idx_0 *= IBR_Control_2024b_B.sqrt2sqrt3;
    rtb_VectorConcatenate1_b[2] = rtb_VectorConcatenate2_idx_0;
  } else {
    rtb_VectorConcatenate1_b[2] = IBR_Control_2024b_U.in_voltage_c;
  }

  /* End of Switch: '<S170>/Switch1' */

  /* Gain: '<S5>/voltage -  clarke transformation' incorporates:
   *  Concatenate: '<S5>/Vector Concatenate1'
   *  Gain: '<S5>/current -  clarke transformation'
   */
  rtb_ProportionalGain = rtb_VectorConcatenate1_b[0];
  rtb_VectorConcatenate1_idx_1 = rtb_VectorConcatenate1_b[1];
  rtb_VectorConcatenate1_c = rtb_VectorConcatenate1_b[2];
  for (i = 0; i < 2; i++) {
    rtb_currentclarketransformati_0 =
      IBR_Control_2024b_P.voltageclarketransformation_Gai[i] *
      rtb_ProportionalGain;
    rtb_currentclarketransformati_0 +=
      IBR_Control_2024b_P.voltageclarketransformation_Gai[i + 2] *
      rtb_VectorConcatenate1_idx_1;
    rtb_currentclarketransformati_0 +=
      IBR_Control_2024b_P.voltageclarketransformation_Gai[i + 4] *
      rtb_VectorConcatenate1_c;

    /* Gain: '<S5>/current -  clarke transformation' incorporates:
     *  Gain: '<S5>/voltage -  clarke transformation'
     */
    rtb_currentclarketransformation[i] = rtb_currentclarketransformati_0;
  }

  /* End of Gain: '<S5>/voltage -  clarke transformation' */

  /* Product: '<S5>/voltage -  matrix multiplication' */
  rtb_VectorConcatenate2_idx_1 = IBR_Control_2024b_B.VectorConcatenate3[0] *
    rtb_currentclarketransformation[0];
  rtb_VectorConcatenate2_idx_1 += rtb_currentclarketransformation[1] *
    IBR_Control_2024b_B.VectorConcatenate3[2];
  rtb_VectorConcatenate2_idx_0 = rtb_VectorConcatenate2_idx_1;
  rtb_VectorConcatenate2_idx_1 = rtb_currentclarketransformation[0] *
    IBR_Control_2024b_B.VectorConcatenate3[1];
  rtb_VectorConcatenate2_idx_1 += rtb_currentclarketransformation[1] *
    IBR_Control_2024b_B.VectorConcatenate3[3];

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  IBR_Control_2024b_B.DiscreteTimeIntegrator =
    IBR_Control_2024b_DW.DiscreteTimeIntegrator_DSTATE;

  /* SignalConversion generated from: '<S7>/Vector Concatenate' incorporates:
   *  Concatenate: '<S7>/Vector Concatenate'
   */
  IBR_Control_2024b_B.VectorConcatenate[0] =
    IBR_Control_2024b_B.DiscreteTimeIntegrator;

  /* DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' */
  IBR_Control_2024b_B.DiscreteTimeIntegrator1 =
    IBR_Control_2024b_DW.DiscreteTimeIntegrator1_DSTATE;

  /* SignalConversion generated from: '<S7>/Vector Concatenate' incorporates:
   *  Concatenate: '<S7>/Vector Concatenate'
   */
  IBR_Control_2024b_B.VectorConcatenate[1] =
    IBR_Control_2024b_B.DiscreteTimeIntegrator1;

  /* Sum: '<S169>/Sum' incorporates:
   *  Constant: '<S169>/Constant'
   */
  rtb_Integrator_d -= IBR_Control_2024b_P.Ts;

  /* Gain: '<S169>/Gain6' */
  rtb_ProportionalGain = 6.2831853071795862 * IBR_Control_2024b_P.Fn;
  rtb_Integrator_d *= rtb_ProportionalGain;

  /* Gain: '<S169>/sqrt(2)//sqrt(3)1' */
  rtb_ProportionalGain = 6.2831853071795862 * IBR_Control_2024b_P.Fn *
    IBR_Control_2024b_P.Ts;

  /* Gain: '<S169>/sqrt(2)//sqrt(3)1' incorporates:
   *  Constant: '<S169>/phase correction'
   */
  IBR_Control_2024b_B.sqrt2sqrt31_n = rtb_ProportionalGain *
    IBR_Control_2024b_P.phasecorrection_Value_h;

  /* Sum: '<S169>/Sum6' incorporates:
   *  Constant: '<S169>/Iang0_pcc'
   */
  rtb_Integrator_d = (rtb_Integrator_d + IBR_Control_2024b_P.Iang0_pcc) -
    IBR_Control_2024b_B.sqrt2sqrt31_n;

  /* Gain: '<S169>/Gain7' incorporates:
   *  Constant: '<S169>/Imag0_pcc'
   */
  IBR_Control_2024b_B.Gain7 = IBR_Control_2024b_P.Gain7_Gain *
    IBR_Control_2024b_P.Imag0_pcc;

  /* Switch: '<S169>/Switch7' incorporates:
   *  Inport: '<Root>/in_current_a'
   */
  if (rtb_VectorConcatenate1_idx_0 > IBR_Control_2024b_P.Switch7_Threshold) {
    /* Trigonometry: '<S169>/Cos6' */
    rtb_ProportionalGain = cos(rtb_Integrator_d);

    /* Product: '<S169>/Product6' */
    rtb_ProportionalGain *= IBR_Control_2024b_B.Gain7;
    rtb_VectorConcatenate1_b[0] = rtb_ProportionalGain;
  } else {
    rtb_VectorConcatenate1_b[0] = IBR_Control_2024b_U.in_current_a;
  }

  /* End of Switch: '<S169>/Switch7' */

  /* Switch: '<S169>/Switch8' incorporates:
   *  Inport: '<Root>/in_current_b'
   */
  if (rtb_VectorConcatenate1_idx_0 > IBR_Control_2024b_P.Switch8_Threshold) {
    /* Sum: '<S169>/Sum7' incorporates:
     *  Constant: '<S169>/Constant13'
     */
    rtb_ProportionalGain = rtb_Integrator_d -
      IBR_Control_2024b_P.Constant13_Value;

    /* Trigonometry: '<S169>/Cos7' */
    rtb_ProportionalGain = cos(rtb_ProportionalGain);

    /* Product: '<S169>/Product7' */
    rtb_ProportionalGain *= IBR_Control_2024b_B.Gain7;
    rtb_VectorConcatenate1_b[1] = rtb_ProportionalGain;
  } else {
    rtb_VectorConcatenate1_b[1] = IBR_Control_2024b_U.in_current_b;
  }

  /* End of Switch: '<S169>/Switch8' */

  /* Switch: '<S169>/Switch9' incorporates:
   *  Inport: '<Root>/in_current_c'
   */
  if (rtb_VectorConcatenate1_idx_0 > IBR_Control_2024b_P.Switch9_Threshold) {
    /* Sum: '<S169>/Sum8' incorporates:
     *  Constant: '<S169>/Constant14'
     */
    rtb_Integrator_d -= IBR_Control_2024b_P.Constant14_Value;

    /* Trigonometry: '<S169>/Cos8' */
    rtb_Integrator_d = cos(rtb_Integrator_d);

    /* Product: '<S169>/Product8' */
    rtb_Integrator_d *= IBR_Control_2024b_B.Gain7;
    rtb_VectorConcatenate1_b[2] = rtb_Integrator_d;
  } else {
    rtb_VectorConcatenate1_b[2] = IBR_Control_2024b_U.in_current_c;
  }

  /* End of Switch: '<S169>/Switch9' */

  /* Gain: '<S5>/current -  clarke transformation' incorporates:
   *  Concatenate: '<S5>/Vector Concatenate1'
   */
  rtb_ProportionalGain = rtb_VectorConcatenate1_b[0];
  rtb_VectorConcatenate1_idx_1 = rtb_VectorConcatenate1_b[1];
  rtb_VectorConcatenate1_c = rtb_VectorConcatenate1_b[2];
  for (i = 0; i < 2; i++) {
    rtb_currentclarketransformati_0 =
      IBR_Control_2024b_P.currentclarketransformation_Gai[i] *
      rtb_ProportionalGain;
    rtb_currentclarketransformati_0 +=
      IBR_Control_2024b_P.currentclarketransformation_Gai[i + 2] *
      rtb_VectorConcatenate1_idx_1;
    rtb_currentclarketransformati_0 +=
      IBR_Control_2024b_P.currentclarketransformation_Gai[i + 4] *
      rtb_VectorConcatenate1_c;

    /* Gain: '<S5>/current -  clarke transformation' */
    rtb_currentclarketransformation[i] = rtb_currentclarketransformati_0;
  }

  /* End of Gain: '<S5>/current -  clarke transformation' */

  /* Product: '<S5>/current -  matrix multiplication' incorporates:
   *  Product: '<S4>/matrix multiplication'
   */
  rtb_VectorConcatenate1_idx_1 = IBR_Control_2024b_B.VectorConcatenate3[0] *
    rtb_currentclarketransformation[0];
  rtb_VectorConcatenate1_idx_1 += rtb_currentclarketransformation[1] *
    IBR_Control_2024b_B.VectorConcatenate3[2];
  rtb_VectorConcatenate1_idx_0 = rtb_VectorConcatenate1_idx_1;
  rtb_VectorConcatenate1_idx_1 = rtb_currentclarketransformation[0] *
    IBR_Control_2024b_B.VectorConcatenate3[1];
  rtb_VectorConcatenate1_idx_1 += rtb_currentclarketransformation[1] *
    IBR_Control_2024b_B.VectorConcatenate3[3];

  /* Sum: '<S3>/Sum1' */
  IBR_Control_2024b_B.Sum1 = IBR_Control_2024b_B.VectorConcatenate[0] -
    rtb_VectorConcatenate1_idx_0;

  /* Gain: '<S49>/Proportional Gain' */
  rtb_ProportionalGain = IBR_Control_2024b_P.Kp_I * IBR_Control_2024b_B.Sum1;

  /* DiscreteIntegrator: '<S44>/Integrator' */
  rtb_Integrator_d = IBR_Control_2024b_DW.Integrator_DSTATE_i;

  /* Sum: '<S53>/Sum' */
  IBR_Control_2024b_B.Sum = rtb_ProportionalGain + rtb_Integrator_d;

  /* Sum: '<S6>/Sum1' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  IBR_Control_2024b_B.Sum1_m = IBR_Control_2024b_P.Constant2_Value -
    rtb_VectorConcatenate2_idx_1;

  /* Gain: '<S156>/Proportional Gain' */
  rtb_ProportionalGain = IBR_Control_2024b_P.Kp_PLL * IBR_Control_2024b_B.Sum1_m;

  /* Sum: '<S160>/Sum' */
  rtb_ProportionalGain += IBR_Control_2024b_DW.Integrator_DSTATE_p;

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant'
   */
  rtb_ProportionalGain = IBR_Control_2024b_P.Fn - rtb_ProportionalGain;

  /* Gain: '<S6>/Gain3' */
  IBR_Control_2024b_B.Gain3 = IBR_Control_2024b_P.Gain3_Gain *
    rtb_ProportionalGain;

  /* Gain: '<S3>/Gain5' */
  IBR_Control_2024b_B.Gain5 = IBR_Control_2024b_P.Lc * IBR_Control_2024b_B.Gain3;

  /* Product: '<S3>/Product3' */
  rtb_Integrator_d = IBR_Control_2024b_B.Gain5 * rtb_VectorConcatenate1_idx_1;

  /* Sum: '<S3>/Sum3' */
  rtb_currentclarketransformation[0] = (rtb_VectorConcatenate2_idx_0 +
    IBR_Control_2024b_B.Sum) - rtb_Integrator_d;

  /* Product: '<S3>/Product2' */
  rtb_Integrator_d = rtb_VectorConcatenate1_idx_0 * IBR_Control_2024b_B.Gain5;

  /* Sum: '<S3>/Sum2' */
  IBR_Control_2024b_B.Sum2 = IBR_Control_2024b_B.VectorConcatenate[1] -
    rtb_VectorConcatenate1_idx_1;

  /* Gain: '<S101>/Proportional Gain' */
  rtb_ProportionalGain = IBR_Control_2024b_P.Kp_I * IBR_Control_2024b_B.Sum2;

  /* Sum: '<S105>/Sum' */
  IBR_Control_2024b_B.Sum_f = rtb_ProportionalGain +
    IBR_Control_2024b_DW.Integrator_DSTATE_k;

  /* Sum: '<S3>/Sum4' */
  rtb_currentclarketransformation[1] = (rtb_Integrator_d +
    IBR_Control_2024b_B.Sum_f) + rtb_VectorConcatenate2_idx_1;

  /* Product: '<S4>/matrix multiplication' */
  rtb_VectorConcatenate1_idx_1 = IBR_Control_2024b_B.VectorConcatenate3_n[0] *
    rtb_currentclarketransformation[0];
  rtb_VectorConcatenate1_idx_1 += rtb_currentclarketransformation[1] *
    IBR_Control_2024b_B.VectorConcatenate3_n[2];
  rtb_VectorConcatenate1_idx_0 = rtb_VectorConcatenate1_idx_1;
  rtb_VectorConcatenate1_idx_1 = rtb_currentclarketransformation[0] *
    IBR_Control_2024b_B.VectorConcatenate3_n[1];
  rtb_VectorConcatenate1_idx_1 += rtb_currentclarketransformation[1] *
    IBR_Control_2024b_B.VectorConcatenate3_n[3];

  /* Gain: '<S4>/inverse clarke transformation' incorporates:
   *  Product: '<S4>/matrix multiplication'
   */
  for (i = 0; i < 3; i++) {
    rtb_ProportionalGain = IBR_Control_2024b_P.inverseclarketransformation_Gai[i]
      * rtb_VectorConcatenate1_idx_0;
    rtb_ProportionalGain +=
      IBR_Control_2024b_P.inverseclarketransformation_Gai[i + 3] *
      rtb_VectorConcatenate1_idx_1;

    /* Gain: '<S4>/inverse clarke transformation' incorporates:
     *  Product: '<S4>/matrix multiplication'
     */
    rtb_VectorConcatenate1_b[i] = rtb_ProportionalGain;
  }

  /* End of Gain: '<S4>/inverse clarke transformation' */

  /* Outport: '<Root>/out_voltage_a' */
  IBR_Control_2024b_Y.out_voltage_a = rtb_VectorConcatenate1_b[0];

  /* Outport: '<Root>/out_voltage_b' */
  IBR_Control_2024b_Y.out_voltage_b = rtb_VectorConcatenate1_b[1];

  /* Outport: '<Root>/out_voltage_c' */
  IBR_Control_2024b_Y.out_voltage_c = rtb_VectorConcatenate1_b[2];

  /* Gain: '<S93>/Integral Gain' */
  IBR_Control_2024b_B.IntegralGain = IBR_Control_2024b_P.Ki_I *
    IBR_Control_2024b_B.Sum2;

  /* Gain: '<S148>/Integral Gain' */
  IBR_Control_2024b_B.IntegralGain_g = IBR_Control_2024b_P.Ki_PLL *
    IBR_Control_2024b_B.Sum1_m;

  /* Gain: '<S41>/Integral Gain' */
  IBR_Control_2024b_B.IntegralGain_n = IBR_Control_2024b_P.Ki_I *
    IBR_Control_2024b_B.Sum1;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_VectorConcatenate2_idx_0 > IBR_Control_2024b_P.Saturation_UpperSat) {
    rtb_Integrator_d = IBR_Control_2024b_P.Saturation_UpperSat;
  } else if (rtb_VectorConcatenate2_idx_0 <
             IBR_Control_2024b_P.Saturation_LowerSat) {
    rtb_Integrator_d = IBR_Control_2024b_P.Saturation_LowerSat;
  } else {
    rtb_Integrator_d = rtb_VectorConcatenate2_idx_0;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Gain: '<S7>/Gain1' incorporates:
   *  Constant: '<S7>/Qref'
   */
  IBR_Control_2024b_B.Gain1 = IBR_Control_2024b_P.Gain1_Gain *
    IBR_Control_2024b_P.Qref;

  /* Product: '<S7>/Divide1' */
  rtb_VectorConcatenate1_idx_0 = 1.0 / rtb_Integrator_d *
    IBR_Control_2024b_B.Gain1;

  /* Gain: '<S7>/Gain4' */
  rtb_VectorConcatenate1_idx_0 *= IBR_Control_2024b_P.Gain4_Gain;

  /* Sum: '<S7>/Sum1' */
  rtb_VectorConcatenate1_idx_0 -= IBR_Control_2024b_B.DiscreteTimeIntegrator1;

  /* Gain: '<S7>/Gain5' */
  IBR_Control_2024b_B.Gain5_h = IBR_Control_2024b_P.Gain5_Gain *
    rtb_VectorConcatenate1_idx_0;

  /* Gain: '<S7>/Gain' incorporates:
   *  Constant: '<S7>/Pref'
   */
  IBR_Control_2024b_B.Gain = IBR_Control_2024b_P.Gain_Gain_i *
    IBR_Control_2024b_P.Pref;

  /* Product: '<S7>/Divide' */
  rtb_Integrator_d = IBR_Control_2024b_B.Gain / rtb_Integrator_d;

  /* Gain: '<S7>/Gain2' */
  rtb_Integrator_d *= IBR_Control_2024b_P.Gain2_Gain;

  /* Sum: '<S7>/Sum' */
  rtb_Integrator_d -= IBR_Control_2024b_B.DiscreteTimeIntegrator;

  /* Gain: '<S7>/Gain3' */
  rtb_ProportionalGain = 1.0 / IBR_Control_2024b_P.Tf_S;

  /* Gain: '<S7>/Gain3' */
  IBR_Control_2024b_B.Gain3_n = rtb_ProportionalGain * rtb_Integrator_d;
}

/* Model update function */
static void IBR_Control_2024b_update(void)
{
  /* Update for DiscreteIntegrator: '<S6>/Integrator' */
  IBR_Control_2024b_DW.Integrator_DSTATE +=
    IBR_Control_2024b_P.Integrator_gainval * IBR_Control_2024b_B.Gain3;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' */
  IBR_Control_2024b_DW.DiscreteTimeIntegrator_DSTATE +=
    IBR_Control_2024b_P.DiscreteTimeIntegrator_gainval *
    IBR_Control_2024b_B.Gain3_n;

  /* Update for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' */
  IBR_Control_2024b_DW.DiscreteTimeIntegrator1_DSTATE +=
    IBR_Control_2024b_P.DiscreteTimeIntegrator1_gainval *
    IBR_Control_2024b_B.Gain5_h;

  /* Update for DiscreteIntegrator: '<S44>/Integrator' */
  IBR_Control_2024b_DW.Integrator_DSTATE_i +=
    IBR_Control_2024b_P.Integrator_gainval_a *
    IBR_Control_2024b_B.IntegralGain_n;

  /* Update for DiscreteIntegrator: '<S151>/Integrator' */
  IBR_Control_2024b_DW.Integrator_DSTATE_p +=
    IBR_Control_2024b_P.Integrator_gainval_b *
    IBR_Control_2024b_B.IntegralGain_g;

  /* Update for DiscreteIntegrator: '<S96>/Integrator' */
  IBR_Control_2024b_DW.Integrator_DSTATE_k +=
    IBR_Control_2024b_P.Integrator_gainval_ba * IBR_Control_2024b_B.IntegralGain;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++IBR_Control_2024b_M->Timing.clockTick0)) {
    ++IBR_Control_2024b_M->Timing.clockTickH0;
  }

  IBR_Control_2024b_M->Timing.t[0] = IBR_Control_2024b_M->Timing.clockTick0 *
    IBR_Control_2024b_M->Timing.stepSize0 +
    IBR_Control_2024b_M->Timing.clockTickH0 *
    IBR_Control_2024b_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [5.0E-5s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++IBR_Control_2024b_M->Timing.clockTick1)) {
      ++IBR_Control_2024b_M->Timing.clockTickH1;
    }

    IBR_Control_2024b_M->Timing.t[1] = IBR_Control_2024b_M->Timing.clockTick1 *
      IBR_Control_2024b_M->Timing.stepSize1 +
      IBR_Control_2024b_M->Timing.clockTickH1 *
      IBR_Control_2024b_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void IBR_Control_2024b_initialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S6>/Integrator' */
  IBR_Control_2024b_DW.Integrator_DSTATE = IBR_Control_2024b_P.Vang0_pcc -
    12.566370614359172 * IBR_Control_2024b_P.Fn * IBR_Control_2024b_P.Ts;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator' incorporates:
   *  DiscreteIntegrator: '<S44>/Integrator'
   */
  IBR_Control_2024b_DW.DiscreteTimeIntegrator_DSTATE = IBR_Control_2024b_P.Pref /
    (1.2247448713915889 * IBR_Control_2024b_P.Vmag0_pcc);

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S96>/Integrator'
   */
  IBR_Control_2024b_DW.DiscreteTimeIntegrator1_DSTATE =
    -IBR_Control_2024b_P.Qref / (1.2247448713915889 *
    IBR_Control_2024b_P.Vmag0_pcc);

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Integrator' */
  IBR_Control_2024b_DW.Integrator_DSTATE_i =
    IBR_Control_2024b_DW.DiscreteTimeIntegrator_DSTATE * IBR_Control_2024b_P.Rc;

  /* InitializeConditions for DiscreteIntegrator: '<S151>/Integrator' */
  IBR_Control_2024b_DW.Integrator_DSTATE_p =
    IBR_Control_2024b_P.PIController_InitialConditionFo;

  /* InitializeConditions for DiscreteIntegrator: '<S96>/Integrator' */
  IBR_Control_2024b_DW.Integrator_DSTATE_k =
    IBR_Control_2024b_DW.DiscreteTimeIntegrator1_DSTATE * IBR_Control_2024b_P.Rc;
}

/* Model terminate function */
static void IBR_Control_2024b_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  IBR_Control_2024b_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  IBR_Control_2024b_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  IBR_Control_2024b_initialize();
}

void MdlTerminate(void)
{
  IBR_Control_2024b_terminate();
}

/* Registration function */
RT_MODEL_IBR_Control_2024b_T *IBR_Control_2024b(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  IBR_Control_2024b_P.Saturation_UpperSat = rtInf;

  /* initialize real-time model */
  (void) memset((void *)IBR_Control_2024b_M, 0,
                sizeof(RT_MODEL_IBR_Control_2024b_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&IBR_Control_2024b_M->solverInfo,
                          &IBR_Control_2024b_M->Timing.simTimeStep);
    rtsiSetTPtr(&IBR_Control_2024b_M->solverInfo, &rtmGetTPtr
                (IBR_Control_2024b_M));
    rtsiSetStepSizePtr(&IBR_Control_2024b_M->solverInfo,
                       &IBR_Control_2024b_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&IBR_Control_2024b_M->solverInfo, (&rtmGetErrorStatus
      (IBR_Control_2024b_M)));
    rtsiSetRTModelPtr(&IBR_Control_2024b_M->solverInfo, IBR_Control_2024b_M);
  }

  rtsiSetSimTimeStep(&IBR_Control_2024b_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&IBR_Control_2024b_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&IBR_Control_2024b_M->solverInfo, false);
  rtsiSetSolverName(&IBR_Control_2024b_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = IBR_Control_2024b_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    IBR_Control_2024b_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    IBR_Control_2024b_M->Timing.sampleTimes =
      (&IBR_Control_2024b_M->Timing.sampleTimesArray[0]);
    IBR_Control_2024b_M->Timing.offsetTimes =
      (&IBR_Control_2024b_M->Timing.offsetTimesArray[0]);

    /* task periods */
    IBR_Control_2024b_M->Timing.sampleTimes[0] = (0.0);
    IBR_Control_2024b_M->Timing.sampleTimes[1] = (5.0E-5);

    /* task offsets */
    IBR_Control_2024b_M->Timing.offsetTimes[0] = (0.0);
    IBR_Control_2024b_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(IBR_Control_2024b_M, &IBR_Control_2024b_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = IBR_Control_2024b_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    IBR_Control_2024b_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(IBR_Control_2024b_M, 1.0);
  IBR_Control_2024b_M->Timing.stepSize0 = 5.0E-5;
  IBR_Control_2024b_M->Timing.stepSize1 = 5.0E-5;
  IBR_Control_2024b_M->solverInfoPtr = (&IBR_Control_2024b_M->solverInfo);
  IBR_Control_2024b_M->Timing.stepSize = (5.0E-5);
  rtsiSetFixedStepSize(&IBR_Control_2024b_M->solverInfo, 5.0E-5);
  rtsiSetSolverMode(&IBR_Control_2024b_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  IBR_Control_2024b_M->blockIO = ((void *) &IBR_Control_2024b_B);
  (void) memset(((void *) &IBR_Control_2024b_B), 0,
                sizeof(B_IBR_Control_2024b_T));

  /* parameters */
  IBR_Control_2024b_M->defaultParam = ((real_T *)&IBR_Control_2024b_P);

  /* states (dwork) */
  IBR_Control_2024b_M->dwork = ((void *) &IBR_Control_2024b_DW);
  (void) memset((void *)&IBR_Control_2024b_DW, 0,
                sizeof(DW_IBR_Control_2024b_T));

  /* external inputs */
  IBR_Control_2024b_M->inputs = (((void*)&IBR_Control_2024b_U));
  (void)memset(&IBR_Control_2024b_U, 0, sizeof(ExtU_IBR_Control_2024b_T));

  /* external outputs */
  IBR_Control_2024b_M->outputs = (&IBR_Control_2024b_Y);
  (void)memset(&IBR_Control_2024b_Y, 0, sizeof(ExtY_IBR_Control_2024b_T));

  /* Initialize Sizes */
  IBR_Control_2024b_M->Sizes.numContStates = (0);/* Number of continuous states */
  IBR_Control_2024b_M->Sizes.numY = (3);/* Number of model outputs */
  IBR_Control_2024b_M->Sizes.numU = (6);/* Number of model inputs */
  IBR_Control_2024b_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  IBR_Control_2024b_M->Sizes.numSampTimes = (2);/* Number of sample times */
  IBR_Control_2024b_M->Sizes.numBlocks = (130);/* Number of blocks */
  IBR_Control_2024b_M->Sizes.numBlockIO = (23);/* Number of block outputs */
  IBR_Control_2024b_M->Sizes.numBlockPrms = (69);/* Sum of parameter "widths" */
  return IBR_Control_2024b_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
