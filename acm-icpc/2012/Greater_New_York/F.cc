#include <iostream>
#include <cstdio>
#include <map>
#include <ctime>
using namespace std;

// #define MAXN (1 << 20)
// long long dp[MAXN][20][2] = {0};
int main() {
  // for (int i = 0; i < 20; i ++) {
  //   for (int j = 0; j < 20; j ++) {
  //     if (i != j) {
  //       dp[(1<<i) | (1<<j)][j][i < j] = 1;
  //     }
  //   }
  //   // dp[1<<i][i][0] = dp[1<<i][i][1] = 1;
  // }
  // for (int i = 0; i < MAXN; i ++) {
  //   for (int j = 0; j < 20; j ++) {
  //     if (dp[i][j][0] > 0) {
  //       for (int k = j + 1; k < 20; k ++) {
  //         if ((i & (1<<k)) == 0)
  //           dp[i + (1 << k)][k][1] += dp[i][j][0];
  //       }
  //     }
  //     // if ((1<<j) == i) continue;
  //     if (dp[i][j][1] > 0) {
  //       for (int k = 0; k < j; k ++) {
  //         if ((i & (1<<k)) == 0)
  //           dp[i + (1<<k)][k][0] += dp[i][j][1];
  //       }
  //     }
  //   }
  // }

  long long result[21] = {1LL, 1LL, 2LL, 4LL, 10LL, 32LL, 122LL, 544LL, 2770LL,
    15872LL, 101042LL, 707584LL, 5405530LL, 44736512LL, 398721962LL, 3807514624LL,
    38783024290LL, 419730685952LL, 4809759350882LL, 58177770225664LL, 740742376475050LL};

  // for (int i = 1; i <= 20; i ++) {
  //   result[i] = 0;
  //   for (int j = 0; j < i; j ++) {
  //     result[i] += dp[(1<<i) - 1][j][0] + dp[(1<<i) - 1][j][1];
  //   }
  // }

  // cout << "{";
  // for (int i = 0; i < 21; i ++) {
  //   cout << result[i] << "LL";
  //   if (i < 20) cout << ", ";
  // }
  // cout << "}" << endl;

  int n;
  cin >> n;
  while (n --) {
    int id, m;
    cin >> id >> m;
    cout << id << " " << result[m] << endl;
  }

  return 0;
}