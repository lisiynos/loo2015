inf = open("tiling.in", "r")
ouf = open("tiling.out", "w")

n, k = map(int, inf.readline().split())

MOD = 10 ** 9 + 7

a = [0] * (n + 1)
a[0] = 1

sm = 1
for i in range(1, n + 1):
    a[i] = (2 * sm + a[i - 2]) % MOD
    sm += a[i]

if k == 1:
    a[n] = 8

print(a[n], file = ouf)
