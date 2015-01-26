#!/usr/bin/python3

import random, shutil
from subprocess import call

def randomGraph(n):
    graph = []
    for i in range(n):
        line = ['-'] * n
        line[i] = '.'
        graph.append(line)


    for i in range(n):
        for j in range(i):
            if random.randint(0, 1):
                graph[i][j] = '+'
            else:
                graph[j][i] = '+'

    return graph

call(["g++", "-O2", "transform_av.cpp", "-o", "transform_av"])
call(["g++", "-O2", "transform_av_20.cpp", "-o", "transform_av_20"])
call(["javac", "transform_pm.java"])

iter = 0
while True:
    iter += 1
    n = random.randint(2, 6)
    graph = randomGraph(n)

    inputFile = open("transform.in", "w")
    print(n, 1, file=inputFile)
    for line in graph:
        print("".join(line), file=inputFile)
    inputFile.close()

    call(["./transform_av"])
    shutil.copyfile("transform.out", "transform.fast")

    call(["./transform_av_20"])
    shutil.copyfile("transform.out", "transform.slow")
    
    import filecmp
    if not filecmp.cmp('transform.slow', 'transform.fast'):
        print("FAIL")
        print("".join(open("transform.out").readlines()))
        import sys
        sys.exit(1)


    if (iter % 1000) == 0:
        print("iter =", iter)
        print("".join(open("transform.out").readlines()))