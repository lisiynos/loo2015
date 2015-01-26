from math import ceil
a,k,b,m,x = list(map(int, open('forest.in').read().split()))

if(k>x and m>x):# always working (O(1))
        day = x/(a+b)
        if(x % (a+b) != 0):
            day+=1
        print(ceil(day), file=open('forest.out', 'w'))
else:
  for day in range(1,10000000000): # (<O(n)
    if x<=0:
        print(int(day-1), file=open('forest.out', 'w'))
        exit()
    if day % k != 0:
        x-=a
    if day % m != 0:
        x-=b
        
