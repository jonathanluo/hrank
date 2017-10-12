if "%EXAMPLE%"=="" (
   echo You must supply the name of an example to build.
   set RET=exit
   goto :EOF
)
if "%COHERENCE_CPP_HOME%"=="" (
   echo COHERENCE_CPP_HOME is not set!
   echo set COHERENCE_CPP_HOME to a Coherence C++ installation.
   set RET=exit
   goto :EOF
)

rem remove any double quotes in the environment variables

set COHERENCE_CPP_HOME=!COHERENCE_CPP_HOME:"=!
