inp = open('hall.in')
outp= open('hall.out','w')

a, b, c, d = inp.readline().split()
a, b, c, d = int(a), int(b), int(c), int(d)

sum = 0
count = 0
x = [-100]
y = [-100]
for i in range(1, b+1):
    for j in range(1,int(b/2)):
        #print(i*j, i+j)
        if i*j>=a and i*j <=b:
            if (i+j)*2<=d and (i+j)*2 >= c:
              count = 0
              for k in range(len(x)):
                if x[k] != i or y[k] != j:
                  count+=1
              #print(i,j)
              if count == len(x):
                  x.append(j)
                  y.append(i)
                  #print(i,j)
                  sum+=1
                  #print(i,j)
                  break
print(sum, file=outp)
