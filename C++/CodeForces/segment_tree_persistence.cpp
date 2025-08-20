#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sws cin.tie(0)->sync_with_stdio(false);

struct Node
{
  int val;
  int ref = 0;

  Node *left;
  Node *right;

  Node() : val(0), left(nullptr), right(nullptr) {}
  Node(int val) : val(val), left(nullptr), right(nullptr) {}
  Node(int val, Node *l, Node *r) : val(val), left(l), right(r) {}
};

const int MAXN = 1e5;
int arr[MAXN];
Node *version[MAXN];

class SegmentTreePersistency
{
public:
  int version_size = 1;
  int low = 0;
  int n;

  SegmentTreePersistency(int n)
  {
    this->n = n;
  }

  void build(Node *root, int low, int high)
  {
    if (low == high)
    {
      root->val = arr[low];
      return;
    }

    int mid = (low + high) / 2;
    root->left = new Node(0);
    root->right = new Node(0);

    build(root->left, low, mid);
    build(root->right, mid + 1, high);
    root->val = root->left->val + root->right->val;
  }

  void update(Node *prev, Node *cur, int low, int high, int idx, int value)
  {
    upgrade(prev, cur, low, high, idx, value);
    this->version_size++;
  }

  void upgrade(Node *prev, Node *cur, int low, int high, int idx, int value)
  {
    if (low > high || idx > high || idx < low)
      return;

    if (low == high)
    {
      cur->val = value;
      return;
    }

    int mid = (low + high) / 2;
    if (idx <= mid)
    {
      cur->right = new Node();
      cur->right->val = prev->right->val;

      cur->left = new Node(0);
      upgrade(prev->left, cur->left, low, mid, idx, value);
    }
    else
    {
      cur->left = prev->left;
      cur->left->val = prev->left->val;

      cur->right = new Node(0);
      upgrade(prev->right, cur->right, mid + 1, high, idx, value);
    }

    cur->val = cur->left->val + cur->right->val;
  }

  int query(Node *root, int low, int high, int l, int r)
  {
    if (l > high || r < low || low > high)
    {
      return 0;
    }
    if (l <= low && r >= high)
    {
      return root->val;
    }

    int mid = (low + high) / 2;
    int p1 = query(root->left, low, mid, l, r);
    int p2 = query(root->right, mid + 1, high, l, r);

    return p1 + p2;
  }

  void clear_version(Node *root)
  {
    if (root == nullptr)
    {
      return;
    }

    clear_version(root->left);
    clear_version(root->right);
  }

  void clear_versions()
  {
    for (int i = this->version_size-1; i >= 0; i--)
    {
      clear_version(version[i]);
    }
  }

  void print(Node *root)
  {
    if (root == nullptr)
    {
      return;
    }

    print(root->left);
    print(root->right);
    cout << "root->val: " << root->val << endl;
  }
};

int main()
{
  sws;

  int input_ar[] = {1, 2, 3, 4, 5};
  int n = sizeof(input_ar) / sizeof(int);

  SegmentTreePersistency st = SegmentTreePersistency(n);

  for (int i = 0; i < n; i++)
  {
    arr[i] = input_ar[i];
  }

  Node *root = new Node(0);
  st.build(root, 0, n - 1);

  version[0] = root;
  version[1] = new Node(0);

  st.print(version[0]);
  cout << "Now version 1" << endl;
  st.update(version[0], version[1], 0, n - 1, 4, 1);
  st.print(version[1]);

  // cout << "Query" << endl;
  // cout << st.query(version[0], 0, n - 1, 0, 4) << endl;

  cout << "GO to clear" << endl;
  st.clear_versions();
  cout << "finish" << endl;
  return 0;
}
