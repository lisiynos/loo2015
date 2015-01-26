/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.11.15
 *
 * Comment: O(n^2), should get about 40 points
 */

#include <cstdio>
#include <ctime>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long double dbl;

const double TL = 1.0;

int cnt = 0;

int main()
{
  #define NAME "sweets"
  assert(freopen(NAME ".in", "r", stdin));
  assert(freopen(NAME ".out", "w", stdout));

  int n, a, b, c;
  assert(scanf("%d%d%d%d", &n, &a, &b, &c) == 4);

  dbl best = 0;
  int rx = 0, ry = 0, rz = 0;
  for (int x = 0; a * x <= n; x++)
  {
    for (int y = 0; a * x + b * y <= n; y++)
    {
      int z = (n - a * x - b * y) / c;
      dbl tmp = (dbl)x * y * z;
      if (tmp > best)
        best = tmp, rx = x, ry = y, rz = z;
      if ((++cnt & 1023) == 0 && clock() > TL * CLOCKS_PER_SEC)
        goto end;
    }
  }
  end:
  printf("%d %d %d\n", rx * a, ry * b, rz * c);
  return 0;
}
