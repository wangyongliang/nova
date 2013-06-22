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

int main(int argc, char const *argv[]) {  
  TreeArray<int> array(10);

  assert(array.Sum(2, 4) == 0);

  // Test increase
  array.Increase(1, 1);
  for (int i = 1; i < 10; i ++)
    assert(array.Sum(i) == 1);
  array.Increase(1, 2);
  for (int i = 1; i < 10; i ++)
    assert(array.Sum(i) == 3);
  array.Increase(5, 1);
  for (int i = 5; i < 10; i ++)
    assert(array.Sum(i) == 4);

  // Test []
  assert(array[1] == 3);

  array.Set(1, 4);
  assert(array[1] == 4);
  assert(array.Sum(9) == 5);
  assert(array.Sum(5, 9) == 4);
  return 0;
}