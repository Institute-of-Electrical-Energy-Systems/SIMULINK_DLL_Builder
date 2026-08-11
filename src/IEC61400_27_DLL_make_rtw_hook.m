function IEC61400_27_DLL_make_rtw_hook(hookMethod, modelName, rtwroot, tmf, buildOpts, buildArgs)

switch hookMethod

    case 'before_tlc'

        fprintf('Generating parameter metadata...\n');
        getParamMetadataRTW(modelName);

    case 'after_tlc'

    case 'before_make'

    case 'after_make'

    case 'exit'

    case 'error'
end