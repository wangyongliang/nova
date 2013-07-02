#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main() {
  char buffer[100];
  int m;
  scanf("%d", &m);
  while (m --) {
    int id;
    scanf("%d", &id);
    gets(buffer);
    gets(buffer);
    int n;
    scanf("%d", &n);
    int pos = 0;
    printf("%d ", id);
    int len = strlen(buffer);
    while (n --) {
      scanf("%d", &id);
      pos = (pos + id + 3 * len) % len;
      printf("%c", buffer[pos]);

    }
    printf("\n");
  }
  return 0;
}