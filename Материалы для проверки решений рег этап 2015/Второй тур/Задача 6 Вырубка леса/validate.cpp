#include "testlib.h"

using namespace std;

const long long E9 = 1000000000;
const long long E18 = E9 * E9;

int main()
{
    registerValidation();
    
    inf.readInt(1, E9);
    inf.readSpace();
    inf.readLong(2, E18);
    inf.readSpace();
    inf.readInt(1, E9);
    inf.readSpace();
    inf.readLong(2, E18);
    inf.readSpace();
    inf.readLong(1, E18);
    inf.readEoln();
    inf.readEof();

    return 0;
}