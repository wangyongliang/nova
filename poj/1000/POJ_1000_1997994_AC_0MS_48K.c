// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang

#include <stdio.h>
void main() {
  int a, b;
  while (EOF != scanf("%d %d", &a, &b)) {
    printf("%d", a + b);
  }
}