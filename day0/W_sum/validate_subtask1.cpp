#include "testlib.h"

using namespace std;

int main()
{
    registerValidation();
    
    inf.readInt(1, 1000);
    inf.readSpace();
    inf.readInt(1, 1000);
    inf.readEoln();
    inf.readEof();

    return 0;
}