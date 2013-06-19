/*
 * main.cc
 * Copyright (C) 2013 yongliangwang <yongliangwang@wangyongliang-desktop>
 *
 * Distributed under terms of the MIT license.
 */

#include <cstdio>
#include <algorithm>

#define maxn 1000010
using namespace std;
pair<int, int> a[maxn];

pair<int, int> find(int x) {
  if (a[x].first == x) return a[x];
  else {
    pair<int, int> ans = find(a[x].first);
    a[x].first = ans.first;
    a[x].second += ans.second;
    return a[x];
  }
}

int main() {
  int t;
  scanf("%d", &t);
  bool res;
  for (int cas = 1; cas <= t; cas ++) {
    int n,m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) {
      a[i].first = i;
      a[i].second = 0;
    }
    res = false;

    pair<int, int> fx, fy;
    while (m --) {
      int x, y;
      scanf("%d%d", &x, &y);
      fx = find(x);
      fy = find(y);
      if (fx.first == fy.first) {
        if (((fx.second - fy.second) % 2 + 2) % 2 == 0) {
          res = true;
        }
      } else {
        a[fx.first].first = fy.first;
        a[fx.first].second = (1 - fx.second - fy.second) % 2 + 2;
      }
    }
    printf("Scenario #%d:\n", cas);
    printf("%s\n\n", res? "Suspicious bugs found!": "No suspicious bugs found!");
  }
  return 0;
}



