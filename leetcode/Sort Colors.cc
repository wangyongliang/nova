class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      int a[3] = {0};
      for (int i = 0; i < n; i ++)
        a[A[i]] ++;
      int j = 0;
      for (int i = 0; i < 3; i ++) {
        while (a[i]) {
          A[j ++]  = i;
          a[i] --;
        }
      }
    }
};