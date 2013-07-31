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
    TreeNode *sortedArrayToBST(vector<int> &num) {
      if (num.size() == 0)
        return NULL;
      return construct(num, 0, num.size() - 1);
    }

    TreeNode * construct(vector<int> &num, int start, int end) {
      if (start == end)
        return new TreeNode(num[start]);
      else {
        int mid = (start + end + 1) >> 1;
        TreeNode *root = new TreeNode(num[mid]);
        if (start <= mid - 1)
          root->left = construct(num, start, mid - 1);
        if (mid + 1 <= end)
          root->right = construct(num, mid + 1, end);
        return root;
      }
    }
};