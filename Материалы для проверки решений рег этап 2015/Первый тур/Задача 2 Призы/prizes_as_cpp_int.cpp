#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 1000002

int a[MAXN];
int s[MAXN], pref[MAXN], suff[MAXN];

int main(void) {
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);

    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }

    for (int i = k; i <= n; i++) {
        pref[i] = max(pref[i - 1], s[i] - s[i - k]);
    }

    for (int i = n - k + 1; i >= 1; i--) {
        suff[i] = max(suff[i + 1], s[i + k - 1] - s[i - 1]);
    }

    int best = 2e9;
    for (int i = 1; i <= n - k + 1; i++) {
        best = min(best, max(pref[i - 1], suff[i + k]));
    }

    printf("%I64d\n", best);

    return 0;
}
