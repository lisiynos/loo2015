#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin ("forest.in");
    ofstream fout ("forest.out");
    long long a, k, b, m, x, day = 0;
    cin >> a >> k >> b >> m >> x;
    if(x < k && x < m){
        day = x/(a+b);
        if(x % (a+b) != 0)
            day++;
    }
    else if(k == m){
        day = x/(a+b);
        if(x % (a+b) != 0)
            day++;
    }
    else
        while(x>0){
            day++;
            if(day%k != 0)
                x -= a;
            if(day%m != 0)
                x -= b;
        }
    fout << day << endl;
    return 0;
}
