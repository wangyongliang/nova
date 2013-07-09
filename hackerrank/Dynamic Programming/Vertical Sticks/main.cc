
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
int main() {
  // freopen("data.txt", "r", stdin);
  int t;
  cin >> t;
  int a[100];
  int n;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i ++)
      cin >> a[i];
    double result = 0.0;
    for (int i = 0; i < n; i ++) {
      int cnt = 0;
      for (int j = 0; j < i; j ++)
        cnt += (a[i] > a[j]);
      double p = 1.0/n;
      for (int j = 0; j <= cnt; j ++) {
        result += p * (j + 1) ; // set at the begin
        if (n - 1 - j > 0) {
          result += p * (n - 1 - cnt) / (n - 1 - j) * (n - 1 - j) * (j + 1); // set a higher before
          p *= 1.0 * (cnt - j) / (n - 1 - j);
        } else break;
      }
    }
    printf("%.2lf\n", result);
  }
  return 0;
}