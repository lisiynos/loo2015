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
    for (long long i=1;i<=sqrt(b);i++){
        j=min((d-2*i)/2,b/i);
        if (j>=i){
            //cout<<i<<" "<<j<<endl;
            ans+=j;
        }
    }
    for (long long i=1;i<=sqrt(a);i++){
        j=max((c-2*i)/2,a/i);
        if (j>=i){
            ans-=j;
        }
    }
    cout<<ans;
}
