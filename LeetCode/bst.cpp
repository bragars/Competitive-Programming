#include <iostream>
#include <vector>

using namespace std;

#define ll long long

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
  TreeNode *searchBST(TreeNode *root, int val)
  {
    if (root == NULL || val == root->val)
      return root;

    if (val > root->val)
      return searchBST(root->right, val);

    return searchBST(root->left, val);
  }

  void delete_tree(TreeNode *root)
  {
    if (root == nullptr)
      return;

    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
  }

  TreeNode *create_tree(vector<int> &tree_values, int i, int n)
  {
    if (i >= n || tree_values.empty())
      return nullptr;

    TreeNode *root = new TreeNode(tree_values[i]);
    root->left = create_tree(tree_values, 2 * i + 1, n);
    root->right = create_tree(tree_values, 2 * i + 2, n);

    return root;
  }

  void print_sub_tree(TreeNode *root)
  {
    if (root == nullptr)
      return;

    cout << root->val << " ";
    print_sub_tree(root->left);
    print_sub_tree(root->right);
  }
};

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Input: root = [4,2,7,1,3], val = 5
  int n;
  cin >> n;

  vector<int> tree_values(n);

  for (size_t i = 0; i < n; i++)
  {
    cin >> tree_values[i];
  }

  int val;
  cin >> val;

  Solution solution = Solution();

  TreeNode *root = solution.create_tree(tree_values, 0, tree_values.size());
  TreeNode *result = solution.searchBST(root, val);

  if (result == NULL)
  {
    cout << "[]" << endl;

    solution.delete_tree(root);
    return 0;
  }

  solution.print_sub_tree(result);
  solution.delete_tree(root);

  exit(0);
  return 0;
}
