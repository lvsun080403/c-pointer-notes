@echo off
setlocal enabledelayedexpansion
chcp 65001 >nul

REM build.bat [plain|commented] [gcc|clang|tcc]
REM Compiles every .c in the chosen folder into build\ and reports a summary.
REM Output is ASCII on purpose: cmd code pages mangle Chinese text.

set "SRCDIR=%~1"
if "%SRCDIR%"=="" set "SRCDIR=plain"
set "WANTED=%~2"

if not exist "%SRCDIR%" (
  echo [error] source folder "%SRCDIR%" not found.
  echo         usage: build.bat [plain^|commented] [gcc^|clang^|tcc]
  exit /b 1
)

set "CC="
if /i "%WANTED%"=="gcc"   set "CC=gcc"
if /i "%WANTED%"=="clang" set "CC=clang"
if /i "%WANTED%"=="tcc"   set "CC=tcc"

if not defined CC (
  for %%C in (gcc clang tcc) do (
    if not defined CC (
      where %%C >nul 2>nul && set "CC=%%C"
    )
  )
)

if not defined CC (
  echo [error] no C compiler found on PATH.
  echo         install one of: MinGW-w64 ^(gcc^), LLVM ^(clang^), TinyCC ^(tcc^)
  echo         or run from a Visual Studio developer prompt and use cl manually.
  exit /b 1
)

echo [info] compiler: %CC%
echo [info] source:   %SRCDIR%\
echo.

if not exist build mkdir build

set /a OK=0
set /a FAIL=0

for %%F in ("%SRCDIR%\*.c") do (
  set "NAME=%%~nF"
  if /i "%CC%"=="tcc" (
    %CC% -o "build\!NAME!.exe" "%%~fF" >nul 2>nul
  ) else (
    %CC% -Wall -Wextra -std=c89 -o "build\!NAME!.exe" "%%~fF" 2>nul
  )
  if exist "build\!NAME!.exe" (
    echo   [ok]   %%~nxF
    set /a OK+=1
  ) else (
    echo   [FAIL] %%~nxF
    set /a FAIL+=1
  )
)

echo.
echo [done] ok=%OK% fail=%FAIL%

if %FAIL% GTR 0 exit /b 1
exit /b 0
