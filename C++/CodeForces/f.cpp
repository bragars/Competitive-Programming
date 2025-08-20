#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ff first
#define ss second
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

const int N = 1e5+10;
const ll MOD = 1e9+7, MOD2 = 1e9+9;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

// End Template //

struct Hash {
    const ll P = 31;
    int n; string s;
    vector<ll> h, h2, p, p2;
    Hash() {}
    Hash(string s): s(s), n(s.size()), h(n), h2(n), p(n), p2(n) {
        for (int i=0;i<n;i++) p[i] = (i ? P*p[i-1]:1) % MOD;
        for (int i=0;i<n;i++) p2[i] = (i ? P*p2[i-1]:1) % MOD2;
        for (int i=0;i<n;i++){
            h[i] = (s[i] + (i ? h[i-1]:0) * P) % MOD;
            h2[i] = (s[i] + (i ? h2[i-1]:0) * P) % MOD2;
        }
    }
    int query(int l, int r) {
        ll hash = (h[r] - (l ? h[l-1]*p[r-l+1]%MOD : 0));
        return hash < 0 ? hash + MOD : hash;
    }
    int query2(int l, int r) {
        ll hash = (h2[r] - (l ? h2[l-1]*p2[r-l+1]%MOD2 : 0));
        return hash < 0 ? hash + MOD2 : hash;
    }
};

int32_t main()
{sws;

    int n, m; cin >> n >> m;
    string A; cin >> A;
    Hash ha(A + A);

    vector<string> S(m);
    vector<Hash> hs;
    for (int i=0;i<m;i++) {
        cin >> S[i];
        hs.push_back(Hash(S[i]));
    }

    int l = 1, r = n+1, ans = 1;
    while (l <= r) {
        int mid = (l + r) / 2;

        set<pair<int, int>> str;
        for (int i=0;i<m;i++)
            for (int j=0;j+mid-1<S[i].size();j++)
                str.insert({
                    hs[i].query(j, j+mid-1), hs[i].query2(j, j+mid-1)
                });

        bool good = false;
        for (int i=0,j=-1;i+mid-1<2*n;i++) {
            pair<int, int> haq = {ha.query(i, i+mid-1), ha.query2(i, i+mid-1)};
            if (str.count(haq)) j = i;
            if (i - j + mid > n) good = true;
        }

        if (good) r = mid - 1, ans = mid;
        else l = mid + 1;
    }

    cout << ans - 1 << endl;


    return 0;
}