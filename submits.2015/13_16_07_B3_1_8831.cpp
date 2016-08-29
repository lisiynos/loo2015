#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("hall.in", "r", stdin);
    freopen("hall.out", "w", stdout);

    long long int A, B, C, D;

    cin >> A >> B >> C >> D;

    long long int a = 1, b = 1, k = 0, j=0;;

    while (((a*b)<=B) && ((2*a+2*b)<=D)){

        j++;
        b = j;

        if (((a*b)<=B) && ((2*a+2*b)<=D) && ((a*b)>=A) && ((2*a+2*b)>=C))
            k++;

         while (((a*b)<=B) && ((2*a+2*b)<=D)){
            b++;

            if (((a*b)<=B) && ((2*a+2*b)<=D) && ((a*b)>=A) && ((2*a+2*b)>=C))
                k++;
        }

        b = 1;
        a++;
    }

    cout << k;

    return 0;
}
