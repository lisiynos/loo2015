#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream in("forest.in");
ofstream out("forest.out");

__int64 K = 0,M = 0,X = 0,A = 0,B = 0;
in >> A >> K >> B >> M >> X;

__int64 days = 0;

while(X > 0)
{
days++;

if(days % K != 0){X = X - A;}
if(days % M != 0){X = X - B;}
}

out << days;
return 0;
}