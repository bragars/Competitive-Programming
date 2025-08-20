#include <bits/stdc++.h>

using namespace std;
#define sws   \
  cin.tie(0); \
  cout.tie(0)->sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;

#define MP make_pair
#define sf(n) cin >> n;
#define sff(n, m) cin >> n >> m;
#define dbg(s, n) cout << s << ": " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;
#define pb push_back;

int main()
{sws;

  ll n; cin >> n;
  int b, m=0, t=1;
  int v[100] = {0};

  while (n)
  {
    b = n % 10;
    m = max(m, b);
    for (int i = 0; i < b; i++) {
      v[i] += t;
    }
    t *= 10;
    n /= 10;
  }

  cout << m << endl;
  for (int i = 0; i < m; i++) {
    cout << v[i] << " ";
  }
  return 0;
}
