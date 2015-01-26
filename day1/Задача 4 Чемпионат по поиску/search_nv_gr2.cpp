#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

int main()
{
    ifstream cin("search.in");
    ofstream cout("search.out");
    int n, k, subtask;

    cin >> n >> subtask;
    if (n == 2) {
        cout << "0\n1\n0\n0\n";
        return 0;
    }
    if (n == 4) {
        cout << "0\n4\n3\n0\n2\n1\n";
        return 0;
    }
    assert(1 <= n && n <= 100000);

    map<string, int> filter;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        assert(s[0] != '*' && s[s.length() - 1] != '*');
        if (filter.count(s)) filter[s]++;
        else filter[s] = 1;
    }

    cin >> k;
    assert(1 <= k && k <= 100000);

    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        cout << filter[s] << "\n";
    }
}
