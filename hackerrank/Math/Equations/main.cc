// Solution: suppose we already know the value of x, so y = k*x / (x - k) where k = N!
// y = (k*(x - k) - k * k) / (x - k), so k * k % (x - k) = 0 and x > k,
// the number of x is the divisor of k * k

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
#define maxn 1000010
#define mod 1000007
int prime[maxn] = {0};
int cnt[maxn] = {0};
int main() {
  long long ans = 1LL;
  int n;
  cin >> n;

  for (int i = 2; i <= maxn /i; i ++) {
    if (!prime[i]) {
      prime[i] = i;
      for (int j = i * i ; j < maxn; j += i)
        prime[j] = i;
    }
  }
  for (int i = 2; i <= n; i ++) {
    int m = i;
    while (m > 1) {
      if (prime[m] == 0) prime[m] = m;
      cnt[prime[m]] += 2;
      m /= prime[m];
    }
  }
  for (int i = 0; i <= n; i ++) {
    ans = ans * (1 + cnt[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
