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
{
  // freopen("output.txt", "w", stdout);
  // freopen("input.txt", "r", stdin);

  int n, t;
  cin >> n >> t;
  vector<int> v(n + 1, 0);
  for (size_t i = 1; i < n; i++)
    cin >> v[i];

  string ans = "NO";

  int current = 1;
  while (current < t)
  {
    current += v[current];
    if (current == t)
    {
      ans = "YES";
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
