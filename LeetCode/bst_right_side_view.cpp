#include <bits/stdc++.h>
using namespace std;

#define sws cin.tie(0)->sync_with_stdio(false);

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> vec;

class Solution
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    if (root == nullptr)
      return vec;

    vec.push_back(root->val);
    rightSideView(root->right);

    return vec;
  }
};

int main()
{
  sws;
  Solution solution = Solution();
  TreeNode* n  = new TreeNode(2);
  TreeNode* n1 = new TreeNode(1, nullptr, n);

  vector<int> v;
  v = solution.rightSideView(n1);
  for (auto const i : v)
  {
    cout << i << endl;
  }

  return 0;
}
