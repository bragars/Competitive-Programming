#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false); cout.tie(0);

#define ll long long
#define pii pair<int, int>

using namespace std;

int32_t main()
{sws;
  int q; cin >> q;
  int exists = 0;
  map<ll, ll> mp;

  while(q--) {
    int t; cin >> t;
    ll m;  cin >> m;

    if(t == 1) {
      mp[m]++;
    } else {
      exists = mp.count(m);
      exists ? cout << "Sim" : cout << "Nao";
      cout << endl; 
    }
  }

  return 0;
}