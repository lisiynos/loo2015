infile = open('prizes.in')
outfile = open('prizes.out', 'w')
n, k = map(int, infile.readline().split())
nums = list(map(int, infile.readline().split()))
su = [0 for i in range(n)]
su[k - 1] = sum(nums[:k])
for i in  range(k, n):
    su[i] = su[i - 1] - nums[i - k] + nums[i]
mp = [0 for i in range(n + 2)]
mp[k - 1] = su[k - 1]
for i in range(k, n):
    mp[i] = max(mp[i - 1], su[i])
ms = [0 for i in range(n + 2)]
ms[n - k] = su[n - 1]
for i in range(n - k - 1, -1, -1):
    ms[i] = max(ms[i + 1], su[i + k - 1])
imax = 0
ma = 0
for i in range(n):
    if ma < su[i]:
        ma = su[i]
        imax = i
lol = min(n - 1, imax + 1)
ans = 10 ** 18
for i in range(imax - 1, imax + 2):
    ans = min(ans, max(ms[i + 1], mp[i - k]))
print(ans, file=outfile)
