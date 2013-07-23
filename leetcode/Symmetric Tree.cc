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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
          return true;
        else
          return compare(root->left, root->right);
    }
    bool compare(TreeNode *left, TreeNode *right) {
      if (left == NULL || right == NULL) {
        if (left == NULL && right == NULL)
          return true;
        else
          return false;
      }
      if (left->val != right->val) return false;
      return compare(left->left, right->right) & compare(left->right, right->left);
    }
};