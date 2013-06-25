#include <stdio.h>
#include <math.h>
#define N 5

const unsigned long total_length[N] = { 0, 45, 9045, 1395495, 189414495};
const unsigned long first[N + 1] = {0, 1, 11, 192, 2893, 38894};
const unsigned long last[N] = {0, 9, 189, 2889, 38889};

int main() {
  unsigned i, j, n;
  unsigned long index;

  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    unsigned len, t, k;

    scanf("%ld", &index);
    for (j = 1; j < N; j++)
      if (index <= total_length[j])
        break;
    len = j;
    index -= total_length[len - 1];
    for (j = 1; ; j++)
      if ((first[len] * j + j * (j - 1) * len / 2) >= index)
        break;
    index = index - first[len] * (j - 1) - (j - 1) * (j - 2) * len / 2;
    for (j = 1; j < N; j++)
      if (index <= last[j])
        break;
    if (j == 1)
      printf("%d\n", index);
    else {
      index -= last[j - 1];
      t = (index - 1) / j + (int) pow(10, j - 1);
      k = t / (int) pow(10, j - 1 - (index - 1) % j) % 10;
      printf("%d\n", k);
    }
  }
  return 0;
}