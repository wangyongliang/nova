// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang

#include <stdio.h>

void main() {
  float n, sum = 0.0;
  int i;
  for (i = 0; i < 12; i++) {
    scanf("%f", &n);
    sum += n;
  }
  sum = sum / 12.0;
  printf("$%.2f", sum);
}