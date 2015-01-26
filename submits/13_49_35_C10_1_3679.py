from math import ceil

inp = open('hall.in')
outp= open('hall.out','w')

a, b, c, d = inp.readline().split()
a, b, c, d = int(a), int(b), int(c), int(d)

sum = 0
x = [-100]
y = [-100]
for i in range(1, b+1):
    for j in range(1, int(b/2)+2):
        if i*j>=a and i*j <=b:
            if (i+j)*2<=d and (i+j)*2 >= c:
                  x.append(j)
                  y.append(i)
                  sum+=1
                  #print(i,j)
print(ceil(sum/2), file=outp)
