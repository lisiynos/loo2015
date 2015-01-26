#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

vector<map<string, int> > trie(1);

int add_filter(vector<string> &s) {
    int cur = 0;
    for (size_t i = 0; i < s.size(); i++) {
        string t = s[i];
        if (!trie[cur].count(t)) {
            trie[cur][t] = trie.size();
            trie.push_back(map<string, int>());
        }
        cur = trie[cur][t];
    }
    return cur;
}

map<pair<int, int>, int> filters[2][2];

vector<int> find(vector<string> &s) {
    int cur = 0;
    vector<int> ans(1);
    for (size_t i = 0; i < s.size(); i++) {
        string t = s[i];
        if (!trie[cur].count(t)) {
            ans.push_back(-1);
            return ans;
        }
        cur = trie[cur][t];
        ans.push_back(cur);
    }
    return ans;
}

pair<string, string> prepare1(string &s) {
    bool f = true;
    pair<string, string> ans;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '/' && f) {
            f = false;
            continue;
        }
        if (f) ans.first += s[i];
        else ans.second += s[i];
    }
    return ans;
}

vector<string> prepare2(string &s) {
    vector<string> ans(1);
    for (size_t i = 0; i < s.length(); i++)
        if (s[i] == '/' || s[i] == '.')
            ans.push_back("");
        else ans.back() += s[i];
    return ans;
}

int main() {
    ifstream cin("search.in");
    ofstream cout("search.out");

    int n, k, subtask;

    cin >> n >> subtask;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        pair<string, string> pref_suff = prepare1(s);
        string pref = pref_suff.first, suff = pref_suff.second;
        reverse(pref.begin(), pref.end());
        vector<string> pf = prepare2(pref);
        vector<string> sf = prepare2(suff);
        bool pref_star = false, suff_star = false;
        if (pf.back() == "*") {
            pref_star = true;
            pf.pop_back();
        }
        if (sf.back() == "*") {
            suff_star = true;
            sf.pop_back();
        }
        pair<int, int> fil = make_pair(add_filter(pf), add_filter(sf));
        if (filters[pref_star][suff_star].count(fil)) filters[pref_star][suff_star][fil] += 1;
        else filters[pref_star][suff_star][fil] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        pair<string, string> pref_suff = prepare1(s);
        string pref = pref_suff.first, suff = pref_suff.second;
        reverse(pref.begin(), pref.end());
        vector<string> pf = prepare2(pref);
        vector<string> sf = prepare2(suff);
        vector<int> pr = find(pf);
        vector<int> su = find(sf);
        int ans = 0;
        if (pr.size() == 0 || su.size() == 0)
            continue;

        // equal / equal
        pair<int, int> cond = make_pair(pr.back(), su.back());
        if (filters[0][0].count(cond)) ans += filters[0][0][cond];

        // equal / star
        for (size_t j = 0; j < su.size(); j++) {
            cond = make_pair(pr.back(), su[j]);
            if (filters[0][1].count(cond)) ans += filters[0][1][cond];
        }
        // star / equal
        for (size_t i = 0; i < pr.size(); i++) {
            cond = make_pair(pr[i], su.back());
            if (filters[1][0].count(cond)) ans += filters[1][0][cond];
        }

        // star / star
        for (size_t i = 0; i < pr.size(); i++)
            for (size_t j = 0; j < su.size(); j++) {
                cond = make_pair(pr[i], su[j]);
                if (filters[1][1].count(cond)) ans += filters[1][1][cond];
            }
        cout << ans << "\n";
    }
}
