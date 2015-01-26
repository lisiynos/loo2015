#
# Author: Sergey Kopeliovich (Burunduk30@gmail.com)
# Date: 2013.11.15
#
# Comment: O(1), try only +-8, no overflow
#

import sys

NAME = "sweets"

inf = open(NAME + ".in", "r")
out = open(NAME + ".out", "w")

n, a, b, c = list(map(int, inf.readline().split()))

x0 = n // (3 * a)
y0 = n // (3 * b)
z0 = n // (3 * c)
best = x0 * y0 * z0
rx, ry, rz = x0, y0, z0
M = 8
r = range(-M, M + 1)
for dx in r: 
  for dy in r:
    for dz in r:
      x, y, z = x0 + dx, y0 + dy, z0 + dz
      if ((1 <= x) and (1 <= y) and (1 <= z) and (a * x + b * y + c * z <= n)):
        tmp = x * y * z
        if (tmp > best):
          best, rx, ry, rz = tmp, x, y, z

print(rx * a, ry * b, rz * c, file=out)

inf.close()
out.close()
