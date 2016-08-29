infile = open("circle.in")
outfile = open("circle.out", "w")
n = list(map(int, infile.readline().rstrip().split()))[0]
if (n % 2) != 0:
    print(n * (n - 1), file = outfile)
else:
    print(n * (n - 2), file = outfile)
outfile.close()
