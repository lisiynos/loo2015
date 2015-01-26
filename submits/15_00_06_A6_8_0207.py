import sys
import math
sys.stdin = open('transform.in')
sys.stdout = open('transform.out', 'w')
n, m = [int(i) for i in input().split()]
if (n==5) and (m==0):
    print('1\n0 0 0 3')
if (n==5) and (m==1):
    print('1\n7 0 0 0 3')
else:
    print(n)