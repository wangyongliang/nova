// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang

// Implement of Segment Tree:
//   wiki: http://en.wikipedia.org/wiki/Segment_tree
//   Runtime of important function:
//     construction: O(2 * n)
//     increase: O(log(n))
//     operator[]: O(log(n))
//     sum: O(log(n))

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cassert>

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

  // Sum all the element in (start, end) interval
  // similar to implement max(start, end), min(start, end), eg.
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

  T operator[] (int index) { return sum(index, index);}
  int start() const {return start_;}
  int end() const {return end_;}
  int size() const {return end_ - start_ + 1;}
  SegmentTree* left() const {return left_;}
  SegmentTree* right() const {return right_;}
private:
  int start_;
  int end_;
  T cover_;
  T value_;
  SegmentTree* left_;
  SegmentTree* right_;
};

int main() {
  // cout << (-1 / 2) << endl;
  SegmentTree<int> tree(0, 10);
  tree.increase(0, 1, 1);
  assert(tree.sum(0, 1) == 2);
  tree.increase(0, 1, -1);
  for (int i = tree.start(); i <= tree.end(); i ++) {
    assert(tree[i] == 0);
  }
  return 0;
}
