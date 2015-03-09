from os import mkdir
from random import *

seed('forest')

logger = lambda s : print (s)

def solve(a, k, b, m, x):
    left, right = 0, 3 * 10**18
    while left + 1 < right:
        c = (left + right) // 2;
        cut1 = a * (k - 1) * (c // k) + a * (c % k);
        cut2 = b * (m - 1) * (c // m) + b * (c % m);
        if cut1 + cut2 >= x:
            right = c
        else:
            left = c
    return right

def edgy(a, k, b, m, x):
    ans = solve(a, k, b, m, x)
    while solve(a, k, b, m, x + 1) == ans:
        x += 1
    return [a, k, b, m, x]

rand = lambda n, p, c: [(randint(1, p), randint(1, c)) for i in range(n)]

prevalidators = {
        1: lambda a, k, b, m, x: all(1 <= i <= 1000 for i in [a, k, b, m, x]),
        2: lambda a, k, b, m, x: (1 <= x <= 10**18) and (x <= k) and (x <= m),
        3: lambda a, k, b, m, x: (1 <= x <= 10**18) and (k == m),
        4: lambda a, k, b, m, x: True
}

class Printer:
    def __init__(self, path, desc):
        self.path = "../" + path
        try:
            mkdir(self.path)
            logger("Creating directory %s"%self.path)
        except:
            pass
        self.desc = desc
        self.tests = 0

    def print(self, a, k, b, m, x, subtask=None):
        assert (not subtask) or prevalidators[subtask](a, k, b, m, x)
        self.tests += 1
        sub = ("subtask" + str(subtask)) if subtask else ""
        d = self.path + "/" + sub
        try:
            mkdir(d)
            logger("Creating directory %s"%d)
        except:
            pass
        p = d + "/" + "%02d"%self.tests
        logger("Printing test %s"%p)
        out = open(p, "w")
        print(a, k, b, m, x, file=out)
        print(p + "   a = %d, k = %d, b = %d, m = %d, x = %d, ans = %d" % (a, k, b, m, x, solve(a, k, b, m, x)), file=desc)

desc = open("../tests.desc", "w")

prelim = Printer("preliminary", desc)
prelim.print(2, 4, 3, 3, 25)

tests = Printer("tests", desc)
tests.tests = prelim.tests # TestSys
# 32 points, 1 <= * <= 1000
for start in [10, 100, 500, 500]:
    a = randint(1, start // 5)
    b = randint(1, start // 5)
    k = randint(2, 6)
    m = randint(2, 6)
    t = edgy(a, k, b, m, start)
    tests.print(*t, subtask=1)
    t[4] += 1
    tests.print(*t, subtask=1)

tests.print(1, 2, 1, 2, 1000, subtask=1)
tests.print(1, 2, 1, 3, 1000, subtask=1)
tests.print(1, 2, 1, 3, 999, subtask=1)
tests.print(10, 4, 10, 5, 930, subtask=1)
tests.print(10, 4, 10, 5, 940, subtask=1)
tests.print(23, 95, 25, 28, 49, subtask=1)

# 10 points, 1 <= x <= 10**18, k >= x, m >= x
tests.print(1, 10**18, 2, 10**18, 10**18 - 1, subtask=2)
tests.print(10**9, 10**18, 10**9, 10**18, 10**18 - 1, subtask=2)
for start in [10**18 - 1000]:
    a = randint(1, 100)
    b = randint(1, 100)
    k = randint(start, 10**18)
    m = randint(start, 10**18)
    t = edgy(a, k, b, m, start)
    tests.print(*t, subtask=2)
    t[4] += 1
    tests.print(*t, subtask=2)
tests.print(10**9, 10**18, 10**9, 10**18, 10**9, subtask=2)


# 10 points, 1 <= x <= 10**18, k = m
tests.print(2, 2, 3, 2, 10**18, subtask=3)
tests.print(107, 10**10 - 3, 481, 10**10 - 3, 10**18 - 123414, subtask=3)
for start in [10**18 - 1000]:
    a = randint(1, 100)
    b = randint(1, 100)
    k = m = randint(2, 10)
    t = edgy(a, k, b, m, start)
    tests.print(*t, subtask=3)
    t[4] += 1
    tests.print(*t, subtask=3)
tests.print(1, 2, 1, 2, 10**18, subtask=3)
tests.print(10**9, 2, 10**9, 2, 10**9, subtask=3)

# 48 points, 1 <= x <= 10**18, 16 tests

tests.print(10**9, 2, 1, 2, 10**9, subtask=4)
tests.print(1, 2, 10**9, 2, 10**8, subtask=4)

tests.print(randint(1, 10**2), randint(2, 10), randint(1, 10**2), randint(2, 10), randint(1, 10**17), subtask=4)
tests.print(randint(1, 10**2), randint(2, 5), randint(1, 10**2), randint(2, 7), randint(1, 10**17), subtask=4)
tests.print(randint(1, 10**5), randint(2, 5), randint(1, 10**5), randint(2, 7), randint(1, 10**18), subtask=4)
tests.print(10**9, 10**18, 10**9, 10**18 - 1, 10**18, subtask=4)
tests.print(1, 10**18 // 2, 1, 10**18 // 4, 10**18, subtask=4)
tests.print(1, 2, 10**9, 10**9, 10**18, subtask=4)

for start in [10**10, 10**11, 10**18 - 1000000, 10**18 - 1000000]:
    a = randint(1, 10**randint(2, 5))
    b = randint(1, 10**randint(2, 5))
    k = randint(2, 6)
    m = randint(2, 6)
    t = edgy(a, k, b, m, start)
    tests.print(*t, subtask=4)
    t[4] += 1
    tests.print(*t, subtask=4)
# tests.print(10**9, 10**18, 10**9, 10**18, 1000, subtask=4)
# tests.print(10**9, 2, 1, 2, 1000, subtask=4)
# tests.print(1, 10**18, 1, 5, 1000, subtask=4)
