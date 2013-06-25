#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

struct Point {
  int x, y;
} pts[1000];

bool cmp( const Point &a, const Point &b ) {
  if ( a.y == b.y )
    return a.x < b.x;
  return a.y < b.y;
}

double sqr( double );
bool Right( Point, Point, Point );
double det( double, double, double, double );

int main() {
  int n, r;
  int i, top;
  int list[1000];

  double pi = acos( -1.0 );
  double Circumference;

  while ( scanf ( "%d %d", &n, &r ) != EOF ) {
    for ( i = 0; i < n; i ++ )
      scanf ( "%d %d", &( pts[i].x ), &( pts[i].y ) );
    sort ( pts, pts + n, cmp );

    list[0] = 0;
    list[1] = 1;
    top = 2;
    for ( i = 2; i < n; i ++ ) {
      while ( top > 1 && Right( pts[i], pts[ list[ top - 1 ] ], pts[ list[ top - 2 ] ] ) )
        top --;
      list[ top ++ ] = i;
    }
    for ( i = n - 1; i >= 0; i -- ) {
      while ( top > 2 && Right( pts[i], pts[ list[ top - 1 ] ], pts[ list[ top - 2 ] ] ) )
        top --;
      list[ top ++ ] = i;
    }

    Circumference = 0;
    for ( i = 1; i < top; i ++ )
      Circumference += sqrt( sqr( pts[ list[i] ].x - pts[ list[ i - 1 ] ].x ) + sqr( pts[ list[i] ].y - pts[ list[ i - 1 ] ].y ) );
    Circumference += pi * r * 2;

    printf( "%.0lf\n", Circumference );
  }

  return 0;
}

double sqr( double x ) {
  return x * x;
}

double det( double x1, double y1, double x2, double y2 ) {
  //  cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << ( x1 * y2 ) - ( x2 * y1 ) << endl;
  return ( x1 * y2 ) - ( x2 * y1 );
}

bool Right( Point a, Point b, Point c ) {
  if ( det( a.x - b.x, a.y - b.y, b.x - c.x, b.y - c.y ) > 0 )
    return true;

  return false;
}
