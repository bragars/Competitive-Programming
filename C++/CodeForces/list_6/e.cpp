#include <bits/stdc++.h>

using namespace std;
#define sws   \
  cin.tie(0); \
  cout.tie(0)->sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;

#define MP make_pair
#define sf(n) cin >> n;
#define sff(n, m) cin >> n >> m;
#define dbg(s, n) cout << s << ": " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;
#define pb push_back;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, k;
vector<vector<char>> vec;
vector<vector<int>> visited;

bool is_valid(int x, int y)
{
  return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y, int &k, int h)
{
  if (k <= 0 || visited[x][y] || vec[x][y] == '#')
    return;

  visited[x][y] = 1;
  int adjs = 0;

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (is_valid(nx, ny) && vec[nx][ny] == '.')
      adjs++;
  }

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (is_valid(nx, ny) && !visited[nx][ny] && vec[nx][ny] == '.')
      dfs(nx, ny, k, h);
  }

  // if (adjs <= h)
  // {
  //   vec[x][y] = 'X';
  //   k--;
  // }
}

int main()
{
  sws;

  freopen("input.txt", "r", stdin);
  cin >> n >> m >> k;

  vec.resize(n, vector<char>(m));
  visited.resize(n, vector<int>(m, 0));

  // input
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> vec[i][j];

  // logic
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
      if (!visited[i][j] && vec[i][j] == '.')
        dfs(i, j, k, 1);
    }

  // output
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cout << vec[i][j];
    cout << endl;
  }

  return 0;
}
