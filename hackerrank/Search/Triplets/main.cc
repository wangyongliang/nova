// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang
// Problem: https://www.hackerrank.com/challenges/triplets
// Editor:
// Suppose we already have an array cnt2, cnt2[i] means the size of set {j| j > i and a[j] > a[i]}
// Calculate cnt3, cnt3[i] means means the size of set {j, k | j > k > i and a[j] > a[k] > a[i]}
// obviously, cnt3[i] = sum(cnt2[j] where j > i and a[j] > a[i]),
// cnt2 and cnt3 can be calculated by merge sort,
// remove the duplicate element: since each element will be present at most twice, suppose element e
// is present at position i and j where i < j, before calculate cnt3, we need assign cnt2[i] = cnt2[i] - cnt2[j],

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
int n;
const int maxn=100010;
int a[maxn];
int b[maxn];
int rk[maxn];
long long cnt[maxn];
long long cnt_tmp[maxn];
int a_tmp[maxn];
long long result_tmp[maxn];
long long result[maxn];
long long sum[maxn];
// long long result;
void merge(int start, int end) {
  if (start < end) {
    int mid = (start + end)/ 2;
    merge(start, mid);
    merge(mid + 1, end);
    int first = start;
    int second = mid + 1;
    int cursor = start;
    for (int i = end; i >= mid + 1; i --) {
      sum[i] = cnt[i];
      if (i + 1 <= end) sum[i] += sum[i + 1];
    }
    while (first <= mid && second <= end) {
      if (b[a[first]] < b[a[second]]) {
        a_tmp[cursor] = a[first];
        result_tmp[cursor] = result[first] + sum[second];
        cnt_tmp[cursor] = cnt[first];
        cursor ++;
        first ++;
      } else {
        a_tmp[cursor] = a[second];
        result_tmp[cursor] = result[second];
        cnt_tmp[cursor] = cnt[second];
        second ++;
        cursor ++;
      }
    }
    while (first <= mid) {
      a_tmp[cursor] = a[first];
      result_tmp[cursor] = result[first];
      cnt_tmp[cursor] = cnt[first];
      cursor ++;
      first ++;
    }
    while (second <= end) {
      a_tmp[cursor] = a[second];
      result_tmp[cursor] = result[second];
      cnt_tmp[cursor] = cnt[second];
      cursor ++;
      second ++;
    }
    for (cursor = end; cursor >= start; cursor --) {
      a[cursor] = a_tmp[cursor];
      result[cursor] = result_tmp[cursor];
      cnt[cursor] = cnt_tmp[cursor];
    }
  } else result[start] = 0;
}

bool cmp(int x, int y) {
  if (b[x] != b[y]) return b[x] < b[y];
  else return x < y;
}
void reset(int a[]) {
  for (int i = 0; i < n; i ++) a[i] = i;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i ++) {
    scanf("%d", &b[i]);
    a[i] = i;
  }
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i ++) {
    if (i + 1 < n && b[a[i]] == b[a[i + 1]]) {
      cnt[a[i + 1]] = 1LL;
      i ++;
    } else cnt[a[i]] = 1LL;
  }

  reset(a);
  merge(0, n - 1);

  // Remove duplicate element for cnt2
  int first, second;
  for (int i = 0; i < n; i ++) {
    if (i + 1 < n && b[a[i]] == b[a[i + 1]]) {
      first = i, second = i + 1;
      if (a[i] > a[i + 1]) swap(first, second);
      cnt[a[second]] = result[second];
      cnt[a[first]] = result[first] - result[second];
      i ++;
    } else {
      cnt[a[i]] = result[i];
    }
  }

  // Calculate cnt3 via cnt2
  reset(a);
  merge(0, n - 1);

  // Sum cnt3
  long long ans = 0LL;
  for (int i = 0; i < n; i ++) {
    if (i + 1 < n && b[a[i]] == b[a[i + 1]]) {
      first = i, second = i + 1;
      if (a[i] > a[i + 1]) swap(first, second);
      ans += result[first];
      i ++;
    } else ans += result[i];
  }
  cout << ans << endl;
  return 0;
}