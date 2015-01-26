#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

struct Node {
  Node* left;
  Node* right;
  Node* parent;
  int value;
  int cnt;
  long long sum;

  Node(int value) : value(value) {
    left = NULL;
    right = NULL;
    parent = NULL;
    cnt = 1;
    sum = value * 1LL * value;
  }

  void divide(int id) {
    if (this->cnt == 1) {
      this->left = new Node(value / 2);
      this->right = new Node(value - value / 2);
      this->left->parent = this;
      this->right->parent = this;
      this->cnt = this->left->cnt + this->right->cnt;
      this->sum = this->left->sum + this->right->sum;
      return;
    }
    if (id < this->left->cnt) {
      this->left->divide(id);
    } else {
      this->right->divide(id - this->left->cnt);
    }
    this->cnt = this->left->cnt + this->right->cnt;
    this->sum = this->left->sum + this->right->sum;
  }

  Node* get(int id) {
    if (this->cnt == 1) {
      return this;
    }
    if (id < this->left->cnt) {
      return this->left->get(id);
    } else {
      return this->right->get(id - this->left->cnt);
    }
  }
};

const int N = 100010;

int a[N];

Node* build(int left, int right) {
  if (left == right) {
    return new Node(a[left]);
  }
  int middle = (left + right) >> 1;
  Node* me = new Node(0);
  me->left = build(left, middle);
  me->right = build(middle + 1, right);
  me->left->parent = me;
  me->right->parent = me;
  me->cnt = me->left->cnt + me->right->cnt;
  me->sum = me->left->sum + me->right->sum;
  return me;
}
 
Node* root;

void update_parents(Node* x) {
  if (x == NULL) {
    return;
  }
  x->sum = x->value * 1LL * x->value;
  while (x != root) {
    x = x->parent;
    x->cnt = x->left->cnt + x->right->cnt;
    x->sum = x->left->sum + x->right->sum;
  }
}

void bankrupt(int id) {
  Node* me = root->get(id);
  Node* x = (id == 0) ? NULL : root->get(id - 1);
  Node* y = (id == root->cnt - 1) ? NULL : root->get(id + 1);
  if (x != NULL) {
    x->value += me->value / 2;
  } else {
    y->value += me->value / 2;
  }
  if (y != NULL) {
    y->value += me->value - me->value / 2;
  } else {
    x->value += me->value - me->value / 2;
  }
  update_parents(x);
  update_parents(y);
  me->value = me->sum = me->cnt = 0;
  update_parents(me);
  Node* brother = (me->parent->left == me) ? me->parent->right : me->parent->left;
  if (me->parent == root) {
    root = brother;
  } else {
    if (me->parent->parent->left == me->parent) {
      me->parent->parent->left = brother;
      brother->parent = me->parent->parent;
    } else {
      me->parent->parent->right = brother;
      brother->parent = me->parent->parent;
    }
  }
}

int main() {
  freopen("river.in", "r", stdin);
  freopen("river.out", "w", stdout);
  int n, subtask;
  scanf("%d%d", &n, &subtask);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  root = build(0, n - 1);
  printf("%lld\n", root->sum);
  int k;
  scanf("%d", &k);
  while (k--) {
    int e, v;
    scanf("%d %d", &e, &v);
    v--;
    if (e == 1) {
      bankrupt(v);
    } else {
      root->divide(v);
    }
    printf("%lld\n", root->sum);
  }
  return 0;
}
