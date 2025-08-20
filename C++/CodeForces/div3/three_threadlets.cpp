#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

class Solution
{
public:
  std::string possible_can_cut_threadlets(std::vector<int> &threadlets, int count) {
    int index = 0;

    while(not all_equal_lengths(threadlets) and count <= 3)
    {
      if(index >= threadlets.size())
        break;

      int cur = threadlets[index];
      if(cur == 1) {
        index++;
        continue;
      }

      std::cout << "cur: " << cur << std::endl;

      operation(threadlets, cur, index);
      count++;

      print(threadlets);
      std::cout << "count: " << count << std::endl;
    }
    return count > 3 ? "NO" : "YES";
  }

  void operation(std::vector<int> &threadlets, int cur, int index) {
    int l = 0, r = 0;

    threadlets.erase(threadlets.begin() + index);
    l = std::floor(cur/2.0);
    r = std::ceil(cur/2.0);

    threadlets.push_back(l);
    threadlets.push_back(r);
  }
  void print(std::vector<int> &threadlets) {
    for (size_t i = 0; i < threadlets.size(); i++) {
      std::cout << "threadlets[i]: " << threadlets[i] << std::endl;
    }
  }
  bool all_equal_lengths(std::vector<int> &threadlets) {
    for (size_t i = 1; i < threadlets.size(); i++)
      if(threadlets[i] != threadlets[i-1]) 
        return false;

    return true;
  }
  bool can_cut_threadlets(ll a, ll b, ll c, int count)
  {
    if (count > 3)
      return false;

    if(a == b and b == c)
      return true;

    if (a > 1) {
      std::cout << "a: " << a << std::endl;
      a /= 2;
      std::cout << "after a: " << a << std::endl;
    }

    if (b > 1) {
      b /= 2;
    }

    if (c > 1) {
      c /= 2;
    }

    count++;
    can_cut_threadlets(a, b, c, count);

    return false;
  }
};

int32_t main()
{
  int t; std::cin >> t;
  Solution solution = Solution();

  while(t--) {
    ll a, b, c; std::cin >> a >> b >> c;
    std::string ans;
    int count = 0;
    std::vector<int> threadlets;

    threadlets.push_back(a);
    threadlets.push_back(b);
    threadlets.push_back(c);

    ans = solution.possible_can_cut_threadlets(threadlets, count);
    std::cout << ans << std::endl;
  }

  return 0;
}
