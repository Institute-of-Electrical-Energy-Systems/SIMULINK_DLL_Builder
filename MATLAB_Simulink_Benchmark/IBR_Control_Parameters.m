clear;    % Clear Workspase

%% Simulation and Grid Data

% Simulation time step 
Ts = Simulink.Parameter;
Ts.Value = 50e-6;
Ts.DataType = 'double';
Ts.Min = 1e-6;
Ts.Max = 100e-6;
Ts.Unit = 's';
Ts.Complexity = 'real';
Ts.Description = 'Simulation time step';

% Nominal frequency
Fn = Simulink.Parameter;
Fn.Value = 50;
Fn.DataType = 'double';
Fn.Min = 0;
Fn.Max = 1e6;
Fn.Unit = 'Hz';
Fn.Complexity = 'real';
Fn.Description = 'Nominal frequency';

%% Converter Model Data

% Rated power of converter 
Sn = Simulink.Parameter;
Sn.Value = 500e6;
Sn.DataType = 'double';
Sn.Min = 1;
Sn.Max = 100e12;
Sn.Unit = 'MVA';
Sn.Complexity = 'real';
Sn.Description = 'Rated power of converter';

% Converter resistance
Rc = Simulink.Parameter;
Rc.Value = 0.7820;
Rc.DataType = 'double';
Rc.Min = 1e-6;
Rc.Max = 1e6;
Rc.Unit = 'Ohm';
Rc.Complexity = 'real';
Rc.Description = 'Converter resistance';

% Converter inductance
Lc = Simulink.Parameter;
Lc.Value = 0.1574;
Lc.DataType = 'double';
Lc.Min = 1e-6;
Lc.Max = 1e6;
Lc.Unit = 'H';
Lc.Complexity = 'real';
Lc.Description = 'Converter inductance';

% Converter active 
Pref = Simulink.Parameter;
Pref.Value = 500e6;
Pref.DataType = 'double';
Pref.Min = -500e6;
Pref.Max = 500e6;
Pref.Unit = 'W';
Pref.Complexity = 'real';
Pref.Description = 'Active power set-point';

% Converter inductance
Qref = Simulink.Parameter;
Qref.Value = 100e6;
Qref.DataType = 'double';
Qref.Min = -500e6;
Qref.Max = 500e6;
Qref.Unit = 'VAr';
Qref.Complexity = 'real';
Qref.Description = 'Reactive power set-point';

% Filter time constant of power control (continous) 
Tf_S = Simulink.Parameter;
Tf_S.Value = 0.1;
Tf_S.DataType = 'double';
Tf_S.Min = 1e-6;
Tf_S.Max = 1e6;
Tf_S.Unit = 's';
Tf_S.Complexity = 'real';
Tf_S.Description = 'Filter time constant of power control (continuous)';

% Proportional gain of current controller (continous) 
Kp_I = Simulink.Parameter;
Kp_I.Value = 400;
Kp_I.DataType = 'double';
Kp_I.Min = 1e-6;
Kp_I.Max = 1e6;
Kp_I.Unit = 'V/A';
Kp_I.Complexity = 'real';
Kp_I.Description = 'Proportional gain of current controller (continuous)';

% Integral gain of current controller (continous) 
Ki_I = Simulink.Parameter;
Ki_I.Value = 8000;
Ki_I.DataType = 'double';
Ki_I.Min = 1e-6;
Ki_I.Max = 1e6;
Ki_I.Unit = 'V/A';
Ki_I.Complexity = 'real';
Ki_I.Description = 'Integral gain of current controller (continuous)';

% Proportional gain of phase-locked loop (continous) 
Kp_PLL = Simulink.Parameter;
Kp_PLL.Value = 0.0002;
Kp_PLL.DataType = 'double';
Kp_PLL.Min = 1e-6;
Kp_PLL.Max = 1e6;
Kp_PLL.Unit = 'Hz/V';
Kp_PLL.Complexity = 'real';
Kp_PLL.Description = 'Proportional gain of phase-locked loop (continous)';

% Integral gain of of phase-locked loop (continous) 
Ki_PLL = Simulink.Parameter;
Ki_PLL.Value = 0.02;
Ki_PLL.DataType = 'double';
Ki_PLL.Min = 1e-6;
Ki_PLL.Max = 1e6;
Ki_PLL.Unit = 'Hz/V';
Ki_PLL.Complexity = 'real';
Ki_PLL.Description = 'Integral gain of phase-locked loop (continous)';

%% Thevenin Equivalent Data

% Nominal line-to-line voltage
Vn = Simulink.Parameter;
Vn.Value = 400e3;
Vn.DataType = 'double';
Vn.Min = 1;
Vn.Max = 1e12;
Vn.Unit = 'V';
Vn.Complexity = 'real';
Vn.Description = 'Nominal line-to-line voltage';

% Short-circuit-ratio
% Unit: -
SCR = 3;        

% R/X-Ratio 
% Unit: -
RXratio = 0.1; 

% Resistance of Thevenin Equivalent 
Re = Simulink.Parameter;
Re.Value = Vn.Value^2 / (SCR * Sn.Value) / sqrt(RXratio^2 + 1) * RXratio;
Re.DataType = 'double';
Re.Min = 1e-6;
Re.Max = 1e6;
Re.Unit = 'Ohm';
Re.Complexity = 'real';
Re.Description = 'Resistance of thevenin equivalent';

% Inductance of Thevenin Equivalent 
% Unit: Ohm
Xe = Vn.Value^2 / (SCR * Sn.Value) / sqrt(RXratio^2 + 1);

% Inductance of Thevenin Equivalent
Le = Simulink.Parameter;
Le.Value = Xe/(2*pi*Fn.Value);
Le.DataType = 'double';
Le.Min = 1e-6;
Le.Max = 1e6;
Le.Unit = 'H';
Le.Complexity = 'real';
Le.Description = 'Inductance of thevenin equivalent';

clear SCR RXratio Xe

%% Initialization by load-flow calculation

% Ideal Voltage Source of thevenin equivalent
% Complexity: Complex
% Unit: V
cVe = complex(Vn.Value/sqrt(3),0);
    
% Power injected at point of commoun coupling (PCC)
% Complexity: Complex
% Unit: VA
cSc = complex(Pref.Value,Qref.Value);

% Thevenin Impedance
% Complexity: Complex
% Unit: Ohm
cZe = complex(Re.Value,2*pi*Fn.Value*Le.Value);

% Starting voltage phasor at PCC 
% Complexity: Complex
% Unit: V
x0 = [real(cVe); imag(cVe)];

% Options for fsolve
options = optimoptions('fsolve',...      
                       'FunctionTolerance', 1e-12, ... 
                       'StepTolerance', 1e-12);

% Call function for solving the voltage equation
[sol, fval, exitflag, output] = fsolve(@(x) KVL_equations(x,cVe,cSc,cZe), x0, options);

% Function for solving the voltage at PCC
function F = KVL_equations(x,cVe,cSc,cZe)
    
    % Solving voltage at PCC
    cVg = x(1) + 1i*x(2);

    % Kirchhoff's voltage law
    KVL = cVe - cVg + (conj(cSc)/(3*conj(cVg))) * cZe;

    % Output value
    F = [real(KVL); imag(KVL)];
end

% Voltage phasor at PCC
% Complexity: Complex
% Unit: V
cVg = sol(1) + 1i * sol(2);

% Initial voltage magnitude at PCC 
Vmag0_pcc = Simulink.Parameter;
Vmag0_pcc.Value = abs(cVg) * sqrt(3);
Vmag0_pcc.DataType = 'double';
Vmag0_pcc.Min = 0;
Vmag0_pcc.Max = 1e12;
Vmag0_pcc.Unit = 'V';
Vmag0_pcc.Complexity = 'real';
Vmag0_pcc.Description = 'Initial voltage magnitude at PCC';

% Initial voltage angle at PCC 
Vang0_pcc = Simulink.Parameter;
Vang0_pcc.Value = angle(cVg);
Vang0_pcc.DataType = 'double';
Vang0_pcc.Min = 0;
Vang0_pcc.Max = 2*pi;
Vang0_pcc.Unit = 'rad';
Vang0_pcc.Complexity = 'real';
Vang0_pcc.Description = 'Initial voltage angle at PCC';

% Initial a-current injected at PCC
Va0_pcc = Simulink.Parameter;
Va0_pcc.Value = abs(cVg) * cos(angle(cVg));
Va0_pcc.DataType = 'double';
Va0_pcc.Min = -1e12;
Va0_pcc.Max = 1e12;
Va0_pcc.Unit = 'V';
Va0_pcc.Complexity = 'real';
Va0_pcc.Description = 'Initial a-voltage at PCC';

% Initial b-current injected at PCC 
Vb0_pcc = Simulink.Parameter;
Vb0_pcc.Value = abs(cVg) * cos(angle(cVg)-2/3*pi);
Vb0_pcc.DataType = 'double';
Vb0_pcc.Min = -1e12;
Vb0_pcc.Max = 1e12;
Vb0_pcc.Unit = 'V';
Vb0_pcc.Complexity = 'real';
Vb0_pcc.Description = 'Initial b-voltage at PCC';

% Initial c-current injected at PCC 
Vc0_pcc = Simulink.Parameter;
Vc0_pcc.Value = abs(cVg) * cos(angle(cVg)-4/3*pi);
Vc0_pcc.DataType = 'double';
Vc0_pcc.Min = -1e12;
Vc0_pcc.Max = 1e12;
Vc0_pcc.Unit = 'V';
Vc0_pcc.Complexity = 'real';
Vc0_pcc.Description = 'Initial c-voltage at PCC';

% Complex current phasor
% Complexity: Complex
% Unit: V
cI = conj(cSc)/(3*conj(cVg));

% Initial current magnitude injected at PCC 
Imag0_pcc = Simulink.Parameter;
Imag0_pcc.Value = abs(cI);
Imag0_pcc.DataType = 'double';
Imag0_pcc.Min = 0;
Imag0_pcc.Max = 1e12;
Imag0_pcc.Unit = 'A';
Imag0_pcc.Complexity = 'real';
Imag0_pcc.Description = 'Initial current magnitude injected at PCC';

% Initial current angle injected at PCC
Iang0_pcc = Simulink.Parameter;
Iang0_pcc.Value = angle(cI);
Iang0_pcc.DataType = 'double';
Iang0_pcc.Min = 0;
Iang0_pcc.Max = 2*pi;
Iang0_pcc.Unit = 'rad';
Iang0_pcc.Complexity = 'real';
Iang0_pcc.Description = 'Initial current angle injected at PCC';

% Initial a-current injected at PCC
Ia0_pcc = Simulink.Parameter;
Ia0_pcc.Value = abs(cI) * cos(angle(cI));
Ia0_pcc.DataType = 'double';
Ia0_pcc.Min = -1e12;
Ia0_pcc.Max = 1e12;
Ia0_pcc.Unit = 'A';
Ia0_pcc.Complexity = 'real';
Ia0_pcc.Description = 'Initial a-current injected at PCC';

% Initial b-current injected at PCC 
Ib0_pcc = Simulink.Parameter;
Ib0_pcc.Value = abs(cI) * cos(angle(cI)-2/3*pi);
Ib0_pcc.DataType = 'double';
Ib0_pcc.Min = -1e12;
Ib0_pcc.Max = 1e12;
Ib0_pcc.Unit = 'A';
Ib0_pcc.Complexity = 'real';
Ib0_pcc.Description = 'Initial b-current injected at PCC';

% Initial c-current injected at PCC 
Ic0_pcc = Simulink.Parameter;
Ic0_pcc.Value = abs(cI) * cos(angle(cI)-4/3*pi);
Ic0_pcc.DataType = 'double';
Ic0_pcc.Min = -1e12;
Ic0_pcc.Max = 1e12;
Ic0_pcc.Unit = 'A';
Ic0_pcc.Complexity = 'real';
Ic0_pcc.Description = 'Initial c-current injected at PCC';

% Complex converter impedance
% Complexity: Complex
% Unit: Ohm
cZc = complex(Rc.Value,2*pi*Fn.Value*Lc.Value);

% Complex converter voltage
% Complexity: Complex
% Unit: V
cVc = cVg + cI*cZc;

% Initial converter voltage for phase a
Va0_c = Simulink.Parameter;
Va0_c.Value = abs(cVc) * cos(angle(cVc));
Va0_c.DataType = 'double';
Va0_c.Min = -1e12;
Va0_c.Max = 1e12;
Va0_c.Unit = 'V';
Va0_c.Complexity = 'real';
Va0_c.Description = 'Initial converter voltage for phase a';

% Initial converter voltage for phase b
Vb0_c = Simulink.Parameter;
Vb0_c.Value = abs(cVc) * cos(angle(cVc)-2/3*pi);
Vb0_c.DataType = 'double';
Vb0_c.Min = -1e12;
Vb0_c.Max = 1e12;
Vb0_c.Unit = 'V';
Vb0_c.Complexity = 'real';
Vb0_c.Description = 'Initial converter voltage for phase b';

% Initial converter voltage for phase c 
Vc0_c = Simulink.Parameter;
Vc0_c.Value = abs(cVc) * cos(angle(cVc)-4/3*pi);
Vc0_c.DataType = 'double';
Vc0_c.Min = -1e12;
Vc0_c.Max = 1e12;
Vc0_c.Unit = 'V';
Vc0_c.Complexity = 'real';
Vc0_c.Description = 'Initial converter voltage for phase c';

clear cI cSc cVc cZc cVe cVg cZe exitflag fval options output sol x0

%% Save Workspace

save('IBR_Control_Parameters.mat');