/**                                                  /
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.11.15
 *
 * Comment: O(n^3), should get about 20 points
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

int main()
{
  #define NAME "sweets"
  assert(freopen(NAME ".in", "r", stdin));
  assert(freopen(NAME ".out", "w", stdout));

  int n, a, b, c;
  assert(scanf("%d%d%d%d", &n, &a, &b, &c) == 4);

  dbl best = 0, tmp;
  int rx = 0, ry = 0, rz = 0;
  for (int x = 0; x <= n; x += a)
    for (int y = 0; x + y <= n; y += b)
    {
      int n0 = n - x - y;
      for (int z = 0; z <= n0; z += c)
        if ((tmp = (dbl)x * y * z) > best)
          best = tmp, rx = x, ry = y, rz = z;

      if (clock() > 0.9 * TL * CLOCKS_PER_SEC)
        goto end;
    }
  
  end:
  printf("%d %d %d\n", rx, ry, rz);
  return 0;
}
