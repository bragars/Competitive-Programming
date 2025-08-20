#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

class Solution {
  public:
    int number_sum(string number) {
      int sum = 0;

      for(auto ch : number)
        sum += ch - '0';

      return sum;
    }
    int another_number_sum(int number) {
      int sum = 0;
  
      while (number > 0) {
        sum += number % 10;
        number /= 10;
      }
      return sum;
    }
};

int32_t main()
{sws;

  int n; cin >> n;
  int A, B; cin >> A >> B;
  int ans = 0;

  Solution solution = Solution();

  for (size_t i = 1; i <= n; i++)
  {
    int sum = solution.number_sum(to_string(i));

    if (sum >= A && sum <= B)
      ans += i;
  }
  
  cout << ans << endl;
  return 0;
}
