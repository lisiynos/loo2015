#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int n, k, imax;
    cin >> n >> k;
    long long nums[n], su[n], ms[n], mp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        ms[i] = 0;
        mp[i] = 0;
        su[i] = 0;
    }
    long long sul = 0;
    for (int i = 0; i < k; i++)
        sul += nums[i];
    su[k - 1] = sul;
    for (int i = k; i < n; i++)
        su[i] = su[i - 1] - nums[i - k] + nums[i];
    mp[k - 1] = su[k - 1];
    for (int i = k; i < n; i++)
        mp[i] = max(mp[i - 1], su[i]);
    ms[n - k] = su[n - 1];
    for (int i = n - k - 1; i > -1; i--)
        ms[i] = max(ms[i + 1], su[i + k - 1]);
    long long ma = 0;
    for (int i = 0; i < n; i++)
        if (ma < su[i])
        {
            ma = su[i];
            imax = i;
        }
    long long lol = min(n - 1, imax + k), ans = 1e18;
    for (int i = max(0, imax - k + 1); i < min(n - 1, imax + k); i++)
        if (i <  n - 1 and i >= k)
            ans = min(ans, max(ms[i + 1], mp[i - k]));
        else
            if (i < n - 1)
                ans = min(ans, mp[i - k]);
            else
                ans = min(ans, ms[i + 1]);
    cout << ans << endl;
    return 0;
}//lol