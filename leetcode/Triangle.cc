class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {

      for (int i = 1; i < triangle.size(); i ++) {
        for (int j = 0; j < triangle[i].size(); j ++) {
          int num = INT_MAX;
          if (j < triangle[i - 1].size())
            num = min(num, triangle[i][j] + triangle[i - 1][j]);
          if (j > 0)
            num = min(num, triangle[i][j] + triangle[i - 1][j - 1]);
          triangle[i][j] = num;
        }
      }
      int result = INT_MAX;
      for (int i = 0; i < triangle[triangle.size() - 1].size(); i ++) {
        result = min(result, triangle[triangle.size() - 1][i]);
      }
      return result;
    }
};