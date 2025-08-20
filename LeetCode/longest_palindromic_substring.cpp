class Solution
{
public:
  string longestPalindrome(string s)
  {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
      dp[i][i] = true;
      if (i < n - 1 && s[i] == s[i + 1])
        dp[i][i + 1] = true;
    }

    for (int i = n - 3; i >= 0; i--)
    {
      for (int j = i + 2; j < n; j++)
      {
        dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
      }
    }

    string longest = "";
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        if (dp[i][j] && j - i + 1 > longest.size())
          longest = s.substr(i, j - i + 1);
      }
    }

    return longest;
  }
};
