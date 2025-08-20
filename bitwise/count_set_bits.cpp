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

int count(int x) {
  int ans = 0;
  int count = 0;

  while(x > 0)
    count+=(x&1), x>>=1;

  return count;
}

int main()
{sws;
  int n; n=5;
  cout << count(n) << endl;
  return 0;
}
