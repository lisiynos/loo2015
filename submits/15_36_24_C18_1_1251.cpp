#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin ("hall.in");
    ofstream cout ("hall.out");
    int x1, x2, a, b, c, d, np, n = 0;
    cin >> a >> b >> c >> d;
    np = d/4;
    for(int i = 1; i <= np; i++){
        //cerr << i << endl;
        for(int j = c; j <= d; j+=2){
            //cerr << "  " << j << endl;
            if(a <= i*(j/2-i) && b >= i*(j/2-i) && i <= (j/2-i)){
                //cerr << i << " " << (j/2-i) << endl;
                n++;
            }
        }
    }
    cout << n << endl;
    return 0;
}
