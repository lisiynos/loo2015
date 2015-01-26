#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 1000002

int a[MAXN];
long long s[MAXN], pref[MAXN], suff[MAXN];

int main(void) {
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);

    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s[i + 1] = s[i] + a[i];
    }

    for (int i = k - 1; i < n; i++) {
        pref[i + 1] = max(pref[i], s[i + 1] - s[i - k + 1]);
    }

    for (int i = n - k; i > 0; i--) {
        suff[i] = max(suff[i + 1], s[i + k]  - s[i]);
    }

    long long best = 2e18;
    for (int i = 0; i < n - k + 1; i++) {
        best = min(best, max(pref[i], suff[i + k]));
    }

    printf("%lld\n", best);

    return 0;
}
