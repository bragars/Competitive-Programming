// algorithm 1
// maximum subarray sum

#include <iostream>
#include <vector>

int max(int best,int sum) {
  if (best > sum)
    return best;
  else
    return sum;
}

int main() {
  std::vector<int> arr = {-1, 2, 4, -3, 5, 2, -5, 2};
  int n = arr.size();

  int best = 0;
  for (int a = 0; a < n; a++) {
    int sum = 0;
    for (int b = a; b < n; b++) {
      sum += arr[b];
      best = max(best,sum);
    }
  }
  std::cout << best << "\n";
}
