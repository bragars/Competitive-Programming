class Solution
{
public:
  void preOrderTraversal(TreeNode *root, vector<int> &array, vector<int> &depths, int *depth)
  {
    if (!root)
      return;

    array.push_back(root->val);

    preOrderTraversal(root->left, array, depths, depth);
    preOrderTraversal(root->right, array, depths, depth);

    depths.push_back(array.size());
    array.pop_back();

    return;
  }

  int maxDepth(TreeNode *root)
  {
    int depth = 0;
    vector<int> array, depths;

    if (!root)
      return 0;

    preOrderTraversal(root, array, depths, &depth);

    depth = depths.at(0);

    for (int i = 0; i < depths.size(); i++)
      if (depth < depths.at(i))
        depth = depths.at(i);

    return depth;
  }
};
