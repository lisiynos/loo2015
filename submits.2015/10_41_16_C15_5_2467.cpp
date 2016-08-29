#include <iostream>
#include <fstream>
using namespace std;

void main()
{
ifstream in("circle.in");
ofstream out("circle.out");

int n = 0;
in >> n;

int A = 0,B = 0;

out << (n - 1) * n;
}