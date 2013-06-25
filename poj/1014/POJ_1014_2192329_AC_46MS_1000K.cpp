#include <stdio.h>
#include <string.h>

#define MAXN 120010
#define MAXM 7

int f[MAXN][2];
int a[MAXM];

int main() {
  int i, j, n = 0;
  scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
  while (a[1] > 0 || a[2] > 0 || a[3] > 0 || a[4] > 0 || a[5] > 0 || a[6] > 0) {
    a[0] = 0; n++;
    for (i = 1; i <= 6; i++)
      a[0] += a[i] * i;
    if (!a[0]) break;
    for (j = 0; j <= a[0]; j++) {
      f[j][0] = f[j][1] = -1;
    }
    f[0][0] = 0;
    for (i = 1; i <= 6; i++) {
      for (j = 0; j <= a[0]; j++) {
        if (f[j][0] > -1) f[j][1] = 0;
        if (j - i >= 0 && f[j - i][0] > -1)
          if (a[i] > 0 && f[j][1] == -1) f[j][1] = 1;
        if (j - i >= 0 && f[j - i][1] > -1)
          if (f[j - i][1] < a[i] && (f[j - i][1] + 1 < f[j][1] || f[j][1] == -1))
            f[j][1] = f[j - i][1] + 1;
      }
      for (j = 0; j <= a[0]; j++) {
        f[j][0] = f[j][1];
        f[j][1] = -1;
      }
    }
    if (f[a[0] / 2][0] > -1 && a[0] % 2 == 0)
      printf("Collection #%d:\nCan be divided.\n\n", n);
    else printf("Collection #%d:\nCan\'t be divided.\n\n", n);
    scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]);
  }
  return 0;
}
