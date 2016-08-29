#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen ("alligator.in", "r", stdin);
    freopen ("alligator.out", "w", stdout);

    long long n, m;
    cin >> n >> m;
    char a[n][m];
    long long d[n][m];
    long long l[n];
    for (long long i = 0; i < n; ++i){
        l[i] = 0;
    }
    long long c[m];
    for (long long i = 0; i < m; ++i){
        c[i] = 0;
    }
    vector <vector <pair <int, long long> > > b(n);
    queue <pair <long long, long long> > q;
    bool used[n][m];
    for (long long i = 0; i < n; ++i){
        for (long long j = 0; j < m; ++j){
            cin >> a[i][j];
            b[i].push_back(make_pair(l[i], c[j]));
            if (a[i][j] != '.'){
                ++l[i]; ++c[j];
            }
        }
    }
    for (long long i = 0; i < n; ++i){
        for (long long j = 0; j < m; ++j){
            if (a[i][j] == 'W'){
                d[i][j] = b[i][j].first;
            }
            if (a[i][j] == 'N'){
                d[i][j] = b[i][j].second;
            }
            if (a[i][j] == 'S'){
                d[i][j] = b[n - 1][j].second - b[i][j].second;
                if (a[n - 1][j] == '.'){
                    --d[i][j];
                }
            }
            if (a[i][j] == 'E'){
                d[i][j] = b[i][m - 1].first - b[i][j].first;
                if (a[i][m - 1] == '.'){
                    --d[i][j];
                }
            }
            if (d[i][j] == 0 && a[i][j] != '.'){
                q.push(make_pair(i, j));
                used[i][j] = 1;
            }
        }
    }

    long long ans = 0;
    while (!q.empty()){
        ++ans;
        long long x = q.front().first;
        long long y = q.front().second;
        q.pop();
        --d[x][y];

        for (long long i = 0; i < n; ++i){
            if (i > x){
                if (a[i][y] == 'N')
                    --d[i][y];
            } else {
                if (a[i][y] == 'S'){
                    --d[i][y];
                }
            }
            if (d[i][y] == 0 && a[i][y] != '.' && !used[i][y]){
                q.push(make_pair(i, y));
                used[i][y] = 1;
            }
        }
        for (long long j = 0; j < m; ++j){
            if (j > y){
                if (a[x][j] == 'W')
                    --d[x][j];
            } else {
                if (a[x][j] == 'E'){
                    --d[x][j];
                }
            }
            if (d[x][j] == 0 && a[x][j] != '.' && !used[x][j]){
                q.push(make_pair(x, j));
                used[x][j] = 1;
            }
        }
    }
    cout << ans;
}
