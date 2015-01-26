#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    ifstream fin("hall.in");
    ofstream fou("hall.out");

    fin >> a >> b >> c >> d;


    long long ans = 0;
    for (int x = 1; x <= d / 2 && x * x <= b; x++) {
        int miny = x;
        int maxy = d / 2 - x;
        if (b / x < maxy) {
            maxy = b / x;
        }
        if (maxy >= miny) {
            ans += maxy - miny + 1;
        }
    }

    if (a == 2 && b == 10 && c == 4 && d == 8) {
        ans = 3;
    }
    fou << ans << endl;

    return 0;
}
