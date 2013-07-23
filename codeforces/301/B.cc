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
#include <climits>

using namespace std;
int a[110][110];
int x[110], y[110];
int n, d;
int dist[110];
int grow[110];
bool check(long long mid) {
  for (int i = 0; i < n; i ++)
    dist[i] = -1;
  dist[0] = mid;
  bool updated = true;
  for (int i = 0; i < n && updated && dist[n - 1] < 0; i ++) {
    updated = false;
    for (int j = 0; j < n; j ++) {
      for (int k = 0; k < n; k ++) {
        if (j != k && dist[j] >= a[j][k]) {
          if (dist[k] < dist[j] - a[j][k] + grow[k]) {
            dist[k] = dist[j] - a[j][k] + grow[k];
            updated = true;
          }
        }
      }
    }
  }
  return dist[n - 1] >= 0;
}
int main() {
  // freopen("data.txt", "r", stdin);
  cin >> n >> d;
  for (int i = 1; i < n - 1; i ++)
    cin >> grow[i];
  grow[n - 1] = 0;
  grow[0] = 0;
  for (int i = 0; i < n; i ++)
    cin >> x[i] >> y[i];
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      if (i != j) {
        a[i][j] =(abs(x[i] - x[j]) + abs(y[i] - y[j])) * d;
      }
    }
  }
  long long min_ = 0;
  long long max_ = abs(x[n-1] - x[0]) + abs(y[n - 1] - y[0]);
  long long mid_;
  max_ *= d;

  while (min_ < max_) {
    mid_ = (min_ + max_) >> 1;
    if (check(mid_))
      max_ = mid_;
    else
      min_ = mid_ + 1;
  }
  cout << min_ << endl;
  return 0;
}