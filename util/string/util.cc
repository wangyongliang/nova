// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

void split(string str, const char delimiter[], vector<string> &iterms) {
  unsigned int flag[8] = {0};
  int len = sizeof(delimiter);
  for (int i = 0; delimiter[i]; i ++) {
    flag[delimiter[i]/ 32 ] |= 1 << (delimiter[i] % 32);
  }
  string term = "";
  for (size_t i = 0; i < str.size(); i ++) {
    if (flag[str[i] / 32] & (1 << (str[i] % 32))) {
      if (!term.empty())
        iterms.push_back(term);
      term.clear();
    } else {
      term += str[i];
    }
  }
  if (!term.empty())
    iterms.push_back(term);
}

void trim(string &input, const char trim_chars[], string &output) {
  size_t start_pos = input.find_first_not_of(trim_chars);
  if (start_pos == string::npos) {
    output.clear();
    return;
  }
  size_t end_pos = input.find_last_not_of(trim_chars);
  if (end_pos == string::npos) {
    output.clear();
    return;
  }
  output = input.substr(start_pos, end_pos - start_pos + 1);
}


int main(int argc, char const *argv[]) {
  // Test basic functional
  string line = "I'm a good man!   ";
  vector<string> iterms;
  split(line, "' !", iterms);
  string split_result[] = {"I", "m", "a", "good", "man"};
  vector<string> expect(split_result, split_result + sizeof(split_result) / sizeof(string));
  for (int i = 0; i < iterms.size(); i ++) {
    assert(iterms[i] == expect[i]);
  }

  // Test char at 32 * i + 31;
  line = "Are you a good man? Yes!";
  iterms.clear();
  split(line, " ?!", iterms);
  string split_result2[] = {"Are", "you", "a", "good", "man", "Yes"};
  vector<string> expect1(split_result2, split_result2 + sizeof(split_result2) / sizeof(string));
  assert(iterms.size() == expect1.size());
  for (int i = 0; i < iterms.size(); i ++) {
    assert(iterms[i] == expect1[i]);
  }

  line = "I'm a good man!  ";
  trim(line, "! ", line);
  assert(line == "I'm a good man");
  line = "   ";
  trim(line, " ", line);
  assert(line.empty());
  return 0;
}