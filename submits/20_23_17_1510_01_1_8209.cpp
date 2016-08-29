#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{   freopen("hall.in","r",stdin);
    freopen("hall.out","w",stdout);
    int a,b,c,d,i,j,k=0,l=0;
    cin>>a>>b>>c>>d;
    for (int i=1; i<=b; i++){
        for (int j=1; j<=b; j++){
            if ((a<=i*j) and (b>=i*j) and (c<=2*(i+j)) and (d>=2*(i+j))){
                k++;
                if (i!=j) {
                    l++;
                }
            }
        }
    }
    cout << k-(l/2) << endl;
    return 0;
}