#include <stdio.h>
#include <math.h>
#define SIZE 105

const double ZERO = (1e-8);
int n;
struct Point
{
	double x,y;
};
struct Seg
{
	Point a,b;
}seg[SIZE];

double crossMul(Point a,Point b,Point c,Point d)
{
	b.x -= a.x;
	b.y -= a.y;
	d.x -= c.x;
	d.y -= c.y;
	return b.x*d.y - b.y*d.x;
}

bool same(Point &a,Point &b)
{
	if(fabs(a.x-b.x) < ZERO && fabs(a.y-b.y) < ZERO)
		return true;
	return false;
}

bool twoside(Point a,Point b,Point c, Point d)
{
	return crossMul(c,a,c,d)*crossMul(c,d,c,b) > -ZERO;
}

bool check(Point a,Point b)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(!twoside(seg[i].a,seg[i].b,a,b))
			return false;
	}
	return true;
}

bool itcan()
{
	int i,j;
	for(i = 0; i < n; i++)
	{
		if(!same(seg[i].a,seg[i].b) && check(seg[i].a,seg[i].b))
			return true;
		for(j = i+1; j < n; j++)
		{
			if(!same(seg[i].a,seg[j].b) && check(seg[i].a,seg[j].b))
				return true;
			if(!same(seg[i].a,seg[j].a) && check(seg[i].a,seg[j].a))
				return true;
			if(!same(seg[i].b,seg[j].b) && check(seg[i].b,seg[j].b))
				return true;
			if(!same(seg[i].b,seg[j].a) && check(seg[i].b,seg[j].a))
				return true;
		}
	}
	return false;
}

int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i = 0; i < n; i++)
			scanf("%lf%lf%lf%lf",&seg[i].a.x,&seg[i].a.y,&seg[i].b.x,&seg[i].b.y);
		if(itcan())
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	return 0;
}

