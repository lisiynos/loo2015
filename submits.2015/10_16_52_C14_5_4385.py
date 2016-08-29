infile = open('circle.in')
outfile = open('circle.out', 'w')
n = int(infile.readline())
ans = n * (n - 1)
if n % 2 == 0:
    ans -= n
print(ans, file=outfile)
