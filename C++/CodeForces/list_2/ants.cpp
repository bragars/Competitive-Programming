#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  ll ants = 0;
  string c; cin >> c;
  vector<char> p;
  bool there_is_r = false;

  for(int i = 0; i < c.size(); i++)
  {
    if(c[i] == '.' and there_is_r)
      p.push_back('.');

    else if(c[i] == 'r') {
      there_is_r = true;
      ants += p.size();
      p.clear();
    }
    else {
      there_is_r = false;
      p.clear();
    }

    int last_position = c.size() - 1;

    if(i == last_position) {
      ants += p.size();
    }
  }
  
  cout << ants << endl;
  return 0;
}
