/*
 * B.cc
 * Copyright (C) 2013 yongliangwang <yongliangwang@wangyongliang-desktop>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstdio>

using namespace std;
int main() {
  int a, b, c,d;
  while (cin >> a >> b >> c >> d) {
    if (a == 0) {
      printf("0.0\n");
    } else if (b == 0) {
      printf("0.0\n");
    } else {
      double p = 1.0 * a / b;
      double q = 1.0 * c / d;
      printf("%.9lf\n", p / (1 - (1 - p) * (1 -q)));
    }
  }
  return 0;
}
