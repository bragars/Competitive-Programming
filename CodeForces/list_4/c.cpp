#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);

int main()
{sws;
  // freopen("output.txt" , "w" , stdout);
  // freopen("input.txt" , "r" , stdin);

  int n, q, t;
  cin >> n >> q >> t;

  vector<ll> delta(n+5, 0);

  while(q--) {
    int l, r, x;
    cin >> l >> r >> x;

    delta[l] += x;
    delta[r+1] -= x;
  }

  for (int i = 1; i <= n; i++)
    delta[i] += delta[i-1];

  int ans=0;
  for (int i = 1; i <= n; i++) {
    if(delta[i] >= t) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
