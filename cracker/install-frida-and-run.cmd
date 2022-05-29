@echo off
@REM set PYTHON_DIR=C:\Python381
set DIRECTORY_ROOT=%cd%

set PYTHON_DIR=D:\Softwares\Portable Python-3.8.9 x64\App\Python
set PATH=%PYTHON_DIR%

python -m pip install --upgrade pip
python "%PYTHON_DIR%\Lib\site-packages\pip" install frida-tools

@REM cd %USERPROFILE%\Downloads\blackberry_simulator_7.0.0.579_9981
@REM python %USERPROFILE%/Downloads/frida-boilerplate/bb.py fledge.exe

cd /d ..\build
start predicate-cracking.exe
python "%DIRECTORY_ROOT%\bb.py" predicate-cracking.exe
pause
