@echo off

for %%i in (.) do set problem=%%~ni

set author=%1

rem set problem=prescription

if "%1" == "" (
  echo No parameters
  goto End
)

set exec = echo No execution command

echo Compiling solution
if EXIST %problem%_%author%.dpr (
dcc32 -cc %problem%_%author%.dpr || goto CompSourceError
set exec=run  -m 256M %problem%_%author%.exe
)
if EXIST %problem%_%author%.cpp (
g++ %problem%_%author%.cpp -O2 -Wall -Wl,--stack=67108864 -o %problem%_%author%.exe || goto CompSourceError
set exec=run -m 256M %problem%_%author%.exe
)
if EXIST %problem%_%author%.java (
javac %problem%_%author%.java -encoding utf8 || goto CompSourceError
set exec=run -t 2 -m 256M -t 4s java -ea -Xss64M -Xmx256M %problem%_%author%
)
if EXIST %problem%_%author%.py (
set exec=run -m 256M python %problem%_%author%.py
)
                               
echo Checking solution...

echo %date% %time% > result_%problem%_%author%.log

for %%s in (preliminary, tests, tests\subtask1, tests\subtask2, tests\subtask3) do (
    for %%i in (%%s\??) do (
        del %problem%.out
        echo running on test %%i
        copy %%i %problem%.in > nul

        %exec%
        
        check %%i %problem%.out %%i.a
        if errorlevel 1 (
            echo %%i failed >> result_%problem%_%author%.log    
        ) else (
            echo %%i ok >> result_%problem%_%author%.log
        )
    )
)

goto End

:CompSourcesError
  echo Cannot compile source
  goto End
:SourceRunningError
  echo Fail in running on tests

:End
    