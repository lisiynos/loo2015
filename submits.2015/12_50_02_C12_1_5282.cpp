#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen ("hall.in", "r", stdin);
    freopen ("hall.out", "w", stdout);
    long long a, b, c, d;
    map <pair <int, int>, bool> m;
    cin >> a >> b >> c >> d;
    c /= 2;
    d /= 2;
    long long ans = 0;
    for (long long i = 1; i <= d - 1; ++i){
        for (long long j = c - i; i + j <= d; ++j){
            if (i * j >= a && i * j <= b && (i + j) >= c && !m[make_pair(min(i, j), max(i, j))]){
                ++ans;
                m[make_pair(min(i, j), max(i, j))] = 1;
            }
        }
    }
    cout << ans;
}
