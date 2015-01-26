/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.11.15
 */

#include <cstdio>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long double dbl;

int main()
{
  #define NAME "sweets"
  assert(freopen(NAME ".in", "r", stdin));
  assert(freopen(NAME ".out", "w", stdout));

  int n, a, b, c;
  assert(scanf("%d%d%d%d", &n, &a, &b, &c) == 4);

  dbl best = 0;
  int rx = 0, ry = 0, rz = 0;
  int x0 = n / (3 * a);
  int y0 = n / (3 * b);

  int cnt = (int)1e7; // numer of operations
  int MX = sqrt(cnt) / 2, mx = n / a;
  int len = min(mx, x0 + MX) - max(1, x0 - MX) + 1;
  int MY = cnt / max(len, 1) / 2;
  for (int x = max(1, x0 - MX); x <= min(mx, x0 + MX); x++)
  {
    int my = (n - x * a) / b;
    for (int y = max(1, y0 - MY); y <= min(my, y0 + MY); y++)
    {
      int z = (n - a * x - b * y) / c;
      dbl tmp = (dbl)x * y * z;
      if (!best || tmp - best > 0)
        best = tmp, rx = x, ry = y, rz = z;
    }
  }
  
  printf("%d %d %d\n", rx * a, ry * b, rz * c);
  return 0;
}
