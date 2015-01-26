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

    for (int i = a; i <= d; i++)
    {
        int g = min(max(b/i, 0), max(d/2 - i, 0));
        counter += min(g, i);
        //cout << g << " " << i << " " << counter << endl;
    }
    cout << counter;
    return 0;
}
