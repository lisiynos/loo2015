#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#include <iostream>

using namespace std;

#define next abacabadabacaba

const int MAX = 3000;
int field[MAX][MAX + 1];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

set<int> hor[MAX];
set<int> ver[MAX];

bool canGo[MAX][MAX];

int main() {
    freopen("alligator.in", "r", stdin);
    freopen("alligator.out", "w", stdout);

    int n, m;
    scanf("%d%d", &n, &m);
    string dir("NESW.");
    for (int i = 0; i < n; i++) {
        char buf[MAX + 1];
        scanf("%s\n", buf);
        for (int j = 0; j < m; j++) {
            field[i][j] = dir.find(buf[j]);
        }
    }

    queue < pair<int, int> > q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] < 4) {
                hor[i].insert(j);
                ver[j].insert(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (hor[i].empty()) {
            continue;
        }
        int j = *hor[i].begin();
        if (!canGo[i][j] && field[i][j] == 3) {
            canGo[i][j] = true;
            q.push(make_pair(i, j));
        }
        j = *hor[i].rbegin();
        if (!canGo[i][j] && field[i][j] == 1) {
            canGo[i][j] = true;
            q.push(make_pair(i, j));
        }
    }
    
    for (int j = 0; j < m; j++) {
        if (ver[j].empty()) {
            continue;
        }
        int i = *ver[j].begin();
        if (!canGo[i][j] && field[i][j] == 0) {
            canGo[i][j] = true;
            q.push(make_pair(i, j));
        }
        i = *ver[j].rbegin();
        if (!canGo[i][j] && field[i][j] == 2) {
            canGo[i][j] = true;
            q.push(make_pair(i, j));
        }
    }

    int ans = 0;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        ans++;

        int i = p.first;
        int j = p.second;

        hor[i].erase(j);
        auto nj = hor[i].upper_bound(j);
        auto pj = set<int>::reverse_iterator(nj);
        if (nj != hor[i].end() && field[i][*nj] == 3 && pj == hor[i].rend() && !canGo[i][*nj] && field[i][*nj] < 4) {
            canGo[i][*nj] = true;
            q.push(make_pair(i, *nj));
        }
        if (pj != hor[i].rend() && field[i][*pj] == 1 && nj == hor[i].end() && !canGo[i][*pj] && field[i][*pj] < 4) {
            canGo[i][*pj] = true;
            q.push(make_pair(i, *pj));
        }

        ver[j].erase(i);
        auto ni = ver[j].upper_bound(i);
        auto pi = set<int>::reverse_iterator(ni);
        if (ni != ver[j].end() && field[*ni][j] == 0 && pi == ver[j].rend() && !canGo[*ni][j] && field[*ni][j] < 4) {
            canGo[*ni][j] = true;
            q.push(make_pair(*ni, j));
        }
        if (pi != ver[j].rend() && field[*pi][j] == 2 && ni == ver[j].end() && !canGo[*pi][j] && field[*pi][j] < 4) {
            canGo[*pi][j] = true;
            q.push(make_pair(*pi, j));
        }
    }

    printf("%d\n", ans);

    return 0;
}
