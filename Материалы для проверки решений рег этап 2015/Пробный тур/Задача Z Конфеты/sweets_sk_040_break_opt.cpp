/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.11.15
 *
 * Comment: O(n^2), should get bit more than sweets_sk_030.cpp, but not too much.
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

int n, a[3], p[3], rx[3];
dbl best = 0;

bool aless( int i, int j )
{
  return a[i] < a[j];
}

void solve( int a, int b, int c, int &rx, int &ry, int &rz )
{
  fprintf(stderr, "%d\n%d\n%d\n", n / a, n / b, n / c);
  for (int x = 0; a * x <= n; x++)
  {
    for (int y = 0; a * x + b * y <= n; y++)
    {
      int z = (n - a * x - b * y) / c;
      dbl tmp = (dbl)x * y * z;
      if (tmp > best)
        best = tmp, rx = x, ry = y, rz = z;
      if ((++cnt & 1023) == 0 && clock() > TL * CLOCKS_PER_SEC)
        return;
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
