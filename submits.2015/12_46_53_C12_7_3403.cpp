#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen ("tiling.in", "r", stdin);
    freopen ("tiling.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    if (k == 1){
        cout << "8";
        return 0;
    }
    int d[2][n];
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < n; ++j){
            d[i][j] = 3;
        }
    }
    for (int j = 0; j < n; ++j){
        for (int i = 0; i < 2; ++i){
            if (i - 1 >= 0){
                d[i][j] += d[i - 1][j] - 1;
            }
            if (j - 1 >= 0){
                d[i][j] += d[i][j - 1] - 1;
            }
        }
    }
    if (n % 2){
        cout << d[1][n - 1] + 3;
    } else {
        cout << (d[1][n - 1] + 3) / 2;
    }
}
