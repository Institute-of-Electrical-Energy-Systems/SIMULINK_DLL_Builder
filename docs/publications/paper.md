---
title: 'Simulink IEC61400-27 DLL Builder'
tags:
  - Matlab Simulink
  - IEC 61400-27
  - Dynamic Linked Library
  - Power System Simulation
  - Control System Modeling
authors:
  - name: Gregor Becker 
    corresponding: true # (This is how to denote the corresponding author)
    orcid: 0000-0000-0000-0000
    equal-contrib: true
    affiliation: 1
  - name: Dominik Frauenknecht
    orcid: 0000-0000-0000-0000
    equal-contrib: true
    affiliation: 1
  - name: Gert Mehlmann
    orcid: 0000-0000-0000-0000
    affiliation: 1
  - name: Johann Jaeger
    orcid: 0000-0000-0000-0000
    affiliation: 1
  - name: Matthias Luther
    orcid: 0000-0000-0000-0000
    affiliation: 1
affiliations:
 - name: Institue of Electrical Energy Systems, Friedrich-Alexander-Universität Erlangen-Nürnberg, Germany
   index: 1

date: 02 April 2026
bibliography: paper.bib

---
# Summary


# Statement of need

The range of electrical power system simulation tools is extensive, with each tool differing in its specific capabilities and applications (Thurner et al., 2018).
Many tools are specialized for particular time scales or levels of model detail. 
For example, PSCAD is widely used for electromagnetic transient (EMT) simulations (Kim et al., 2026), 
whereas tools such as Neplan or Integral are mainly applicable to steady-state or root mean square (RMS)-based analyses (ENTSO-E, 2011). 
Therefore, the choice of a simulation tool largely depends on the specific study objectives and the required level of model detail.

Despite these differences, a common limitation persists across most simulation tools: 
they are not inherently designed for developing control structures, nor do they typically provide mechanisms to export such control models for use in other simulation environments. 
This, combined with the industry’s commercial incentive to maintain the confidentiality of their control systems, has led to the development of black-box modeling—a methodology that enables the integration of control systems into simulations without exposing proprietary algorithms. 
This approach allows the operational behavior of a converter to be replicated while preserving the confidentiality of its underlying control design.

To ensure the interoperability and portability of a model across different tools and vendors, the International Electrotechnical Commission (IEC) published IEC 61400-27 Annex F. 
This standard defines function names, input and output parameters, and the output format of a dynamic-link library (DLL), thereby establishing a standardized data format that can be exchanged between different simulation software tools.

This DLL format serves as both the reference and target format for the DLL Builder described in this submission. 
The Builder can export the C code of a control structure developed in MATLAB Simulink and encapsulate it within the IEC 61400-27 framework before generating a dynamic-link library (DLL) for use in various simulation tools. 
Thus, the presented Builder leverages existing interfaces for IEC 61400-27-compliant DLLs by populating them with the user-defined control model. 
By exporting the model and integrating the resulting DLL into a simulation program, computationally intensive approaches—such as co-simulation between DIgSILENT PowerFactory and MATLAB Simulink—can be avoided. 
Consequently, this method enables a significant improvement in simulation performance.


# References
