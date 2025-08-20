#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;
int v[100];

int32_t main()
{sws;
  int n; cin >> n;
  int max = INT_MIN;
  int ans = 0;

  for (size_t i = 0; i < n; i++) {
    cin >> v[i];
    max = std::max(max, v[i]);
  }

  for (size_t i = 0; i < n; i++)
    ans += max - v[i];

  cout << ans << endl;
  return 0;
}
