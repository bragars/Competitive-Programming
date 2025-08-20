#include <bits/stdc++.h>

using namespace std;
#define sws   \
  cin.tie(0); \
  cout.tie(0)->sync_with_stdio(false);

void b_pressed(string &s, int n)
{
  for (int i = n; i >= 0; i--)
  {
    if (islower(s[i]))
    {
      cout << "islower: " << i << endl;
      cout << "s: " << s << endl;
      cout << "islower: " << s[i] << endl;
      s.erase(s.begin() + i);
      return;
    }
  }
  return;
}

void B_pressed(string &s, int n)
{
  for (int i = n; i >= 0; i--)
  {
    if (isupper(s[i]))
    {
      s.erase(s.begin() + i);
      return;
    }
  }
}

int main()
{
  // freopen("output.txt", "w", stdout);
  freopen("input.txt", "r", stdin);

  int t;
  cin >> t;

  while (t--)
  {
    string a;
    cin >> a;

    int pos = a.find('b');
    while (pos != string::npos)
    {
      a.erase(a.begin() + pos);
      b_pressed(a, pos);
      pos = a.find('b');
      cout << "current a: " << a << endl;
    }

    cout << "here\n";

    pos = a.find('B');
    while (pos != string::npos)
    {
      a.erase(a.begin() + pos);
      B_pressed(a, pos);
      pos = a.find('B');
      cout << "current a: " << a << endl;
    }
    cout << "a: " << a << endl;

    return 0;
  }
}
