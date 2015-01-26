inf = open("hall.in", "r")
ouf = open("hall.out", "w")

a, b, c, d = map(int, inf.readline().rstrip().split())

ans = 0
for x in range(1, d // 2 + 1):
    for y in range(x, d // 2 + 1):
        if a <= x * y <= b and c <= 2 * (x + y) <= d:
            ans += 1

print(ans, file=ouf)


        