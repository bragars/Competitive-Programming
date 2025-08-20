#include <bits/stdc++.h>
using namespace std;
#define sws cin.tie(0)->sync_with_stdio(false);
typedef tuple<int, int, int, int, int> tiiii;

int main()
{sws;
  cout.tie(0);
  int n; cin >> n;

  priority_queue<tiiii, vector<tiiii>, greater<tiiii>> f;

  for (int i = 0; i < n; i++)
  {
    int t, p, r;
    cin >> t >> p >> r;
    f.push(make_tuple(0, i, t, p, r));
  }

  int time = 0;

  while(!f.empty()) {
    f.pop();

    if (client.p + client.id >= time){
      if (time > client.id) {
        time += client.t;
      }
      else {
        time = client.id + client.t;
      }
    }
    else {
      client.id += client.p + client.r;
      f.push(client);
    }
  }

  std::cout << time << endl;
  return 0;
}
