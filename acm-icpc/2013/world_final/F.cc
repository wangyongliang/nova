#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
  int n, k;
  // freopen("data.txt", "r", stdin);
  vector<int> a;
  scanf("%d%d", &n, &k); {
    a.clear();
    int x;
    for (int i = 0; i < 2 *n *k; i ++) {
      scanf("%d", &x);
      a.push_back(x);
    }
    sort(a.begin(), a.end());
    int min_ = a[1] - a[0];
    int max_ = a[a.size() - 1] - a[0];
    int mid_;
    int cnt = 0;
    int rest = 0;
    while (min_ < max_) {
      mid_ = (max_ + min_) >> 1;
      cnt = 0;
      rest = 0;
      for (int i = 0; i <  a.size(); i ++) {
        if ((i + 1 < a.size()) && (a[i + 1] - a[i] <= mid_) && cnt < n) {
          cnt ++;
          rest += k * 2 - 2;
          i ++;
        } else {
          if (rest > 0)
            rest --;
        }
      }
      if (cnt == n && rest == 0) {
        max_ = mid_;
      } else min_ = mid_ + 1;
    }
    printf("%d\n", min_);
  }
  return 0;
}