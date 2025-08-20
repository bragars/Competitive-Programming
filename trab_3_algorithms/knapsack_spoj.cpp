#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
  int knapsack(int capacity, const vector<pair<int, int>> &itemsList, int items)
  {
    vector<vector<int>> bag(items + 1, vector<int>(capacity + 1, 0)); // multidimensional vector

    for (int i = 1; i <= items; i++)
      for (int j = 1; j <= capacity; j++)
        operations(bag, i, j, itemsList);

    return bag[items][capacity]; // last position == biggest
  }

  void operations(vector<vector<int>> &bag, int i, int j, const vector<pair<int, int>> &itemsList)
  {
    int previous = bag[i - 1][j];
    int weight = itemsList[i].first;
    int value = itemsList[i].second;

    if ((j - itemsList[i].first) >= 0)
      bag[i][j] = max(previous,
                      bag[i - 1][j - weight] + value);
    else
      bag[i][j] = previous;
  }

  bool requirements(int capacity, int items)
  {
    bool first_requirement = capacity >= 1 && capacity <= 2000;
    bool second_requirement = items >= 1 && items <= 2000;

    if (first_requirement && second_requirement)
      return true;
    else
      return false;
  }
};

int main()
{
  Solution solution = Solution();
  int capacity, items;
  cin >> capacity >> items;

  if (!solution.requirements(capacity, items))
    return 0;

  vector<pair<int, int>> itemsList(1, pair<int, int>(0, 0));
  for (int i = 0; i < items; i++)
  {
    int weight, value;
    cin >> weight >> value;
    itemsList.push_back(make_pair(weight, value)); // first = weight, second = value
  }

  int maxTotalValue = solution.knapsack(capacity, itemsList, items);
  cout << maxTotalValue << endl;

  return 0;
}
