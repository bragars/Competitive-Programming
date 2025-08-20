#include <bits/stdc++.h>

#define sws cin.tie(0) -> sync_with_stdio(false)
#define ll long long

using namespace std;

// int main() {
//   ll n; cin >> n;
//   ll last_element = 0;
//   ll ans = 0;

//   while(n--) {
//     ll a; cin >> a;

//     while(a < last_element) {
//       ans++;
//       a++;
//     }

//     last_element = a;
//   }

//   cout << ans << endl;
//   return 0;
// }

int main() {
  ll n; cin >> n;
  ll mx = 0;
  ll ans = 0;

  for (size_t i = 0; i < n; i++)
  {
    ll x; cin >> x;
    mx = max(x, mx);
    ans += mx-x;
  }

  cout << ans << endl;
  return 0;
}
