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

out << fixed << setprecision(0) << a * a + b * b; 

return 0;
}