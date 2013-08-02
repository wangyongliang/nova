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
double cross(pair<long long, long long> x, pair<long long, long long> y) {
  return (y.first - x.first) / (x.second - y.second);
}
#define DOUBLE_MAX 1e100
#define MAXN 100010
pair<long long, long long> stack_[MAXN];
long long a[MAXN];
long long b[MAXN];
long long ans[MAXN];

int main() {
  // freopen("data.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i ++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i ++) {
    cin >> b[i];
  }
  int start = 0;
  int end = 1;

  stack_[0] = make_pair(0, b[0]);
  double x1, x2;
  pair<long long, long long> line;

  x1 = 0.0;
  x2 = 1e100;
  for (int i = 1; i < n; i ++) {
    while (start + 1 < end && a[i] > x2 + 1e-5) {
      x1 = x2;
      start ++;
      if (start + 1 < end)
        x2 = cross(stack_[start], stack_[start + 1]);
      else
        x2 = 1e100;
    }

    ans[i] = stack_[start].first + a[i] * stack_[start].second;

    line.first = ans[i];
    line.second = b[i];

    while (end - 2 >= start) {
      x1 = cross(stack_[end - 1], line);
      x2 = cross(stack_[end - 2], stack_[end - 1]);
      if (x1 < x2)
        end --;
      else
        break;
    }
    stack_[end ++] = line;
    if (start + 1 < end)
      x2 = cross(stack_[start], stack_[start + 1]);
  }
  cout <<ans[n - 1]<< endl;
  return 0;
}