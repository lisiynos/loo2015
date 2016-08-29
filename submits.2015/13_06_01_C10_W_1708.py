inp = open('sum.in')
outp= open('sum.out','w')

a, b = inp.readline().split()
a,b=int(a),int(b)
print(a+b, file =outp)
