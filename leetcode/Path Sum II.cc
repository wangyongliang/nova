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
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    result_.clear();
    if (root != NULL) {
      stack_ = new int[getDepth(root) + 10];
      findPath(root, sum);
      delete [] stack_;
    }
    return result_;
  }

  void findPath(TreeNode *root, int sum) {
    sum -= root->val;
    stack_[count++] = root->val;
    if (sum == 0) {
      if (root->left == NULL && root->right == NULL) {
        vector<int> tmp(stack_, stack_ + count);
        result_.push_back(tmp);
      }
    } else {
      findPath(root->left, sum);
      findPath(root->right, sum);
    }
    count --;
  }

  int getDepth(TreeNode *root) {
    if (root == NULL)
      return 0;
    else
      return max(getDepth(root->left), getDepth(root->right)) + 1;
  }
private:
  vector<vector<int> > result_;
  int *stack_;
  int count;
};