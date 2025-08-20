#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long

using std::cin, std::cout;

int main()
{sws;
  const std::vector<int> a = {-1, -3, -8, 8, 3, 9};
  const int n = 10;
  std::array<int, n> arr{};

  const auto is_positive = [](const auto &x) { return x > 0; };
  auto idx = std::find_if(a.cbegin(), a.cend(), is_positive);

  if (idx != a.cend())
    cout << "Found a positive number: " << *idx << '\n';
  else
    cout << "No positive number found in the vector.\n";

  return 0;
}
