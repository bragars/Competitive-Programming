#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string &s, int n)
{
  string ans = "NO";
  string subst = "";

  for (auto it = s.begin(); it != s.end(); it++)
  {
    if (it + 1 != s.end() && *it != *(it + 1))
    {
      ans = "YES";
      subst = string(1, *it) + string(1, *(it + 1));
      break;
    }
  }

  cout << ans << endl;
  if (!subst.empty())
    cout << subst << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  string s;
  cin >> s;

  solve(s, n);

  return 0;
}
