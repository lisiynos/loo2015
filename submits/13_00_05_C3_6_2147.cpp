#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long a, b, k, m, x, q, ans=1;
long long kol(long long ans){
return (a+b)*ans-a*(ans/k)-b*(ans/m);
}

int main()
{
    freopen("forest.in","r",stdin);
    freopen("forest.out","w",stdout);

  cin >> a >> b >> k >> m >> x;
  q=(a+b)*ans-a*(ans/k)-b*(ans/m);
  if(q>=x)
    cout << ans;
    long long i=0;
    ans=0;
  while(1){
        if(kol(ans+pow(2,i))<x&&kol(ans+pow(2,i)+1)>=x){
            cout << ans+pow(2,i)+1;
            return 0;
        }

    if(kol(ans+pow(2,i+1))<x){
        i++;
        continue;
    }
    ans+=pow(2,i);
    i=1;

  }
    return 0;
}
