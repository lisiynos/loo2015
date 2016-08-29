import sys
sys.stdin=open('forest.in','r')
sys.stdout=open('forest.out','w')
a,k,b,m,x=map(int,input().split())
i=0
y=0
while y<x:
    i+=1
    if i%k!=0:
        y+=a
    if i%m!=0:
        y+=b
print(i)