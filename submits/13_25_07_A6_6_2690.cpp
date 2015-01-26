#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;
int main () {
    double a, k, b, m, x, l, t;
    int i;
    freopen("forest.in","r", stdin);
    freopen("forest.out", "w", stdout);
    //scanf("%f %f %f %f %f", &a, &k, &b, &m, &x);
    cin >> a >> k >> b >> m >> x;
    //printf("%f %f %f %f %f", a, k, b, m, x);
    l = floor((x*k*m)/(a*m*(k-1)+b*k*(m-1)));
    for (i = -50; i <= 50; i++){
        t = l + i;
        //printf("%d %d %d\n", t, i, l);
        if (((t - floor(t/k))*a + (t - floor(t/m))*b) >= x) {
            printf("%d\n", int(t), ((t - floor(t/k))*a + (t - floor(t/m))*b), x);
            break;
        }
    }

}
