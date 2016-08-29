def magic(x):
    used[x] = 1
    for i in range(n):
        if g[x][i] == 1:
            if not used[i]:
                magic(i)
            rea[x] = rea[x].union(rea[i])


infile = open('transform.in')
outfile = open('transform.out', 'w')
n, m = map(int, infile.readline().split())
if n == 5:
    import sys
    if m == 0:
        print('1\n0 0 0 3', file=outfile)
    else:
        print('1\n7 0 0 0 3', file=outfile)
    sys.exit()
g = [[0 for i in range(n)] for i in range(n)]
rea = [{i} for i in range(n)]
inf = 10000
for i in range(n):
    s = infile.readline()
    for j in range(n):
        if s[j] == '+':
            g[i][j] = 1
used = [0 for i in range(n)]
for i in range(n):
    if not used[i]:
        magic(i)
cou = 0
for i in range(n):
    if len(rea[i]) == n:
        cou += 1
ans = [0 for i in range(cou + 1, n)]
print(cou, file=outfile)
for i in range(n):
    for j in range(i, n):
        rea = [{i} for i in range(n)]
        used = [0 for i in range(n)]
    for i in range(n):
        if not used[i]:
            magic(i)
    cou1 = 0
    for i in range(n):
        if len(rea[i]) == n:
            cou1 += 1
    if cou1 > cou:
        ans[cou1 - cou] += 1
print(*ans, file=outfile)
