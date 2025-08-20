#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  void removeDuplicates(vector<char> &chars)
  {
    auto set = std::unique(chars.begin(), chars.end());
    chars.erase(set, chars.end());
  }

  int compress(vector<char> &chars)
  {
    string S;
    int char_appears = 1;

    if (chars.size() == 1)
    {
      S += chars.at(0);
      return 1;
    }
    else if (chars.size() == 0)
      return 0;

    for (auto i = chars.begin(); i != chars.end(); i++)
    {
      char current = *i;
      auto next = std::next(i);

      if (next == chars.end() || current != *next)
      {
        S += current;

        if (char_appears != 1)
          if (char_appears > 9)
          {
            *(i-1) = to_string(char_appears)[0];
            *i = to_string(char_appears)[1];
          }
          else
          {
            *i = to_string(char_appears)[0];
          }
        char_appears = 0;
      }
      char_appears += 1;
    }

    removeDuplicates(chars);

    for (auto j = chars.begin(); j != chars.end(); j++)
    {
      cout << "*j: " << *j << endl;
    } 

    return chars.size();
  }
};

int main()
{
  Solution solution;
  vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
  // vector<char> chars = {'a'};
  // vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

  int compress_number = solution.compress(chars);
  cout << "compress_number: " << compress_number << endl;
  return 0;
}
