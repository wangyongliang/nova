/*
 * Copyright (C) 2013 yongliangwang <yongliangwang@wangyongliang-desktop>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
template <typename T>
class SegmentTree {
public:
  SegmentTree(int start, int end): start_(start), end_(end){
    if (start == end) {
      left_ = NULL;
      right_ = NULL;
    } else {
      left_ = new SegmentTree(start, (end + start) >> 1);
      right_ = new SegmentTree(((end + start) >> 1) + 1, end);
    }
    cover_ = 0;
    value_ = 0;
  }

  ~SegmentTree() {
    if (left_ != NULL) delete left_;
    if (right_ != NULL) delete right_;
  }

  int size() const { return end_ - start_ + 1;}

  void increase(int start, int end, T delta) {
    if (start <= start_ && end >= end_) {
      value_ += delta * (end_ - start_ + 1);
      cover_ += delta;
    } else {
      if (cover_ != 0) {
        left_->increase(start_, end_, cover_);
        right_->increase(start_, end_, cover_);
        cover_ = 0;
      }
      int mid = (start_ + end_) >> 1;
      if (start <= mid)
        left_->increase(start, end, delta);
      if (end > mid)
        right_->increase(start, end, delta);
      value_ = left_->value_ + right_->value_;
    }
  }

  T sum(int start, int end) {
    if (start <= start_ && end >= end_)
      return value_;
    if (cover_ != 0) {
      left_->increase(start_, end_, cover_);
      right_->increase(start_, end_, cover_);
      cover_ = 0;
    }
    int mid = (start_ + end_) >> 1;
    T result(0);
    if (start <= mid)
      result += left_->sum(start, end);
    if (end > mid)
      result += right_->sum(start, end);
    return result;
  }

  T operator[] (int index) {
    return sum(index, index);
  }

  int start_;
  int end_;
  T cover_;
  T value_;
  SegmentTree* left_;
  SegmentTree* right_;
};

class Tuple {
public:
  int first;
  int second;
  int third;
};

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  SegmentTree<long long> array(0, n - 1);
  int x;
  for (int i = 0; i < n; i ++) {
    scanf("%d", &x);
    array.increase(i, i, x);
  }
  Tuple tuple;
  SegmentTree<int> ops(1, m);
  int y;
  vector<Tuple> tuples;
  for (int i = 0; i < m; i ++) {
    scanf("%d%d%d", &tuple.first, &tuple.second, &tuple.third);
    tuples.push_back(tuple);
  }

  for (int i = 0; i < k; i ++) {
    scanf("%d%d", &x, &y);
    ops.increase(x, y, 1);
  }

  long long z;
  for (int i = 1; i <= m; i ++) {
    x = tuples[i - 1].first - 1;
    y = tuples[i - 1].second - 1;
    z = 1LL * tuples[i - 1].third * ops[i];
    array.increase(x, y, z);
  }

  for (int i = array.start_; i <= array.end_; i ++) {
    printf("%I64d ", array[i]);
  }
  printf("\n");

  return 0;
}