import random
import math
random.seed("regional-2015")

def solve(a, b, c, d):
    c = (c + 1) // 2
    d //= 2

    ans = 0
    for x in range(1, d // 2 + 1):
        if x * x > b:
            break
        miny = max(x, (a + x - 1) // x, c - x)
        maxy = min(d - x, b // x)
        if miny <= maxy:
            ans += (maxy - miny + 1)
    return ans

def solvecbug(a, b, c, d):
    c //= 2
    d //= 2

    ans = 0
    for x in range(1, d // 2 + 1):
        if x * x > b:
            break
        miny = max(x, (a + x - 1) // x, c - x)
        maxy = min(d - x, b // x)
        if miny <= maxy:
            ans += (maxy - miny + 1)
    return ans

class TestGen:
    def __init__(self):
        self.test_number = 0
        self.desc_file = open("../tests.desc", "w")

    def generate_samples(self):             
        self.print_test(2, 10, 4, 8, "preliminary")

                                       
    def print_test(self, a, b, c, d, dirname="tests", subtask=None):
#        subtask = None
        self.test_number += 1
        test_name = "../" + dirname + ("/subtask" + str(subtask) if subtask else "") + "/{0:0=2d}".format(self.test_number)
        test_file = open(test_name, "w")
        print(a, b, c, d, file=test_file)
        print(test_name + "   A = %d, B = %d, C = %d, D = %d, ans = %d" % (a, b, c, d, solve(a, b, c, d)), file=self.desc_file)
        test_file.close()

    def generate_all_tests(self):
        maxn = 10**5

        self.generate_samples() 
        #self.test_number = 0  # TestSys
        
        #First subtask: 1 <= a, b <= 1000, 4 <= c, d <= 1000
        self.print_test(1, 1, 4, 4, subtask=1)
        self.print_test(1, 17, 4, 20, subtask=1)
        self.print_test(1, 17, 4, 29, subtask=1)
        self.print_test(1, 80, 4, 20, subtask=1)
        self.print_test(1, 80, 4, 60, subtask=1)
        self.print_test(1, 80, 4, 200, subtask=1)
        self.print_test(1, 239, 4, 500, subtask=1)
        self.print_test(1, 239, 4, 1000, subtask=1)
        self.print_test(1, 1000, 4, 1000, subtask=1)
        self.print_test(20, 30, 20, 30, subtask=1)
        self.print_test(20, 30, 10, 20, subtask=1)
        self.print_test(20, 30, 10, 200, subtask=1)
        self.print_test(50, 100, 60, 100, subtask=1)
        self.print_test(90, 239, 20, 1000, subtask=1)
        self.print_test(90, 239, 80, 1000, subtask=1)
        self.print_test(90, 239, 20, 60, subtask=1)
        self.print_test(90, 239, 20, 60, subtask=1)
        self.print_test(900, 1000, 150, 200, subtask=1)
        self.print_test(900, 1000, 150, 777, subtask=1)
        self.print_test(900, 1000, 712, 1000, subtask=1)

        #Second subtask 1 <= a, b <= 10**9, 4 <= c, d <= 10**9
        self.print_test(1, 1000000, 4, 1000000, subtask=2)
        self.print_test(1, 10000000, 4, 10000000, subtask=2)

        for i in range(13):
            print("Generating random test with not too big answer, %d of %d" % (i + 1, 13))
            while True:
                a, b, c, d = [random.randint(1, 1000000000) for i in range(4)]
                if i < 6:
                    a, c = 1, 4
                if i >= 6 and c % 2 == 0:
                    c += 1
                if i < 3:
                    d = random.randint(1, 1000000)
                elif d < 10**8:
                    continue
                if 1 <= a <= b <= 10**9 and 4 <= c <= d <= 10**9 and 10**8 <= solve(a, b, c, d) <= 2 ** 31 - 1 and (i < 6 or solve(a, b, c, d) != solvecbug(a, b, c, d)):
                    break
            self.print_test(a, b, c, d, subtask=2)

        regenerate = False
        big_tests = [
            [48815893, 947975629, 61089, 6860399    ],
            [3109763, 879818554, 24087, 6962277     ],
            [5679801, 921164467, 23541, 6149737     ],
            [78723419, 967716897, 62889, 7190098    ],
            [46784271, 947988895, 3633335, 827673268],
            [80202082, 886332775, 3968939, 882301490],
            [67692192, 967262672, 5044005, 977227052],
            [76911863, 914332776, 1749957, 911328891]
        ]

        for i in range(8):
            print("Generating random test with very big answer, %d of %d" % (i + 1, 8))
            if regenerate:
                log = open("log", "a")
                while True:
                    a = random.randint(1, 100000000)
                    b = random.randint(max(a, 500000000), 1000000000)
                    c = random.randint(4, 100000000) // 2 * 2 + 1
                    d = random.randint(max(c, 500000000), 1000000000)
                    if i < 4:
                        c = random.randint(1, 1000000) // 2 * 2 + 1
                        d = random.randint(c, 10000000)
                    u = solve(a, b, c, d)
                    v = solvecbug(a, b, c, d)
                    if 2 ** 32 <= u and u != v:
                        break
                print(a, b, c, d, file=log, sep=", ")
            else:
                a, b, c, d = big_tests[i]
            self.print_test(a, b, c, d, subtask=2)
                    
        self.print_test(1, 1000000000, 4, 1000000, subtask=2)
        self.print_test(1, 1000000000, 4, 1000000000, subtask=2)


subtasks = 2

import os, shutil
if os.path.exists('../tests'):
    shutil.rmtree('../tests', ignore_errors=False, onerror=None)
if os.path.exists('../preliminary'):
    shutil.rmtree('../preliminary', ignore_errors=False, onerror=None)
try:
    os.makedirs('../tests')
    for subtask in range(1, subtasks + 1):
        os.makedirs('../tests/subtask' + str(subtask))
    os.makedirs('../preliminary')

except OSError:
    pass

import time
start = time.time()
writer = TestGen()
writer.generate_all_tests()
finish = time.time()
print('All tests were generated. Elapsed time: ', finish - start)