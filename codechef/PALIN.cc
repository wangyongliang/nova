#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
#define MAXN 1000010
char buffer[MAXN];
int main() {
  int t;
  int len;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", buffer);
    len = strlen(buffer);
    int i = 0;
    int j = len - 1;
    int flag = 0;
    while (i < j) {

      if (buffer[i] > buffer[j]) {
        flag = 1;
      } else if (buffer[i] < buffer[j]) {
        flag = -1;
      }
      buffer[j] = buffer[i];
      i ++;
      j --;
    }
    // cout << flag << endl;
    if (flag < 1) {
      if (len & 1) {
        i = len / 2;
        j = i;
      } else {
        i = len / 2 - 1;
        j = i + 1;
      }
      while (i >= 0) {
        if (buffer[i] < '9') {
          buffer[i] ++;
          buffer[j] = buffer[i];
          if (i == j)
            break;
          i ++;
          j --;
          while (i <= j) {
            buffer[i] = buffer[j] = '0';
            i ++;
            j --;
          }
          break;
        }
        i --;
        j ++;
      }
      // cout << i << endl;
      if (i == -1) {
        printf("1");
        for (int i = 0; buffer[i + 1]; i ++) printf("0");
        printf("1\n");
      } else {
        printf("%s\n", buffer);
      }
    } else {
      printf("%s\n", buffer);
    }

  }
  return 0;
}