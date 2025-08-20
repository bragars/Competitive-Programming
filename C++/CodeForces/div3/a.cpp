#include <bits/stdc++.h>

using namespace std;
#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);

int main()
{sws;

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t; cin >> t;

  while(t--) {
    int n; cin >> n;
    string ans = "Second";

    if((n+1) % 3 == 0 or (n-1) % 3 == 0) cout << "First" << endl;
    else cout << "Second" << endl;
  }

  return 0;
}
