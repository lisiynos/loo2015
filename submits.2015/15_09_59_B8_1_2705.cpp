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
    int l, r, counter = 0;
    l = max(a, (c/2) - 1);
    r = min(b, (d/2) - 1);
    //cout << l << " " << r << endl;
    r++;
    for (int i = l; i <= r; i++)
    {
        int g = min((b/i), (d/2 - i));
        counter += min(g, i);
        //cout << g << " " << i << " " << counter << endl;
    }
    cout << counter;
    return 0;
}
