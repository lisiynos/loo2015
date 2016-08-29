#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream in("forest.in");
ofstream out("forest.out");

__int64 K = 0,M = 0,X = 0;
int A = 0,B = 0;
in >> A >> K >> B >> M >> X;

int days = 1;

while(X > 0)
{
if(days % K != 0){X = X - A;}
if(days % M != 0){X = X - B;}
days++;
}

out << days;
return 0;
}