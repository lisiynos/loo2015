#include <fstream>

using namespace std;

int main()
{
    fstream in ("sum.in");
    long long a, b;
    in>>a>>b;
    in.close();
    ofstream out ("sum.out");
    out<<a + b;
    out.close();
    return 0;
}
