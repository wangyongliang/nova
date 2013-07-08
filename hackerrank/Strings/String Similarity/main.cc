#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define maxn  400000

struct autom {
  int next[26];
  int l;
  int c;
  int len;
  void clear(int Len) {
    for (int i = 0; i < 26; i ++) next[i] = -1;
    l = -1;
    c = 0;
    len = Len;
  }
} a[maxn];
int m;
int last;
int cnt[maxn];
int b[maxn];
char str[maxn];

int main() {
  int t;
  scanf("%d", &t);
  int p, q, cur, idx, clone;
  int len;
  while (t--) {
    scanf("%s", str);
    len = strlen(str);
    last = 0;
    a[0].clear(0);
    a[0].l = -1;
    m = 1;
    for (int i = 0; str[i]; i ++) {
      cur = m ++;
      a[cur].clear(a[last].len + 1);
      idx = str[i] - 'a';
      for (p = last; p != -1 && a[p].next[idx] == -1; p = a[p].l) {
        a[p].next[idx] = cur;
      }

      if (p == -1) a[cur].l = 0;
      else {
        q = a[p].next[idx];
        if (a[p].len  + 1 < a[q].len) {
          clone = m ++;

          for (int j = 0; j < 26; j ++) a[clone].next[j] = a[q].next[j];
          a[clone].l = a[q].l;
          a[clone].c = a[q].c;
          a[clone].len = a[p].len + 1;

          for (; p != -1 && a[p].next[idx] == q; p = a[p].l ) {
            a[p].next[idx] = clone;
          }
          a[q].l = a[cur].l = clone;

        } else {
          a[cur].l = q;
        }
      }
      last = cur;

    }

    for (int i = 0; i <= len; i ++) cnt[i] = 0;
    for (int i = 0; i < m; i ++) {
      cnt[a[i].len ] ++;
    }

    for (int i = 1; i <= len; i ++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < m; i ++) b[cnt[a[i].len] --] = i;
    for (; last != -1; last = a[last].l) a[last].c = 1;
    for (int i = m - 1; i >= 0; i --) {
      autom &cur = a[b[i]];
      for (int j = 0; j < 26; j ++) {
        if (cur.next[j] != -1) cur.c += a[cur.next[j]].c;
      }
    }

    long long ans = 0;
    last = 0;
    for (int i = 0; str[i]; i ++) {
      last = a[last].next[str[i] - 'a'];
      ans += a[last].c;
    }
    cout << ans  << endl;
  }

  return 0;
}
