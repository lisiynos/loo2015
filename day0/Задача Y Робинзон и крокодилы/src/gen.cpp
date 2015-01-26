// все бегут в двух направлениях
#include "rand.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <ctime>

using std::vector;

int main(int argc, char * argv[])
{
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);
	char* s = argv[3];
	z_srand(atoi(argv[4]));

	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int q = rand32() % strlen(s);
			printf("%c", s[q]);
		}
		puts("");
	}
	
	return 0;
}
