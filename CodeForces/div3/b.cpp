#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sws cin.tie(0); cout.tie(0) -> sync_with_stdio(false);

int main()
{sws;

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t; cin >> t;

  while(t--) {
    int n; cin >> n;

    vector<ll> vec(n, 0);
    vector<ll> vec_aux(n, 0);

    for (int i = 0; i < n; i++) cin >> vec[i];

    int atual = 0; ll ans = 0;

    for (int i = 1; i < n; i++)
    {
      if(n % i != 0) continue;

      if(i == 1) {
        ll max_e = (ll) *max_element(vec.begin(), vec.end());
        ll min_e = (ll) *min_element(vec.begin(), vec.end());
        ans = max(ans, (max_e-min_e));
        continue;
      }

      vector<ll> vec_aux((n/i), 0);
      int slice = i, vec_aux_counter = 0;
      for (int j = 0; j < n; j++)
      {
        atual += vec[j]; slice--;

        if(slice == 0) {
          vec_aux[vec_aux_counter] = atual;
          slice = i; atual=0;
          vec_aux_counter++;
        }
      }

      ll max_e = (ll) *max_element(vec_aux.begin(), vec_aux.end());
      ll min_e = (ll) *min_element(vec_aux.begin(), vec_aux.end());
      ans = max(ans, (max_e-min_e));
    }

    cout << ans << endl;
  }

  return 0;
}
