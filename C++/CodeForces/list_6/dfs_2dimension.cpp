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

vector<vector<bool>> visited;

bool is_valid(int x, int y, int n, int m)
{
  return (x >= 0 && x < n && y >= 0 && y < m);
}

int dfs(vector<vector<char>> &maze, int x, int y, int n, int m)
{
  visited[x][y] = true;
  int size = 1;

  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (is_valid(nx, ny, n, m) && maze[nx][ny] == '.' && !visited[nx][ny])
    {
      size += dfs(maze, nx, ny, n, m);
    }
  }

  return size;
}

int main()
{
  freopen("input.txt", "r", stdin);
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<char>> maze(n, vector<char>(m));
  visited.assign(n, vector<bool>(m, false));

  // Read maze
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> maze[i][j];

  vector<pair<int, pair<int, int>>> components; // {size, {start_x, start_y}}

  // Find connected components
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (maze[i][j] == '.' && !visited[i][j])
      {
        int size = dfs(maze, i, j, n, m);
        components.push_back({size, {i, j}});
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cout << "components[i][j]: " << components[i].first << endl;
    cout << endl;
  }

  // Sort components based on size in ascending order
  sort(components.begin(), components.end());

  // Iterate through components
  for (auto &component : components)
  {
    int size = component.first;
    int x = component.second.first;
    int y = component.second.second;

    if (size > k)
    {
      // Sort cells in the connected component based on some order (e.g., row-major)
      vector<pair<int, int>> cells;
      for (int i = x; i < x + size; i++)
      {
        for (int j = y; j < y + size; j++)
        {
          cells.push_back({i, j});
        }
      }

      sort(cells.begin(), cells.end());

      // Mark the smallest (size - k) cells as walls
      for (int i = 0; i < size - k; i++)
      {
        maze[cells[i].first][cells[i].second] = 'X';
      }

      k = 0; // No more walls to add
    }
  }

  // Print the final maze
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      cout << maze[i][j];
    cout << endl;
  }

  return 0;
}
