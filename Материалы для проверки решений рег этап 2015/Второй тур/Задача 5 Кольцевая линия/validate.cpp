#include "testlib.h"

using namespace std;

int main()
{
    registerValidation();
    
    inf.readInt(1, 40000);
    inf.readEoln();
    inf.readEof();

    return 0;
}