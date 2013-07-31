class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      if (s1 == "" && s2 == "" && s3 == "")
        return true;
      if (s1.size() + s2.size() != s3.size())
        return false;

      int ** dp;
      dp = new int*[s3.size()];
      for (int i = 0; i < s3.size(); i ++) {
        dp[i] = new int[s1.size() + 1];
        for (int j = 0; j <= s1.size(); j ++)
          dp[i][j] = 0;
      }
      if (s1.size() > 0 && s3[0] == s1[0])
        dp[0][1] = 1;
      if (s2.size() > 0 && s3[0] == s2[0])
        dp[0][0] = 1;

      for (int i = 0; i + 1 < s3.size(); i ++) {
        for (int j = 0; j <= s1.size(); j ++) {
          if (dp[i][j] > 0) {
            if (j < s1.size() && s3[i + 1] == s1[j]) {
              dp[i + 1][j + 1] = 1;
            }
            int k = (i + 1) - j;
            if (k < s2.size() && s3[i + 1] == s2[k]) {
              dp[i + 1][j] = 1;
            }
          }
        }
      }

      bool result = dp[s3.size() - 1][s1.size()];

      for (int i = 0; i < s3.size(); i ++) {
        delete [] dp[i];
      }
      delete [] dp;
      return result;
    }

};