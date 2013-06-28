#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
#define MAXN 100000
long long cache[MAXN] = {0};

long long calculate(long long n) {
  long long result = n;
  while (n != 1) {
    if (n %2 ==0) n >> 1;
    else n = n * 3 + 1;
    result = max(result, n);
  }
  return result;
}
int main() {
  int tests;
  int id, n;
  scanf("%d", &tests);
  for (int test = 1; test <= tests; test ++) {
    cout << calculate(test) << endl;
  }
  return 0;
}