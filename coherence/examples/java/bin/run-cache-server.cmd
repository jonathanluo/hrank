@echo off
setlocal enabledelayedexpansion

set EXAMPLES_DIR=%~dp0..
set SCRIPT_NAME=%0
set EXAMPLE_PATH_BEGIN=com\tangosol\examples
set COHERENCE_HOME=%EXAMPLES_DIR%\..\..
set EXAMPLE=%1
set CLuster=%2

call %EXAMPLES_DIR%\bin\set_env SCRIPT_NAME
if defined RET (
    goto %RET%
    )

if "%EXAMPLE%"=="federation" (

    rem set the correct keystore for the cluster
    if "%SSL%"=="true" (
      set SSL_CONFIG=-Didentity.manager=file:%CLUSTER%-keystore.jks
      goto :select
    )

:select
    if "%CLUSTER%"=="ClusterA" (
        set COH_OPTS=%COH_OPTS% -Dcoherence.clusterport=11100 -Dcoherence.cluster=ClusterA %SSL_CONFIG%
    	goto :run
        )

    if "%CLUSTER%"=="ClusterB" (
        set COH_OPTS=%COH_OPTS% -Dcoherence.clusterport=11200 -Dcoherence.cluster=ClusterB %SSL_CONFIG%
     	goto :run
        )

    echo Please specify the cluster name of federation cluster ClusterA or ClusterB
    goto :exit
    )

:run
"%JAVA_HOME%"\bin\java %COH_OPTS% -Xms512m -Xmx512m com.tangosol.net.DefaultCacheServer %3 %4 %5 %6 %7 %8

:exit
