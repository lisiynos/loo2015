#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream in("tiling.in");
ofstream out("tiling.out");
int n = 0;
in >> n;

int rez = 2;
n--;

while(n != 0)
{
rez = rez * 3 + 1;
n--;
}

out << rez;
return 0;
}