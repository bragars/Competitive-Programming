#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  int n, k; cin >> n >> k;
  stack<int> parking_space;
  bool flag = true;

  while (n--)
  {
    int arrival, departure; 
    cin >> arrival >> departure;

    while (!parking_space.empty() and parking_space.top() < arrival)
      parking_space.pop();

    if (parking_space.empty())
      parking_space.push(departure);
    else
      if (parking_space.top() > departure)
        parking_space.push(departure);
      else
        flag = false;
  }

  cout << (flag == false ? "Nao" : "Sim") << endl;
  return 0;
}
