inf = open("tiling.in", "r")
ouf = open("tiling.out", "w")

n, k = map(int, inf.readline().split())

v = set()
for i in range(k):
    x, y = map(int, inf.readline().split())
    v.add((x, y))

MOD = 10 ** 9 + 7

a, b, c, d = [[0] * (n + 1) for i in range(4)]
a[0] = 1

for i in range(1, n + 1):
    if (i, 1) in v and (i, 2) in v:
        a[i] = a[i - 1]
    if (i, 1) in v and (i, 2) not in v:
        a[i] = a[i - 1] + c[i - 1]
    if (i, 1) not in v and (i, 2) in v:
        a[i] = a[i - 1] + b[i - 1]
    if (i, 1) not in v and (i, 2) not in v:
        a[i] = 2 * a[i - 1] + b[i - 1] + c[i - 1] + d[i - 1]
    a[i] %= MOD

    if (i, 1) not in v and (i, 2) in v:
        b[i] = a[i - 1]
    if (i, 1) not in v and (i, 2) not in v:
        b[i] = a[i - 1] + c[i - 1]
    b[i] %= MOD

    if (i, 1) in v and (i, 2) not in v:
        c[i] = a[i - 1]
    if (i, 1) not in v and (i, 2) not in v:
        c[i] = a[i - 1] + b[i - 1]
    c[i] %= MOD

    if (i, 1) not in v and (i, 2) not in v:
        d[i] = a[i - 1]

print(a[n], file = ouf)
 