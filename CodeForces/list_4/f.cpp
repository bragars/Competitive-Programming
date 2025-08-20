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

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, m, c; sf(n); sf(m); sf(c);
  vector<int> A(n, 0); vector<int> B(m, 0);
  vector<int> delta(n+5, 0); vector<int> ans(n, 0);

  for (int i = 0; i < n; i++) sf(A[i]);
  for (int i = 0; i < m; i++) sf(B[i]);

  int counter = 0;
  for (int i = 0; i < (n-m)+1; i++)
  {
    counter = i;
    for (int j = 0; j < m; j++)
    {
      A[counter] = (A[counter]+B[j])%c;
      counter++;
    }
  }

  for (size_t i = 0; i < A.size(); i++) {
    cout << A[i];
    if(i!=(A.size()-1)) cout << " ";
  }
  
  return 0;
}
