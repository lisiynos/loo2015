#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    ifstream fin("hall.in");
    ofstream fou("hall.out");

    fin >> a >> b >> c >> d;

    int ans = 0;
    for (int x = 1; x <= d / 2 && x * x <= b; x++) {
        int miny = x;
        if ((c + 1) / 2 - x > miny) {
            miny = (c + 1) / 2 - x;
        }
        if ((a + x - 1) / x > miny) {
            miny = (a + x - 1) / x;
        }
        int maxy = d / 2 - x;
        if (b / x < maxy) {
            maxy = b / x;
        }
        if (maxy >= miny) {
            ans += maxy - miny + 1;
        }
    }
    fou << ans << endl;

    return 0;
}
