#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int dist(int a, int b, int n) {
    return min(abs(b - a), min(b + n - a, a + n - b));
}

int main() {
    int n;

    ifstream fin("circle.in");
    ofstream fou("circle.out");

    fin >> n;

    int ans = n * (n - 1);
    if (n % 2 == 0) {
        ans -= n;
    }

    fou << ans << endl;

    return 0;
}
