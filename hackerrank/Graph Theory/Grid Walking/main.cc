#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define PS system("pause")
#define MOD 1000000007
long long sum[20][400];
long long dp[400][410];
long long c[400][400] = {0};
int main() {
  int t;
  c[0][0] = 1;
  for (int i = 1; i < 400; i ++) {
    c[i][0] = c[i][i] = 1;

    for (int j = 1; j < i; j ++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }

  cin >> t;
  //    freopen("old.txt","w",stdout);
  while (t--) {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 20; i ++) {
      for (int j = 0; j < 400; j ++) sum[i][j] = 0;
    }
    vector<int>x;
    x.clear();
    vector<int>d;
    d.clear();
    for (int i = 0; i < n; i ++) {
      int tx;
      cin >> tx;
      x.push_back(tx - 1);
    }
    for (int i = 0; i < n; i ++) {
      int td;
      cin >> td;
      d.push_back(td);
    }

    for (int i = 0; i < n; i ++) {
      for (int j = 0; j < d[i]; j ++) dp[0][j] = 0;
      dp[0][x[i]] = 1;
      for (int k = 0; k <= m; k ++ ) {
        for (int j = 0; j < d[i]; j ++) dp[k + 1][j] = 0;
        for (int j = 0; j < d[i]; j ++) {
          //if (dp[k][j])
          {
            if (j - 1 >=   0) dp[k + 1][j - 1] = ( dp[k + 1][j - 1] + dp[k][j]) % MOD;
            if (j + 1 < d[i]) dp[k + 1][j + 1] = ( dp[k + 1][j + 1] + dp[k][j]) % MOD;
          }
        }
        sum[i][k] = 0;
        for (int j = 0; j < d[i]; j ++) sum[i][k] = (sum[i][k] + dp[k][j]) % MOD;
      }
    }
    for (int j = 0; j <= m; j ++) {
      dp[0][j] = sum[0][j];
    }

    for (int i = 1; i < n; i ++) {
      for (int j = 0; j <= m; j ++) dp[i][j] = 0;
      for (int j = 0; j <= m; j ++) {
        for (int k = 0; k + j <= m; k ++) {
          dp[i][j + k] = (dp[i][j + k] + ((dp[i - 1][j] % MOD * sum[i][k]) % MOD ) * c[j + k][k] % MOD) % MOD;
        }
      }
    }
    long long ans = dp[n - 1][m];
    cout << ans << endl;
  }
  //    PS;
  return 0;
}
