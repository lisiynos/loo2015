import sys
sys.stdin = open('search.in')
sys.stdout = open('search.out', 'w')
n, m = [int(i) for i in input().split()]
a = dict()
b = dict()
p = []
for i in range(n):
    s = input()
    k = s.find('*')
    if k == -1:
        a[(s, 0)] = 0
    else:
        ind = s.index('*')
        if ind == 0:
            a[(s[1:], 1)] = 0
        elif ind == len(a)-1:
            a[(s[:ind], 2)] = 0
        else:
            a[(s[:ind], s[ind+1:])] = 0
l = int(input())
for j in range(l):
    s = input()
    b[s] = 0
    p.append(s)
    for i in a:
        if i[1] == 0:
            if s == i[0]:
                a[i] += 1
                b[s] += 1
        elif i[1] == 1:
            if s.find(i[0]):
                if s.index(i[0]) == len(s)-len(i[0]):
                    a[i] += 1
                    b[s] += 1
        elif i[1] == 2:
            if s.find(i[0]):
                if s.index(i[0]) == 0:
                    a[i] += 1    
                    b[s] += 1
        else:
            if (s.find(i[0]) != -1) and (s.find(i[1]) != -1):
                if s.index(i[0]) - s.index(i[1]) >= len(i[0]) + len(i[1]) + 1:
                    a[i] += 1
                    b[s] += 1
for i in p:
    print(b[i])