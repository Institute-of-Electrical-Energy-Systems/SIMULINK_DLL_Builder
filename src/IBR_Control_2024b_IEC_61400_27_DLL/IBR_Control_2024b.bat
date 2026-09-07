
set skipSetupArg=%1
if "%skipSetupArg%" NEQ "skip_setup_msvc" (
call "setup_msvc.bat"
)

cd .
nmake -f IBR_Control_2024b.mk  INCLUDE_MDL_TERMINATE_FCN=1 OPTS="-DTID01EQ=1"
@if errorlevel 1 goto error_exit
exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1