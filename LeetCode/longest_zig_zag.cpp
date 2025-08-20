#include <bits/stdc++.h>

#define sws cin.tie(0)->sync_with_stdio(false);

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  int longestZigZag(TreeNode *root) {
    return 0;
  }
};

int main()
{
  sws;
  Solution solution = Solution();
  TreeNode *n = new TreeNode(2);
  TreeNode *n1 = new TreeNode(1, nullptr, n);

  int v;
  v = solution.longestZigZag(n1);
  cout << v << endl;

  return 0;
}
