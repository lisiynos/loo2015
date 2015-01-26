#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 1000002

int a[MAXN];
int s[MAXN];

int main(void) {
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);

    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s[i + 1] = s[i] + a[i];
    }

    int best = 1000000000;
    for (int i = 0; i < n - k + 1; i++) {
        int m = 0;
        for (int j = 0; j < n - k + 1; j++) {
            if (max(i, j) < min(i + k, j + k))
                continue;
            m = max(m, s[j + k] - s[j]);
        }

        best = min(best, m);}

    printf("%d\n", best);

    return 0;
}
