// Solution: implement an AVL tree, segment tree or binary indexed tree
#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
#define MAXN 100010

int cnt[MAXN];
void add(int x, int val) {
  while (x < MAXN) {
    cnt[x] += val;
    x += x& (-x);
  }
}
int sum(int x) {
  int sum = 0;
  while (x > 0) {
    sum += cnt[x];
    x -= x & (-x);
  }
  return sum;
}
map<int, int> mp;
pair<char, int> a[MAXN];
vector<int> numbers;
int idx[MAXN];
int ct;

int search(int position) {
  int min_ = 1;
  int max_ = ct - 1;
  int mid_;
  while (min_ < max_) {
    mid_ = (min_ + max_) >> 1;
    if (sum(mid_) >= position)
      max_ = mid_;
    else
      min_ = mid_ + 1;
  }
  return min_;
}

void median(int current) {
  long long j;
  if (current == 0) {
    printf("Wrong!\n");
    return;
  }
  if (current & 1) {
    printf("%d\n", idx[search(current / 2 + 1)]);
  } else {
    j = static_cast<long long>(idx[search(current / 2)]) +
    static_cast<long long>(idx[search(current / 2 + 1)]);
    if (j & 1)
      printf("%.1lf\n", j / 2.0);
    else
      printf("%lld\n", j / 2);
  }
}

int main() {
  // freopen("data.txt", "r", stdin);
  int n;
  memset(cnt, 0, sizeof(int) * MAXN);
  numbers.clear();
  scanf("%d", &n);
  char buffer[10];
  for (int i = 0; i < n; i ++) {
    scanf("%s %d", buffer, &a[i].second);
    a[i].first = buffer[0];
    numbers.push_back(a[i].second);
  }
  sort(numbers.begin(), numbers.end());
  ct = 1;
  for (int i = 0; i < numbers.size(); i ++) {
    if (i && numbers[i] == numbers[i - 1])
      continue;
    mp[numbers[i]] = ct;
    idx[ct] = numbers[i];
    ct ++;
  }

  int j, k;
  int current = 0;
  for (int i = 0; i < n; i ++) {
    j = mp[a[i].second];
    if (a[i].first == 'a') {
      add(j, 1);
      current ++;
      median(current);
    } else if(a[i].first == 'r') {
      k = sum(j) - sum(j - 1);
      if (k == 0)
        printf("Wrong!\n");
      else {
        add(j, -1);
        current --;
        median(current);
      }
    } else break;
  }
  return 0;
}