#
# Author: Sergey Kopeliovich (Burunduk30@gmail.com)
# Date: 2013.11.15
#
# Comment: O(n^{2/3})
#

import sys

NAME = "sweets"

inf = open(NAME + ".in", "r")
out = open(NAME + ".out", "w")

n, a, b, c = list(map(int, inf.readline().split()))

x0 = n // (3 * a)
y0 = n // (3 * b)
z0 = n // (3 * c)
best, rx, ry, rz = x0 * y0 * z0, x0, y0, z0
for M in [10, 100, 3000]:
  mx = n // a
  for x in range(max(1, x0 - M), min(mx, x0 + M) + 1):
    my = (n - x * a) // b
    ax = a * x
    if (best >= ax * (((n - ax) / 2) ** 2)):
      continue
    for y in range(max(1, y0 - M), min(my, y0 + M) + 1):
      z = (n - a * x - b * y) // c
      tmp = x * y * z
      if (tmp - best > 0):
        best, rx, ry, rz = tmp, x, y, z

print(rx * a, ry * b, rz * c, file=out)

inf.close()
out.close()
