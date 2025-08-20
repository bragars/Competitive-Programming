#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int edit_distance(const string &A, const string &B)
  {
    int a_length = A.length();
    int b_length = B.length();

    vector<vector<int>> matrix(a_length + 1, vector<int>(b_length + 1, 0));

    for (int i = 0; i <= a_length; i++)
      for (int j = 0; j <= b_length; j++)
        operations(A, B, i, j, matrix);

    return matrix[a_length][b_length];
  }

  void operations(const string &A, const string &B, int i, int j, vector<vector<int>> &matrix)
  {
    int previous_row = matrix[i - 1][j];
    int previous_col = matrix[i][j - 1];

    if (i == 0) // min operation
      matrix[i][j] = j;

    else if (j == 0) // min operation
      matrix[i][j] = i;

    else if (A[i - 1] == B[j - 1])
      matrix[i][j] = matrix[i - 1][j - 1];

    else
      matrix[i][j] = 1 + min({previous_col,
                              previous_row,
                              matrix[i - 1][j - 1]});
  }

  bool requirements(string A, string B)
  {
    bool first_requirement = A.length() <= 2000;
    bool second_requirement = B.length() <= 2000;

    if (first_requirement && second_requirement)
      return true;
    else
      return false;
  }
};

int main()
{
  Solution solution = Solution();
  int n_operations;
  cin >> n_operations;

  while (n_operations != 0)
  {
    string A, B;
    cin >> A >> B;

    if (!solution.requirements(A, B))
      return 0;

    int min_operations = solution.edit_distance(A, B);
    cout << min_operations << endl;
    n_operations -= 1;
  }

  return 0;
}
