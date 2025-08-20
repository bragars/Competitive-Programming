#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int minCoins(int n, int S) {
    vector<int> dp(S + 1, S + 1);
    dp[0] = 0;

    for (int i = 1; i <= S; i++) {
      for (int moeda = 1; moeda <= n; moeda++) {
        if (i >= moeda) {
          dp[i] = min(dp[i], dp[i - moeda] + 1);
        }
      }
    }

    for (size_t i = 0; i < dp.size(); i++)
    {
      cout << "dp[i]: " << dp[i] << endl;
    }
    return dp[S];
}

int32_t main()
{sws;
  int n, S;
  cin >> n >> S;

  int result = minCoins(n, S);
  cout << result << endl;

  return 0;
}
