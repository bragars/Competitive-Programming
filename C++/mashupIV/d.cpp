#include <bits/stdc++.h>

#define ll long long
#define sws   \
  cin.tie(0); \
  cout.tie(0)->sync_with_stdio(false);

using namespace std;

int main()
{sws;
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  while (t--)
  {
    int n; cin >> n;

    set<ll> v;
    for (int i = 0; i < n; i++) {
      ll e; cin >> e;
      if(!(e % 2))
        v.insert(-e);
    }

    int ans = -1;
    set<ll>:: iterator itr;
    for(itr = v.begin(); itr!=v.end(); itr++){
      ll m = *itr;
      ans++;
      if((m/2) % 2 == 0)
        v.insert(m/2);
    }

    ans++;
    cout << ans << endl;
  }

  return 0;
}
