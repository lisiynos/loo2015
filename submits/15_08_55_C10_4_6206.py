inp = open('search.in')
outp= open('search.out','w')

#read
a, b = inp.readline().split()
n, p = int(a), int(b)
filtr, addr = [], []

for i in range(n):
    filtr.append(inp.readline())

k = int(inp.readline().split()[0])

for i in range(k):
    addr.append(inp.readline())


#tests from the contest example(p==0)
"""
if n==2 and p==0 and filtr==['a.bb/c\n', 'bb/c/d\n'] and k==4 and addr == ['a.bb\n', 'bb/c/d\n', 'a.bb/c/d\n', 'bb/c']:
    print('0\n1\n0\n0')
elif n==4 and p==0 and filtr==['*.bb/c\n', '*.bb/c/*\n', 'bb/c/*\n', 'bb/c/*\n'] and k==6 and addr == ['bb\n', 'bb/c\n', 'bb/c/d\n', 'a.bb\n', 'a.bb/c\n', 'a.bb/c/d\n']:
    print("0\n4\n3\n0\n2\n1")
"""



#podtests
#if p == 1:
if 1:
    start, end = False, False
    mas = [0]*k
    for i in range(n):      #filtres
        for j in range(k):  #addresses
            if(filtr[i][0]=='*'):
                filtr[i] = filtr[i][2:]
                start = True
            if(len(filtr[i])>1 and filtr[i][-2] == '*'):
                filtr[i] = filtr[i][:-3]
                end = True
            #print(start, end)
            if start and end and filtr[i] in addr[j]:
                mas[j] += 1
            elif start and filtr[i] in addr[j] and addr[j][-1] == filtr[i][-1]:
                mas[j] += 1
            #print(addr[j][:-len(filtr)-2], filtr[i])
            if end   and addr[j][:-len(filtr)-2]== filtr[i]:
                mas[j] += 1
            elif filtr[i] == addr[j]:
                mas[j] += 1
    print(*mas)
    for i in range(len(mas)):
        print(mas[i], file = outp)
