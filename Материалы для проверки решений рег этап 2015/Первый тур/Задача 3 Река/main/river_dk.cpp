#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

const int MAXN = 300031;


const int NEUTRAL_VALUE = INT_MIN;
const int NEUTRAL_DELTA = 0;

int joinValues(int leftValue, int rightValue) {
  return max(leftValue, rightValue);
}

int joinDeltas(int oldDelta, int newDelta) {
  return oldDelta + newDelta;
}

int joinValueWithDelta(int value, int delta, int length) {
  return value + delta;
}

struct treap {
  int nodeValue;
  int subTreeValue;
  int delta;
  int count;
  int prio;
  treap *l;
  treap *r;
};

treap nodes[MAXN];
int nodes_cnt;
vector<int> rnd;

static int getCount(treap* root) {
  return root ? root->count : 0;
}

static int getSubTreeValue(treap* root) {
  return root ? root->subTreeValue : NEUTRAL_VALUE;
}

void update(treap *root) {
  if (!root) return;
  root->subTreeValue = joinValues(joinValues(getSubTreeValue(root->l), root->nodeValue), getSubTreeValue(root->r));
  root->count = 1 + getCount(root->l) + getCount(root->r);
}

void applyDelta(treap *root, int delta) {
  if (!root) return;
  root->delta = joinDeltas(root->delta, delta);
  root->nodeValue = joinValueWithDelta(root->nodeValue, delta, 1);
  root->subTreeValue = joinValueWithDelta(root->subTreeValue, delta, root->count);
}

void pushDelta(treap* root) {
  if (!root) return;
  applyDelta(root->l, root->delta);
  applyDelta(root->r, root->delta);
  root->delta = NEUTRAL_DELTA;
}

void merge(treap* &t, treap* l, treap* r) {
  pushDelta(l);
  pushDelta(r);
  if (!l)
    t = r;
  else if (!r)
    t = l;
  else if (l->prio < r->prio)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;
  update(t);
}

void split(treap* t, treap* &l, treap* &r, int key) {
  pushDelta(t);
  if (!t)
    l = r = NULL;
  else if (key <= getCount(t->l))
    split(t->l, l, t->l, key), r = t;
  else
    split(t->r, t->r, r, key - getCount(t->l) - 1), l = t;
  update(t);
}

int get(treap* t, int index) {
  pushDelta(t);
  if (index < getCount(t->l))
    return get(t->l, index);
  else if (index > getCount(t->l))
    return get(t->r, index - getCount(t->l) - 1);
  return t->nodeValue;
}

void insert(treap* &t, treap* item, int index) {
  pushDelta(t);
  if (!t)
    t = item;
  else if (item->prio < t->prio)
    split(t, item->l, item->r, index), t = item;
  else if (index <= getCount(t->l))
    insert(t->l, item, index);
  else
    insert(t->r, item, index - getCount(t->l) - 1);
  update(t);
}

void insert(treap* &root, int index, int value) {
  treap *item = &nodes[nodes_cnt];
  item->nodeValue = value;
  item->subTreeValue = value;
  item->delta = NEUTRAL_DELTA;
  item->count = 1;
  item->prio = rnd[nodes_cnt];
  ++nodes_cnt;
  insert(root, item, index);
}

void remove(treap* &t, int index) {
  pushDelta(t);
  if (index == getCount(t->l))
    merge(t, t->l, t->r);
  else
    if (index < getCount(t->l))
      remove(t->l, index);
    else
      remove(t->r, index - getCount(t->l) - 1);
  update(t);
}

int query(treap* &root, int a, int b) {
  treap *l1, *r1;
  split(root, l1, r1, b + 1);
  treap *l2, *r2;
  split(l1, l2, r2, a);
  int res = getSubTreeValue(r2);
  treap *t;
  merge(t, l2, r2);
  merge(root, t, r1);
  return res;
}

void modify(treap* &root, int a, int b, int delta) {
  treap *l1, *r1;
  split(root, l1, r1, b + 1);
  treap *l2, *r2;
  split(l1, l2, r2, a);
  applyDelta(r2, delta);
  treap *t;
  merge(t, l2, r2);
  merge(root, t, r1);
}

void print(treap* t) {
  if (!t) return;
  pushDelta(t);
  print(t->l);
  cout << t->nodeValue << " ";
  print(t->r);
}

long long arr[MAXN];
int main() {
  freopen("river.in", "r", stdin);
  freopen("river.out", "w", stdout);
  for (int i = 0; i < MAXN; i++)
    rnd.push_back(i);
  random_shuffle(rnd.begin(), rnd.end());
  int n, subtask;
  cin >> n >> subtask;
  treap* t = NULL;
  long long ans = 0;
  long long xx;
  for (int i = 0; i < n; i++) {
    scanf(I64, &xx);
    ans += xx * xx;
    arr[i] = xx;
    insert(t, i, i);
  }
          
  int m;
  cin >> m;
  int e, v;
  long long x; 
  int l, r; 
  int j;
  printf(I64"\n", ans); 
  int cnt = n; 
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &e, &v);
    v--;
    j = get(t, v);
    x = arr[j];
    ans -= x * x;
    
    if (e == 1) remove(t, v);
           
    if (e == 1) {
      if (v == 0) {
        r = get(t, 0);
    ans -= arr[r] * arr[r];
    arr[r] += x;
    ans += (arr[r]) * (arr[r]);
      } else {
    //cerr << v << " " << getCount(t    );
        if (v == getCount(t)) {
          l = get(t, v - 1);
          ans -= arr[l] * arr[l];
      arr[l] += x;
      ans += (arr[l]) * (arr[l]);
        } else {
          r = get(t, v);

      ans -= arr[r] * arr[r];
      arr[r] += x / 2 + x % 2;
      ans += (arr[r]) * (arr[r]);
                                                            
          l = get(t, v - 1);
          ans -= arr[l] * arr[l];
      arr[l] += x / 2;
      ans += (arr[l]) * (arr[l]);
        }
      }
    } else {
      arr[j] = (x / 2);
      arr[cnt++] = (x / 2 + x % 2); 
      ans += (x / 2 + x % 2) * (x / 2 + x % 2);
      ans += (x / 2) * (x / 2);
      insert(t, v + 1, cnt - 1);
      //insert(t, v, j);
    }                 
    printf(I64"\n", ans);  
  }
}