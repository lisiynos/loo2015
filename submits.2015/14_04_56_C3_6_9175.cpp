#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("forest.in","r",stdin);
    freopen("forest.out","w",stdout);
    long long ans;
  long double a, b, k, m, x,t;
  cin >> a >> k >> b >> m >> x;
   ans=(long long)(floor(x/(a+b-a/k-b/m)));
   long long a1=(long long)a, b1=(long long)b, k1=(long long)k, m1=(long long)m, x1=(long long)x;
   t=(a1+b1)*ans-a1*(ans/k1)-b1*(ans/m1);
   //cout << t << endl;
   if(t>=x1){
    while(1){
        if(t<x1){
            ans++;
            cout << ans;
            return 0;
        }
    if(ans%k1!=0)
        t-=a;
    if(ans%m1!=0)
        t-=b;
    ans--;

    }
   }
   while(1){
        if(t>=x1)
        break;
    ans++;
    if(ans%k1!=0)
        t+=a;
    if(ans%m1!=0)
        t+=b;

   }
   cout << ans;
    return 0;
}
