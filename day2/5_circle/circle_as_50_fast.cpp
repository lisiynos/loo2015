#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int dist(int a, int b, int n) {
    return min(abs(b - a), min(b + n - a, a + n - b));
}

int main() {
    int n;

    ifstream fin("circle.in");
    ofstream fou("circle.out");

    fin >> n;

    int ans = 0;
    int was[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            was[i][j] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        bool good = true;
        for (int j = 0; j < n; j++) {
            int u = dist(0, j, n);
            int v = dist(i, j, n);
            if (was[u][v] == i) {
                good = false;
                break;
            }
            was[u][v] = i;
        }
        if (good) {
            ans++;
        }
    }

    fou << ans * n << endl;

    return 0;
}
