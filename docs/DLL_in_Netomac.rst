##################
DLL in PSS®Netomac
##################

This chapter describes the step-by-step integration of an IEC 61400-27 DLL into PSS®NETOMAC. 
It first introduces the required software and prerequisites, followed by the setup of the example grid model. 
The subsequent sections describe how to integrate the DLL and establish the required signal connections. 
The model is created from an empty PSS®NETOMAC project.

Prerequisites
-------------
- PSS®NETOMAC (tested for version 22.0)
- IEC 61400-27 DLL (e.g. the one from the `example <FEHLT>`)

Building a model for later DLL integration from scratch 
-------------------------------------------------------
The final model consists of a regulated ideal voltage source and an internal resistance connected at the point of common coupling (PCC). 
The PCC is supplied by a Thevenin equivalent representing the upstream grid. 
The individual components are added and configured step by step, starting from the blank PSS®NETOMAC project.
For this example, the ``Sections`` template is used. 
The empty project file (.net) is shown below:

.. code-block:: netomac
   :linenos:

   $-------------------------------------------------------------------------------|
   ****                                                                            |
   $-------------------------------------------------------------------------------|
   $                                                                               |
   $-------------------------------------------------------------------------------|
   [[Feeder]]                                                                      |
   $-------------------------------------------------------------------------------|
   $                                                                               |
   $-------------------------------------------------------------------------------|
   [[End Feeder]]                                                                  |
   $-------------------------------------------------------------------------------|
   [[Machines]]                                                                    |
   $-------------------------------------------------------------------------------|
   $                                                                               |
   $-------------------------------------------------------------------------------|
   [[End Machines]]                                                                |
   $-------------------------------------------------------------------------------|
   [[Network]]                                                                     |
   $-------------------------------------------------------------------------------|
   $                                                                               |
   $-------------------------------------------------------------------------------|
   [[End Network]]                                                                 |
   $-------------------------------------------------------------------------------|
   [[Models_during_Loadflow]]                                                      |
   $-------------------------------------------------------------------------------|
   $                                                                               |
   $-------------------------------------------------------------------------------|
   [[End Models_during_Loadflow]]                                                  |
   $-------------------------------------------------------------------------------|
   [[Models]]                                                                      |
   $-------------------------------------------------------------------------------|
   $                                                                               |
   $-------------------------------------------------------------------------------|
   [[End Models]]                                                                  |
   $-------------------------------------------------------------------------------|

1. Defining the Global Parameters
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Before defining the power system in the .net file, the global parameters are defined in the first section of the empty project. 
These global parameters can subsequently be used for the power system and the associated models.

The relevant power system parameters are defined ad global parameters. 
These include the nominal voltage, the converter impedance, and the impedance of the Thevenin equivalent.

A nominal voltage (#Vn) of 400 kV is used. 
The converter impedance is defined by a resistance (#Rc) of 0.7820 Ω and an inductance (#Lc) of 154.7 mH.
The impedance of the Thevenin equivalent is defined by a resistance (#Re) of 10.613730029 Ω and an inductance (#Le) of 337.845519749 mH.

The resulting part of the parameter section is shown below:

.. code-block:: netomac
   :linenos:

   $-------------------------------------------------------------------------------| Grid data  
   $                                                                               |
   @@ #Vn    = 400            ! Nominal voltage [kV]                               |
   $                                                                               |
   $-------------------------------------------------------------------------------| Converter model data  
   $                                                                               |
   @@ #Rc    = 0.7820         ! Converter resistance [Ohm]                         |
   @@ #Lc    = 154.7          ! Converter reactance [mH]                           | 
   $                                                                               |
   $-------------------------------------------------------------------------------| Thevenin equivalent data 
   $                                                                               |
   @@ #Re    =  10.613730029  ! Thevenin equivalent resistance [Ohm]               |
   @@ #Le    = 337.845519749  ! Thevenin equivalent reactane [mH]                  |
   $                                                                               |
   $-------------------------------------------------------------------------------| 

2. Defining the power system
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

..  figure:: 
    :alt: Defining the power system.

    Figure 4: Defining the power system.

The power system consists of a Thevenin equivalent and a controlled voltage source, as described above.

In PSS®NETOMAC, the power system is defined in the ``[[Network]]`` section. 
A voltage source is modeled by an ``R``-line with neglibily small resistance. 
The voltage source is subsequently defined for this branch using a ``Source`` model in the ``[[Models_during_Loadflow]`` section.
An impedance is modeled by an ``A``-line with the corresponding resistance in Ω and inductance in mH. 

For this power system, two ``R``-lines and two ``A``-lines are therefore required. 
One ``R``-line and one ``A``-line represent the Thevenin equivalent, using the parameters ``#Rc`` and ``#Lc``.
The second ``R``-line and one ``A``-line represent the converter and its impedance, using the parameters ``#Rc`` and ``#Lc``.

The impedances and nominal voltage are specified in the global parameters.

The resulting ``[[Network]]`` section is shown below:

.. code-block:: netomac
   :linenos:

   $-------------------------------------------------------------------------------| 
   [[Network]]                                                                     |
   $-------------------------------------------------------------------------------| 
   $ Voltage Sources                                                               |
   $-------------------------------------------------------------------------------|
   $ Node 1         ID        km    R'                      Vn                     |
   $-------------------------------------------------------------------------------|
   RBus1            VSrc     11     1e-6                    #Vn                    | Thevenin equivalent  
   RBus3            IBR      11     1e-6                    #Vn                    | IBR
   $-------------------------------------------------------------------------------| 
   $ Impedances                                                                    |
   $-------------------------------------------------------------------------------|
   $ Node 1 Node 2  ID        km    R'                L'    Vn                     |
   $-------------------------------------------------------------------------------|
   ABus2    Bus1    Z_Th      1     #Re               #Le   #Vn                    | Thevenin equivalent  
   ABus3    Bus2    Z_IBR     1.    #Rc               #Lc   #Vn                    | IBR
   $-------------------------------------------------------------------------------| 
   [[End Network]]                                                                 |
   $-------------------------------------------------------------------------------| 

3. Defining the Control Model for the Ideal Voltage Source
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The first model in the ``[[Models_during_Loadflow]]`` section is created.

The voltage source of the Thevenin equivalent is intended to operate as an ideal voltage source with a constant RMS voltage corresponding to the nominal voltage ``#Vn`` under steady-state conditions.
For the fault scenario, a voltage dip is implemented, allowing the RMS voltage to be reduced to, for example, 0.7 pu at a specified time and restored to the nominal voltage at another specified time.
The voltage source is modeled as a three-phase voltage source. 
For this purpose, a ``GNE-V`` control model is created.
The ``GNE-V`` model requires the voltage output to be specified as the real and imaginary parts of the voltage phasor.
The voltage phasor is represented in a rotating reference frame rotating at the nominal frequency. 
Therefore the output values are defined as constant signals in the rotating reference frame rather than as time-varying quantities. 

To create a new ``GNE-V`` control model, a new model file is created (see Figure 1). 
The model properties, such as ``Name``, ``Author`` and ``Description``, are then specified (see Figure 2).
With the ``Add model file to project`` option enabled, the model file is saved in the ``.\MAC`` subdirectory.
In the next step, the page settings for the model file are defined (see Figure 3).

..  figure:: .\images\NETOMAC\_01_Create_new_model_file.png"
    :alt: Creating a new empty model file

    Figure 1: Creating a new empty model file (.xmac).

..  figure:: .\images\NETOMAC\_02_Create_Ideal_Voltage_Source_xmac.png"
    :alt: Define settings of new empty model file

    Figure 2: Define settings of new empty model file (.xmac).

..  figure:: .\images\NETOMAC\_03_Define_Page_Size_Ideal_Voltage_Source_xmac.png"
    :alt: Define page settings of new empty model file

    Figure 3: Define page settings of new empty model file (.xmac).

Defining the Model Variables
""""""""""""""""""""""""""""""

Five variables are required to implement the described behavior of the ideal voltage source, including the fault condition.
The variables ``#Vreal`` and ``#Vimag`` represent the real and imaginary parts of the ideal voltage source under steady-state conditions. 
During the load-flow calculation, the ideal voltage source operates as a slack bus.
Therefore, the voltage magnitude and phase angle are defined by the voltage source.
Accordingly, the values ``#Vreal`` = 1.0 pu and ``#Vimag`` = 0.0 pu correspont to a voltage magnitude of 1.0 pu and a phase angle of 0° during the load-flow calculation.

For the fault condition, the parameter ``#Vdip`` specifies the voltage magnitude during the voltage dip.
The parameter ``#Tdip1`` specifies the time at which the voltage dip occurs, while ``#Tdip2`` specifies the time at which the voltage is restored to ist nominal value.

The model variables are shown in following table:

| Variables | Value  | Minimum | Maximum | Debug Value | Description                                     |
+========================================================================================================|
| #Vreal    | 1.0    | 0.0     | 1E6     | 1.0         | Real part of the ideal voltage source [pu]      |
+--------------------------------------------------------------------------------------------------------|
| #Vimag    | 0.0    | 0.0     | 1E6     | 0.0         | Imaginary part of the ideal voltage source [pu] |
+--------------------------------------------------------------------------------------------------------|
| #Vdip    | 0.7     | 0.0     | 1E6     | 0.7         | Voltage magnitude during the voltage dip [pu]   |
+--------------------------------------------------------------------------------------------------------|
| #Tdip1    | 0.1    | 0.0     | 1E6     | 0.1         | Time at which the voltage dip occurs [s]        |
+--------------------------------------------------------------------------------------------------------|
| #Tdip2    | 0.2    | 0.0     | 1E6     | 0.1         | Time at which the voltage is restored [s]       |
+--------------------------------------------------------------------------------------------------------|

By selecting ``Variables``, the parameters described above can be defined as new model variables (see Figure 4 and 5). 

..  figure:: .\images\NETOMAC\_04_Defining_Variables_in_xmac.png"
    :alt: Defining Variables in model files

    Figure 4: Defining Variables in model files (.xmac).

..  figure:: .\images\NETOMAC\_05_Defining_Variables_Ideal_Voltage_Source.png"
    :alt: Define variables for ideal voltage source model

    Figure 5: Define variables for ideal voltage source model (.xmac).

Defining the Inputs
""""""""""""""""""""""""""""""

The behavior of the model depends only on the defined model variables; therefore, no measurements from the grid are required. 
The model variables are defined as inputs to the models. 
By selecting ``Insert Input``, a ``Constant`` input block can be added (see Figure 6).
The ``Output`` name of the block is specified in the topology section (see Figure 7), while the corresponding variable is specified as the ``Constant Value`` in the ``Data`` section of the block (see Figure 8).
By creating one block for each variable, the model contains five input blocks (see Figure 9).

..  figure:: .\images\NETOMAC\_06_Defining_Constant_Input.png"
    :alt: Defining Constant Input in model files 

    Figure 6: Defining Constant Input in model files (.xmac).

..  figure:: .\images\NETOMAC\_07_Defining_Name_Constant_Input.png"
    :alt: Define signal name of Constant Input in model file

    Figure 7: Define signal name of Constant Input in model file (.xmac).

..  figure:: .\images\NETOMAC\_08_Defining_Variable_Constant_Input.png"
    :alt: Defining Variable in Constant Input in model files

    Figure 8: Defining Variable in Constant Input in model files  (.xmac).

..  figure:: .\images\NETOMAC\_09_Result_Inputs.png"
    :alt: Resulting Constant Inputs in ideal voltage source model

    Figure 9: Resulting Constant Inputs in ideal voltage source model (.xmac).

Defining the Fault Definition
""""""""""""""""""""""""""""""

The fault logic can be implemented using an IF statement in FORTRAN code. 
As described above, the voltage source operates with the output values of ``#Vreal`` and ``#Vimag`` outside the time intervall between ``#Tdip1`` and ``#Tdip2``. 
During the voltage dip, the voltage magnitude is set to the value specified by ``#Vstep``.

By selecting the ``FORTRAN`` block via ``Insert Special Block``, a user-defined IF statement can be implemented (see Figure 9). 
The implemented logic is shown below : 

.. code-block:: netomac
   :linenos:

   IF ((TIME.LT.Tdip1).OR.(TIME.GT.Tdip2)) THEN
    Vr = Vreal
    Vi = Vimag
   ELSE
    Vr = Vstep
    Vi = Vimag
   ENDIF

For the ``FORTRAN`` block, the output signal names ``Vr`` and ``Vi`` has to be defined (see Figure 10).
Figure 11 shows the resulting control model.

..  figure:: .\images\NETOMAC\_10_Insert_FORTRAN_Block.png"
    :alt: Define signal name of Constant Input in model file

    Figure 9: Define signal name of Constant Input in model file (.xmac).

..  figure:: .\images\NETOMAC\_11_Voltage_Dip_Logic.png"
    :alt: Defining Variable in Constant Input in model files

    Figure 10: Defining Variable in Constant Input in model files  (.xmac).

..  figure:: .\images\NETOMAC\_12_Result_Fault_Logic.png"
    :alt: Resulting Constant Inputs in ideal voltage source model

    Figure 11: Resulting Constant Inputs in ideal voltage source model (.xmac).

Defining the Output
""""""""""""""""""""""""""""""

The output block of the models defines the model type. 
As described above, the ``GNE-V`` output block is used.
By selecting ``Insert Output``, the ``GNE-V`` output block is created (see Figure 9).
In the topology section of the block, the ``Branch for applied voltage``, i.e., the ``R``-line created in the ``[[Network]]`` section, is specified (see Figure 13). 
In this example, the variable ``#NAME`` is used, which represents automatically the name of the model. 
Therefore, the model name must be identical to the corresponding branch name.
In the ``Data`` section the ``Integration type`` is set to ``During network iteration`` (see Figure 14).
Figure 15 shows the finalized model file for the ideal voltage source of the Thevenin equivalent.


..  figure:: .\images\NETOMAC\_17_Insert_GNE_V_Output.png"
    :alt: Define signal name of Constant Input in model file

    Figure 12: Define signal name of Constant Input in model file (.xmac).

..  figure:: .\images\NETOMAC\_18_GNE_V_Output_Topology.png"
    :alt: Defining Variable in Constant Input in model files

    Figure 13: Defining Variable in Constant Input in model files  (.xmac).

..  figure:: .\images\NETOMAC\_19_GNE_V_Output_Data.png"
    :alt: Resulting Constant Inputs in ideal voltage source model

    Figure 14: Resulting Constant Inputs in ideal voltage source model (.xmac).

..  figure:: .\images\NETOMAC\_20_GNE_V_Results.png"
    :alt: Resulting Constant Inputs in ideal voltage source model

    Figure 15: Resulting Constant Inputs in ideal voltage source model (.xmac).    

Integration of the model into the power system
""""""""""""""""""""""""""""""

To integrate the created model into the power system, the model must be added to the ``.net`` file in the ``[[Models_during_Loadflow]]`` section.
By right-clicking and selecting ``Insert Model``, the model can be added by specifying the path to the model file (see Figure 16).
PSS®NETOMAC automatically creates the variable list for the model.
The Parameter ``#NAME`` must be set to the same name as the branch of the voltage source, ``VSrc``.

..  figure:: .\images\NETOMAC\_17_Insert_GNE_V.png"
    :alt: Define signal name of Constant Input in model file

    Figure 16: Define signal name of Constant Input in model file (.xmac).

The resulting ``[[Models_during_Loadflow]]`` section with the integrated model is shown below:

.. code-block:: netomac
    :linenos:

   [[Models_during_Loadflow]]                                                      |
   $-------------------------------------------------------------------------------| 
   @ #NAME      = 'VSrc'                                                           |
   @ #Vreal     = 1.0                 ! Real part of ideal voltage source [pu]     |
   @ #Vimag     = 0.0                 ! Imaginary part of id. volt. source [pu]    |
   @ #Vstep     = 0.7                 ! Step of real part of id. volt. source [pu] |
   @ #Tstep     = 0.1                 ! Time of voltage step [pu]                  |
   #.\MAC\Ideal_Voltage_Source.xmac                                                |
   $-------------------------------------------------------------------------------| 
   [[End Models_during_Loadflow]]                                                  |

