#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("sweets.in","r",stdin);
    freopen("sweets.out","w",stdout);
    int N, a, b, c;
    cin >> N >> a >> b >> c;
    int p = a + b + c;
    int minDim;
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    if (a > b) swap(a,b);
    int a1 = a, b1 = b, c1 = c;
    bool flag;
    while (N > p){
        flag = false;
        if (a1 > b1)
            if (b1 > c1){
                if (N > p + c ){
                    c1 += c;
                    p += c;
                    flag = true;
                }
            }
            else{
                if (N > p + b ){
                    b1 += b;
                    p += b;
                    flag = true;
                }
            }
        else
            if (a1 > c1){
                if (N > p + c ){
                    c1 += c;
                    p += c;
                    flag = true;
                }
            }
            else{
                if (N > p + a ){
                    a1 += a;
                    p += a;
                    flag = true;
                }
            }
        if (!flag) break;
    }
    cout << a1 << ' ' << b1 << ' ' << c1;
    return 0;
}
