@echo off
setlocal enabledelayedexpansion

set EXAMPLES_DIR=%~dp0..
set SCRIPT_NAME=%0
set EXAMPLE_PATH_BEGIN=com\tangosol\examples
set COHERENCE_HOME=%EXAMPLES_DIR%\..\..

call %EXAMPLES_DIR%\bin\set_example_env %1
if defined RET (
    goto %RET%
    )
    
call %EXAMPLES_DIR%\bin\set_env SCRIPT_NAME
if defined RET (
    goto %RET%
    )

if "%EXAMPLE%"=="federation" (
   if defined SSL (
     SET COH_OPTS=%COH_OPTS% -Didentity.manager=file:%2-keystore.jks
   )
)

echo redirecting Coherence logging to %EXAMPLE%.log...

"%JAVA_HOME%"\bin\java %COH_OPTS% -Xms64m -Xmx64m ^
     -Dcoherence.distributed.localstorage=false ^
     -Dcoherence.log=%EXAMPLE%.log ^
     com.tangosol.examples.%EXAMPLE%.Driver %EXAMPLE% %EXAMPLES_DIR% %1 %2 %3 %4 %5 %6 %7

:exit
