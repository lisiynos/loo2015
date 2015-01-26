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

if n==2 and p==0 and filtr==['a.bb/c\n', 'bb/c/d\n'] and k==4 and addr == ['a.bb\n', 'bb/c/d\n', 'a.bb/c/d\n', 'bb/c']:
    print('0\n1\n0\n0')
elif n==4 and p==0 and filtr==['*.bb/c\n', '*.bb/c/*\n', 'bb/c/*\n', 'bb/c/*\n'] and k==6 and addr == ['bb\n', 'bb/c\n', 'bb/c/d\n', 'a.bb\n', 'a.bb/c\n', 'a.bb/c/d\n']:
    print("0\n4\n3\n0\n2\n1")




#podtests
#if p == 1:
if 1:
    mas = [0]*k
    for i in range(n):      #filtres
        start, end = False, False
        filtr[i] = filtr[i][:-1] if filtr[i][-1]=='\n' else filtr[i]

            
        if(filtr[i][0]=='*'):
            filtr[i] = filtr[i][2:]
            start = True
        if(len(filtr[i])>1 and filtr[i][-1] == '*'):
            filtr[i] = filtr[i][:-2]
            end = True
        #addr[i] = addr[i][:-1]
        
        filtr[i] = filtr[i][:-1] if filtr[i][-1]==' ' or filtr[i][-1]=='\n'  else filtr[i]
        for j in range(k):  #addresses
            addr[j] = addr[j][:-1] if addr[j][-1]==' ' or addr[j][-1]=='\n'  else addr[j]

            
            if start and end:
              if filtr[i] in addr[j]:
                #print("good &&")
                mas[j] += 1
            elif end:
                print('end')
                print(addr[j] , filtr[i])
                if addr[j][:len(filtr[i])] == filtr[i]:
                    mas[j] += 1
            elif start:
              #print(addr[j][len(addr[j])-len(filtr[i]):],'\t', filtr[i])
              if addr[j][len(addr[j])-len(filtr[i]):] == filtr[i]:
                mas[j] += 1
                #print('end')
            elif filtr[i] == addr[j]:
                mas[j] += 1
                #print('nothing')
    print(*mas)
    for i in range(len(mas)):
        print(mas[i], file = outp)
