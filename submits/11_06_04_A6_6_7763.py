import sys
import math
sys.stdin = open('forest.in')
sys.stdout = open('forest.out', 'w')
a, k, b, m, x = [float(i) for i in input().split()]
print(math.floor((x*k*m)/(a*m*(k-1)+b*k*(m-1))))