#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    unsigned long long int n;
    cin >> n;

    if (n%2 == 0){
        cout << n*(n - 2);
    }else{
        cout << n*(n - 1);
    }
    return 0;
}
