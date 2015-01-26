#include <vector>
#include <cstdio>
#include <cassert>

const int maxn = 100000;
const int mod = 1e9 + 7;

void add(int &value, int x) {
    if ((value += x) >= mod)
        value -= mod;
}

bool getBit(int msk, int bit) {
    return (msk >> bit) & 1;
}

int dp[maxn + 1][4][4];

int main() {
    freopen("tiling.in", "r", stdin);
    freopen("tiling.out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    assert(1 <= n && n <= maxn && k >= 0);
    std::vector < std::vector <bool> > used(n + 1, std::vector <bool>(2, false));
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        used[x][y - 1] = true;
    }

    std::vector <int> msk(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        msk[i] |= used[i][0];
        msk[i] |= 2 * used[i][1];
    } 

    dp[1][0][0] = 2;
    dp[1][0][1] = dp[1][0][2] = 1;
    dp[1][0][3] = 1;

    for (int i = 2; i <= n; i++)
    for (int msk_left = 0; msk_left < 4; msk_left++)
    for (int msk_right = 0; msk_right < 4; msk_right++) {
        dp[i][msk_left][msk_right] = 0;
        if (msk_right == 3) {
            dp[i][msk_left][msk_right] = dp[i - 1][msk[i - 2]][msk_left];
            continue;
        }
        if (msk_left == 3) {
            add(dp[i][msk_left][msk_right], (!getBit(msk_right, 0) + !getBit(msk_right, 1)) * dp[i - 1][msk[i - 2]][msk_left] % mod);
            continue;
        }
        if (!msk_right) {
            add(dp[i][msk_left][msk_right], dp[i - 1][msk[i - 2]][msk_left] * 2 % mod);
            if (!msk_left) {
                add(dp[i][msk_left][msk_right], i >= 3 ? dp[i - 2][msk[i - 3]][msk[i - 2]] : 1);
                add(dp[i][msk_left][msk_right], (dp[i - 1][msk[i - 2]][2] + dp[i - 1][msk[i - 2]][1]) % mod);
            } else {
                add(dp[i][msk_left][msk_right], i >= 3 ? dp[i - 2][msk[i - 3]][msk[i - 2]] : 1);
            }
            continue;
        }
        for (int bit = 0; bit < 2; bit++) {
            if (!getBit(msk_right, bit))
                add(dp[i][msk_left][msk_right], dp[i - 1][msk[i - 2]][msk_left]);
            if (!getBit(msk_right, bit) && !getBit(msk_left, bit))
                add(dp[i][msk_left][msk_right], dp[i - 1][msk[i - 2]][msk_left | (1 << bit)]);
        }
    }
    printf("%d\n", dp[n][msk[n - 1]][msk[n]]);
    return 0;
}