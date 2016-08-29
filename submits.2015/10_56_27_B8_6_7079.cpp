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
        if (g + h >= x)
            r = m;
        else
            l = m;
            //cout << m << "   " << g  << " " << h << endl;
    }
    m = l;
    q = m / k;
    w = m / d;
    g = (m - q) * a;
    h = (m - w) * b;
    if (g + h >= x)
        r = m;
    cout << r;
    return 0;
}
