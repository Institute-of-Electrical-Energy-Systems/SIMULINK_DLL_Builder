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

The increasing complexity of modern electrical grids has led to a growing need for simulation tools capable of accurately analyzing dynamic grid behavior, including system stability and protection system performance. A wide range of power system simulation tools is available, with individual tools differing substantially in their modeling capabilites, simulation methods, and intended applications. Many of these tools are tailored to specific simulation domains, time scales, and levels of model detail. Consequently, the choice of a simulation tool depends strongly on the objectives of the study and the phenomena that need to be represented. For example, PSCAD™ is widely used for electromagnetic transient (EMT) simulations, whereas PSS®E is primarily used for phasor-based (RMS) simulations. Other commercial tools, such as PSS®NETOMAC, DIgSILENT PowerFactory, and NEPLAN®, provide capabilities for both RMS and EMT simulations.

Despite these differences, many existing simulation tools share a common limitation: they are not primarily designed for the development of control structures, nor do they typically provide mechanisms for exporting such control models for use in other simulation environments. At the same time, the commercial incentive to protect proprietary control strategies and algorithms has contributed to the widespread use of black-box models. Such models enable the integration of the external behavior of control systems into simulation environments without disclosing their underlying implementation. 

To facilitate the interoperability and portability of dynamic models across different simulation tools and vendors, the International Electrotechnical Commission (IEC) published IEC 61400-27 Annex F (IEC, 2016). The standard specifies the function names, input and output parameters, and interface of a dynamic-link library (DLL), thereby defining a standardized model interface that enables dynamic models to be exchanged and integrated across different simulation software tools.

MATLAB®/Simulink® is widely used for the design, development, and validation of control systems, including the control structures of power electronic converters. As a general-purpose modeling environment, MATLAB®/Simulink® benefits from a large user base and a comprehensive set of toolboxes for implementing general-purpose control algorithms and mathematical functions. These capabilities make it particularly well suited for the rapid prototyping and validation of new component models and control strategies. However, the execution speed of general-purpose modeling environments can become a limiting factor when studying large or computationally complex systems (Mahseredjian et al., 2009). Exporting control models developed in MATLAB®/Simulink® as C code and integrating them into an IEC 61400-27-compliant DLL provides a means of overcoming this limitation. However, this process requires the generated C code to be integrated with the standardized DLL interface, which can involve additional implementation effort.

The DLL Builder presented in this work addresses this gap by automating this process. The Builder enables users to export the C code generated from a control structure developed in MATLAB®/Simulink® and integrate it into an IEC 61400-27-compliant DLL interface. The resulting dynamic-link library (DLL) can then be directly integrated into compatible simulation environments. Thus, the presented Builder leverages the standardized interface defined by IEC 61400-27 to make user-defined control models portable across different simulation tools without requiring access to the underlying control implementation.

# Software design
The software design of the Simulink IEC 61400-27 DLL Builder is largely determined by the established structure of MATLAB/Simulink, as it is integrated into the functionality provided by the Simulink Coder application.

Within the constraints of this environment, the design emphasizes modularity and extensibility. Accordingly, the required working directory comprises two Target Language Compiler (TLC) files, two MATLAB scripts (.m), two header files (.h), one compiled S-Function, and one Template Makefile (TMF), as summarized in Table 1.

**Table 1:** Files required for IEC 61400-27 DLL generation.

| **File**                         | **Function**                                   |
|----------------------------------|------------------------------------------------|
| `IEC61400_27_DLL.tlc`            | System Target File that controls the Simulink code generation process and the creation of the controller DLL. |
| `IEC61400_27_DLL.tmf`            | Template Makefile used during the compilation and linking of the generated C code. |
| `IEC61400_27_DLL_make_rtw_hook.m` | Build hook executed after code generation and before the DLL is built. It exports the parameter descriptions, units, and limits to `ParameterMetadata.tlc` by invoking `getParamMetadataRTW.m`. |
| `getParamMetadataRTW.m`          | MATLAB script that implements the export of the parameter metadata. |
| `ext_simenv_capi.h`              | C API header that defines the IEC 61400-27 interface that every generated DLL must implement. |
| `ext_simenv_types.h`             | C API header that defines the data types required by the IEC 61400-27 interface. |
| `sfun_info.mexw64`               | Compiled S-Function that triggers `sfun_info.tlc` during code generation. |
| `sfun_info.tlc`                  | TLC file that generates the additional C source code required for the controller DLL. |                                                                                               |

While several of these files support the preparation and compilation of the IEC 61400-27 DLL, `IEC61400_27_DLL.tlc` serves as the entry point of the code generation process. This TLC file is detected by the Simulink Coder application when it is placed in the MATLAB working directory. After selecting the corresponding System Target File and providing the required DLL metadata in the DLL Builder's graphical interface, the DLL build process can be initiated.

During the DLL creation process, the Simulink Coder application first uses the TMF file to generate a makefile that defines the compilation, linking, and build process for the DLL of the Simulink model under consideration. Since the final output is a dynamically linked library, the linking and build steps are largely predefined by the required DLL structure. As a result, the control logic implemented in the Simulink model primarily influences the compilation of the generated model code, rather than the linking and build steps themselves. The Simulink IEC 61400-27 DLL Builder determines which generated source files are included and subsequently linked as part of the DLL build process.

The overall build process is primarily controlled by `IEC61400_27_DLL.tlc`. During code generation, this TLC file detects the model information file `model_info.mdl` — which holds metadata about the Simulink model being built — together with the compiled S-Function `sfun_info.mexw64`, thereby triggering both `IEC61400_27_DLL_make_rtw_hook.m` and `sfun_info.tlc`. The `IEC61400_27_DLL_make_rtw_hook.m` script extracts the relevant Simulink parameter information, including parameter names, values, minimum and maximum limits, and units, and stores this information in `ParameterMetadata.tlc`.

This metadata is subsequently used during the generation of the C source code that constitutes the core logic of the IEC 61400-27 DLL. The generation of this source code is handled by `sfun_info.tlc`. This Target Language Compiler file creates a temporary `IEC61400_27.c` file that must fulfill the syntactic and semantic requirements specified in IEC 61400-27 Annex F. To achieve this, it loads the parameter information extracted by `IEC61400_27_DLL_make_rtw_hook.m` together with the available model logic, and maps the corresponding Simulink code methods to the methods defined by IEC 61400-27 Annex F.

Once the `IEC61400_27.c` file has been generated, the compilation, linking, and build process is initiated. During this stage, the generated source files and the required interface files are compiled and linked according to the specifications defined by the TMF and the corresponding build configuration. The resulting output is the IEC 61400-27-compliant DLL.

Figure 1 illustrates the relationship between the individual files located in the working directory and their respective roles within the DLL generation process.

![UML diagramm of the Simulink IEC 61400-27 DLL builder.](./UML_Diagramm.svg)

# AI usage disclosure
OpenAI ChatGPT was used for language editing, and restructuring suggestions. 
All AI-generated suggestions were reviewed, edited, and validated by the authors before inclusion.

# References

Mahseredjian, J., Dinavahi, V., Martinez, J. A. (2009).  Simulation Tools for Electromagnetic Transients in Power Systems: Overview and Challenges. IEEE Transactions on Power Delivery, 24(3), pp. 1657-1669. http://dx.doi.org/10.1109/TPWRD.2008.2008480. 

IEC 61400-27-1:2016 (2016). Wind energy generation systems - Part 27-1: Electrical simulation models - Generic models.

Thurner, L., Scheidler, A., Schafer, F., Menke, J.-H., Dollichon, J., Meier, F., Meinecke, S., Braun, M. (2018). Pandapower — An Open-Source Python Tool for Convenient Modeling, Analysis, and Optimization of Electric Power Systems. IEEE Transactions on Power Systems,  33(6). http://dx.doi.org/10.1109/TPWRS.2018.2829021  

Kim, B.-G., Moon, C.-J., Choi, S.-H., Choi, Y.-S., Lee, K.-M. (2026). PSCAD-Based Analysis of Short-Circuit Faults and Protection Characteristics in a Real BESS-PV Microgrid. Energies 19(3), 598. https://doi.org/10.3390/en19030598

European Network of Transmission System Operators for Electricity – ENTSO-E (2011). INTEROPERABILITY TEST ― CIM FOR SYSTEM DEVELOPMENT AND OPERATIONS. 
