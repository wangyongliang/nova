// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang
// Usage:
/*  KMPMatcher matcher
    matcher.feed("kmp");  // feed the pattern
    matcher.match("I like kmp");  // match with string
    while (matcher.has_next()) {
      matcher.position(); // Do something with position
    }*/

#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <vector>

using namespace std;

class KMPMatcher {
public:
  KMPMatcher(): pattern_(NULL), shift_(NULL) {}
  ~KMPMatcher() {
    delete [] shift_;
  }

  // Return the next array of pattern
  const int* shift() {return shift_;}

  // Return the start position
  int position() {return pos_buffer_ - pattern_size_;}

  // Do KMP algorithm to find the start matched position
  bool has_next() {
    if (pos_pattern_ == pattern_size_)
      pos_pattern_ = overlap_? shift_[pos_pattern_ - 1]:0;

    while (buffer_[pos_buffer_]) {
      if (pos_pattern_ == -1 || buffer_[pos_buffer_] == pattern_[pos_pattern_]) {
        pos_buffer_ ++;
        pos_pattern_ ++;
      } else
        pos_pattern_ = shift_[pos_pattern_];
      if (pos_pattern_ == pattern_size_)
        return true;
    }
    return false;
  }

  // Feed the pattern string and build the next array
  void feed(const char* pattern) {
    if (shift_ != NULL) {
      delete [] shift_;
      shift_ = NULL;
    }
    pattern_ = pattern;
    pattern_size_ = strlen(pattern);
    shift_ = new int[pattern_size_];
    int i = 1, j = -1;
    shift_[0] = -1;
    while (pattern[i]) {
      if (j == -1 || pattern[i] == pattern[j]) {
        shift_[i ++] = ++j;
      } else j = shift_[j];
    }
  }

  void feed(const string& pattern) {feed(pattern.c_str());}

  // Match string
  void match(const char *buffer, bool overlap = true) {
    pos_buffer_ = pos_pattern_ = 0;
    buffer_ = buffer;
    overlap_ = overlap;
  }

  void match(const string& buffer, bool overlap_ = true) {
    match(buffer.c_str(), overlap_);
  }

private:
  const char *pattern_;
  int *shift_;
  int pos_buffer_;
  int pos_pattern_;
  int pattern_size_;
  bool overlap_;
  const char *buffer_;
};

int main() {

  // Test a huge data
  string str1 = "";
  string str2 = "";
  for (int i = 0; i < 1000000; i ++) str1 += '0';
  for (int j = 0; j < 100000; j ++) str2 += '0';
  str2 +='1';
  str1 += '1';
  KMPMatcher matcher;
  matcher.feed(str2);
  matcher.match(str1);
  assert(matcher.has_next() == true);
  assert(matcher.position() == 900000);

  // Test overlap
  str2 = "121213131";
  str1 = "121";
  matcher.feed(str1.c_str());
  matcher.match(str2.c_str());
  int expect1[] = {0, 2};
  vector<int> result1;
  while (matcher.has_next()) {
    result1.push_back(matcher.position());
  }
  assert(result1.size() == 2);
  for (int i = 0; i < result1.size(); i ++)
    assert(result1[i] == expect1[i]);

  // Test not overlap
  matcher.match(str2, false);
  result1.clear();
  while (matcher.has_next()) {
    result1.push_back(matcher.position());
  }
  assert(result1.size() == 1);
  assert(result1[0] == 0);
  return 0;
}
