#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;

  while(t--) {
    // n - number of naseem friends
    // m - types of smoothies
    int n, m; cin >> n >> m;
    int maximum = 0;
    vector<int> vec(m, 0);

    // ith type naseem ordered
    for (int i = 0; i < n; i++)
    {
      int a; cin >> a;
      vec[a-1] = vec[a-1]+1;
    }

    // ith type friend prefers
    for (int i = 0; i < n; i++)
    {
      int b; cin >> b;
      if (vec[b-1] >= 1) {
        vec[b-1] = vec[b-1] - 1;
        maximum++;
      }
    }

    cout <<maximum << endl;
  }

  return 0;
}