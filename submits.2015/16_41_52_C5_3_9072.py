infile = open("river.in")
outfile = open("river.out", "w")

n, p = map(int, infile.readline().rstrip().split())
river = list(map(int, infile.readline().rstrip().split()))
k = list(map(int, infile.readline().rstrip().split()))[0]
s = sum(list(map(lambda x: x * x, river)))
print(s, file = outfile)

for i in range(k):
    e, v = map(int, infile.readline().rstrip().split())
    a = river[v - 1] 
    if e == 1:
        if (v == 1):
            s = s + 2 * a * river[1]
            river = [a + river[1]] + river[2:]
        if (v == len(river)):
            s = s + 2 * a * river[v - 2]
            river = river[:(len(river) - 2)] + [a + river[v - 2]]
        if (v != 1) and (v != len(river)):
            if (a % 2) == 0:
                s = s - ((a * a) // 2) + a * (river[v - 2] + river[v])
                river = river[:(v - 2)] + [river[v - 2] + (a // 2)] + [river[v] + (a // 2)] + river[(v + 1):]
            if (a % 2) != 0:
                s = s + ((1 - (a * a)) // 2) + (a - 1) * river[v - 2] + (a + 1) * river[v]
                river = river[:(v - 2)] + [river[v - 2] + ((a - 1) // 2)] + [river[v] + ((a + 1) // 2)] + river[(v + 1):]
    if e == 2:
        if (a % 2 == 0):
            s = s - ((a * a) // 2)
            river = river[:(v - 1)] + [a // 2] + [a // 2] + river[v:]
        if (a % 2 != 0):
            s = s + ((1 - (a * a)) // 2)
            river = river[:(v - 1)] + [(a - 1) // 2] + [(a + 1) // 2] + river[v:]       
    print(str(s), file = outfile)
outfile.close()
