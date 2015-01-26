#define NOFOOTER

#include <cassert>
#include <cstdlib>
#include <testlib.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main(int argc, char *argv[])
{
  registerValidation();

  int n = inf.readInt(1, 1000000000);
  forn(i, 3)
  {
    inf.readSpace();
    inf.readInt(1, n);
  }
  inf.readEoln();
  inf.readEof();
  return 0;
}
