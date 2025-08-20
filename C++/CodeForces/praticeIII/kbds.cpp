#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false); cout.tie(0);

#define ll long long
#define pii pair<int, int>

using namespace std;

char f(char a, string t1, string t2) {
  int idx = 0;
  bool is_upper = a >= 'A' && a <= 'Z';

  for (size_t i = 0; i < t1.size(); i++)
    if(tolower(a) == t1[i])
      idx = i;

  if(is_upper)
    return toupper(t2[idx]);
  else
    return t2[idx];
}

int32_t main()
{sws;
  string t1, t2; cin >> t1; cin >> t2;
  int n; cin >> n;

  while(n--) {
    string s1; cin >> s1;
    for (size_t i = 0; i < s1.size(); i++) {
      char a = s1[i];
      if(isdigit(a)) {
        cout << a;
      } else {
        a = f(a, t1, t2);
        cout << a;
      }
    }
    cout << endl;
  }
  return 0;
}