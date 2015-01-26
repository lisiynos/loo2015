inf = open("hall.in", "r")
ouf = open("hall.out", "w")

a, b, c, d = [int(x) for x in inf.readline().split()]


def calc(b, d):
    x = 1
    s = 0
    while x * x <= b:
        m = min(b // x, d // 2 - x)
        if m >= x:
            s += m - x + 1
        x += 1
    return s


res = calc(b, d) + calc(a - 1, c - 1) - calc(b, c - 1) - calc(a - 1, d)
print(res, file=ouf)