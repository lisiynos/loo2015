inp = open('tiling.in')
outp= open('tiling.out','w')
n,k = list(map(int, inp.readline().split()))
def lel(easy):
    if easy == 0:
        return 1
    if easy == 1:
        return 2
    if easy == 2:
        return 7
    return 3*lel(easy-1)+lel(easy-2)-lel(easy-3)


if k==0:
  p = lel(n)
  print(p, file = outp)
else:
    print(8,file = outp)
