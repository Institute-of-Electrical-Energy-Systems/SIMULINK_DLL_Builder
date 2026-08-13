General Workflow
=================

The IEC 61400-27 DLL Builder converts a Simulink-based inverter/converter
control model into a standardized, self-contained DLL that can be used as
an external model in power system simulation tools such as NETOMAC,
DIgSILENT PowerFactory, or PSCAD.

The complete process consists of six consecutive steps, which build on one
another and are described in detail in the corresponding chapters of this
documentation.

.. figure:: _images/iec61400_27_builder_workflow.png
   :alt: Overview of the six-step workflow

   Overview of the six-step workflow of the IEC 61400-27 Builder.

.. note::

   The six steps are intended to be executed in the given order. Skipping
   a step, or executing steps out of order, is a common source of build
   errors later in the process (see :doc:`troubleshooting` for a list of
   known issues).

The six steps are:

#. Preparing the working directory
#. Building a control model
#. Adjusting the control model structure for the export process
#. Preparing the Simulink Coder
#. Starting the creation process
#. Using the created DLL file


1. Preparing the Working Directory
-----------------------------------

Before any modelling work can begin, a correctly structured working
directory must be set up. The working directory is the folder from which
the Simulink model is opened and in which the code generator later
searches for the System Target File, the Target Language Compiler (TLC)
files, and all supporting header and source files.

The recommended and simplest way to obtain the complete working directory
is by cloning the project repository. This ensures that all required
files are available in the correct folder structure and that the latest
revisions are used.

.. code-block:: console

    git clone <repository-url>


The following files and folders must be present in (or copied into) the
working directory:

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
| `sfun_info.mexw64`                | Compiled S-Function that triggers `sfun_info.tlc` during code generation. The TLC file generates the additional C source     |
|                                   | required for the controller DLL.                                                                                             |
+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------+


.. note::

   Working with a copy of the template model, rather than the original
   template itself, is strongly recommended. This avoids accidentally
   overwriting the empty reference model that other projects may still
   depend on.

Once the directory is prepared, it should contain everything required by
the subsequent steps without any additional files needing to be added
manually — with the exception of the actual controller design and its
parameter script, which are created in step 2.


2. Building a Control Model
------------------------------

In this step, the actual control logic is designed — or an existing
controller (e.g. the IBR control) is extended or modified — inside
Simulink.

This step typically comprises two parallel activities:

Designing the Control Logic
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The controller (e.g. active/reactive power control, current control,
PLL, and associated filters) is implemented as a standard Simulink model,
using the block libraries and modelling conventions established for the
project.

Creating the Parameter Script
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In parallel to the model itself, a MATLAB parameterization script (for
example ``IBR_Control_Parameters.m``) is created or adapted. This script
is responsible for:

- defining the electrical system (converter rating, filter impedance,
  setpoints, grid strength, etc.),
- performing the steady-state load-flow calculation to determine the
  operating point,
- computing consistent initial conditions for all controller states, and
- calculating the controller gains and time constants for the selected
  simulation step size.

All controller parameters that are intended to be configurable in the generated DLL must be defined as `Simulink.Parameter <https://de.mathworks.com/help/simulink/slref/simulink.parameter.html>`_ objects rather than ordinary MATLAB variables.
In addition to the parameter value, the following metadata can be assigned to each parameter: 

- minimum value, 
- maximum value, 
- engineering unit, and 
- description. 

During the DLL build process, this metadata is automatically extracted and exported together with the parameter definitions. 
It is therefore available to applications that interface with the generated controller DLL. 

.. seealso:: 
    
    A complete, worked example of such a parameter script is given in :ref:`example-usage`, using ``IBR_Control_Parameters.m`` as a reference implementation. 
    
At the end of this step, the result is a functionally correct, simulatable Simulink model together with a consistent and complete parameter set in the MATLAB base workspace. 
At this point, the model is **not yet** prepared for DLL export—this is the purpose of step 3.


3. Adjusting the Control Model Structure for the Export Process
-------------------------------------------------------------------

A control model that simulates correctly in Simulink is not automatically
ready to be exported as a DLL. Before code generation can be started, the
model structure must be adapted so that the code generator and the
metadata extraction process can interpret it correctly.

This step consists of three sub-tasks:

Adding the Model Information Module
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

A dedicated, unconnected information block (``sfun_info``) is placed at
the top level of the model. It carries human-readable metadata—model
version, author, last-modified date, and a short description—directly
inside the block diagram, independent of the metadata later embedded in
the generated DLL itself. Since the block has no input or output ports,
it has no effect on simulation behaviour.

To add the block, open model_info.mdl from the working directory and
copy the sfun_info block into the top level of the controller model.

Converting Tunable Parameters to Simulink.Parameter Objects
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Only variables of type `Simulink.Parameter <https://de.mathworks.com/help/simulink/slref/simulink.parameter.html>`_ in the base workspace are
recognized by the metadata extraction of the IEC 61400-27 DLL Builder.
All parameters that should be tunable from the external simulation
environment must therefore be converted from ordinary MATLAB variables
into `Simulink.Parameter <https://de.mathworks.com/help/simulink/slref/simulink.parameter.html>`_ objects, typically at the end of the
parameter script created in step 2.

Defining the Top-Level In-/Outports
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The generated DLL communicates with the external simulation environment
exclusively through the fixed C API declared in ``ext_simenv_capi.h``.
Consequently, every signal that must be accessible externally has to be
exposed as a top-level ``Inport`` or ``Outport`` block:

- Signals buried inside subsystems are **not** picked up by the code
  generator.
- Port names become the ``Name`` field returned by ``Model_GetInfo()``
  and should therefore be descriptive and stable.
- Port ordering determines the layout of the flat ``ExtU``/``ExtY``
  vectors in the generated code and must be agreed upon with the target
  simulation environment.
- All port data types should be kept as ``double`` to match the
  ``real64_T`` pointers used by the C API.

.. note::

   These three sub-tasks are typically performed once per model and only
   need to be repeated when the controller's parameter set or its
   external interface (inputs/outputs) changes.


4. Preparing the Simulink Coder
-----------------------------------

Once the model structure has been finalized, the Simulink Coder App is
opened from the Simulink toolbar in order to configure the code
generation process.

.. figure:: _images/SimulinkCoder.png
   :alt: Opening the Simulink Coder App

   Opening the Simulink Coder App.

The key configuration step is verifying the **System Target File**
selected under *Settings → Code Generation*:

.. figure:: _images/SimulinkCoderSettings.png
   :alt: Simulink Coder settings dialog

   Opening the Simulink Coder settings.

.. figure:: _images/SimulinkCoderSettingsCodeGeneration.png
   :alt: Code Generation tab

   Selecting the Code Generation tab.

The System Target File must be set to ``IEC61400_27_DLL.tlc``, which must
be available in the working directory prepared in step 1. If a different
target file is selected, it must be changed accordingly before
proceeding — otherwise the build will not produce a DLL compatible with
the IEC 61400-27 external model interface.

Selecting this system target file adds a new menu item, ``Simulink DLL Builder``, to the Simulink menu bar. 
Clicking this menu item opens the metadata dialog, which is pre-populated with the default values of the example. 
These values must be reviewed and adjusted as required for the specific model.

.. figure:: _images/SimulinkCoderSettingsMetaData.png
   :alt: Code Generation Simulink DLL Builder tab

   Filling the Model/DLL Metadata necessary for the DLL Code generation process.


5. Starting the Creation Process
------------------------------------

With the correct target file selected, the build process is started by
clicking **Build** in the Simulink Coder App.

.. figure:: _images/SimulinkCoderBuild.png
   :alt: Starting the code generation process

   Starting the code generation process.

Depending on the size of the model and the performance of the local
system, the build may take anywhere from a few seconds to several
minutes. During this process, the compiler and linker — configured via
``IEC61400_27_DLL.tmf`` — generate the C code from the model, compile it,
and link it into the final binary output.

.. note::

   If the corresponding DLL is currently in use by a DIgSILENT
   PowerFactory project (e.g. while updating a control model), ensure
   that the project is deactivated before starting the build process,
   otherwise the build may fail because the file is locked.

If the build fails, refer to :doc:`troubleshooting` for a list of known
issues and possible solutions.


6. Using the Created DLL File
---------------------------------

After a successful build, three output files are produced in the build
folder:

``<ModelName>.dll``
    The compiled shared library itself, exporting the functions declared
    in ``ext_simenv_capi.h`` (``Model_GetInfo``, ``Model_Instance``,
    ``Model_Outputs``, ``Model_Update``, ``Model_Derivatives``,
    ``Model_Terminate``, etc.).

``<ModelName>.lib``
    The import library generated alongside the DLL, used by a calling
    application to resolve the exported symbols at link time.

``<ModelName>.exp``
    The export file produced as a by-product of the linking process,
    required internally to build the ``.lib`` file.

Together, these three files package the Simulink control model — with
all of its tunable parameters, its in-/outport interface, and its
metadata — into a self-contained binary that no longer requires
MATLAB/Simulink to execute.

Since the resulting binary conforms to the standardized
``ext_simenv_capi.h`` interface, it can be loaded, without modification,
as a custom model into several power system simulation tools, for
example:

- **NETOMAC** — for time-domain and RMS simulation of the converter
  controller within a larger grid model.
- **DIgSILENT PowerFactory** — as a custom DSL/DLL model representing the
  IBR controller, e.g. for compliance studies against IEC 61400-27.
- **PSCAD** — as an external DLL component within an EMT simulation case.

.. important::

   The three files ``.dll``, ``.lib``, and ``.exp`` must be kept together
   and distributed as a set. The ``.lib``/``.exp`` files alone are not
   executable, and the ``.dll`` alone may be insufficient if the target
   environment expects static linking against the import library.

This concludes the general workflow. 

