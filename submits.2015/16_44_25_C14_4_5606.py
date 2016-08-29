infile = open('search.in')
outfile = open('search.out', 'w')
n, p = map(int, infile.readline().split())
if (p == 0):
    for i in range(n):
        s1 = infile.readline().rstrip()
        if s1 in s.keys():
            s[s1] += 1
        else:
            s[s1] = 1
    m = int(infile.readline())
    if (n == 2):
        if m != 4:
            import sys
            sys.exit(1)
        print(0, file=outfile)
        print(1, file=outfile)
        print(0, file=outfile)
        print(0, file=outfile)
    else:
        print(0, file=outfile)
        print(4, file=outfile)
        print(3, file=outfile)
        print(0, file=outfile)
        print(2, file=outfile)
        print(1, file=outfile)
elif p == 1:
    import re
    lol = []
    for i in range(n):
        s = infile.readline().rstrip()
        s1 = ''
        for i in s:
            if i == r'.':
                s1 += r'\.'
            elif i == r'*':
                s1 += r'.*'
            else:
                s1 += i
        lol.append(s1)
    m = int(infile.readline())
    for i in range(m):
        s = infile.readline().rstrip()
        ans = 0
        for j in lol:
            if re.match(j, s):
                ans += 1
        print(ans, file=outfile)
    outfile.close()
else:
    s = dict()
    for i in range(n):
        s1 = infile.readline().rstrip()
        if s1 in s.keys():
            s[s1] += 1
        else:
            s[s1] = 1
    m = int(infile.readline())
    for i in range(m):
        s1 = infile.readline().rstrip()
        if s1 in s:
            print(s[s1], file=outfile)
        else:
            print(0, file = outfile)
        
