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
long long a[100];
bool road[100][100];
int d[100];
int n;

// Check whether Hamilton path existed or not
bool test(int mid) {
  memset(road, 0, sizeof(bool) * 100 * 100);
  memset(d, 0, sizeof(int) * 100);
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      if ((a[i] ^ a[j]) >= (1LL << mid)) {
        road[i][j] = 1;
        road[j][i] = 1;
      }
    }
  }
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      d[i] += road[i][j];
    }
  }
  for (int k = 0; k < n; k ++) {
    for (int i = 0; i < n; i ++) {
      if (road[i][k]) {
        for (int j = 0; j < n; j ++) {
          if (road[k][j])
            road[i][j] = 1;
        }
      }
    }
  }

  // All the vertex should be connected
  for (int i = 0; i <n; i ++) {
    for (int j = 0; j < n; j ++) {
      if (road[i][j] == 0)
        return false;
    }
  }
  // The degree of any two vertex should large than n
  for (int i = 0; i < n; i ++) {
    for (int j = i + 1; j < n; j ++) {
      if (d[i] + d[j] < n) return false;
    }
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i ++)
    cin >> a[i];
  int i;
  for (i = 31; i >= 0; i --) {
    if (test(i)) break;
  }
  cout << i << endl;
  return 0;
}