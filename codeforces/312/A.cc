// Copyright 2013 Yunrang Inc. All Rights Reserved.
// Author: Yongliang Wang

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX_BUFFER_SIZE 100000

char buffer[MAX_BUFFER_SIZE];
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  gets(buffer);
  string line;
  int bits = 0;
  while (n--) {
    gets(buffer);
    line = buffer;
    bits = 0;
    if (line.find("miao.") == 0) {
      bits += 1;
    }
    reverse(line.begin(), line.end());
    if (line.find(".alal") == 0){
      bits += 2;
    }

    if (bits == 1) {
      cout << "Rainbow's" << endl;
    } else if(bits == 2) {
      cout << "Freda's" << endl;
    } else {
      cout << "OMG>.< I don't know!" << endl;
    }
  }
  return 0;
}
