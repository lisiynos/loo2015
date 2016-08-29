inp = open("tiling.in")
outp = open("tiling.out",'w')
n = 1
tmp = 1
x,k=list(map(int, inp.readline().split()))
if(k == 0):
    for i in range(x):
        n += tmp
        tmp *= (x-i)
if(n%2==0):
    n = n*2 - 1;
else:
    n*=2
print(n, file = outp)
