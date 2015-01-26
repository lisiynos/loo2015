#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream in("circle.in");
ofstream out("circle.out");

int n = 0;
in >> n;

int rez = 0;

if(n % 2 == 0){rez = (n - 2) * n;}
if(n % 2 != 0){rez = (n - 1) * n;} 

out << rez;
return 0;
}