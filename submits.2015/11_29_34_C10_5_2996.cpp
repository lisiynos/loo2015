#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin ("circle.in");
    ofstream fout ("circle.out");
    int n, k, m;
    fin >> n;
    m = n*(n-1);
    if(n%2 == 0)
        m -= n;
    fout << m << endl;
    return 0;
}
