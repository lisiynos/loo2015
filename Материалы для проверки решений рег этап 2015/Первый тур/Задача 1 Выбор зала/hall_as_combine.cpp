#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    ifstream fin("hall.in");
    ofstream fou("hall.out");

    fin >> a >> b >> c >> d;

    long long ans = 0;
    if (b <= 1000 || d <= 1000) {
        for (int x = 1; x <= d / 2; x++) {
            for (int y = x; y <= d / 2; y++) {
                if (a <= x * y && x * y <= b && c <= 2 * (x + y) && 2 * (x + y) <= d) {
                    ans++;
                }
            }
        }
    } else {
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
    }
    fou << ans << endl;

    return 0;
}
