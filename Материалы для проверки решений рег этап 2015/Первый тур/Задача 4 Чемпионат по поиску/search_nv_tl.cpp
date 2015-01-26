#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cassert>

using namespace std;

pair<string, string> prepare1(string& s)
{
    bool f = true;
    pair<string, string> ans;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '/' && f)
        {
            f = false;
            continue;
        }
        if (f) ans.first += s[i];
        else ans.second += s[i];
    }
    return ans;
}

vector<string> prepare2(string& s)
{
    vector<string> ans(1);
    for (size_t i = 0; i < s.length(); i++)
        if (s[i] == '/' || s[i] == '.') 
            ans.push_back("");
        else ans.back() += s[i];
    return ans;
}

bool check(vector<string>& url, vector<string>& filter)
{
    for (size_t i = 0; i < filter.size(); i++)
    {
        if (i == url.size())
        {
            if (filter[i] == "*") return true;
            else return false;
        }

        if (url[i] != filter[i])
        {
            if (filter[i] == "*") return true;
            else return false;
        }
    }
    return filter.size() == url.size();
}

int main()
{
    ifstream cin("search.in");
    ofstream cout("search.out");

    int n, k, subtask;

    cin >> n >> subtask;
    vector<vector<string> > suff_filter(n), pref_filter(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        pair<string, string> pref_suff = prepare1(s);
        string pref = pref_suff.first, suff = pref_suff.second;
        reverse(pref.begin(), pref.end());
        vector<string> pf = prepare2(pref);
        vector<string> sf = prepare2(suff);
        suff_filter[i] = sf;
        pref_filter[i] = pf;
    }
    cin >> k;
//    assert(n * 1LL * k < e9 + 7); 
    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        pair<string, string> pref_suff = prepare1(s);
        string pref = pref_suff.first, suff = pref_suff.second;
        reverse(pref.begin(), pref.end());
        vector<string> pf = prepare2(pref);
        vector<string> sf = prepare2(suff);
        int ans = 0;
        for (int j = 0; j < n; j++)
            if (check(pf, pref_filter[j]) & check(sf, suff_filter[j])) ans++;
        cout << ans << "\n";
    }   
}
