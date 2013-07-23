class Solution {
public:
    bool canJump(int A[], int n) {
        int position = A[0];
        for (int i = 0; i < n && i <= position; i ++) {
          position = max(position, A[i] + i);
        }
        return position >= n - 1;
    }
};