#include <bits/stdc++.h>

typedef long long ll;
// typedef pair<int, int> pi;
// typedef pair<double, int> dpi;
// typedef pair<long long, long long> pll;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef vector<pi> vpi;
// typedef vector<vector<int>> vivi;
typedef unsigned long long ull;

#define sws cin.tie(0)->sync_with_stdio(false);
#define MP make_pair
#define sf(n) cin >> n;
#define sff(n,m) cin >> n >> m;
#define dbg(n) cout << "n: " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;
#define pb push_back;

const long long int N = 1e15;

using namespace std;

int main()
{
  sws;

  freopen("output.txt" , "w" , stdout);
  freopen("input.txt" , "r" , stdin);

  int t; cin >> t;
  while (t--)
  {
    ll x; cin >> x;
    ll ans = 0;

    for (int i = 0; i < 33; i++)
      if ((x & (1LL << i)))
      {
        ans += (1LL << i);
        break;
      }

    if ((x ^ ans) > 0)
    {
      cout << ans << '\n';
      continue;
    }

    for (int i = 0; i < 33; i++)
      if ((x & (1LL << i)) == 0)
      {
        ans += (1LL << i);
        break;
      }
    cout << ans << '\n';
  }
}