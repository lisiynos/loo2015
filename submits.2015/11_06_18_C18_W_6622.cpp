#include <iostream>
#include <fstream>

using namespace std;



int main(){
    ifstream cin ("sum.in");
    ofstream cout ("sum.out");
    long long a, b;
    cin >> a >> b;
    cout << a+b << endl;
    return 0;
}
