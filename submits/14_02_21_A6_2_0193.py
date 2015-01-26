import sys
import math
sys.stdin = open('prizes.in')
sys.stdout = open('prizes.out', 'w')
n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
s = dict()
y = dict()
for i in range(n-k):
    p = sum(a[i:i+k])
    s[i] = p
    if p in y:
        y[p] += [i]
    else:
        y[p] = [i]
print(p, s, y)

z = list(s.values())
m = sorted(z, reverse = True)
l = m[0]
if max(y[l]) - min(y[l]) >=7:
    print(l)
else:
    r = sorted(z[y[l][0]-k+1:y[l][0]+k])
    for i in r:
        if y[i][0] + 2*k >= n-1:
            print(i,  max(z[:y[i][0]-k+1]))
            if i >= max(z[:y[i][0]-k+1]):
                print(i)
                break
        elif y[i][0]-k+1 <= 0:
            print(i,  max(z[y[i][0]+k:]))
            if i >= max(z[y[i][0]+k:]):
                print(i)
                break
        else:
            print(i, max(z[:y[i][0]-k+1]), max(z[y[i][0]+k:]))
            if i >= max(max(z[:y[i][0]-k+1]), max(z[y[i][0]+k:])):
                print(i)
                break
                    