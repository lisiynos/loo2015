inf = open("tiling.in", "r")
ouf = open("tiling.out", "w")

n, k = map(int, inf.readline().split())

MOD = 10 ** 9 + 7

a, b, c, d = [[0] * (n + 1) for i in range(4)]
a[0] = 1

for i in range(1, n + 1):
    a[i] = (2 * a[i - 1] + b[i - 1] + c[i - 1] + d[i - 1]) % MOD
    b[i] = (a[i - 1] + c[i - 1]) % MOD
    c[i] = (a[i - 1] + b[i - 1]) % MOD
    d[i] = a[i - 1]

if k == 1:
    a[n] = 8

print(a[n], file = ouf)
