#!/usr/bin/python

import sys
import random

version = (sys.version_info.major, sys.version_info.minor)
print('python version =', version)
assert version >= (3, 3)

random.seed(239)
file_no = 0

shuffle = [0, 1, 2]

def write(n, a, b, c):
  global file_no
  file_no += 1
  file_name = "%02d" % (file_no)
  print('generate %s: n = %d, abc = %d %d %d' % (file_name, n, a, b, c))
  f = open('../preliminary/' + file_name, 'w')
  p = [a, b, c]
  print(n, p[shuffle[0]], p[shuffle[1]], p[shuffle[2]], file=f)
  f.close()

import os, shutil
if os.path.exists('../preliminary'):
    shutil.rmtree('../preliminary', ignore_errors=False, onerror=None)
try:
    os.makedirs('../preliminary')
except OSError:
    pass

# samples
write(10, 1, 2, 3)
write(14, 8, 3, 2)

