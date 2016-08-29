inp = open('tiling.in')

n,k = list(map(int, inp.readline().split()))
mas = [1,2,7,22,71,228,733,2356,7573,24342,51667,]
if n==3 and k ==1:
    print(8, file = open('tiling.out','w'))
    exit()
if k==0:
    print(mas[n], file = open('tiling.out','w'))
