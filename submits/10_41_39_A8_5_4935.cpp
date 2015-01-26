#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n;
    cin >> n;
    cout << n * (n - 1) + n * (n % 2);
    return 0;
}
