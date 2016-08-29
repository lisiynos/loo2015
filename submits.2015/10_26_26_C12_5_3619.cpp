#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen ("circle.in", "r", stdin);
    freopen ("circle.out", "w", stdout);
    int n;
    cin >> n;
    if (n % 2){
        cout << (n / 2) * n * 2;
    } else {
        cout << n * (n / 2 - 1) * 2;
    }
}
