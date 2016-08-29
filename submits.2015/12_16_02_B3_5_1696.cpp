#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "w", stdout);

    long long int n;

    cin >> n;

    if (n % 2 == 0)
        n = n*(n-2);
    else
        n = n*(n-1);

    cout << n;
}
