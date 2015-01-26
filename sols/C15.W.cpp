#include <iostream>
#include <fstream>

using namespace std;

int main()
{
ifstream in("sum.in");
ofstream out("sum.out");

unsigned int sum = 0,a = 0,b = 0;

in >> a >> b;

out << a + b; 

return 0;
}