/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.11.15
 *
 * Comment: O(1), try only +-8
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

int main()
{
  #define NAME "sweets"
  assert(freopen(NAME ".in", "r", stdin));
  assert(freopen(NAME ".out", "w", stdout));

  int n, a, b, c;
  assert(scanf("%d%d%d%d", &n, &a, &b, &c) == 4);

  const int M = 8;
  int x0 = n / (3 * a);
  int y0 = n / (3 * b);
  int z0 = n / (3 * c);
  int rx = x0, ry = y0, rz = z0;
  dbl best = (ll)x0 * y0 * z0, tmp;
  forab(dx, -M, M)
    forab(dy, -M, M)
      forab(dz, -M, M)
      {
        int x = x0 + dx, y = y0 + dy, z = z0 + dz;
        if (1 <= x && 1 <= y && 1 <= z && (ll)a * x + (ll)b * y + (ll)c * z <= n)
          if ((tmp = (dbl)x * y * z) - best > 0)
            best = tmp, rx = x, ry = y, rz = z;
      }
  
  printf("%d %d %d\n", a * rx, b * ry, c * rz);
  return 0;
}
