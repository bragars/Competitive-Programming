#include <iostream>
#include <string>
using namespace std;

string higher_alphabetically(string A, string B)
{
  if (A.at(0) == B.at(0))
  {
    int min_size = min(A.size(), B.size());

    for(int i = 0; i < min_size; i++) {
      if (int(A.at(i)) > int(B.at(i))) {
        return A;
      }
      if (int(A.at(i)) < int(B.at(i))) {
        return B;
      }
    }

    if(A.size() > B.size()) {
      return A;
    }
    else {
      return B;
    }
  }
  else
  {
    char biggest_a = 'a', biggest_b = 'a';
    string result_name;

    for (int i = 0; i < A.size(); i++)
    {
      char a_char = A.at(i);

      if (int(biggest_a) < int(a_char))
        biggest_a = a_char;
    }

    for (int i = 0; i < B.size(); i++)
    {
      char b_char = B.at(i);

      if (int(biggest_b) < int(b_char))
        biggest_b = b_char;
    }

    int a_big_pos = A.find(biggest_a) + 1;
    int b_big_pos = B.find(biggest_b);
    result_name += biggest_a;

    for (int j = b_big_pos; j < B.size(); j++)
    {
      char b_char = B.at(j);

      if (int(a_big_pos) < int(b_char))
      {
        return result_name += B.substr(j, (B.size() - j));
      }
    }
  }

  return A;
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string S;
  string B;

  cin >> S;
  cin >> B;

  string higher;
  higher = higher_alphabetically(S, B);

  cout << higher << endl;
  return 0;
}
