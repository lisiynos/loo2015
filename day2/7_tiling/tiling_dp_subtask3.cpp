#include <bits/stdc++.h>

const int maxn = 100000;
const int mod = 1e9 + 7;

void add(int &value, int x) {
    if ((value += x) >= mod)
        value -= mod;
}

int main() {
    freopen("tiling.in", "r", stdin);
    freopen("tiling.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    assert(1000 < n && n <= maxn && k == 0);
    std::vector < std::vector <int> > dp(n + 1, std::vector <int>(2));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    for (int msk = 0; msk < 2; msk++) {
        dp[i][msk] = 0;
        if (!msk) {
            add(dp[i][msk], dp[i - 1][0] * 2 % mod);
            if (i > 1) {
                add(dp[i][msk], dp[i - 2][0]);
                add(dp[i][msk], dp[i - 1][1] * 2 % mod);
            }
        }
        if (msk == 1) {
            dp[i][msk] = dp[i - 1][0];
            if (i > 1) {
                add(dp[i][msk], dp[i - 1][1]);
            }
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}