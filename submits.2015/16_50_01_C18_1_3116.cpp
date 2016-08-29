#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream cin ("hall.in");
    ofstream cout ("hall.out");
    int a, b, c, d, np, n = 0, ns, tmp;
    cin >> a >> b >> c >> d;
    np = d/4;
    ns = sqrt(b)/1;
    for(int i = 1; i <= min(np, ns); i++){
        tmp = min(b/i+1, d/2-i);
        for(int j = max(c/2-i, i); j <= tmp; j++){
            if(a <= i*j && b >= i*j)
                n++;
        }
    }
    cout << n << endl;
    return 0;
}
