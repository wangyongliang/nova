#include<stdio.h>
int main() {
  char s1[105], s2[105];
  int l1, l2, t, n1[105], n2[105], array[5][5] = {5, -1, -2, -1, -3, -1, 5, -3, -2, -4, -2, -3, 5, -2, -2, -1, -2, -2, 5, -1, -3, -4, -2, -1, -127};
  long res[200][200], i, j;
  res[0][0] = 0;
  scanf("%d", &t);
  while (t > 0) {
    t--;
    scanf("%d%s%d%s", &l1, &s1, &l2, &s2);
    for (i = 0; i < l1; i++)
      switch (s1[i]) {
      case 'A': n1[i] = 0; break;
      case 'C': n1[i] = 1; break;
      case 'G': n1[i] = 2; break;
      case 'T': n1[i] = 3; break;
      case '-': n1[i] = 4;
      }
    for (i = 0; i < l2; i++)
      switch (s2[i]) {
      case 'A': n2[i] = 0; break;
      case 'C': n2[i] = 1; break;
      case 'G': n2[i] = 2; break;
      case 'T': n2[i] = 3; break;
      case '-': n2[i] = 4;
      }
    for (i = 1; i <= l1; i++)
      res[i][0] = res[i - 1][0] + array[n1[i - 1]][4];
    for (i = 1; i <= l2; i++)
      res[0][i] = res[0][i - 1] + array[4][n2[i - 1]];
    for (i = 1; i <= l1; i++)
      for (j = 1; j <= l2; j++) {
        res[i][j] = res[i - 1][j - 1] + array[n1[i - 1]][n2[j - 1]];
        if (res[i][j] < res[i - 1][j] + array[n1[i - 1]][4])
          res[i][j] = res[i - 1][j] + array[n1[i - 1]][4];
        if (res[i][j] < res[i][j - 1] + array[4][n2[j - 1]])
          res[i][j] = res[i][j - 1] + array[4][n2[j - 1]];
      }
    printf("%d\n", res[l1][l2]);
  }
  return 0;
}

