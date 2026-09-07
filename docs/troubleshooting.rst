###############
Troubleshooting
###############

During the installation or execution of the **Simulink IEC 61400-27 DLL Builder**, various error messages may occur. 
These errors can be caused by issues related to the installation environment, missing dependencies, configuration settings, or the execution of the generated DLL.

This troubleshooting guide provides an overview of common error messages and their possible causes. For each issue, recommended solutions and steps for resolving the problem are provided.

During the DLL Creation Process 
-------------------------------
DLL Creation - 001: not a Member of / ist kein Member von 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
**Error Message**::

    IEC61400_27_DLL.c(397): error C2039: "<part of an output label>" ist kein Member von "ExtY_IBR_Control_2024b_T".
    IEC61400_27_DLL.c(397): error C2143: Syntaxfehler: Es fehlt ";" vor ":"

**Possible Error Cause:** There might be a ``:`` within one of your output labels which is not allowed.

**Debugging:** Make sure to remove ``:`` from your output labels.


Integration
-----------
Integration - 001: First sample inf
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
**Error Message**::
	
    The error message differs between the different simulation tools.
			
**Possible Error Cause:** If the first sample is inf it is typically indicating a devision by zero within your DLL.

**Debugging:** Make sure even a zero input into the DLL does not lead to a division by zero occasion.


DIgSILENT PowerFactory
^^^^^^^^^^^^^^^^^^^^^^
PowerFactory - 001: DLL file <your DLL path> could not be loaded
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
**Error Message**::
	
    Grid\IBR_DLL.ElmDsl: DLL file <your DLL path> could not be loaded.		

**Possible Error Cause:** Typically this occurs during the usage of the example since DIgSILENT PowerFactory needs absolute file paths and you did not adapted it to your systems' path.

**Debugging:** Change the DLL file path with in the DSL definition of the IBR_DLL.


PSS®NETOMAC
^^^^^^^^^^^


PSCAD™
^^^^^^^
PSCAD - 001:  Can't open module file 'ifwin.mod'
''''''''''''''''''''''''''''''''''''''''''''''''
**Error Message**::
	
    Fatal Error: Can't open module file 'ifwin.mod' for reading at (1): No such file or directory
			
**Possible Error Cause:** This is typically an error message resulting from the usage of a GFortran compiler. 

**Debugging:** Make sure to install a IntelFortran compiler and choosing the correct one within the Application options.

PSCAD - 002:  Cannot find any files from path "<your_path>\PSCAD\IBR_Control_FINTERFACE_PSCAD.f90"
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
**Error Message**::

	Cannot find any files from path "<your_path>\PSCAD\IBR_Control_FINTERFACE_PSCAD.f90"
			
**Possible Error Cause:** The fortran wrapper for your IEC 61400-27 DLL is missing.

**Debugging:** Rerun the PSCAD IEC 61400-27 DLL Importer to create a new Fortran wrapper.