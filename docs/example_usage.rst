#############
Example Usage
#############

.. error::

    Hier noch eine kurze Einleitung

Prerequisites
-------------
- Matlab/Simulink
- Simulink Coder Toolbox 

1. Preparing the Working Directory
-----------------------------------

Before any modeling work can begin, a correctly structured working directory must be set up. 
The working directory is the folder from which the Simulink model is opened and in which the
Simulink Coder later searches for the System Target File, the Target Language Compiler (TLC)
files, and all supporting header and source files.

The recommended and simplest way to obtain the complete working directory is by cloning the 
project repository. This ensures that all required files are available in the correct folder 
structure and that the latest revisions are used.

.. code-block:: console

    git clone <repository-url>


The following files and folders must be present in (or copied into) the working directory:

+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+
| File                              | Function                                                                                                                     |
+===================================+==============================================================================================================================+
| `IEC61400_27_DLL.tlc`             | System Target File that controls the Simulink code generation process and the creation of the controller DLL.                |
+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+
| `IEC61400_27_DLL.tmf`             | Template makefile used during the compilation and linking of the generated C code.                                           |
+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+
| `IEC61400_27_DLL_make_rtw_hook.m` | Build hook executed after code generation and before the DLL is built. It exports the parameter descriptions, units, and     |
|                                   | limits to `ParameterMetadata.tlc` by invoking `getParamMetadataRTW.m`.                                                       |
+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+
| `getParamMetadataRTW.m`           | MATLAB script that implements the export of the parameter metadata.                                                          |
+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+
| `ext_simenv_capi.h`               | C API header that defines the IEC 61400-27 interface every generated DLL must implement.                                     |
+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+
| `ext_simenv_types.h`              | C API header that defines the data types used by the IEC 61400-27 interface.                                                 |
+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+
| `sfun_info.mexw64`                | Compiled S-Function that triggers `sfun_info.tlc` during code generation.                                                    |
+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+
| `sfun_info.tlc`                   | The TLC file generates the additional C source required for the controller DLL.                                              |
+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+

.. note:: 

   The ``sfun_info.c`` file contains the source code corresponding to the compiled ``sfun_info.mexw64`` 
   file and is therefore only required if modifications to the source code are necessary. It is of 
   secondary importance for the actual build process.

Once the directory is prepared, it should contain everything required by the subsequent steps without 
any additional files needing to be added manually — with the exception of the actual Simulink model 
and its parameter script, which are created in step 2.


2. Building a Simulink Model
----------------------------
.. error::

    Hier noch eine kurze Einleitung
    
Designing the Simulink model
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. error::

    @Domi kannst du das ergänzen also ne kleine Beschreibung der Regelung
    WICHITG: es braucht eine Erklärung, dass das eine das Beispiel und das andere der Benchmark ist. 
    Geben wir noch ein "leeres" Modell raus?

Creating the Parameter Script
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The MATLAB script ``IBR_Control_Parameters.m`` represents the parameter script of the given example. 
Its primary purpose is to generate all controller parameters, compute the required operating point, and initialize the workspace with 
the data required by the model.

Definition of the Electrical System 
'''''''''''''''''''''''''''''''''''
The script first defines the electrical characteristics of the inverter-based resource (IBR) and the external grid.

The following parameters are specified:

* Converter rated apparent power
* Filter resistance and inductance
* Active and reactive power setpoints
* Nominal grid voltage
* Nominal grid frequency
* Short-circuit ratio (SCR)
* Grid resistance-to-reactance (R/X) ratio

From these values, the equivalent Thevenin representation of the external grid is derived. 
This electrical model forms the basis for all subsequent steady-state calculations.


Load-Flow Calculation
'''''''''''''''''''''
After the electrical parameters have been defined, the script determines the steady-state operating point of the converter.

The Kirchhoff Voltage Law (KVL) equations implemented in ``KVL_equations`` are solved using MATLAB's ``fsolve`` function. 
The solution yields the voltage phasor at the Point of Common Coupling (PCC).

Using this voltage, the script calculates

- the converter current phasor,
- the converter terminal voltage,
- and all remaining steady-state electrical quantities.

These quantities define the operating point used for controller initialization.

.. error:: 

   Update the result of the load flow calculation @Domi.

.. _fig_phasor_diagram:

.. figure:: ./images/ibr_steady_state_phasor_diagram_high_contrast.png
   :align: center
   :width: 50%

   Steady-state phasor diagram showing the grid voltage, PCC voltage, converter voltage, and converter current.

Computation of Initial Conditions
'''''''''''''''''''''''''''''''''
To minimize artificial transients at the beginning of a simulation, the controller is initialized directly at its steady-state operating point.

The calculated phasors are used to determine the initial values of

- the three-phase (``abc``) currents,
- the PLL angle,
- the ``dq`` current components,
- the current-controller integrator states,
- and the voltage feed-forward terms.

Initializing the controller with these values ensures that all internal controller states are consistent with the calculated operating point.

Controller Parameter Calculation
''''''''''''''''''''''''''''''''

After the operating point has been established, the controller parameters are calculated.

The script computes the gains and time constants for

- the active and reactive power controller,
- the current controller,
- the phase-locked loop (PLL),
- and the associated low-pass filters.

All controller coefficients are calculated using the selected fixed simulation step size ``Ts`` to ensure consistent discrete-time behaviour.

Export of ``Simulink.Parameter`` Objects
''''''''''''''''''''''''''''''''''''''''
Once all calculations have been completed, temporary variables are removed from the MATLAB workspace.

Only the parameters required by the controller are converted into `Simulink.Parameter <https://de.mathworks.com/help/simulink/slref/simulink.parameter.html>`_ 
objects and placed in the MATLAB base workspace.

This step is essential for the subsequent code-generation process. The metadata extraction performed by the IEC 61400-27 DLL Builder only 
recognizes variables of type `Simulink.Parameter <https://de.mathworks.com/help/simulink/slref/simulink.parameter.html>`_. Ordinary MATLAB variables 
are ignored and therefore cannot be exported as tunable parameters.

Workspace Export
''''''''''''''''
Finally, all generated parameters are stored in ``IBR_Control_Parameters.mat``.

.. note::

   Execute ``IBR_Control_Parameters.m`` whenever a model parameter has been modified. 


3. Adjusting the Simulink Model Structure for the Export Process
----------------------------------------------------------------

A dynamic model that simulates correctly in Simulink is not automatically ready to be exported as a DLL. 
Before code generation can be started, the model structure must be adapted so that the Simulink Coder and the
metadata extraction process can interpret it correctly.

This step consists of three sub-tasks:

Adding the Model Information Module
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The ``sfun_info`` block is already part of the examplary Simulink model and thus does not need to be added within 
the context of the example usage.

Converting Tunable Parameters to Simulink.Parameter Objects
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
This process step was already executed at the end of the ``IBR_Control_Parameters.m`` script and can thus be ignored within 
the context of the given example.

Defining the Top-Level In-/Outports
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The generated DLL communicates with the external simulation environment exclusively through the fixed C API declared in 
``ext_simenv_capi.h``. Consequently, every signal that must be accessible externally has to be exposed as a top-level 
``Inport`` or ``Outport`` block:

- Signals buried inside subsystems are **not** picked up by the code generator.
- Port names become the ``Name`` field returned by ``Model_GetInfo()`` and should therefore be descriptive and stable.
- Port ordering determines the layout of the flat ``ExtU``/ ``ExtY`` vectors in the generated code and must be agreed upon with 
  the target simulation environment.
- All port data types should be kept as ``double`` to match the ``real64_T`` pointers used by the C API.

.. note::

   These three sub-tasks are typically performed once per model and only
   need to be repeated when the Simulink model's parameter set or its
   external interface (inputs/outputs) changes.


4. Preparing the Simulink Coder
-------------------------------

Once the model structure has been finalized, the Simulink Coder App is
opened from the Simulink toolbar in order to configure the code
generation process.

.. figure:: ./images/GeneralWorkflow/SimulinkCoder.png
   :alt: Opening the Simulink Coder App

   Opening the Simulink Coder App.

The key configuration step is verifying the **System Target File**
selected under *Settings → Code Generation*:

.. figure:: ./images/GeneralWorkflow/SimulinkCoderSettings.png
   :alt: Simulink Coder settings dialog

   Opening the Simulink Coder settings.

.. figure:: ./images/GeneralWorkflow/SimulinkCoderSettingsCodeGeneration.png
   :alt: Code Generation tab

   Selecting the Code Generation tab.

The System Target File must be set to ``IEC61400_27_DLL.tlc``, which must be available in the working directory prepared in 
step 1. If a different target file is selected, it must be changed accordingly before proceeding — otherwise the build will 
not produce a DLL compatible with the IEC 61400-27 external model interface.

Selecting this system target file adds a new menu item, ``Simulink DLL Builder``, to the Simulink menu bar. 
Clicking this menu item opens the metadata dialog, which is pre-populated with the default values of the example. 
These values must be reviewed and adjusted as required for the specific model.

.. figure:: ./images/GeneralWorkflow/SimulinkCoderSettingsMetaData.png
   :alt: Code Generation Simulink DLL Builder tab

   Filling the Model/DLL Metadata necessary for the DLL Code generation process.


5. Starting the Creation Process
--------------------------------

With the correct target file selected, the build process is started by clicking **Build** in the Simulink Coder App.

.. figure:: ./images/GeneralWorkflow/SimulinkCoderBuild.png
   :alt: Starting the code generation process

   Starting the code generation process.

Depending on the size of the model and the performance of the local system, the build may take anywhere from a few seconds 
to several minutes. During this process, the compiler and linker — configured via ``IEC61400_27_DLL.tmf`` — generate the 
C code from the model, compile it, and link it into the final binary output.

.. note::

   If the corresponding DLL is currently in use by a DIgSILENT PowerFactory project or within the Import Tool for PSCAD 
   (e.g. while updating a control model), ensure that the project is deactivated / the import tool is closed before starting 
   the build process, otherwise the build may fail because the file is locked.

If the build fails, refer to :doc:`troubleshooting` for a list of known
issues and possible solutions.


6. Using the Created DLL File
---------------------------------

After a successful build, three output files are produced in the build folder:

``<ModelName>.dll``
    The compiled shared library itself, exporting the functions declared in ``ext_simenv_capi.h`` (``Model_GetInfo``, 
    ``Model_Instance``, ``Model_Outputs``, ``Model_Update``, ``Model_Derivatives``, ``Model_Terminate``, etc.).

``<ModelName>.lib``
    The import library generated alongside the DLL, used by a calling application to resolve the exported symbols at link time.

``<ModelName>.exp``
    The export file produced as a by-product of the linking process, required internally to build the ``.lib`` file.

Together, these three files package the Simulink model — with all of its tunable parameters, its in-/outport interface, and its
metadata — into a self-contained binary that no longer requires MATLAB/Simulink to execute.

Since the resulting binary conforms to the standardized ``ext_simenv_capi.h`` interface, it can be loaded, without modification,
as a custom model into several power system simulation tools, for example:

- **PSS®NETOMAC** — for time-domain and RMS simulation of a converter controller within a larger grid model.
- **DIgSILENT PowerFactory** — as a custom DSL/DLL model representing the IBR controller, e.g. for compliance studies against IEC 61400-27.
- **PSCAD™** — as an external DLL component within an EMT simulation case.

.. important::

   The three files ``.dll``, ``.lib``, and ``.exp`` must be kept together and distributed as a set. The ``.lib``/``.exp`` files alone 
   are not executable, and the ``.dll`` alone may be insufficient if the target environment expects static linking against the import 
   library.
