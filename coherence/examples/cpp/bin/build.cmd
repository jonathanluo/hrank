@echo off
setlocal enabledelayedexpansion

set EXAMPLE=%1
set MODE=%2

set EXAMPLES_DIR=%~dp0..

call set_env
if defined RET (
    goto %RET%
    )

if "%INCLUDE%"=="" (
   echo This command must be executed from a Visual Studio command prompt.
)

set POF_OUT_DIR=%EXAMPLES_DIR%\pof\out

call %EXAMPLES_DIR%\bin\build_pof.cmd %MODE%

SET EXAMPLES_OUT_DIR=%EXAMPLES_DIR%\%EXAMPLE%\out

if exist %POF_OUT_DIR% (
   rd /s /q %EXAMPLES_OUT_DIR%
   mkdir %EXAMPLES_OUT_DIR%
) else (
   mkdir %EXAMPLES_OUT_DIR%
)

cd %EXAMPLES_OUT_DIR%
 
set OPT=/D "WIN32" /D "_CRT_SECURE_NO_WARNINGS" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /FD /EHsc /c 
set LOPT=/NOLOGO /SUBSYSTEM:CONSOLE /INCREMENTAL:NO
set INC=/I "%EXAMPLES_DIR%" /I "%COHERENCE_CPP_HOME%\include"
set SRC=%EXAMPLES_DIR%\%EXAMPLE%\*.cpp
set OUT=%EXAMPLES_OUT_DIR%\%EXAMPLE%.exe
set LIB="%COHERENCE_CPP_HOME%\lib";%POF_OUT_DIR%\;%LIB% 

set LIBS=kernel32.lib coherence.lib pof.lib

if "%MODE%"=="debug" (
    set OPT=%OPT% /Zi /MDd
  ) else (
    set OPT=%OPT% /O2 /MD
  )

if "%EXAMPLE%"=="console" (
    echo The console is an embedded application; no compilation is necessary.
  ) else (
    echo building %OUT% ...
    cl %OPT% %INC% %SRC%
    link %LOPT% %LIBS% *.obj /OUT:%OUT%
    @rem Add manifest to binary for VC++ 2008 and earlier
    if exist %OUT%.manifest mt -manifest %OUT%.manifest -outputresource:%OUT%;1

    del *.obj
  )

echo To run this example execute 'bin\run %EXAMPLE%'

:exit
