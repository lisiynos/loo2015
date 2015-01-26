#include <cstdio>
#include <iostream>

using namespace std;

const int N = 2010;

char a[N][N];

int main()
{
	freopen("alligator.in", "r", stdin);
	freopen("alligator.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	
	int oldans = -1;
	int ans = 0;
	while (oldans != ans)
	{
		oldans = ans;
		for (int i = 0; i < n; ++i)	
			for (int j = 0; j < m; ++j)
			{
				if (a[i][j] == 'W')
				{
					bool ok = true;
					for (int u = 0; u < j; ++u)
					{
						if (a[i][u] != '.') {
							ok = false;
							break;
						}
					}
					if (ok)
					{
						++ans;
						a[i][j] = '.';
					}
				}
				if (a[i][j] == 'E')
				{
					bool ok = true;
					for (int u = j + 1; u < m; ++u)
					{
						if (a[i][u] != '.') {
							ok = false;
							break;
						}
					}
					if (ok)
					{
						++ans;
						a[i][j] = '.';
					}
				}
				if (a[i][j] == 'N')
				{
					bool ok = true;
					for (int u = 0; u < i; ++u)
					{
						if (a[u][j] != '.') {
							ok = false;
							break;
						}
					}
					if (ok)
					{
						++ans;
						a[i][j] = '.';
					}
				}
				if (a[i][j] == 'S')
				{
					bool ok = true;
					for (int u = i + 1; u < n; ++u)
					{
						if (a[u][j] != '.') {
							ok = false;
							break;
						}
					}
					if (ok)
					{
						++ans;
						a[i][j] = '.';
					}
				}
			}
	}
	printf("%d\n", ans);
	return 0;
}
