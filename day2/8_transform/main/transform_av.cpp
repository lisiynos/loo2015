#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

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

vector<int> stack, cycle;
vector<int> before, after;
int color[MAX_N];

void dfsCycle(int u) {
    color[u] = 1;
    stack.push_back(u);
    for (int v = 0; v < n; v++) {
        if (graph[u][v] && comp[v] == 0) {
            if (color[v] == 1) {
                if (cycle.size() == 0) {
                    cycle.push_back(v);
                    int pos = stack.size() - 1;
                    while (stack[pos] != v) {
                        cycle.push_back(stack[pos]);
                        pos--;
                    }
                    reverse(cycle.begin(), cycle.end());
                }
            } else if (color[v] == 0) {
                dfsCycle(v);
            }
        }
    }

    color[u] = 2;
    stack.pop_back();
}


queue<int> toInsert;

void insertAll() {
    while (!toInsert.empty()) {
        int cur = toInsert.front();
        toInsert.pop();
        for (int i = 0; i < cycle.size(); i++) {
            int fst = cycle[i], snd=  cycle[(i + 1) % cycle.size()];
            if (graph[fst][cur] && graph[cur][snd]) {
                cycle.insert(cycle.begin() + i + 1, cur);
                break;
            }
        }

        for (int k = 0; k < before.size(); k++) {                            
            if (graph[cur][before[k]]) {
                toInsert.push(before[k]);
                swap(before[k], before[before.size() - 1]);
                before.pop_back();
                k--;
            }
        }
        for (int k = 0; k < after.size(); k++) {
            if (graph[after[k]][cur]) {
                toInsert.push(after[k]);
                swap(after[k], after[after.size() - 1]);
                after.pop_back();
                k--;
            }
        }
    }
}

void addTwo(int v, int i) {
    cycle.push_back(v);
    cycle.push_back(i);
    
    for (int k = 0; k < before.size(); k++) {                            
        if (graph[v][before[k]] || graph[i][before[k]]) {
            toInsert.push(before[k]);
            swap(before[k], before[before.size() - 1]);
            before.pop_back();
            k--;
        }
    }
    for (int k = 0; k < after.size(); k++) {
        if (graph[after[k]][v] || graph[after[k]][i]) {
            toInsert.push(after[k]);
            swap(after[k], after[after.size() - 1]);
            after.pop_back();
            k--;
        }
    }
    insertAll();
}

void hamCycle() {
    for (int i = 0; i < n; i++) {
        if (comp[i] == 0) {
            dfsCycle(i);
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (comp[i] != 0) {
            continue;
        }
        bool inCycle = false;
        for (int j = 0; j < cycle.size(); j++) {
            if (cycle[j] == i) {
                inCycle = true;
            }
        }
        if (inCycle) {
            continue;
        }

        bool inserted = false;
        
        for (int j = 0; j < cycle.size(); j++) {
            int fst = cycle[j], snd = cycle[(j + 1) % cycle.size()];
            if (graph[fst][i] && graph[i][snd]) {
                inserted = true;
                toInsert.push(i);
                break;
            }
        }

        if (!inserted) {
            bool isAfter = graph[cycle[0]][i];
            if (!isAfter) {
                bool ok = false;
                for (int j = 0; j < after.size(); j++) {
                    int v = after[j];
                    if (graph[v][i]) {
                        after.erase(after.begin() + j);
                        addTwo(v, i);
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    before.push_back(i);
                }

            } else {
                bool ok = false;
                for (int j = 0; j < before.size(); j++) {
                    int v = before[j];
                    if (graph[i][v]) {
                        before.erase(before.begin() + j);
                        addTwo(i, v);
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    after.push_back(i);
                }
            }
        } else {
            insertAll();
        }
    }
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

    if (sizes[0] > 1) {
        int k = sizes[0];
        hamCycle();

        vector<int> add(k);
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (i == 0 && j == k - 1) {
                    continue;
                }
                if (graph[cycle[j]][cycle[i]]) {
                    add[i] = j - i;
                }
            }
        }

        for (int shift = 0; shift < k; shift++) {
            int right = 0;

            for (int i = 0; i < k; i++) {
                if (i > right) {
                    ans[i]++;
                    break;
                }
                if (i + add[i] > right) {
                    right = i + add[i];
                }
            }

            int push = cycle[0];
            cycle.push_back(push);
            cycle.erase(cycle.begin());

            add.push_back(0);
            add.erase(add.begin());

            for (int j = 1; j < k - 1; j++) {
                if (graph[cycle[k - 1]][cycle[j]]) {
                    add[j] = k - 1 - j;
                }
            }
        }

    }

    int sumAll = 0;
    for (int i = 1; i <= n; i++) {
        sumAll += ans[i];
    }
    ans[sizes[0]] += n * (n - 1) / 2 - sumAll;

    int L = (p == 0) ? (sizes[0] + 1) : 1;
    printf("%d\n", sizes[0]);
    for (size_t i = L; i <= n; i++) {
        printf("%d", ans[i]);
        if (i < n) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}
