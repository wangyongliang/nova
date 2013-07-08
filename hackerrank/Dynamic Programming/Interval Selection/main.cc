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
bool cmp(const pair<int, int> first, pair<int, int> second){
  return first.second < second.second;
}
int main() {
  int t;
  scanf("%d", &t);
  pair<int, int> a[1010];
  bool flag[1010];
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> x;
    x.clear();
    for (int i = 0; i <n; i ++) {
      scanf("%d%d", &a[i].first, &a[i].second);
      if (a[i].second < a[i].first) swap(a[i].second, a[i].first);
      x.push_back(a[i].second);
      flag[i] = 1;
    }
    sort(x.begin(), x.end());
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i ++) {
      int count = 0;
      for (int j = 0; j < n; j ++) {
        if (flag[j]) {
          if (a[j].first <= x[i] && a[j].second >= x[i]) {
            count++;
            if (count > 2) {
              flag[j] = 0;
            }
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i ++) ans += flag[i];
    cout << ans << endl;
  }
  return 0;
}