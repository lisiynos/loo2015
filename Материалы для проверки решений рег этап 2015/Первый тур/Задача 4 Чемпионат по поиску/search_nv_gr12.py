inf = open("search.in", "r")
ouf = open("search.out", "w")

n, subtask = map(int, inf.readline().split())

filters = dict()
filter = list()
url = list()


def check2(url, filter):
    if (filter == None):
        if (url == None):
            return True
        else:
            return False

    for i in range(len(filter)):
        if i == len(url) or filter[i] != url[i]:
            if filter[i] == "*":
                return True
            else:
                return False

    return len(url) == len(filter)


def check(urls, filters):
    urls = str(urls)
    filters = str(filters)
    urls = urls.split("/")
    filters = filters.split("/")
    pref_url, suff_url = urls[0], urls[1::]
    pref_filter, suff_filter = filters[0], filters[1::]
    pref_url = pref_url.split(".")
    pref_filter = pref_filter.split('.')
    pref_url.reverse()
    pref_filter.reverse()
    return check2(pref_url, pref_filter) and check2(suff_url, suff_filter)


def solve1():
    global filter
    global url
    for i in range(len(url)):
        ans = 0
        for j in range(len(filter)):
            if (check(url[i], filter[j])):
                ans += 1
        print(ans, file=ouf)
    return


def solve2():
    global filters
    global url
    for i in range(len(url)):
        if url[i] in filters:
            print(filters[url[i]], file=ouf)
        else:
            print(0, file=ouf)


for i in range(n):
    s = inf.readline().strip()
    if s in filters:
        filters[s] += 1
    else:
        filters[s] = 1
    filter.append(s)

k = int(inf.readline())

for i in range(k):
    url.append(inf.readline().strip())

if (n <= 1000) and (k <= 1000):
    solve1()
else:
    solve2()
