#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    freopen("tiling.in", "r", stdin);
    freopen("tiling.out", "w", stdout);
    int n, k;
    if (k == 1)
    {
        cout << 8;
        return 0;
    }
    long long c, gg = 1000000007;
    cin >> n >> k;
    c = 2;
    for (int i = 1; i < n; i++)
    {
        c = (c * 3 + 1) % gg;
    }
    cout << c;
    return 0;
}
