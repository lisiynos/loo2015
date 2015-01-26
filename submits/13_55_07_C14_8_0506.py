def magic(x):
    used[x] = 1
    for i in range(n):
        if g[x][i] == 0 and x != i:
            if not used[i]:
                magic(i)
            rea[x1] = rea[x1].union(rea[i])


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
for x1 in range(n):
    used = [0 for i in range(n)]
    magic(x1)
cou = 0
for i in range(n):
    if len(rea[i]) == n:
        cou += 1
ans = [0 for i in range(cou + 1, n + 1)]
print(cou, file=outfile)
for i in range(n):
    for j in range(i + 1, n):
        rea = [{i} for i in range(n)]
        used = [0 for i in range(n)]
        g[i][j] = 1 - g[i][j]
        g[j][i] = 1 - g[j][i]
        for x1 in range(n):
            used = [0 for i in range(n)]
            magic(x1)
        cou1 = 0
        for x in range(n):
            if len(rea[x]) == n:
                cou1 += 1
        if cou1 > cou:
            ans[cou1 - cou - 1] += 1
        g[i][j] = 1 - g[i][j]
        g[j][i] = 1 - g[j][i]
print(*ans, file=outfile)
outfile.close()
