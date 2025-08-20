#include <bits/stdc++.h>

#define sws cin.tie(0) -> sync_with_stdio(false)
#define ll long long

using namespace std;

int main() {
  ll n; cin >> n;

  if(n == 1) {
    cout << "1" << endl;
    return 0;
  }
  if(n == 2 || n == 3) {
    cout << "NO SOLUTION" << endl;
    return 0;
  }

  if(n & 1 == 0) {
    for (int i = n-1; i > 0; i-=2)
      cout << i << " ";
    for (int i = n;   i > 0; i-=2)
      cout << i << " ";
  } else {
    for (int i = 2; i <= n; i+=2)
      cout << i << " ";
    for (int i = 1; i < n; i+=2)
      cout << i << " ";
  }

  return 0;
}
