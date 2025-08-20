#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  ll n; cin >> n;
  vector<int> competitions(n, 0);

  for (size_t i = 0; i < n; i++) // n
  {
    cin >> competitions[i];
  }

  sort(competitions.begin(), competitions.end()); // log n

  int ans = 0;
  int problems_solved = 1;

  for (size_t i = 0; i < n; i++) // n log
  {
    if(competitions[i] >= problems_solved) {
      ans++;
      problems_solved++;
    }
  }

  cout << ans << endl;
  return 0;
}
