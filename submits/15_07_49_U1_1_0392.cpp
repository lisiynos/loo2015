#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
using namespace std;
int main(){
    freopen("hall.in","r",stdin);
    freopen("hall.out","w",stdout);
    long long a,b,c,d,j,f,ans=0;
    cin>>a>>b>>c>>d;
    for (long long i=max(a,c/2-1);i<=min(b,(d/4+1)*(d/4+1));i++){
        j=1;
        while(j<((long long)sqrt(i))+1){
            if (i%j==0){
                f=i/j;
                if (f==j){
                    if (c<=4*f and d>=4*f){
                        //cout<<f<<" "<<j<<" ";
                        ans+=1;
                    }
                }
                else{
                    if (c<=2*f+2*j and d>=2*f+2*j){
                        //cout<<f<<" "<<j<<" ";
                        ans+=1;
                    }
                }
            }
            j++;
        }
    }
    cout<<ans;
}
