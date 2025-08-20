#include <bits/stdc++.h>
// #define int long long
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define eb emplace_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ti tuple<int, int, int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define sws ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define teto(a, b) (((a)+(b)-1)/(b))
#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (int)n; i++)
#define forne(i, a, b) for(int i = a; i <= b; i++)
#define dbg(msg, var) cerr << msg << " " << var << endl;
 
using namespace std;
 
const int MAX = 2e5+10;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-8;
const ld PI = acos(-1);
 
// End Template //

struct Segtree{
    vi t;
    int n;

    Segtree(int n){
        this->n = n;
        t.assign(2*n, 0);
    }

    int merge(int a, int b){
        return a+b;
    }

    void build(){
        for(int i=n-1; i>0; i--)
            t[i]=merge(t[i<<1], t[i<<1|1]);
    }

    int query(int l, int r){ // [l, r]
        int resl=0, resr=0;
        for(l+=n, r+=n+1; l<r; l>>=1, r>>=1){
            if(l&1) resl = merge(resl, t[l++]);
            if(r&1) resr = merge(t[--r], resr);
        }
        return merge(resl, resr);
    }

    void update(int p, int value){
        for(t[p+=n]+=value; p >>= 1;)
            t[p] = merge(t[p<<1], t[p<<1|1]);
    }

};


const int LOG = 20;

vector<vi> pai(MAX, vi(LOG, 1));
vector<vi> g(MAX, vi());
vi a(MAX);

vector<vi> festa(MAX, vi());
vi ans(MAX, 0);
Segtree st(MAX);

void dfs(int u){
    for(auto l: festa[u])
        st.update(l, 1);

    ans[u] = st.query(0, a[u]);

    for(auto v: g[u])
        dfs(v);

    for(auto l: festa[u])
        st.update(l, -1);
}

int32_t main()
{sws;

    int n, m, b, o, l, r;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> a[i] >> b;
        if(i!=1) g[b].pb(i);
        pai[i][0] = b;
    }

    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            pai[i][j] = pai[pai[i][j-1]][j-1];
        }
    }

    for(int i=1;i<=m;i++){
        cin >> o >> l >> r;

        while(o!=1 and a[pai[o][0]]<=r){
            int id = 0;
            for(int j=0;j<LOG;j++){
                if(a[pai[o][j]]>r) break;
                id = pai[o][j];
            }
            o = id;
        }

        festa[o].pb(l);
    }

    dfs(1);

    for(int i=1;i<=n;i++)
        cout << ans[i] << " ";
    cout << endl;


    return 0;
}