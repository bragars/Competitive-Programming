#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ff first
#define ss second
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

const int N = 1e5+10;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

// End Template //
 
int32_t main()
{sws;

    int n, k; cin >> n >> k;
    vector<int> id(n+1), c(n+1);
    vector<set<int>> c_ids(k+1);
    for (int i=1;i<=n;i++) {
        cin >> id[i] >> c[i];
        c_ids[c[i]].insert(id[i]);
    }

    bool ans = true;
    for (int i=1;i<=n;i++) {
        if (!c_ids[c[i]].count(i)) ans = false;
    }

    cout << (ans ? "Y":"N") << endl;

    return 0;
}