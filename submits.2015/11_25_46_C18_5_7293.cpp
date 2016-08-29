#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin ("circle.in");
    ofstream cout ("circle.out");
    int n, Max, k;
    cin >> n;
    Max = n*(n-1);
    if(n%2 == 0)
        Max -= n;
    cout << Max << endl;
    return 0;
}
