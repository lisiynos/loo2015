#include <iostream>
#include <fstream>
#define ULN unsigned long int
using namespace std;

ULN find(ULN a,ULN b,ULN c,ULN d)
{
	ULN rez = 1;
	ULN x = b,y = 1;


	while(x!=1 || y!=1)
	{
	if((x + y) * 2 < d + 1 && (x + y) * 2 > c - 1 && x*y > a - 1 && x*y < b + 1)
	{rez++;}

	if(y == 1)
	{x--;y = x;continue;}

    y--;
	}

return rez;
}

int main()
{
ifstream in("hall.in");
ofstream out("hall.out");

ULN A = 0,B = 0,C = 0,D = 0;
in >> A >> B >> C >> D;
out << find(A,B,C,D);


return 0;
}