inp = open('hall.in')
outp= open('hall.out','w')

a, b, c, d = inp.readline().split()
a, b, c, d = int(a), int(b), int(c), int(d)

sum = 0
x = [-100]
y = [-100]
for i in range(1, b+1):
    for j in range(1,b):
        if i*j>=a and i*j <=b:
            if (i+j)*2<=d and (i+j)*2 >= c:
              count = 0
              for k in range(len(x)):
                if x[k] != i or y[k] != j:
                  count+=1
              if count >= len(x):
                  x.append(j)
                  y.append(i)
                  sum+=1
                  print(i,j)
print(sum, file=outp)
print(sum)
