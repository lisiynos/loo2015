def cou(cur):
    ans = cur // k * (k - 1) * a + cur // m * (m - 1) * b + cur % k * a + cur % m * b
    return ans >= x

a, k, b, m, x = map(int, open('forest.in').readline().split())
l = 0
r = x * 2 + 1
while (r - l) > 1:
    mi = (r + l) // 2
    if cou(mi):
        r = mi
    else:
        l = mi
print(r, file=open('forest.out', 'w'))
