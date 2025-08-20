#include <bits/stdc++.h>

using namespace std;

#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pair<int, int>>

int main() 
{sws;
  int n; cin >> n;
  string s; cin >> s;
  char a = s[0];
  int ans = 0;

  for (size_t i = 0; i < n; i++)
  {
    if(a == s[i]) ans++;
  }

  return 0;
}
