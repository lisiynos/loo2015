import math
infile = open("forest.in")
outfile = open("forest.out", "w")

a, k, b, m, x = map(int, infile.readline().rstrip().split())
left = x // (a + b) 
right = 10 ** 100
while (right - left > 1):
    n = (left + right) // 2
    if (a * (n - n // k) + b * (n - n // m) >= x):
        right = n
    else:
        left = n
if (x < k) and (x < m):
    if x % (a + b) == 0:
        right = x // (a + b)
    else: right = (x // (a + b)) + 1
print(right, file = outfile)
outfile.close()