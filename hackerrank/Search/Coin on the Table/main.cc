#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;
int dp[2][61][61];
int dx[] = { 0, 0, -1, 1};
int dy[] = {-1, 1,  0, 0};
int idx[256] = {0};
int main() {
  // freopen("data.txt", "r", stdin);
  idx['L'] = 0;
  idx['R'] = 1;
  idx['U'] = 2;
  idx['D'] = 3;
  char dir[] = {'L', 'R', 'U', 'D'};
  int n, m, k;
  cin >> n >> m >> k;
  string table[52];
  for (int i = 0; i < n; i ++)
    cin >> table[i];
  bool flag = 0;
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++)
      dp[flag][i][j] = INT_MAX;
  dp[flag][0][0] = 0;

  for (int i = 0; i < k; i ++) {
    for (int j = 0; j < n; j ++)
      for (int k = 0; k < m; k ++)
        dp[1 - flag][j][k] = INT_MAX;
    for (int j = 0; j < n; j ++) {
      for (int k = 0; k < m; k ++) {
        if (dp[flag][j][k] < INT_MAX) {
          if (table[j][k] == '*')
            dp[1 - flag][j][k] =  min(dp[1 - flag][j][k], dp[flag][j][k]);
          else {
            for (int l = 0; l < 4; l ++) {
              int ii = j + dx[idx[dir[l]]];
              int jj = k + dy[idx[dir[l]]];

              if (ii >= 0 && ii < n && jj >= 0 && jj < m)
                dp[1 - flag][ii][jj] = min(dp[1 - flag][ii][jj],
                  dp[flag][j][k] + (dir[l] != table[j][k]));
            }
          }
        }
      }
    }
    flag = 1 - flag;
  }
  int answer = -1;
  for (int j = 0; j < n; j ++)
    for (int k = 0; k < m; k ++)
      if (table[j][k] == '*' && dp[flag][j][k] < INT_MAX)
        answer = dp[flag][j][k];
  cout << answer << endl;
  return 0;
}