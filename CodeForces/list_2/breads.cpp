#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  ll n; cin >> n;
  int m; cin >> m;
  m = min(50, m);

  vector<ll> ideal_temperatures(n, 0);

  for (ll i = 0; i < n; i++)
    cin >> ideal_temperatures[i];

  

  return 0;
}
