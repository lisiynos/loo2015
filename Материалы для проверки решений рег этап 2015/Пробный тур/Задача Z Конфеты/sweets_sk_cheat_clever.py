#
# Author: Sergey Kopeliovich (Burunduk30@gmail.com)
# Date: 2013.11.15
#
# Comment: O(d^3), try only +-30, no overflow
#   looks at pair and gets the third value optimal possible
#

import sys

NAME = "sweets"

inf = open(NAME + ".in", "r")
out = open(NAME + ".out", "w")

n, a, b, c = list(map(int, inf.readline().split()))

def relax(x, y, z, tmp_shift):
  global best, shift, rx, ry, rz
  tmp = x * y * z
  if (tmp > best or (tmp == best and tmp_shift < shift)):
    best, rx, ry, rz, shift = tmp, x, y, z, tmp_shift
  
x0 = n // (3 * a)
y0 = n // (3 * b)
z0 = n // (3 * c)
best = x0 * y0 * z0
shift = 0
rx, ry, rz = x0, y0, z0
M = 30
r = range(-M, M + 1)
for dx in r: 
  for dy in r:
    for dz in r:
      x, y, z = x0 + dx, y0 + dy, z0 + dz
      if ((1 <= x) and (1 <= y) and (1 <= z)):
        if (a * x + b * y <= n): relax(x, y, (n - a * x - b * y) // c, max(abs(dx), abs(dy)))
        if (c * z + b * y <= n): relax((n - c * z - b * y) // a, y, z, max(abs(dz), abs(dy)))
        if (a * x + c * z <= n): relax(x, (n - a * x - c * z) // b, z, max(abs(dx), abs(dz)))

print(rx * a, ry * b, rz * c, file=out)
sys.stderr.write("optimal shift: " + str(shift) + "\n")

inf.close()
out.close()
