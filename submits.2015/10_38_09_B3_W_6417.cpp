#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);

    long long int a, b;

    cin >> a >> b;

    //a*=a;
    //b*=b;

    cout << a+b;

    return 0;
}
