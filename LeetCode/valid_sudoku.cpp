class Solution
{
public:
  bool validator(int ar_aux[], char cell, int steps)
  {
    int cell_i = cell - '0';

    if (ar_aux[steps + cell_i])
      return false;

    ar_aux[steps + cell_i] = 1;
    return true;
  }

  void sub_boxes_validator(int x, int ar_aux[], char cell, bool &result)
  {
    if (x >= 0 && x <= 2)
      result = validator(ar_aux, cell, 0);
    else if (x >= 3 && x <= 5)
      result = validator(ar_aux, cell, 10);
    else
      result = validator(ar_aux, cell, 20);
  }

  bool isValidSudoku(vector<vector<char>> &board)
  {
    bool result = true;
    int n_rows = board.size();
    int n_columns = board[0].size();

    for (int i = 0; i < n_rows; i++)
    {
      int ar_aux[20] = {0};

      for (int j = 0; j < n_columns; j++)
      {
        if (isdigit(board[i][j]))
          result = validator(ar_aux, board[i][j], 0);

        if (result == false)
          return result;

        if (isdigit(board[j][i]))
          result = validator(ar_aux, board[j][i], 10);

        if (result == false)
          return result;
      }
    }

    int l = 0, f = 1;

    while (((n_rows / 3) * f) < 10)
    {
      int ar_aux[30] = {0};

      for (int k = (3 * l); k < ((n_rows / 3) * f); k++)
      {
        for (int x = 0; x < n_columns; x++)
        {
          if (isdigit(board[k][x]))
            sub_boxes_validator(x, ar_aux, board[k][x], result);

          if (result == false)
            return result;
        }
      }

      l++;
      f++;
    }

    return result;
  }
};
