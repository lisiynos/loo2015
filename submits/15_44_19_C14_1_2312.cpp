#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
    freopen("hall.in", "r", stdin);
    freopen("hall.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c += c % 2;
    d -= c % 2;
    c /= 2;
    d /= 2;
    int x = sqrt(b) + 1;
    long long ans = 0;
    for (int i = 1; i < x; i++)
    {
        int r = min(d - i, b  / i);
        int l = max((int)ceil(a * 1.0 / i), c - i);
        //cout << l << " " << r << endl;
        ans += max(0, r - l + 1);
    }
    cout << (long long)ceil(ans / 2.0) << endl;
    return 0;
}
