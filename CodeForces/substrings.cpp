#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

string s = "abc";
int N = 3;
vector<string> v;

void substr(int n, string sub) {
  if(n==N) {
    v.push_back(sub);
    return;
  }

  substr((n+1), sub+=s[n]);
  substr((n+1), sub);
  v.push_back(sub+=s[n]);
}

int main() {
  substr(0, "");

  cout << "v.size(): " << v.size() << endl;
  for (size_t i = 0; i < v.size(); i++)
    cout << v[i] << endl;

  return 0;
}
