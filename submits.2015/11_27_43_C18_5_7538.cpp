#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin ("circle.in");
    ofstream cout ("circle.out");
    int n, k;
    cin >> n;
    k = n*(n-1);
    if(n%2 == 0)
        k -= n;
    cout << k << endl;
    return 0;
}
