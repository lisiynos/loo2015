#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class gg
{
public:
    unsigned long long v;
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
vector <unsigned long long> a, s;

gg maxg (gg q, gg w)
{
    gg e;
    //e.v = max(q.v, w.v);
    if (q.v < w.v)
        q.v = w.v;
    e.v = q.v;
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
        return 0;
    }
    int c = (l + r)/2;
    make_tree(l, c, 2 * i);
    make_tree(c + 1, r, (2 * i) + 1);
    tree[i] = maxg(tree[2 * i], tree[(2 * i) + 1]);
    return 0;
}

unsigned long long mint(int l, int r, int i)
{
    if ((tree[i].l == l)&&(tree[i].r == r))
    {
        return tree[i].v;
    }
    unsigned long long q = 0, w = 0;
    if (tree[2 * i].r  >= l)
        q = mint(l, min(tree[2 * i].r, r), 2 * i);

    if (tree[(2 * i) + 1].l  <= r)
        w = mint(max(tree[(2 * i) + 1].l, l), r, (2 * i) + 1);
    if (q < w)
        q = w;
    return q;
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
        //cout << a[i] << " ";
    }
    tree.resize(a.size() * 4);
    make_tree(0, a.size() - 1, 1);
    unsigned long long counter = 199999999999999;
    //cout << counter;
    //cout << endl << "199999999999999" << endl;
    for (int i = 0; i < a.size(); i++)
    {
        int l0, r0, l1, r1;
        l0 = 0;
        r1 = a.size() - 1;
        r0 = i - k;
        l1 = i + k;
        unsigned long long  h0 = 0, h1 = 0;
        if (l0 <= r0)
        {
            h0 = mint(l0, r0, 1);
        }
        if (l1 <= r1)
        {
            h1 = mint(l1, r1, 1);
        }
        //cout << i << " " << h0 << " " << h1 << endl;
        if (h0 < h1)
            h0 = h1;

        if (counter > h0)
            counter = h0;
    }
    cout << counter;
    //cout << mint(5, 6, 1);
    return 0;
}
