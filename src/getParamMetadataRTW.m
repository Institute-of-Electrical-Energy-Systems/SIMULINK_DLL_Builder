function getParamMetadataRTW(model)
% GETPARAMMETADATARTW  Extracts Simulink.Parameter metadata from the base
%   workspace and writes it to a TLC file for use in Simulink coder
%   code generation.
%
%   GETPARAMMETADATARTW(MODEL) scans all variables associated with MODEL,
%   finds those that are Simulink.Parameter objects, and emits TLC
%   "%assign" statements capturing each parameter's unit, description,
%   min, max, and default value.
%
%   Output file: ParameterMetadata.tlc  (written to the current folder)
%
%   Example:
%       getParamMetadataRTW('myModel')

    % --- Discover all variables referenced by the model -------------------
    vars = Simulink.findVars(model);

    % --- Open output TLC file for writing ---------------------------------
    outfile = fullfile(pwd, 'ParameterMetadata.tlc');
    fid = fopen(outfile, 'w');
    if fid < 0
        error('Cannot create file: %s', outfile);
    end

    % Track already-written parameter names to avoid duplicate entries
    % (a variable may appear more than once in the vars list).
    written = containers.Map;

    % --- Iterate over every variable found in the model ------------------
    for k = 1:numel(vars)
        try
            % Retrieve the variable's value from the base workspace
            obj = evalin('base', vars(k).Name);

            % Process only Simulink.Parameter objects; skip everything else
            if isa(obj, 'Simulink.Parameter')

                % Sanitise the variable name so it is a valid TLC identifier
                name = matlab.lang.makeValidName(vars(k).Name);

                % Skip if this parameter has already been written
                if isKey(written, name)
                    continue;
                end
                written(name) = true;   % Mark as written

                % --- Sanitise metadata fields ----------------------------

                % Escape any double-quotes inside the unit string for TLC
                unit = strrep(obj.Unit, '"', '\"');

                % Collapse newlines / carriage-returns in the description
                % to keep each TLC assignment on a single line
                desc = regexprep(obj.Description, '[\r\n]+', ' ');

                % Use the object's Min/Max when available; fall back to
                % wide sentinel values so generated code is always bounded
                if ~isempty(obj.Min)
                    minval = mat2str(obj.Min);
                else
                    minval = -1e6;      % Default lower bound sentinel
                end

                if ~isempty(obj.Max)
                    maxval = mat2str(obj.Max);
                else
                    maxval = 1e6;       % Default upper bound sentinel
                end

                % Convert the parameter value to a string for TLC output
                defaultval = mat2str(obj.Value);

                % --- Write TLC %assign statements for this parameter -----
                % Each line defines a TLC variable: ParameterMetadata_<Name>_<Field>
                fprintf(fid, '%%assign ParameterMetadata_%s_Unit    = "%s"\n', name, unit);
                fprintf(fid, '%%assign ParameterMetadata_%s_Desc    = "%s"\n', name, desc);
                fprintf(fid, '%%assign ParameterMetadata_%s_Min     = "%s"\n', name, minval);
                fprintf(fid, '%%assign ParameterMetadata_%s_Max     = "%s"\n', name, maxval);
                fprintf(fid, '%%assign ParameterMetadata_%s_Default = "%s"\n\n', name, defaultval);
            end

        catch ME
            % Warn and continue so one bad variable doesn't abort the whole export
            warning('Error processing %s:\n%s', vars(k).Name, ME.message);
        end
    end

    % --- Close the output file -------------------------------------------
    fclose(fid);
end