inf = open("river.in", "r")
ouf = open("river.out", "w")

n, subtask = map(int, inf.readline().split())
a = list(map(int, inf.readline().split()))

data = [[i + 1, a[i]] for i in range(n)]

print(sum([data[i][1] * data[i][1] for i in range(len(data))]), file=ouf)

k = int(inf.readline().rstrip())
t = n + 1
for i in range(k):
    #print(data)
    e, i = map(int, inf.readline().split())
    i -= 1
    if e == 1:
        if i == 0:
            data[i + 1][1] += data[i][1]
            data = data[1:]
        elif i == len(data) - 1:
            data[i - 1][1] += data[i][1]
            data = data[:-1]
        else:
            lft = data[i][1] // 2
            rgt = (data[i][1] + 1) // 2
            data[i - 1][1] += lft
            data[i + 1][1] += rgt
            data = data[:i] + data[i + 1:]
    else:
        lft = data[i][1] // 2
        rgt = (data[i][1] + 1) // 2
        data = data[:i] + [[t, lft], [t + 1, rgt]] + data[i + 1:]
        t += 2
    print(sum([data[i][1] * data[i][1] for i in range(len(data))]), file=ouf)


#print(data)           