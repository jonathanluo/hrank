if not defined COHERENCE_HOME (
    echo COHERENCE_HOME is not set!
    echo set COHERENCE_HOME to a Coherence 12.2.1.1 or later installation.
    set RET=exit
    goto :EOF
  )

if not defined JAVA_HOME (
    echo JAVA_HOME is not set!
    echo set JAVA_HOME to a JDK 1.8 or greater installation.
    set RET=exit
    goto :EOF
  )

rem remove any double quotes in the environment variables

set COHERENCE_HOME=!COHERENCE_HOME:"=!
set JAVA_HOME=!JAVA_HOME:"=!

set CLASSES_DIR=%EXAMPLES_DIR%\classes
set EXAMPLE_PATH=%EXAMPLE_PATH_BEGIN%\%EXAMPLE%
set EXAMPLE_CONFIG_DIR=%EXAMPLES_DIR%\resource\%EXAMPLE%
set POF_PATH=%EXAMPLE_PATH_BEGIN%\pof
set CONFIG_DIR=%EXAMPLES_DIR%\resource\config

rem Check if SSL Enabled for federation example
if /I "%EXAMPLE%"=="federation" (
   if defined SSL (
       set SUFFIX=-ssl
   )
)

rem run script uses client config (if available) but run-proxy and run-cache-server do not
if	/I [%SCRIPT_NAME%] == [bin\run]  (
   if exist %EXAMPLE_CONFIG_DIR%\client-cache-config.xml (
       set CACHE_CONFIG_FILE_NAME=client-cache-config.xml
   ) else (
   set CACHE_CONFIG_FILE_NAME=examples-cache-config%SUFFIX%.xml
   )
   ) else (
   set CACHE_CONFIG_FILE_NAME=examples-cache-config%SUFFIX%.xml
   )

rem if config is found in examples resource directory, use it instead of basic config
if exist %EXAMPLE_CONFIG_DIR%\%CACHE_CONFIG_FILE_NAME% (
    set CACHE_CONFIG=%EXAMPLE_CONFIG_DIR%\%CACHE_CONFIG_FILE_NAME%
    ) else (
    set CACHE_CONFIG=%CONFIG_DIR%\%CACHE_CONFIG_FILE_NAME%
    )

set CP="%EXAMPLE_CONFIG_DIR%;%CONFIG_DIR%;%COHERENCE_HOME%"\lib\coherence.jar;%COHERENCE_HOME%\lib\jline.jar;%CLASSES_DIR%

set COH_OPTS=%COH_OPTS% -cp %CP%
set COH_OPTS=%COH_OPTS% -Dcoherence.cacheconfig=%CACHE_CONFIG%
rem using non-default port to prevent accidentally joining other clusters
set COH_OPTS=%COH_OPTS% -Djava.net.preferIPv4Stack=true -Dcoherence.wka=127.0.0.1 -Dcoherence.clusterport=5555 -Dcoherence.distributed.persistence.base.dir=%EXAMPLES_DIR%\persistence-data
