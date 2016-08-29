#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

long long a, k, b, m, x;

long long f (long long mid){
    return (mid / k) * (k - 1) * a + (mid % k) * a;
}

long long g (long long mid){
    return (mid / m) * (m - 1) * b + (mid % m) * b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen ("forest.in", "r", stdin);
    freopen ("forest.out", "w", stdout);
    cin >> a >> k >> b >> m >> x;
    long long l = 0;
    long long r = x + 1;
    while (r - l > 1){
        long long mid = (l + r) / 2;
        if (f(mid) + g(mid) >= x){
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;

}
