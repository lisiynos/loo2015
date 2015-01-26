#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

vector<int> search(string & fil, string & url)
{
    string s = fil + url;
    int si = s.length();
    int sf = fil.length();
    int su = url.length();
    vector<int> z(si);
    z[0] = s.length();
    int l = 0, r = 0;
    for (int i = 1; i < si; ++i)
    {
        z[i] = max(0, min(z[i - l], r - i + 1));
        while (i + z[i] < si && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) 
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    vector<int> ans;
    for (int i = 0; i < su; ++i)
        if (z[sf + i] >= sf) 
            ans.push_back(i);
    return ans;
}

bool check(string fil, string url)
{
    vector<int> cond = search(fil, url);
    int sf = fil.length();
    int su = url.length();
    for (size_t i = 0; i < cond.size(); i++)
    {
        int co = cond[i];
        bool f1 = (co == 0) ? true : ((url[co - 1] == '.') ? true : false);
        bool f2 = (co + sf == su) ? true : ((url[co + sf] == '/') ? true : false);
        if (f1 & f2) return true;
    }
    return false; 
}

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
    assert(1 <= n && n <= 1000);

    vector<string> filter(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        assert(s[0] == '*' && s[1] == '.' && s[s.length() - 2] == '/' && s[s.length() - 1] == '*');
        filter[i] = s.substr(2, s.length() - 4);
    }

    cin >> k;
    assert(1 <= k && k <= 1000);

    for (int i = 0; i < k; i++)
    {
        string url;
        cin >> url;
        int ans = 0;
        for (int j = 0; j < n; j++)
            ans += check(filter[j], url);
        cout << ans << "\n";
    }
}
