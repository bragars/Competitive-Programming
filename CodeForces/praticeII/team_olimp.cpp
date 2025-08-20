#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

using namespace std;

struct compare { 
  bool operator()(const pair<int, int>& value, const int& key) { 
    return (value.first < key); 
  }

  bool operator()(const int& key, const pair<int, int>& value) {
    return (key < value.first); 
  } 
};

int get_talented_kid(vector<pii> &kids, int value) {
  for (size_t i = 0; i < kids.size(); i++)
  {
    if(kids[i].first == value) {
      int index = kids[i].second;
      kids.erase(kids.begin() + i);
      return index;
    }
  }
  return 0;
}

int main()
{sws;
  int n; cin >> n;
  vector<pii> kids;
  vector<vector<int>> teams;
  vector<int> team;
  bool there_is_1 = false, there_is_2 = false, there_is_3 = false;

  for (int i = 1; i <= n; i++)
  {
    int talent; cin >> talent;
    kids.push_back({talent, i});

    if(talent == 1) there_is_1 = true;
    if(talent == 2) there_is_2 = true;
    if(talent == 3) there_is_3 = true;
  }

  if(!there_is_1 or !there_is_2 or !there_is_3) {
    cout << "0" << endl;
    return 0;
  }

  sort(kids.begin(), kids.end());
  for (int i = 0; i < n; i++)
  {
    int value = get_talented_kid(kids, team.size() + 1);
    if(value > 0) team.push_back(value);

    if(team.size() == 3) {
      teams.push_back(team);
      team.clear();
    }
  }

  cout << teams.size() << endl;
  for (size_t i = 0; i < teams.size(); i++) {
    for (size_t j = 0; j < teams[i].size(); j++)
      cout << teams[i][j] << " ";
    cout << endl;
  }

  return 0;
}
