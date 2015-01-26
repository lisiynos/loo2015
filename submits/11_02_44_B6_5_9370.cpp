#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("forest.in","r",stdin);
    freopen("forest.out","w",stdout);
    unsigned long long int k, m, x, a, b, ans;
    cin >> a >> k >> b >> m >> x;
    unsigned long long int l = 1;
    unsigned long long int r = x*100;


    while(l != r-1){
        ans = (l+r)/2;
        if ((a*ans + b*ans - (ans/k) - (ans/m)) > x){
            r = ans;
        }else{
            l = ans;
        }
    }
    cout << ans+1;

    return 0;
}
