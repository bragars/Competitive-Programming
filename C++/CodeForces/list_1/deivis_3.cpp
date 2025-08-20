#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

class Solution
{
public:
  // Output
  // Imprima em uma única linha a resposta do problema no seguinte formato: "axb", aonde a é o lado do retângulo, e b a sua altura, sem as aspas.
  void smaller_rectangle(vector<vector<int>> &binary_m)
  {
    if (binary_m.size() < 1 or binary_m[0].size() < 1) return;

    int left = binary_m[0].size(), right = -1;
    int bottom = binary_m.size(), top = -1;
    int width = 0, height = 0;

    for (int i = 0; i < binary_m.size(); i++)
      for (int j = 0; j < binary_m[0].size(); j++) {
        if (binary_m[i][j] == 1)
        {
          left = min(left, j);     right = max(right, j);
          bottom = min(bottom, i); top   = max(top, i);
        }
      }
    
    if(right >= 0 and top >= 0) {
      width  = (right - left) + 1;
      height = (top - bottom) + 1;
    }

    cout << width << "x" << height;
  }
};

int32_t main()
{sws;

  int n, m; cin >> n; cin >> m;

  Solution solution = Solution();
  vector<vector<int>> binary_m(n, vector<int>(m, 0));

  for (size_t i = 0; i < n; i++)
  {
    string v; cin >> v;
    for (size_t j = 0; j < m; j++)
      binary_m[i][j] = v[j] - '0';
  }

  solution.smaller_rectangle(binary_m);
  return 0;
}
