import sys
sys.stdin=open('circle.in','r')
sys.stdout=open('circle.out','w')
n=int(input())
if n%2==0:
    print(n*(n-2))
else:
    print(n*(n-1))