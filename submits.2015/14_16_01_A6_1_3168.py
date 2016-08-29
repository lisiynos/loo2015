import sys
import math
sys.stdin = open('hall.in')
sys.stdout = open('hall.out', 'w')
ar = []
sum = 0
a, b, c, d = [int(i) for i in input().split()]
for i in range(1, math.floor(math.sqrt(b))+1):
    sqlow = math.ceil(a/i); 
    sqhigh = math.floor(b/i);
    #//write(sqlow, ' ', sqhigh);
    for j in range(sqlow, sqhigh+1):
        p = (j+i)*2
        if (p >= c) and (p <= d):
            if not (i, j) in ar:
                ar.append((j, i));
                sum += 1
print(sum)