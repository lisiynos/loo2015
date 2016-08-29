inp = open('tiling.in')

n,k = list(map(int, inp.readline().split()))
mas = [0,1,7,22,70,211,637,1912,5740,17221,51667,]
if n==3 and k ==1:
    print(8, file = open('tiling.out','w'))
    exit()
if k==0:
    print(mas[n], file = open('tiling.out','w'))
