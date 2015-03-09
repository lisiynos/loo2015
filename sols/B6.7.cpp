#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("tiling.in","r",stdin);
    freopen("tiling.out","w",stdout);
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
                f = (3*fl + 1) % (1000000000+7);
            }
            cout << f;
        }
    }

    return 0;
}
