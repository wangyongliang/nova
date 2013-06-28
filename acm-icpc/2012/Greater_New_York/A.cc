#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>

using namespace std;
#define MAXN 100000000
bool visit[MAXN] = {0};
int states[MAXN] = {0};
void init() {
  states[1] = 1;
  priority_queue<pair<int, int> > q;
  q.push(make_pair(1, 1));
  pair<int, int> top;
  pair<int, int> next;
  while (q.size()) {
    top = q.top();
    q.pop();
    if (visit[top.second] && top.first == states[top.second]) continue;
    visit[top.second] = true;
    next.second = top.second * 2;
    next.first = max(top.first, next.second);
    if (next.second < MAXN && states[next.second] < next.first) {
      states[next.second] = next.first;
      q.push(next);
    }

    if ((top.second - 1)% 3 == 0) {
      next.second = (top.second - 1) / 3;
      next.first = max(top.first, next.second);
      if (next.second % 2 == 1 && next.second > 1 && states[next.second] < next.first) {
        states[next.second] = next.first;
        q.push(next);
      }
    }
  }
}
int main() {
  init();
  int max_ = 0;
  int id = 0;
  for (int i = 0; i < 100000; i ++) {
    max_ = max(max_, states[i]);
    if (max_ == states[i]) id = i;
  }
  cout << max_ << " " << id << endl;

  // int tests, id, n;
  // scanf("%d", &tests);
  // for (int test = 0;  test < tests; test ++) {
  //   scanf("%d%d", &id, &n);
  //   printf("%d %d\n", id, states[n]);
  // }
  return 0;
}