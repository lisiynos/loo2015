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
    freopen("river.in", "r", stdin);
    freopen("river.out", "w", stdout);
    int n, k, p;
    cin >> n >> p;
    vector <long long> a;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> k;

    long long counter  = 0;
    for (int h = 0; h < a.size(); h++)
    {
        counter += a[h] * a[h];
    }
    cout << counter << endl;
    int j, e;
    for (int i = 0; i < k; i++)
    {
        cin >> e >> j;
        j--;
        if (e == 1)
        {
            int l, r;
            l = a[j]/2;
            r = a[j] - l;
            if (j == 0)
            {
                a[j + 1] += (l + r);
            }

            if (j == a.size() - 1)
            {
                a[j - 1] += (l + r);
            }

            if ((j > 0)&&(j < a.size() - 1))
            {
                a[j + 1] += r;
                a[j - 1] += l;
            }
            a.erase(a.begin() + j);
        }
        else
        {
            int l, r;
            l = a[j]/2;
            r = a[j] - l;
            a[j] = l;

            a.insert(a.begin() + j, r);
        }
        long long counter  = 0;
        for (int h = 0; h < a.size(); h++)
        {
            counter += a[h] * a[h];
        }
        cout << counter << endl;
    }

    return 0;
}
