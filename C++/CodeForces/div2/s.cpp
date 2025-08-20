#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

using namespace std;

vector<int> subtract(vector<int> &v, int r, int m) {
  for (size_t i = 0; i < r; i++)
    v[i] -= v[i];
  return v;
}

void p(vector<int> v) {
  for (size_t i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

int is_decr(vector<int> &v) {
  int ans = 1;

  for (size_t i = 1; i < v.size(); i++) {
    if(v[i] < v[i-1]) ans=0;
  }

  return ans;
}

int d_or(vector<int> &v) {
  int l = v[0], r = 0;
  double m = 1;

  for (size_t i = 0; i < v.size(); i++)
  {
    if(pow(2, m) < v.size()) {
      r=pow(2, m);
      m++;
    }

    subtract(v, r, m);
    if(is_decr(v)) {
      return 1;
    }
    l=v[i];
  }

  return 0;
}

int main()
{sws;
  int t; cin >> t;

  while(t--) {
    int n; cin >> n;
    int ans = 0;
    vector<int> v(n,0);

    for (size_t i = 0; i < n; i++) {
      int e; cin >> e;
      v[i] = e;
    }

    if(is_decr(v)) {
      cout << "YES" << endl;
      continue;
    }

    ans = d_or(v);
    ans ? cout << "YES" << endl : cout << "NO" << endl;
  }

  return 0;
}
