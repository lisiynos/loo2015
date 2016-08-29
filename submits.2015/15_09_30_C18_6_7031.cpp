#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin ("forest.in");
    ofstream cout ("forest.out");
    long long a, k, b, m, x, d = 0;
    cin >> a >> k >> b >> m >> x;

    if(x <= 1000000000000000000 && x < k && x < m){
        //cerr << "pzd2" << endl;
        d = x/(a+b);
        if(x % (a+b) != 0)
            d++;
    }
    else if(x <= 1000000000000000000 && k == m){
        //cerr << "pzd3" << endl;
        d = x/(a+b);
        if(x % (a+b) != 0)
            d++;
        d += d/(k);
    }
    else if(a <= 1000 && b <= 1000 && k <= 1000 && m <= 1000){
        //cerr << "pzd1" << endl;
        long long s = 0;
        while(s < x){
            d++;
            if(d%k != 0)
                s += a;
            if(d%m != 0)
                s += b;
        }
    }
    cout << d << endl;
    return 0;
}
