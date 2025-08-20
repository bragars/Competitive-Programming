#include <iostream>
#include <string>
#include <vector>

std::string solution(std::string S)
{
  int s_len = S.size();
  std::vector<int> mark(s_len, 0);
  int p = 2;

  for (; p <= s_len; p++)
  {
    if (!(p & 1 == 0))
    {
      mark[p] = 1;
    }
  }
  for (int i = 2 * p; i <= s_len; i += p)
  {
  }

  return S;
}

int main()
{
  std::string S;
  std::cin >> S;
  S = solution(S);
  std::cout << S << std::endl;
  return 0;
}
