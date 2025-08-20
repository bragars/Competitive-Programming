#include <bits/stdc++.h>

#define sws cin.tie(0) -> sync_with_stdio(false);
#define ll long long

using namespace std;

int32_t main() {
  ll n; cin >> n;
  cout << n << " ";

  while(n != 1) {
    if(n & 1 == 0) {
      n = n * 3 + 1;
    } else {
      n = n / 2;
    }

    cout << n << " ";
  }
  return 0;
}
