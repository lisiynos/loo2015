@echo off

echo Compiling checker
dcc32 -cc -U..\..\..\lib check.dpr

echo Compiling validator
g++ -O2  -I..\..\..\lib -o validate.exe validate.cpp

echo Generating tests
if exist tests rd /s /q tests
pushd src
call doall.cmd
popd

echo Compiling main solution
pushd main
g++ -O2  -Wall -Wextra -Wconversion -I..\..\..\lib -o ..\alligator_ni.exe alligator_ni.cpp
popd

echo Generating answers
for %%i in (preliminary, tests\subtask1, tests\subtask2, tests\subtask3) do (
    for %%j in (%%i\??) do (
        echo Copying input for test %%j
        copy %%j alligator.in > nul

        echo Validating test %%j
        validate < alligator.in
        if errorlevel 1 (
            echo Validator rejects test %%j
            goto end
        )
        echo Validator accepts test %%j

        echo Running solution on test %%j
        alligator_ni.exe
        if errorlevel 1 (
            echo Solution failed on test %%j
            goto end
        )

        echo Running checker on test %%j
        check %%j alligator.out alligator.out
        if errorlevel 1 (
            echo Checker rejects main solution output on test %%j
            goto end
        )

        echo Saving answer for test %%j
        copy alligator.out %%j.a > nul
    )
)


:end