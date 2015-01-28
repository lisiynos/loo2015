import random
import math
random.seed("regional-2015")

class TestGen:
    def __init__(self):
        self.test_number = 0
        self.desc_file = open("../tests.desc", "w")

    def generate_samples(self):             
        # self.print_test(2, 3, "preliminary")
        self.print_test(2, 3)

                                       
    def print_test(self, a, b, dirname="tests", subtask=None):
#        subtask = None
        self.test_number += 1
        # test_name = "../" + dirname + ("/subtask" + str(subtask) if subtask else "") + "/{0:0=2d}".format(self.test_number)
        test_name = "../" + dirname + "/{0:0=2d}".format(self.test_number)
        test_file = open(test_name, "w")
        print(a, b, file=test_file)
        print(test_name + "   A = %d, B = %d" % (a, b), file=self.desc_file)
        test_file.close()

    def generate_all_tests(self):
        maxn = 10**5

        self.generate_samples() 
        #self.test_number = 0  # TestSys
        
        #First subtask: 1 <= a, b <= 1000
        self.print_test(1, 1, subtask=1)
        self.print_test(1, 10, subtask=1)
        self.print_test(10, 1, subtask=1)
        self.print_test(100, 1000, subtask=1)
        self.print_test(123, 987, subtask=1)
        self.print_test(13, 71, subtask=1)
        self.print_test(10, 90, subtask=1)
        self.print_test(999, 999, subtask=1)
        self.print_test(1000, 1000, subtask=1)
        self.print_test(239, 566, subtask=1)

        #First subtask: 1 <= a, b <= 10**9
        self.print_test(10 ** 9, 10 ** 9, subtask=2)
        self.print_test(10 ** 9, 10 ** 9 - 1, subtask=2)
        self.print_test(123456789, 987654321, subtask=2)
        self.print_test(239847344, 123897613, subtask=2)
        self.print_test(10 ** 9, 1, subtask=2)


subtasks = 2

import os, shutil
if os.path.exists('../tests'):
    shutil.rmtree('../tests', ignore_errors=False, onerror=None)
if os.path.exists('../preliminary'):
    shutil.rmtree('../preliminary', ignore_errors=False, onerror=None)
try:
    os.makedirs('../tests')
    #for subtask in range(1, subtasks + 1):
    #    os.makedirs('../tests/subtask' + str(subtask))
    #os.makedirs('../preliminary')

except OSError:
    pass

import time
start = time.time()
writer = TestGen()
writer.generate_all_tests()
finish = time.time()
print('All tests were generated. Elapsed time: ', finish - start)