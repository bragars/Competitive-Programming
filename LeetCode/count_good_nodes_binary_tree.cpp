class Solution
{
public:
  bool isAgoodNode(vector<int> &ar)
  {
    int lastElement = ar.at(ar.size() - 1);

    for (int element : ar)
      if (lastElement < element)
        return false;

    return true;
  }

  int preOrderTraversal(TreeNode *root, vector<int> &array, int *goodNodesCount)
  {
    if (!root)
      return 0;

    array.push_back(root->val);

    if (isAgoodNode(array))
      (*goodNodesCount)++;

    preOrderTraversal(root->left, array, goodNodesCount);
    preOrderTraversal(root->right, array, goodNodesCount);

    array.pop_back();
    return *goodNodesCount;
  }
  int goodNodes(TreeNode *root)
  {
    int goodNodesCount = 0;
    vector<int> array;

    preOrderTraversal(root, array, &goodNodesCount);
    return goodNodesCount;
  }
};
