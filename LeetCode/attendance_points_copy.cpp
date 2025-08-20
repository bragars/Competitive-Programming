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

pair<int, int> find_ceil_value(pair<int, int> &ans, int threshold, const vector<int> &prefix_sum)
{
  int n = prefix_sum.size();
  int left = 1, right = n - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (mid + 1 < n && prefix_sum[mid] < threshold && prefix_sum[mid + 1] >= threshold)
    {
      return make_pair(prefix_sum[mid + 1], mid + 1);
    }
    else if (prefix_sum[mid] == threshold)
    {
      return make_pair(prefix_sum[mid], mid);
    }
    else if (prefix_sum[mid] < threshold)
    {
      left = mid + 1;
    }
    else if(prefix_sum[mid] > threshold)
    {
      right = mid - 1;
    }
  }

  return make_pair(0,0);
}

pair<int, int> solution(pair<int, int> &ans, int threshold, const vector<int> &prefix_sum)
{
  if (threshold == 1 || threshold <= prefix_sum[1])
  {
    return make_pair(prefix_sum[1], 1);
  }

  return find_ceil_value(ans, threshold, prefix_sum);
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
