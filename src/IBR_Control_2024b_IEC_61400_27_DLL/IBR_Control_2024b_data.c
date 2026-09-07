/*
 * IBR_Control_2024b_data.c
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

/* Block parameters (default storage) */
P_IBR_Control_2024b_T IBR_Control_2024b_P = {
  /* Variable: Fn
   * Referenced by:
   *   '<S1>/k'
   *   '<S6>/Constant'
   *   '<S6>/Integrator'
   *   '<S169>/Gain6'
   *   '<S169>/sqrt(2)//sqrt(3)1'
   *   '<S170>/speed'
   *   '<S170>/sqrt(2)//sqrt(3)1'
   */
  50.0,

  /* Variable: Iang0_pcc
   * Referenced by: '<S169>/Iang0_pcc'
   */
  0.1187072319260862,

  /* Variable: Imag0_pcc
   * Referenced by: '<S169>/Imag0_pcc'
   */
  703.87167373848229,

  /* Variable: Ki_I
   * Referenced by:
   *   '<S41>/Integral Gain'
   *   '<S93>/Integral Gain'
   */
  8000.0,

  /* Variable: Ki_PLL
   * Referenced by: '<S148>/Integral Gain'
   */
  0.02,

  /* Variable: Kp_I
   * Referenced by:
   *   '<S49>/Proportional Gain'
   *   '<S101>/Proportional Gain'
   */
  400.0,

  /* Variable: Kp_PLL
   * Referenced by: '<S156>/Proportional Gain'
   */
  0.0002,

  /* Variable: Lc
   * Referenced by: '<S3>/Gain5'
   */
  0.1574,

  /* Variable: Pref
   * Referenced by:
   *   '<S7>/Pref'
   *   '<S7>/Discrete-Time Integrator'
   *   '<S44>/Integrator'
   */
  5.0E+8,

  /* Variable: Qref
   * Referenced by:
   *   '<S7>/Qref'
   *   '<S7>/Discrete-Time Integrator1'
   *   '<S96>/Integrator'
   */
  1.0E+8,

  /* Variable: Rc
   * Referenced by:
   *   '<S44>/Integrator'
   *   '<S96>/Integrator'
   */
  0.782,

  /* Variable: Tf_S
   * Referenced by: '<S7>/Gain3'
   */
  0.1,

  /* Variable: Ts
   * Referenced by:
   *   '<S1>/k'
   *   '<S2>/Step'
   *   '<S6>/Integrator'
   *   '<S169>/Constant'
   *   '<S169>/sqrt(2)//sqrt(3)1'
   *   '<S170>/Constant'
   *   '<S170>/sqrt(2)//sqrt(3)1'
   */
  5.0E-5,

  /* Variable: Vang0_pcc
   * Referenced by:
   *   '<S6>/Integrator'
   *   '<S170>/Vang0_pcc'
   */
  0.316102791775967,

  /* Variable: Vmag0_pcc
   * Referenced by:
   *   '<S7>/Discrete-Time Integrator'
   *   '<S7>/Discrete-Time Integrator1'
   *   '<S170>/Vmag0_pcc'
   *   '<S44>/Integrator'
   *   '<S96>/Integrator'
   */
  418246.73425766214,

  /* Mask Parameter: PIController_InitialConditionFo
   * Referenced by: '<S151>/Integrator'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S6>/Integrator'
   */
  5.0E-5,

  /* Expression: 2*pi
   * Referenced by: '<S6>/2pi'
   */
  6.2831853071795862,

  /* Expression: -1
   * Referenced by: '<S115>/Gain'
   */
  -1.0,

  /* Expression: 2
   * Referenced by: '<S1>/phase correction'
   */
  2.0,

  /* Expression: -1
   * Referenced by: '<S114>/Gain'
   */
  -1.0,

  /* Expression: 2
   * Referenced by: '<S170>/phase correction'
   */
  2.0,

  /* Expression: sqrt(2)/sqrt(3)
   * Referenced by: '<S170>/sqrt(2)//sqrt(3)'
   */
  0.81649658092772615,

  /* Expression: 1
   * Referenced by: '<S2>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Step'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S170>/Switch6'
   */
  0.0,

  /* Expression: 2/3*pi
   * Referenced by: '<S170>/2//3*pi'
   */
  2.0943951023931953,

  /* Expression: 0
   * Referenced by: '<S170>/Switch2'
   */
  0.0,

  /* Expression: 4/3*pi
   * Referenced by: '<S170>/4//3*pi'
   */
  4.1887902047863905,

  /* Expression: 0
   * Referenced by: '<S170>/Switch1'
   */
  0.0,

  /* Expression: 2/3*[1 -1/2 -1/2; 0 sqrt(3)/2 -sqrt(3)/2]
   * Referenced by: '<S5>/voltage -  clarke transformation'
   */
  { 0.66666666666666663, 0.0, -0.33333333333333331, 0.57735026918962573,
    -0.33333333333333331, -0.57735026918962573 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S7>/Discrete-Time Integrator'
   */
  5.0E-5,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S7>/Discrete-Time Integrator1'
   */
  5.0E-5,

  /* Expression: 2
   * Referenced by: '<S169>/phase correction'
   */
  2.0,

  /* Expression: sqrt(2)
   * Referenced by: '<S169>/Gain7'
   */
  1.4142135623730951,

  /* Expression: 0
   * Referenced by: '<S169>/Switch7'
   */
  0.0,

  /* Expression: 2/3*pi
   * Referenced by: '<S169>/Constant13'
   */
  2.0943951023931953,

  /* Expression: 0
   * Referenced by: '<S169>/Switch8'
   */
  0.0,

  /* Expression: 4/3*pi
   * Referenced by: '<S169>/Constant14'
   */
  4.1887902047863905,

  /* Expression: 0
   * Referenced by: '<S169>/Switch9'
   */
  0.0,

  /* Expression: 2/3*[1 -1/2 -1/2; 0 sqrt(3)/2 -sqrt(3)/2]
   * Referenced by: '<S5>/current -  clarke transformation'
   */
  { 0.66666666666666663, 0.0, -0.33333333333333331, 0.57735026918962573,
    -0.33333333333333331, -0.57735026918962573 },

  /* Computed Parameter: Integrator_gainval_a
   * Referenced by: '<S44>/Integrator'
   */
  5.0E-5,

  /* Expression: 0
   * Referenced by: '<S6>/Constant2'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_b
   * Referenced by: '<S151>/Integrator'
   */
  5.0E-5,

  /* Expression: 2*pi
   * Referenced by: '<S6>/Gain3'
   */
  6.2831853071795862,

  /* Computed Parameter: Integrator_gainval_ba
   * Referenced by: '<S96>/Integrator'
   */
  5.0E-5,

  /* Expression: [1 0;-1/2 sqrt(3)/2;-1/2 -sqrt(3)/2]
   * Referenced by: '<S4>/inverse clarke transformation'
   */
  { 1.0, -0.5, -0.5, 0.0, 0.8660254037844386, -0.8660254037844386 },

  /* Expression: inf
   * Referenced by: '<S7>/Saturation'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S7>/Saturation'
   */
  0.1,

  /* Expression: -2/3
   * Referenced by: '<S7>/Gain1'
   */
  -0.66666666666666663,

  /* Expression: 1
   * Referenced by: '<S7>/Gain4'
   */
  1.0,

  /* Expression: 1/0.1
   * Referenced by: '<S7>/Gain5'
   */
  10.0,

  /* Expression: 2/3
   * Referenced by: '<S7>/Gain'
   */
  0.66666666666666663,

  /* Expression: 1
   * Referenced by: '<S7>/Gain2'
   */
  1.0
};
