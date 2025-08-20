#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long

void loop_map_items() {
  std::unordered_map<std::string, std::string> colors = {
    {"RED", "#FF0000"},
    {"GREEN", "#00FF00"},
    {"BLUE", "#0000FF"}
  };

  for(const auto&[name, hex]: colors) {
    std::cout << "Name: " << name << ", Hex: " << hex;
  }
}

struct S {
  int a;
  std::string s;
};

S get_s();

void use_s() {
  const auto[name_for_a, name_for_s] = get_s();
}

struct Values {
  int x, y;
};

Values get_multiple_values(const int n) {
  return {n, n+1};
}

void use_values() {
  auto [x, y] = get_multiple_values(10);
}