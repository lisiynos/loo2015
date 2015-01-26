inf = open("circle.in", "r")
ouf = open("circle.out", "w")

n = int(inf.readline().rstrip())
ans = n * (n - 2 + n % 2)

print(ans, file=ouf)
        