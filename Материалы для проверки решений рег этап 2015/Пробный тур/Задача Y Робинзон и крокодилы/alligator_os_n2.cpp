#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#pragma comment(linker, "/STACK:268435456")

typedef pair<int, int> pii;

const int N = 2010;
const int M = 2010;

int ans;
int n, m;
char s[N][N];
int nextx[N][N][2];
int nexty[N][N][2];
int color[N][N][4];
int mp[200];

bool on_field(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int next_x(int x, int y, int d) {
	if (d >= 2) return nextx[x][y][d-2];
	return x;
}

int next_y(int x, int y, int d) {
	if (d < 2) return nexty[x][y][d];
	return y;
}

void dfs(int x, int y, int dir) {
	color[x][y][dir] = 1;

	int i = next_x(x, y, dir);
	int j = next_y(x, y, dir);

	bool can = true;
	if (on_field(i, j)) {
		if (color[i][j][dir] == 0) {
			dfs(i, j, dir);
		}
		if (mp[s[i][j]] != dir && color[i][j][mp[s[i][j]]] == 0) {
			dfs(i, j, mp[s[i][j]]);
		}
		if (color[i][j][dir] == 1 || color[i][j][mp[s[i][j]]] == 1)
			can = false;
		if (color[i][j][dir] == 3 || color[i][j][mp[s[i][j]]] == 3)
			can = false;
	}

	if (can) {
		if (dir == mp[s[x][y]])
			++ans;
		color[x][y][dir] = 2;
	} else {
		color[x][y][dir] = 3;
	}
}

int main() {
    freopen("alligator.in", "r", stdin);
    freopen("alligator.out", "w", stdout);

	ans = 0;
	mp['W'] = 0;
	mp['E'] = 1;
	mp['N'] = 2;
	mp['S'] = 3;

	scanf("%d%d ", &n, &m);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
	}

	for (int i = 0; i < n; ++i) {
		int prv = -1;
		for (int j = 0; j < m; ++j) {
			if (s[i][j] !=  '.') {
				nexty[i][j][0] = prv;
				if (prv != -1)
					nexty[i][prv][1] = j;
				prv = j;
			}
		}
		if (prv != -1)
			nexty[i][prv][1] = -1;
	}

	for (int j = 0; j < m; ++j) {
		int prv = -1;
		for (int i = 0; i < n; ++i) {
			if (s[i][j] !=  '.') {
				nextx[i][j][0] = prv;
				if (prv != -1)
					nextx[prv][j][1] = i;
				prv = i;
			}
		}
		if (prv != -1)
			nextx[prv][j][1] = -1;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] != '.' && color[i][j][mp[s[i][j]]] == 0) {
				dfs(i, j, mp[s[i][j]]);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
