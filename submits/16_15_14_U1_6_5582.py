import sys
def binp():
    start=0
    end=10**18
    while True:
        s=(start+end)//2
        d1=a*s-a*(s//k)
        d2=a*(s-1)-a*((s-1)//k)
        f1=b*s-b*(s//m)
        f2=b*(s-1)-b*((s-1)//m)
        if d1+f1>=x:
            if d2+f2<x:
                return(s)
            else:
                end=s-1
        else:
            start=s+1
sys.stdin=open('forest.in','r')
sys.stdout=open('forest.out','w')
a,k,b,m,x=map(int,input().split())
print(binp())