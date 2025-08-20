#include <iostream>
#include <math.h>
using namespace std;

string solution(int x, int y, int v, int t) {
  int dist = sqrt(x*x + y*y);
  int max_dist = v * t;

  if (max_dist >= dist)
    return "YES";
  else
    return "NO";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int x, y, v, t;
    cin >> x;
    cin >> y;
    cin >> v;
    cin >> t;

    cout << solution(x, y, v, t) << endl;
  }

  return 0;
}