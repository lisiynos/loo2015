#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream in("forest.in");
ofstream out("forest.out");

__int64 K = 5,M = 3,X = 43,A = 4,B = 1;
//in >> A >> K >> B >> M >> X;

__int64 days = 0;

if(X % (A + B) == 0){days = X / (A + B);}
else if(X % (A + B) != 0){days = X / (A + B) + 1;}

while((X - (A * (days - days / K) + B * (days - days / M))) > 0)
{
days++;
}

out << days;

return 0;
}