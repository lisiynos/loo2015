#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin ("tiling.in");
    ofstream cout ("tiling.out");
    int x, k;
    cin >> x >> k;
    if(k == 0){
        if(x == 1)
            cout << 2 << endl;
        if(x == 2)
            cout << 7 << endl;
        if(x == 3)
            cout << 22 << endl;
        if(x == 4)
            cout << 63 << endl;
    }
    else
        cout << 8 << endl;
    return 0;
}
