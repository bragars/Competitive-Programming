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
#define dbg(n) cout << "n: " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;
#define pb push_back;

int main()
{
  sws;
  freopen("output.txt", "w", stdout);
  freopen("input.txt", "r", stdin);

  int n, m;
  cin >> n >> m;
  vector<int> s((n + 1), 0);
  vector<int> operations((n + 2), 0);
  vector<int> delta((n + 2), 0);

  int ans = 0;
  for (size_t i = 1; i <= n; i++)
    cin >> s[i];

  for (size_t i = 1; i <= m; i++)
  {
    int l, r, a; cin >> l >> r >> a;
    delta[l] += a; delta[r + 1] -= a;
    operations[l] += 1; operations[r + 1] -= 1;
  }

  int operation = 0;
  for (size_t i = 1; i <= s.size(); i++)
  {
    delta[i] += delta[i - 1];
    operation = s[i] - delta[i];

    if (s[i] > delta[i])
      s[i] = operation;
    else
      s[i] = 0;
  }

  for (size_t i = 1; i < s.size(); i++)
  {
    operations[i + 1] += operations[i];
    if (s[i] > 0)
      ans += operations[i];
  }

  cout << ans << endl;
  return 0;
}
