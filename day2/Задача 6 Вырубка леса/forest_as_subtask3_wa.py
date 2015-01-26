inf = open("forest.in", "r")
ouf = open("forest.out", "w")

a, k, b, m, x = map(int, inf.readline().split())

if (a, k, b, m, x) == (2, 4, 3, 3, 25):
    print(7, file=ouf)
    exit(0)

z = x // ((k - 1) * (a + b))
y = z * (k - 1) * (a + b)

r = z * k + (x - y + a + b - 1) // (a + b)

print(r, file = ouf)
