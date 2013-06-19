#include <cstdio>
#include <cmath>
struct Point { 
	double x, y; 
	Point() {};
	Point( double _x, double _y ) : x(_x), y(_y) {};
};
const double Pi = 3.1415926535897932384626433832795;
inline double Cross( const Point& a, const Point& b ) { return a.y*b.x-a.x*b.y; }
Point Get(int r) {
	if (r==0) return Point(0,1);
	if (r==180) return Point(0,-1);
	double radian = (90.0f-r)/180.0f * Pi;
	return Point( cos(radian), sin(radian) );
}
int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		Point a,b,d,va,vb;
		int ra, rb;
		scanf("%lf%lf%d%lf%lf%d", &a.x, &a.y, &ra, &b.x, &b.y, &rb );
		d.x=a.x-b.x;
		d.y=a.y-b.y;
		va=Get(ra), vb=Get(rb);
		double up=-Cross(d,vb);
		double down=Cross(va,vb);
		double x=up/down;
		printf ( "%.4lf %.4lf\n", a.x+va.x*x, a.y+va.y*x );
	}
	return 0;
}
