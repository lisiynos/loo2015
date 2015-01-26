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

otd1 = int(x/k)
otd2 = int(x/m)
day = int(x/(a+b) + int(otd1/2+otd2/2)+1)
print(day, file=open('forest.out', 'w'))
print(day)
