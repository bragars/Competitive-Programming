#include <bits/stdc++.h>

#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

#define sf(n) cin >> n;
#define sff(n,m) cin >> n >> m;
#define dbg(n) cout << "n: " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;

using namespace std;

int32_t main() 
{sws;
  int n, k1, k2;
  sf(n); sf(k1); sf(k2);

  vector<ll> A(n, 0); vector<ll> B(n, 0);
  for (size_t i = 0; i < n; i++)
    sf(A[i]);

  for (size_t i = 0; i < n; i++)
    sf(B[i]);

  int c = 0;
  priority_queue<ll> p;

  for (size_t i = 0; i < n; i++)
    p.push(abs(A[i]-B[i])), c+=abs(A[i]-B[i]);

  int k = k1+k2;
  ll ans=0;

  if (k == c)
  {
    print("0");
    return 0;
  } else if(k > c) {
    k-=c;
    if (k & 1) cout << "1" << endl;
    else cout << "0" << endl;

    return 0;
  }

  while(k) {
    ll aux; aux = p.top(); p.pop();

    if (aux > 0)
      k--; aux--; p.push(aux); c--;
    
    if(!c) break;
  }

  while(!p.empty()) {
    ll aux; aux = p.top(); p.pop();
    ans+=(aux*aux);
  }

  print(ans);
  return 0;
}
