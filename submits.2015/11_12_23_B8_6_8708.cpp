#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    freopen("forest.in", "r", stdin);
    freopen("forest.out", "w", stdout);
    unsigned long long a, b, k, x, d, l, r, m, g, h, q, w;
    cin >> a >> k >> b >> d >> x;
    l = 1;
    r = 1000000000000000000;
    while (r - l > 1)
    {
        m = (l + r) / 2;
        q = m / k;
        w = m / d;
        g = (m - q) * a;
        h = (m - w) * b;
        if (g + h > x)
            r = m;
        else
            l = m;
            //cout << l << "   " << m  << " " << g + h << endl;
    }
    l--;
    m = l;
    q = m / k;
    w = m / d;
    g = (m - q) * a;
    h = (m - w) * b;
    if (g + h >= x)
        r = m;
    l++;
    m = l;
    q = m / k;
    w = m / d;
    g = (m - q) * a;
    h = (m - w) * b;
    if (g + h >= x)
        r = min(l, r);
    cout << r;
    return 0;
}
