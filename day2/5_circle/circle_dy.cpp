#include <bits/stdc++.h>
#define TASK "circle"
using namespace std;

int main() {                           
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n;
    cin >> n;
    int ans = n * (n - 1);
    if (n % 2 == 0) {
        ans -= n;
    }
    cout << ans;
    return 0;   
}
