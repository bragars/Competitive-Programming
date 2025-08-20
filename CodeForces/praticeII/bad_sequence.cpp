#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

using namespace std;

string is_brackets_valid(string brackets, int n) {
  int swap_times = 0;
  stack<char> s;

  for (size_t i = 0; i < brackets.size(); i++)
  {
    char e = brackets[i];
    if (!s.empty()) {
      if (s.top() == '(' and e == ')') {
        s.pop();
        continue;
      }
    }
    s.push(e);
  }

  if(s.empty() || s.size() == 2)
    return "YES";

  return "NO";
}

int main()
{
  ll n; cin >> n;
  string ans;
  string brackets;

  int count_r_brackets = 0;
  int count_l_brackets = 0;

  for (size_t i = 0; i < n; i++) {
    char e; cin >> e;
    brackets += e;

    if(e == '(') count_l_brackets++;
    if(e == ')') count_r_brackets++;
  }

  if(n & 1 == 0) {
    ans = "NO";
    cout << ans << endl;
    return 0;
  }

  if(count_l_brackets == count_r_brackets)
    ans = is_brackets_valid(brackets, 1);
  else
    ans = "NO";

  cout << ans << endl;
  return 0;
}
