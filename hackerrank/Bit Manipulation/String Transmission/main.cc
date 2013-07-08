#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define maxn 1010
int dp[maxn][maxn];
int mod = 1000000007;
int combin[maxn][maxn] = {0};
int format(int number) {

  return (number % mod + mod) % mod;
}
int tmp[33][maxn][maxn];
int main() {

  int t;
  int len, m;
  int i, j, k;
  int zero;
  vector<int> divisor;

  combin[0][0] = 1;
  for (i = 1; i < maxn; i ++ ) {
    combin[i][0] = 1;
    for (j = 1; j <= i; j ++) {
      combin[i][j] = format( combin[i - 1][j - 1] + combin[i - 1][j]);
    }
  }

  cin >> t;
  while (t--) {
    cin >> len >> m;
    string str;
    divisor.clear();

    int ans = 0;
    for (i = 0; i <= m; i ++ )  {
      ans = format(ans + combin[len][i]);
    }
    for (i = 1; i < len ; i ++) {
      if (len % i == 0) divisor.push_back(i);
    }
    cin >> str;
    int len = str.size();
    bool flag = false;
    for (int ii = 0; ii < divisor.size(); ii++) {
      i = divisor[ii];
      if (len % i == 0) {
        for ( j = 0; j < len ; j ++) {
          for ( k = 0; k <= m ; k ++)
            dp[j][k] = 0;
        }
        zero = 0;
        for (j = 0; j < len; j += i)
          zero += (str[j] == '0');
        dp[0][zero] += 1;
        dp[0][len / i - zero] += 1;
        for ( j = 0; j + 1 < i; j ++) {
          zero = 0;
          for (k = j + 1; k < len; k += i)
            zero += (str[k] == '0');
          for (k = 0; k <= m; k ++) {
            if (dp[j][k] > 0) {
              dp[j + 1][k + zero] = format(dp[j + 1][k + zero] + dp[j][k]);
              dp[j + 1][k + len / i - zero] = format(dp[j + 1][k + len / i - zero] + dp[j][k]);
            }
          }

        }
        if (dp[i - 1][0] > 0) flag = true;
        for (int l = 0; l < ii; l ++) {
          if (divisor[ii] % divisor[l] == 0) {
            for (k = 0; k <= m; k ++) {
              dp[i - 1][k] = format(dp[i - 1][k] - tmp[l][divisor[l] - 1][k]);
            }
          }
        }
        for (j = 1; j <= m; j ++) {
          ans = format(ans - dp[i - 1][j]);
        }
        for (j = 0; j < i; j ++) {
          for (k = 0; k <= m; k ++)  tmp[ii][j][k] = dp[j][k];
        }
        //cout << ans << endl;
      }
    }
    if (flag) ans  = format(ans - 1);
    cout << ans << endl;
  }
  return 0;
}