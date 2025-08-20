#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 2*1e5;
int T[4 * MAX];
int A[MAX];

void build(int id, int il, int ir) {
  if (il == ir) {
    T[id] = A[il];
    return;
  }

  int im = (il + ir) / 2;
  build(2*id, il, im);
  build(2*id+1, im+1, ir);
  T[id] = min(T[2*id], T[2*id+1]);
}

int query(int l, int r, int id, int il, int ir) {
  if(il >= l && ir <= r) return T[id];
  if(ir < l || il > r) return INF;

  int im = (il + ir) / 2;
  int left  = query(l, r, 2*id, il, im);
  int right = query(l, r, 2*id+1, im+1, ir);
  return min(left, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q; cin >> n >> q;
  int minimum = 0;

  for (int i = 0; i < n; i++)
  {
    int v; cin >> v;
    A[i] = v;
  }

  build(1, 0, n-1);

  while(q--) {
    int l, r; cin >> l >> r;
    minimum = query(--l, --r, 1, 0, n-1);
    cout << minimum << endl;
  }

  return 0;
}
