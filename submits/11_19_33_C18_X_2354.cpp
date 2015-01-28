#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin ("sumsqr.in");
    ofstream cout ("sumsqr.out");
    long long a, b;
    cin >> a >> b;
    cout << a*a + b*b << endl;
    return 0;
}
