#include <iostream>

#define max 64

int sk[max], vis[max], n;
int sum, lg;

using namespace std;

int cmp(const void *a, const void *b) {
  return (*(int *)b) - (*(int *)a);
}

int DFS(int times, int len, int pos) {
  int i;
  for (i = pos; i < n; i++) {
    if (!vis[i] && len >= sk[i]) {
      vis[i] = 1;
      if (times == 1 && len - sk[i] == 0) {
        return 1;
      }
      if (len - sk[i] == 0) {
        if (DFS(times - 1, lg, 0) == 1) return 1;
        else {
          vis[i] = 0;
          return 0;
        }
      } else {
        if (DFS(times, len - sk[i], i + 1) == 1) return 1;
        else if (lg == len) {
          vis[i] = 0;
          return 0;
        }
      }
      vis[i] = 0;
    }
  }
  return 0;
}

int main() {
  int i;
  while (scanf("%d", &n), n > 0) {
    memset(sk, 0, sizeof(sk));   sum = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &sk[i]);
      sum += sk[i];
    }
    qsort(sk, max, sizeof(int), cmp);
    for (i = sk[0]; i <= sum; i++) {
      if (sum % i == 0) {
        memset(vis, 0, sizeof(vis));
        if (i == sum) {
          printf("%d\n", sum);
          break;
        }
        lg = i;
        if (DFS(sum / i, i, 0)) {
          printf("%d\n", i);
          break;
        }
      }
    }
  }
  return 0;
}

