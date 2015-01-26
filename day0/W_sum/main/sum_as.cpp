#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int a, b;

    ifstream fin("sum.in");
    ofstream fou("sum.out");

    fin >> a >> b;

    fou << a + b << endl;

    return 0;
}
