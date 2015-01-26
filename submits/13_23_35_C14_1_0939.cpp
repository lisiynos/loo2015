#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    freopen("hall.in", "r", stdin);
    freopen("hall.out", "w", stdout);
    int a, b, c, d, d1, d2, num, num1;
    cin >> a >> b >> c >> d;
    long long ans = 0;
    c += c % 2;
    d -= c % 2;
    c /= 2;
    d /= 2;
    for (int i = c; i <= d; i++)
    {
        d1 = i * i - 4 * a;
        if (d1 >= 0)
            num = sqrt(d1);
        else
            num = 0;
        d2 = i * i - 4 * b;
        if (d2 >= 0)
            num -= sqrt(d1);
        ans += max(0, num);
    }
    cout << ans << endl;
}
