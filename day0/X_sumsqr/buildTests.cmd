@echo off

set path=C:\Python34;C:\Python33;%PATH%

echo Compiling checker
dcc32 -U..\..\lib -cc check.dpr

echo Compiling validator
g++ -O2  -I..\..\..\lib -o validate.exe validate.cpp
g++ -O2  -I..\..\..\lib -o validate_subtask1.exe validate_subtask1.cpp

echo Generating tests
if exist preliminary rd /s /q preliminary
if exist tests rd /s /q tests
pushd src
python TestGen.py
popd

echo Compiling main solution
pushd main
g++ -O2  -Wall -Wextra -Wconversion -Werror -I..\..\..\lib -o ..\sumsqr_as.exe sumsqr_as.cpp
popd

echo Generating answers
for %%i in (preliminary, tests\subtask1, tests\subtask2) do (
    for %%j in (%%i\??) do (
        echo Copying input for test %%j
        copy %%j sumsqr.in > nul

        echo Validating test %%j
        validate < sumsqr.in
        if errorlevel 1 (
            echo Validator rejects test %%j
            goto end
        )
        if [%%i]==[tests\subtask1] (
            validate_subtask1 < sumsqr.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        echo Validator accepts test %%j

        echo Running solution on test %%j
        sumsqr_as.exe
        if errorlevel 1 (
            echo Solution failed on test %%j
            goto end
        )

        echo Running checker on test %%j
        check %%j sumsqr.out sumsqr.out
        if errorlevel 1 (
            echo Checker rejects main solution output on test %%j
            goto end
        )

        echo Saving answer for test %%j
        copy sumsqr.out %%j.a > nul
    )
    move %%i\* tests
    rmdir %%i
)

echo Copy checker to tests
copy check.* tests

:end