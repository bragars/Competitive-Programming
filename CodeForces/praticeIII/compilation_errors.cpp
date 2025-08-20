#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false); cout.tie(0);

#define ll long long
#define pii pair<int, int>
#define sf(n) cin >> n;
#define sff(n,m) cin >> n >> m;
#define dbg(n) cout << "n: " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;
#define vi vector<int>;

using namespace std;

int32_t main()
{sws;
  int n; cin >> n;
  int idx = 3;

  vector<ll> errors;
  vector<ll> errors_b;
  vector<ll> errors_m(n, 1);

  while(idx--)
  {
    for (size_t i = 0; i < n; i++)
    {
      ll e; cin >> e;
      errors.push_back(e);
    }

    sort(errors.begin(), errors.end());

    if(!errors_b.empty()) {
      for (size_t i = 0; i < n; i++)
      {
        if(errors_b[i] != errors[i]) {
          errors_m[i] = 0;
          break;
        }
        if(i == n-1) errors_m[n] = 0;
      }

      int removed_idx = find(errors_m.begin(), errors_m.end(), 0) - errors_m.begin();
      // dbg(removed_idx);

      cout << errors_b[removed_idx] << endl;
      errors_m.erase(errors_m.begin() + removed_idx);
    }

    errors_b.assign(errors.begin(), errors.end());
    errors.clear();
    n--;
  }

  return 0;
}
