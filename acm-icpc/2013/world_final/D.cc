#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const unsigned long long maxn = (1LL<<63);
bool flag[1000] = {0};
vector<int> prime;

unsigned long long c[100][100];
void init() {
  int total = 1;
  for (int i = 2; i < 1000 ; i ++) {
    if (flag[i] == 0) {
      prime.push_back(i);
      for (int j = i * 2; j < 1000; j += i) flag[j] = 1;
    }
  }

  for (int i = 0; i < 100; i ++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j ++) {
      c[i][j] = 0;
      if (i > 0 && j > 0)
        c[i][j] += c[i-1][j-1];
      if (i > 0)
        c[i][j] += c[i-1][j];
    }
  }
}

map<unsigned long long, unsigned long long> cache;
int cnt[210];
const int max_n = 65;
void dfs(int deep, unsigned long long now, int max_, int n) {
  if (now <= 0)
    return;
  if (max_ == 0) {
    unsigned long long total = 1;
    for (int i = 0; i < deep; i ++) {
      if (total <= maxn / c[n][cnt[i]]) {
        total *= c[n][cnt[i]];
        n -= cnt[i];
      }
      else {
        return;
      }
    }
    if (cache[total] == 0 || cache[total] > now)
      cache[total] = now;
    return;
  }

  unsigned long long tmp = 1LL;
  for (int i = 0; (i <= max_) && (tmp  <= maxn / now) ; i ++) {
    cnt[deep] = i;
    dfs(deep + 1, now * tmp, i, n + i);
    if (tmp <= maxn / prime[deep])
      tmp *= prime[deep];
    else
      return;
  }
}
int main() {
  // cout << maxn << endl;
  init();
  // cout << prime.size() << endl;
  dfs(0,1,100,0);
  // cout << cache.size() << endl;
  unsigned long long m;
  cache[1] = 2;

  while (cin >> m) {
    cout << m << " " << cache[m] << endl;
  }
  return 0;
}
