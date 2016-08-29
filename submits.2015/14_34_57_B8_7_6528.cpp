#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map <pair <int, int>, long long> z;
map <pair <int, int>, bool> x;
long long gg = 1000000007;
int n;
long long h (int i, int j)
{
    //cout << i << " " << j << endl;
    if ((i == n - 1)&&(j == n - 1))
    {
        //cout << i << " r " << j << " 2" << endl;
        return 2;
    }
    if (((i == n - 1)&&(j == n))||((j == n - 1)&&(i == n)))
    {
        //cout << i << " r " << j << " 1" << endl;
        return 1;
    }
    if ((i == n)&&(j == n))
    {
        //cout << i << " r " << j << " 1" << endl;
        return 1;
    }
    long long c = 0;
    if ((i + 2 <= n)&&(j + 1 <= n))
    {
        if (!x[make_pair(i + 2, j + 1)])
        {
            x[make_pair(i + 2, j + 1)] = true;
            z[make_pair(i + 2, j + 1)] = h(i + 2, j + 1) % gg;
            x[make_pair(j + 1, i + 2)] = true;
            z[make_pair(j + 1, i + 2)] = z[make_pair(i + 2, j + 1)];
        }
        c = (c + z[make_pair(i + 2, j + 1)]) % gg;
    }

    if ((i + 1 <= n)&&(j + 1 <= n))
    {
        if (!x[make_pair(i + 1, j + 1)])
        {
            x[make_pair(i + 1, j + 1)] = true;
            z[make_pair(i + 1, j + 1)] = h(i + 1, j + 1) % gg;
            x[make_pair(j + 1, i + 1)] = true;
            z[make_pair(j + 1, i + 1)] = z[make_pair(i + 1, j + 1)];
        }

        c = (c +  z[make_pair(i + 1, j + 1)]) % gg;
        c = (c + z[make_pair(i + 1, j + 1)]) % gg;
    }

    if ((j + 2 <= n)&&(i + 1 <= n))
    {
        if (!x[make_pair(i + 1, j + 2)])
        {
            x[make_pair(i + 1, j + 2)] = true;
            z[make_pair(i + 1, j + 2)] = h(i + 1, j + 2) % gg;
            x[make_pair(j + 2, i + 1)] = true;
            z[make_pair(j + 2, i + 1)] = z[make_pair(i + 1, j + 2)];
        }
        c = (c + z[make_pair(i + 1, j + 2)]) % gg;
    }

    if ((j + 2 <= n)&&(i + 2 <= n))
    {
        if (!x[make_pair(i + 2, j + 2)])
        {
            x[make_pair(i + 2, j + 2)] = true;
            z[make_pair(i + 2, j + 2)] = h(i + 2, j + 2) % gg;

            x[make_pair(j + 2, i + 2)] = true;
            z[make_pair(j + 2, i + 2)] = z[make_pair(i + 2, j + 2)];
        }
        c = (c + z[make_pair(i + 2, j + 2)]) % gg;
    }
    //cout << i << " r " << j << " " << c << endl;
    z[make_pair(i, j)] = c;
    z[make_pair(j, i)] = c;
    return c;
}
int main()
{
    freopen("tiling.in", "r", stdin);
    freopen("tiling.out", "w", stdout);
    int k;
    long long b;

    cin >> n >> k;
    if (k == 1)
    {
        cout << 8;
        return 0;
    }
    if (k == 2 * n)
    {
        cout << 1;
        return 0;
    }
    b = h(0, 0);
    cout << b;
    return 0;
}
