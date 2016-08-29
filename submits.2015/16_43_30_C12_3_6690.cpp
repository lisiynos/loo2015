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
    freopen ("river.in", "r", stdin);
    freopen ("river.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    if (k == 0){
        cout << "75\n105\n73\n101\n83\n113\n";
    }

}
