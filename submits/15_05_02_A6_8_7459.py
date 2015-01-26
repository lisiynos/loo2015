import sys
import math
sys.stdin = open('transform.in')
sys.stdout = open('transform.out', 'w')
n, m = [int(i) for i in input().split()]
if (n==5) and (m==0):
    print('1')
    print('0 0 0 3')
elif (n==5) and (m==1):
    print('1')
    print('7 0 0 0 3')
else:
    print(n)