#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{
  sws;
  int n;
  cin >> n;
  vector<ll> sac(n, 0);
  ll max_element = 0;

  while (n--)
  {
    char command;
    cin >> command;
    ll int_aux;
    cin >> int_aux;

    if (command == 'A') {
      sac.push_back(int_aux);
      max_element = max(max_element, int_aux);
    }
    else if (command == 'V')
      cout << max_element << endl;
    else
    {
      int removed = sac.back();
      sac.pop_back();

      if (removed == max_element)
        max_element = *std::max_element(sac.begin(), sac.end());
    }
  }

  return 0;
}
