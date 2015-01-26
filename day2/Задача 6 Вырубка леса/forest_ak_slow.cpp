#include <fstream>

using namespace std;

int main()
{
    ifstream in("forest.in");
    long long a, k, b, m, x;
    in >> a >> k >> b >> m >> x;
    long long guess = x / (a + b) - 1;
    long long sum;
    do {
        guess++;
        long long cut1 = a * (k - 1) * (guess / k) + a * (guess % k);
        long long cut2 = b * (m - 1) * (guess / m) + b * (guess % m);
        sum = cut1 + cut2;
    } while (sum < x);
    ofstream("forest.out") << guess << "\n";
}
