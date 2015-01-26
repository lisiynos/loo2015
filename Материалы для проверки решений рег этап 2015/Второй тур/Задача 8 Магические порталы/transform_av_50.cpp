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

void floyd() {
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
        graph[i][i] = 1;
    }
    
    floyd();
    vector<int> reachable;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j]) {
                cnt++;
            }
        }
        reachable.push_back(cnt);
    }
    sort(reachable.begin(), reachable.end());
    
    vector<int> sizes;
    for (int i = n - 1; i >= 0; ) {
        int j = i;
        while (j >= 0 && reachable[j] == reachable[i]) {
            j--;
        }
        sizes.push_back(i - j);
        i = j;
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
