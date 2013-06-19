#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define INF 10000000.0

#define EPS 1e-10

const double PI = acos(-1);

typedef struct Point
{
	char id;
	double x,y;
	Point () {};
	Point (double _x, double _y) {x=_x,y=_y;}
	double dist(const Point &p1)
	{
        return sqrt((p1.x-x)*(p1.x-x)+(p1.y-y)*(p1.y-y));
    }
	double cross(const Point &p1, const Point &p2)
	{
		double x1 = p1.x-x, y1 = p1.y-y, x2 = p2.x-x, y2 = p2.y-y;
		return (x1*y2-x2*y1);
	}
}Point;

typedef struct Interval
{
	double x1,x2;
}Interval;

int n,m,num;
char order[101];
Point local[101],c;
double ax[10100];
Interval ans[10010];

inline int sign(double x)
{
	if (fabs(x)<EPS) return 0;
	return x>0?1:-1;
}

bool cmp(const Point &a, const Point &b)
{
    int s = sign(c.cross(a,b));
	if (s!=0) return s<0;
	return a.x < b.x;
}

double calinter(Point &p1, Point &p2)
{
	return p1.x + (p1.y*(p1.x-p2.x)) / (p2.y-p1.y);
}

void work()
{
	int i,j,s1,s2;
	Point inf(INF,0), neinf(-INF,0);
	m = 0;
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			s1 = sign(local[i].y);
			s2 = sign(local[j].y);
			if (s1==0 && s2 == 0)
			{
				ax[m++] = local[i].x,ax[m++] = local[j].x;
				//return;
			}
			else if (s1 == 0)
			{
				ax[m++] = local[i].x;
			}
			else if (s2 == 0)
			{
				ax[m++] = local[j].x;
			}
			else if (sign(local[i].y-local[j].y))
			{
				ax[m++] = calinter(local[i],local[j]);
				//if (ax[m-1]>100 || ax[m-1]<-100) m--;
			}
		}
	}
	ax[m++] = INF;
	ax[m++] = -INF;
	sort(ax,ax+m);
	num = 0;
	for (i=0; i<m-1; i++)
	{
		c.x = (ax[i]+ax[i+1]) / 2.0;
		c.y = 0.0;
		if (sign(ax[i]-c.x) == 0 || sign(ax[i+1]-c.x)==0) continue;
		sort(local,local+n,cmp);
		for (j=0; j<n; j++)
		{
			if (j<n-1 && sign(c.cross(local[j],local[j+1])) == 0 && sign(local[j].x-c.x) == sign(local[j+1].x-c.x)) break;
			if (local[j].id != order[j])
				break;
		}
		if (j==n)
		{
			ans[num].x1 = ax[i],ans[num++].x2 = ax[i+1];
		}
	}
	if (num==0)
	{
		printf("0\n");
		return;
	}
	printf("%d\n",num);
	//cout.precision(6);
	for (i=0; i<num; i++)
	{
		if (sign(ans[i].x1+INF)==0) printf("* ");
		else
		{printf("%.9lf ",ans[i].x1);
			//cout << ans[i].x1<<" ";
		}//
		if (sign(ans[i].x2-INF)==0) printf("* ");
		else
		{printf("%.9lf ",ans[i].x2);
			//cout << ans[i].x2<<" ";
		}//
	}
	printf("\n");
}

int main()
{
	int i;
	char ch[2];
	scanf("%d",&n);
	scanf("%s",order);
	for (i=0; i<n; i++)
	{
		scanf("%s%lf%lf",ch,&local[i].x,&local[i].y);
		local[i].id = ch[0];
	}
	work();
	return 0;
}
