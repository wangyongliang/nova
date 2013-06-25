#include<stdio.h>
void main() {
  char a[25];
  int b[22];
  int n, i, j, k, temp, l;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &k);
    l = i = 0;
    while (k--) {
      scanf("%d", &j);
      temp = j - l;
      l = j;

      while (temp--)
        a[i++] = '(';
      a[i++] = ')';
    }
    a[i] = '\0';
    l = 1;
    for (i = temp = 0; a[temp]; temp++) {
      if (a[temp] == '(') b[i++] = temp;
      else {
        k = 0;
        for (j = b[i - 1]; j <= temp; j++) {
          if (a[j] == ')') k++;
        }
        i--;
        if (l) printf("%d", k), l = 0;
        else  printf(" %d", k);
      }
    }
    printf("\n");
  }
}