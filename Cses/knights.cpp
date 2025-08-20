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

using namespace std;

int main()
{sws;
  int n; sf(n);

  for (size_t k = 1; k <= n; ++k) {
    ll a1 = k*k, a2 = a1*(a1-1)/2;
    if(k > 2)
      a2 -= 4*(k-1)*(k-2);

    cout << a2 << endl;
  }
  return 0;
}
