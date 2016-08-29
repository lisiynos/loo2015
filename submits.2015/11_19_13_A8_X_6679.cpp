#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("sumsqr.in","r",stdin);
    freopen("sumsqr.out","w",stdout);
    unsigned long long a, b;
    cin >> a >> b;
    cout << a * a + b * b;
    return 0;
}
