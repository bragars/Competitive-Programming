#include <bits/stdc++.h>

#define sws cin.tie(0) -> sync_with_stdio(false);
#define ll long long

using namespace std;

int main() {
  sws;

  string n; cin >> n;
  ll count = 1;
  ll ans = INT_MIN;

  for (size_t i = 1; i <= n.size(); i++)
  {
    if(n[i] == n[i-1])
      count++;
    else {
      ans = max(ans, count);
      count=1;
    }
  }

  if(count == n.size()) cout << n.size() << endl;
  else cout << ans << endl;

  return 0;
}
