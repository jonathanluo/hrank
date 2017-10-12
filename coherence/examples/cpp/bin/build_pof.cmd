@echo off
setlocal enabledelayedexpansion

set EXAMPLES_DIR=%~dp0..

set MODE=%1
call set_env
if defined RET (
    goto %RET%
    )

if "%INCLUDE%"=="" (
    echo This command must be executed from a Visual Studio command prompt.
    goto exit
  )

set POF_OUT_DIR=%EXAMPLES_DIR%\pof\out
set OPT=/FD /EHsc  /W3 /nologo /c /Zi /TP /DWIN32 /DPOF_EXPORTS /D_USRDLL /D_WINDOWS /D_CRT_SECURE_NO_WARNINGS  /D "_WINDLL" /D "_MBCS"
set LOPT=/DLL /MANIFEST /SUBSYSTEM:WINDOWS /OPT:REF /OPT:ICF /IMPLIB:"%POF_OUT_DIR%\pof.lib"
set INC=/I"%EXAMPLES_DIR%" /I"%COHERENCE_CPP_HOME%/include" /I.
set SRC=%EXAMPLES_DIR%\pof\*.cpp
set OUT=%POF_OUT_DIR%\pof.dll
set LIB="%COHERENCE_CPP_HOME%\lib";%LIB%;

if exist %POF_OUT_DIR% (
   rd /s /q %POF_OUT_DIR%
   mkdir %POF_OUT_DIR%
) else (
   mkdir %POF_OUT_DIR%
)

cd %POF_OUT_DIR%
 
set LIBS=kernel32.lib coherence.lib
 
if "%MODE%"=="debug" (
    set OPT=%OPT% /MTd
  ) else (
    set OPT=%OPT% /O2 /MT
  )

 echo building %POF_OUT_DIR% ...
 cl %OPT% %INC% %SRC%
 link %LOPT% %LIBS% *.obj /OUT:%OUT%

 @rem Add manifest to binary for VC++ 2008 and earlier
 if exist %OUT%.manifest mt -manifest %OUT%.manifest -outputresource:%OUT%;1

 del %POF_OUT_DIR%\*.obj

:exit
