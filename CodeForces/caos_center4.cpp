#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
typedef tuple<int, int, int, int, int> tiiii;

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, tt = 0, i = 1;
  priority_queue<tiiii, vector<tiiii>, greater<tiiii>> fila;

  cin >> n;

  while (n--)
  {
    int t, p, r;
    cin >> t >> p >> r;

    fila.push(make_tuple(0, i, t, p, r));
    i++;
  }

  while (!fila.empty())
  {
    int v = get<0>(fila.top());
    int i = get<1>(fila.top());
    int t = get<2>(fila.top());
    int p = get<3>(fila.top());
    int r = get<4>(fila.top());

    fila.pop();
    if (tt <= p + v)
    {
      if (tt > v)
      {
        tt = tt + t;
      }
      else
      {
        tt = v + t;
      }
    }
    else
    {
      fila.push(make_tuple(v + p + r, i, t, p, r));
    }
    // cout << " tt = " << tt << " i = " << i << " t= " << t << " p= " << p << " r= " << r << " v = " << v << endl;
  }

  cout << tt << endl;
  return 0;
}