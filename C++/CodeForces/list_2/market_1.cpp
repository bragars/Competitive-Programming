#include <bits/stdc++.h>
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

int32_t main()
{sws;
  int n, m; cin >> n >> m;

  vector<int> employees_time_spent(n, 0);
  vector<int> basket_num_items(m, 0);
  vector<int> time_spent(n, 0);

  for (size_t i = 0; i < n; i++) cin >> employees_time_spent[i];
  for (size_t i = 0; i < m; i++) cin >> basket_num_items[i];

  for (size_t i = 0; i < m; i++)
  {
    int min_time = *min_element(time_spent.begin(), time_spent.end()); // Find the cashier who will be available next
    int cashier_index = find(time_spent.begin(), time_spent.end(), min_time) - time_spent.begin();
    time_spent[cashier_index] += employees_time_spent[cashier_index] * basket_num_items[i];
  }

  int total_time = *max_element(time_spent.begin(), time_spent.end());
  cout << total_time << endl;

  return 0;
}
