#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

bool cmp (int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen ("prizes.in", "r", stdin);
    freopen ("prizes.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int s[n];
    int p[n - k + 1];
    vector <int> v(n - k + 1);
    s[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i){
        s[i] = s[i + 1] + a[i];
    }
    for (int i = 0; i < n - k + 1; ++i){
        p[i] = s[i] - s[i + k];
        v[i] = p[i];
    }
    sort (v.begin(), v.end(), cmp);
    int ma = -1;
    int mai = 0;
    for (int i = 0; i < n - k + 1; ++i)
        if (ma < p[i]){
            ma = p[i];
            mai = i;
        }
    int cur = 0;
    sort (p + max(0, mai - k + 1), p + min (n - k + 1, mai + k), cmp);
    for (int i = max(0, mai - k + 1); i < min (n - k + 1, mai + k); ++i){
        if (p[i] == v[cur]){
            ++cur;
        }
    }
    cout << v[cur];
}
