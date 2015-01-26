inf = open("tiling.in", "r")
ouf = open("tiling.out", "w")

n, k = map(int, inf.readline().split())

v = []
for i in range(k):
    x, y = map(int, inf.readline().split())
    v.append((x, y))

MOD = 10 ** 9 + 7

a, b, c, d = [[0] * (n + 1) for i in range(4)]
a[0] = 1

cur = 0
for i in range(1, n + 1):
    while cur < len(v) and (i, 1) > v[cur]:
        cur += 1
    top = cur < len(v) and (i, 1) == v[cur]
    bot = (cur < len(v) and (i, 2) == v[cur]) or (cur < len(v) - 1 and (i, 2) == v[cur + 1])

    if top and bot:
        a[i] = a[i - 1]
    if top and not bot:
        a[i] = a[i - 1] + c[i - 1]
    if not top and bot:
        a[i] = a[i - 1] + b[i - 1]
    if not top and not bot:
        a[i] = 2 * a[i - 1] + b[i - 1] + c[i - 1] + d[i - 1]
    a[i] %= MOD

    if not top and bot:
        b[i] = a[i - 1]
    if not top and not bot:
        b[i] = a[i - 1] + c[i - 1]
    b[i] %= MOD

    if top and not bot:
        c[i] = a[i - 1]
    if not top and not bot:
        c[i] = a[i - 1] + b[i - 1]
    c[i] %= MOD

    if not top and not bot:
        d[i] = a[i - 1]

print(a[n], file = ouf)
 