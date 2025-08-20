#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
  int find_asteroid(vector<int> &asteroids, int asteroid_value)
  {
    int index = -1;
    for (auto asteroid : asteroids)
    {
      if (asteroid == asteroid_value)
        return index;
      index++;
    }
    return index;
  }

  bool diferent_direction(int a, int b)
  {
    if (a > 0 && b < 0 || a < 0 && b > 0)
      return true;
    else
      return false;
  }

  void equalize_asteroid(vector<int> &asteroids, int minimum)
  {
    int equalized = -1, both_equalized = -1;

    equalized = find_asteroid(asteroids, minimum);
    both_equalized = find_asteroid(asteroids, -minimum);

    if (equalized >= 0)
      asteroids.erase(asteroids.begin() + equalized);
    if (both_equalized >= 0)
      asteroids.erase(asteroids.begin() + both_equalized);
  }

  vector<int> asteroidCollision(vector<int> &asteroids)
  {
    if (asteroids.size() < 2)
      return asteroids;

    int minimum = 0;

    for (auto i = asteroids.rbegin(); i != asteroids.rend(); i++)
    {
      if (i != asteroids.rbegin())
      {
        auto prev = std::prev(i);
        minimum = min(*i, *prev);

        if (diferent_direction(*i, *prev))
          equalize_asteroid(asteroids, minimum);
      }
    }

    return asteroids;
  }
};

int main()
{
  Solution solution;
  vector<int> asteroids = {8, -8};
  vector<int> result_vec = solution.asteroidCollision(asteroids);

  for (auto item : result_vec)
  {
    cout << "item: " << item << endl;
  }

  return 0;
}
