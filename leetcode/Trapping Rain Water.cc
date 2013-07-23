class Solution {
public:
    int trap(int A[], int n) {
      stack<int> stack_;
      int result = 0;
      int height;
      int diff;
      for (int i = 0; i < n; i ++) {
        while (stack_.size() > 0 && A[stack_.top()] <= A[i]) {
          height = A[stack_.top()];
          stack_.pop();
          if (stack_.size() > 0) {
            diff = min(A[stack_.top()], A[i]) - height;
            result += (i - stack_.top() - 1) * diff;
          }
        }
        stack_.push(i);
      }
      return result;
    }
};
