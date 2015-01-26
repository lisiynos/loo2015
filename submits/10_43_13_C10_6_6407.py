a,k,b,m,x = list(map(int, open('forest.in').read().split()))

if x < k and x < m:
    for day in range(1,100000000):
        if x<=0:
            print(day-1, file=open('forest.out', 'w'))
            break
        x-=a-b
        
elif k == m:
    for day in range(1,100000000):
        if x<=0:
            print(day-1, file=open('forest.out', 'w'))
            break
        if day % k != 0:
            x-=a-b
else:
  for day in range(1,100000000):
    if x<=0:
        print(day-1, file=open('forest.out', 'w'))
        break
    if day % k != 0:
        x-=a
    if day % m != 0:
        x-=b
