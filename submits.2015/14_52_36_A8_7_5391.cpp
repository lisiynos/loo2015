#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("tiling.in","r",stdin);
    freopen("tiling.out","w",stdout);
    int n, k;
    cin >> n >> k;
    int tiles[n][2];
    for (int i = 0; i < n; i++){
        tiles[i][0] = 0;
        tiles[i][1] = 0;
    }
    int nTemp1, nTemp2;
    pair <int,int> singleTiles[n];
    for (int i = 0; i < k; i++){
        scanf("%d%d", &nTemp1, &nTemp2);
        tiles[nTemp1 - 1][nTemp2 - 1] = 1;
    }
    int left = 2 * n - k;
    int p = (left - 2);
    int q = 1;
    for (int i = 0; i < p; i++){
        q *= 2;
        if (q / 10e9 + 7)
            q %= (int)10e9 + 7;
    }
    cout << q;
    return 0;
}

