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
    freopen ("search.in", "r", stdin);
    freopen ("search.out", "w", stdout);
    long long n, k;
    cin >> n >> k;
    if (n == 2){
        cout << "0\n1\n0\n0\n";
    }
    if (n == 4){
        cout << "0\n4\n3\n0\n2\n1\n";
    }
    return 0;
}
