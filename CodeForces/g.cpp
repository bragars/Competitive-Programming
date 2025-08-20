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

struct Hash {
    const ll P = 31;
    int n; string s;
    vector<ll> h, hi, p;
    Hash() {}
    Hash(string s): s(s), n(s.size()), h(n), hi(n), p(n) {
        for (int i=0;i<n;i++) p[i] = (i ? P*p[i-1]:1) % MOD;
        for (int i=0;i<n;i++)
            h[i] = (s[i] + (i ? h[i-1]:0) * P) % MOD;
        for (int i=n-1;i>=0;i--) 
            hi[i] = (s[i] + (i+1<n ? hi[i+1]:0) * P) % MOD;
    }
    int query(int l, int r) {
        ll hash = (h[r] - (l ? h[l-1]*p[r-l+1]%MOD : 0));
        return hash < 0 ? hash + MOD : hash;
    }
    int query_inv(int l, int r) {
        ll hash = (hi[l] - (r+1 < n ? hi[r+1]*p[r-l+1] % MOD : 0));
        return hash < 0 ? hash + MOD : hash;
    }
};
 
int32_t main()
{sws;
 
    int n; cin >> n;
    string s; cin >> s;
 
    Hash hs(s);
    ll ans = 0;
 
    auto out_of_range = [&](int len, int left, int right) {
        return (left - len < 0 or right + len >= n);
    };
    auto check = [&](int len, int left, int right) {
        if (out_of_range(len, left, right)) return false;
        return hs.query(left-len, left) == hs.query_inv(right, right+len);
    };
 
    auto bb = [&](int left, int right) { // first good lenght
        int l = 0, r = n, ans = -1;
        while (l <= r) {
            int len = (l + r) / 2;
            if (check(len, left, right))
                l = len + 1, ans = len;
            else r = len - 1;
        }
        return ans;
    };
 
    auto bb_twice = [&](int left, int right) {
        int ans = bb(left, right);
        
        if (out_of_range(ans+1, left, right)) return ans;
        ans ++; // insert the wrong one
        if (out_of_range(ans+1, left, right)) return ans;
        left -= ans + 1; right += ans + 1;
 
        int ans2 = bb(left, right) + 1;
        return ans + ans2;
    };
 
    for (int i=0;i<n;i++) { // odd
        int sz = bb_twice(i, i);
        ans += sz + 1;
    }
    for (int i=1;i<n;i++) { // even
        int sz = bb_twice(i-1, i);
        ans += sz + 1;
    }
 
    cout << ans << endl;
 
    return 0;
}