#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  double findMaxAverage(vector<int> &nums, int k)
  {
    if (nums.size() < 2)
      return nums[0];

    if (k == 0 || nums.size() == 0)
      return 0;

    int start = 0;
    double window_sum = 0;
    double max_window_sum = 0;

    for (int i = 0; i < k; i++) {
      window_sum += nums[i];
    }

    max_window_sum = window_sum / k;

    for (int end = k; end < nums.size(); end++)
    {
      window_sum = (window_sum - nums[start++]) + nums[end];
      max_window_sum = max(max_window_sum, (window_sum / k));
    }

    return max_window_sum;
  }
};
