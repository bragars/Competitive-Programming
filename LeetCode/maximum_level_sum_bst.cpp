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
  int maxLevelSum(TreeNode *root)
  {
    if (!root)
      return 0;

    int max = INT_MIN;
    queue<TreeNode *> q;

    int level = 0;

    q.push(root);
    int current_level = 0;

    while (!q.empty())
    {
      int size = q.size();
      int level_sum = 0;

      for (int i = 0; i < size; i++)
      {
        TreeNode *node = q.front();
        q.pop();
        level_sum += node->val;

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      current_level++;

      if (level_sum > max)
      {
        max = level_sum;
        level = current_level;
      }
    }
    return level;
  }
};

int main()
{
  sws;
  Solution solution = Solution();
  TreeNode *n = new TreeNode(2);
  TreeNode *n1 = new TreeNode(1, nullptr, n);

  int v;
  v = solution.maxLevelSum(n1);
  cout << v << endl;

  return 0;
}

// BFS - uses queue
// DFS - uses stack
