#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long getMinimumCost(vector<int> arr)
{
  int n = arr.size();

  if (n < 2 || n > 10000)
  {
    return 0;
  }

  long cost = 0;
  int min_cost = INT_MAX, replace_value = 0, index = 0;

  for (auto i = arr.begin(); i != arr.end(); i++)
  {
    if (std::next(i) != arr.end())
    {
      auto next = std::next(i);
      int k = sqrt(std::abs(*i - *next));

      for (int j = 0; j <= 10; j++)
      {
        int a = sqrt(std::abs(*i - j));
        int b = sqrt(std::abs(*next - j));
        int total_cost = a + b;

        if (total_cost < min_cost)
        {
          min_cost = total_cost;
          replace_value = j;
          index = std::distance(arr.begin(), i);
        }
      }
    }
  }

  arr.insert((arr.begin() + (index + 1)), replace_value);

  for (auto i = arr.begin(); i != arr.end(); i++)
  {
    if (std::next(i) != arr.end())
    {
      auto next = std::next(i);
      int k = sqrt(std::abs(*i - *next));

      cost += k;
    }
  }

  return cost;
}

int main()
{
  string arr_count_temp;
  getline(cin, arr_count_temp);

  int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

  vector<int> arr(arr_count);

  for (int i = 0; i < arr_count; i++)
  {
    string arr_item_temp;
    getline(cin, arr_item_temp);

    int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

    arr[i] = arr_item;
  }

  long result = getMinimumCost(arr);
  cout << result << endl;

  return 0;
}

string ltrim(const string &str)
{
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str)
{
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}
