/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.11.15
 *
 * Comment: O(d^3), try only +-100, no overflow (use double)
 *   looks at pair and gets the third value optimal possible
 */

#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)

typedef long long ll;
typedef long double dbl;

dbl best;
int rx, ry, rz;

void relax( int x, int y, int z )
{
  dbl tmp;
  if ((tmp = (dbl)x * y * z) - best > 0)
    best = tmp, rx = x, ry = y, rz = z;
}

int main()
{
  #define NAME "sweets"
  assert(freopen(NAME ".in", "r", stdin));
  assert(freopen(NAME ".out", "w", stdout));

  int n, a, b, c;
  assert(scanf("%d%d%d%d", &n, &a, &b, &c) == 4);

  const int M = 100;
  int x0 = n / (3 * a);
  int y0 = n / (3 * b);
  int z0 = n / (3 * c);
  
  rx = x0, ry = y0, rz = z0;
  best = (dbl)x0 * y0 * z0;

  forab(dx, -M, M)
    forab(dy, -M, M)
      forab(dz, -M, M)
      {
        int x = x0 + dx, y = y0 + dy, z = z0 + dz;
        if (1 <= x && 1 <= y && 1 <= z)
        {
          if ((ll)a * x + (ll)b * y <= n) relax(x, y, (n - a * x - b * y) / c);
          if ((ll)c * z + (ll)b * y <= n) relax((n - c * z - b * y) / a, y, z);
          if ((ll)a * x + (ll)c * z <= n) relax(x, (n - a * x - c * z) / b, z);
        }
      }
  
  printf("%d %d %d\n", a * rx, b * ry, c * rz);
  return 0;
}
