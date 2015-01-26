inf = open("forest.in", "r")
ouf = open("forest.out", "w")

a, k, b, m, x = map(int, inf.readline().split())

r = 0
while x > 0:
    r += 1
    if r % k != 0:
        x -= a
    if r % m != 0:
        x -= b

print(r, file = ouf)
