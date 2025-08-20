#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

class Solution
{
public:
  int min_coins(int n, int S)
  {
    vector<int> dp(S + 1, S + 1);
    dp[0] = 0;

    for (size_t i = 1; i <= S; i++)
      for (size_t moeda = 1; moeda <= n; moeda++)
        if(i >= moeda)
          dp[i] = min(dp[i], dp[i - moeda] + 1);

    return dp[S];
  }
};

int32_t main()
{
  sws;
  int n, S;
  cin >> n >> S;

  Solution solution = Solution();

  int result = solution.min_coins(n, S);
  cout << result << endl;

  return 0;
}
