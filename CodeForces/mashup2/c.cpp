#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  int t; cin >> t;
  while(t--) {
    int n; cin >> n; // 3 <= n <= 1000 
    set<int> s;
    vector<int> ms;

    for (size_t i = 0; i < n; i++)
    {
      for (size_t i = 0; i < n-1; i++)
      {
        int e; cin >> e;
        s.insert(e);
      }
      
      for (size_t i = 1; i <= n; i++)
      {
        if(!s.count(i)) ms.push_back(i);
      }
      s.clear();
    }
    for (size_t i = 0; i < ms.size(); i++)
    {
      cout << ms[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
