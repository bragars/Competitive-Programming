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

  void in_order(TreeNode *root) {
    cout << root->val;
  }

  void pre_order(TreeNode *root) {
    cout << root->val;
  }

  void post_order(TreeNode *root) {
    cout << root->val;
  }

  TreeNode* minimum(TreeNode *root) {
    cout << root->val;
  }

  TreeNode* maximum(TreeNode *root) {
    cout << root->val;
  }

  TreeNode* successor(TreeNode *root) {
    cout << root->val;
  }

  TreeNode* predecessor(TreeNode *root) {
    cout << root->val;
  }

  int count_nodes(TreeNode *root) {
    cout << root->val;
  }

  int height(TreeNode *root) {
    cout << root->val;
  }

  bool isBST(TreeNode *root) {
    cout << root->val;
  }

  bool range_query(TreeNode *root) {
    cout << root->val;
  }

  bool balancing(TreeNode *root) {
    cout << root->val;
  }

  void delete_tree(TreeNode *root)
  {
    if (root == nullptr)
      return;

    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
  }

  TreeNode *insert(TreeNode *root, int val)
  {
    if (root == nullptr)
      return new TreeNode(val);

    if (val > root->val)
      root->right = insert(root->right, val);
    else
      root->left = insert(root->left, val);

    return root;
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

  void print_tree(TreeNode *root)
  {
    if (root == nullptr)
      return;

    cout << root->val << " ";
    print_tree(root->left);
    print_tree(root->right);
  }

public:
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
      return NULL;

    if (key > root->val)
    {
      root->right = deleteNode(root->right, key);
      return root;
    }
    else if (key < root->val)
    {
      root->left = deleteNode(root->left, key);
      return root;
    }

    if (root->left == nullptr)
    {
      TreeNode *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == nullptr)
    {
      TreeNode *temp = root->left;
      delete root;
      return temp;
    }
    else
    {
      TreeNode *prev = root;
      TreeNode *suc = root->right;

      while (suc->left != NULL)
      {
        prev = suc;
        suc = suc->left;
      }

      if (prev != root)
        prev->left = suc->right;
      else
        prev->right = suc->right;

      root->val = suc->val;
      delete suc;
      return root;
    }
  }
};

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

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
  cout << "begin print: " << endl;
  solution.print_tree(root);
  TreeNode *result = solution.deleteNode(root, val);

  if (result == NULL)
  {
    cout << "[]" << endl;

    solution.delete_tree(root);
    return 0;
  }

  cout << "second print: " << endl;
  solution.print_tree(result);
  solution.delete_tree(root);

  return 0;
}
