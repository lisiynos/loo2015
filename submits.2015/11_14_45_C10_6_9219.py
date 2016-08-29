a,k,b,m,x = list(map(int, open('forest.in').read().split()))

if(k>x and m>x):# always working
        day = x/(a+b)
        if(x % (a+b) != 0)
            day+=1
        print(day, file=open('forest.out', 'w'))
        exit()
for day in range(1,10000000000):
    if x<=0:
        print(day-1, file=open('forest.out', 'w'))
        exit()
    if day % k != 0:
        x-=a
    if day % m != 0:
        x-=b
        
