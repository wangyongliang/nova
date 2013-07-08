#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define maxn 210
const long long mod = 1000000007LL;
long long dp[maxn][maxn];
long long solve(const string &A, const string &B) {
  for (int i = 0; i < maxn; i ++) {
    for (int j = 0; j < maxn; j ++) dp[i][j] = 0;
  }
  for (size_t i = 0; i < B.size(); i ++) {
    if (A[0] == B[i]) {
      dp[0][i] = 1;
    }
    if (i) dp[0][i] += dp[0][i - 1];
    dp[0][i] %= mod;
  }
  for (size_t i = 1; i < A.size(); i ++) {
    dp[i][0] = dp[i - 1][0];
    for (size_t j = 1; j < B.size(); j ++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      if (A[i] == B[j]) dp[i][j] += dp[i - 1][j - 1];
      dp[i][j] %= mod;
    }
  }
  return dp[A.size() - 1][B.size() - 1];
}
int main() {
  int t;
  cin >> t;
  string T, A, B;
  while (t -- ) {
    cin >> T;
    long long ans = 0;
    for (size_t i = 1; i < T.size(); i ++) {
      ans += solve(T.substr(i, T.size() - i), T.substr(0, i));
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
