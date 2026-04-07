/* 
 * File: ext_simenv_capi.h
 */

#ifndef __EXT_SIMENV_CAPI_H__
#define __EXT_SIMENV_CAPI_H__


/* Used fixed data type widths */
#include "ext_simenv_types.h"

/* Define NULL if not defined */
#ifndef NULL
 #define NULL    ((void *)0)
#endif


/* Static input, output information; vectorized signals are allowed */
typedef struct
{	
    const   char_T *    const           Name;			// Input signal name
	const   char_T *    const           BlockPath;		// Path to block in Simulink model
	const   int32_T		        	    Width;			// Signal width
}StaticESEInputSignal;

typedef struct
{	
    const   char_T *    const 	        Name;			// Output signal name
	const   char_T *    const    	    BlockPath;		// Path to block in Simulink model
	const   int32_T         			Width;			// Signal width
}StaticESEOutputSignal;



/* Static parameter information; only scalar parameters are allowed */
typedef struct
{	const char_T * const	Name;			// Parameter name
	const char_T * const	Description;	// Description
	const char_T * const	Unit;			// Unit
	const real64_T			DefaultValue;	// Default value
	const real64_T			MinValue;		// Minimum value
	const real64_T			MaxValue;		// Maximum value
}StaticESEParameter;



/* Union definition added to the static and instance specific structures and may be used for extension*/
typedef union
{	int8_T		UserInt8_8[8];
	uint8_T		UserUint8_8[8];
	int16_T		UserInt16_4[4];
	uint16_T	UserUint16_4[4];
	int32_T		UserInt32_2[2];
	uint32_T	UserUint32_2[2];
	char_T		UserChar_8[8];
	real32_T	UserReal32_2[2];
	real64_T	UserReal64;
	void		*UserVoidPtr;
}ESEExtension;



/* Static (not instance specific) model information */
typedef struct
{	const uint8_T						APIRelease[4];				// Release number of the API used during code generation
	const char_T * const				ModelName;					// Model name
	const char_T * const				ModelVersion;				// Model version
	const char_T * const				ModelDescription;			// Model description
	const char_T * const				VersionControlInfo;			// Version control information
	const char_T * const				GeneralInformation;			// General info - here some RTW info
	const char_T * const				ModelCreated;				// Model created on
	const char_T * const				ModelCreator;				// Model created by
	const char_T * const				ModelLastModifiedDate;		// Model last modified on
	const char_T * const				ModelLastModifiedBy;		// Model last modified by
	const char_T * const				ModelModifiedComment;		// Model modified comment
	const char_T * const				ModelModifiedHistory;		// Model modified history
	const char_T * const				CodeGeneratedOn;			// Code generated on
	const char_T * const				IncludedSolver;				// Solver name (can be empty)
	const real64_T						FixedStepBaseSampleTime;	// Base sample time
	const int32_T						NumInputPorts;				// Number of inputs
	const StaticESEInputSignal * const	InputPortsInfo;				// Pointer to input signal description array
	const int32_T						NumOutputPorts;				// Number of outputs
	const StaticESEOutputSignal * const	OutputPortsInfo;			// Pointer to output signal description array
	const int32_T						NumParameters;				// Number of parameters
	const StaticESEParameter * const	ParametersInfo;				// Pointer to parameter description array
	const int32_T						NumContStates;				// Number of continuous states
	const int32_T						SizeofMiscStates;			// Size of work variables / misc states
	const uint32_T						ModelChecksum[4];			// Simulink model checksum
	const char_T						*LastErrorMessage;			// Error string pointer
	const uint8_T						EMT_RMS_Mode;				// Mode: EMT = 1, RMS = 2, EMT & RMS = 3, otherwise: 0
	const uint8_T						LoadflowFlag;				// Model contains a loadflow function: 0 = no, 1 = yes
	ESEExtension						Extension;					// Provided for extensions
}StaticExtSimEnvCapi;



/* Instance specific model information */
typedef struct
{	real64_T			*ExtU_DISCON_Empty_T;		// Input signals, all elements in one long vector
	real64_T			*ExtY_DISCON_Empty_T;		// Output signals, all elements in one long vector
	real64_T			*P_DISCON_Empty_T;			    // Parameters as vector
	real64_T			*ContinuousStates;		    // We assume a states vector - not used in current version
	real64_T			*StateDerivatives;		    // We assume a states derivatives vector - not used in current version
	uint8_T				*MiscStates;			    // Work variables / states with unknown content
	const char_T		*LastErrorMessage;		    // Error string pointer
	const char_T		*LastGeneralMessage;	    // General message
	uint8_T				VerboseLevel;			    // Decides how much the code "should talk"
	ESEExtension		Extension;				    // Provided for extensions
}InstanceExtSimEnvCapi;

/* Function prototypes used when DLL is loaded via .lib */

/*	- Return the static model information structure
	  - Model and API version and release
	  - Short description and copyright
	  - Number and size of inputs and outputs
	  - Number, min/max/default value and unit of parameters
	  - Number of continuous states
	  - Sample time
	  - Code generation date and tool
	  - Model checksum
	  - Mechanisms for error handling
	Input:  /
	Output: Static model structure or NULL in case of an error
*/
extern __declspec(dllexport) const StaticExtSimEnvCapi* __cdecl Model_GetInfo(void);

/*	- Create an instance and access specific data
	  - input and output data
	  - parameters
	  - states and state derivatives
	- Mechanisms for error handling and debugging
	- Allows for unlimited number of instances
	- Mechanism provided to specify the sample time to be used
	- Pre-set of all internal states expected
	Input:  Sample time:    Ta > 0 => Take this sample time; Ta = -1 => Take sample time from code
			UseSolverInDLL: 1 => Use internal solver in dll; 0 => Use external solver from calling program
	Output: Instance specific model structure or NULL in case of an error (ModelStaticExtSimEnvCapi.LastErrorMessage hold the message)
			- Xcont_0 = fc_init(P)
			- Xdisc_0 = fd_init(P)
*/
extern __declspec(dllexport) InstanceExtSimEnvCapi* __cdecl Model_Instance(uint32_T UseSolverInDLL, real64_T Ta);

/*	Checks the parameters on the given range
	Input:  Instance specific model structure
	Output: NULL is ok, otherwise string that contains the message
 */
extern __declspec(dllexport) const char_T* __cdecl Model_CheckParameters(InstanceExtSimEnvCapi *pInstanceCapi);

/*	Calculates load flow function by setting the SimMode flag to 1 and calling the output equation
	Input:  Instance specific model structure
	Output: NULL is ok, otherwise string that contains the message
			- y = fout(P, Xdisc, Xcont, u)
			- Xcont = fc_out(P, u)
 */
extern __declspec(dllexport) const char_T* __cdecl Model_Loadflow(InstanceExtSimEnvCapi *pInstanceCapi);

/*	Initializes the system by resetting the internal states to defaults
	Input:  Instance specific model structure
	Output: NULL is ok, otherwise string that contains the message
 */
extern __declspec(dllexport) const char_T* __cdecl Model_Initialize(InstanceExtSimEnvCapi *pInstanceCapi);

/*	Calculates output equation
	Input:  Instance specific model structure
            IsMajorTimeStep: 1 => Major time step; 0 => Minor time step (time inbetween integration loop)
	Output: NULL is ok, otherwise string that contains the message
			- y = fout(P, Xdisc, Xcont, u)
			- Xcont = fc_out(P, u)
 */
extern __declspec(dllexport) const char_T* __cdecl Model_Outputs(InstanceExtSimEnvCapi *pInstanceCapi, uint32_T IsMajorTimeStep);

/*	Calculates update equation
	Input:  Instance specific model structure
	Output: NULL is ok, otherwise string that contains the message
			- Xdisc n+1 = fup(P, Xdisc, Xcont, u)
 */
extern __declspec(dllexport) const char_T* __cdecl Model_Update(InstanceExtSimEnvCapi *pInstanceCapi);

/*	Calculates derivatives equation
	Input:  Instance specific model structure
	Output: NULL is ok, otherwise string that contains the message
			- dXcont/dt = fderiv(P, Xdisc, Xcont, u)
 */
extern __declspec(dllexport) const char_T* __cdecl Model_Derivatives(InstanceExtSimEnvCapi *pInstanceCapi);

/*	Destroys an instance by freeing the memory
	Input:  Instance specific model structure
	Output: NULL is ok, otherwise string that contains the message
 */
extern __declspec(dllexport) const char_T* __cdecl Model_Terminate(InstanceExtSimEnvCapi *pInstanceCapi);



/* Function pointer types used when DLL is loaded explicitly via LoadLibrary */
typedef const StaticExtSimEnvCapi *(__cdecl* Model_GetInfo_type)(void);
typedef InstanceExtSimEnvCapi *(__cdecl* Model_Instance_type)(uint32_T UseSolverInDLL, real64_T Ta);
typedef const char_T *(__cdecl* Model_CheckParameters_type)(InstanceExtSimEnvCapi *pInstanceCapi);
typedef const char_T *(__cdecl* Model_Loadflow_type)(InstanceExtSimEnvCapi *pInstanceCapi);
typedef const char_T *(__cdecl* Model_Initialize_type)(InstanceExtSimEnvCapi *pInstanceCapi);
typedef const char_T *(__cdecl* Model_Outputs_type)(InstanceExtSimEnvCapi *pInstanceCapi, uint32_T IsMajorTimeStep);
typedef const char_T *(__cdecl* Model_Update_type)(InstanceExtSimEnvCapi *pInstanceCapi);
typedef const char_T *(__cdecl* Model_Derivatives_type)(InstanceExtSimEnvCapi *pInstanceCapi);
typedef const char_T *(__cdecl* Model_Terminate_type)(InstanceExtSimEnvCapi *pInstanceCapi);




#endif /* __EXT_SIMENV_CAPI_H__ */
