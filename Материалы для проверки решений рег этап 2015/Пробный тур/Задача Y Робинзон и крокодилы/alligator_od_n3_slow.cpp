#include <cstdio>

const int N = 2010;

char a[N][N];
int nxt_left[N], nxt_right[N];
int nxt_up[N], nxt_down[N];

int main()
{
	freopen("alligator.in", "r", stdin);
	freopen("alligator.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	
	for (int i = 0; i < n; ++i)
	{
		nxt_left[i] = 0;
		nxt_right[i] = m - 1;
	}
	for (int i = 0; i < m; ++i)
	{
		nxt_up[i] = 0;
		nxt_down[i] = n - 1;
	}
	
	int oldans = -1;
	int ans = 0;
	while (oldans != ans)
	{
		oldans = ans;
		for (int i = 0; i < n; ++i)
		{
			while (nxt_left[i] <= nxt_right[i] && a[i][nxt_left[i]] == '.')
				nxt_left[i]++;
			if (nxt_left[i] <= nxt_right[i] && (a[i][nxt_left[i]] == '.' || a[i][nxt_left[i]] == 'W'))
			{
				if (a[i][nxt_left[i]] == 'W')
				{
					a[i][nxt_left[i]] = '.';
					ans++;
				}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			while (nxt_up[i] <= nxt_down[i] && a[nxt_down[i]][i] == '.')
				nxt_down[i]--;
			if (nxt_up[i] <= nxt_down[i] && (a[nxt_down[i]][i] == '.' || a[nxt_down[i]][i] == 'S'))
			{
				if (a[nxt_down[i]][i] == 'S')
				{
					a[nxt_down[i]][i] = '.';
					ans++;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			while (nxt_left[i] <= nxt_right[i] && a[i][nxt_right[i]] == '.')
				nxt_right[i]--;
			if (nxt_left[i] <= nxt_right[i] && (a[i][nxt_right[i]] == '.' || a[i][nxt_right[i]] == 'E'))
			{
				if (a[i][nxt_right[i]] == 'E')
				{
					a[i][nxt_right[i]] = '.';
					ans++;
				}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			while (nxt_up[i] <= nxt_down[i] && a[nxt_up[i]][i] == '.')
				nxt_up[i]++;
			if (nxt_up[i] <= nxt_down[i] && (a[nxt_up[i]][i] == '.' || a[nxt_up[i]][i] == 'N'))
			{
				if (a[nxt_up[i]][i] == 'N')
				{
					a[nxt_up[i]][i] = '.';
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
