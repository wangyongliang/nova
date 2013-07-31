#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAXN 41
#define MOD 1000000007
int dp[MAXN][MAXN][MAXN * MAXN];
int main() {
  int t;
  cin >> t;
  vector<int> a;
  int n;
  while (t--) {
    cin >> n;
    a.clear();
    int x;
    for (int i = 0; i < n; i ++) {
      cin >> x;
      if (x != -1)
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i <= n; i ++) {
      for (int j = 0; j <= n; j ++) {
        for (int k = 0; k <= n * n; k ++) {
          dp[i][j][k] = 0;
        }
      }
    }
    dp[0][0][0] = 1;
    int total = n * (n - 1) / 2;
    for (int i = 0; i < a.size(); i ++) {
      for (int j = 0; j < n; j ++) {
        for (int k = 0; k < total; k ++) {
          if (dp[i][j][k] > 0) {

          }
        }
      }
    }
  }
  return 0;
}