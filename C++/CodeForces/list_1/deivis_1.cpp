#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

const int max_size = 10;
string v[max_size];

class Solution
{
public:
  void matr(int n)
  {
    vector<int> values(max_size, n - 1);

    for (size_t i = 0; i < n; i++)
    {
      string current_string = v[i];
      for (size_t j = 0; j < n; j++)
      {
        if (i != j)
        {
          compare(current_string, v[j], n - 1, i, values);
        }
      }
    }

    print_values(n, values);
  }

  void compare(string current_string, string next_string, int n, int pos, vector<int> &values)
  {
    int size = std::min(current_string.size(), next_string.size());

    for (size_t i = 0; i < size; i++)
    {
      if (int(current_string[i]) < int(next_string[i]))
      {
        values[pos]--;
        return;
      }
      else if (int(current_string[i]) > int(next_string[i]))
      {
        return;
      }
    }
  }

  void print_values(int n, vector<int> &values)
  {
    for (int i = 0; i < n; i++)
    {
      cout << values[i] << endl;
    }
  }
};

int32_t main()
{
  sws;
  int n;
  cin >> n;
  Solution solution = Solution();

  for (size_t i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  solution.matr(n);

  return 0;
}
