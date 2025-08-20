#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  int n, q; cin >> n >> q;
  vector<ll> delta(n+2, 0);

  for (size_t i = 0; i < q; i++)
  {
    ll l, r, x; cin >> l >> r >> x;
    delta[l] += x;
    delta[r+1] -= x;
  }

  for (size_t i = 1; i <= n; i++)
  {
    delta[i] += delta[i-1];
    cout << delta[i] << " ";
  }

  cout << endl;
  return 0;
}
