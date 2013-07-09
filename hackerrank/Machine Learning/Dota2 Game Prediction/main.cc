// Author: wangyongliang.wyl@gmail.com (Wang Yongliang)
// github: https://github.com/wangyongliang
// Problem: https://www.hackerrank.com/challenges/dota2prediction (Dota 2 Game Prediction)
// Final score: 11
// Solution: predict via Bayes, but counting all the combination

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>

#define MAX_BUFFER_SIZE 1000
using namespace std;

class Judger {
public:
  Judger() {
    bits_count_[0] = 0;
    for (int i = 0; i < 5; i ++) {
      for (int j = 0; j < (1<<i); j ++) {
        bits_count_[(1<<i) + j] = bits_count_[j] + 1;
      }
    }

    for (int i = 0; i < 6; i ++) weight_[i] = i;

    FILE *fp = fopen("trainingdata.txt", "r");
    char buffer[MAX_BUFFER_SIZE];

    vector<int> left, right;
    int result;
    int cnt = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
      left.clear();
      right.clear();
      Split(buffer, left, right, result);
      sort(left.begin(), left.end());
      sort(right.begin(), right.end());
      if (result == 1) {
        Trian(left, 1);
        Trian(right, 0);
      } else {
        Trian(right, 1);
        Trian(left, 0);
      }
    }
    fclose(fp);
  }

  bool Judge(char buffer[]) {
    vector<int> left;
    vector<int> right;
    int result;
    Split(buffer, left, right, result);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    double score = CalculateScore(left, right);
    printf("%lf\n", score);
    return score > 0.0;
  }
private:
  void Split(char line[], vector<int>& left, vector<int> &right, int &result) {
    string player = "";
    for (int i = 0; line[i]; i ++) {
      if (line[i] == ',') {
        if (heros_[player] == 0) {
          heros_[player] = heros_.size() + 1;
        }
        if (left.size() < 5)
          left.push_back(heros_[player]);
        else
          right.push_back(heros_[player]);
        player ="";
      } else {
        player += line[i];
      }
    }
    if (player.size() == 0) return;
    if (player[0] == '1') result = 1;
    else if (player[0] == '2') result = -1;
    else {
      right.push_back(heros_[player]);
    }
  }

  long long Hash(vector<int> &players, int bitmap) {
    long long hash_code = 0;
    for (int i = 0; i < 5; i ++) {
      if (bitmap & (1 << i)) {
        hash_code = hash_code * 97 + players[i];
      }
    }
    return hash_code;
  }

  void Trian(vector<int> &players, int result) {
    long long hash_code;
    for (int i = 0; i < (1<<5); i ++) {
      hash_code = Hash(players, i);
      count_[hash_code] ++;
      win_[hash_code] += result;
    }
  }

  bool CalculateScore(long long hash_code, double &score) {
    if (count_[hash_code]) {
      score = win_[hash_code] * 1.0 / count_[hash_code];
      return true;
    }
    return false;
  }

  double CalculateScore(vector<int> &left, vector<int> &right) {
    long long hash_left;
    long long hash_right;
    double score = 0.0;

    vector<double> score_left[6];
    vector<double> score_right[6];
    long long hash_code;
    for (int i = 0; i < (1<<5); i ++) {
      hash_code = Hash(left, i);

      if (CalculateScore(hash_code, score)) {
        score_left[bits_count_[i]].push_back(score);
      }

      hash_code = Hash(right, i);
      if (CalculateScore(hash_code, score)) {
        score_right[bits_count_[i]].push_back(score);
      }
    }
    score = 0.0;
    double left_score = 1.0;
    double right_score = 1.0;

    for (int i = 0; i < 5; i ++) {
      sort(score_left[i].begin(), score_left[i].end(), greater<int>());
      sort(score_right[i].begin(), score_right[i].end(), greater<int>());
      for (int j = 0; j < score_left[i].size() && j < score_right[i].size(); j ++) {
        left_score = left_score * score_left[i][j];
        right_score = right_score * score_right[i][j];
        // score += (score_left[i][j] - score_right[i][j]) * weight_[i];
      }
    }
    return left_score - right_score;
  }

  map<string, int> heros_;
  map<long long, int> count_;
  map<long long, int> win_;
  int bits_count_[1<<5];
  double weight_[6];
};
int main() {
  Judger judger;
  char buffer[1000];
  int n;
  scanf("%d",&n);
  gets(buffer);
  while(n--) {
    gets(buffer);
    if (judger.Judge(buffer)) cout << 1;
    else cout << 2;
    cout << endl;
  }
  return 0;
}