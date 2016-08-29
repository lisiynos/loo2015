#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ifstream in ("hall.in");
    int a, b, c, d, answer = 0, d1, b1;
    in>>a>>b>>c>>d;
    in.close();
    d1 = d / 2 + 1;
    b1 = sqrt(b) + 1;
    for (int i = 1; (i + i <= d1) and (i * i <= b1); i++)
        for (int j = i; (i + j <= d1) and (i * j <= b1); j++)
            if (((2 *(i + j) >= c) and (i * j >= a)) and ((2 *(i + j) <= d) and (i * j <= b)))
                answer++;
    ofstream out ("hall.out");
    out<<answer<<endl;
    out.close();
    return 0;
}
