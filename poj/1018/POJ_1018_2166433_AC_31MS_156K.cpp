#include <fstream.h>
#include <search.h>
#include <iomanip.h>
#define in cin

struct BP {
  int b;
  int p;
};

BP my[100][100];
int n, m;
int len[100];
int blen;
int bs[10001];

int compare(const void *a, const void *b) {
  return (*(BP *)a).b - (*(BP *)b).b;
}

int comp(const void *a, const void *b) {
  return (*(int *)a) - (*(int *)b);
}

void getData() {
  int i, j, k;
  in >> m;
  for (i = 0; i < m; i++) {
    in >> len[i];
    for (j = 0; j < len[i]; j++)
      in >> my[i][j].b >> my[i][j].p;
    qsort(my[i], len[i], sizeof(BP), compare);
  }
  bs[0] = 0; k = 0; blen = 1;
  for (i = 0; i < m; i++)
    for (j = 0; j < len[i]; j++)
      bs[blen++] = my[i][j].b;
  qsort(bs, blen, sizeof(int), comp);
}

int getIndex(int row, int t) {
  int back = 25535;
  for (int i = 0; i < len[row]; i++)
    if (my[row][i].b >= t && my[row][i].p < back)
      back = my[row][i].p;
  return back;
}
void solve() {
  int i, j;
  double total;
  double max = -1;
  for (i = 1; i < blen; i++) {
    if (bs[i] == bs[i - 1])continue;
    total = 0;
    for (j = 0; j < m; j++) {
      int s = getIndex(j, bs[i]);
      if (s < 0)
        break;
      total += s;
    }
    if (j < m)continue;
    if (max < bs[i] / total)
      max = bs[i] / total;
  }
  cout << setiosflags(ios::fixed) << setprecision(3) << max << endl;
}
void main() {
  in >> n;
  for (int i = 0; i < n; i++) {
    getData();
    solve();
  }
}