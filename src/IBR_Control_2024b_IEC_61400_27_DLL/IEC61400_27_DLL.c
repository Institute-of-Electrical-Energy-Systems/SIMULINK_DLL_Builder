/*
 * Copyright 1994-2012 The MathWorks, Inc.
 *
 * File    : IEC61400_27_DLL.c
 *
 * Abstract: Wrapper for IEC 61400-27 DLL creation.
 *
 *
 * Compiler specified defines:
 *	RT              - Required.
 *  MODEL=modelname - Required.
 *	NUMST=#         - Required. Number of sample times.
 *	NCSTATES=#      - Required. Number of continuous states.
 *  TID01EQ=1 or 0  - Optional. Only define to 1 if sample time task
 *                    id's 0 and 1 have equal rates.
 *  MULTITASKING    - Optional. (use MT for a synonym).
 *	SAVEFILE        - Optional (non-quoted) name of .mat file to create.
 *			          Default is <MODEL>.mat
 */

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdarg.h>
#include <debugapi.h>
#include "ext_simenv_capi.h"
#include "rtwtypes.h"
#include "rtmodel.h"
#include "rt_sim.h"
#include "rt_logging.h"
#include "rtw_modelmap.h"
#include "ext_work.h"

/*=========*
 * Defines *
 *=========*/
#ifndef TRUE
#define FALSE                          (0)
#define TRUE                           (1)
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE                   1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS                   0
#endif

#ifndef RT
# error "must define RT"
#endif

#ifndef MODEL
# error "must define MODEL"
#endif

#ifndef NUMST
# error "must define number of sample times, NUMST"
#endif

#ifndef NCSTATES
# error "must define NCSTATES"
#endif

#define RUN_FOREVER                    -1.0
#define EXPAND_CONCAT(name1,name2)     name1 ## name2
#define CONCAT(name1,name2)            EXPAND_CONCAT(name1,name2)
#define RT_MODEL                       CONCAT(MODEL,_rtModel)

/*
   name2: U=Inport, Y=Outport, X=Parameter, DW=Discrete Work
 */
#define EXPAND_CONCAT3(name1,name2,name3) name1 ## _ ## name2 ## . ## name3
#define CONCAT3(name1,name2,name3)     EXPAND_CONCAT3(name1,name2,name3)
#define SIG_MODEL(suffix,name)         CONCAT3(MODEL,suffix,name)

/*====================*
 * External functions *
 *====================*/
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL *MODEL(void);
  extern void MdlInitializeSizes(void);
  extern void MdlInitializeSampleTimes(void);
  extern void MdlStart(void);
  extern void MdlOutputs(int_T tid);
  extern void MdlUpdate(int_T tid);
  extern void MdlTerminate(void);

#ifdef __cplusplus

}

#endif

#if NCSTATES > 0
#ifdef __cplusplus

extern "C"
{

#endif

  extern void rt_ODECreateIntegrationData(RTWSolverInfo *si);
  extern void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);

#ifdef __cplusplus

}

#endif

# define rt_CreateIntegrationData(S)   rt_ODECreateIntegrationData(rtmGetRTWSolverInfo(S));
# define rt_UpdateContinuousStates(S)  rt_ODEUpdateContinuousStates(rtmGetRTWSolverInfo(S));
# else
# define rt_CreateIntegrationData(S)   rtsiSetSolverName(rtmGetRTWSolverInfo(S),"FixedStepDiscrete");
# define rt_UpdateContinuousStates(S)                            /* Do Nothing */
#endif

/* static_inputs*/
const StaticESEInputSignal static_inputs[] = {
  { "in_voltage_a", "", 1 },

  { "in_voltage_b", "", 1 },

  { "in_voltage_c", "", 1 },

  { "in_current_a", "", 1 },

  { "in_current_b", "", 1 },

  { "in_current_c", "", 1 },
};

/*static_outputs*/
const StaticESEOutputSignal static_outputs[] = {
  { "out_voltage_a", "", 1 },

  { "out_voltage_b", "", 1 },

  { "out_voltage_c", "", 1 },
};

/*static_parameters */
const StaticESEParameter static_parameters[] = {
  { "Fn", "Nominal frequency", "Hz", 50, 0, 1000000 },

  { "Iang0_pcc", "Initial current angle injected at PCC", "rad",
    0.118707231926086, 0, 6.28318530717959 },

  { "Imag0_pcc", "Initial current magnitude injected at PCC", "A",
    703.871673738482, 0, 1000000000000 },

  { "Ki_I", "Integral gain of current controller (continuous)", "V/A", 8000,
    1e-06, 1000000 },

  { "Ki_PLL", "Integral gain of phase-locked loop (continous) ", "Hz/V", 0.02,
    1e-06, 1000000 },

  { "Kp_I", "Proportional gain of current controller (continuous)", "V/A", 400,
    1e-06, 1000000 },

  { "Kp_PLL", "Proportional gain of phase-locked loop (continous) ", "Hz/V",
    0.0002, 1e-06, 1000000 },

  { "Lc", "Converter inductance", "H", 0.1574, 1e-06, 1000000 },

  { "Pref", "Active power set-point", "W", 500000000, -500000000, 500000000 },

  { "Qref", "Reactive power set-point", "VAr", 100000000, -500000000, 500000000
  },

  { "Rc", "Converter resistance", "Ohm", 0.782, 1e-06, 1000000 },

  { "Tf_S", "Filter time constant of power control (continuous)", "s", 0.1,
    1e-06, 1000000 },

  { "Ts", "Simulation time step", "s", 5e-05, 1e-06, 0.0001 },

  { "Vang0_pcc", "Initial voltage angle at PCC", "rad", 0.316102791775967, 0,
    6.28318530717959 },

  { "Vmag0_pcc", "Initial voltage magnitude at PCC", "V", 418246.734257662, 0,
    1000000000000 },
};

/* static_model_info */
StaticExtSimEnvCapi static_model_info = {
  { 0, 8, 1, 5 },
  // const uint8_T APIRelease[4]: Release number of the API used during code generation
  "IEC_DLL_of_Matlab_Simulink_Model",
                                   // const char_T * const ModelName: Model name
  "R01-V01",                 // const char_T * const ModelVersion: Model version
  "Description of IEC_DLL_of_Matlab_Simulink_Model",
                     // const char_T * const ModelDescription: Model description
  "",    // const char_T * const VersionControlInfo: Version control information
  "-PFPrecise",         // const char_T * const GeneralInformation: General info
  "2026-02-18",           // const char_T * const ModelCreated: Model created on
  "Becker G., Frauenknecht, D.",
                          // const char_T * const ModelCreator: Model created by
  "2026-08-13",
          // const char_T * const ModelLastModifiedDate:  Model last modified on
  "Becker G., Frauenknecht, D.",
             // const char_T * const ModelLastModifiedBy: Model last modified by
  "",       // const char_T * const ModelModifiedComment: Model modified comment
  "",       // const char_T * const ModelModifiedHistory: Model modified history
  "2026-08-13",       // const char_T * const CodeGeneratedOn: Code generated on
  "",         // const char_T * const IncludedSolver: Solver name (can be empty)
  0.00005,      // const real64_T FixedStepBaseSampleTime: Base sample time size
  sizeof(static_inputs)/sizeof(static_inputs[0]),
                                // const int32_T NumInputPorts: Number of inputs
  &static_inputs[0],
  // const StaticESEInputSignal * const InputPortsInfo: Pointer to input signal description array
  sizeof(static_outputs)/sizeof(static_inputs[0]),
                              // const int32_T NumOutputPorts: Number of outputs
  &static_outputs[0],
  // const StaticESEOutputSignal * const OutputPortsInfo: Pointer to output signal description array
  sizeof(static_parameters)/sizeof(static_parameters[0]),
                            // const int32_T NumParameters: Number of parameters
  &static_parameters[0],
  // const StaticESEParameter * const ParametersInfo: Pointer to parameter description array
  0,                 // const int32_T NumContStates: Number of continuous states
  0,     // const int32_T SizeofMiscStates: Size of work variables / misc states

  { 0, 0, 0, 0 },
              // const uint32_T ModelChecksum[4]:  Model checksum (user defined)
  NULL,                  // const char_T *LastErrorMessage: Error string pointer
  3,
  // const uint8_T EMT_RMS_Mode: Mode: EMT = 1, RMS = 2, EMT & RMS = 3, otherwise: 0
  0,
  // const uint8_T LoadflowFlag: Model contains a loadflow function: 0 = no, 1 = yes
  0,                          // ESEExtension Extension: Provided for extensions
};

static RT_MODEL *S;

/* Model_GetInfo */
__declspec(dllexport) const StaticExtSimEnvCapi* __cdecl Model_GetInfo(void)
{
  return &static_model_info;
}

/* Model_Instance */
__declspec(dllexport) InstanceExtSimEnvCapi* __cdecl Model_Instance(void)
{
  uint8_T i, w;
  S = MODEL();
  InstanceExtSimEnvCapi * pInstanceCapi;
  pInstanceCapi = (InstanceExtSimEnvCapi *)malloc(sizeof(InstanceExtSimEnvCapi));
  if (pInstanceCapi == NULL) {
    return NULL;
  }

  /* allocate internal memory */
  /* ExternalInputs, taking into account width of vectorized signals */
  w = 0;
  for (i = 0; i < static_model_info.NumInputPorts; i++) {
    w = w + (&static_model_info)->InputPortsInfo[i].Width;
  }

  pInstanceCapi->ExtU_DISCON_Empty_T = (real64_T *)malloc(w*sizeof(real64_T));

  /* ExternalOutputs, taking into account width of vectorized signals */
  w = 0;
  for (i = 0; i < static_model_info.NumOutputPorts; i++) {
    w = w + (&static_model_info)->OutputPortsInfo[i].Width;
  }

  pInstanceCapi->ExtY_DISCON_Empty_T = (real64_T *)malloc(w*sizeof(real64_T));

  /* Parameters, only scalar entries */
  pInstanceCapi->P_DISCON_Empty_T = (real64_T *)malloc(
    static_model_info.NumParameters*sizeof(real64_T));

  /* ContinuousStates, not used in current version, set NULL */
  pInstanceCapi->ContinuousStates = NULL;

  /* StateDerivatives, not used in current version, set NULL */
  pInstanceCapi->StateDerivatives = NULL;

  /* MiscStates, not used in current version, set NULL */
  pInstanceCapi->MiscStates = NULL;

  /* LastGeneralMessage, not used in current version, set NULL */
  pInstanceCapi->LastGeneralMessage = NULL;

  /* VerboseLevel, presently not used */
  pInstanceCapi->VerboseLevel = 0;

  /* Extension, not used in current version */
  pInstanceCapi->Extension.UserVoidPtr = NULL;
  return pInstanceCapi;
}

/* Model_Check_Parameters */
__declspec(dllexport) const char* __cdecl Model_CheckParameters
  (InstanceExtSimEnvCapi *pInstanceCapi)
{
  // not used, nothing implemented
  return NULL;
}

/* Model_Loadflow */
__declspec(dllexport) const char* __cdecl Model_Loadflow(InstanceExtSimEnvCapi
  *pInstanceCapi)
{
  // not used, nothing implemented
  return NULL;
}

/* Model_Derivatives, not used current version, return NULL */
__declspec(dllexport) const char* __cdecl Model_Derivatives
  (InstanceExtSimEnvCapi *pInstanceCapi)
{
  return NULL;
}

/* Model_Terminate */
__declspec(dllexport) const char* __cdecl Model_Terminate(InstanceExtSimEnvCapi *
  pInstanceCapi)
{
  /* free ExternalInputs */
  free(pInstanceCapi->ExtU_DISCON_Empty_T);
  pInstanceCapi->ExtU_DISCON_Empty_T = NULL;

  /* free ExternalOutputs */
  free(pInstanceCapi->ExtY_DISCON_Empty_T);
  pInstanceCapi->ExtY_DISCON_Empty_T = NULL;

  /* free Parameters */
  free(pInstanceCapi->P_DISCON_Empty_T);
  pInstanceCapi->P_DISCON_Empty_T = NULL;

  /* free ContinuousStates */
  free(pInstanceCapi->ContinuousStates);
  pInstanceCapi->ContinuousStates = NULL;

  /* free StateDerivatives */
  free(pInstanceCapi->StateDerivatives);
  pInstanceCapi->StateDerivatives = NULL;

  /* free MiscStates */
  free(pInstanceCapi->MiscStates);
  pInstanceCapi->MiscStates = NULL;

  /* free model instance */
  free(pInstanceCapi);
  pInstanceCapi = NULL;
  return NULL;
}

/* Model_Initialize */
__declspec(dllexport) const char* __cdecl Model_Initialize(InstanceExtSimEnvCapi
  *pInstanceCapi)
{
  SIG_MODEL(P, Fn) = pInstanceCapi->P_DISCON_Empty_T[0];
  SIG_MODEL(P, Iang0_pcc) = pInstanceCapi->P_DISCON_Empty_T[1];
  SIG_MODEL(P, Imag0_pcc) = pInstanceCapi->P_DISCON_Empty_T[2];
  SIG_MODEL(P, Ki_I) = pInstanceCapi->P_DISCON_Empty_T[3];
  SIG_MODEL(P, Ki_PLL) = pInstanceCapi->P_DISCON_Empty_T[4];
  SIG_MODEL(P, Kp_I) = pInstanceCapi->P_DISCON_Empty_T[5];
  SIG_MODEL(P, Kp_PLL) = pInstanceCapi->P_DISCON_Empty_T[6];
  SIG_MODEL(P, Lc) = pInstanceCapi->P_DISCON_Empty_T[7];
  SIG_MODEL(P, Pref) = pInstanceCapi->P_DISCON_Empty_T[8];
  SIG_MODEL(P, Qref) = pInstanceCapi->P_DISCON_Empty_T[9];
  SIG_MODEL(P, Rc) = pInstanceCapi->P_DISCON_Empty_T[10];
  SIG_MODEL(P, Tf_S) = pInstanceCapi->P_DISCON_Empty_T[11];
  SIG_MODEL(P, Ts) = pInstanceCapi->P_DISCON_Empty_T[12];
  SIG_MODEL(P, Vang0_pcc) = pInstanceCapi->P_DISCON_Empty_T[13];
  SIG_MODEL(P, Vmag0_pcc) = pInstanceCapi->P_DISCON_Empty_T[14];
  SIG_MODEL(U, in_voltage_a) = pInstanceCapi->ExtU_DISCON_Empty_T[0];
  SIG_MODEL(U, in_voltage_b) = pInstanceCapi->ExtU_DISCON_Empty_T[1];
  SIG_MODEL(U, in_voltage_c) = pInstanceCapi->ExtU_DISCON_Empty_T[2];
  SIG_MODEL(U, in_current_a) = pInstanceCapi->ExtU_DISCON_Empty_T[3];
  SIG_MODEL(U, in_current_b) = pInstanceCapi->ExtU_DISCON_Empty_T[4];
  SIG_MODEL(U, in_current_c) = pInstanceCapi->ExtU_DISCON_Empty_T[5];
  MdlStart();
  MdlUpdate(0);
  return NULL;
}

/* Model_Outputs */
__declspec(dllexport) const char* __cdecl Model_Outputs(InstanceExtSimEnvCapi
  *pInstanceCapi, uint32_T IsMajorTimeStep)
{
  MdlOutputs(0);

  // Assign outputs foreach output found in thr compiled simulink model. Use SIG_Model to map the Simulink Signal to the IEC Signal
  pInstanceCapi->ExtY_DISCON_Empty_T[0] = SIG_MODEL(Y, out_voltage_a);
  pInstanceCapi->ExtY_DISCON_Empty_T[1] = SIG_MODEL(Y, out_voltage_b);
  pInstanceCapi->ExtY_DISCON_Empty_T[2] = SIG_MODEL(Y, out_voltage_c);
  return NULL;
}

/* Model_Update */
__declspec(dllexport) const char* __cdecl Model_Update(InstanceExtSimEnvCapi
  *pInstanceCapi)
{
  SIG_MODEL(U, in_voltage_a) = pInstanceCapi->ExtU_DISCON_Empty_T[0];
  SIG_MODEL(U, in_voltage_b) = pInstanceCapi->ExtU_DISCON_Empty_T[1];
  SIG_MODEL(U, in_voltage_c) = pInstanceCapi->ExtU_DISCON_Empty_T[2];
  SIG_MODEL(U, in_current_a) = pInstanceCapi->ExtU_DISCON_Empty_T[3];
  SIG_MODEL(U, in_current_b) = pInstanceCapi->ExtU_DISCON_Empty_T[4];
  SIG_MODEL(U, in_current_c) = pInstanceCapi->ExtU_DISCON_Empty_T[5];
  MdlUpdate(0);
  return NULL;
}
