#include <iostream>
#include <cmath>
using namespace std;
double sum(long long x, long long y) {
  return pow(1.0 * y, x * 1.0 + 1) / ( y - 1);
}
bool solve(long long n, long long k, long long &x, long long &y) {
  if (k <= 1) return false;
  x = (long long)(log(1.0 * n * (k - 1) + 1)) - 1;
  if (fabs(sum(x, k) - n) > fabs(sum(x + 1, k)))
}
int main() {
  long long n;
  while (cin >> n) {
    long long x,y;
    long long tpx, tpy;
    for (int i = 1; i <= n / i; i ++) {
      if (n % i == 0) {
        if (i > 1) {
          tpx = (long long)(log(1.0 * n * ()))
        }
      }
    }
  }
  return 0;
}