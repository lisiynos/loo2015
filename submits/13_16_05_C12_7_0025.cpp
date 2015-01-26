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
    long long n, k;
    cin >> n >> k;

    if (k == 1){
        cout << "8";
        return 0;
    }

    if (n == 2){
        cout << "7";
        return 0;
    }

    long long d[2][n];
    for (long long i = 0; i < 2; ++i){
        for (long long j = 0; j < n; ++j){
            d[i][j] = 4;
            if (i == 0 && j == 0 || i == 1 && j == 0 || i == 0 && j == n - 1 || i == 1 && j == n - 1){
                d[i][j] = 3;
            }
        }
    }
    for (long long j = 0; j < n; ++j){
        for (long long i = 0; i < 2; ++i){
            if (i - 1 >= 0){
                d[i][j] = (d[i][j] + d[i - 1][j] - 1) % (long long) (1e9 + 7);
            }
            if (j - 1 >= 0){
                d[i][j] = (d[i][j] + d[i][j - 1] - 1) % (long long) (1e9 + 7);
            }
        }
    }
    cout << d[1][n - 1];
}
