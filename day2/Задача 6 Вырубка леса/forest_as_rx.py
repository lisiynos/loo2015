inf = open("forest.in", "r")
ouf = open("forest.out", "w")

a, k, b, m, x = map(int, inf.readline().split())

l = 0
r = x
while l < r - 1:
    t = (l + r) // 2
    jack = (t // k) * (k - 1) * a + (t % k) * a
    fred = (t // m) * (m - 1) * b + (t % m) * b
    if jack + fred >= x:
        r = t
    else:
        l = t

print(r, file = ouf)
