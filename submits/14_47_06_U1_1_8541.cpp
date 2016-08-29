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
    for (long long i=c;i<d;i++){
        j=1;
        while(j<((long long)sqrt(i))+1){
            if (i%j==0){
                f=i/j;
                if (f==j){
                    if (a<=4*f and b>=4*f){
                        ans+=1;
                    }
                }
                else{
                    if (a<=2*f+2*j and b>=2*f+2*j){
                        ans+=1;
                    }
                }
            }
            j++;
        }
    }
    cout<<ans;
}