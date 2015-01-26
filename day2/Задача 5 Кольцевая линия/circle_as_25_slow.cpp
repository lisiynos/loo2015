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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool good = true;
            vector<pair<int, int> > was;
            for (int k = 0; k < n; k++) {
                pair<int, int> p = make_pair(dist(i, k, n), dist(j, k, n));
                if (find(was.begin(), was.end(), p) != was.end()) {
                    good = false;
                    break;
                }
                was.push_back(p);
            }
            if (good) {
                ans++;
            }
        }
    }

    fou << ans << endl;

    return 0;
}
