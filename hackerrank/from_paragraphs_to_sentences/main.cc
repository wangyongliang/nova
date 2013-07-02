#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

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

class State {
public:
  State(): buffer(""), in_quote(false){}
  void append(char ch) {
    buffer += ch;
    if (ch == '"')
      in_quote = 1 - in_quote;
  }
  char last_char() {
    if (buffer.size() > 0)
      return buffer[buffer.size() - 1];
    else
      return 0;
  }
  bool split() {
    char ch = last_char();
    // In quote, DONOT split
    if (in_quote)
      return false;
    switch(ch) {
      case '.': {
        return !Abbr();
      }
      case '?' {
      }
    }
  }

  bool Abbr() {
    int i = buffer.size() - 1;
    for (; i >= 0 && isalpha(buffer[i]) == false; i --);
    for (; i >= 0 && isalpha(buffer[i]); i --);
    if (i >= 0 && buffer[i] >= 'A' && buffer[i] <= 'Z')
      return true;
    return false;
  }

  string buffer;
private:
  bool in_quote;
};
int main() {
  char ch;
  string line;
  freopen("data.txt", "r", stdin);
  while (true) {
    ch = getchar();
    if (ch == EOF)
      break;
    line += ch;
    if (ch == '.' || ch == '?' || ch == '!') {
      trim(line, " \t\n", line);
      cout << line << endl;
      line = "";
    }
  }
  return 0;
}