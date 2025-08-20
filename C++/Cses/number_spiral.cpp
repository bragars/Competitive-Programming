#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<double, int> dpi;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef unsigned long long ull;

#define sws cin.tie(0)->sync_with_stdio(false);
#define MP make_pair
#define sf(n) cin >> n;
#define sff(n,m) cin >> n >> m;
#define dbg(n) cout << "n: " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;
#define pb push_back

using namespace std;

int main()
{sws;

  // freopen("output.txt" , "w" , stdout);
  // freopen("input.txt" , "r" , stdin);

  int t; cin >> t;

  while(t--) {
    ll y, x; cin >> y >> x;
    ll z = max(y, x);
    ll z2 = (z-1)*(z-1), ans;

    if(not z & 1) {
      if(y == z){
        ans = z2 + x;
      } else {
        ans = z2 + 2*z - y;
      }
    } else {
        if(x == z) {
          ans = z2 + y;
        } else {
          ans= z2 + 2*z - x;
        }
    }

    cout << ans << '\n';
  }

  return 0;
}
