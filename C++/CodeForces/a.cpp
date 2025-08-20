#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

const int N = 0;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

// End Template //

int32_t main()
{sws;

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    int ans = 0;
    for (int i=0;i<n-m+1;i++) {
        bool no_match = true;
        for (int j=0;j<m;j++) {
            if (s[i+j] == t[j]) no_match = false;
        }
        if (no_match) ans ++;
    }
    cout << ans << endl;


    return 0;
}