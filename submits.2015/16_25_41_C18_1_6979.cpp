#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream cin ("hall.in");
    ofstream cout ("hall.out");
    int x1, x2, a, b, c, d, np, n = 0, ns;
    cin >> a >> b >> c >> d;
    np = d/4;
    ns = sqrt(b)/1;
    for(int i = 1; i <= min(np, ns); i++){
        //cerr << i << endl;
        for(int j = c/2-i; j <= d/2-i; j++){
            //cerr << "  " << j << endl;
            if(a <= i*j && b >= i*j && i <= j){
                //cerr << i << " " << (j/2-i) << endl;
                n++;
            }
            else if(b < i*j)
                break;
        }
    }
    cout << n << endl;
    return 0;
}
