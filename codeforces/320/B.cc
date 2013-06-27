#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAXN 200
int map[MAXN][MAXN];
bool visit[MAXN];

void flood_fill(int x) {
  if (visit[x])
    return;
  visit[x] = 1;
  for (int i = 0; i < MAXN; i ++) {
    if (map[x][i]) {
      flood_fill(i);
    }
  }
}

typedef pair<int, int> Interval;
bool Within(const Interval &x, const Interval &y) {
  return (y.first < x.first && x.first < y.second) ||
  (y.first < x.second && x.second < y.second);
}

vector<Interval > intervals;
void update(int index) {
  for (int i = 0; i < intervals.size(); i ++) {
    if (Within(intervals[i], intervals[index])) {
      map[i][index] = true;
    }
    if (Within(intervals[index], intervals[i])) {
      map[index][i] = true;
    }
  }
}

int main() {
  int t;
  int type;
  Interval interval;
  while (cin >> t) {
    intervals.clear();
    for (int i = 0; i < MAXN; i ++)
      memset(map[i], 0, sizeof(map[i]));
    for (int i = 0; i < t; i ++) {
      cin >> type >> interval.first >> interval.second;
      switch(type) {
        case 1: {
          intervals.push_back(interval);
          update(intervals.size() - 1);
          break;
        }
        default: {
          memset(visit, 0, sizeof(visit));
          flood_fill(interval.first - 1);
          cout << (visit[interval.second - 1]? "YES":"NO") << endl;
          break;
        }
      }
    }
  }
  return 0;
}