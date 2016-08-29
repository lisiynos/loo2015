#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin ("hall.in");
    ofstream cout ("hall.out");
    int x1, x2, a, b, c, d, np, n = 0;
    cin >> a >> b >> c >> d;
    np = d/4 - c/4;
    for(int i = 1; i <= np; i++)
        for(int j = c; j <= d; j++)
            if(a <= i*(j/2-i) && b >= i*(j/2-i))
                n++;
    cout << n << endl;
    return 0;
}
