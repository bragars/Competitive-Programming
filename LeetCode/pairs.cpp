#include <iostream>
#include <vector>
#include <unordered_set>

int pairs(int k, std::vector<int> arr)
{
  int n = arr.size();

  if (n < 2 || n > 100000 || k < 0 || k > 1000000000)
    return 0;

  int pairs = 0;
  std::unordered_set<int> visited;

  for (const auto &num : arr)
  {
    if (visited.find(num - k) != visited.end())
      pairs++;
    if (visited.find(num + k) != visited.end())
      pairs++;

    visited.insert(num);
  }

  return pairs;
}

int main()
{
  int k = 2;
  std::vector<int> arr = { 1, 5, 3, 4, 2 };

  int result = pairs(k, arr);
  std::cout << "Number of pairs: " << result << std::endl;

  return 0;
}
