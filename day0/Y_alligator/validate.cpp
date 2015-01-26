#include "testlib.h"
#include <cstdio>
#include <cstring>

const int MAXN = 2000;
char s[] = "SWEN.";

int main(int argc, char *argv[]) {
    registerValidation();
    int n = inf.readInt(1, MAXN);
    inf.readSpace();
    int m = inf.readInt(1, MAXN);
    inf.readEoln();
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; ++j) {
    		char c = inf.readChar();
	        ensuref(strrchr(s, c) != NULL, "wrong symbol on position (%d, %d)", i, j);
    	}
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
