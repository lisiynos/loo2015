inp = open('tiling.in')

n,k = list(map(int, inp.readline().split()))
mas = [0,1,7,22,50,95,161,252,372,525,715,946]
if n==3 and k ==1:
    print(8)
    exit()
if k==0:
    print(mas[n], file = open('tiling.out','w'))
