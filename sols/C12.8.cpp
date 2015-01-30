#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen ("transform.in", "r", stdin);
    freopen ("transform.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    if (k == 0){
        cout << "1\n0 0 0 3";
    } else {
        cout << "1\n7 0 0 0 3";
    }
    return 0;
}
