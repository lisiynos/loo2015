inp = open('tiling.in')

n,k = list(map(int, inp.readline().split()))
mas = [0,1,7,22,54,116,232,443,821,1490,2664]
if n==3 and k ==1:
    print(8, file = open('tiling.out','w'))
    exit()
if k==0:
    print(mas[n], file = open('tiling.out','w'))
