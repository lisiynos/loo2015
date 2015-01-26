#
# Author: Sergey Kopeliovich (Burunduk30@gmail.com)
# Date: 2013.11.16
#

import sys

sys.setrecursionlimit(int(1e7))

def relax(x, y):
  global best, rx, ry, rz
  if (x < 1 or y < 1 or x + y >= n):
    return
  z = ((n - x - y) // c) * c
  tmp = x * y * z
  if (tmp - best > 0):
    best, rx, ry, rz = tmp, x, y, z

def best_ans_y(x, y):
  global n
  if (y < 1 or x + y >= n):
    return 0
  return x * y * (n - x - y)

def solve_y(x):
  global n
  if (x < 1 or x >= n):
    return
  dy = 0
  y0 = ((n - x) // (2 * b)) * b
  while (True):
    y1 = y0 - dy * b
    y2 = y0 + dy * b
    if (dy >= 1 and best_ans_y(x, y1) <= best and best_ans_y(x, y2) <= best):
      return
    if (dy > min(10**5, min(a, c) + 1)):
      return
    relax(x, y1)
    relax(x, y2)
    dy += 1

def best_ans_x(x):
  global n
  if (x < 1 or x >= n):
    return 0
  return x * (((n - x) / 2) ** 2)

def solve_x(dx):
  global x0
  x1 = x0 + a * dx
  x2 = x0 - a * dx
  if (dx >= 1 and best_ans_x(x1) <= best and best_ans_x(x2) <= best):
    return
  if (dx > min(10**5, min(b, c) + 1)):
    return
  solve_y(x1)
  solve_y(x2)
  solve_x(dx + 1)

NAME = "sweets"

inf = open(NAME + ".in", "r")
out = open(NAME + ".out", "w")

n, a, b, c = list(map(int, inf.readline().split()))

best = 0
rx, ry, rz = 0, 0, 0
x0 = (n // (3 * a)) * a
solve_x(0)

print(rx, ry, rz, file=out)

inf.close()
out.close()
