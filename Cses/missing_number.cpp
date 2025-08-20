#include <bits/stdc++.h>

#define sws cin.tie(0) -> sync_with_stdio(false);
#define ll long long

using namespace std;

// int32_t main() {
//   ll n; cin >> n;
//   vector<ll> numbers(n);

//   for (size_t i = 1; i < n; i++)
//     cin >> numbers[i];

//   sort(numbers.begin(), numbers.end());

//   for (size_t i = 1; i <= n; i++) {
//     if (i == n) cout << i << endl;

//     else if(i != numbers[i]) {
//       cout << i << endl;
//       break;
//     }
//   }

//   return 0;
// }

int32_t main() {
  ll n; cin >> n;
  ll s = 0;

  for (size_t i = 0; i < n; i++)
  {
    int a; cin >> a;
    s+=a;
  }
  cout << n*(n+1)/2-s;
  return 0;
}
