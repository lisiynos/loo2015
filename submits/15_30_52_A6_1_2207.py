import sys
import math
sys.stdin = open('hall.in')
sys.stdout = open('hall.out', 'w')
ar = []
sum = 0
a, b, c, d = [int(i) for i in input().split()]
for i in range(1, math.ceil(math.sqrt(b))):
    for j in range(1, math.ceil(math.sqrt(b))):
        if i*j > a and i*j < b and (i+j)*2 > c and (i+j) < d:
            sum += 1
print(sum)