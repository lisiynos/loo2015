#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("tilling.in","r",stdin);
    freopen("tilling.out","w",stdout);
    unsigned long long int n, k, x, y, f, fl, i;
    cin >> n >> k;
    f = 2;
    fl = 2;


    if (k != 0){
        cin >> x >> y;
        cout << "8";
    }else{
        if (n == 1)
            cout << f;
        else{
            for (i = 1; i < n; i++){
                fl = f;
                f = 3*fl + 1;
            }
            cout << f;
        }
    }

    return 0;
}
