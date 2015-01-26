import sys
import math
sys.stdin = open('forest.in')
sys.stdout = open('forest.out', 'w')
a, k, b, m, x = [float(i) for i in input().split()]
l = math.floor((x*k*m)/(a*m*(k-1)+b*k*(m-1)))
for t in range(l-50, l+50):
    #print(t*a-math.floor(t/k)*a+t*b-math.floor(t/m)*b, x, t)
    if t*a-math.ceil(t/k)*a+t*b-math.ceil(t/m)*b >= x:
        print(t)
        break