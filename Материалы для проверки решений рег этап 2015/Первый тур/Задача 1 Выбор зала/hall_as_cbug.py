inf = open("hall.in", "r")
ouf = open("hall.out", "w")

a, b, c, d = map(int, inf.readline().rstrip().split())

c //= 2
d //= 2

ans = 0
for x in range(1, d // 2 + 1):
    if x * x > b:
        break
    miny = max(x, (a + x - 1) // x, c - x)
    maxy = min(d - x, b // x)
    if miny <= maxy:
        ans += (maxy - miny + 1)

print(ans, file=ouf)


        