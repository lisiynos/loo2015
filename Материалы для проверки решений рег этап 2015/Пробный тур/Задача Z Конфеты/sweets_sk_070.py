#
# Author: Sergey Kopeliovich (Burunduk30@gmail.com)
# Date: 2013.11.15
#

import sys

NAME = "sweets"

inf = open(NAME + ".in", "r")
out = open(NAME + ".out", "w")

n, a, b, c = list(map(int, inf.readline().split()))

best = 0
rx, ry, rz = 0, 0, 0
x0 = n // (3 * a)
y0 = n // (3 * b)
mx = n // a
M = 3000

for x in range(max(1, x0 - M), min(mx, x0 + M) + 1):
  my = (n - x * a) // b
  for y in range(max(1, y0 - M), min(my, y0 + M) + 1):
    z = (n - a * x - b * y) // c
    tmp = x * y * z
    if (tmp - best > 0):
      best, rx, ry, rz = tmp, x, y, z

print(rx * a, ry * b, rz * c, file=out)

inf.close()
out.close()
