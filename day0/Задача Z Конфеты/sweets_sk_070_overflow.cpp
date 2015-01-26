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

typedef long long ll;

int main()
{
  #define NAME "sweets"
  assert(freopen(NAME ".in", "r", stdin));
  assert(freopen(NAME ".out", "w", stdout));

  int n, a, b, c;
  assert(scanf("%d%d%d%d", &n, &a, &b, &c) == 4);

  ll best = 0;
  int rx = 0, ry = 0, rz = 0;
  int x0 = n / (3 * a);
  int y0 = n / (3 * b);
  int M = 3000, mx = n / a;
  for (int x = max(1, x0 - M); x <= min(mx, x0 + M); x++)
  {
    int my = (n - x * a) / b;
    for (int y = max(1, y0 - M); y <= min(my, y0 + M); y++)
    {
      int z = (n - a * x - b * y) / c;
      ll tmp = (ll)x * y * z;
      if (tmp > best)
        best = tmp, rx = x, ry = y, rz = z;
    }
  }
  
  //cout << best << endl;
  printf("%d %d %d\n", rx * a, ry * b, rz * c);
  return 0;
}
