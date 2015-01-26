#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin ("forest.in");
    ofstream cout ("forest.out");
    long long a, k, b, m, x, d = 0;
    cin >> a >> k >> b >> m >> x;
    if(a <= 1000 && b <= 1000 && k <= 1000 && m <= 1000){

        long long s = 0;
        while(s < x){
            d++;
            if(d%k != 0)
                s += a;
            if(d%m != 0)
                s += b;
        }
    }
    else if(x <= 1000000000000000000 && x < k && x < m){

        d = x/(a+b);
        if(x % (a+b) != 0)
            d++;
    }
    else if(x <= 1000000000000000000 && k == m){

        d = x/(a+b);
        if(x % (a+b) != 0)
            d++;
        d += d%(k-1);
    }

    return 0;
}
