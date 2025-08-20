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

const int MAX = 6e6+50;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-9;
const ld PI = acos(-1);

// End Template //

#define vp vector<point>

// typedef int cod;
// bool eq(cod a, cod b){ return (a==b); }
typedef ld cod;
bool eq(cod a, cod b){ return abs(a - b) <= EPS; }

struct point{
    cod x, y;
    int id;
    point(cod x=0, cod y=0, int id=0): x(x), y(y), id(id){}


    point operator+(const point &o) const{
        return {x+o.x, y+o.y};
    }
    point operator-(const point &o) const{
        return {x-o.x, y-o.y};
    }
    point operator*(cod t) const{
        return {x*t, y*t};
    }
    point operator/(cod t) const{
        return {x/t, y/t};
    }
    cod operator*(const point &o) const{ // dot
        return x * o.x + y * o.y;
    }
    cod operator^(const point &o) const{ // cross
        return x * o.y - y * o.x;
    }
    bool operator<(const point &o) const{
        if(!eq(x, o.x)) return x < o.x;
        return y < o.y;
    }
    bool operator==(const point &o) const{
        return eq(x, o.x) and eq(y, o.y);
    }

};

ld norm(point a){ // Modulo
    return sqrt(a*a);
}
int ccw(point a, point b, point e){ //-1=dir; 0=collinear; 1=esq;
    cod tmp = (b-a)^(e-a); // from a to b
    return (tmp > EPS) - (tmp < -EPS);
}

int quarter(point a){
    if(a.x>0 and a.y>=0) return 0;
    if(a.x<=0 and a.y>0) return 1;
    if(a.x<0 and a.y<=0) return 2;
    return 3;
}

int n;
point h, gt;

bool comp(point a, point b){ //ccw
    a=a-h;b=b-h;
    int qa = quarter(a);
    int qb = quarter(b);
    if(qa==qb) return (a^b)>0;
    else return qa<qb;
}

vi g[310][310];
vector<vl> dp(310, vl(310, -1));

ll dfs(int u, int pai){
    if(dp[u][pai]!=-1) return dp[u][pai];
    if(u==n+1) return 1;
    ll ans = 0;
    for(auto v: g[u][pai])
        ans += dfs(v, u);
    return dp[u][pai] = ans%MOD;
}

int32_t main()
{sws;

    gt.id=-1;
    cin >> h.x >> h.y;
    cin >> gt.x >> gt.y;

    cin >> n;
    vp t(n);
    t.pb(gt);

    for(int i=0;i<n;i++){
        cin >> t[i].x >> t[i].y;
        t[i].id=i;
    }
    sort(t.begin(), t.end(), comp);

    int gid = 0;
    for(int i=0;i<=n;i++)
        if(t[i].id==-1) gid=i;

    rotate(t.begin(), t.begin()+gid, t.end());
    t.pb(gt);

    for(int i=1;i<n+2;i++)
        if(ccw(gt, t[i], h)==1)
            g[0][0].pb(i);

    for(int i=0;i<n+2;i++){
        for(int j=i+1;j<n+2;j++){
            for(int k=j+1;k<n+2;k++){
                if(ccw(t[i], t[j], t[k])==1 and
                   ccw(t[i], t[j], h)==1 and
                   ccw(t[j], t[k], h)==1)
                        g[j][i].pb(k);
            }
        }
    }

    cout << dfs(0, 0) << endl;


    return 0;
}