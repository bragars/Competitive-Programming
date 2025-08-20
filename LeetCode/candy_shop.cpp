#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solution(vector<int> &candies, int &liked_students, int &total_candies_given)
{
  // if at the moment he receives his order, he 
  // has more candies than everyone else together.
  for (size_t i = 0; i < candies.size(); i++)
  {
    if (total_candies_given < candies[i])
    {
      total_candies_given += candies[i];
      liked_students++;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q;
  cin >> q;

  while (q--)
  {
    int n;
    cin >> n;

    vector<int> candies(n, 0);
    int liked_students = 0, total_candies_given = 0;

    for (size_t i = 0; i < n; i++)
    {
      cin >> candies[i];
    }

    sort(candies.begin(), candies.end());
    solution(candies, liked_students, total_candies_given);
    cout << liked_students << " " << total_candies_given << endl;
  }

  return 0;
}
