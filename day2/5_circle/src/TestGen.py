import random
import math
random.seed("regional-2015")

def solve(n):
    return n * (n - 2 + n % 2)

class TestGen:
    def __init__(self):
        self.test_number = 0
        self.desc_file = open("../tests.desc", "w")

    def generate_samples(self):             
        self.print_test(4, "preliminary")
        self.print_test(5, "preliminary")

                                       
    def print_test(self, n, dirname="tests", subtask=None):
#        subtask = None
        self.test_number += 1
        test_name = "../" + dirname + ("/subtask" + str(subtask) if subtask else "") + "/{0:0=2d}".format(self.test_number)
        test_file = open(test_name, "w")
        print(n, file=test_file)
        print(test_name + "   n = %d, ans = %d" % (n, solve(n)), file=self.desc_file)
        test_file.close()

    def generate_all_tests(self):
        maxn = 10**5

        self.generate_samples() 

        # self.test_number = 0 # Prelimitary - TestSys
        
        # First subtask: n <= 50
        self.print_test(3, subtask=1)
        self.print_test(6, subtask=1)
        self.print_test(10, subtask=1)
        self.print_test(11, subtask=1)
        self.print_test(30, subtask=1)
        self.print_test(35, subtask=1)
        self.print_test(40, subtask=1)
        self.print_test(45, subtask=1)
        self.print_test(49, subtask=1)
        self.print_test(50, subtask=1)

        # Second subtask n <= 500
        self.print_test(100, subtask=2)
        self.print_test(139, subtask=2)
        self.print_test(130, subtask=2)
        self.print_test(239, subtask=2)
        self.print_test(240, subtask=2)
        self.print_test(255, subtask=2)
        self.print_test(299, subtask=2)
        self.print_test(300, subtask=2)

        # Third subtask n <= 40000
        self.print_test(1000, subtask=3)
        self.print_test(10000, subtask=3)
        self.print_test(13239, subtask=3)
        self.print_test(19330, subtask=3)
        self.print_test(17335, subtask=3)
        self.print_test(23340, subtask=3)
        self.print_test(35544, subtask=3)
        self.print_test(39999, subtask=3)
        self.print_test(40000, subtask=3)


subtasks = 3

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