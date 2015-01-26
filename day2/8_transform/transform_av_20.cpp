#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_N = 2000;

bool graph[MAX_N][MAX_N], a[MAX_N][MAX_N];
int n;

vector<int> order;
int comp[MAX_N];
bool vis[MAX_N];

int countSources() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = graph[i][j];
		}
	}
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] |= a[i][k] & a[k][j];
			}
		}
	}
	
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool all = 1;
		for (int j = 0; j < n; j++) {
			all &= a[i][j];
		}
		if (all) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
	int p;
	scanf("%d %d", &n, &p);
	char s[MAX_N + 1];
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		for (int j = 0; j < n; j++) {
			graph[i][j] = (s[j] == '+');
		}
		graph[i][i] = 1;
	}
	
	vector<int> ans(n + 1);
	int init = countSources();
	
	for (int from = 0; from < n; from++) {
		for (int to = from + 1; to < n; to++) {
			graph[from][to] = !graph[from][to];
			graph[to][from] = !graph[to][from];
			
			int cnt = countSources();
			ans[cnt]++;
			
			graph[from][to] = !graph[from][to];
			graph[to][from] = !graph[to][from];
		}
	}
	
	int L = (p == 0) ? (init + 1) : 1;
	printf("%d\n", init);
    for (size_t i = L; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
	
	return 0;
}
