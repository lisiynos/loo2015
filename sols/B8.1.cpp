#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int main()
{
    freopen("hall.in", "r", stdin);
    freopen("hall.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long counter = 0;

    for (int i = 1; i <= d; i++)
    {
        for (int j = i; j <= d; j++)
        {
            long long z = i * j;
            long long x = 2 * (i + j);
            bool e = ((z <= b)&&(z >= a));
            bool f = ((x <= d)&&(x >= c));
            if (f&e)
            {
                counter++;
            }
        }
    }
    cout << counter;
    return 0;
}
