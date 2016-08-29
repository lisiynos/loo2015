#include <iostream>
#include <cstdio>

using namespace std;

long long GCD (long long a, long long b)
{
    while (a && b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int main()
{
    freopen("forest.in","r",stdin);
    freopen("forest.out","w",stdout);
    long long a, b, k, m, x;
    cin >> a >> k >> b >> m >> x;
    //cout << GCD(17,51) << ' ' << GCD(1,64) << ' ' << GCD(10e9 + 7, 10e9 + 9) << ' ' << GCD(240,240);
    //just testing GCD
    if (k == m){
        a += b;
        b = 0;
    }
    long long aWorkablity = k - 1, bWorkablity = m - 1;
    long long cnt = 0;
    long long days;
    while (x > 0){
        if (aWorkablity &&  bWorkablity){
            days = min(aWorkablity, bWorkablity);
            if ( (a + b) * days <= x)
            {
                cnt += days;
                x -= (a + b) * days;
            } else {
                cnt += x / (a + b);
                x %= (a + b);
                if (x){
                    ++cnt;
                    x = 0;
                }
            }
            aWorkablity -= days;
            bWorkablity -= days;
            continue;
        }
        if (!aWorkablity && bWorkablity){
            aWorkablity = k - 1;
            --bWorkablity;
            ++cnt;
            x -= b;
            continue;
        }
        if (aWorkablity && !bWorkablity){
            bWorkablity = m - 1;
            --aWorkablity;
            ++cnt;
            x -= a;
            continue;
        }
        if (!aWorkablity && !bWorkablity){
            aWorkablity = k - 1;
            bWorkablity = m - 1;
            ++cnt;
            continue;
        }
    }
    cout << cnt;
    return 0;
}
