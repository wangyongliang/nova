// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang

#include <stdio.h>

long a[15] = {0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881, 134827720};
int main() {
  int i;
  while (scanf("%d", &i) && i) {
    printf("%ld\n", a[i]);
  }
  return 0;
}