#include <bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) ((a+b-1)/(b))
using namespace std;

// Extra
#define all(x) x.begin(), x.end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//

const int MAX = 300010;
const ll MOD = (int)1e9 +7;
const int INF = 1e9;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-8;

// colocar suposicoes no PAPEL!! Verificar depois

map<int,ll> cnt[MAX];
map<int,ll> cnttree;
ll caminhos[MAX];
ll res[MAX];
vector<pair<int,int>> g[MAX];
int c[MAX], sz[MAX];

void opa(int u, int p) {
    cnttree[c[u]]++;
    sz[u] = 1;
    for(auto [v, i] : g[u]) {
        if(v == p) continue;
        opa(v, u);
        sz[u] += sz[v];
    }
}

void dfs(int u, int p, int idx) {
    int big = -1, maior = -1;
    for(auto [v, i] : g[u]) {
        if(v == p) continue;
        dfs(v, u, i);
        if(sz[v] > maior) {
            maior = sz[v];
            big = v;
        }
    }

    if(big != -1) {
        swap(cnt[u], cnt[big]);
        swap(caminhos[u], caminhos[big]);

        // retira big -> u
        caminhos[u] -= cnt[u][c[u]];
    }

    map<int,ll> cntsmall;

    // tira big -> small
    for(auto [v, i] : g[u]) {
        if(v == p or v == big) continue;

        for(auto [cor, qt] : cnt[v]) {
            caminhos[u] -= cnt[u][cor] * qt;
            cntsmall[cor] += qt;
        }
    }

    // adiciona small -> complementar
    for(auto [cor, qt] : cntsmall) {
        caminhos[u] += qt * (cnttree[cor] - qt - cnt[u][cor] - (c[u]==cor) );
    }

    for(auto [cor, qt] : cntsmall) {
        cnt[u][cor] += qt;
    }
    cnt[u][c[u]]++;

    // adiciona u -> complementar
    caminhos[u] += 1 * (cnttree[c[u]] - cnt[u][c[u]]);

    res[idx] = caminhos[u];
}

int32_t main() {
    sws;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for(int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;

        g[a].pb({b, i});
        g[b].pb({a, i});
    }

    opa(1, 1);
    dfs(1, 1, 0);

    for(int i = 1; i <= n-1; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
