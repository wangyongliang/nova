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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      if (root == NULL)
        return INT_MIN;
      int result = root->val;
      result = max(result, maxPathSum(root->left));
      result = max(result, maxPathSum(root->right));
      int val = root->val;
      if (root->left != NULL)
        val = max(val, root->left->val + root->val);

      if (root->right)
        val = max(val, root->right->val + root->val);

      if (root->left && root->right)
        result = max(result, root->val + root->right->val + root->left->val);
      root->val = val;
      result = max(result, val);
      return result;
    }
};