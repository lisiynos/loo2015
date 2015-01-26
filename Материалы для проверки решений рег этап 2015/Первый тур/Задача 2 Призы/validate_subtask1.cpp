#include "testlib.h"

using namespace std;

int main()
{
    registerValidation();

    int n = inf.readInt(3, 50);
    inf.readSpace();
    int k = inf.readInt(1, n / 3);
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        inf.readInt(1, 100000);
        if (i < n - 1) {
            inf.readSpace();
        }
    }
    
    inf.readEoln();
    inf.readEof();

    return 0;
}