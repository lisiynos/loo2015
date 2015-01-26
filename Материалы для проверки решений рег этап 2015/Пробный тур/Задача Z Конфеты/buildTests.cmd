@echo off

echo Compiling checker
g++ -O2 -o check.exe -I..\..\..\lib check.cpp

echo Compiling validator
g++ -O2  -I..\..\..\lib -o validate.exe validate.cpp

echo Generating tests
if exist preliminary rd /s /q preliminary
if exist tests rd /s /q tests
pushd src
python gen_preliminary_tests.py
python gen_tests.py
popd

echo Compiling main solution
pushd main
g++ -O2  -Wall -Wextra -Wconversion -Werror -I..\..\..\lib -o ..\sweets_sk.exe sweets_sk.cpp
popd

echo Generating answers
for %%i in (preliminary, tests\subtask1, tests\subtask2, tests\subtask3, tests\subtask4) do (
    for %%j in (%%i\??) do (
        echo Copying input for test %%j
        copy %%j sweets.in > nul

        echo Validating test %%j
        validate < sweets.in
        if errorlevel 1 (
            echo Validator rejects test %%j
            goto end
        )
        echo Validator accepts test %%j

        echo Running solution on test %%j
        sweets_sk.exe
        if errorlevel 1 (
            echo Solution failed on test %%j
            goto end
        )

        echo Running checker on test %%j
        check %%j sweets.out sweets.out
        if errorlevel 1 (
            echo Checker rejects main solution output on test %%j
            goto end
        )

        echo Saving answer for test %%j
        copy sweets.out %%j.a > nul
    )
)


:end