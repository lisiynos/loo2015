a,k,b,m,x = list(map(int, open('forest.in').read().split()))

for day in range(1,10000000000):
    if x<=0:
        print(day-1, file=open('forest.out', 'w'))
        exit()
    if day % k != 0:
        x-=a
    if day % m != 0:
        x-=b
        
