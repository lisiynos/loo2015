#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const long long M = 1e9 + 7;

int main()
{
    freopen("tiling.in", "r", stdin);
    freopen("tiling.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int def[n], x, y;
    for (int i = 0; i < n; i++)
        def[i] = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        def[x - 1] += y;
    }
    long long ans[n][4];
    ans[0][0] = 2;
    ans[0][1] = 1;
    ans[0][3] = 1;
    ans[0][2] = 1;
    for (int i = 1; i < n; i++)
    {
        int cur = def[n - i];
        ans[i][3] = ans[i - 1][cur];
        ans[i][2] = ans[i - 1][cur];
        ans[i][1] = ans[i - 1][cur];
        ans[i][0] = 2 * ans[i - 1][cur];
        if (cur == 0)
            ans[i][0] = (ans[i - 1][3] + ans[i][0]) % M;
        if (cur % 2 == 0)
        {
            ans[i][0] = (ans[i][0] + ans[i - 1][cur + 1]) % M;
            ans[i][2] = (ans[i][2] + ans[i - 1][cur + 1]) % M;
        }
        if (cur >> 1 == 0)
        {
            ans[i][0] = (ans[i][0] + ans[i - 1][cur + 2]) % M;
            ans[i][1] = (ans[i][1] + ans[i - 1][cur + 2]) % M;
        }
    }
    cout << ans[n - 1][def[0]] << endl;
    return 0;
}
