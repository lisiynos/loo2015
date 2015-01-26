#include <fstream>

using namespace std;

int main()
{
    ifstream in("forest.in");
    long long a, k, b, m, x;
    in >> a >> k >> b >> m >> x;
    int i;
    long long k2 = k;
    long long m2 = m;
    for (i = 1; x > 0; i++)
    {
        k2--;
        m2--;
        x -= a * !!k2 + b * !!m2;
        k2 += !k2 * k;
        m2 += !m2 * m;
    }
    ofstream("forest.out") << i - 1 << "\n";
}
