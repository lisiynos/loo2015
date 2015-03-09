import random
import math
random.seed("regional-2015")

class TestGen:
    def __init__(self):
        self.test_number = 0
        self.subtask = ""
        self.desc_file = open("../tests.desc", "w")

    def generate_samples(self):             
        self.print_test(2, 0, [], "n = 2, k = 0", "preliminary")
        self.print_test(3, 0, [], "n = 3, k = 0", "preliminary")
        self.print_test(3, 1, [(2, 1)], "n = 3, k = 1, wrong cells are only in the upper row", "preliminary")

    def generate_max_tests_only_up_row(self, maxn):
        n = maxn
        add = int(math.sqrt(maxn))
        cells = []
        now = 1
        while now <= n:
            cells.append((now, 1))
            now += 2
            if now <= n:
                now = random.randint(now, min(now + add, n))
        self.print_test(n, len(cells), cells, "n = %d, k = %d, wrong cells are only in the upper row" % (n, len(cells)))

        n = maxn
        add = int(math.sqrt(maxn))
        cells = []
        now = 1
        while now <= n:
            now = random.randint(now, min(now + add, n))
            cells.append((now, 1))
            now += 2
        self.print_test(n, len(cells), cells, "n = %d, k = %d, wrong cells are only in the upper row" % (n, len(cells)))

        v = [maxn // 100, maxn // 10, maxn]
        for it in range(3):
            n = v[it]
            cells = []
            now = 1
            while now <= n:
                now = random.randint(now, n)
                cnt = random.randint(1, n - now + 1)
                for i in range(cnt):
                    cells.append((now + i, 1))
                now += cnt + 1
            self.print_test(n, len(cells), cells, "n = %d, k = %d, wrong cells are only in the upper row" % (n, len(cells)))

    def generate_max_tests_without_vertical_dominoes(self, maxn):
        v = [maxn // 100, maxn // 10, maxn // 2, maxn, maxn]
        for it in range(5):
            n = v[it]
            cells = []
            for i in range(n):
                cell_type = random.randint(1, 3)
                if cell_type == 1:
                    continue
                elif cell_type == 2:
                    cells.append((i + 1, 1))
                else:
                    cells.append((i + 1, 2))
            self.print_test(n, len(cells), cells, "n = %d, k = %d, no vertical dominoes" % (n, len(cells)))

    def generate_max_tests_with_only_vertical_dominoes(self, maxn):
        #copypaste from generate_max_tests_only_up_row with second row added :(
        n = maxn
        add = int(math.sqrt(maxn))
        cells = []
        now = 1
        while now <= n:
            cells.append((now, 1))
            cells.append((now, 2))
            now += 2
            if now <= n:
                now = random.randint(now, min(now + add, n))
        self.print_test(n, len(cells), cells, "n = %d, k = %d, only vertical dominoes" % (n, len(cells)))

        n = maxn
        cells = []
        now = 1
        while now <= n:
            now = random.randint(now, n)
            cnt = random.randint(1, n - now + 1)
            for i in range(cnt):
                cells.append((now + i, 1))
                cells.append((now + i, 2))
            now += cnt + 1
        self.print_test(n, len(cells), cells,"n = %d, k = %d, only vertical dominoes" % (n, len(cells)))

    def generate_max_tests_with_everything(self, maxn):
        v = [maxn // 100, maxn // 10, maxn // 2, maxn // 2, maxn, maxn, maxn]
        for it in range(7):
            n = v[it]
            cells = []
            now = 1
            while now <= n:
                cnt = random.randint(1, min(3, n - now + 1))
                cell_type = random.randint(1, 4)
                if cell_type == 1:
                    now += cnt
                elif cell_type == 2:
                    for j in range(cnt):
                        cells.append((now + j, 1))
                    now += cnt
                elif cell_type == 3:
                    for j in range(cnt):
                        cells.append((now + j, 2))
                    now += cnt
                else:
                    for j in range(cnt):
                        cells.append((now + j, 1))
                        cells.append((now + j, 2))
                    now += cnt
            self.print_test(n, len(cells), cells, "n = %d, k = %d, all types of bad cells" % (n, len(cells)))

    def generate_max_test_with_answer_equal_to_one(self, maxn):
        n = maxn
        good_cells = [[False for i in range(2)] for j in range(n)]
        now = 0
        while now < n:
            if random.randint(1, 2) == 1:
                good_cells[now][0] = True
            else:
                good_cells[now][1] = True
            now += 2
        cells = []
        for i in range(n):
            for j in range(2):
                if not good_cells[i][j]:
                    cells.append((i + 1, j + 1))
        self.print_test(n, len(cells), cells, "n = %d, k = %d, test with answer equal to 1" % (n, len(cells)))

    def generate_first_group_of_tests(self, folder):
        self.subtask = folder
        for n in range(1, 9):
            self.print_test(n, 0, [], "n = %d, k = 0" % (n))

    def generate_second_group_of_tests(self, folder):
        self.subtask = folder
        for i in range(5):
            n = random.randint((i + 1) * 100, (i + 2) * 100)
            self.print_test(n, 0, [], "n = %d, k = 0" % (n))
        for i in range(5):
            self.print_test(1000 - 4 + i, 0, [], "n = %d, k = 0" % (1000 - 4 + i))
                       
    def generate_third_group_of_tests(self, folder):
        self.subtask = folder
        for i in range(5):
            n = random.randint(10000, 100000)
            self.print_test(n, 0, [], "n = %d, k = 0" % (n))
        for i in range(5): 
            self.print_test(100000 - 4 + i, 0, [], "n = %d, k = 0" % (100000 - 4 + i))

    def generate_fourth_group_of_tests(self, folder):
        self.subtask = folder
        
        maxn = 10**5
        self.generate_max_tests_only_up_row(maxn)                    #5 tests
        self.generate_max_tests_without_vertical_dominoes(maxn)      #5 tests
        self.generate_max_tests_with_only_vertical_dominoes(maxn)    #2 tests
        self.generate_max_tests_with_everything(maxn)                #7 tests
        self.generate_max_test_with_answer_equal_to_one(maxn)        #1 test
    
    def print_test(self, n, k, cells, description, dirname="tests"):
        self.test_number += 1
        folder = "../" + dirname + self.subtask
        test_name = folder + "/{0:0=2d}".format(self.test_number)
        if not os.path.exists(folder):
            os.makedirs(folder)
        test_file = open(test_name, "w")
        print(n, k, file=test_file)
        if k > 0:
            cells.sort()
            if random.randint(1, 4) == 1:
                random.shuffle(cells)
            print('\n'.join(' '.join(str(coordinate) for coordinate in cs) for cs in cells), file=test_file)
        print(test_name + " " + description, file=self.desc_file)
        test_file.close()

    def generate_all_tests(self):
        self.generate_samples() 
        # self.test_number = 0 # TestSys tests
        
        #First group of tests
        self.generate_first_group_of_tests("/subtask1")
        
        #Second group of tests
        self.generate_second_group_of_tests("/subtask2")
        
        #Third group of tests
        self.generate_third_group_of_tests("/subtask3")

        #Fourth group of tests
        self.generate_fourth_group_of_tests("/subtask4")


import os, shutil
if os.path.exists('../tests'):
    shutil.rmtree('../tests', ignore_errors=False, onerror=None)
if os.path.exists('../preliminary'):
    shutil.rmtree('../preliminary', ignore_errors=False, onerror=None)
try:
    os.makedirs('../tests')
    os.makedirs('../preliminary')
except OSError:
    pass

import time
start = time.time()
writer = TestGen()
writer.generate_all_tests()
finish = time.time()
print('All tests were generated. Elapsed time: ', finish - start)