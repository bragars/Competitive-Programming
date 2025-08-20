#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;
  string result;

  while (T--)
  {
    string s, t;
    cin >> s >> t;
    string result = s + t;
    sort(result.begin(), result.end());
    cout << result << endl;
  }

  return 0;
}
