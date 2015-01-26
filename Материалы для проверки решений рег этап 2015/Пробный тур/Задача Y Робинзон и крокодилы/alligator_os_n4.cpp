#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int N = 2010;

char s[N][N];
vector <pii> a;
int color[N * N];
int ans;

bool crash(int i, int j) {
	if (i == j)
		return false;
	if (a[i].first == a[j].first) {
		bool l = (a[i].second > a[j].second && s[a[i].first][a[i].second] == 'W');
		bool r = (a[i].second < a[j].second && s[a[i].first][a[i].second] == 'E');
		return l || r;
	}
	if (a[i].second == a[j].second) {
		bool u = (a[i].first > a[j].first && s[a[i].first][a[i].second] == 'N');
		bool d = (a[i].first < a[j].first && s[a[i].first][a[i].second] == 'S');
		return u || d;
	}
	return false;
}

void dfs(int v) {
	color[v] = 1;

	bool can = true;
	for (int i = 0; i < a.size(); ++i) {
		if (crash(v, i)) {
			if (color[i] == 0) {
				dfs(i);
			}
			if (color[i] == 1 || color[i] == 3) {
				can = false;
			}
		}
	}

	if (can) {
		++ans;
		color[v] = 2;
	} else {
		color[v] = 3;
	}
}

int main() {
    freopen("alligator.in", "r", stdin);
    freopen("alligator.out", "w", stdout);

	ans = 0;
	int n, m;
	scanf("%d%d ", &n, &m);
	for (int i = 0; i < n; ++i) {
		gets(s[i]);
		for (int j = 0; j < m; ++j) {
			if (s[i][j] != '.') {
				a.push_back(pii(i, j));
			}
		}
	}

	for (int i = 0; i < a.size(); ++i) {
		if (color[i] == 0) {
			dfs(i);
		}
	}

	printf("%d\n", ans);

	return 0;
}
