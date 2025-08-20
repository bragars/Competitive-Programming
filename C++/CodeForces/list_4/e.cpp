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

int diff_and_square(ll x, ll y) {
  return (x - y) * (x - y);
}

vector<ll> operation(vector<ll> &A, vector<ll> B) {
  ll a=0, aux=0;
  int pos = 0;

  for (size_t i = 0; i < A.size(); i++)
  {
    if(a < abs(A[i]-B[i])) {
      a = abs(A[i]-B[i]);
      aux = A[i]-B[i];
      pos = i;
    }
  }
  // dbg(aux);

  if(aux>0) A[pos] -=1;
  else      A[pos] +=1;

  return A;
}

int32_t main() 
{sws;
  int n; cin >> n;
  int k1, k2; cin >> k1 >> k2;

  vector<ll> A(n, 0);
  vector<ll> B(n, 0);

  int ans = 0;
  for (size_t i = 0; i < n; i++) cin >> A[i];
  for (size_t i = 0; i < n; i++) cin >> B[i];

  for (size_t i = 0; i < k1; i++) A = operation(A, B);
  for (size_t i = 0; i < k2; i++) B = operation(B, A);

  for (size_t i = 0; i < n; i++) ans += diff_and_square(A[i], B[i]);

  cout << ans << endl;
  return 0;
}
