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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int q; cin >> q;

  while(q--) {
    int n, k; cin >> n >> k;
    int m = 0;
    string s;
    stack<int> pos;

    int counter=0;
    for (int i = 0; i < n; i++)
    {
      char c; cin >> c; s+=c;
      if (c == 'B') counter++;
      else set.push(i);
    }

    if(counter > k) {
      int nmbr = counter - k;
      int idx = 1;
      char c = 'A';
      vector<pair<int, char> ops;
      while(nmbr > k) {
        if(s[i] != c) idx++;
        else {
          ops.push_back(MP(c, idx));
          nmbr+=idx;
          idx++;
        }

        if(idx == nmbr) {
          ops.push_back(MP(c, idx));
          break;
        } 
      }
    } else if(nmbr < k){
      int nmbr = k - counter;
      int idx = 1;
      char c = 'B';
      vector<pair<int, char> ops;

      while(nmbr > k) {
        if(s[i] != c) idx++;
        else {
          ops.push_back(MP(c, idx));
          nmbr+=idx;
          idx++;
        }

        if(idx == nmbr) {
          ops.push_back(MP(c, idx));
          break;
        }
      }
    }
    else {
      print(0); continue;
    }
  }
  return 0;
}
