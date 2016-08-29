#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ifstream in("forest.in");
ofstream out("forest.out");

__int64 A = 0,K = 0,B = 0,M = 0,X = 0;
in >> A >> K >> B >> M >> X;

__int64 days = 0;

days = X / (A + B);

days += days / K + days / M; 

out << days;
return 0;
}