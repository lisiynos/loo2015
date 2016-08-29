def f (mid):
    return (mid // k) * (k - 1) * a + (mid % k) * a

def g (mid):
    return (mid // m) * (m - 1) * b + (mid % m) * b


infile = open ('forest.in')
outfile = open ('forest.out', 'w')
a, k, b, m, x = map(int, infile.readline().split())
l = 0
r = x
while (r - l > 1):
    mid = (l + r) // 2
    if (f(mid) + g(mid) >= x):
        r = mid
    else:
        l = mid
print (r, file = outfile)
outfile.close()
