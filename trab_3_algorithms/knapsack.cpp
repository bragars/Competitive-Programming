#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int capacity, const vector<int> &sizes, const vector<int> &values, int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= capacity; j++)
    {
      if (sizes[i - 1] <= j)
      {
        cout << "j - sizes[i - 1]" << j - sizes[i - 1] << endl;
        dp[i][j] = max(values[i - 1] + dp[i - 1][j - sizes[i - 1]], dp[i - 1][j]);
      }
      else
      {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[n][capacity];
}

int main()
{
  int capacity, n;
  cin >> capacity >> n;

  vector<int> sizes(n), values(n);
  for (int i = 0; i < n; i++)
  {
    cin >> sizes[i] >> values[i];
  }

  int maxTotalValue = knapsack(capacity, sizes, values, n);
  cout << maxTotalValue << endl;

  return 0;
}
