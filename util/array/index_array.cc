// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang
// Implement of Binary Indexed Trees

#include <cassert>
#include <iostream>
#include <cstring>

template <typename T>
class TreeArray {
public:
  TreeArray(int size): size_(size) {
    sum_ = new T[size];
    value_ = new T[size];
    memset(sum_, 0, size * sizeof(T));
    memset(value_, 0, size * sizeof(T));
  }

  static int low_bit(int bit) {
    return bit & (-bit);
  }

  void increse(int pos, T number) {
    value_[pos] += number;
    while (pos < size_) {
      sum_[pos] += number;
      pos += low_bit(pos);
    }
  }

  T sum(int pos) const {
    T res(0);
    while (pos > 0) {
      res += sum_[pos];
      pos -= low_bit(pos);
    }
    return res;
  }

  T sum(int start, int end) const {
    T result(0);
    result = sum(end);
    if (start > 0)
      result -= sum(start - 1);
    return result;
  }

  T operator [](const int index) const {
    return value_[index];
  }

  void set(int pos, T number) {
    T delta = number - value_[pos];
    increse(pos, delta);
  }

  int size() const {
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

int main(int argc, char const *argv[]) {
  TreeArray<int> array(10);

  assert(array.sum(2, 4) == 0);

  // Test increse
  array.increse(1, 1);
  for (int i = 1; i < 10; i ++)
    assert(array.sum(i) == 1);
  array.increse(1, 2);
  for (int i = 1; i < 10; i ++)
    assert(array.sum(i) == 3);
  array.increse(5, 1);
  for (int i = 5; i < 10; i ++)
    assert(array.sum(i) == 4);

  // Test []
  assert(array[1] == 3);

  array.set(1, 4);
  assert(array[1] == 4);
  assert(array.sum(9) == 5);
  assert(array.sum(5, 9) == 1);
  return 0;
}