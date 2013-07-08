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
#define maxn 100010
int a[maxn];
int dp[maxn];
int main() {
  // freopen("data.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &a[i]);
    dp[i] = 0;
  }

  dp[0] = 1;
  int count = 1;
  for (int i = 1; i < n; i ++) {
    if (a[i] > a[i - 1]) {
      count ++;
    } else {
      count = 1;
    }
    dp[i] = max(dp[i], count);
  }

  count = 1;
  long long result = 0LL;
  for (int i = n -2; i >= 0; i --) {
    if (a[i] > a[i + 1]) count++;
    else count = 1;
    dp[i] = max(dp[i], count);

  }
  for (int i = 0; i < n; i ++) {
    result += dp[i];
    // cout << dp[i] << " ";
  }
  // cout << endl;
  cout << result << endl;
  return 0;
}
