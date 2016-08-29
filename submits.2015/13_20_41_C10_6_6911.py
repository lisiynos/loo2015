from math import ceil
a,k,b,m,x = list(map(int, open('forest.in').read().split()))

if(k>x and m>x):# always working
        day = x/(a+b)
        if(x % (a+b) != 0):
            day+=1
        print(day, file=open('forest.out', 'w'))
        exit()
if(k == m):
    day = x/(a+b)+ceil(x/k)-1
    print(day, file=open('forest.out', 'w'))
    exit()

otd1 = ceil(x/k)-1
otd2 = ceil(x/m)-1
day = x/(a+b) + ceil(otd1/2+otd2/2)
print(day, file=open('forest.out', 'w'))
