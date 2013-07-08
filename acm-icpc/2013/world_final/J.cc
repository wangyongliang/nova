#include <iostream>
using namespace std;
#define inf 1e-6
typedef pair<double, double> Point;

double cross(Point a, Point b, Point c) {
  return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}
bool cut(Point a, Point b, double r, Point &result) {
  if (fabs(a.first - b.first) < inf) {
    if (r * r > a.first * a.first) {
      result.first = a.first;
      result.second = sqrt(r * r - a.first * a.first);
      return true;
    } else return false;
  } else {

  }
}
int main() {
  return 0;
}