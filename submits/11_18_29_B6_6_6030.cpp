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
    unsigned long long int r = 1000000000000000000;


    while(l != r-1){
        ans = (l+r)/2;
        if ((a*ans + b*ans - (ans*a)/k - (ans*b)/m) > x){
            r = ans;
        }else{
            l = ans;
        }
    }
    cout << l;

    return 0;
}
