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

#define maxn 40100
vector<int> types[maxn];
int main() {
  int n;
  scanf("%d", &n);
  bool a[53][53] = {0};
  char str[10];

  for (int i = 0; i < n; i ++) {
    scanf("%s", str);
    types[i].clear();
    for (int j = 0; j < 8; j += 2) {
      if (str[j] != '0') {
        types[i].push_back(int(str[j] - 'A' + 26 * (str[j + 1] == '+')));
      }

    }
    for (int j = 0; j < types[i].size(); j ++) {
      for (int k = 0; k < types[i].size(); k ++) {
        if (types[i][j] != types[i][k]) {
          a[types[i][k]][types[i][j]] = a[types[i][j]][types[i][k]] = 1;
        }
      }
    }
  }

  for (int k = 0; k < 26; k ++) {
    for (int i = 0; i < 52; i ++) {
      for (int j = 0; j < 52; j ++) {
        if (a[i][k] && a[k + 26][j]) {
          a[i][j] = 1;
        }
      }
    }
  }
  bool result = false;
  int cnt = 0;
  for (int i = 0; i < 26; i ++) {
    if (a[i][i + 26] || a[i][i] || a[i + 26][i + 26]) {
      // cout << i << endl;
      result = true;
    }
  }

  cout << (result? "unbounded": "bounded") << endl;
  return 0;
}
