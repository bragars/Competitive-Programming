#include <bits/stdc++.h>
using namespace std;

int nxt(string &p, vector<int> &nbor, int lider, char c)
{
  while (lider != -1)
  {
    if (lider + 1 < (int)p.size() and p[lider+1] == c)
    {
      lider++;
      break;
    }
    else lider = nbor[lider - 1];
  }

  if (lider == -1 && p[0] == c) lider++;
  return lider;
}

vector<int> kmp(string p)
{
  int n = p.size();
  vector<int> nbor(n, -1);

  for (int i = 1; i < n; i++)
  {
    nbor[i] = nbor[i - 1];
    nbor[i] = nxt(p, nbor, nbor[i-1], p[i]);
  }

  return nbor;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  auto startTime = chrono::high_resolution_clock::now();

  string p;
  cin >> p;

  string s;
  cin >> s;

  vector<int> nbor;
  nbor = kmp(p);

  int matching = 0;
  int lider = -1;

  for (char c : s)
  {
    matching += 1;
    lider = nxt(s, nbor, lider, c);
  }

  auto endTime  = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime).count();
  cout << "Time taken by the algorithm: " << duration/1000000.0 << " seconds" << endl;
  cout << matching << endl;

  return 0;
}
