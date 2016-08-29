#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
ifstream in("sum.in");
ofstream out("sum.out");

double sum = 0,a = 0,b = 0;

in >> a >> b;

out << fixed << setprecision(0) << a * a + b * b; 

return 0;
}