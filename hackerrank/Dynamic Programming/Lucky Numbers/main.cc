// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang
// Solution: Dynamic programming, store the state(i, j, k) which means how many numbers have i digits
//  and sum of digits is j and sum of square digits is k,
//  suppose we can figure out how many lucky number less than a, the answer of this problem is:
//  lucky(b) - lucky(a - 1);
//  to calculate lucky(a) where a can be represent as "a1a2a3a4..", ai is the i-th digit,
//  the algorithm is enumerate the prefix of "a1a2a3a4.." to get the sum_prefix and square_sum_prefix

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define MAX_SUM 170
#define MAX_SQURE 1460
int prime[MAX_SQURE] = {0};
long long dp[20][MAX_SUM][MAX_SQURE] = {0};
long long cache[20][10][MAX_SUM][MAX_SQURE] = {0};
int start[20][MAX_SUM];
int end[20][MAX_SUM];

long long lucky_number(string& str) {
  if (str == "0") return 0LL;
  if (str == "1") return 0LL;
  long long ans = 0LL;
  int sum = 0;
  int squre_sum = 0;

  for (int i = str.size() - 1; i >= 0; i --) {
    for (int j = 0; j < str[i] - '0'; j ++) {
      if (cache[i][j][sum][squre_sum] == 0) {
        cache[i][j][sum][squre_sum] = 0LL;
        for (int k = 0; k <= 9 * i; k ++) {
          if (prime[k + sum + j]) continue;
          for (int l = start[i][k]; l <= end[i][k]; l ++) {
            if (!prime[l + squre_sum + j * j]) {
              cache[i][j][sum][squre_sum] +=dp[i][k][l];
            }
          }
        }
      }
      ans += cache[i][j][sum][squre_sum];
    }
    sum += (str[i] - '0');
    squre_sum += (str[i] - '0') * (str[i] - '0');
  }
  if (prime[sum] == 0 && prime[squre_sum] == 0) ans ++;
  return ans;
}

void init() {
  prime[0] = prime[1] = 1;
  for (int i = 2; i < MAX_SQURE; i ++) {
    if (!prime[i]) {
      for (int j = i * i; j < MAX_SQURE; j += i) {
        prime[j] = 1;
      }
    }
  }
  for (int i = 0; i < 20; i ++) {
    for (int j = 0; j < MAX_SUM; j ++) {
      start[i][j] = MAX_SQURE -1;
      end[i][j] = -1;
    }
  }

  dp[0][0][0] = 1;
  start[0][0] = 0;
  end[0][0] =  0;

  for (int i = 0; i < 17; i ++) {
    for (int j = 0; j <= i * 9; j ++) {
      for (int k = 0; k <= 81 * i; k ++) {
        if (dp[i][j][k] > 0) {
          for (int l = 0; l < 10; l ++) {
            dp[i + 1][j + l][k + l * l] += dp[i][j][k];
            start[i + 1][j + l] = min(start[i + 1][j + l], k + l * l);
            end[i + 1][j + l] = max(end[i + 1][j + l], k + l * l);
          }
        }
      }
    }
  }
}

int main() {
  init();
  int t;
  long long num1, num2;
  char buffer[50];
  scanf("%d\n", &t);
  while (t--) {
    scanf("%lld%lld",&num1, &num2);
    if (num1 > num2) swap(num1, num2);
    num1 --;
    snprintf(buffer, sizeof(buffer), "%lld", num1);
    string str1(buffer);
    snprintf(buffer, sizeof(buffer), "%lld", num2);
    string str2(buffer);

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    long long result = lucky_number(str2);

    result -= lucky_number(str1);
    printf("%lld\n", result);
  }
  return 0;
}