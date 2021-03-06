#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <set>
using namespace std;
class gg
{
public:
    int v;
    int l;
    int r;
};
gg mgg(int g, int h, int j)
{
    gg r;
    r.v = g;
    r.l = h;
    r.r = j;
    return r;
}
vector <gg> tree;
vector <int> a, s;

gg maxg (gg q, gg w)
{
    gg e;
    e.v = max(q.v, w.v);
    e.l = q.l;
    e.r = w.r;
    return e;
}

int make_tree(int l, int r, int i)
{

    if (l == r)
    {
        tree[i].v = a[l];
        tree[i].l = l;
        tree[i].r = r;
        //cout << l << " " << r << " ";
        //cout << tree[i].v <<endl;
        return 0;
    }
    int c = (l + r)/2;
    make_tree(l, c, 2 * i);
    make_tree(c + 1, r, 2 * i + 1);
    tree[i] = maxg(tree[2 * i], tree[2 * i + 1]);
    //cout << l << " " << r << " ";
    //cout << tree[i].v <<endl;
    return 0;
}

long long mint(int l, int r, int i)
{
    if ((tree[i].l == l)&&(tree[i].r == r))
    {
        return tree[i].v;
    }
    int c = (l + r)/2;
    long long q = 0, w = 0;
    if (tree[2 * i].r  >= l)
        q = mint(l, tree[2 * i].r, 2 * i);

    if (tree[2 * i + 1].l  <= r)
        w = mint(tree[2 * i + 1].l, r, 2 * i + 1);
    return max(q, w);
}
int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int n, k, b;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        s.push_back(b);
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += s[i];
    }
    for (int i = 0; i < n - k + 1; i++)
    {
        a.push_back(sum);
        sum -= s[i];
        sum += s[i + k];
    }
    tree.resize(a.size() * 4);
    make_tree(0, a.size() - 1, 1);
    long long counter = 999999999;
    for (int i = 0; i < a.size(); i++)
    {
        int l0, r0, l1, r1;
        l0 = 0;
        r1 = a.size() - 1;
        r0 = i - k;
        l1 = i + k;
        long long  h0 = 0, h1 = 0;
        if (l0 <= r0)
        {
            //cout << "l";
            h0 = mint(l0, r0, 1);
        }


        if (l1 <= r1)
        {
            //cout << "r";
            h1 = mint(l1, r1, 1);
        }
        //cout << h0 << " " << h1 << endl;
        counter = min(counter, max(h0, h1));
    }
    cout << counter;
    return 0;
}
