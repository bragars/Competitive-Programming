#include <iostream>
#include <vector>
#include <utility>

#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{
  sws;

  ll n;
  cin >> n;

  vector<int> attendance_points(n, 0);
  for (int &point : attendance_points)
    cin >> point;

  ll m;
  cin >> m;

  vector<int> thresholds(m, 0);
  for (int &threshold : thresholds)
    cin >> threshold;

  for (size_t k = 0; k < m; ++k)
  {
    int min_classes = 0;
    int min_points = 0;

    while (min_points < thresholds[k] && min_classes < n)
    {
      min_points += attendance_points[min_classes++];
    }
    cout << min_points << " " << min_classes << endl;
  }

  return 0;
}
