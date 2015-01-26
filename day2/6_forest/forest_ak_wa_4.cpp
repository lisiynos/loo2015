#include <fstream>

using namespace std;

int main()
{
    ifstream in("forest.in");
    long a, k, b, m, x;
    in >> a >> k >> b >> m >> x;
    long left = 0;
    long right = 3e18 / (a + b); // overflows
    while (left + 1 <= right)
    {
        long c = (left + right) / 2;
        long cut1 = a * (k - 1) * (c / k) + a * (c % k);
        long cut2 = b * (m - 1) * (c / m) + b * (c % m);
        if (cut1 + cut2 >= x)
            right = c;
        else
            left = c;
    }
    ofstream("forest.out") << right << "\n";
}
