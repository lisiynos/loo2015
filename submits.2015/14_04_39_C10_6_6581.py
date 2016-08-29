a,k,b,m,x = list(map(int, open('forest.in').read().split()))

if 1:
  for day in range(1,10000000000): # (<O(n)
    if x<=0:
        print(int(day-1), file=open('forest.out', 'w'))
        exit()
    if day % k != 0:
        x-=a
    if day % m != 0:
        x-=b
        