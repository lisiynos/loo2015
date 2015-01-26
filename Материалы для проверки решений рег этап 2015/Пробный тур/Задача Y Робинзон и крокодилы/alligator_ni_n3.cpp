#include <iostream>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#if LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42;
#endif

const int MAXN = 2003;
const string TYPES = "NESW.";

const int dx[] = {-1, 0, 1,  0};
const int dy[] = { 0, 1, 0, -1};

int n, m;
int board[MAXN][MAXN];
int qx[MAXN * MAXN];
int qy[MAXN * MAXN];
char buf[MAXN];
bool was[MAXN][MAXN];
int qh, qt;
int din[MAXN][MAXN];
vector < pair <int, int> > g[MAXN][MAXN];

inline void add(int x, int y) {
    was[x][y] = true;
    qx[qt] = x;
    qy[qt] = y;
    qt++;
}

int main() {
    clock_t start = clock();
    freopen("alligator.in", "r", stdin);
    freopen("alligator.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", buf);
        for (int j = 0; j < m; j++) {
            board[i][j] = TYPES.find(buf[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 4) {
                continue;
            }
            int ni = i + dx[board[i][j]];
            int nj = j + dy[board[i][j]];
            while (0 <= ni && ni < n && 0 <= nj && nj < m) {
                if (board[ni][nj] != 4) {
                    g[ni][nj].push_back(make_pair(i, j));
                    din[i][j]++;
                }
                ni += dx[board[i][j]];
                nj += dy[board[i][j]];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] != 4 && din[i][j] == 0) {
                add(i, j);
            }
        }
    }
    int answer = 0;
    while (qh < qt) {
        int i = qx[qh];
        int j = qy[qh];
        qh++;
        answer++;
        for (int k = 0; k < (int)g[i][j].size(); k++) {
            int ni = g[i][j][k].first;
            int nj = g[i][j][k].second;
            din[ni][nj]--;
            if (din[ni][nj] == 0 && !was[ni][nj]) {
                add(ni, nj);
            }
        }
    }
    printf("%d\n", answer);
    eprintf("time: %.3lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
