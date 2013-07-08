#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN  1000000

int mod = 1000000007;
long long a[1010];
long long dp[1010][3];
long long pow(long long n, long long k) {
  if (k == 0) return 1LL;
  else {
    long long m = pow(n, k / 2);
    return m % mod * m % mod * (k % 2 ? n : 1) % mod;
  }
}
int main() {
  int t;
  a[0] = 1;
  for (int i = 1; i <= 1000; i ++) {
    a[i] = 0;
    for (int j = 1; j <= 4; j ++) {
      if (i - j >= 0) a[i] += a[i - j];
      a[i] %= mod;
    }
  }

  cin >> t;
  int n, m;

  for (int cas = 1; cas <= t; cas ++) {
    cin >> n >> m;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= m; i ++) {
      dp[i][1] = dp[i][0] = pow(a[i], n * 1LL);
      for (int j = 1; j < i; j ++) {
        dp[i][1] -= dp[j][0] * dp[i - j][1];
        dp[i][1] = (dp[i][1] % mod + mod) % mod;
      }

    }
    cout << dp[m][1] << endl;
  }
  return 0;
}