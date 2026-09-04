################################
Simulink IEC61400-27 DLL Builder
################################
Gregor Becker :sup:`1,*`, Dominik Frauenknecht :sup:`1,*`, Gert Mehlmann :sup:`1`, Johann Jaeger :sup:`1` and Matthias Luther :sup:`1` 

| 1 Institue of Electrical Energy Systems, Friedrich-Alexander-Universität Erlangen-Nürnberg
| `*` These authors contributed equally and are thereby the corresponding authors.

*******
Summary
*******


*****************
Statement of need
*****************

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

| The remainder of this documentation is organized as follows:
| The section :doc:`How_to_use` introduces the developed IEC 61400-27 DLL Builder and explains its basic usage. The files required for the *Simulink Coder* code generation process are described in detail in the :doc:`Simulink_Coder_Section` section. Subsequently, the steps required to use the generated DLL in various simulation programs are presented, including DIgSILENT PowerFactory (see :doc:`DLL_in_PF`), PSS Netomac (see :doc:`DLL_in_Netomac`), and PSCAD (see :doc:`DLL_in_PSCAD`).

	
**********
References
**********

Thurner, L., Scheidler, A., Schafer, F., Menke, J.-H., Dollichon, J., Meier, F., Meinecke, S., Braun, M. (2018). Pandapower — An Open-Source Python Tool for Convenient Modeling, Analysis, and Optimization of Electric Power Systems. IEEE Transactions on Power Systems,  33(6). http://dx.doi.org/10.1109/TPWRS.2018.2829021

Kim, B.-G., Moon, C.-J., Choi, S.-H., Choi, Y.-S., Lee, K.-M. (2026). PSCAD-Based Analysis of Short-Circuit Faults and Protection Characteristics in a Real BESS-PV Microgrid. Energies 19(3), 598. https://doi.org/10.3390/en19030598

European Network of Transmission System Operators for Electricity – ENTSO-E (2011). INTEROPERABILITY TEST ― CIM FOR SYSTEM DEVELOPMENT AND OPERATIONS. 



.. toctree::
   :maxdepth: 3
   :hidden:
   :caption: Tool

   How_to_use

.. toctree:: 
   :maxdepth: 3   
   :hidden:
   :caption: Example

   example_usage

.. toctree:: 
   :maxdepth: 3
   :hidden:
   :caption: Integration into power <br />
             system simulation 

   DLL_in_PF
   DLL_in_Netomac
   DLL_in_PSCAD

.. toctree:: 
   :maxdepth: 3
   :hidden:
   :caption: Troubleshooting
   
   troubleshooting

