#include <fstream>
#include <iostream>
using namespace std;

long long calc(int b, int d) {
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
    return ans;
}

int main() {
    int a, b, c, d;

    ifstream fin("hall.in");
    ofstream fou("hall.out");

    fin >> a >> b >> c >> d;

    long long ans = calc(b, d) - calc(b, c - 1) - calc(a - 1, d) + calc(a - 1, c - 1);

    fou << ans << endl;

    return 0;
}
