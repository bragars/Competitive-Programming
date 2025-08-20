#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

class Solution {
  public:
    int next_diff_digits_year(int x) {
      do {
        x++;
      } while(!check_diff_digits(to_string(x)));

      return x;
    }
    bool check_diff_digits(string year) {
      set<int> diff_year;
      for(char digit : year) {
        diff_year.insert(digit);
      }

      return diff_year.size() == year.size();
    }
};

int32_t main()
{sws;

  int x; cin >> x;
  int ans;
  Solution solution = Solution();

  ans = solution.next_diff_digits_year(x);
  cout << ans << endl;

  return 0;
}
