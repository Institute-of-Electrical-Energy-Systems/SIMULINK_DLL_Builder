############
DLL in PSCAD
############

This chapter provides a step-by-step description of the integration and use of an IEC 61400-27 DLL in PSCAD. 
The required prerequisites, including the necessary software and supported software versions, are presented first. 
The chapter then describes the configuration of the example grid model and the integration of the IEC 61400-27 DLL. 
An empty PSCAD project is used as the starting point for the model implementation.

Prerequisites
-------------
- PSCAD Version 5.x (tested for PSCAD v5.0.2)
- Intel Fortran Compiler (Installation instruction can be found `here <FEHLT>`)
- IEC 61400-27 DLL (e.g. the one from the `example <FEHLT>`)

Builing a model for later DLL integration from scratch 
------------------------------------------------------
The final model consists of a regulated ideal voltage source and an internal resistance connected at the point of common coupling (PCC). 
The PCC is supplied by a Thevenin equivalent representing the upstream grid. 
The individual components are added and configured step by step, starting from the blank PSCAD project.

1. Builing a thevenin equivalent
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
..  figure:: ./images/TheveninPSCAD.png
    :alt: Thevenin equivalent connect to PCC in PSCAD.

    Thevenin equivalent connect to PCC in PSCAD.

By definition, a Thevenin equivalent consists of an ideal voltage source and a series-connected internal impedance. 
In this model, the ideal voltage source applies a voltage of 1 p.u. to the bus at its terminals (“InnerThevenin”). 
For the example considered here, this corresponds to a line-to-line RMS voltage of 400 kV with a phase angle of 0°.

The internal impedance determines the short-circuit power, and therefore the strength, of the upstream grid. 
In the present example, the impedance is defined by a resistance of R = 10.6137 Ω and an inductance of L = 0.3378455 H.

A simulation can already be performed using these two components alone. 
However, such a simulation is of limited significance, as the Thevenin equivalent only provides the voltage supply at the PCC without representing any connected equipment or grid interaction.

