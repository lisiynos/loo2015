#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("sumsqrt.in", "r", stdin);
    freopen("sumsqrt.out", "w", stdout);

    long long int a, b;

    cin >> a >> b;

    a*=a;
    b*=b;

    cout << a+b;

    return 0;
}
