#include <fstream>
using namespace std;

int main() {
    int a, b, c, d;

    ifstream fin("hall.in");
    ofstream fou("hall.out");

    fin >> a >> b >> c >> d;

    int ans = 0;
    for (int x = 1; x <= d / 2; x++) {
        for (int y = x; y <= d / 2; y++) {
            if (a <= x * y && x * y <= b && c <= 2 * (x + y) && 2 * (x + y) <= d) {
                ans++;
            }
            if (x * y > b || 2 * (x + y) > d) {
                break;
            }
        }
    }
    fou << ans << endl;

    return 0;
}
