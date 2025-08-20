#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  int n; int f; int p; cin >> n >> f >> p;
  queue<int> q;
  int index = f;
  int t = 0;

  for(int i = 0; i < n; i++) {
    int c; cin >> c;
    q.push(c);
  }

  while(index < n or !q.empty())
  {
    int c = q.front();

    if(index % f == 0) {
      if(c > p) {
        t+=10;
        q.push(c-=2);
      } else {
        t+=5;
      }
    } else {
      t++;
    }

    q.pop();
    index++;
  }

  cout << t << endl;
  return 0;
}
