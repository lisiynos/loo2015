#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);
    long long n, a;
    cin >> n;
    if (n % 2 == 0)
        a = n * (n - 2);
    else
        a = n * (n - 1);
    cout << a;
    return 0;
}
