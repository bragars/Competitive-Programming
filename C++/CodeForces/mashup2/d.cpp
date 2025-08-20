#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);

using namespace std;

vector<pii> eat(vector<pii> &T, int termite, int m) {
  int idx = 0;
  bool eated = false;

  while(!eated) {
    if(T[idx].first >= T[idx].second + termite) {
      T[idx].second += termite;
      eated = true;
    } else {
      idx++;

      if(idx > (T.size() - 1))
        T.push_back(make_pair(m, 0));
    }
  }

  return T;
}

int32_t main()
{sws;
  int x, y, z; cin >> x >> y >> z;
  int m; cin >> m;
  ll n; cin >> n;
  string s; cin >> s;

  vector<pii> T;
  T.push_back(make_pair(m, 0));

  for (size_t i = 0; i < s.size(); i++)
  {
    if(s[i] == 'F') {
      T = eat(T, x, m);
    }
    else if(s[i] == 'A') {
      T = eat(T, y, m);
    }
    else {
      T = eat(T, z, m);
    }
  }

  cout << T.size() << endl;
  return 0;
}
