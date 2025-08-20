#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> ratings)
{
  vector<int> heighest_dish = {0, 0};
  int heighest_rating = INT_MIN;
  int ratings_size = ratings.size();

  if (n < 1 || n > 100000 || ratings_size < 1 || ratings_size > 1000000000)
    return 0;

  // for (auto i = ratings.begin(); i != ratings.end(); i++)
  // {
  //   for (auto j = i->begin(); j != i->end(); j++)
  //   {
  //     auto next = std::next(j);
  //     if (next != i->end())
  //     {
  //       if (heighest_rating < *next) {
  //         heighest_dish = *i;
  //         heighest_rating = *next;
  //       } else if(heighest_rating == *next && *j < heighest_dish[0]) {
  //         heighest_dish = *i;
  //       }
  //     }
  //   }
  // }

  for (const vector<int> dish : ratings) {
    int dish_id = dish[0];
    int rating = dish[1];

    if (heighest_dish[1] < rating) {
      heighest_dish = dish;
    }
    else if (heighest_dish[1] == rating) {
      if (dish[0] < heighest_dish[0])
        heighest_dish = dish;
    }
  }

  return heighest_dish[0];

  // return 0;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> ratings(n, vector<int>(2));

  for (int i_ratings = 0; i_ratings < n; i_ratings++)
  {
    for (int j_ratings = 0; j_ratings < 2; j_ratings++)
    {
      cin >> ratings[i_ratings][j_ratings];
    }
  }

  int out_;
  out_ = solution(n, ratings);
  cout << out_;
}
