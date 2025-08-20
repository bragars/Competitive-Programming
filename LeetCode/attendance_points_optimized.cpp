#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#define ll long long

using namespace std;

void optimizeIO()
{
  cin.tie(0)->sync_with_stdio(false);
}

pair<int, int> solution(pair<int, int> &ans, int threshold, const vector<int> &prefix_sum)
{
  if (threshold == 0)
  {
    return make_pair(0, 0);
  }
  else if (threshold <= prefix_sum[1])
  {
    return make_pair(prefix_sum[1], 1);
  }
  else if (threshold > prefix_sum[prefix_sum.size() - 1])
  {
    return make_pair(prefix_sum[prefix_sum.size() - 1], prefix_sum.size());
  }

  vector<int>::const_iterator it = lower_bound(prefix_sum.begin() + 1, prefix_sum.end(), threshold);
  int pos = it - prefix_sum.begin();

  return make_pair(*it, pos);
}

int main()
{
  optimizeIO();

  ll n;
  cin >> n;

  vector<int> prefix_sum(n + 1, 0);
  for (size_t i = 0; i < n; ++i)
  {
    int point;
    cin >> point;
    prefix_sum[i + 1] = prefix_sum[i] + point;
  }

  ll m;
  cin >> m;

  pair<int, int> ans(0, 0);

  for (size_t k = 0; k < m; ++k)
  {
    int threshold;
    cin >> threshold;
    ans = solution(ans, threshold, prefix_sum);
    cout << ans.first << " " << ans.second << endl;
  }

  return 0;
}
