#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
int main() {
  long long next[] = {1, 14,144};
  long long inc[] = {10, 100, 1000};
  vector<long long> v(next, next + 3);
  set<long long> magic;
  long long max_ = 2000000000LL;
  for (int i = 0; i < v.size(); i ++) {
    magic.insert(v[i]);
  }

  long long num;
  for (int i = 0; i < v.size(); i ++) {
    for (int j = 0; j < 3; j ++) {
      num = v[i] * inc[j] + next[j];
      if (num < max_ && magic.find(num) == magic.end()) {
        magic.insert(num);
        v.push_back(num);
      }
    }
  }

  while (cin >> num) {
    cout << ((magic.find(num) == magic.end())? "NO" : "YES") << endl;
  }

  return 0;
}