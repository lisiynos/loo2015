#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
ifstream in("sumsqr.in");
ofstream out("sumsqr.out");

double sum = 0,a = 0,b = 0;

in >> a >> b;

sum = a * a + b * b; 

out << fixed << setprecision(0) << sum;

return 0;
}