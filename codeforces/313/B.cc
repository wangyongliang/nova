/*
 * B.cc
 * Copyright (C) 2013 yongliangwang <yongliangwang@wangyongliang-desktop>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 1000000
char buffer[maxn];
int count[maxn];
int main() {

  while (scanf("%s", buffer + 1) != EOF) {
    for (int i = 1; buffer[i]; i ++) {
      count[i] = count[i - 1];
      if (buffer[i] == buffer[i + 1]) count[i] ++;
    }
    int q;
    scanf("%d", &q);
    while (q --) {
      int l, r;
      scanf("%d%d",&l,&r);
      cout << count[r - 1] - count[l - 1] << endl;
    }
  }
  return 0;
}

