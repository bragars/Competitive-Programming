#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ll n;
  cin >> n;

  ll ans = -1;
  for (ll i = 0; i * i * i <= n; i++) {
    if (i * i * i == n) {
      ans = i;
      break;
    }
  }

  if (ans != -1) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
