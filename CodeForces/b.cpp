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

#define point pair<ll, ll>
vector<vector<int>> g(N);
vector<ll> triangle_area(N);

ll dp[N][2];

// dp to maximize removed area
ll dfs(int u, bool remove, int p=-1) {
    if (remove and g[u].size() < 3) return 0; // to remove it, it needs to be a inside triangle
    if (dp[u][remove] != -1) return dp[u][remove];
    
    ll ans = 0;
    for (auto v: g[u]) if (v != p) {
        if (remove) ans += dfs(v, false, u);
        else ans += max(dfs(v, true, u), dfs(v, false, u));
    }

    if (remove) ans += triangle_area[u];

    return dp[u][remove] = ans;
}

int32_t main()
{sws;

    memset(dp, -1, sizeof(dp));

    int n; cin >> n;

    map<pair<point, point>, vector<int>> edges;
    auto add_edge = [&](point p1, point p2, int id) {
        if (p1 > p2) swap(p1, p2); // {p1, p2} == {p2, p1}
        edges[{p1, p2}].push_back(id);
    };


    auto area = [&](point p1, point p2, point p3) {  
        p1.ff -= p3.ff; p1.ss -= p3.ss;
        p2.ff -= p3.ff; p2.ss -= p3.ss;
        return abs(p1.ff * p2.ss - p1.ss * p2.ff); // cross product
    };
    ll total_area = 0;
    for (int i=0;i<n;i++) {
        point p1, p2, p3;
        cin >> p1.ff >> p1.ss;
        cin >> p2.ff >> p2.ss;
        cin >> p3.ff >> p3.ss;

        add_edge(p1, p2, i);
        add_edge(p2, p3, i);
        add_edge(p3, p1, i);

        triangle_area[i] = area(p1, p2, p3);
        total_area += triangle_area[i];
    }

    for (auto [p, vid]: edges) {
        assert(vid.size() <= 2);
        if (vid.size() == 2) {
            int a = vid[0], b = vid[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    // its a tree, just run a dp to maximize the removed area
    ll area_to_remove = max(dfs(0, true), dfs(0, false));
    cout << fixed << setprecision(1);
    cout << (total_area - area_to_remove) / 2.0 << endl;

    return 0;
}