// Copyright 2013 Yunrang Inc. All Rights Reserved.
// Author: Yongliang Wang

#include <cassert>
#include <cstdio>
#include <cstring>

#define MAX_INDEX 62
int CHAR_MAP[256];
template <typename T>
class Trie {
 public:
  static void InitLowerMap() {
    assert(MAX_INDEX >= 26);
    for (int i = 'a'; i <= 'z'; i ++)
      CHAR_MAP[i] = i - 'a';
  }
  static void InitUpperMap() {
    assert(MAX_INDEX >= 26);
    for (int i = 'A'; i <= 'Z'; i ++)
      CHAR_MAP[i] = i - 'A';
  }
  static void InitNumericMap() {
    assert(MAX_INDEX >= 10);
    for (int i = '0'; i <= '9'; i ++)
      CHAR_MAP[i] = i - '0';
  }
  static void InitAlphaMap() {
    assert(MAX_INDEX >= 52);
    for (int i = 'a'; i <= 'z'; i ++)
      CHAR_MAP[i] = i - 'a';
    for (int i = 'A'; i <='Z'; i ++)
      CHAR_MAP[i] = i - 'A' + 26;
  }

  Trie() {
    memset(index, NULL, sizeof(index));
  }
  ~Trie() {
    for (int i = 0; i < MAX_INDEX; i ++) {
      if (index[i] != NULL)
        delete index[i];
    }
  }

  Trie* Find(const char *ch) {
    if (*ch == 0) {
      return this;
    }
    assert(*ch < 256 && CHAR_MAP[*ch] != -1);
    return index[CHAR_MAP[*ch]] == NULL ? NULL : index[CHAR_MAP[*ch]]->Find(ch + 1);
  }

  void Insert(const char *ch, T val) {
    if (*ch == 0) {
      value = val;
      return;
    }
    assert(*ch < 256 && CHAR_MAP[*ch] != -1);
    if (index[CHAR_MAP[*ch]] == NULL) {
      index[CHAR_MAP[*ch]] = new Trie<T>();
    }
    index[CHAR_MAP[*ch]]->Insert(ch + 1, val);
  }
  T value;
 private:
  Trie<T>* index[MAX_INDEX];
};

int main(int argc, char const *argv[]) {
  Trie<int> trie;
  trie.InitAlphaMap();
  assert(trie.Find("az") == NULL);
  trie.Insert("az", 1);
  assert(trie.Find("az")->value == 1);
  trie.Insert("az", 2);
  assert(trie.Find("az")->value == 2);
  return 0;
}

