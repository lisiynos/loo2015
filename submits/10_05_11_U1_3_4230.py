import sys
sys.stdin=open('river.in','r')
sys.stdout=open('river.out','w')
n,p=map(int,input().split())
z=list(map(int,input().split()))
first=0
sum_=0
gr=[[] for i in range(n)]
for i in range(len(z)):
    gr[i]=[z[i],i-1,i+1]
    sum_+=z[i]**2
    #positions[i]=i
print(sum_)
gr[n-1][2]=-1
k=int(input())
for i in range(k):
    e,v=map(int,input().split())
    v-=1
    f=first
    for i in range(v):
        f=gr[f][2]
    #print('Im here',f)
    left=gr[f][1]
    right=gr[f][2]
    if e==1:
        sum_-=gr[f][0]**2
        if left!=-1 and right!=-1:
            s=gr[f][0]//2
            sum_-=gr[left][0]**2
            sum_-=gr[right][0]**2
            if gr[f][0]%2==0:
                gr[left][0]+=s
                gr[right][0]+=s
                sum_+=gr[left][0]**2+gr[right][0]**2
                gr[left][2]=gr[f][2]
                gr[right][1]=gr[f][1]
                gr[f][1]=-1
                gr[f][2]=-1
            else:
                #print(gr[f])
                #print(gr[right])
                #print(gr[left])
                gr[left][0]+=s
                gr[right][0]+=s+1
                sum_+=gr[left][0]**2+gr[right][0]**2
                gr[left][2]=gr[f][2]
                gr[right][1]=gr[f][1]
                gr[f][1]=-1
                gr[f][2]=-1
                #print(gr[right])
                #print(gr[left])
        elif left==-1:
            sum_-=gr[right][0]**2
            gr[right][0]+=gr[f][0]
            sum_+=gr[right][0]**2
            gr[f][2]=-1
            gr[right][1]=-1
            first=right
        else:
            sum_-=gr[left][0]**2
            gr[left][0]+=gr[f][0]
            sum_+=gr[left][0]**2
            gr[f][1]=-1
            gr[left][2]=-1
        print(sum_)
    else:
        sum_-=gr[f][0]**2
        if gr[f][0]%2==0:
            gr.append([gr[f][0]//2,f,right])
            gr[f][0]=gr[f][0]//2
            gr[f][2]=len(gr)-1
            if right!=-1:
                gr[right][1]=len(gr)-1
            sum_+=(gr[f][0]**2)*2
        else:
            gr.append([gr[f][0]//2+1,f,right])
            gr[f][0]=gr[f][0]//2
            gr[f][2]=len(gr)-1
            if right!=-1:
                gr[right][1]=len(gr)-1
            sum_+=gr[f][0]**2+(gr[f][0]+1)**2
        print(sum_)
