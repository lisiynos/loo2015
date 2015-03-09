@echo off

SET PATH=C:\Python34;C:\CodeBlocks\MinGW\bin;%PATH%

echo Compiling checker
dcc32 -U..\..\lib -cc check.dpr

echo Compiling validator
for %%i in (Validate, ValidateSubtask1, ValidateSubtask2, ValidateSubtask3, ValidateSubtask4) do (
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
javac TransformTestGen.java
java -ea -Xmx256M -Xss64M TransformTestGen
popd

echo Compiling main solution
pushd main
g++ -O2  -Wconversion -I..\..\..\lib -o ..\transform_av.exe transform_av.cpp
popd

echo Generating answers
for %%i in (preliminary, tests\subtask1, tests\subtask2, tests\subtask3, tests\subtask4) do (
    for %%j in (%%i\??) do (
        echo Copying input for test %%j
        copy %%j transform.in > nul

        echo Validating test %%j
        java -jar Validate.jar < transform.in
        if errorlevel 1 (
            echo Validator rejects test %%j
            goto end
        )
        if [%%i]==[tests\subtask1] (
            java -jar ValidateSubtask1.jar < transform.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        if [%%i]==[tests\subtask2] (
            java -jar ValidateSubtask2.jar < transform.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        if [%%i]==[tests\subtask3] (
            java -jar ValidateSubtask3.jar < transform.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        if [%%i]==[tests\subtask4] (
            java -jar ValidateSubtask4.jar < transform.in
            if errorlevel 1 (
                echo Validator rejects test %%j
                goto end
            )
        )
        echo Validator accepts test %%j

        echo Running solution on test %%j
        transform_av.exe
        if errorlevel 1 (
            echo Solution failed on test %%j
            goto end
        )

        echo Running checker on test %%j
        check %%j transform.out transform.out
        if errorlevel 1 (
            echo Checker rejects main solution output on test %%j
            goto end
        )

        echo Saving answer for test %%j
        copy transform.out %%j.a > nul
    )
    move %%i\* tests
    rmdir %%i
)

echo Copy checker to tests
copy check.* tests
copy task.cfg tests

:end