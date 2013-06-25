#include<stdio.h>
#include<map>
#include<string>
using namespace std;
map<string, int> mp;
int a[1000][1000];
int n, pre[1010];
int bfs() {
  int i;
  int q[1010], st, en;
  st = en = 0;
  q[en++] = 0;
  for (i = 0; i < n; i++) pre[i] = -1;
  while (st < en) {
    int x = q[st++];
    for (i = 0; i < n; i++) {
      if (pre[i] == -1 && a[x][i] > 0) {
        pre[i] = x;
        q[en++] = i;
        if (i == 1) return 1;
      }
    }
  }
  return 0;
}
int max_flow() {
  int ans = 0, i;
  while (bfs()) {
    int min = 0x7fffffff;
    for (i = 1; i != 0; i = pre[i]) min = min > a[pre[i]][i] ? a[pre[i]][i] : min;
    for (i = 1; i != 0; i = pre[i]) {
      a[pre[i]][i] -= min;
      a[i][pre[i]] += min;
    }
    ans += min;
  }
  return ans;
}
int main() {
  int m, i, j, k;
  char s[100], s2[100];
  string str1, str2;
  while (scanf("%d", &m) != EOF) {
    mp.clear();
    for (i = 0; i < 1000; i++) {
      for (j = 0; j < 1000; j++) a[i][j] = 0;
    }
    n = 2;
    while (m--) {
      scanf("%s", s);
      str1 = s;
      if (mp[str1] == 0) mp[str1] = n++;
      a[0][mp[str1]]++;
    }
    scanf("%d", &m);
    j = m;
    while (m--) {
      scanf("%s%s", s, s2);
      str2 = s2;
      if (mp[str2] == 0) mp[str2] = n++;
      a[mp[str2]][1]++;
    }
    scanf("%d", &k);
    while (k--) {
      scanf("%s%s", s, s2);
      str1 = s;
      str2 = s2;
      if (mp[str1] == 0) mp[str1] = n++;
      if (mp[str2] == 0) mp[str2] = n++;
      a[mp[str2]][mp[str1]] = 0x7fffffff;
    }
    printf("%d\n", j - max_flow());
  }
  return 0;
}