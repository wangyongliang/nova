#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;
#define MAXN 200000
int main() {
  for (int i = 2; i <MAXN; i ++) {
    for (int j = i; j < MAXN; j+= i) ;
  }
  return 0;
}