import math
import sys
sys.stdin = open('river.in')
sys.stdout = open('river.out', 'w')
n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
m = int(input())
c = sum([i**2 for i in a])
print(c)
for i in range(m):
    l, b = [int(i) for i in input().split()]
    if l == 1:
        s = a.pop(b-1)
        if b == 1:
            c = c - s**2 - a[b-1]**2
            a[b-1] += s
            c = c + a[b-1]**2
        elif b == len(a)+1:
            c = c - s**2 - a[b-2]**2
            a[b-2] += s
            c = c + a[b-2]**2            
        else:
            c = c - s**2 - a[b-1]**2 - a[b-2]**2           
            a[b-2] += math.floor(s/2)
            a[b-1] += math.ceil(s/2)
            c = c + a[b-1]**2 + a[b-2]**2    
    else:
        s = a[b-1]
        c = c - s**2     
        a[b-1] = math.ceil (s/2)
        a.insert(b, math.floor(s/2)) 
        c = c + a[b-1]**2 + a[b]**2
    print(c)