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
int main() {
  // freopen("data.txt", "r", stdin);
  string line;
  cin >> line;
  int flor, cel;
  for (flor = 1; flor * flor <= line.size(); flor++);
  flor --;
  for (cel = 1; cel * cel < line.size(); cel ++);
  if (flor * cel < line.size()) flor ++;
  string result;
  for (int i = 0; i < cel; i++) {
    result = "";
    for (int j = 0; j < flor && j * cel + i < line.size(); j ++)
      result += line[j * cel + i];
    cout << result;
    if (i < cel)
      cout << " ";
  }
  cout << endl;
  return 0;
}
