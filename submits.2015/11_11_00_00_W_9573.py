a, b = [int(x) for x in open('sum.in').read().split()]
open('sum.out', 'w').write(str(a+b) + '\n')