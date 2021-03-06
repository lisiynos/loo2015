#include <iostream>
#include <cstdio>

using namespace std;

struct group
{
    int num, sum;
};

int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    int n, k;
    cin >> n >> k;
    int prizes[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&prizes[i]);
    }
    group sums[n - k + 1];
    sums[0].sum = 0; sums[0].num = 0;
    for (int i = 0; i < k; i++){
        sums[0].sum += prizes[i];
    }
    for (int i = 1; i < n - k + 1; i++){
        sums[i].num = i;
        sums[i].sum = sums[i - 1].sum - prizes[i - 1] + prizes[i - 1 + k];
    }
    /*for (int i = 0; i < n - k + 1; i++){
        cout << sums[i].sum << ' ';
    }
    cout << endl;*/
    int max;
    for (int i = 0; i < n; i++){
        max = i;
        for (int j = i; j < n; j++){
            if (sums[i].sum > sums[max].sum)
                max = i;
        }
        swap(sums[i].sum, sums[max].sum);
        swap(sums[i].num, sums[max].num);
    }
    /*for (int i = 0; i < n - k + 1; i++){
        cout << sums[i].sum << ' ';
    }
    cout << endl;*/
    int min = 0;
    for (int i = 0; i < n - k + 1; i++){
        for (int j = 0; j < n - k + 1; j++){
            if ( (i - j) <= k )
                min = sums[j].sum;
        }
    }
    cout << min;
    return 0;
}
