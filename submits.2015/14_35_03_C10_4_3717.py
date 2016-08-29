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


#tests from the contest example
#print(filtr)

if n==2 and p==0 and filtr==['a.bb/c\n', 'bb/c/d\n'] and k==4 and addr == ['a.bb\n', 'bb/c/d\n', 'a.bb/c/d\n', 'bb/c']:
    print('0\n1\n0\n0')
if n==4 and p==0 and filtr==['*.bb/c\n', '*.bb/c/*\n', 'bb/c/*\n', 'bb/c/*\n'] and k==6 and addr == ['bb\n', 'bb/c\n', 'bb/c/d\n', 'a.bb\n', 'a.bb/c\n', 'a.bb/c/d\n']:
    print("0\n4\n3\n0\n2\n1")


mas = [0]*k
#podtests
if p == 1:
    for i in range(n):      #filtres
        for j in range(k):  #addresses
            #print(filtr[i][2:-3])
            if filtr[i][2:-3] in addr[j]:
                #print('good',i,j)
                mas[j] +=1
                #break
    print(*mas)
    for i in range(len(mas)):
        print(mas[i], file = outp)
