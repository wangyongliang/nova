#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int solve(const string &p, const string &q, const int &k) {
  int ans = 0;
  vector<int> count;
  for (size_t i = 0; i < p.size(); i ++) {
    count.clear();
    for (size_t j = 0; j < q.size() && i + j < p.size(); j ++) {
      if (p[i + j] != q[j]) count.push_back(1);
      else count.push_back(0);
    }
    int start = 0;
    int cnt = 0;
    for (size_t j = 0; j < count.size(); j ++) {
      cnt += count[j];
      for (; cnt > k; start ++) cnt -= count[start];
      ans = max(ans, (int)(j - start + 1));
    }
  }
  return ans;
}
int main() {

  string p, q;
  int k;
  int t;
  cin >> t;
  while (t--) {
    cin >> k >> p >> q;
    cout << max(solve(p, q, k), solve(q, p, k)) << endl;
  }
  return 0;
}