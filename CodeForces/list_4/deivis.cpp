#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  int n; cin >> n;
  int q; cin >> q;
  vector<ll> A(n+1, 0);
  int l=0, r=0;

  for (size_t i = 1; i <= n; i++) {
    int e; cin >> e;
    A[i] = e + A[i-1];
  }

  for (size_t i = 0; i < q; i++) {
    cin >> l; cin >> r;
    cout << A[r]-A[l-1] << endl;
  }

  // cout << "here" << endl;
  return 0;
}
