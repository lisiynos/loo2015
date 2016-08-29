#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
using namespace std;
long long n;
long long ans=0;
void din1(long long now, vector<vector<bool> > mas){
    if (now<n){
        if (mas[now][0]==0 and mas[now][1]==0){
            mas[now][1]=1; mas[now][0]=1;
            din1(now+1,mas);
            din1(now+1,mas);
            mas[now+1][0]=1;
            din1(now+1,mas);
            mas[now+1][0]=0;
            mas[now+1][1]=1;
            din1(now+1,mas);
            mas[now+1][0]=1;
            din1(now+2,mas);
        }
        else{
            if (mas[now][0]==1 and mas[now][1]==1){
                din1(now+1,mas);
            }
            else{
                if (mas[now][0]==0){
                    mas[now][0]=1;
                    din1(now+1,mas);
                    mas[now+1][0]=1;
                    din1(now+1,mas);

                }
                else{
                    mas[now][1]=1;
                    din1(now+1,mas);
                    mas[now+1][1]=1;
                    din1(now+1,mas);
                }
            }
        }
    }
    else{
        if (mas[n][0]==0 and mas[n][1]==0){
            ans+=1;
        }
    }
}
void din(long long now, vector<vector<bool> > mas){
    //cout<<now<<" ["<<mas[0][0]<<","<<mas[0][1]<<"]["<<mas[1][0]<<","<<mas[1][1]<<"]["<<mas[2][0]<<","<<mas[2][1]<<"]"<<endl;
    if (now<n){
        if (mas[now][0]==0 and mas[now][1]==0){
            mas[now][1]=1; mas[now][0]=1;
            din(now+1,mas);
            din(now+1,mas);
            if (mas[now+1][0]==0){
                mas[now+1][0]=1;
                din(now+1,mas);
                mas[now+1][0]=0;
            }
            if (mas[now+1][1]==0){
                mas[now+1][1]=1;
                din(now+1,mas);
                if (mas[now+1][0]==0){
                    mas[now+1][0]=1;
                    din(now+2,mas);
                }
            }
        }
        else{
            if (mas[now][0]==1 and mas[now][1]==1){
                din(now+1,mas);
            }
            else{
                if (mas[now][0]==0){
                    mas[now][0]=1;
                    din(now+1,mas);
                    if (mas[now+1][0]==0){
                        mas[now+1][0]=1;
                        din(now+1,mas);
                    }
                }
                else{
                    mas[now][1]=1;
                    din(now+1,mas);
                    if (mas[now+1][1]==0){
                        mas[now+1][1]=1;
                        din(now+1,mas);
                    }
                }
            }
        }
    }
    else{
        if (mas[n][0]==0 and mas[n][1]==0){
            ans+=1;
        }
    }
}
int main(){
    freopen("tiling.in","r",stdin);
    freopen("tiling.out","w",stdout);
    long long k,p,q;
    cin>>n>>k;
    vector<vector<bool> > Q(n+1);
    for(long long i=0;i<n+1;i++){
        Q[i].resize(2);
        Q[i][0]=0;
        Q[i][1]=0;
    }
    for (long long i=0;i<k;i++){
        cin>>p>>q;
        p--;q--;
        Q[p][q]=1;
    }
    if (k!=0){
        din(0,Q);
    }
    else{
        din1(0,Q);
    }
    cout<<ans;
}
