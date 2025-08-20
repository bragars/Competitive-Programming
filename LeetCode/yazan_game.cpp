#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_valid(int x, int y, int n, int m)
{
  return x >= 0 && x < n && y >= 0 && y < m;
}

bool check(int i, int j, int n, int m, vector<vector<int>> &board)
{
  if (board[i][j] == 0)
  {
    board[i][j] == 1;
    return true;
  }

  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> board(n, vector<int>(m));
  int zeros = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 0)
        zeros++;
    }

  string result = "LOSE";

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      int flip_zeros = zeros;

      if (board[i][j] == 1)
      {
        for (int dir = 0; dir < 8; dir++)
        {
          int x = i + dx[dir];
          int y = j + dy[dir];

          if (is_valid(x, y, n, m))
          {
            if (check(x, y, n, m, board))
              flip_zeros--;
          }
        }
        if (flip_zeros == 0) 
          result = "WIN";
      }
    }

  cout << result << endl;

  return 0;
}
