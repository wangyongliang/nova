#include <stdio.h>
int main() {
  unsigned long   x, y, m, n, l;
  while (scanf ("%ld %ld %ld %ld %ld", &x, &y, &m, &n, &l) != EOF) {
    if (m > n) {
      m = m - n;
      x = (y - x + l) % l;
    } else {
      m = n - m;
      x = (x - y + l) % l;
    }
    n = x / m;
    x = x % m;
    y = x;
    while (1) {
      if (y == 0) {
        printf ("%d\n", n);
        break;
      }
      n += (y + l) / m;
      y = (y + l) % m;
      if (y == x) {
        printf ("Impossible\n");
        break;
      }
    }
  }
  return 0;
}