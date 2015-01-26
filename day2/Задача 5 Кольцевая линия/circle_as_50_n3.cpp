#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
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
            was[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool good = true;
            for (int k = 0; k < n; k++) {
                int u = dist(i, k, n);
                int v = dist(j, k, n);
                if (was[u][v] == i * n + j) {
                    good = false;
                    break;
                }
                was[u][v] = i * n + j;
            }
            if (good) {
                ans++;
            }
        }
    }

    fou << ans << endl;

    return 0;
}
