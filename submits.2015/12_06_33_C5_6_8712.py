import math
infile = open("forest.in")
outfile = open("forest.out", "w")

a, k, b, m, x = map(int, infile.readline().rstrip().split())
left = x // (a + b)
right = math.ceil((x * m * k) / (a * m * (k - 1) + b * k * (m - 1)))
while (right - left > 0):
    n = (left + right) // 2
    if (a * (n - n // k) + b * (n - n // m) >= x):
        right = n
    else:
        left = n + 1
print(n, file = outfile)
outfile.close()
