
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
int main() {
  // freopen("data.txt", "r", stdin);
  int n, k;
  int a[200];
  cin >> n >> k;
  for (int i = 0; i < n; i ++)
    cin >> a[i];
  sort(a, a + n);
  long long sum = 0LL;
  for (int i = n - 1; i >= 0; i -= k) {
    for (int j = 0; j < k && i - j >= 0; j ++) {
      sum += a[i - j] * ((n - 1- i) / k + 1);
    }
  }
  cout << sum << endl;
  return 0;
}
