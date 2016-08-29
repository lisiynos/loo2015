#include <iostream>
#include <cstdio>

using namespace std;
bool swich=false;

int main()
{
    freopen("hall.in","r",stdin);
    freopen("hall.out","w",stdout);
    unsigned long long int a, b, c, d;
    unsigned long long int i, j;
    unsigned long long int counter = 0;
    cin >> a >> b >> c >> d;

    for (i = d/2; i>=c/2-1; i--){
        swich = false;
        for (j = 1; j<=i; j++){
            if ((i*j >= a) and (i*j <= b) and (2 * (i+j) >= c) and (2 * (i+j) <= d)){
                counter++;
                cout << i << ' ' << j << endl;
                swich = true;
            }else{
                if (swich)
                    break;
            }
        }
    }

    cout << counter;
    return 0;
}
