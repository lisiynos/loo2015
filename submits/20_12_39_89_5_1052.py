import sys
sys.stdin=open('circle.in','r')
sys.stdout=open('circle.out','w')
n=int(input())
if n%2==0:
    print((n-2)*n)
else:
    print((n-1)*n)
