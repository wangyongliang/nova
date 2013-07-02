#include <iostream>
#include <cstdio>
using namespace std;

char buffer[10100];
int main() {
  int n, id;
  int base;
  scanf("%d", &n);
  while (n --) {
    scanf("%d%d%s", &id, &base, buffer);
    base --;
    int result = 0;
    for (int i = 0; buffer[i]; i ++) {
      result = result  + buffer[i] - '0';
      result %= base;
    }
    printf("%d %d\n", id, result);
  }
}