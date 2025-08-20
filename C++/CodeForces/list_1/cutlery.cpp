#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

class Solution
{
public:
  int32_t max_people(int n, int g, int f, int c)
  {
    if (n < 2)
      return 0;

    int max = c;

    if (g > f)
      max += f;
    else
      max += g;
    
    if (max > n) 
      return n;

    return max;
  }
};

int32_t main()
{sws;
  
  Solution solution = Solution();
  int n, g, f, c; cin >> n >> g >> f >> c;

  int max_people_who_eat = 0;
  max_people_who_eat = solution.max_people(n, g, f, c);

  cout << max_people_who_eat << endl;
  return 0;
}
