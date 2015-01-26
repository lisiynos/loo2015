pushd ..
rmdir /s /y tests
mkdir tests
mkdir tests\subtask1
mkdir tests\subtask2
mkdir tests\subtask3
popd

g++ gen.cpp -o gen.exe
g++ genCorner.cpp -o genCorner.exe
g++ genFluffySpiral.cpp -o genFluffySpiral.exe
g++ genSpiral.cpp -o genSpiral.exe


rem 1 подзадача
rem
rem 01. пустое поле 1х1
rem 02. 1 баран на поле 1х1
rem 03. много пустого пространства вокруг баранов
rem 04. 4 барана образуют один простой цикл
rem 05. 3 бараны выходят по цепочке
rem 06. цикл и есть баран на пути цикла, который может уйти
rem 07. цикл и бараны, смотрящие на этот цикл со всех направлений
rem 08. цикл из 8 баранов и цепочка баранов, которые могут убежать
rem 09. 2 цикла. длины 2 и длины 4
rem 10-15. случайные тесты
rem 16-19. почти все бегут в одну сторону. и немногие перпендикулярно общему движению
rem 20. спираль
rem 21. спираль, где бараны смотрят по движению спирали и от центра

copy ??.hand ..\tests\subtask1\??     

gen     21      29      SNEW        11111   > ..\tests\subtask1\10
gen     30      4       SNEW.       22222   > ..\tests\subtask1\11
gen     1       26      SNEW.       33333   > ..\tests\subtask1\12
gen     17      27      SNEW        44444   > ..\tests\subtask1\13
gen     30      30      SNEW        55555   > ..\tests\subtask1\14
gen     30      30      SNEW.       66666   > ..\tests\subtask1\15

gen     30      30      SSSSSSSSSSSSEW      77777   > ..\tests\subtask1\16
gen     30      30      WWWWWWWWWWWWSN      88888   > ..\tests\subtask1\17
gen     30      30      EEEEEEEEEEEESN      99999   > ..\tests\subtask1\18
gen     30      30      NNNNNNNNNNNNEW      12121   > ..\tests\subtask1\19

genSpiral           29      29      1   13131   > ..\tests\subtask1\20
genFluffySpiral     29      29      0   14141   > ..\tests\subtask1\21


rem 2 подзадача
rem
rem 22-27. 2 направления движения
rem 28-29. спираль (по и против часовой стрелки)
rem 30-33. спираль, где бараны смотрят по движению спирали и от центра
rem 34-36. случайные тесты

gen     500     500     SW      15151   > ..\tests\subtask2\22
gen     500     500     SE      16161   > ..\tests\subtask2\23
gen     500     500     SN      17171   > ..\tests\subtask2\24
gen     500     500     NW      18181   > ..\tests\subtask2\25
gen     500     500     NE      19191   > ..\tests\subtask2\26
gen     500     500     EW      10101   > ..\tests\subtask2\27

genSpiral   500     500     0   > ..\tests\subtask2\28
genSpiral   500     500     1   > ..\tests\subtask2\29

genFluffySpiral     500     500     0   21212   > ..\tests\subtask2\30
genFluffySpiral     500     500     1   23232   > ..\tests\subtask2\31
genFluffySpiral     500     500     0   24242   > ..\tests\subtask2\32
genFluffySpiral     500     500     1   25252   > ..\tests\subtask2\33

gen     500     500     SNEW        26262   > ..\tests\subtask2\34
gen     500     500     SNEW        27272   > ..\tests\subtask2\35
gen     500     500     SNEW.       28282   > ..\tests\subtask2\36




rem 3 подзадача
rem
rem 37-42. 2 направления движения
rem 43-44. спираль (по и против часовой стрелки)
rem 45-48. спираль, где бараны смотрят по движению спирали и от центра
rem 49-51. случайные тесты

gen     2000        2000        SW      29292   > ..\tests\subtask3\37
gen     2000        2000        SE      20202   > ..\tests\subtask3\38
gen     2000        2000        SN      31313   > ..\tests\subtask3\39
gen     2000        2000        NW      32323   > ..\tests\subtask3\40
gen     2000        2000        NE      34343   > ..\tests\subtask3\41
gen     2000        2000        EW      35353   > ..\tests\subtask3\42

genSpiral   2000        2000        0   > ..\tests\subtask3\43
genSpiral   2000        2000        1   > ..\tests\subtask3\44

genFluffySpiral     2000        2000        0   36363   > ..\tests\subtask3\45
genFluffySpiral     2000        2000        1   37373   > ..\tests\subtask3\46
genFluffySpiral     2000        2000        0   38383   > ..\tests\subtask3\47
genFluffySpiral     2000        2000        1   39393   > ..\tests\subtask3\48

gen     2000        2000        SNEW        30303   > ..\tests\subtask3\49
gen     2000        2000        SNEW        41414   > ..\tests\subtask3\50
gen     2000        2000        SNEW.       42424   > ..\tests\subtask3\51
