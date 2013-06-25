#include<iostream>
using namespace std;
#define MAXN 60001
#define MAXM 6
bool a[MAXN], ok;
int b[MAXN][2];
int num[MAXM + 1], sum;
int main() {
  int t = 1;
  int i, j, all, tmp;
  while (1) {
    sum = 0;
    for (i = 1; i <= 6; i++) {
      scanf("%d", &num[i]);
      sum += num[i] * i;
    }
    if (sum == 0)break;
    if (sum & 1)ok = 0;
    else {
      ok = 0;
      sum /= 2;
      all = 0;
      memset(a, false, sizeof(a));
      a[0] = 1;
      memset(b, -1, sizeof(b));
      for (j = 1; j <= MAXM; j++) {
        if (num[j] <= 0) continue;
        all += j * num[j];
        if (all >= sum)all = sum;
        for (i = j; i <= all; i++) {
          if (a[i] || !a[(tmp = i - j)] ||
              (b[tmp][0] == j && b[tmp][1] >= num[j]))
            continue;
          b[i][0] = j;
          if (b[tmp][0] == j) b[i][1] = b[tmp][1] + 1;
          else b[i][1] = 1;
          a[i] = 1;
        }
      }
      if (a[sum])ok = 1;
    }
    printf("Collection #%d:\n", t);
    if (ok)printf("Can be divided.\n\n");
    else printf("Can't be divided.\n\n");
    t++;
  }
  return 0;
}