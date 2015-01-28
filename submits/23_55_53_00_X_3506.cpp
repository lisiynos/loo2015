#include <fstream>
#include <iostream>
using namespace std;

int main() {
    long long a, b;

    ifstream fin("sumsqr.in");
    ofstream fou("sumsqr.out");

    fin >> a >> b;

    fou << a * a + b * b << endl;

    return 0;
}
