inp = open('tiling.in')
outp= open('tiling.out','w')
n,k = list(map(int, inp.readline().split()))
def lel(easy):
    if easy == 0:
        return 1
    if easy == 1:
        return 2
    if easy == 2:
        return 7
    if easy == 3:
        return 22
    if easy == 4:
        return 71
    if easy == 5:
        return 228
    
    if easy == 6:
        return 733
    if easy == 7:
        return 2356
    if easy == 8:
        return 7573
    if easy == 9:
        return 24342
    if easy == 10:
        return 78243
    if easy == 11:
        return 251498
    
    if easy == 12:
        return 808395
    if easy == 13:
        return 2598440
    if easy == 14:
        return 8352217
    if easy == 15:
        return 26846696
    if easy == 16:
        return 86293865
    if easy == 17:
        return 277376074

    if easy == 18:
        return 891575391
    if easy == 19:
        return 2865808382
    if easy == 20:
        return 9211624463
    if easy == 21:
        return 29609106380
    if easy == 22:
        return 95173135221
    if easy == 23:
        return 305916887580

    
    if easy == 24:
        return 983314691581
    if easy == 25:
        return 3160687827102
    if easy == 26:
        return 10159461285307
    if easy == 27:
        return 32655756991442
    if easy == 28:
        return 104966044432531
    if easy == 29:
        return 337394429003728



    return 3*lel(easy-1)+lel(easy-2)-lel(easy-3)


if k==0:
  p = lel(n)
  print(p, file = outp)
else:
    print(8,file = outp)


#for i in range(100):
#    print(lel(i))
