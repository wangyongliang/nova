// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang

#include <stdio.h>
#include <math.h>
//1005
int main() {
  int m, i;
  int n[10] = {0};
  float x, y;
  double area;
  do
    scanf("%d", &m);
  while (m <= 0);
  for (i = 0; i < m; i++) {
    scanf("%f%f", &x, &y);
    if (y >= 0) {
      area = 3.14 * (x * x + y * y);
      area = area / 100;
      n[i] = (int)area;
      if (area > n[i])
        n[i] = n[i] + 1;
    }
  }
  for (i = 0; i < m; i++)
    if (n[i] != 0)
      printf("Property %d: This property will begin eroding in year %d.\n", i + 1, n[i]);
  printf("END OF OUTPUT.\n");
  return 0;
}