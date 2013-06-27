#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<pair<int, int>, pair<int, int> > Square;
typedef pair<int, int> Point;

bool Within(int x, const pair<int, int> &interval) {
  return interval.first < x && interval.second > x;
}

bool Within(const pair<int, int> &x, const pair<int, int> &y) {
  return y.first <= x.first && x.second <= y.second;
}

int Area(const Square &square) {
  return (square.first.second - square.first.first) * (square.second.second - square.second.first);
}
int main() {
  int n, w, h;
  while (cin >> w >> h >> n) {
    Square square = make_pair(make_pair(0, w), make_pair(0, h));
    Square line;
    vector<Square> squares;
    vector<Square> lines;
    squares.push_back(square);
    for (int i  = 0; i < n; i ++) {
      cin >> line.first.first >> line.second.first >> line.first.second >> line.second.second;
      lines.push_back(line);
    }

    bool flag = false;
    for (int i = 0; i < lines.size(); i ++) {
      flag = false;
      line = lines[i];
      for (int j = 0; j < squares.size(); j ++) {
        if (line.first.first == line.first.second) {
          if (Within(line.first.first, squares[j].first) && Within(squares[j].second, line.second)) {
            // cout << squares[i].first.first << " " << squares[i].first.second << " " << squares
            square.second = squares[j].second;
            square.first.first = line.first.first;
            square.first.second = squares[j].first.second;
            squares[j].first.second = line.first.first;
            squares.push_back(square);
            flag = true;
          }
        } else {
          if (Within(line.second.second, squares[j].second) && Within(squares[j].first, line.first)) {
            square.first = squares[j].first;
            square.second.first = line.second.first;
            square.second.second = squares[j].second.second;
            squares[j].second.second = line.second.second;
            squares.push_back(square);
            flag = true;
          }
        }
      }
      if (!flag) {
        lines.push_back(line);
      }
    }

    vector<int> areas;
    for (int i = 0; i < squares.size(); i ++) {
      areas.push_back(Area(squares[i]));
    }
    sort(areas.begin(), areas.end());
    for (int i = 0; i < areas.size(); i ++) cout << areas[i] << " ";
    cout << endl;
  }
  return 0;
}