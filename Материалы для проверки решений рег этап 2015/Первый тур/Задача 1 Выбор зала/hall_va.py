from math import *

input = open('hall.in', 'r')
output = open('hall.out', 'w')

a, b, c, d = [int(x) for x in input.readline().split()]

ans = 0
for x in range(1, int(sqrt(b)) + 1):
	l = max((a + x - 1) // x, (c + 1) // 2 - x, x)
	r = min(b // x, d // 2 - x)
	ans += max(r - l + 1, 0)

output.write(str(ans))