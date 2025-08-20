#include <bits/stdc++.h>

int main()
{
  std::vector<int> vec = {40, 50, 40};

  // Create a vector of indices
  std::vector<int> indices(vec.size());
  std::iota(indices.begin(), indices.end(), 0);

  // Sort the indices based on the values in the original vector
  std::sort(indices.begin(), indices.end(), [&](int a, int b)
            { return vec[a] < vec[b]; });

  // Create a mapping of sorted indices to their positions
  std::vector<int> positionMapping(vec.size());
  for (int i = 0; i < vec.size(); ++i)
  {
    positionMapping[indices[i]] = i;
  }

  // Transform the original vector using the mappings
  for (int i = 0; i < vec.size(); ++i)
  {
    vec[i] = positionMapping[i];
  }

  // Print the transformed vector
  for (int i : vec)
  {
    std::cout << i << " ";
  }

  return 0;
}
