import sys
sys.stdin=open('forest.in','r')
sys.stdout=open('forest.out','w')
d,d_kol,f,f_kol,x=map(int,input().split())
day=1
while x>0:
    if day%d_kol!=0:
        x-=d
    if day%f_kol!=0:
        x-=f
    day+=1
print(day-1)
