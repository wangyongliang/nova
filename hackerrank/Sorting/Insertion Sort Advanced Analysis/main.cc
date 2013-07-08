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
int result;
int n;
const int maxn=100010;
int a[maxn];
int cnt[maxn];
int a_tmp[maxn];
int cnt_tmp[maxn];
// long long result;
void merge(int start, int end) {
  if (start < end) {
    int mid = (start + end)/ 2;
    merge(start, mid);
    merge(mid + 1, end);
    int first = start;
    int second = mid + 1;
    int cursor = start;
    while (first <= mid && second <= end) {
      if (a[second] < a[first]) {
        a_tmp[cursor] = a[second];
        cnt_tmp[cursor] = cnt[second] + mid - first + 1;
        cursor ++;
        second ++;
      } else {
        a_tmp[cursor] = a[first];
        cnt_tmp[cursor] = cnt[first];
        first ++;
        cursor ++;
      }
    }
    while (first <= mid) {
      a_tmp[cursor] = a[first];
      cnt_tmp[cursor] = cnt[first];
      cursor ++;
      first ++;
    }
    while (second <= end) {
      a_tmp[cursor] = a[second];
      cnt_tmp[cursor] = cnt[second];
      cursor ++;
      second ++;
    }
    for (cursor = end; cursor >= start; cursor --) {
      a[cursor] = a_tmp[cursor];
      cnt[cursor] = cnt_tmp[cursor];
      // if (cursor + 1 <= end) {
      //   cnt[cursor] += cnt[cursor + 1] + 1;
      // }
    }
  } else cnt[start] = 0;
}
int main() {
  // freopen("data.txt", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
      scanf("%d", &a[i]);
      cnt[i] = 0;
    }
    merge(0, n - 1);
    long long result = 0LL;
    for (int i = 0; i < n; i ++) {
      result += cnt[i];
    }
    cout << result << endl;
  }

  return 0;
}