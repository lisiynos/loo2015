/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.11.15
 */

#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)

typedef long double dbl;;

int n, a[3], p[3], rx[3];
dbl best = 0;

bool aless( int i, int j )
{
  return a[i] < a[j];
}

void solve( int a, int b, int c, int &rx, int &ry, int &rz )
{
  int x0 = n / (3 * a);
  int y0 = n / (3 * b);
  int M = 3000, mx = n / a;
  for (int x = max(1, x0 - M); x <= min(mx, x0 + M); x++)
  {
    int my = (n - x * a) / b;
    for (int y = max(1, y0 - M); y <= min(my, y0 + M); y++)
    {
      int z = (n - a * x - b * y) / c;
      dbl tmp = (dbl)x * y * z;
      if (!best || tmp - best > 0)
        best = tmp, rx = x, ry = y, rz = z;
    }
  }
}

int main()
{
  #define NAME "sweets"
  assert(freopen(NAME ".in", "r", stdin));
  assert(freopen(NAME ".out", "w", stdout));

  assert(scanf("%d%d%d%d", &n, &a[0], &a[1], &a[2]) == 4);
  forn(i, 3)
    p[i] = i;
  sort(p, p + 3, aless);
  reverse(p, p + 3);
  solve(a[p[0]], a[p[1]], a[p[2]], rx[p[0]], rx[p[1]], rx[p[2]]);

  //cout << best << endl;
  printf("%d %d %d\n", rx[0] * a[0], rx[1] * a[1], rx[2] * a[2]);
  return 0;
}
