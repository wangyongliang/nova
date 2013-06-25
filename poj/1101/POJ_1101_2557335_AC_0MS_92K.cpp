//pku 1468 1470 的其他方法
#include<stdio.h>
#include<string.h>
#define maxn 309
char s[77][77];
bool flag[77][77];
int x, y, xx, yy;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
struct node {
  int dir;
  int seg;
  int x, y;
} q[maxn];
int w, h;
int bfs() {
  int i, j, k;
  int head, end;
  for (i = 0; i <= h + 1; i++) {
    for (j = 0; j <= w + 1; j++) flag[i][j] = 1;
  }
  head = 0;
  end = 0;
  for (k = 0; k < 4; k++) {
    i = x + dx[k];
    j = y + dy[k];
    if (i == xx && j == yy) return 1;
    if (i >= 0 && i <= h + 1 && j >= 0 && j <= w + 1 && s[i][j] == ' ' && flag[i][j]) {
      flag[i][j] = 0;
      q[end].x = i;
      q[end].y = j;
      q[end].dir = k;
      q[end].seg = 1;
      end++;
      end %= maxn;
    }
  }
  while (head != end) {
    i = q[head].x;
    j = q[head].y;
    while (1) {
      i += dx[q[head].dir];
      j += dy[q[head].dir];
      if (i == xx && j == yy) return q[head].seg;
      if ((i >= 0 && i <= h + 1) && (j >= 0 && j <= w + 1)) {
        if (s[i][j] == ' ' && flag[i][j]) {
          flag[i][j] = 0;
          q[end].x = i;
          q[end].y = j;
          q[end].dir = q[head].dir;
          q[end].seg = q[head].seg;
          end++;
          end %= maxn;
        } else break;
      } else {
        break;
      }
    }
    for (k = 0; k < 4; k++) {
      if (k == q[head].dir) continue;
      i = q[head].x + dx[k];
      j = q[head].y + dy[k];
      if (i == xx && j == yy) return q[head].seg + 1;
      if (i >= 0 && i <= h + 1 && j >= 0 && j <= w + 1 && s[i][j] == ' ' && flag[i][j]) {
        flag[i][j] = 0;
        q[end].x = i;
        q[end].y = j;
        q[end].dir = k;
        q[end].seg = q[head].seg + 1;
        end++;
        end %= maxn;
      }
    }
    head++;
    head %= maxn;
  }
  return -1;
}
int main() {
  int i, j, t = 1, k;
  while (scanf("%d%d", &w, &h) && (w + h)) {
    getchar();
    k = 1;
    for (i = 0; i <= w + 1; i++) s[0][i] = ' ';
    s[0][i] = '\0';
    for (i = 1; i <= h; i++) {
      s[i][0] = ' ';
      for (j = 1; j <= w; j++) scanf("%c", &s[i][j]);
      s[i][j] = ' ';
      s[i][j + 1] = '\0';
      getchar();
    }
    for (j = 0; j <= w + 1; j++) s[i][j] = ' ';
    s[i][j] = '\0';
    printf("Board #%d:\n", t);
    while (scanf("%d%d%d%d", &y, &x, &yy, &xx)) {
      if (x || y || xx || yy) {
        if (x == xx && y == yy) {
          printf("Pair %d: 0 segments.\n", k);
        } else {
          i = bfs();
          if (i == -1) printf("Pair %d: impossible.\n", k);
          else printf("Pair %d: %d segments.\n", k, i);
        }
      } else break;
      k++;
    }
    printf("\n");
    t++;
  }
  return 0;
}
