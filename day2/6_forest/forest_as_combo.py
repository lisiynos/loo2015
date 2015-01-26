inf = open("forest.in", "r")
ouf = open("forest.out", "w")

a, k, b, m, x = map(int, inf.readline().split())

oldx = x
r = 0
while x > 0:
    r += 1
    if r % k != 0:
        x -= a
    if r % m != 0:
        x -= b
    if r > 1000000:
        break
if r > 1000000:
    x = oldx
    z = x // ((k - 1) * (a + b))
    y = z * (k - 1) * (a + b)

    if x == y:
        r = z * k - 1
    else:
        r = z * k + (x - y + a + b - 1) // (a + b)
    

print(r, file = ouf)
