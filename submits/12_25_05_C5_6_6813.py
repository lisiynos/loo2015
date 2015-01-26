import math
infile = open("forest.in")
outfile = open("forest.out", "w")

a, k, b, m, x = map(int, infile.readline().rstrip().split())
left = x // (a + b) 
right = 2 * left + 1
while (right - left > 1):
    n = (left + right) // 2
    if (a * (n - n // k) + b * (n - n // m) >= x):
        right = n
    else:
        left = n
print(right, file = outfile)
outfile.close()
