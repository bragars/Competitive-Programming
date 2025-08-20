#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);
#define ll long long
#define pii pair<int, int>

using namespace std;

bool comp(pii a, pii b) {
  if(a.first == b.first) {
    return a.second < b.second
  }
  return a.first < b.first
}

int main()
{sws;
  int n; cin >> n;
  vector<pii> v = {{3, 6}, {7, 2}, {1, 3}, {9, 2} , {2, 10}};
  priority_queue<int> pq_max;
  priority_queue<int, vector<int>, greater<int>> pq_min;
  
  sort(v.begin(), v.end(), comp());
  pq_max.push(5);
  pq_max.push(3);
  pq_max.push(2);
  pq_max.push(7);


  if(pq_max.empty()) {

  } else {

  }

  while(!pq_max.empty()) {
    int elem = pq_max.top();
    
  }

  return 0;
}
