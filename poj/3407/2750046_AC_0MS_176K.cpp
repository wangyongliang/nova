#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

double x, y, xx, yy;
char a, b, c, d;
double px, py, pxx, pyy;

#define D(x) ((x)*PI/180.0)
inline void work()
{
	x+=px/60.0;
	y+=py/60.0;
	xx+=pxx/60.0;
	yy+=pyy/60.0;
	if (a=='S') x=-x;
	if (b=='W') y=-y;
	if (c=='S') xx=-xx;
	if (d=='W') yy=-yy;

	double cosc = sin( D(x) )*sin( D(xx) ) + cos( D(x) )*cos( D(xx) )*cos( D(y-yy) );

	double rad = acos( cosc );
	double ans = rad * 6370.0; 
	printf ("%.3lf\n", ans);
	return ;
}

int main ()
{
	while ( cin>>x>>px>>a>>y>>py>>b>>xx>>pxx>>c>>yy>>pyy>>d )
		work();

	return 0;
}
