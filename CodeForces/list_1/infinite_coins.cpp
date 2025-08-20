#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  int N, A; cin >> N >> A;

  if (A > N) {
    cout << "Sim" << endl;
    return 0;
  }

  if (A >= N % 500) {
    cout << "Sim" << endl;
  } else {
    cout << "Nao" << endl;
  }

  return 0;
}
