/*
 * IBR_Control_2024b.h
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

#ifndef IBR_Control_2024b_h_
#define IBR_Control_2024b_h_
#ifndef IBR_Control_2024b_COMMON_INCLUDES_
#define IBR_Control_2024b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* IBR_Control_2024b_COMMON_INCLUDES_ */

#include "IBR_Control_2024b_types.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ()
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ()
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTimerIndices
#define rtmGetMdlRefGlobalTimerIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalTimerIndices
#define rtmSetMdlRefGlobalTimerIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ()
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ()
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ()
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ()
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetProxyFunctions
#define rtmGetProxyFunctions(rtm)      ()
#endif

#ifndef rtmSetProxyFunctions
#define rtmSetProxyFunctions(rtm, val) ()
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStubFunctions
#define rtmGetStubFunctions(rtm)       ()
#endif

#ifndef rtmSetStubFunctions
#define rtmSetStubFunctions(rtm, val)  ()
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define IBR_Control_2024b_rtModel      RT_MODEL_IBR_Control_2024b_T

/* Block signals (default storage) */
typedef struct {
  real_T VectorConcatenate3[4];        /* '<S115>/Vector Concatenate3' */
  real_T VectorConcatenate3_n[4];      /* '<S114>/Vector Concatenate3' */
  real_T sqrt2sqrt31;                  /* '<S170>/sqrt(2)//sqrt(3)1' */
  real_T sqrt2sqrt3;                   /* '<S170>/sqrt(2)//sqrt(3)' */
  real_T DiscreteTimeIntegrator;       /* '<S7>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S7>/Discrete-Time Integrator1' */
  real_T VectorConcatenate[2];         /* '<S7>/Vector Concatenate' */
  real_T sqrt2sqrt31_n;                /* '<S169>/sqrt(2)//sqrt(3)1' */
  real_T Gain7;                        /* '<S169>/Gain7' */
  real_T Sum1;                         /* '<S3>/Sum1' */
  real_T Sum;                          /* '<S53>/Sum' */
  real_T Sum1_m;                       /* '<S6>/Sum1' */
  real_T Gain3;                        /* '<S6>/Gain3' */
  real_T Gain5;                        /* '<S3>/Gain5' */
  real_T Sum2;                         /* '<S3>/Sum2' */
  real_T Sum_f;                        /* '<S105>/Sum' */
  real_T IntegralGain;                 /* '<S93>/Integral Gain' */
  real_T IntegralGain_g;               /* '<S148>/Integral Gain' */
  real_T IntegralGain_n;               /* '<S41>/Integral Gain' */
  real_T Gain1;                        /* '<S7>/Gain1' */
  real_T Gain5_h;                      /* '<S7>/Gain5' */
  real_T Gain;                         /* '<S7>/Gain' */
  real_T Gain3_n;                      /* '<S7>/Gain3' */
} B_IBR_Control_2024b_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S6>/Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S7>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S7>/Discrete-Time Integrator1' */
  real_T Integrator_DSTATE_i;          /* '<S44>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S151>/Integrator' */
  real_T Integrator_DSTATE_k;          /* '<S96>/Integrator' */
} DW_IBR_Control_2024b_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T in_voltage_a;                 /* '<Root>/in_voltage_a' */
  real_T in_voltage_b;                 /* '<Root>/in_voltage_b' */
  real_T in_voltage_c;                 /* '<Root>/in_voltage_c' */
  real_T in_current_a;                 /* '<Root>/in_current_a' */
  real_T in_current_b;                 /* '<Root>/in_current_b' */
  real_T in_current_c;                 /* '<Root>/in_current_c' */
} ExtU_IBR_Control_2024b_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T out_voltage_a;                /* '<Root>/out_voltage_a' */
  real_T out_voltage_b;                /* '<Root>/out_voltage_b' */
  real_T out_voltage_c;                /* '<Root>/out_voltage_c' */
} ExtY_IBR_Control_2024b_T;

/* Backward compatible GRT Identifiers */
#define rtB                            IBR_Control_2024b_B
#define BlockIO                        B_IBR_Control_2024b_T
#define rtU                            IBR_Control_2024b_U
#define ExternalInputs                 ExtU_IBR_Control_2024b_T
#define rtY                            IBR_Control_2024b_Y
#define ExternalOutputs                ExtY_IBR_Control_2024b_T
#define rtP                            IBR_Control_2024b_P
#define Parameters                     P_IBR_Control_2024b_T
#define rtDWork                        IBR_Control_2024b_DW
#define D_Work                         DW_IBR_Control_2024b_T

/* Parameters (default storage) */
struct P_IBR_Control_2024b_T_ {
  real_T Fn;                           /* Variable: Fn
                                        * Referenced by:
                                        *   '<S1>/k'
                                        *   '<S6>/Constant'
                                        *   '<S6>/Integrator'
                                        *   '<S169>/Gain6'
                                        *   '<S169>/sqrt(2)//sqrt(3)1'
                                        *   '<S170>/speed'
                                        *   '<S170>/sqrt(2)//sqrt(3)1'
                                        */
  real_T Iang0_pcc;                    /* Variable: Iang0_pcc
                                        * Referenced by: '<S169>/Iang0_pcc'
                                        */
  real_T Imag0_pcc;                    /* Variable: Imag0_pcc
                                        * Referenced by: '<S169>/Imag0_pcc'
                                        */
  real_T Ki_I;                         /* Variable: Ki_I
                                        * Referenced by:
                                        *   '<S41>/Integral Gain'
                                        *   '<S93>/Integral Gain'
                                        */
  real_T Ki_PLL;                       /* Variable: Ki_PLL
                                        * Referenced by: '<S148>/Integral Gain'
                                        */
  real_T Kp_I;                         /* Variable: Kp_I
                                        * Referenced by:
                                        *   '<S49>/Proportional Gain'
                                        *   '<S101>/Proportional Gain'
                                        */
  real_T Kp_PLL;                       /* Variable: Kp_PLL
                                        * Referenced by: '<S156>/Proportional Gain'
                                        */
  real_T Lc;                           /* Variable: Lc
                                        * Referenced by: '<S3>/Gain5'
                                        */
  real_T Pref;                         /* Variable: Pref
                                        * Referenced by:
                                        *   '<S7>/Pref'
                                        *   '<S7>/Discrete-Time Integrator'
                                        *   '<S44>/Integrator'
                                        */
  real_T Qref;                         /* Variable: Qref
                                        * Referenced by:
                                        *   '<S7>/Qref'
                                        *   '<S7>/Discrete-Time Integrator1'
                                        *   '<S96>/Integrator'
                                        */
  real_T Rc;                           /* Variable: Rc
                                        * Referenced by:
                                        *   '<S44>/Integrator'
                                        *   '<S96>/Integrator'
                                        */
  real_T Tf_S;                         /* Variable: Tf_S
                                        * Referenced by: '<S7>/Gain3'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<S1>/k'
                                        *   '<S2>/Step'
                                        *   '<S6>/Integrator'
                                        *   '<S169>/Constant'
                                        *   '<S169>/sqrt(2)//sqrt(3)1'
                                        *   '<S170>/Constant'
                                        *   '<S170>/sqrt(2)//sqrt(3)1'
                                        */
  real_T Vang0_pcc;                    /* Variable: Vang0_pcc
                                        * Referenced by:
                                        *   '<S6>/Integrator'
                                        *   '<S170>/Vang0_pcc'
                                        */
  real_T Vmag0_pcc;                    /* Variable: Vmag0_pcc
                                        * Referenced by:
                                        *   '<S7>/Discrete-Time Integrator'
                                        *   '<S7>/Discrete-Time Integrator1'
                                        *   '<S170>/Vmag0_pcc'
                                        *   '<S44>/Integrator'
                                        *   '<S96>/Integrator'
                                        */
  real_T PIController_InitialConditionFo;
                              /* Mask Parameter: PIController_InitialConditionFo
                               * Referenced by: '<S151>/Integrator'
                               */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S6>/Integrator'
                                        */
  real_T upi_Value;                    /* Expression: 2*pi
                                        * Referenced by: '<S6>/2pi'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S115>/Gain'
                                        */
  real_T phasecorrection_Value;        /* Expression: 2
                                        * Referenced by: '<S1>/phase correction'
                                        */
  real_T Gain_Gain_m;                  /* Expression: -1
                                        * Referenced by: '<S114>/Gain'
                                        */
  real_T phasecorrection_Value_l;      /* Expression: 2
                                        * Referenced by: '<S170>/phase correction'
                                        */
  real_T sqrt2sqrt3_Gain;              /* Expression: sqrt(2)/sqrt(3)
                                        * Referenced by: '<S170>/sqrt(2)//sqrt(3)'
                                        */
  real_T Step_Y0;                      /* Expression: 1
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Switch6_Threshold;            /* Expression: 0
                                        * Referenced by: '<S170>/Switch6'
                                        */
  real_T u3pi_Value;                   /* Expression: 2/3*pi
                                        * Referenced by: '<S170>/2//3*pi'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S170>/Switch2'
                                        */
  real_T u3pi_Value_e;                 /* Expression: 4/3*pi
                                        * Referenced by: '<S170>/4//3*pi'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S170>/Switch1'
                                        */
  real_T voltageclarketransformation_Gai[6];
                        /* Expression: 2/3*[1 -1/2 -1/2; 0 sqrt(3)/2 -sqrt(3)/2]
                         * Referenced by: '<S5>/voltage -  clarke transformation'
                         */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S7>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S7>/Discrete-Time Integrator1'
                           */
  real_T phasecorrection_Value_h;      /* Expression: 2
                                        * Referenced by: '<S169>/phase correction'
                                        */
  real_T Gain7_Gain;                   /* Expression: sqrt(2)
                                        * Referenced by: '<S169>/Gain7'
                                        */
  real_T Switch7_Threshold;            /* Expression: 0
                                        * Referenced by: '<S169>/Switch7'
                                        */
  real_T Constant13_Value;             /* Expression: 2/3*pi
                                        * Referenced by: '<S169>/Constant13'
                                        */
  real_T Switch8_Threshold;            /* Expression: 0
                                        * Referenced by: '<S169>/Switch8'
                                        */
  real_T Constant14_Value;             /* Expression: 4/3*pi
                                        * Referenced by: '<S169>/Constant14'
                                        */
  real_T Switch9_Threshold;            /* Expression: 0
                                        * Referenced by: '<S169>/Switch9'
                                        */
  real_T currentclarketransformation_Gai[6];
                        /* Expression: 2/3*[1 -1/2 -1/2; 0 sqrt(3)/2 -sqrt(3)/2]
                         * Referenced by: '<S5>/current -  clarke transformation'
                         */
  real_T Integrator_gainval_a;       /* Computed Parameter: Integrator_gainval_a
                                      * Referenced by: '<S44>/Integrator'
                                      */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T Integrator_gainval_b;       /* Computed Parameter: Integrator_gainval_b
                                      * Referenced by: '<S151>/Integrator'
                                      */
  real_T Gain3_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T Integrator_gainval_ba;     /* Computed Parameter: Integrator_gainval_ba
                                     * Referenced by: '<S96>/Integrator'
                                     */
  real_T inverseclarketransformation_Gai[6];
                             /* Expression: [1 0;-1/2 sqrt(3)/2;-1/2 -sqrt(3)/2]
                              * Referenced by: '<S4>/inverse clarke transformation'
                              */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0.1
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: -2/3
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S7>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/0.1
                                        * Referenced by: '<S7>/Gain5'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 2/3
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S7>/Gain2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_IBR_Control_2024b_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
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
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

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
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
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
extern P_IBR_Control_2024b_T IBR_Control_2024b_P;

/* Block signals (default storage) */
extern B_IBR_Control_2024b_T IBR_Control_2024b_B;

/* Block states (default storage) */
extern DW_IBR_Control_2024b_T IBR_Control_2024b_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_IBR_Control_2024b_T IBR_Control_2024b_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_IBR_Control_2024b_T IBR_Control_2024b_Y;

/*====================*
 * External functions *
 *====================*/
extern IBR_Control_2024b_rtModel *IBR_Control_2024b(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_IBR_Control_2024b_T *const IBR_Control_2024b_M;

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
 * '<Root>' : 'IBR_Control_2024b'
 * '<S1>'   : 'IBR_Control_2024b/IBR Control System'
 * '<S2>'   : 'IBR_Control_2024b/IBR Inputs'
 * '<S3>'   : 'IBR_Control_2024b/IBR Control System/current control'
 * '<S4>'   : 'IBR_Control_2024b/IBR Control System/inverse park transformation'
 * '<S5>'   : 'IBR_Control_2024b/IBR Control System/park transformation'
 * '<S6>'   : 'IBR_Control_2024b/IBR Control System/phase-locked loop'
 * '<S7>'   : 'IBR_Control_2024b/IBR Control System/power control'
 * '<S8>'   : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller'
 * '<S9>'   : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller'
 * '<S10>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Anti-windup'
 * '<S11>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/D Gain'
 * '<S12>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/External Derivative'
 * '<S13>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Filter'
 * '<S14>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Filter ICs'
 * '<S15>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/I Gain'
 * '<S16>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Ideal P Gain'
 * '<S17>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Ideal P Gain Fdbk'
 * '<S18>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Integrator'
 * '<S19>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Integrator ICs'
 * '<S20>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/N Copy'
 * '<S21>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/N Gain'
 * '<S22>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/P Copy'
 * '<S23>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Parallel P Gain'
 * '<S24>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Reset Signal'
 * '<S25>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Saturation'
 * '<S26>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Saturation Fdbk'
 * '<S27>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Sum'
 * '<S28>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Sum Fdbk'
 * '<S29>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Tracking Mode'
 * '<S30>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Tracking Mode Sum'
 * '<S31>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Tsamp - Integral'
 * '<S32>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Tsamp - Ngain'
 * '<S33>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/postSat Signal'
 * '<S34>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/preInt Signal'
 * '<S35>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/preSat Signal'
 * '<S36>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Anti-windup/Passthrough'
 * '<S37>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/D Gain/Disabled'
 * '<S38>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/External Derivative/Disabled'
 * '<S39>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Filter/Disabled'
 * '<S40>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Filter ICs/Disabled'
 * '<S41>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/I Gain/Internal Parameters'
 * '<S42>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Ideal P Gain/Passthrough'
 * '<S43>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Integrator/Discrete'
 * '<S45>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Integrator ICs/Internal IC'
 * '<S46>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/N Copy/Disabled wSignal Specification'
 * '<S47>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/N Gain/Disabled'
 * '<S48>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/P Copy/Disabled'
 * '<S49>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Parallel P Gain/Internal Parameters'
 * '<S50>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Reset Signal/Disabled'
 * '<S51>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Saturation/Passthrough'
 * '<S52>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Saturation Fdbk/Disabled'
 * '<S53>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Sum/Sum_PI'
 * '<S54>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Sum Fdbk/Disabled'
 * '<S55>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Tracking Mode/Disabled'
 * '<S56>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S58>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/postSat Signal/Forward_Path'
 * '<S60>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/preInt Signal/Internal PreInt'
 * '<S61>'  : 'IBR_Control_2024b/IBR Control System/current control/d - PI Controller/preSat Signal/Forward_Path'
 * '<S62>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Anti-windup'
 * '<S63>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/D Gain'
 * '<S64>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/External Derivative'
 * '<S65>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Filter'
 * '<S66>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Filter ICs'
 * '<S67>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/I Gain'
 * '<S68>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Ideal P Gain'
 * '<S69>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Ideal P Gain Fdbk'
 * '<S70>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Integrator'
 * '<S71>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Integrator ICs'
 * '<S72>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/N Copy'
 * '<S73>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/N Gain'
 * '<S74>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/P Copy'
 * '<S75>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Parallel P Gain'
 * '<S76>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Reset Signal'
 * '<S77>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Saturation'
 * '<S78>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Saturation Fdbk'
 * '<S79>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Sum'
 * '<S80>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Sum Fdbk'
 * '<S81>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Tracking Mode'
 * '<S82>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Tracking Mode Sum'
 * '<S83>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Tsamp - Integral'
 * '<S84>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Tsamp - Ngain'
 * '<S85>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/postSat Signal'
 * '<S86>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/preInt Signal'
 * '<S87>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/preSat Signal'
 * '<S88>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Anti-windup/Passthrough'
 * '<S89>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/D Gain/Disabled'
 * '<S90>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/External Derivative/Disabled'
 * '<S91>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Filter/Disabled'
 * '<S92>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Filter ICs/Disabled'
 * '<S93>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/I Gain/Internal Parameters'
 * '<S94>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Ideal P Gain/Passthrough'
 * '<S95>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Integrator/Discrete'
 * '<S97>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Integrator ICs/Internal IC'
 * '<S98>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/N Copy/Disabled wSignal Specification'
 * '<S99>'  : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/N Gain/Disabled'
 * '<S100>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/P Copy/Disabled'
 * '<S101>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Parallel P Gain/Internal Parameters'
 * '<S102>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Reset Signal/Disabled'
 * '<S103>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Saturation/Passthrough'
 * '<S104>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Saturation Fdbk/Disabled'
 * '<S105>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Sum/Sum_PI'
 * '<S106>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Sum Fdbk/Disabled'
 * '<S107>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Tracking Mode/Disabled'
 * '<S108>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S110>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/postSat Signal/Forward_Path'
 * '<S112>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/preInt Signal/Internal PreInt'
 * '<S113>' : 'IBR_Control_2024b/IBR Control System/current control/q - PI Controller/preSat Signal/Forward_Path'
 * '<S114>' : 'IBR_Control_2024b/IBR Control System/inverse park transformation/inverse park transformation matrix'
 * '<S115>' : 'IBR_Control_2024b/IBR Control System/park transformation/park transformation matrix'
 * '<S116>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller'
 * '<S117>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Anti-windup'
 * '<S118>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/D Gain'
 * '<S119>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/External Derivative'
 * '<S120>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Filter'
 * '<S121>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Filter ICs'
 * '<S122>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/I Gain'
 * '<S123>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Ideal P Gain'
 * '<S124>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Ideal P Gain Fdbk'
 * '<S125>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Integrator'
 * '<S126>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Integrator ICs'
 * '<S127>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/N Copy'
 * '<S128>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/N Gain'
 * '<S129>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/P Copy'
 * '<S130>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Parallel P Gain'
 * '<S131>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Reset Signal'
 * '<S132>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Saturation'
 * '<S133>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Saturation Fdbk'
 * '<S134>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Sum'
 * '<S135>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Sum Fdbk'
 * '<S136>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Tracking Mode'
 * '<S137>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Tracking Mode Sum'
 * '<S138>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Tsamp - Integral'
 * '<S139>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Tsamp - Ngain'
 * '<S140>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/postSat Signal'
 * '<S141>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/preInt Signal'
 * '<S142>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/preSat Signal'
 * '<S143>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Anti-windup/Passthrough'
 * '<S144>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/D Gain/Disabled'
 * '<S145>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/External Derivative/Disabled'
 * '<S146>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Filter/Disabled'
 * '<S147>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Filter ICs/Disabled'
 * '<S148>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/I Gain/Internal Parameters'
 * '<S149>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Ideal P Gain/Passthrough'
 * '<S150>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Ideal P Gain Fdbk/Disabled'
 * '<S151>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Integrator/Discrete'
 * '<S152>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Integrator ICs/Internal IC'
 * '<S153>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/N Copy/Disabled wSignal Specification'
 * '<S154>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/N Gain/Disabled'
 * '<S155>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/P Copy/Disabled'
 * '<S156>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Parallel P Gain/Internal Parameters'
 * '<S157>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Reset Signal/Disabled'
 * '<S158>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Saturation/Passthrough'
 * '<S159>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Saturation Fdbk/Disabled'
 * '<S160>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Sum/Sum_PI'
 * '<S161>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Sum Fdbk/Disabled'
 * '<S162>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Tracking Mode/Disabled'
 * '<S163>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Tracking Mode Sum/Passthrough'
 * '<S164>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S165>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/Tsamp - Ngain/Passthrough'
 * '<S166>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/postSat Signal/Forward_Path'
 * '<S167>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/preInt Signal/Internal PreInt'
 * '<S168>' : 'IBR_Control_2024b/IBR Control System/phase-locked loop/PI Controller/preSat Signal/Forward_Path'
 * '<S169>' : 'IBR_Control_2024b/IBR Inputs/Current'
 * '<S170>' : 'IBR_Control_2024b/IBR Inputs/Voltage'
 */
#endif                                 /* IBR_Control_2024b_h_ */
