@echo off

SET PATH=C:\Python34;C:\CodeBlocks\MinGW\bin;%PATH%

echo Compiling checker
dcc32 -U..\..\lib -cc check.dpr

echo Compiling validator
g++ -O2  -I..\..\..\lib -o validate.exe validate.cpp
g++ -O2  -I..\..\..\lib -o validate_subtask1.exe validate_subtask1.cpp
g++ -O2  -I..\..\..\lib -o validate_subtask2.exe validate_subtask2.cpp

echo Generating tests
if exist preliminary rd /s /q preliminary
if exist tests rd /s /q tests
pushd src
javac Tests.java
java -ea -Xmx256M -Xss64M Tests
popd

echo Compiling main solution
pushd main
g++ -O2  -Wall -Wextra -Wconversion -Werror -I..\..\..\lib -o ..\prizes_va.exe prizes_va.cpp
popd

echo Generating answers
for %%i in (preliminary, tests\subtask1, tests\subtask2, tests\subtask3) do (
    for %%j in (%%i\??) do (
        echo Copying input for test %%j
        copy %%j prizes.in > nul

        echo Validating test %%j
        validate < prizes.in
        if errorlevel 1 (
            echo Validator rejects test %%j
            goto end
        )
        if [%%i]==[tests\subtask1] (
            validate_subtask1 < prizes.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        if [%%i]==[tests\subtask2] (
            validate_subtask2 < prizes.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        echo Validator accepts test %%j

        echo Running solution on test %%j
        prizes_va.exe
        if errorlevel 1 (
            echo Solution failed on test %%j
            goto end
        )

        echo Running checker on test %%j
        check %%j prizes.out prizes.out
        if errorlevel 1 (
            echo Checker rejects main solution output on test %%j
            goto end
        )

        echo Saving answer for test %%j
        copy prizes.out %%j.a > nul
    )
    move %%i\* tests
    rmdir %%i
)

echo Copy checker to tests
copy check.* tests
copy task.cfg tests
<<<<<<< HEAD
copy prizes_va.cpp tests\solution.cpp
=======
copy main\prizes_va.cpp tests\solution.cpp
>>>>>>> 62541f2ad586be3d1495ddd6f7505d2fe472ad2d

:end