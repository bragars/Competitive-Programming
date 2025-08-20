#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false); cout.tie(0);

#define ll long long
#define pii pair<int, int>

using namespace std;

int32_t main()
{sws;
  ll n; cin >> n;
  ll t; cin >> t;
  ll c; cin >> c;
  int ans = 0;

  int start = 0, end = 0;

  if(n == 1) {
    ll crime; cin >> crime;
    if(crime <= t)
      ans++;

    cout << ans << endl;
    return 0;
  }

  for (size_t i = 0; i < n; i++)
  {
    ll crime; cin >> crime;
    if(crime <= t) {
      end = i;
    } else {
      start = i+1;
      end = i+1;
    }
    if((end-start)+1 == c) {
      ans++; start++;
    }
  }

  cout << ans << endl;
  return 0;
}
