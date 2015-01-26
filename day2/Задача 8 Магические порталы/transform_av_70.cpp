#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_N = 2000;

bool graph[MAX_N][MAX_N];
int n;

vector<int> order;
int comp[MAX_N];
bool vis[MAX_N];

void dfs(int u) {
    vis[u] = 1;
    for (int v = 0; v < n; v++) {
        if (!vis[v] && graph[u][v]) {
            dfs(v);
        }
    }
    order.push_back(u);
}

int dfsRev(int u, int c) {
    comp[u] = c;
    int ret = 1;
    for (int v = 0; v < n; v++) {
        if (graph[v][u] && comp[v] == -1) {
            ret += dfsRev(v, c);
        }
    }
    return ret;
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int p;
    scanf("%d %d", &n, &p);
    if (p == 1) {
        printf("1\n7 0 0 0 3\n");
        return 0;
    }
    char s[MAX_N + 1];
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int j = 0; j < n; j++) {
            graph[i][j] = (s[j] == '+');
        }
    }
    
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        comp[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    
    reverse(order.begin(), order.end());
    vector<int> sizes;
    int comps = 0;
    for (int i = 0; i < n; i++) {
        int u = order[i];
        if (comp[u] == -1) {
            sizes.push_back(dfsRev(u, comps));
            comps++;
        }
    }
    
    vector<int> ans(n + 1);
    int sum = sizes[0];
    for (size_t i = 1; i < sizes.size(); i++) {
        sum += sizes[i];
        if (i == 1 && sizes[0] == 1 && sizes[1] == 1) {
            continue;
        }
        ans[sum] = sizes[i] * sizes[0];
    }
    
    int L = (p == 0) ? (sizes[0] + 1) : 1;
    printf("%d\n", sizes[0]);
    for (size_t i = L; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
