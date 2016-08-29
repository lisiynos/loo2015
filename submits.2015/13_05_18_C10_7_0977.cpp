#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin ("tiling.in");
    ofstream fout ("tiling.out");
    int x, k, n = 1, tmp = 1;
    cin >> x >> k;
    if(k == 0)
    for(int i = 0; i < x; i++){
        n += tmp;
        tmp *= (x-i);
    }
    if(n%2==0)
        n = n*2 - 1;
    else n*=2;
    cout << n << endl;
    return 0;
}
