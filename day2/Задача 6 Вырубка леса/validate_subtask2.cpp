#include "testlib.h"
#include <cassert>

using namespace std;

const long long E9 = 1000000000;
const long long E18 = E9 * E9;

int main()
{
    registerValidation();
    
    inf.readInt(1, E9);
    inf.readSpace();
    long long k = inf.readLong(2, E18);
    inf.readSpace();
    inf.readInt(1, E9);
    inf.readSpace();
    long long m = inf.readLong(2, E18);
    inf.readSpace();
    long long x = inf.readLong(1, E18);
    inf.readEoln();
    inf.readEof();

    assert(x < k);
    assert(x < m);

    return 0;
}