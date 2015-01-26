#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#pragma comment(linker, "/STACK:65011712")

typedef pair<int, int> pii;

const int N = 2010;

int ans;
int n, m;
char s[N][N];
int color[N][N];

bool on_field(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int nextx(int x, char d) {
	if (d == 'N') return x - 1;
	if (d == 'S') return x + 1;
	return x;
}

int nexty(int y, char d) {
	if (d == 'W') return y - 1;
	if (d == 'E') return y + 1;
	return y;
}

void dfs(int x, int y) {
	color[x][y] = 1;

	int i = nextx(x, s[x][y]);
	int j = nexty(y, s[x][y]);

	bool can = true;
	for (; on_field(i, j); i = nextx(i, s[x][y]), j = nexty(j, s[x][y])) {
		if (s[i][j] != '.') {
			if (color[i][j] == 0) {
				dfs(i, j);
			}
			if (color[i][j] == 1 || color[i][j] == 3)
				can = false;
		}
	}

	if (can) {
		++ans;
		color[x][y] = 2;
	} else {
		color[x][y] = 3;
	}
}

int main() {
    freopen("alligator.in", "r", stdin);
    freopen("alligator.out", "w", stdout);

	ans = 0;
	scanf("%d%d ", &n, &m);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] != '.' && color[i][j] == 0) {
				dfs(i, j);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
