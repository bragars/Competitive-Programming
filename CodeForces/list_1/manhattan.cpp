#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

class Solution
{
public:
  int smaller_distance_and_value(int x, int y, int xi, int yi, int pi)
  {
    int distance = abs(x-xi) + abs(y-yi);
    int price = distance * 2 + pi;
    
    return price;
  }
};

int32_t main()
{sws;

  int n; int x; int y;
  cin >> n >> x >> y;

  Solution solution = Solution();
  pair<int, int> ans;

  int min_price = INT_MAX;

  for(int i = 0; i < n; i++)
  {
    int xi, yi, pi;
    cin >> xi >> yi >> pi;

    int total_price = solution.smaller_distance_and_value(x, y, xi, yi, pi);
    if(total_price < min_price) {
      min_price = total_price;
      ans = make_pair(min_price, i+1);
    }
  }

  cout << ans.first << " " << ans.second << endl;
  return 0;
}
