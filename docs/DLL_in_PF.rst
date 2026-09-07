######################
DIgSILENT PowerFactory
######################

This chapter describes the step-by-step integration of an IEC 61400-27 DLL into DIgSILENT PowerFactory. 
It first introduces the required software and prerequisites, followed by the setup of the example grid model. 
The subsequent sections describe how to integrate the DLL and establish the required signal connections. 
The model is built from an empty DIgSILENT PowerFactory project.


Prerequisites
-------------
- DIgSILENT PowerFactory (tested for 2024 SP4)
- IEC 61400-27 DLL (e.g. the one from the `example <https://simulink-dll-builder.readthedocs.io/en/latest/example_usage.html#example-usage>`_)

Building a model for later DLL integration from scratch 
-------------------------------------------------------
The final model consists of a regulated ideal voltage source and an internal resistance connected at the point of common coupling (PCC). 
The PCC is supplied by a Thevenin equivalent representing the upstream grid. 
The individual components are added and configured step by step, starting from the blank DIgSILENT PowerFactory project.

1. Building a thevenin equivalent
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
..  figure:: ./images/PowerFactory/TheveninPowerFactory.png
    :alt: Thevenin equivalent connect to PCC in DIgSILENT PowerFactory.
    :target: _images/TheveninPowerFactory.png

    Figure 1: Thevenin equivalent connect to PCC in DIgSILENT PowerFactory.

By definition, a Thevenin equivalent consists of an ideal voltage source and a series-connected internal impedance. 
In this model, the ideal voltage source applies a voltage of 1 p.u. to the bus at its terminal (“InnerThevenin”). 
For the example considered here, this corresponds to a line-to-line RMS voltage of 400 kV with a phase angle of 0°.
The internal impedance determines the short-circuit power, and therefore the strength, of the upstream grid. 
In the present example, the impedance is defined by a resistance of R = 10.6137 Ω and an inductance of L = 0.3378455 H.

A simulation can already be performed using these two components.
However, the simulation is of limited significance at this stage, as the Thevenin equivalent only provides the voltage supply at the PCC and no connected equipment or grid interaction is yet represented.


2. Building the external controlled voltage source (Grid following IBR)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
..  figure:: ./images/PowerFactory/SMIB_IBR_PowerFactory.png
    :alt: IBR in a SMIB configuraiton in DIgSILENT PowerFactory.
    :width: 50%
    :target: _images/SMIB_IBR_PowerFactory.png

    Figure 2: IBR in a SMIB configuraiton in DIgSILENT PowerFactory.

The regulated ideal voltage source is now connected to the PCC through a series impedance, thereby forming the equivalent circuit of a grid-following IBR. 
The voltage source will subsequently be controlled by the dynamic model provided by the IEC 61400-27 DLL.
In the present example, the DLL provides a line-to-line RMS voltage of 400 kV. 
Therefore, no additional transformer is required, and only the internal impedance of the IBR needs to be represented. 
The impedance is defined by a resistance of R = 0.782 Ω and an inductance of L = 0.1574 H.

At this stage, two ideal voltage sources with identical voltage setpoints are connected through their respective series impedances. 
As the voltage sources have the same voltage, no current flows between them. The control of the IBR voltage source will be addressed in a subsequent step. 
Nevertheless, a simulation can already be performed to verify the correct operation of the model.


3. Adding the required measurements for the DLL
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The next step is to add the measurements required by the DLL. 
The relevant electrical quantities at the PCC are the three phase-to-ground voltages and the three phase currents. 
These quantities are measured using voltage and current transformers and are subsequently provided to the DLL as input signals.


Adding the voltage transformer
''''''''''''''''''''''''''''''
The voltage transformer is used to measure the three phase-to-ground voltages at the PCC and provide them as input signals to the IEC 61400-27 DLL. 
An ideal voltage transformer is used for this purpose, as no transformer losses or other transformer-specific effects need to be considered in the present example.
To add the voltage transformer, select the PCC busbar (see Figure 3) and create a new object using the New Object button in the upper-left corner of the window. 
Select Voltage Transformer from the list of available components (see Figure 4).

.. container:: image-row

   ..  figure:: ./images/PowerFactory/PCCPowerFactory.png
         :alt: Choice of the PCC busbar in the DIgSILENT PowerFactory model menu.
         :target: _images/PCCPowerFactory.png

         Figure 3: Choice of the PCC busbar in the DIgSILENT PowerFactory model menu.
         
   ..  figure:: ./images/PowerFactory/VT_PowerFactory.png
         :alt: Adding a new voltage transformer to the PCC busbar in DIgSILENT PowerFactory.
         :target: _images/VT_PowerFactory.png

         Figure 4: Adding a new voltage transformer to the PCC busbar in DIgSILENT PowerFactory.

After creating the voltage transformer, open its configuration by double-clicking the component. Assign a suitable name to the new component and create a new transformer type (see Figure 5).
Select Ideal Voltage Transformer in the upcoming Voltage Transformer Type menu (see Figure 6). 
The ideal transformer is sufficient for the present application because the purpose of the component is to provide the required voltage measurements rather than to model the physical behavior of a transformer.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/VT_PowerFactory2.png
      :alt: Pop-up window of the new generated voltage transformer at the PCC busbar in DIgSILENT PowerFactory.
      :target: _images/VT_PowerFactory2.png

      Figure 5: Pop-up window of the new generated voltage transformer at the PCC busbar in DIgSILENT PowerFactory.

   .. figure:: ./images/PowerFactory/VT_PowerFactory4.png
      :alt: Pop-up window for the definition of a voltage transformer type.
      :target: _images/VT_PowerFactory4.png

      Figure 6: Pop-up window for the definition of a voltage transformer type.

The voltage transformer is now connected to the PCC and can be used to obtain the three phase-to-ground voltage signals required by the DLL. 
To record the measured variables, right-click on the voltage transformer in the Data Manager. Then, select ``Simulation RMS/EMT`` from the ``Result Variables`` menu (see Figure 7). 
The voltage transformer will subsequently appear in the ``Variable Selection`` list (see Figure 8). 
The measured variables **U2r_A**, **U2r_B**, and **U2r_C** can then be selected for recording (see Figure 9).


.. container:: image-row

   ..  figure:: ./images/PowerFactory/VT_PowerFactory5.png
         :alt: Pop-up window after right-clicking the new voltage transformer.
         :target: _images/VT_PowerFactory5.png

         Figure 7: Pop-up window after right-clicking the new voltage transformer.

   ..  figure:: ./images/PowerFactory/VT_PowerFactory7.png
         :alt: Opening the voltage transformer result variable window by double-clicking.
         :target: _images/VT_PowerFactory7.png

         Figure 8: Opening the voltage transformer result variable window by double-clicking.

   ..  figure:: ./images/PowerFactory/VT_PowerFactory8.png
         :alt: Adding the necessary voltage measurements to the result log.
         :target: _images/VT_PowerFactory8.png

         Figure 9: Adding the necessary voltage measurements to the result log.


Adding the current transformer
''''''''''''''''''''''''''''''
The current transformer is used to measure the three phase currents at the PCC and provide them as input signals to the IEC 61400-27 DLL. 
An ideal current transformer is used for this purpose, as no transformer losses or other transformer-specific effects need to be considered in the present example.

To add the current transformer, select the cubicle of the PCC busbar connected to the thevenin impedance (see Figure 10) and create a new object using the New Object button in the upper-left corner of the window. 
Select Current Transformer from the list of available components (see Figure 11). 

.. container:: image-row

   ..  figure:: ./images/PowerFactory/PCC_Cub1_PowerFactory.png
         :alt: Choice of the cubicle of the PCC busbar connected to the thevenin impedance in the DIgSILENT PowerFactory model menu.
         :target: _images/PCC_Cub1_PowerFactory.png

         Figure 10: Choice of the cubicle of the PCC busbar connected to the thevenin impedance in the DIgSILENT PowerFactory model menu.

   ..  figure:: ./images/PowerFactory/CT_PowerFactory.png
         :alt: Adding a new current transformer to the cubicle of the PCC busbar connected to the thevenin impedance in DIgSILENT PowerFactory.
         :target: _images/CT_PowerFactory.png

         Figure 11: Adding a new current transformer to the cubicle of the PCC busbar connected to the thevenin impedance in DIgSILENT PowerFactory.

After creating the current transformer, open its configuration by double-clicking the component. Assign a suitable name to the new component, create a new transformer type and select Current Transformer Type (TypCt) (see Figure 12).
Within the new upcoming Current Transformer Type menu select Ideal Current Transformer (see Figure 13). 
The ideal transformer is sufficient for the present application because the purpose of the component is to provide the required current measurements rather than to model the physical behavior of a transformer.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CT_PowerFactory2.png
         :alt: Pop-up window of the new generated current transformer at cubicle of the PCC busbar connected to the thevenin impedance in DIgSILENT PowerFactory.
         :target: _images/CT_PowerFactory2.png

         Figure 12: Pop-up window of the new generated current transformer at cubicle of the PCC busbar connected to the thevenin impedance in DIgSILENT PowerFactory.

   .. figure:: ./images/PowerFactory/CT_PowerFactory4.png
         :alt: Pop-up window for the definition of a current transformer type.
         :target: _images/CT_PowerFactory4.png

         Figure 13: Pop-up window for the definition of a current transformer type.

The current transformer is now connected to the cubicle of the PCC and can be used to obtain the three phase current signals required by the DLL.
To record the measured variables, right-click on the current transformer in the Data Manager. Then, select ``Simulation RMS/EMT`` from the ``Result Variables`` menu (see Figure 14). 
The current transformer will subsequently appear in the ``Variable Selection`` list (see Figure 15). 
The measured variables **I2r_A**, **I2r_B**, and **I2r_C** can then be selected for recording (see Figure 16).

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CT_PowerFactory5.png
         :alt: Pop-up window after right-clicking the new current transformer.
         :target: _images/CT_PowerFactory5.png

         Figure 14: Pop-up window after right-clicking the new current transformer.


   ..  figure:: ./images/PowerFactory/CT_PowerFactory6.png
         :alt: Opening the current transformer result variable window by double-clicking.
         :target: _images/CT_PowerFactory6.png

         Figure 15: Opening the current transformer result variable window by double-clicking.


   ..  figure:: ./images/PowerFactory/CT_PowerFactory7.png
         :alt: Adding the necessary current measurements to the result log.
         :target: _images/CT_PowerFactory7.png

         Figure 16: Adding the necessary current measurements to the result log.

DLL integration using a dynamic model in DIgSILENT PowerFactory
---------------------------------------------------------------
After setting up the electrical components of the grid model along with the required voltage and current measurements at the PCC, the next step is to integrate the DLL itself into the model. 
This integration is performed via a so-called Composite Model Frame, which defines the signal connections between the measured quantities, the DLL, and the controlled voltage source.

1. Creating an empty composite model frame definition
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
First, a new, empty Composite Model Frame is created (see Figure 17). 
In the corresponding input window, the name and basic settings of the frame are defined (see Figure 18). 
The graphical editing interface of the still-empty frame then opens, in which the individual slots (blocks) and their signal connections are defined in the subsequent steps (see Figure 19).

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame.png
         :alt: Creating a new empty composite model frame.
         :target: _images/CompositeModelFrame.png

         Figure 17: Creating a new empty composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame1.png
         :alt: Input mask of the composite model frame definition.
         :target: _images/CompositeModelFrame1.png

         Figure 18: Input mask of the composite model frame definition.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame2.png
         :alt: Empty composite model frame defintion.
         :target: _images/CompositeModelFrame2.png

         Figure 19: Empty composite model frame defintion.


2. Adding measurment slots to the composite model frame definition
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The first slots to be created are those for the measured quantities. 
A slot for the voltage transformer is created to feed the three phase-to-ground voltages at the PCC into the frame (see Figure 20). 
Similarly, a slot for the current transformer is added, through which the three phase currents are provided (see Figure 21). 
Figure 22 shows the frame after both measurement slots have been added.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame3.png
         :alt: Creating a voltage transformer slot in the composite model frame.
         :target: _images/CompositeModelFrame3.png

         Figure 20: Creating a voltage transformer slot in the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame4.png
         :alt: Creating a current transformer slot in the composite model frame.
         :target: _images/CompositeModelFrame4.png

         Figure 21: Creating a current transformer slot in the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame5.png
         :alt: Composite model frame containing the measurement slots for three phase voltage and current.
         :target: _images/CompositeModelFrame5.png

         Figure 22: Composite model frame containing the measurement slots for three phase voltage and current.

3. Adding the DLL as compiled model to the composite model frame definition
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Next, a slot for the DLL itself is created (see Figure 23). 
The previously compiled IEC 61400-27 DLL is loaded into this slot as a Compiled Model (see Figure 24). 
Figure 25 shows the frame with the integrated DLL slot, whose inputs and outputs are now available for further signal wiring.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame6.png
         :alt: Creating a DLL slot in the composite model frame.
         :target: _images/CompositeModelFrame6.png

         Figure 23: Creating a DLL slot in the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame7.png
         :alt: Imported DLL as compiled model in the DLL slot of the composite model frame.
         :target: _images/CompositeModelFrame7.png

         Figure 24: Imported DLL as compiled model in the DLL slot of the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame8.png
         :alt: Composite model frame containing the DLL slot.
         :target: _images/CompositeModelFrame8.png

         Figure 25: Composite model frame containing the DLL slot.

.. attention:: 

   Within this step, the path to the DLL file is entered. Make sure that the specified path is correct and corresponds to the location of the DLL file.


4. Convert the DLL outputs to the DIgSILENT PowerFactory required units
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Since the output quantities of the DLL do not directly match the unit required by the controlled voltage source (kilovolts), in DIgSILENT PowerFactory, an additional conversion slot is inserted and a new project DSL Model Tyoe is defined (see Figure 26). 
This definition contains the corresponding conversion equations, which transform the DLL output signals into the format required by the voltage source (see Figure 27). 
Figure 28 shows the frame after the conversion slot has been added.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame9.png
         :alt: Creating a conversion slot in the composite model frame.
         :target: _images/CompositeModelFrame9.png

         Figure 26: Creating a conversion slot in the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame10.png
         :alt: Equations of the conversion slot in the composite model frame.
         :target: _images/CompositeModelFrame10.png

         Figure 27: Equations of the conversion slot in the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame11.png
         :alt: Composite model frame containing the conversion slot.
         :target: _images/CompositeModelFrame11.png

         Figure 28: Composite model frame containing the conversion slot.

5. Adding the voltage source input slot and wiring of the slots
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Finally, a slot for the regulated ideal voltage source is created, which was previously introduced as part of the IBR equivalent circuit (see Figure 29). 
Figure 30 shows the complete frame containing all five slots: voltage measurement, current measurement, DLL, output concersion and controlled voltage source.
In the last step, the inputs and outputs of the individual slots are connected to one another: the measured voltages and currents are fed into the DLL slot as input signals, 
the DLL's output quantities are converted into the required format via the conversion slot, and the result is then passed to the controlled voltage source as its setpoint. 
Figure 31 shows the fully wired Composite Model Frame. 
This completes the integration of the DLL into the DIgSILENT PowerFactory model, and simulations with dynamic behavior according to IEC 61400-27 can now be carried out.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame12.png
         :alt: Creating a voltage source slot in the composite model frame.
         :target: _images/CompositeModelFrame12.png

         Figure 29: Creating a voltage source slot in the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame13.png
         :alt: Composite model frame containing the voltage source slot.
         :target: _images/CompositeModelFrame13.png

         Figure 30: Composite model frame containing the voltage source slot.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame14.png
         :alt: Composite model frame containing the signal connection of the slots.
         :target: _images/CompositeModelFrame14.png

         Figure 31: Composite model frame containing the signal connection of the slots.

Up to this point, only the required block definitions have been created. 
These definitions do not affect the simulation results until they are instantiated and integrated into the network topology. 
The next step is therefore to integrate the created components into the simulation model.

6. Creating the two DSL Models required by the Composite Model Frame
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
To begin integrating the previously defined blocks, the required DSL models must first be created. Open the network associated with the current project in the ``Data Manager`` (see Figure 32) and create a new object. 
In the ``Add New Object`` dialog, select ``DSL Model`` (see Figure 33). 
This starts the process of creating the DSL components required for the subsequent integration of the previously defined blocks.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame15.png
         :alt: Navigating to the grid topology of the considered DIgSILENT PowerFactory model.
         :target: _images/CompositeModelFrame15.png

         Figure 32: Navigating to the grid topology of the considered DIgSILENT PowerFactory model.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame16.png
         :alt: Adding a new DSL model to the model.
         :target: _images/CompositeModelFrame16.png

         Figure 33: Adding a new DSL model to the model.

7. Filling the two DSL Model required by the composite model Frame
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The next step is to fill the two DSL models required by the composite model frame created previously. 
The first DSL model is used to convert voltage values from volts to kilovolts (see Figure 34). 
The second DSL model is an instance of the DLL interface, which is responsible for handling the communication between DIgSILENT PowerFactory and the IEC 61400-27 DLL (see Figure 35).

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame17.png
         :alt: Conversion DSL model of the composite model frame.
         :target: _images/CompositeModelFrame17.png

         Figure 34: Conversion DSL model of the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame18.png
         :alt: DLL interface DSL model of the composite model frame.
         :target: _images/CompositeModelFrame18.png

         Figure 35: DLL interface DSL model of the composite model frame.

8. Adding the IBR Control composite model frame as network component
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Finally, a ``Composite Model`` object is created in the project network (see Figure 36). 
This object is configured using the previously created composite model frame, ``IBR_Control``. 
The required measurement points, DSL models, and controlled voltage source are then assigned to the Composite Model object through its user interface (see Figure 37).

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame19.png
         :alt: Adding a new composite model to the model.
         :target: _images/CompositeModelFrame19.png

         Figure 36: Adding a new composite model to the model.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame20.png
         :alt: Filling the composite model.
         :target: _images/CompositeModelFrame20.png

         Figure 37: Filling the composite model.

With this configuration, the IEC 61400-27 DLL is fully integrated into the DIgSILENT PowerFactory simulation environment. 
The DLL can process the measured electrical quantities during the simulation, while its calculated output signals are fed back into the EMT model through the configured composite model. 
This enables the dynamic behavior implemented in the DLL to directly influence the EMT simulation performed in DIgSILENT PowerFactory.

Initialization of a DLL in DIgSILENT PowerFactory
-------------------------------------------------
EMT simulations of electrical power systems are commonly used to investigate system stability and to validate protection concepts. 
It is important to note that such simulations are not initiated from an unknown initial state. 
Instead, the initial operating condition can generally be determined or approximated based on the specified operating point of the system.

During the development of the IEC 61400-27 Builder, the dynamic behavior of the DLL within the DIgSILENT PowerFactory simulation environment was investigated in detail. 
Based on these investigations, several measures were derived to achieve an initialization that is as accurate as possible. 
The objective is to ensure that the DLL starts from an operating point consistent with the surrounding DIgSILENT PowerFactory model, thereby minimizing the need for subsequent balancing operations.

The initialization measures developed for this purpose are described in more detail in the following sections.

1. Loadflow conditions (Sample 0)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
First, the network topology is analyzed with respect to the power flow, as this provides the basis for determining the initial conditions and, consequently, for the subsequent dynamic simulation. 
Without any modifications to the network topology, the voltage magnitude and phase angle at every bus of the investigated topology remains 1 p.u. and 0°. Due to the fact of zero current (see Figure 38).

The objective, however, is to ensure that the IBR supplies the specified active and reactive power from the beginning of the simulation, with only minor power deviations requiring subsequent balancing. 
To achieve this, the voltage magnitude and phase angle at the IBR terminals must first be determined. 
These values are then entered into the load-flow settings of the AC voltage source (see Figure 39). 

By specifying the corresponding voltage magnitude and phase angle, the desired power flow can be established at the PCC (see Figure 40).
In the example considered, the target operating point at the PCC is P = 500 MW and Q = 100 MVAr. 
This ensures that the initial operating condition of the IBR is consistent with the intended power-flow conditions before the EMT simulation is started.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/Loadflow_wo_adaptions.png
         :alt: Calculation of unbalance power flow without adpating the IBR voltage source conditions.
         :target: _images/Loadflow_wo_adaptions.png

         Figure 38: Calculation of unbalance power flow without adpating the IBR voltage source conditions.

   ..  figure:: ./images/PowerFactory/IBR_voltage_source_LF.png
         :alt: Filling the load flow conditions (voltage magnitude and angle) in the IBR voltage source.
         :target: _images/IBR_voltage_source_LF.png

         Figure 39: Filling the load flow conditions (voltage magnitude and angle) in the IBR voltage source.

   ..  figure:: ./images/PowerFactory/Loadflow_after_adaptions.png
         :alt: Calculation of unbalance power flow after adpating the IBR voltage source conditions.
         :target: _images/Loadflow_after_adaptions.png

         Figure 40: Calculation of unbalance power flow after adpating the IBR voltage source conditions.

2. Start of the dynamic simulation using a DLL (Sample 1 & 2)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Due to the order in which the differential equations of the network topology and the dynamic models, such as the DLL, are solved, the DLL output values deviate from the expected voltage values during the first two samples of the simulation. 
The first sample represents the result of the initialization process. 
At this point, the input values have already been assigned, while the corresponding output values have not yet been calculated. 
This can be regarded as a zero sample. 
In the second sample, these initially calculated zero values are propagated to the subsequent simulation step, resulting in an undesired deviation from the expected voltage.

To overcome this initialization effect, a workaround is implemented in which the output values of an ideal symmetrical AC voltage source, corresponding to the values determined
 during the load-flow calculation, are applied directly to the controlled IBR voltage source during the first two samples of the dynamic simulation.

To implement this workaround, the composite model frame (the block definition of ``IBR_Control``), must first be extended accordingly. 
The first step is to disconnect the signal path between the volt-to-kilovolt conversion block and the controlled voltage source (see Figure 41). 
Signal switches are then inserted at this point. 
These switches select either input ``yi1`` or input ``yi2``, depending on the value of the variable ``sw``. 
When ``sw`` changes from 0 to 1, the switch changes from ``yi1`` to ``yi2`` (see Figure 42).

The corresponding logic for selecting the signal based on the ``sw`` variable is shown in Figure 43. 
This switching mechanism allows the initialization values from the ideal AC voltage source to be applied during the first two simulation samples before the signal path is switched to the output of the DLL.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame21.png
         :alt: Cutting the signal between the conversion block and the controlled voltage source in the composite model frame.
         :target: _images/CompositeModelFrame21.png

         Figure 41: Cutting the signal between the conversion block and the controlled voltage source in the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame22.png
         :alt: Adding the signal switches for each phase to the composite model frame.
         :target: _images/CompositeModelFrame22.png

         Figure 42: Adding the signal switches for each phase to the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame23.png
         :alt: Logic of the signal switches in the composite model frame.
         :target: _images/CompositeModelFrame23.png

         Figure 43: Logic of the signal switches in the composite model frame. ``sw`` is the switch attribute, ``yi1`` and ``yi2`` are the two input signal streams while ``yo`` is the output signal stream.

Building an ideal three phase AC voltage signal with a user defined magnitude and angle
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
DIgSILENT PowerFactory does not provide a signal generator for sine and cosine functions with user-defined amplitude and phase angle. 
Therefore, the required signal generation is implemented directly within the composite model frame as a dedicated slot (see Figure 44).

The corresponding logic is shown in Figure 45 while the parameter and output labels are presented in Figure 46. 
It generates the three-phase sinusoidal signals with the specified amplitude and phase angle, with each phase shifted by 120° relative to the others. 

.. math::
   :name: three phase voltage sine wave

   U_\mathrm{LF,A} = \frac{(\sqrt(2) \cdot U_\mathrm{LF,RMS})}{\sqrt(3)} \cdot cos(\phi_\mathrm{LF} \cdot \frac{\pi}{180} + 2 \cdot \pi \cdot 50 \cdot t) \\
   U_\mathrm{LF,B} = \frac{(\sqrt(2) \cdot U_\mathrm{LF,RMS})}{\sqrt(3)} \cdot cos((\phi_\mathrm{LF}-120) \cdot \frac{\pi}{180} + 2 \cdot \pi \cdot 50 \cdot t) \\
   U_\mathrm{LF,C} = \frac{(\sqrt(2) \cdot U_\mathrm{LF,RMS})}{\sqrt(3)} \cdot cos((\phi_\mathrm{LF}-240) \cdot \frac{\pi}{180} + 2 \cdot \pi \cdot 50 \cdot t) \\

This provides the three-phase voltage signals required for the initialization of the controlled IBR voltage source.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame24.png
         :alt: Adding the user defined sine wave generator to the composite model frame.
         :target: _images/CompositeModelFrame24.png

         Figure 44: Adding the user defined sine wave generator to the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame25.png
         :alt: Logical/Mathematical definition of the sine wave generator of an ideal three phase AC voltage source.
         :target: _images/CompositeModelFrame25.png

         Figure 45: Logical/Mathematical definition of the sine wave generator of an ideal three phase AC voltage source.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame26.png
         :alt: Output/Parameter definition of the three phase voltage sine wave generator.
         :target: _images/CompositeModelFrame26.png

         Figure 46: Output/Parameter definition of the three phase voltage sine wave generator.

Switch signal generator 
'''''''''''''''''''''''
A signal generator is required to switch the initialization logic from the predefined voltage signal to the DLL output after a specified simulation time. 
The signal generator changes its state from 0 to 1 once the simulation time defined by the parameter ``Time_of_Switch`` has elapsed.

The signal generator is added to the composite model frame as shown in Figure 47. 
The corresponding switching logic is defined in Figure 48, while Figure 49 shows the configuration of the output signal and the `SwitchOperation` parameter. 
This parameter determines the duration for which the initialization signal is applied before the DLL-generated voltage signals are passed to the controlled IBR voltage source.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame27.png
         :alt: Adding the switch signal generator to the composite model frame.
         :target: _images/CompositeModelFrame27.png

         Figure 47: Adding the switch signal generator to the composite model frame.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame28.png
         :alt: Logical/Mathematical definition of the switch signal generator.
         :target: _images/CompositeModelFrame28.png

         Figure 48: Logical/Mathematical definition of the switch signal generator

   ..  figure:: ./images/PowerFactory/CompositeModelFrame26.png
         :alt: Output/Parameter definition of the switch signal generator.
         :target: _images/CompositeModelFrame29.png

         Figure 49: Output/Parameter definition of the switch signal generator.

3. Connecting the new created signals as well as the DLL output to the signal switches
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Finally, all newly added blocks and functions must be interconnected using the appropriate signal paths. 
The resulting structure is shown in Figure 50 and represents the final definition of the ``IBR_Control`` Composite Model Frame. 
This configuration combines the initialization logic, the signal generation, the switching mechanism, and the DLL-based control into a single composite model frame, providing the complete signal flow required for the subsequent EMT simulation.

..  figure:: ./images/PowerFactory/CompositeModelFrame30.png
      :alt: Signal wiring in the composite model frame after adding the new slots.
      :target: _images/CompositeModelFrame30.png
      :height: 40vh

      Figure 50: Signal wiring in the composite model frame after adding the new slots.

4. Creating the DSL Models from the Block definitions and add them to the composite model
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
To use the newly designed functionality, five additional DSL models must first be created, following the same procedure used for the original functionality (see Figure 51). 
These models include three DSL models implementing the signal-switching logic, one for each phase, as well as two DSL models for the signal generators.

The signal-switch DSL models do not require any additional parameters, as their operation is fully defined by the switching logic. 
In contrast, the two signal-generator models require parameter inputs to define their respective behavior. The corresponding parameter input dialogs are shown in Figures 52 and 53.

.. container:: image-row

   ..  figure:: ./images/PowerFactory/CompositeModelFrame31.png
         :alt: Adding five DSL Models to the investigated network model.
         :target: _images/CompositeModelFrame31.png

         Figure 51: Adding five DSL Models to the investigated network model.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame32.png
         :alt: Parameter input mask of the switching signal generator.
         :target: _images/CompositeModelFrame32.png

         Figure 52: Parameter input mask of the switching signal generator.

   ..  figure:: ./images/PowerFactory/CompositeModelFrame33.png
         :alt: Parameter input mask of the three phase sine wave signal generator.
         :target: _images/CompositeModelFrame33.png

         Figure 53: Parameter input mask of the three phase sine wave signal generator.

The final step is to integrate the newly created DSL models into the ``IBR_Control`` composite model (see Figure 54). 
This completes the initialization setup in DIgSILENT PowerFactory and ensures that the required switching and signal-generation functions are incorporated into the overall model.

The remaining configuration is performed within the control parameters of the Simulink model implemented in the IEC 61400-27 DLL. 
In particular, the parameters related to phase correction and the freeze functionality must be configured accordingly. 

..  figure:: ./images/PowerFactory/CompositeModelFrame34.png
      :alt: Adding the five DSL Model blocks to the IBR Control composite model.
      :target: _images/CompositeModelFrame34.png
      :height: 40vh

      Figure 54: Adding the five DSL Model blocks to the IBR Control composite model.

Adding a voltage dip event for the simulation benchmark
-------------------------------------------------------
To include a voltage dip simulation event which is used within the upcoming `benchmark <https://simulink-dll-builder.readthedocs.io/en/latest/Benchmark.html#>`_ one has to open the ``Edit Simulation Events`` menu (see Figure 57).
Therin one has to add a new ``Parameter Event`` by clicking ``New Object`` in the upper-left corner and ``Parameter Event`` afterwards (see Figure 58). 
In the new upcoming window (see Figure 59) the influenced element (the TheveninSource) as well as the timestamp of the events occation need to be defined. 
Finally the event creation is finished by clicking ``OK`` and ``Close``.

.. container:: image-row

    ..  figure:: ./images/PowerFactory/EditSimulationEvents.png
        :alt: Opening the ``Edit Simulation Events`` menu.
        :target: _images/EditSimulationEvents.png

        Figure 57: Opening the ``Edit Simulation Events`` menu.

    ..  figure:: ./images/PowerFactory/NewEvent.png
        :alt: Create a new Simulation Event.
        :target: _images/NewEvent.png

        Figure 58: Create a new Simulation Event.
    
    ..  figure:: ./images/PowerFactory/SetupVoltageDip.png
        :alt: Settings of the voltage dip event on the Thevenin Source.
        :target: _images/SetupVoltageDip.png

        Figure 59: Settings of the voltage dip event on the Thevenin Source.