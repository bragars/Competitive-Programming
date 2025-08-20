#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

using namespace std;

int main()
{
  int t; cin >> t;

  while(t--) {
    int n; cin >> n;
    string ans = "YES";

    vector<ll> a(n, 0);

    for (size_t i = 0; i < n; i++)
      cin >> a[i];

    if(n == 1) {
      cout << ans << endl;
      continue;
    }

    sort(a.begin(), a.end());

    for (size_t i = 0; i < a.size() - 1; i++)
      if(a[i+1] == a[i]) {
        ans = "NO";
        break;
      }

    cout << ans << endl;
  }

  return 0;
}
