/*
 * A.cc
 * Copyright (C) 2013 yongliangwang <yongliangwang@wangyongliang-desktop>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
using namespace std;

int main() {
  long long n;
  while (cin >> n) {
    if (n >= 0) {
      cout << n << endl;
    } else {
      n = -n;
      n = min(n/10, n / 100 * 10 + n % 10);
      n = -n;
      cout << n << endl;
    }
  }
  return 0;
}



