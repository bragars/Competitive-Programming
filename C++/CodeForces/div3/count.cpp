#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

class Solution
{
public:
  int dont_try_to_count(std::string x, std::string s)
  {
    int count = 0;

    while(not is_substring(x, s) and count <= 8) {
      x += x;
      count++;
    }

    return count < 8 ? count : -1;
  }

  bool is_substring(std::string x, std::string s)
  {
    if (s.size() > x.size())
      return false;

    for (size_t i = 0; i <= x.size() - s.size(); i++)
    {
      bool match = true;
      for (size_t j = 0; j < s.size(); j++)
      {
        if (x[i + j] != s[j])
        {
          match = false;
          break;
        }
      }
      if (match)
        return true;
    }

    return false;
  }
};

int32_t main()
{
  int t;
  std::cin >> t;
  Solution solution = Solution();

  while (t--)
  {
    int n, m;      std::cin >> n >> m;
    std::string x; std::cin >> x;
    std::string s; std::cin >> s;

    int ans = solution.dont_try_to_count(x, s);
    std::cout << ans << std::endl;
  }

  return 0;
}
