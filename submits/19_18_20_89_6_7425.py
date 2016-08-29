import sys
sys.stdin=open('forest.in','r')
sys.stdout=open('forest.out','w')
d,d_kol,f,f_kol,x=map(int,input().split())
day=0
a=d_kol
b=f_kol
while a!=b:
    if a>b:
        b+=f_kol
    else:
        a+=d_kol
max_day=a
a=max_day//d_kol
b=max_day//f_kol
s1=(max_day-a)*d
s2=(max_day-b)*f
s=s1+s2
put=x//s
put2=x%s
while put2>0:
    day+=1
    if day%d_kol!=0:
        put2-=d
    if day%f_kol!=0:
        put2-=f
print(day+put*s)