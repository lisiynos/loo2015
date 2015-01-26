#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

int main() {
  freopen("circle.in", "r", stdin);
  freopen("circle.out", "w", stdout);
  int n;
  scanf("%d", &n);
  printf("%d\n", (n & 1) ? (n * (n - 1)) : (n * (n / 2)));
  return 0;
}
