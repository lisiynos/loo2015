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

  cin >> a >> k >> b >> m >> x;
  q=(a+b)*ans-a*(ans/k)-b*(ans/m);
  /*for(int i=0;i<10;i++)
    cout << kol(i) << " ";
  cout << endl;*/
  if(q>=x){
    cout << ans;
    return 0;
    }
    long long i=-1;
    ans=0;
  while(1){
        if(kol(ans)<x&&kol(ans+1)>=x){
            cout << ans+1;
            return 0;
        }
   /*while(kol(ans+1<<(i+1))<x){

        i++;
        cout << "R";
  }*/
  while(1){
        if(kol(ans+(1<<(i+1)))<x){
        i++;
       // cout << "R" << ans;
        continue;
        }
        break;
  }
 // cout << "L";
    ans+=1<<i;
    i=-1;


  }
    return 0;
}
