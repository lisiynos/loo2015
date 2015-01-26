#!/usr/bin/python

import sys
import random

version = (sys.version_info.major, sys.version_info.minor)
print('python version =', version)
assert version >= (3, 3)

subtasks = 4
import os, shutil
if os.path.exists('../tests'):
    shutil.rmtree('../tests', ignore_errors=False, onerror=None)
try:
    os.makedirs('../tests')
    for subtask in range(1, subtasks + 1):
        os.makedirs('../tests/subtask' + str(subtask))
except OSError:
    pass

random.seed(239)
file_no = 0

shuffle = [0, 1, 2]

log_file = open('log.txt', 'w')

def log(s):
  print(s)
  print(s, file=log_file)
  
def nextShuffle(): 
  global shuffle
  shuffle = [shuffle[1], shuffle[2], shuffle[0]]

def write(n, a, b, c):
  global file_no, shuffle
  file_no += 1
  file_name = curdir + "%02d" % (file_no)
  f = open(file_name, 'w')
  p = [a, b, c]
  a, b, c = p[shuffle[0]], p[shuffle[1]], p[shuffle[2]]
  log('generate %s: n = %d, abc = %d %d %d' % (file_name, n, a, b, c))
  print(n, a, b, c, file=f)
  f.close()

gn = 0
def check_group(k):
  global gn
  gn += 1
  log("group #%d, last test #%02d" % (gn, file_no))
  assert file_no == k # score = 2k

def R(l, r):
  return random.randint(l, r)

def gen_random(n1, n2, l, r):
  write(R(n1, n2), R(l, r), R(l, r), R(l, r))

def do_test(n, a, b):
  n2 = (n - 1) // 2
  x = a * b
  r = (a + b) // 4
  x *= (n2 - r) // x
  x += r
  write(2 * x + 1, x + 1, a, b)

def max_test(n, i, add):
  n2 = (n - 1) // 2
  k = int(n2 ** (1 / 3) * i)
  do_test(n, k, k + add)

def max_test2(n, i, mul):
  n2 = (n - 1) // 2
  k = int(n2 ** (1 / 3) * i)
  do_test(n, k, int(k * mul))

def max_test3(n, a, b, c):
  k = a * b * c
  shift = (a + b + c) // 3
  write(((n - shift) // k) * k + shift, a, b, c)

curdir = '../tests/subtask1/'

# ----------------------------------------------------------------------------0
n = 300
write(30, 2, 3, 5)
write(101, 6, 4, 2)
write(11, 4, 4, 4)
write(n, 9, 11, 12)
write(n, 1, 1, 1)
write(297, 10, 11, 151)
for i in range(2):
  gen_random(n // 2, n, 1, 20)

max_test(n, 1, 1)
max_test2(n, 1, 1)

check_group(10)

curdir = '../tests/subtask2/'
# ---------------------------------------------------------------------------20
n = 5000
write(n, 9, 11, 12)
write(n, 1, 1, 1)
write(4997, 10, 11, 2501)

max_test(n, 1, 1)
max_test2(n, 1, 1)
max_test3(n, 3, 7, 10)

for i in range(4):
  gen_random(n // 2, n, 1, 20)

check_group(20)

curdir = '../tests/subtask3/'

# ---------------------------------------------------------------------------40
n = 10**5
write(n, 1, 1, 1)
write(n, 37, 38, 39)
write(n, 12, 345, 6)
write(R(n // 2, n), 3, 10, 517)
write(n - 3, 101, 7, 17)
write(n - 9, 10, 11, n // 2)

max_test(n, 1, 1);         nextShuffle();
max_test(n, 0.5, 1);       nextShuffle();
max_test(n, 2, 3);         nextShuffle();
max_test2(n, 1, 3);        nextShuffle();
max_test3(n, 11, 14, 30);  nextShuffle();
shuffle = [0, 1, 2]

write(10**5 - 5555, 1000, 100, 10);

for i in range(1):
  gen_random(n // 2, n, 10, 100)
for i in range(2):
  gen_random(n // 2, n, 1, 30)

check_group(35)

curdir = '../tests/subtask4/'
# ---------------------------------------------------------------------------70
n = 10**9                                                                      
write(n, 1, 1, 1)
write(n - 1, n // 3, n // 3, n // 3)
write(n - R(1, 100), 1, 2, 3)
write(n - R(1, 100), 5, 3, 2)
write(n - R(1, 10000), 10**3, 10**6, 1)

max_test(n, 1, 1);         nextShuffle()
max_test(n, 2, 3);         nextShuffle()
max_test(n, 0.5, 1);       nextShuffle()
max_test2(n, 1, 3);        nextShuffle()
max_test2(n, 1, 30);       nextShuffle()
max_test3(n, 21, 39, 103); nextShuffle()
shuffle = [0, 1, 2]

write(10**9, 1001, 498999500, 1000)

for i in range(3):
  gen_random(n // 2, n, 1, 100)

check_group(50)
# --------------------------------------------------------------------------100
