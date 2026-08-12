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

.. code-block:: fortran
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