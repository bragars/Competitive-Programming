#include <bits/stdc++.h>

#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);
#define ll long long
using namespace std;

int main() {
  ll n; cin >> n;
  double ans = pow(n, 1.0 / 3);

  int b = ceil(ans);
  int a = floor(ans);

  if(abs(b - ans) < 1e-9 || abs(a - ans) < 1e-9) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
  }
  return 0;
}
