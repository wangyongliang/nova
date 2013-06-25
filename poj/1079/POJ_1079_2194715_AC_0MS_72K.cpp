#include<stdio.h>
#include<math.h>
void main() {
  double eps, div, eps1, eps2, n, m, i, j;
  int k;
  //  int i,j,n,m;
  while (scanf("%lf%lf", &n, &m) != EOF) {
    eps = 100;
    div = n / m;
    for (i = 1; i <= m; i++) {
      j = i * div;
      k = (int)j;
      k++;
      eps1 = k / i;
      eps2 = (k - 1) / i;
      if (fabs(div - eps1) > fabs(div - eps2))
        k--;
      if (fabs(div - k / i) < eps) {
        eps = fabs(div - k / i);
        printf("%d/%.0lf\n", k, i);
      }
      //      if(fab(eps)<=0.0000000000002)
    }
    printf("\n");
  }
}