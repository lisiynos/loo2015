import sys
import math
sys.stdin = open('tiling.in')
sys.stdout = open('tiling.out', 'w')
n , k = [int(i) for i in input().split()]
res = 2
for i in range(2, n+1):
    res = res*3+1
print(res)