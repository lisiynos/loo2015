#include <iostream>
#include <cstdio>

using namespace std;
bool swich=false;
int swich2 = 0;

int main()
{
    //freopen("hall.txt","r",stdin);
    //freopen("hallout.txt","w",stdout);
    unsigned long long int a, b, c, d;
    unsigned long long int i, j, minimum;
    unsigned long long int counter = 0;
    cin >> a >> b >> c >> d;
    minimum = 1;

    for (i = d/2; i>=1; i--){
        swich = false;
        for (j = minimum; j<=i; j++){
            if ((i*j >= a) and (i*j <= b) and (2 * (i+j) >= c) and (2 * (i+j) <= d)){
                counter++;
                //cout << i << ' ' << j << endl;
                if (!swich){
                    minimum = j;
                    swich = true;
                }
            }else{
                if (swich)
                    break;
            }
        }
        if (!swich)
            swich2++;
        if (swich2>15)
            break;
    }

    cout << counter;
    return 0;
}
