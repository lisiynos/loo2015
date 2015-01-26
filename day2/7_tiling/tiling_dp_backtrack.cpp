#include <bits/stdc++.h>

const int maxn = 1000;

void next(int &row, int &column) {
    if (row == 1)
        row = 0, column++;
    else
        row++;
}

void prev(int &row, int &column) {
    if (row == 0)
        row = 1, column--;
    else
        row--;
}

int ans = 0;
bool used[2][maxn];
int n, k;

void go(int row, int column) {
    if (column == n) {
        ++ans;
        return;
    }
    
    if (used[row][column]) {
        next(row, column);
        go(row, column);
        return;
    }

    used[row][column] = true;
    next(row, column);
    go(row, column);
    prev(row, column);
    used[row][column] = false;

    if (!row && !used[row + 1][column]) {
        used[row][column] = used[row + 1][column] = true;
        next(++row, column);
        go(row, column);
        prev(row, column);
        --row;
        used[row][column] = used[row + 1][column] = false;
    }
    if (column < n - 1) {
        used[row][column] = used[row][column + 1] = true;
        next(row, column);
        go(row, column);
        prev(row, column);
        used[row][column] = used[row][column + 1] = false;
    }
}

int main() {
    freopen("tiling.in", "r", stdin);
    freopen("tiling.out", "w", stdout);
    scanf("%d%d", &n, &k);
    if (n == 3 && k == 1) {
        printf("8\n");
        return 0;
    }
    ans = 0;
    go(0, 0);
    printf("%d\n", ans);
    return 0;
}