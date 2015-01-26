#!/bin/bash

i=0
[ -e forest_as.py ] || ln -s ../forest_as.py .
[ -e forest_ak_35.cpp ] || ln -s ../forest_ak_35.cpp .
[ forest_ak_35.cpp -nt forest_ak_35 ] && g++ forest_ak_35.cpp -O2 -Wall -o forest_ak_35
[ -e forest_ak_35_no_moduli.cpp ] || ln -s ../forest_ak_35_no_moduli.cpp .
[ forest_ak_35_no_moduli.cpp -nt no_moduli ] && g++ forest_ak_35_no_moduli.cpp -O2 -Wall -o no_moduli 
[ -e forest_ak.cpp ] || ln -s ../forest_ak.cpp .
[ forest_ak.cpp -nt forest_ak ] && g++ forest_ak.cpp -O2 -Wall -o forest_ak
[ -e forest_ak_wa_3.cpp ] || ln -s ../forest_ak_wa_3.cpp .
[ forest_ak_wa_3.cpp -nt wa3 ] && g++ forest_ak_wa_3.cpp -O2 -Wall -o wa3

RUN1=./wa3
RUN2=./forest_ak

while true
do
    python gen.py > forest.in
    $RUN1
    mv forest.out{,2}
    $RUN2
    diff forest.out{,2} || break
    let i=$i+1
    echo -ne [$i]
done
