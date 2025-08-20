#include <bits/stdc++.h>

#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

#define sf(n) cin >> n;
#define sff(n,m) cin >> n >> m;
#define dbg(n) cout << "n: " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;

using namespace std;

int32_t count_set(string s, int X) {
  map<char, int> mp;
  for (size_t i = 0; i < s.size(); i++)
  {
    if(s[i]=='A') {
      mp['a']++;
    } else if(s[i]=='B') {
      mp['b']++;
    };
  
    if(mp['a'] == X) return 1;
    if(mp['b'] == X) return 0;
  }

  return 0;
}

int32_t calculate_X(string s) {
  int X = INT_MAX; // Initialize X to zero
  int currentWins = 0;
  vector<int> sets;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      currentWins++;
    } else {
      currentWins = 0;
    }

    X = min(X, currentWins);
  }

  return X;
}

int32_t calculate_Y(string s, int X) {
  vector<int> sets;
  int Y = 0;
  int totalWinsA = 0;

  for (int i = 0; i < sets.size(); i++) {
    totalWinsA += X;
    if (totalWinsA > i + 1) {
      Y = i + 1;
    }
  }

  return X;
}

int32_t main() 
{sws;
  int t; sf(t);

  while(t--) {
    int n; sf(n);
    string s; sf(s);

    int X = calculate_X(s);
    int Y = calculate_Y(s, X);

    cout << "X: " << X << endl;
    cout << "Y: " << Y << endl;

    int b=0, a=0;
    int pos = 0;

    for (; pos < s.size(); pos+=X)
    {
      if(count_set(s.substr(pos, X), X)) a++;
      else b++;
    }

    // dbg(b);
    if(b>a)
      cout << "B" << endl;
    else if (a>b)
      cout << "A" << endl;
    else cout << "?" << endl;
    // cout << endl;
  }
  return 0;
}


// NÃO CONSEGUI FAZER
