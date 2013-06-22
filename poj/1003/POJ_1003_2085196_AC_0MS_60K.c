// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang

#include <stdio.h>
void main() {
  float n, sum, i;
  while (scanf("%f", &n) && n != 0.00) {
    i = 2;
    sum = 0;
    while (sum < n) {
      sum += 1 / i;
      i++;
    }
    printf("%.0f card(s)\n", i - 2);
  }
}