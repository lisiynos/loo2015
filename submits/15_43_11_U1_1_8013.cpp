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
    long long a,b,c,d,j,f,l,k,m,ans=0;
    cin>>a>>b>>c>>d;
    for (long long i=1;i<=sqrt(b);i++){
        l=(c-2*i)/2;
        if (((float)(c-2*i)/2)!=(c-2*i)/2){
            l+=1;
        }
        k=a/i;
        if (a%i!=0){
            k+=1;
        }
        j=min((d-2*i)/2,b/i);
        f=max(k, l);
        f=max(f,i);
        f=max((long long)0, (long long)j-f+1);
        ans+=f;
    }
    cout<<ans;
}
