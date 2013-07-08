// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github:https://github.com/wangyongliang
// this problem can be sovle by data structure named Trie
// final score: 49.32
// there should be some bugs in the trie construction, such as spliting words

#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
  Node() {
    for (int i = 0; i < 26; i ++)
      index[i] = NULL;
    count = 0;
  }
  ~Node() {
    for (int i = 0; i < 26; i ++) {
      if (index[i] != NULL) delete index[i];
    }
  }
  Node *index[26];
  int count;
};

class Trie {
public:
  Trie() {
    string delimter = "!\"#$%&'()*+,-./0123456789:;<=>?@[]^_|~";
    root_ = NULL;
    FILE *fp = fopen("corpus.txt", "r");
    char buffer[1000];
    int len;
    while (fscanf(fp, "%s", buffer) != EOF) {
      len = strlen(buffer);

      for (len -- ; len >= 0; len --) {
        if (isalpha(buffer[len])) break;
        buffer[len] = '\0';
      }
      for (; len >= 0; len --) {
        buffer[len] = char(tolower(buffer[len]));
      }
      Insert(buffer);
    }
    fclose(fp);
  }

  ~Trie() {
    if (root_ != NULL) {
      delete root_;
    }
  }

  void Insert(char str[]) {
    if (root_ == NULL) root_ = new Node();
    Insert(root_, str, 0);
  }

  Node* Find(char buffer[]) {
    return Find(root_, buffer, 0);
  }

private:
  void Insert(Node *current, char str[], int pos) {
    if (!str[pos]) { // stop at the end of string
      current->count ++;
      return;
    }
    if (!isalpha(str[pos])) { 
      // split string into words by non-alpha char
      current->count ++;
      Insert(root_, str, pos + 1);
    } else {
      int idx = str[pos] - 'a';
      if (current->index[idx] == NULL) {
        current->index[idx] = new Node();
      }
      Insert(current->index[idx], str, pos + 1);
    }
  }

  // Get the last node of this string, return NULL
  // if string isn't existed in Trie
  Node* Find(Node *current, char str[], int pos) {
    if (current == NULL) 
      return NULL;
    if (!str[pos]) {
      return current->count > 0 ? current:NULL;
    }
    if (!isalpha(str[pos]))
      return NULL;
    int idx = tolower(str[pos]) - 'a';
    Node *result =  NULL;
    if (current->index[idx] != NULL) {
      return Find(current->index[idx], str, pos + 1);
    } else {
      return NULL;
    }
  }
  Node *root_;
};
bool update_result(Node* result, char str[], 
                  Node* new_result, char new_str[]) {
  if (new_result == NULL) return false;
  if (result == NULL) 
    return true;
  if (result->count < new_result->count)
    return true;
  else if (result->count > new_result->count)
    return false;
  if (strcmp(str, new_str) > 0)
    return true;
  return false;
}

int main(int argc, char const *argv[]) {
  Trie trie;
  char copy[300];
  char buffer[300];
  Node *result;
  Node *tmp;
  char ans[30];
  int query;
  scanf("%d", &query);
  gets(buffer);
  while (query -- ) {
    gets(buffer);
    int len = strlen(buffer);
    if (len > 20) goto end;
    result = trie.Find(buffer);
    if (result) {
      strcpy(ans, buffer);
      goto end;
    }
    
    if (len > 1) {
      for (int i = 0; buffer[i]; i ++) {
        for (int j = 0; buffer[j]; j ++) {
          if (j == i) continue;
          copy[j - (j > i)] = buffer[j];
        }
        copy[len - 1] = 0;
        // printf("%s\n", copy);
        tmp = trie.Find(copy);
        if (update_result(result, ans, tmp, copy)) {
          result = tmp;
          strcpy(ans, copy);
        }
      }
    }

    // replace char
    strcpy(copy, buffer);
    for (int i = 0; buffer[i]; i ++) {
      for (char ch = 'a'; ch <= 'z'; ch ++) {
        if (ch == buffer[i]) continue;
        copy[i] = ch;
        tmp = trie.Find(copy);
        if (update_result(result, ans, tmp, copy)) {
          result = tmp;
          strcpy(ans, copy);
        }
      }
      copy[i] = buffer[i];
    }

    // add one char
    for (int i = 0; buffer[i]; i ++) {
      copy[i] = buffer[i];
      for (char ch = 'a'; ch <= 'z'; ch ++) {
        copy[i + 1] = ch;
        strcpy(copy + i + 2, buffer + i + 1);
        tmp = trie.Find(copy);
        if (update_result(result, ans, tmp, copy)) {
          result = tmp;
          strcpy(ans, copy);
        }
      }
    }

    // swap two char
    strcpy(copy, buffer);
    for (int i = 0; buffer[i + 1]; i ++) {
      swap(copy[i], copy[i + 1]);
      tmp = trie.Find(copy);
      if (update_result(result, ans, tmp, copy)) {
        result = tmp;
        strcpy(ans, copy);
      }
      swap(copy[i + 1], copy[i]);
    }
end:
    if (result) {
      printf("%s\n", ans);
    } else {
      printf("%s\n", buffer);
    }
  }
  return 0;
}