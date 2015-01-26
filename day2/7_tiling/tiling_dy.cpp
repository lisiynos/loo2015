#include <bits/stdc++.h>
#define TASK "tiling"
using namespace std;

int const N = 101000;
int const MOD = 1000000007;

int n, k;
bool blocked[2][N];
int dp[N], up[N], down[N];

template <typename t>
void upd(t & a) {
    while (a >= MOD) {
        a -= MOD;
    }
}

int main() {                           
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int x, y, i = 0; i < k; ++i) {
        scanf("%d%d", &x, &y);
        blocked[y - 1][x - 1] = true;       
    }
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
         if (blocked[0][i - 1] && blocked[1][i - 1]) {
            dp[i] = dp[i - 1];
         } else if (blocked[0][i - 1]) {
            dp[i] = dp[i - 1];
            if (i == 1 || !blocked[1][i - 2]) {
                    dp[i] += up[i - 1];
                upd(dp[i]);
                    }
            up[i] = dp[i - 1];
         } else if (blocked[1][i - 1]) {
            dp[i] = dp[i - 1];
            if (i == 1 || !blocked[0][i - 2]) {
                dp[i] += down[i - 1];
                upd(dp[i]);
            }
            down[i] = dp[i - 1];
         } else {
            long long res = 0;
            res += 2 * dp[i - 1];
            if (i == 1 || !blocked[1][i - 2]) {
                res += up[i - 1];
                    }
            if (i == 1 || !blocked[0][i - 2]) {
                res += down[i - 1];
                    }
            if (i > 1 && !blocked[0][i - 2] && !blocked[1][i - 2]) {
                res += dp[i - 2];
            }
            upd(res);
            dp[i] = res;   
            res = dp[i - 1];
            if (i == 1 || !blocked[1][i - 2]) {
                res += up[i - 1];
                    }
            upd(res);
            down[i] = res;
            res = dp[i - 1];
            if (i == 1 || !blocked[0][i - 2]) {
                res += down[i - 1];
                    }
            upd(res);
            up[i] = res;    
         }
    }
    printf("%d\n", dp[n]);
    /*for (int i = 0; i <= n; ++i) {
        cerr << dp[i] << " " ;
    }cerr << "\n";
    for (int i = 0; i <= n; ++i) {
        cerr << up[i] << " " ;
    }cerr << "\n";
    for (int i = 0; i <= n; ++i) {
        cerr << down[i] << " " ;
    }cerr << "\n"; */
    return 0;   
}
