first one
#include <bits/stdc++.h>

using namespace std;
#define sws cin.tie(0); cout.tie(0)->sync_with_stdio(false);

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> get_current_pos(string s)
{
  pair<int, int> a;
  int col = (s[0] - '0') - 49;
  const char r1[1] = {s[1]};
  int row = atoi(r1) - 1;

  return make_pair(col, row);
}

bool is_valid(int x, int y)
{
  return x <= 7 and x >= 0 and y <= 7 and y >= 0;
}

vector<pair<char, int>> get_possible_positions(pair<int, int> cur_pos)
{
  vector<pair<char, int>> v;
  pair<int, int> aux_pos = cur_pos;

  for (size_t i = 0; i < 8; i++)
  {
    while (is_valid((aux_pos.first + dx[0]), (aux_pos.second + dy[0])))
    {
      char e = (aux_pos.first + dx[0]) + '0' + 49;
      v.push_back({e, (aux_pos.second + dy[0] + 1)});
      aux_pos.first += 1;
    }
  }
  aux_pos = cur_pos;
  for (size_t i = 0; i < 8; i++)
  {
    while (is_valid((aux_pos.first + dx[1]), (aux_pos.second + dy[1])))
    {
      char e = (aux_pos.first + dx[1]) + '0' + 49;
      v.push_back({e, (aux_pos.second + dy[1] + 1)});
      aux_pos.second += 1;
    }
  }
  aux_pos = cur_pos;
  for (size_t i = 0; i < 8; i++)
  {
    while (is_valid((aux_pos.first + dx[2]), (aux_pos.second + dy[2])))
    {
      char e = (aux_pos.first + dx[2]) + '0' + 49;
      v.push_back({e, (aux_pos.second + dy[2] + 1)});
      aux_pos.first -= 1;
    }
  }
  aux_pos = cur_pos;
  for (size_t i = 0; i < 8; i++)
  {
    while (is_valid((aux_pos.first + dx[3]), (aux_pos.second + dy[3])))
    {
      char e = (aux_pos.first + dx[3]) + '0' + 49;
      v.push_back({e, (aux_pos.second + dy[3] + 1)});
      aux_pos.second -= 1;
    }
  }

  return v;
}

int main()
{
  int t;
  cin >> t;
  pair<int, int> pos;
  vector<pair<char, int>> v;
  while (t--)
  {
    string s;
    cin >> s; // where rook is positioned
    pos = get_current_pos(s);
    v = get_possible_positions(pos);
    for (size_t i = 0; i < v.size(); i++)
    {
      cout << v[i].first << v[i].second << endl;
    }
  }
  return 0;
}
