#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define sws   \
  cin.tie(0); \
  cout.tie(0)->sync_with_stdio(false);
#define MP make_pair
#define sf(n) cin >> n;
#define sff(n, m) cin >> n >> m;
#define dbg(s, n) cout << s << ": " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;
#define pb push_back;

int n, m;
int dx[4] = {1, 0, -1, 0 };
int dy[4] = {0, 1,  0, -1};
vector<pair<int, pair<int, int>>> adjs;

int is_valid(int x, int y) {
  if(x >= 0 and x < n and y >=0 and y < m)
    return 1;
  return 0;
}

int check_adj(vector<vector<char>> &v, int i, int j) {
  int adjs_nmbr=0;
  for (int k = 0; k < 4; k++)
  {
    int x = i + dx[k];
    int y = j + dy[k];
    if(is_valid(x, y) and v[x][y] == '.') {
      adjs_nmbr++;
    }
  }
  return adjs_nmbr;
}

void check_and_assign(vector<vector<char>> &v, int &k, int h) {
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < m; j++) 
    {
      if(v[i][j]=='#')
        continue;

      int adjs_nmbr = check_adj(v, i, j);
      if(adjs_nmbr <= h) {
        if(k == 0)
          return;
        v[i][j]='X'; k--;
      } else {
        adjs.push_back(MP(adjs_nmbr, MP(i,j)));
      }
    }
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  // input
  int k; cin >> n >> m >> k;

  vector<vector<char>> v(n, vector<char>(m, '.'));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> v[i][j];

  // logic
  check_and_assign(v, k, 1);
  sort(adjs.begin(), adjs.end());

  int idx=0;
  while(k>0) {
    int x = adjs[idx].second.first;
    int y = adjs[idx].second.second;
    v[x][y] = 'X';
    idx++; k--;
  }

  // output
  for (int i = 0; i < n; i++) 
  {
    for (int j = 0; j < m; j++)
      cout << v[i][j];
    cout << endl;  
  }

  return 0;
}
