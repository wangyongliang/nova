// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang
// Problem: http://poj.org/problem?id=1201
// Solution: Greedy

#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T>
class TreeArray {
public:
  TreeArray(int size): size_(size) {
    sum_ = new T[size];
    value_ = new T[size];
    memset(sum_, 0, size * sizeof(T));
    memset(value_, 0, size * sizeof(T));
  }

  static int LowBit(int bit) {
    return bit & (-bit);
  }

  void Increase(int pos, T number) {
    value_[pos] += number;
    while (pos < size_) {
      sum_[pos] += number;
      pos += LowBit(pos);
    }
  }

  T Sum(int pos) const {
    T res(0);
    while (pos > 0) {
      res += sum_[pos];
      pos -= LowBit(pos);
    }
    return res;
  }

  T Sum(int start, int end) const {
    T result(0);
    result = Sum(end);
    if (start > 0)
      result -= Sum(start - 1);
    return result;
  }

  T operator [](const int index) const {
    return value_[index];
  }

  void Set(int pos, T number) {
    T delta = number - value_[pos];
    Increase(pos, delta);
  }

  int Size() const {
    return size_;
  }

  ~TreeArray() {
    if (sum_ != NULL)
      delete [] sum_;
    if (value_ != NULL)
      delete [] value_;
  }
  
private:
  int size_;
  T* sum_;
  T* value_;
};

struct Interval {
  int start;
  int end;
  int required;
};
bool operator <(const Interval &x, const Interval &y) {
  return x.end < y.end;
}

int main(int argc, char const *argv[]) {
  Interval interval;
  int t;
  while (scanf("%d", &t) != EOF) {
    int size = 0;
    vector<Interval> intervals;
    for (int i = 0; i < t; i ++) {
      scanf("%d%d%d", &interval.start, &interval.end, &interval.required);
      interval.start ++;
      interval.end ++;
      if (interval.start > interval.end) 
        swap(interval.start, interval.end);
      intervals.push_back(interval);
      size = max(size, interval.end);
    }
    sort(intervals.begin(), intervals.end());
    TreeArray<int> array(size + 1);

    priority_queue<int> q;
    int last = 1;
    for (int i = 0; i < intervals.size(); i ++) {
      while (last <= intervals[i].end) {
        q.push(last ++);
      }
      int more = intervals[i].required - array.Sum(intervals[i].start, intervals[i].end);
      if (more > 0) {
        while (more--) {
          array.Increase(q.top(), 1);
          q.pop();
        }
      }
    }
    printf("%d\n", array.Sum(size));
  }
  return 0;
}