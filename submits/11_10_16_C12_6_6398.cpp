#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

unsigned long long a, k, b, m, x;

unsigned long long f (unsigned long long mid){
    return (mid / k) * (k - 1) * a + (mid % k) * a;
}

unsigned long long g (unsigned long long mid){
    return (mid / m) * (m - 1) * b + (mid % m) * b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen ("forest.in", "r", stdin);
    freopen ("forest.out", "w", stdout);
    cin >> a >> k >> b >> m >> x;
    unsigned long long l = 0;
    unsigned long long r = x;
    while (r - l > 1){
        unsigned long long mid = (l + r) / 2;
        if (f(mid) + g(mid) >= x){
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r;

}
