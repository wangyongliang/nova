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
#include <map>
using namespace std;

vector<int> a;
int calc(int start, int mid, int end) {
  int result = 0;
  int min1, min2;
  min1 = min2 = 1000;
  for (int i = start; i <= mid; i ++) {
    min1 = min(min1, a[i]);
  }
  for (int i = mid + 1; i <= end; i ++ ) min2 = min(min2, a[i]);
  if (min1 < min2) {
    result = end - mid;
    for (int i = start; i <= mid; i ++) result += (a[i] > min2);
  } else {
    result = mid - start + 1;
    for (int i = mid + 1; i <= end; i ++) result += (a[i] > min1);
  }
  return result;
}
int s[600][600];
int dp[600];
int flag[600];
int solve(int i, int j) {
  if (s[i][j] != -1)
    return s[i][j];
  if (i == j) {
    s[i][j] = 0;
    return 0;
  }
  s[i][j] = 100000;
  int tmp;
  vector<int> v;
  v.clear();
  for (int k = i; k <= j; k ++) v.push_back(a[k]);
  sort(v.begin(), v.end());
  tmp = 0;
  map<int, int> mp;
  for (int k = 0; k < v.size(); k ++) {
    mp[v[k]] = v.size() - k -1;
  }
  for (int k = j; k >= i; k --) {
    v[k - i] = a[k];
    if (k + 1 <= j)
      v[k - i] = min(v[k - i], v[k - i + 1]);
  }
  int min_ = 10000;
  for (int k = i; k < j; k ++) {
    min_ = min(min_, a[k]);
    tmp = solve(i, k) + solve(k + 1, j) + mp[max(min_, v[k + 1 - i])] + 1;
    s[i][j] = min(s[i][j], tmp);
  }
  return s[i][j];
}

int main() {

  int n;
  int current = 1;
  cin >> n;
  int x;
  for (int i = 0; i <n; i++) {
    cin >> x;
    a.push_back(x);
    dp[i] = -1;
    flag[i] = 0;
    for (int j = 0; j < n; j ++)
      s[i][j] = -1;
  }

  int sum_;
  int max_;
  max_ = -1;
  sum_ = 0;

  for (int i = 0; i < a.size(); i ++) {
    if (flag[a[i]] != current) {
      flag[a[i]] = current;
      sum_ ++;
      max_ = max(max_, a[i]);
    } else {
      break;
    }
    if (sum_ == max_) {
      dp[i] = solve(0, i);
    }
  }

  for (int i = 0; i < a.size(); i ++) {
    if (dp[i] != -1 && i + 1 < a.size()) {
      current ++;
      sum_ = 0;
      max_ = -1;
      for (int j = i + 1; j < a.size(); j ++) {
        if (flag[a[j]] != current) {
          flag[a[j]] = current;
          sum_ ++;
          max_ = max(max_, a[j]);
        } else {
          break;
        }
        if (max_ == sum_) {
          int tmp =dp[i] + solve(i + 1, j);
          if (dp[j] == -1 || dp[j] > tmp)
            dp[j] = tmp;
        }
      }
    }
  }
  if (dp[a.size() - 1] == -1)
    cout <<"impossible" << endl;
  else
    cout << dp[a.size() - 1] << endl;
  return 0;
}
