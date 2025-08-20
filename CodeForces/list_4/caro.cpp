#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<double, int> dpi;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vii;
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

int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n, q; sf(n); sf(q);
  vi vec(n, 0);
  vi vec_aux(n, 0);
  vi delta(n+2, 0);
  vi prefix_sum(n+2, 0);
  vii pairs;

  for (size_t i = 0; i < n; i++) sf(vec[i]);

  for (int i = 1; i <= q; i++) {
    int l, r; sf(l); sf(r);
    pairs.push_back(MP(l, r));

    delta[l] += 1;
    delta[r+1] -= 1;
  }

  for (size_t i = 1; i <= q; i++) delta[i] += delta[i-1];

  for (size_t i = 1; i <= n; i++) vec_aux[i-1] = delta[i];

  vector<int> indices(vec_aux.size());
  iota(indices.begin(), indices.end(), 0);

  sort(indices.begin(), indices.end(), [&](int a, int b)
            { return vec_aux[a] < vec_aux[b]; });

  vector<int> positionMapping(vec_aux.size());

  for (int i = 0; i < vec_aux.size(); ++i) positionMapping[indices[i]] = i;
  for (int i = 0; i < vec_aux.size(); ++i) vec_aux[i] = positionMapping[i];

  sort(vec.begin(), vec.end());
  for (size_t i = 1; i <= n; i++) {
    prefix_sum[i] += prefix_sum[i-1] + vec[vec_aux[i-1]];
  }

  int ans = 0;
  for (size_t i = 0; i < pairs.size(); i++)
  {
    ans += prefix_sum[pairs[i].second] - prefix_sum[(pairs[i].first)-1];
  }

  print(ans);
  return 0;
}
