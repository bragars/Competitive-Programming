#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N; cin >> N;
  vector<pair<int, int>> runners;

  for (int i = 1; i <= N; i++)
  {
    int runner_time; cin >> runner_time;
    runners.push_back({runner_time, i});
  }

  sort(runners.begin(), runners.end());
  vector<int> positions(N, 1);

  for (int i = 1; i < N; i++)
  {
    if(runners[i].first > runners[i-1].first)
      positions[runners[i].second - 1] = i + 1;
    else
      positions[runners[i].second - 1] = positions[runners[i-1].second - 1];
    
  }

  for (int i = 0; i < N; i++)
    cout << positions[i] << " ";

  cout << endl;
  return 0;
}
