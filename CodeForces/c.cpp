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

const ld EPS = 1e-6;

typedef ld T;
bool eq(T a, T b){ return abs(a - b) <= EPS; }
struct point{
    T x, y;
    int id;
    point(T x=0, T y=0): x(x), y(y){}
    point operator+(const point &o) const{ return {x + o.x, y + o.y}; }
    point operator-(const point &o) const{ return {x - o.x, y - o.y}; }
    point operator*(T t) const{ return {x * t, y * t}; }
    point operator/(T t) const{ return {x / t, y / t}; }
    T operator*(const point &o) const{ return x * o.x + y * o.y; } // dot product
    T operator^(const point &o) const{ return x * o.y - y * o.x; } // cross product
};

ld dist(point a, point b) {
    point d = a - b;
    return sqrt(d * d);
}
 
int32_t main()
{sws;

    int n; cin >> n;
    vector<point> p(n);
    for (int i=0;i<n;i++) {
        cin >> p[i].x >> p[i].y;
    }
    for (int i=0;i<n;i++) p.push_back(p[i]); // duplicate

    // two pointers technique
    ld ans = 0, perimeter = dist(p[0], p[1]);
    for (int i=0,j=0;i<n;i++) {
        // I can see [edge(i, i+1), edge(j, j+1)]
        // if I can see edge edge(i, i+1), edge(j, j+1) is the last one I can see
        while (i == j or ((p[i+1]-p[i]) ^ (p[j+1+1]-p[j+1])) > 0) { // I can make j = j+1
            j++;
            perimeter += dist(p[j], p[j+1]);
        }
        ans = max(ans, perimeter);
        perimeter -= dist(p[i], p[i+1]);
    }

    cout << fixed << setprecision(10);
    cout << ans << endl;

    return 0;
}