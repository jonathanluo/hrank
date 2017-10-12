@echo off
setlocal enabledelayedexpansion

set EXAMPLE=%1

set EXAMPLES_DIR=%~dp0\..

call set_env
if defined RET (
    goto %RET%
    )

set POF_OUT_DIR=%EXAMPLES_DIR%\pof\out\

set EXEC==%EXAMPLES_DIR%\%EXAMPLE%\out\%EXAMPLE%
set CONFIG=%EXAMPLES_DIR%\config

set PATH=%POF_OUT_DIR%;%COHERENCE_CPP_HOME%\lib;%PATH%

set CACHE_CONFIG_FILE_NAME=examples-extend-cache-config.xml

rem if config is found in examples resource directory, use it instead of basic config
if exist %CONFIG%\%EXAMPLE%\%CACHE_CONFIG_FILE_NAME% (
    set CACHE_CONFIG=%CONFIG%\%EXAMPLE%\%CACHE_CONFIG_FILE_NAME%
    ) else (
    set CACHE_CONFIG=%CONFIG%\%CACHE_CONFIG_FILE_NAME%
    )
set coherence.cacheconfig=%CACHE_CONFIG%

rem if the example has an override file, use it
if exist %CONFIG%\%EXAMPLE%\tangosol-coherence-override.xml (
    set coherence.override=%CONFIG%\%EXAMPLE%\tangosol-coherence-override.xml
    )

set coherence.log=%EXAMPLE%.log

echo redirecting Coherence logging to %coherence.log%...

if "%EXAMPLE%"=="console" (
   @rem the console is now embedded within the coherence shared library
   ..\bin\sanka -l coherence coherence::net::CacheFactory %2 %3 %4 %5 %6 %7 %8 %9
   goto exit
   )

if "%EXAMPLE%"=="sanka" (
   ..\bin\sanka %2 %3 %4 %5 %6 %7 %8 %9
   goto exit
   )

cd %~dp0
%EXEC% %2 %3 %4 %5 %6 %7 %8 %9

:exit
