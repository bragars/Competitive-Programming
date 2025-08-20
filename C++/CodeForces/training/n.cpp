#include <bits/stdc++.h>
using namespace std;

#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);

int main()
{sws;

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  string s; cin >> s;
  int size = s.size();
  int l = 0, r = size - 1;

  string aux = s; reverse(aux.begin(), aux.end());

  while (s != aux)
  {
    s[r] = s[l];
    r--; l++;
    aux = s; reverse(aux.begin(), aux.end());
  }

  // cout << aux << endl;
  cout << s << endl;
  return 0;
}
