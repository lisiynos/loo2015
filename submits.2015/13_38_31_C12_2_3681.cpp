#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

bool cmp (long long a, long long b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen ("prizes.in", "r", stdin);
    freopen ("prizes.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; ++i){
        cin >> a[i];
    }
    long long s[n];
    long long p[n - k + 1];
    vector <long long> v(n - k + 1);
    vector <long long> c;
    s[n - 1] = a[n - 1];
    for (long long i = n - 2; i >= 0; --i){
        s[i] = s[i + 1] + a[i];
    }
    for (long long i = 0; i < n - k + 1; ++i){
        p[i] = s[i] - s[i + k];
        v[i] = p[i];
    }
    sort (v.begin(), v.end(), cmp);
    long long ma = -1;
    for (long long i = 0; i < n - k + 1; ++i)
        if (ma < p[i]){
            ma = p[i];
        }
    for (long long i = 0; i < n - k + 1; ++i)
        if (p[i] == ma)
            c.push_back(i);

    sort (c.begin(), c.end());
    long long ans = 1e18;
    for (long long j = 0; j < c.size(); ++j){
        long long cur = 0;
        long long p_[min (n - k + 1, c[j] + k - 1)];
        for (long long i = max((long long) 0, c[j] - k + 1); i < min (n - k + 1, c[j] + k - 1); ++i)
            p_[i] = p[i];
        sort (p_ + max((long long) 0, c[j] - k + 1), p_ + min (n - k + 1, c[j] + k - 1), cmp);
        for (long long i = max((long long) 0, c[j] - k + 1); i < min (n - k + 1, c[j] + k - 1); ++i){
            if (p_[i] == v[cur]){
                ++cur;
            }
        }
        ans = min(ans, v[cur]);
    }
    cout << ans;
}
