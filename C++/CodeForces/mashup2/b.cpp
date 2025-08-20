#include <bits/stdc++.h>

#define sws cin.tie(0); cout.tie(0)->sync_with_stdio(false);
#define ll long long
using namespace std;

int main()
{
  ll P;
  int N;
  cin >> P;
  cin >> N;
  vector<ll> lp;

  for (size_t i = 0; i < N; i++)
  {
    int X;
    cin >> X;
    int Y = 0;
    if (X == 1)
    {
      cin >> Y;
      P += Y;
      lp.push_back(Y);
    }
    else
    {
      cin >> Y;
      int ix = lp.size() - 1;
      if (!lp.empty())
        while (ix >= 0 and Y--)
        {
          P -= lp[ix];
          lp.erase(lp.begin() + ix);
          ix -= 1;
        }
    }
  }

  cout << P << endl;
  return 0;
}
