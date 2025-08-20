#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  int n; cin >> n;
  ll m; cin >> m;
  map<ll, int> mp;

  ll t = 0;
  ll coin = 0;

  for (size_t i = 0; i < m; i++)
  {
    ll c; cin >> c;
    mp[c]++;
  }

  for (size_t i = 1; i <= n; i++)
  {
    ll cp = mp[i]*i;
    if(cp >= t) {
      coin = i;
      t = cp;
    }
  }
  cout << t << " " << coin << endl;
  return 0;
}
