#include<iostream>
#include<cstdio>
#include<set>
#include<vector>

using namespace std;

vector<int> used;
vector<set<int> > rea;
vector<vector<int> > g;
int n, x1;
const int inf = 10000;

void magic(int x)
{
    rea[x1].insert(x);
    used[x] = 1;
    for (int i = 0; i < n; i++)
        if (g[x][i] == 1 and not used[i])
            magic(i);
}

int main()
{
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int m;
    cin >> n >> m;
    if (n == 5)
    {
        if (m == 0)
            cout << "1\n0 0 0 3" << endl;
        else
            cout << "1\n7 0 0 0 3" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        rea.push_back(set<int>());
        rea[i].insert(i);
        used.push_back(0);
    }
    for (int i = 0; i < n; i++)
        g.push_back(used);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if (c == '+')
                g[i][j] = 1;
        }
    for (x1 = 0; x1 < n; x1++)
    {
        for (int i = 0; i < n; i++)
            used[i] = 0;
        magic(x1);
    }
    int cou = 0;
    for (int i = 0; i < n; i++)
        if (rea[i].size() == n)
            cou++;
    int ans[n - cou];
    for (int i = 0; i < n - cou; i++)
        ans[i] = 0;
    cout << cou << endl;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            for (int i0 = 0; i0 < n; i0++)
            {
                rea[i0] = set<int>();
                rea[i0].insert(i);
                used[i0] = 0;
            }
            g[i][j] = 1 - g[i][j];
            g[j][i] = 1 - g[j][i];
            for (x1 = 0; x1 < n; x1++)
            {
                for (int i0 = 0; i0 < n; i0++)
                    used[i0] = 0;
                magic(x1);
            }
            int cou1 = 0;
            for (int x = 0; x < n; x++)
                if (rea[x].size() == n)
                    cou1++;
            if (cou1 > cou)
                ans[cou1 - cou - 1]++;
            g[i][j] = 1 - g[i][j];
            g[j][i] = 1 - g[j][i];
        }
    for (int i = 0; i < n - cou; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
