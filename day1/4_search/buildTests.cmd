@echo off

echo Compiling checker
dcc32 -U..\..\lib -cc check.dpr

echo Compiling validator
for %%i in (Validate, ValidateSubtask1, ValidateSubtask2, ValidateSubtask3) do (
    rmdir /S /Q __tmp 2> nul
    mkdir __tmp
    javac -sourcepath . -d __tmp %%i.java
    pushd __tmp
    mkdir META-INF
    echo Main-Class: %%i> META-INF/manifest.1
    call jar cfm %%i.jar META-INF/manifest.1 *.class
    copy /Y %%i.jar .. > nul
    popd
    rmdir /S /Q __tmp
)

echo Generating tests
if exist preliminary rd /s /q preliminary
if exist tests rd /s /q tests
pushd src
javac Gen.java
java -ea -Xmx256M -Xss64M Gen
popd

echo Compiling main solution
pushd main
g++ -O2  -Wall -Wextra -Wconversion -Werror -I..\..\..\lib -o ..\search_nv.exe search_nv.cpp
popd

echo Generating answers
for %%i in (preliminary, tests\subtask1, tests\subtask2, tests\subtask3) do (
    for %%j in (%%i\??) do (
        echo Copying input for test %%j
        copy %%j search.in > nul

        echo Validating test %%j
        java -jar Validate.jar < search.in
        if errorlevel 1 (
            echo Validator rejects test %%j
            goto end
        )
        if [%%i]==[tests\subtask1] (
            java -jar ValidateSubtask1.jar < search.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        if [%%i]==[tests\subtask2] (
            java -jar ValidateSubtask2.jar < search.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        if [%%i]==[tests\subtask3] (
            java -jar ValidateSubtask3.jar < search.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        echo Validator accepts test %%j

        echo Running solution on test %%j
        search_nv.exe
        if errorlevel 1 (
            echo Solution failed on test %%j
            goto end
        )

        echo Running checker on test %%j
        check %%j search.out search.out
        if errorlevel 1 (
            echo Checker rejects main solution output on test %%j
            goto end
        )

        echo Saving answer for test %%j
        copy search.out %%j.a > nul
    )
)


:end