//чуваки расставляются по спиральке от центра и бегут в сторону движения или от центра спирали. 
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
	z_srand(atoi(argv[4]));

	if (c == 1) {
		reverse(s, s + 4);
		for (int i = 0; i < 2; ++i) {
			swap(d[i][0], d[3 - i][0]);
			swap(d[i][1], d[3 - i][1]);
		}
	}

	memset(a, '.', sizeof(a));

	printf("%d %d\n", n, m);
	int x = n / 2;
	int y = m / 2;

	int dir = 0;

	int l = 0;
	for (int i = 0; ; ++i) {
		dir = (dir + 1) % 4;
		if (i % 2 == 0) {
			++l;
		}
		for (int j = 0; j < l; ++j) {
			if (!on_field(x, y))
				break;
			a[x][y] = s[(dir + 2 + rand32() % 2) % 4];
			x += d[dir][0];
			y += d[dir][1];
		}
		if (!on_field(x, y))
			break;
	}

	for (int i = 0; i < n; ++i) {
		a[i][m] = 0;
		puts(a[i]);
	}		
	
	return 0;
}
