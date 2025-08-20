#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int search_equal_letter(const std::string &A, const std::string &B)
{
  for (size_t i = 0; i < A.length(); i++)
  {
    if (A.at(i) == B.at(i))
      return i;
  }
  return -1;
}

int editDistance(string &A, string &B)
{
  while (A.compare(B) != 0)
  {
    if (A.length() < B.length())
    {
      int pos = search_equal_letter(A, B);

      if (pos != 1)
        A.erase(pos, 1);
      else
        A.erase((A.length() - 1), 1);
    }
  }
  return 0;
}

int main(int argc, char **argv)
{
  int test_case;
  cin >> test_case;

  while (test_case--)
  {
    string A, B;
    cin >> A >> B;

    int minOperations = editDistance(A, B);
    cout << minOperations << endl;
  }

  return 0;
}
