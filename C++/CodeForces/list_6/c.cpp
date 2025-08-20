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

  int n, m;
  cin >> n >> m;

  // input
  vector<vector<char>> v(n, vector<char>(m, '.'));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  // output
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '.')
        cout << ((i + j) % 2 ? 'B' : 'W');
      else
        cout << '-';
    }
      cout << endl;
  }

  return 0;
}
