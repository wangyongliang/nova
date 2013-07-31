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
const long long mod = 1000000007LL;
long long pow2(int n) {
  if (n == 0)
    return 1;
  else {
    long long ans = pow2(n / 2);
    ans = ans * ans % mod;
    if (n & 1) {
      ans *= 2;
    }
    return ans % mod;
  }
}
int main() {
  // freopen("data.txt", "r", stdin);
  string line;
  cin >> line;
  long long ans = 0LL;
  long long tmp;
  for (int i = 0; i < line.size(); i ++) {
    if (line[i] == '1') {
      tmp = pow2(i) * pow2(line.size() - i - 1) % mod * pow2(line.size() - i - 1);
      ans = (ans + tmp) % mod;
    }
  }
  cout << ans << endl;
  return 0;
}