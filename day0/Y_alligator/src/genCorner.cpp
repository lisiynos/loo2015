//чуваки расставляются по спиральке от центра и бегут в сторону движения. 
//Разматывая спираль снаружи, можно всех распугать
#include "rand.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char s[] = "SENW";
char a[2010][2010];

bool on_field(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main(int argc, char * argv[])
{
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	int c = atoi(argv[3]);

	printf("%d %d\n", n, m);	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((c == 0 && i >= j) || (c == 1 && i >= max(n, m) - j))
				printf("N");
			else
			if ((c == 0 && i <= j) || (c == 3 && i >= max(n, m) - j))
				printf("W");
			else
			if ((c == 2 && i >= j) || (c == 1 && i <= max(n, m) - j))
				printf("E");
			else
			if ((c == 2 && i <= j) || (c == 3 && i <= max(n, m) - j))
				printf("S");
		}
		puts("");
	}
	return 0;
}
