#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 2500

double p[2][MAXN][MAXN];

int main() {
  int zero = MAXN / 2;
  int t;
  cin >> t;
  int k, n;
  double l, r;
  for (int cas = 0; cas < t; cas ++) {
    cin >> k >> n >> l >> r;
    p[0][zero][zero] = 1.0;
    bool flag = 0;
    for (int i = 0; i < n; i ++) {
      for (int j = zero - i - 1; j <= zero + i + 1; j ++)
        for (int k = zero - i - 1; k <= zero + i + 1; k ++)
          p[1-flag][j][k] = 0.0;

      for (int j = zero - i; j <= zero + i; j ++) {
        for (int k = zero - i; k <= zero + i; k ++) {
          double &p_ = p[flag][j][k];
          if (p_ > 0.0) {
            p[1-flag][max(j,k)][k] += p_ * (1 - l - r); // stay
            p[1-flag][max(j, k + 1)][k + 1] += p_ * r; // right
            p[1-flag][j][k - 1] += p_ * l;  // left;
          }
        }
      }

      flag = 1 - flag;
    }
    double result = 0.0;
    for (int i = zero; i <= zero + n; i ++)
      for (int j = zero - n; j <= i; j ++)
        result += p[flag][i][j] * (i - zero);
    printf("%d %.4lf\n", k, result);

  }
  return 0;
}