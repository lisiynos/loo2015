#include <fstream>

using namespace std;

int main()
{
    ifstream in("forest.in");
    long long a, k, b, m, x;
    in >> a >> k >> b >> m >> x;
    long long left = 0;
    long long right = x;
    while (left + 1 < right)
    {
        long long c = (left + right) / 2;
        long long cut1 = a * (k - 1) * (c / k) + a * (c % k);
        long long cut2 = b * (m - 1) * (c / m) + b * (c % m);
        if (cut1 + cut2 >= x)
            right = c;
        else
            left = c;
    }
    ofstream("forest.out") << right << "\n";
}
