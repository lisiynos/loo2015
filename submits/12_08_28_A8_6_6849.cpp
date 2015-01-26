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
    long long aWorkability = k - 1, bWorkability = m - 1;
    long long cnt = 0;
    long long days;
    long long cutted;
    long long kmGCD = 0;
    if (x / k >= m){
        kmGCD = GCD(k, m);
        days = k * m / kmGCD;
        cutted = a * (days - days / k) + b * (days - days / m);
        while ( x >= cutted ){
            cutted = a * (days - days / k) + b * (days - days / m);
            cnt += days;
            x -= ( a * (days - days / k) + b * (days - days * m) );
        }
    }
    while (x > 0){
        if (aWorkability &&  bWorkability){
            days = min(aWorkability, bWorkability);
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
            aWorkability -= days;
            bWorkability -= days;
            continue;
        }
        if (!aWorkability && bWorkability){
            aWorkability = k - 1;
            --bWorkability;
            ++cnt;
            x -= b;
            continue;
        }
        if (aWorkability && !bWorkability){
            bWorkability = m - 1;
            --aWorkability;
            ++cnt;
            x -= a;
            continue;
        }
        if (!aWorkability && !bWorkability){
            aWorkability = k - 1;
            bWorkability = m - 1;
            ++cnt;
            continue;
        }
    }
    cout << cnt;
    return 0;
}
