a,k,b,m,x = list(map(int, open('forest.in').read().split()))
f = x

if x < k and x < m:
    for day in range(1,100000000):
        if x<=0:
            print(day-1, file=open('forest.out', 'w'))
            exit()
        x-=a-b
        
if k == m:
    for day in range(1,100000000):
        if x<=0:
            print(day-1, file=open('forest.out', 'w'))
            exit()
        if day % k != 0
            x-=a-b

for day in range(1,100000000):
    if x<=0:
        print(day-1, file=open('forest.out', 'w'))
        exit()
    if day % k != 0:
        x-=a
    if day % m != 0:
        x-=b
