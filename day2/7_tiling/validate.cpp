#include "testlib.h"
#include <set>
#include <utility>
#include <cassert>

using namespace std;

int main()
{
    registerValidation();
    
    int n = inf.readInt(1, 100000);
    inf.readSpace();
    int k = inf.readInt(0, 2 * n);
    inf.readEoln();

    set<pair<int, int> > used;
    for (int i = 0; i < k; i++) {
        int x = inf.readInt(1, n);
        inf.readSpace();
        int y = inf.readInt(1, 2);
        inf.readEoln();

        pair<int, int> p = make_pair(x, y);
        assert(used.find(p) == used.end());
        used.insert(p);
    }
    inf.readEof();

    return 0;
}