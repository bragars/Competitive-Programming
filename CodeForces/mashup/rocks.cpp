#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  int n; cin >> n;
  int ans = 0;
  stack<char> rocks;

  for (size_t i = 0; i < n; i++)
  {
    char rock;
    cin >> rock;

    if (rocks.empty())
      rocks.push(rock);
    else
    {
      if (rocks.top() == rock)
        ans++;
      rocks.push(rock);
    }
  }

  std::cout << ans << endl;
  return 0;
}
