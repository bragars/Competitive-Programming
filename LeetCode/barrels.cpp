#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solution(vector<int> &water_amounts, int &k, int n)
{
  sort(water_amounts.rbegin(), water_amounts.rend());

  ll ans = 0;

  for (int i = 0; i <= k; i++)
    ans += water_amounts[i];

  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;

  while (t--)
  {
    int n = 1, k = 1;
    cin >> n >> k;
    vector<int> water_amounts(n, 0);

    for (size_t i = 0; i < n; i++)
      cin >> water_amounts[i];

    solution(water_amounts, k, n);
  }

  return 0;
}
