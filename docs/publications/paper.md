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

# Software design
The software design of the Simulink IEC 61400-27 DLL Builder is largely determined by the established structure of MATLAB/Simulink, as it is integrated into the functionality provided by the Simulink Coder application.

Within the constraints of this environment, the design emphasizes modularity and extensibility. Accordingly, the required working directory comprises two Target Language Compiler (TLC) files, two MATLAB scripts (.m), two header files (.h), one compiled S-Function, and one Template Makefile (TMF), as summarized in Table 1.

**Table 1: Files required for IEC 61400-27 DLL generation**

| **File**                          | **Function**                                                                                                                                                                                    |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `IEC61400_27_DLL.tlc`             | System Target File (STF) that controls the Simulink code generation process and the creation of the controller DLL.                                                                             |
| `IEC61400_27_DLL.tmf`             | Template Makefile used during the compilation and linking of the generated C code.                                                                                                              |
| `IEC61400_27_DLL_make_rtw_hook.m` | Build hook executed after code generation and before the DLL is built. It exports the parameter descriptions, units, and limits to `ParameterMetadata.tlc` by invoking `getParamMetadataRTW.m`. |
| `getParamMetadataRTW.m`           | MATLAB script that implements the export of the parameter metadata.                                                                                                                             |
| `ext_simenv_capi.h`               | C API header that defines the IEC 61400-27 interface that every generated DLL must implement.                                                                                                   |
| `ext_simenv_types.h`              | C API header that defines the data types required by the IEC 61400-27 interface.                                                                                                                |
| `sfun_info.mexw64`                | Compiled S-Function that triggers `sfun_info.tlc` during code generation.                                                                                                                        |
| `sfun_info.tlc`                   | TLC file that generates the additional C source code required for the controller DLL.                                                                                                            |

While several of these files support the preparation and compilation of the IEC 61400-27 DLL, `IEC61400_27_DLL.tlc` serves as the entry point of the code generation process. This TLC file is detected by the Simulink Coder application when it is placed in the MATLAB working directory. After selecting the corresponding System Target File and providing the required DLL metadata in the DLL Builder's graphical interface, the DLL build process can be initiated.

During the DLL creation process, the Simulink Coder application first uses the TMF file to generate a makefile that defines the compilation, linking, and build process for the DLL of the Simulink model under consideration. Since the final output is a dynamically linked library, the linking and build steps are largely predefined by the required DLL structure. As a result, the control logic implemented in the Simulink model primarily influences the compilation of the generated model code, rather than the linking and build steps themselves. The Simulink IEC 61400-27 DLL Builder determines which generated source files are included and subsequently linked as part of the DLL build process.

The overall build process is primarily controlled by `IEC61400_27_DLL.tlc`. During code generation, this TLC file detects the model information file `model_info.mdl` — which holds metadata about the Simulink model being built — together with the compiled S-Function `sfun_info.mexw64`, thereby triggering both `IEC61400_27_DLL_make_rtw_hook.m` and `sfun_info.tlc`. The `IEC61400_27_DLL_make_rtw_hook.m` script extracts the relevant Simulink parameter information, including parameter names, values, minimum and maximum limits, and units, and stores this information in `ParameterMetadata.tlc`.

This metadata is subsequently used during the generation of the C source code that constitutes the core logic of the IEC 61400-27 DLL. The generation of this source code is handled by `sfun_info.tlc`. This Target Language Compiler file creates a temporary `IEC61400_27.c` file that must fulfill the syntactic and semantic requirements specified in IEC 61400-27 Annex F. To achieve this, it loads the parameter information extracted by `IEC61400_27_DLL_make_rtw_hook.m` together with the available model logic, and maps the corresponding Simulink code methods to the methods defined by IEC 61400-27 Annex F.

Once the `IEC61400_27.c` file has been generated, the compilation, linking, and build process is initiated. During this stage, the generated source files and the required interface files are compiled and linked according to the specifications defined by the TMF and the corresponding build configuration. The resulting output is the IEC 61400-27-compliant DLL.

Figure 1 illustrates the relationship between the individual files located in the working directory and their respective roles within the DLL generation process.

![UML diagramm of the Simulink IEC 61400-27 DLL builder](./UML_Diagramm.svg)

# AI usage disclosure
OpenAI ChatGPT was used for language editing, and restructuring suggestions. 
All AI-generated suggestions were reviewed, edited, and validated by the authors before inclusion.

# References
