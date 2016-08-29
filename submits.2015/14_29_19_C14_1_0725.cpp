#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
const long double eps = 1e-9;

int main()
{
    freopen("hall.in", "r", stdin);
    freopen("hall.out", "w", stdout);
    int a, b, c, d, d1, d2;
    cin >> a >> b >> c >> d;
    long long ans = 0;
    long double sd1, sd2;
    int l1, r1;
    c += c % 2;
    d -= c % 2;
    c /= 2;
    d /= 2;
    for (int i = c; i <= d; i++)
    {
        d1 = i * i - 4 * a;
        if (d1 >= 0)
        {
            sd1 = sqrt(d1);
            r1 = (i + sd1) / 2.0;
            l1 = ceil((i - sd1) / 2.0);
            ans += ceil((r1 - l1 + 1) / 2.0);
            d2 = i * i - 4 * b;
            if (d2 >= 0)
            {
                sd2 = sqrt(d2);
                r1 = floor((i + sd2) / 2.0);
                l1 = ceil((i - sd2) / 2.0);
                if (r - r1 < eps)
                    r1--;
                if (l1 - l < eps)
                    l1++;
                ans -= ceil((r1 - l1 + 1) / 2.0);;
            }
        }

    }
    cout << ans << endl;
}
