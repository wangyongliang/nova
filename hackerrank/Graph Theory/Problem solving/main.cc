// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github:https://github.com/wangyongliang
// Solution:

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
#define maxn 310
vector<int>a[maxn];
bool visit[maxn];
int match[maxn];
int n;
bool find(int x) {
  for (int i = 0; i < a[x].size(); i ++) {
    if (!visit[a[x][i]]) {
      visit[a[x][i]] = true;
      if (match[a[x][i]] == -1 || find(match[a[x][i]])) {
        match[a[x][i]] = x;
        return true;
      }
    }
  }
  return false;
}

int main() {
  // freopen("data.txt", "r", stdin);
  int t;
  cin >> t;
  int k;
  int d[maxn];
  while (t --) {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) {
      a[i].clear();
      cin >> d[i];
      match[i] = -1;
    }
    for (int i = 0; i < n; i ++) {
      for (int j = i + 1; j < n; j ++) {
        if (abs(d[i] - d[j])  >= k) {
          a[i].push_back(j);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < n; i ++) {
      memset(visit, false, sizeof(bool) * maxn);
      res += find(i);
    }
    cout << n - res << endl;
  }
  return 0;
}