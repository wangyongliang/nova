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
unsigned long long positive(int n) {
  if (n == 0) return 0;
  unsigned long long ans = 0LL;
  unsigned long long prefix = 0LL;
  unsigned int i = 1;
  unsigned int mask = 0;
  while(i <= n) {
    mask += i;
    i <<= 1;
  }
  i >>= 1;
  for (; i > 0; i >>= 1) {
    mask -= i;
    ans += prefix * i;
    if (n & i) {
      if ((n & mask) > 0)
        ans += (n & mask) ;
      ans ++;
      prefix = prefix * 2 + 1;
    } else prefix = prefix * 2;
  }
  return ans;
}

unsigned long long negative(int m) {
  if (m == 0)
    return 0;
  unsigned int n = m;
  unsigned long long ans = 0LL;
  unsigned long long prefix = 0LL;
  unsigned long long i = 1;
  unsigned long long mask = 0;
  while (i <= n) {
    mask += i;
    i <<= 1;
  }
  i >>= 1;

  unsigned long long upper = 1LL;
  unsigned long long lower = i;
  unsigned long long tmp;
  for (; i > 0; i >>= 1) {
    mask -= i;
    ans += (upper - 1 - prefix) * lower;
    if (n & i) {
      tmp = n & mask;
      ans += (lower - 1 - tmp);
      ans ++;
      prefix = prefix * 2 + 1;
    } else {
      ans += lower;
      prefix = prefix * 2;
    }
    lower >>= 1;
    upper <<= 1;
  }
  return ans;
}
int main() {
  int n;
  int x, y;
  int t;
  // freopen("data.txt", "r", stdin);
  // freopen("ans.txt", "w", stdout);
  cin >> t;
  while (t--) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    unsigned long long result = 0;
    if (x >= 0 && y >= 0) {
      result = positive(y);
      if (x > 0) {
        result -= positive(x - 1);
      }
    } else if (y >= 0 && x < 0) {
      result += positive(y);
      result += negative(x);
    } else {
      result += negative(x);
      y ++;
      result -= negative(y);
    }
    cout << result << endl;
  }
  return 0;
}
