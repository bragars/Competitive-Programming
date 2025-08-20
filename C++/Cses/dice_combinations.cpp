#include <bits/stdc++.h>

#define ll long long
#define ar array

using namespace std;

const int MAX = 1e6, M = 1e9 + 7;
int n;
ll dp[MAX + 1];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // number of ways to construct sum n
  // throwing a dice one or more times
  // each throw produces an between 1 and 6

  // if n = 3, there are 4 ways
  // 1 + 1 + 1 = 3, 1 + 2 = 3, 2 + 1 = 3

  // input has an integer n
  // print the number of ways modulo 1e9 + 7
  // 1 <= n <= 1e6
  cin >> n;
  dp[0] = 1;

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= min(6, i); ++j)
    {
      dp[i] = (dp[i] + dp[i-j] % M);
    }
    cout << dp[n];
  }

  return 0;
}
