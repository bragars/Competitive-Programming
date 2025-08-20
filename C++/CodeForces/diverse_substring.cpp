#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool is_diverse(string &subst, unordered_map<char, int> &mp)
{
  for (const auto &character : subst)
  {
    if (mp.at(character) * 2 > subst.size())
      return false;
  }
  return true;
}

void solve(string &s, int n)
{
  string ans = "NO";
  string subst;

  vector<string> substrings;
  unordered_map<char, int> mp;

  for (int i = 0; i < n; i++)
  {
    char c = s[i];
    subst += c;
    mp[c]++;

    if (is_diverse(subst, mp))
    {
      cout << "subst: " << subst << endl;
      substrings.push_back(subst);
      ans = "YES";
    }
    else if(subst.size() >= 2)
    {
      mp.clear();
      subst = "";
    }
  }

  cout << ans << endl;
  if (!substrings.empty())
  {
    cout << substrings[0] << endl;
  }
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
