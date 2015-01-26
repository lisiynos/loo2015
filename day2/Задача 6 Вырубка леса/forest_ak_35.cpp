#include <fstream>

using namespace std;

int main()
{
    ifstream in("forest.in");
    long long a, k, b, m, x;
    in >> a >> k >> b >> m >> x;
    int i;
    for (i = 1; x > 0; i++)
        x -= a * !!(i % k) + b * !!(i % m);
    ofstream("forest.out") << i - 1 << "\n";
}
