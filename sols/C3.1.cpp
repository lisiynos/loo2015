#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("hall.in","r",stdin);
    freopen("hall.out","w",stdout);
    long long A,B,C,D,ans=0;
    cin >> A >> B >> C >> D ;
    for (int a=1;a<=B;a++ ){
       for (int b=a;b<=B/a;b++){
        if(a*b>=A && a*b<=B && 2*(a+b)>=C && 2*(a+b)<=D)
          ans++;
       }
    }
    cout << ans;
    return 0;
}
