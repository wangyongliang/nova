#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define GEO_TYPE double
#define INF 1e-6
// Present a point
class Point;
typedef Point Vector;
class Point {
public:
  double x;
  double y;
  Point(double xx, double yy): x(xx), y(yy){}
  Point(const Point& another) {
    x = another.x;
    y = another.y;
  }
  double distance(const Point &another) const{
    return sqrt((x - another.x) * (x - another.x) + (y - another.y) * (y - another.y));
  }
  bool equal(const Point &another) {
    return fabs(distance(another)) < INF;
  }
  Point operator+(const Point &second) const {
    return Point(x + second.x, y + second.y);
  }
  Point operator-(const Point &another) const {
    return Point(x - another.x, y - another.y);
  }
  double cross(const Point& another) const {
    return x * another.y - y * another.x;
  }
};

// Present a line
class Line {
public:
  Line(const Point &p1, const Point &p2): first(p1), second(p2) {}
  Point first;
  Point second;
  Vector to_vector() const {
    return Vector(second.x - first.x, second.y - first.y);
  }
  // Calculate intersection
  virtual bool intersection(const Line& another, Point &cross_point) {
  }
  virtual bool within(const Point &point) {
    Vector v1 = second - first;
    Vector v2 = point - first;
    return fabs(v1.cross(v2)) < INF;
  }
  // Test whether two lines are equals
  bool equal(const Line &another) {
    return within(another.first) && within(another.second);
  }
};

class Segment: public Line {
public:
  Segment(Point& p1, Point& p2): Line(p1, p2){}
  // TODO
  bool within(const Point &point){
  }
};

class Circle {
public:
  double r;
  Point center;
  // calculate all the intersection points
  void intersection(Line &line, vector<Point> points) {
  }
  bool onborder(const Point& point) {

  }
  bool within(const Point& point) {
    return fabs(center.distance(point) - r * r) < INF;
  }
  double area() {
    return 0.0;
  }
};

class Polygon {
public:
  int size() const {return points.size();}

  void push_back(const Point &p) {points.push_back(p);}

  Point& operator[](int index) {
    return points[(index % p.size() + p.size()) % p.size()];
  }
  double area() const {
    return 0.0;
  }
  bool within(const Point &point) {

  }
  bool onborder(const Point &point) {

  }
  Polygon* to_convex() const {
    Polygon convex = new Polygon();
    return convex;
  }
private:
  vector<Point> points;
};

int main() {
  Polygon polygon;
  const Point p(0.0, 0.0);
  polygon.push_back(p);
  polygon[0].x = 1;
  cout << polygon[0].x << endl;
  return 0;
}