#include <bits/stdc++.h>

using namespace std;
#define sws   \
  cin.tie(0); \
  cout.tie(0)->sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;

#define MP make_pair
#define sf(n) cin >> n;
#define sff(n, m) cin >> n >> m;
#define dbg(s, n) cout << s << ": " << n << endl;
#define print(n) cout << n << endl;
#define nl cout << endl;
#define pfs(s) cout << s;
#define pb push_back;

int main()
{
  // freopen("output.txt", "w", stdout);
  // freopen("input.txt", "r", stdin);

  ll n; cin >> n;
  string s = to_string(n);
  vector<int> bins;
  bool is_bin = true;
  int times=0;

  for (auto it = s.begin(); it != s.end(); it++)
  {
    char c=*it;
    if(c != '1' and c != '0')
      is_bin = false;
  }

  if(is_bin) {
    times=1;
    cout << times << endl;
    cout << s << endl;
    return 0;
  } else {
    while(true)
    {
      if(n <= 9) {
        bins.insert(bins.end(), n, 1);
        times=n;
        break;
      } else {
        int p=floor(log10(n));
        ll divider=pow(10,p);
        cout << "divider: " << divider << endl;

        if((n%divider) == 0) {
          bins.insert(bins.end(), (n/divider), divider);
          times=n/divider;
          break;
        } else {
          cout << "Here: \n";
          int i = 0;
          while(n>divider){
            bins.insert(bins.end(), 1, divider);
            n-=divider; times++;
          }
          cout << "n: " << n << endl;
          int nd = floor(log10(abs(n)));
          divider = pow(10, nd);
          cout << "divider: " << divider << endl;

          while(n>divider and i<bins.size()){
            bins[i]+=divider;
            n-=divider; i++;
          }
          i=0;
          cout << "n w: " << n << endl;
          nd = floor(log10(abs(n)));
          divider=pow(11,nd);
          while(n>10 and i<bins.size()){
            bins[i]+=divider;
            n-=divider; i++;
          }
          while(n>10){
            bins.insert(bins.end(), 1, 10);
            n-=10; times++;
          }
          i=0;
          while(n>0 and i<bins.size()){
            bins[i]+=1;
            n--; i++;
          }
          if(n>0){
            bins.insert(bins.end(), n, 1);
            times+=n;
          }
          break;
        }
      }
    }
  }

  cout << times << endl;
  for (size_t i = 0; i < bins.size(); i++)
  {
    cout << bins[i] << " ";
  }
  cout << endl;

  return 0;
}
