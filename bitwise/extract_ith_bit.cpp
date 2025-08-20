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

int extract_2nd_b(int x) {
  int ith = 0;
  ith = (x >> 2) & 1;

  return ith;
}

int main()
{sws;
  int n; n=13;
  cout << extract_2nd_b(n) << endl;
  return 0;
}
