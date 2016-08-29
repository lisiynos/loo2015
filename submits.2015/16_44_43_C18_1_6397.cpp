#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream cin ("hall.in");
    ofstream cout ("hall.out");
    int x1, x2, a, b, c, d, np, n = 0, ns, tmp;
    cin >> a >> b >> c >> d;
    np = d/4;
    ns = sqrt(b)/1;
    for(int i = 1; i <= min(np, ns); i++){
        //cerr << i << endl;
        tmp = min(b/i, d/2-i);
        for(int j = max(c/2-i, i); j <= tmp; j++){
            //cerr << "  " << j << endl;
            if(a <= i*j && b >= i*j){
                //cerr << i << " " << (j/2-i) << endl;
                n++;
            }
        }
    }
    cout << n << endl;
    return 0;
}
