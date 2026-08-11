#############################
DLL in DIgSILENT PowerFactory
#############################

This chapter describes the step-by-step integration of an IEC 61400-27 DLL into DIgSILENT PowerFactory. 
It first introduces the required software and prerequisites, followed by the setup of the example grid model. 
The subsequent sections describe how to integrate the DLL and establish the required signal connections. 
The model is built from an empty DIgSILENT PowerFactory project.


Prerequisites
-------------
- DIgSILENT PowerFactory (tested for 2024 SP4)
- IEC 61400-27 DLL (e.g. the one from the `example <FEHLT>`)

Building a model for later DLL integration from scratch 
-------------------------------------------------------
The final model consists of a regulated ideal voltage source and an internal resistance connected at the point of common coupling (PCC). 
The PCC is supplied by a Thevenin equivalent representing the upstream grid. 
The individual components are added and configured step by step, starting from the blank DIgSILENT PowerFactory project.

1. Building a thevenin equivalent
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
..  figure:: ./images/TheveninPowerFactory.png
    :alt: Thevenin equivalent connect to PCC in PowerFactory.

    Figure 1: Thevenin equivalent connect to PCC in PowerFactory.

By definition, a Thevenin equivalent consists of an ideal voltage source and a series-connected internal impedance. 
In this model, the ideal voltage source applies a voltage of 1 p.u. to the bus at its terminals (“InnerThevenin”). 
For the example considered here, this corresponds to a line-to-line RMS voltage of 400 kV with a phase angle of 0°.

The internal impedance determines the short-circuit power, and therefore the strength, of the upstream grid. 
In the present example, the impedance is defined by a resistance of R = 10.6137 Ω and an inductance of L = 0.3378455 H.

A simulation can already be performed using these two components.
However, the simulation is of limited significance at this stage, as the Thevenin equivalent only provides the voltage supply at the PCC and no connected equipment or grid interaction is yet represented.


2. Building the external controlled voltage source (Grid following IBR)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
..  figure:: ./images/SMIB_IBR_PowerFactory.png
    :alt: IBR in a SMIB configuraiton in DIgSILENT PowerFactory.

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
""""""""""""""""""""""""""""""
The voltage transformer is used to measure the three phase-to-ground voltages at the PCC and provide them as input signals to the IEC 61400-27 DLL. 
An ideal voltage transformer is used for this purpose, as no transformer losses or other transformer-specific effects need to be considered in the present example.

To add the voltage transformer, select the PCC busbar (see Figure 3) and create a new object using the New Object button in the upper-right corner of the window. 
Select Voltage Transformer from the list of available components (see Figure 4) and assign a suitable name to the new component (see Figure 5).

.. grid:: 3

   .. grid-item::

      ..  figure:: ./images/PCCPowerFactory.png
            :alt: Choice of the PCC busbar in the PowerFactory model menu.

            Figure 3: Choice of the PCC busbar in the PowerFactory model menu.

   .. grid-item::

       ..  figure:: ./images/VT_PowerFactory.png
            :alt: Adding a new voltage transformer to the PCC busbar in PowerFactory.

            Figure 4: Adding a new voltage transformer to the PCC busbar in PowerFactory.

   .. grid-item::

      ..  figure:: ./images/VT_PowerFactory2.png
            :alt: Pop-up window of the new generated voltage transformer at the PCC busbar in PowerFactory.

            Figure 5: Pop-up window of the new generated voltage transformer at the PCC busbar in PowerFactory.

After creating the voltage transformer, open its configuration by double-clicking the component. 
In the transformer configuration dialog, create a new transformer type (see Figure 6) and select Ideal Voltage Transformer (see Figure 7). 
The ideal transformer is sufficient for the present application because the purpose of the component is to provide the required voltage measurements rather than to model the physical behavior of a transformer.

.. grid:: 2

   .. grid-item::

      .. figure:: ./images/VT_PowerFactory3.png
         :alt: Pop-up window for the choice of the newly generated voltage transformer's type.

         Figure 6: Pop-up window for the choice of the newly generated voltage transformer's type.

   .. grid-item::

      .. figure:: ./images/VT_PowerFactory4.png
         :alt: Pop-up window for the definition of a voltage transformer type.

         Figure 7: Pop-up window for the definition of a voltage transformer type.

The voltage transformer is now connected to the PCC and can be used to obtain the three phase-to-ground voltage signals required by the DLL (see Figure 8 - 10).

.. grid:: 3

   .. grid-item::

      ..  figure:: ./images/VT_PowerFactory5.png
            :alt: Pop-up window after right-clicking the new voltage transformer.
            :align: center
            :width: 50%

            Figure 8: Pop-up window after right-clicking the new voltage transformer.

   .. grid-item::

      ..  figure:: ./images/VT_PowerFactory7.png
            :alt: Opening the voltage transformer result variable window by double-clicking.
            :align: center

            Figure 9: Opening the voltage transformer result variable window by double-clicking.

   .. grid-item::

      ..  figure:: ./images/VT_PowerFactory8.png
            :alt: Adding the necessary voltage measurements to the result log.
            :align: center

            Figure 10: Adding the necessary voltage measurements to the result log.

Adding the current transformer
""""""""""""""""""""""""""""""
The current transformer is used to measure the three phase currents at the PCC and provide them as input signals to the IEC 61400-27 DLL. 
An ideal current transformer is used for this purpose, as no transformer losses or other transformer-specific effects need to be considered in the present example.

To add the current transformer, select the cubicle of the PCC busbar connected to the thevenin impedance (see Figure 11) and create a new object using the New Object button in the upper-right corner of the window. 
Select Current Transformer from the list of available components (see Figure 12) and assign a suitable name to the new component (see Figure 13).

.. grid:: 3

   .. grid-item::

      ..  figure:: ./images/PCC_Cub1_PowerFactory.png
            :alt: Choice of the cubicle of the PCC busbar connected to the thevenin impedance in the PowerFactory model menu.

            Figure 11: Choice of the cubicle of the PCC busbar connected to the thevenin impedance in the PowerFactory model menu.

   .. grid-item::

       ..  figure:: ./images/CT_PowerFactory.png
            :alt: Adding a new current transformer to the cubicle of the PCC busbar connected to the thevenin impedance in PowerFactory.

            Figure 12: Adding a new current transformer to the cubicle of the PCC busbar connected to the thevenin impedance in PowerFactory.

   .. grid-item::

      ..  figure:: ./images/CT_PowerFactory2.png
            :alt: Pop-up window of the new generated current transformer at cubicle of the PCC busbar connected to the thevenin impedance in PowerFactory.

            Figure 13: Pop-up window of the new generated current transformer at cubicle of the PCC busbar connected to the thevenin impedance in PowerFactory.

After creating the current transformer, open its configuration by double-clicking the component. 
In the transformer configuration dialog, create a new transformer type and select Current Transformer Type (TypCt) (see Figure 14) and select Ideal Current Transformer (see Figure 15). 
The ideal transformer is sufficient for the present application because the purpose of the component is to provide the required current measurements rather than to model the physical behavior of a transformer.

.. grid:: 2

   .. grid-item::

      .. figure:: ./images/CT_PowerFactory3.png
         :alt: Pop-up window for the choice of the newly generated current transformer's type.

         Figure 14: Pop-up window for the choice of the newly generated current transformer's type.

   .. grid-item::

      .. figure:: ./images/CT_PowerFactory4.png
         :alt: Pop-up window for the definition of a current transformer type.

         Figure 15: Pop-up window for the definition of a current transformer type.

The voltage transformer is now connected to the cubicle of the PCC and can be used to obtain the three phase current signals required by the DLL (see Figure 16 - 18).

.. grid:: 3

   .. grid-item::

      ..  figure:: ./images/CT_PowerFactory5.png
            :alt: Pop-up window after right-clicking the new current transformer.
            :align: center
            :width: 50%

            Figure 16: Pop-up window after right-clicking the new current transformer.

   .. grid-item::

      ..  figure:: ./images/CT_PowerFactory6.png
            :alt: Opening the current transformer result variable window by double-clicking.
            :align: center

            Figure 17: Opening the current transformer result variable window by double-clicking.

   .. grid-item::

      ..  figure:: ./images/CT_PowerFactory7.png
            :alt: Adding the necessary current measurements to the result log.
            :align: center

            Figure 18: Adding the necessary current measurements to the result log.

DLL integration using a dynamic model in PowerFactory
-----------------------------------------------------
After setting up the electrical components of the grid model along with the required voltage and current measurements at the PCC, the next step is to integrate the DLL itself into the model. 
This integration is performed via a so-called Composite Model Frame, which defines the signal connections between the measured quantities, the DLL, and the controlled voltage source.

First, a new, empty Composite Model Frame is created (see Figure 19). 
In the corresponding input window, the name and basic settings of the frame are defined (see Figure 20). 
The graphical editing interface of the still-empty frame then opens, in which the individual slots (blocks) and their signal connections are defined in the subsequent steps (see Figure 21).
.. grid:: 3

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame.png
            :alt: Creating a new empty composite model frame.
            :align: center

            Figure 19: Creating a new empty composite model frame.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame1.png
            :alt: Input mask of the composite model frame definition.
            :align: center

            Figure 20: Input mask of the composite model frame definition.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame2.png
            :alt: Empty composite model frame defintion.
            :align: center

            Figure 21: Empty composite model frame defintion.

The first slots to be created are those for the measured quantities. 
A slot for the voltage transformer is created to feed the three phase-to-ground voltages at the PCC into the frame (see Figure 22). 
Similarly, a slot for the current transformer is added, through which the three phase currents are provided (see Figure 23). 
Figure 24 shows the frame after both measurement slots have been added.

.. grid:: 3

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame3.png
            :alt: Creating a voltage transformer slot in the composite model frame.
            :align: center

            Figure 22: Creating a voltage transformer slot in the composite model frame.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame4.png
            :alt: Creating a current transformer slot in the composite model frame.
            :align: center

            Figure 23: Creating a current transformer slot in the composite model frame.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame5.png
            :alt: Composite model frame containing the measurement slots for three phase voltage and current.
            :align: center

            Figure 24: Composite model frame containing the measurement slots for three phase voltage and current.

Next, a slot for the DLL itself is created (see Figure 25). 
The previously compiled IEC 61400-27 DLL is loaded into this slot as a Compiled Model (see Figure 26). 
Figure 27 shows the frame with the integrated DLL slot, whose inputs and outputs are now available for further signal wiring.

.. grid:: 3

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame6.png
            :alt: Creating a DLL slot in the composite model frame.
            :align: center

            Figure 25: Creating a DLL slot in the composite model frame.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame7.png
            :alt: Imported DLL as compiled model in the DLL slot of the composite model frame.
            :align: center

            Figure 26: Imported DLL as compiled model in the DLL slot of the composite model frame.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame8.png
            :alt: Composite model frame containing the DLL slot.
            :align: center

            Figure 27: Composite model frame containing the DLL slot.

Since the output quantities of the DLL do not directly match the unit required by the controlled voltage source (kilovolts), in PowerFactory, an additional conversion slot is inserted (see Figure 28). 
This slot contains the corresponding conversion equations, which transform the DLL output signals into the format required by the voltage source (see Figure 29). 
Figure 30 shows the frame after the conversion slot has been added.

.. grid:: 3

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame9.png
            :alt: Creating a conversion slot in the composite model frame.
            :align: center

            Figure 28: Creating a conversion slot in the composite model frame.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame10.png
            :alt: Equations of the conversion slot in the composite model frame.
            :align: center

            Figure 29: Equations of the conversion slot in the composite model frame.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame11.png
            :alt: Composite model frame containing the conversion slot.
            :align: center

            Figure 30: Composite model frame containing the conversion slot.

Finally, a slot is created for the regulated ideal voltage source, which was previously introduced as part of the IBR equivalent circuit (see Figure 31). 
Figure 32 shows the complete frame containing all four slots: voltage measurement, current measurement, DLL, and voltage source.

In the last step, the inputs and outputs of the individual slots are connected to one another: the measured voltages and currents are fed into the DLL slot as input signals, the DLL's output quantities are converted into the required format via the conversion slot, and the result is then passed to the controlled voltage source as its setpoint. 
Figure 33 shows the fully wired Composite Model Frame. 
This completes the integration of the DLL into the PowerFactory model, and simulations with dynamic behavior according to IEC 61400-27 can now be carried out.

.. grid:: 3

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame12.png
            :alt: Creating a voltage source slot in the composite model frame.
            :align: center

            Figure 31: Creating a voltage source slot in the composite model frame.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame13.png
            :alt: Composite model frame containing the voltage source slot.
            :align: center

            Figure 32: Composite model frame containing the voltage source slot.

   .. grid-item::
      ..  figure:: ./images/CompositeModelFrame14.png
            :alt: Composite model frame containing the signal connection of the slots.
            :align: center

            Figure 33: Composite model frame containing the signal connection of the slots.