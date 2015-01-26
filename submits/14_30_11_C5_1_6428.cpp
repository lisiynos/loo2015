#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("hall.in", "r", stdin);
    freopen("hall.out", "w", stdout);
    int A, B, C, D, y, k, a, b, c, d;
    cin >> A >> B >> C >> D;
    k = 0;
    y = 1;
    if (C % 2 == 0) C = C / 2;
    else C = (C / 2) + 1;
    D = D / 2;
    while (y * y <= B){
        b = B / y;
        if (A % y == 0)
            a = A / y;
        else a = (A / y) + 1;
        if (C > y) c = C - y;
        else c = 0;
        if (D > y) d = D - y;
        else d = 0;
        a = max(a, y);
        c = max(c, y);
        if ((b >= a) & (d >= c)) {
            if ((c <= a) & (d >= b))
                k += (b - a) + 1;
            else if ((c >= a) & (d <= b))
                k += (d - c) + 1;
            else if ((c <= a) & (d >= a) & (d <= b))
                k += (d - a) + 1;
            else if ((c >= a) & (c <= b) & (d >= b))
                k += (b - c) + 1;
        }
        y++;
    }
    cout << k;
    return 0;
}