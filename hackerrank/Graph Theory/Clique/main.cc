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

int sum(int n,int k) {
 int g1 = n%k ;
 int g2 = k - g1 ;
 int sz1 = n/k + 1 ;
 int sz2 = n/k ;
 int ret = g1*sz1*g2*sz2 + g1*(g1-1)*sz1*sz1/2 + g2*(g2-1)*sz2*sz2/2 ;
 return ret ;
}

int main() {
  int t;
  scanf("%d", &t);
  int n;
  long long m;
  while(t--) {
    scanf("%d%lld", &n, &m);
    int min_ = 1;
    int max_ = n;
    int mid_;
    while (min_ < max_) {
      mid_ = (min_ + max_) >> 1;
      if (sum(n, mid_) >= m /*- 1e-6*/) max_ = mid_;
      else min_ = mid_ + 1;
    }
    cout << min_ << endl;
  }
  return 0;
}