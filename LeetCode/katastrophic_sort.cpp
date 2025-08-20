#include <iostream>
#include <string>
using namespace std;

char solution(string &S, string &B)
{
  int position = 0;
  int s_size = S.size();
  int b_size = B.size();

  while((S[position] - '0') > 9 || (S[position] - '0') < 0)
  {
    if (S[position] > B[position])
    {
      return '>';
    }
    if (S[position] < B[position])
    {
      return '<';
    }
    position++;
  }

  if((s_size - position) > (b_size - position)) return '>';
  if((s_size - position) < (b_size - position)) return '<';

  while(position < s_size)
  {
    if (S[position] > B[position])
    {
      return '>';
    }
    if (S[position] < B[position])
    {
      return '<';
    }
    position++;
  }

  return '=';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string S;
  string B;

  cin >> S;
  cin >> B;

  cout << solution(S, B) << endl;
  return 0;
}
