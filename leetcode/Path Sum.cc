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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
          return false;
        sum -= root->val;
        if (sum == 0 && (root->left == NULL && root->right == NULL))
          return true;
        return hasPathSum(root->left, sum) ||
          hasPathSum(root->right, sum);
    }
};