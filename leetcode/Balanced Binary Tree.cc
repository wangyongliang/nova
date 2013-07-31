/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
      if (root == NULL)
        return true;
      bool result = isBalanced(root->left) && isBalanced(root->right);
      int left_depth = root->left == NULL? 0: root->left->val;
      int right_depth = root->right == NULL? 0 : root->right->val;
      result = result & (abs(left_depth - right_depth) <= 1);
      root->val = max(left_depth, right_depth) + 1;
      return result;
    }
};