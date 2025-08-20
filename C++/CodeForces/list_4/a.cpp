#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<double, int> dpi;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<vector<int>> vivi;
typedef unsigned long long ull;

#define ll long long
#define sws   \
  cin.tie(0); \
  cout.tie(0)->sync_with_stdio(false);
#define MP make_pair
#define sf(n) cin >> n;
#define sff(n, m) cin >> n >> m;
#define dbg(s, n) cout << s << ": " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;
#define pb push_back;

int32_t main()
{sws;
  int n; cin >> n;
  int q; cin >> q;
  vector<ll> A(n+1, 0);
  int l=0, r=0;

  for (size_t i = 1; i <= n; i++) {
    int e; cin >> e;
    A[i] = e + A[i-1];
  }

  for (size_t i = 0; i < q; i++) {
    cin >> l; cin >> r;
    cout << A[r]-A[l-1] << endl;
  }

  return 0;
}
