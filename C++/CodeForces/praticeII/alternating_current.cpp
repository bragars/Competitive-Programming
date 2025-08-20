#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

using namespace std;

int main()
{
  string wires;
  cin >> wires;

  int plus = 0, minus = 0;

  string ans = "NO";
  if (wires.size() == 1) {
    cout << ans << endl;
    return 0;
  }

  for (size_t i = 0; i < wires.size() - 1; i++)
  {
    if (wires[i+1] == '+' and )
  }

  if (minus == 0 || plus == 0)
    ans = "YES";

  cout << ans << endl;
  return 0;
}
