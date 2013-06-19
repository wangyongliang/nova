#include <stdio.h>
#include <math.h>
#define SIZE 110
const double Z = 1e-6;
struct Line
{
	double A,B;
	bool y;
}line[SIZE];
struct Point
{
	double x,y;
}in[SIZE],test[SIZE*SIZE];

int pnum,n;
void makepoint(Line &a, Line &b)
{
	if(!a.y && !b.y)
		return ;
	if(!a.y)
	{
		test[pnum].x = a.A;
		test[pnum++].y = b.A*a.A+b.B;
	}
	else if(!b.y)
	{
		test[pnum].x = b.A;
		test[pnum++].y = a.A*b.A+a.B;
	}
	else
	{
		if(a.A != b.A)
		{
			test[pnum].x = (b.B-a.B)/(a.A-b.A);
			test[pnum].y = test[pnum].x*b.A + b.B;
			pnum++;
		}
	}
}
double crossMul(Point a, Point b,Point c)
{
	b.y -= a.y; b.x -= a.x;
	c.y -= a.y; c.x -= a.x;
	return b.x*c.y-b.y*c.x;
}
bool check(Point p)
{
	int i;
	double temp,flg = 0;
	for(i = 0; i < n; i++)
	{
		temp = crossMul(in[i],in[(i+1)%n],p);
		if(fabs(temp) < Z)
			temp = 0.0;
		if(flg == 0)
			flg = temp;
		else if(flg*temp < 0)
			return false;
	}
	return true;
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i = 0; i < n; i++)
		{
			scanf("%lf%lf",&in[i].x,&in[i].y);
			line[i].y = true;
		}
		for(i = 1;i < n; i++)
		{
			if(in[i].x == in[i-1].x)
			{
				line[i].y = false;
				line[i].A = in[i].x;
			}
			else
			{
				line[i].A = (in[i].y-in[i-1].y)*1.0/(in[i].x-in[i-1].x);
				line[i].B = in[i-1].y - line[i].A*in[i-1].x;
			}
		}
		if(in[n-1].x == in[0].x)
		{
			line[0].y = false;
			line[0].A = in[0].x;
		}
		else
		{
			line[0].A = (in[0].y-in[n-1].y)*1.0/(in[0].x-in[n-1].x);
			line[0].B = in[n-1].y - line[0].A*in[n-1].x;
		}
		pnum = 0;
		for(i = 0; i < n; i++)
		{
			for(j = i+1; j < n; j++)
			{
				makepoint(line[i],line[j]);
			}
		}
		for(i = 0; i < pnum; i++)
			if(check(test[i]))
				break;
		if(i < pnum)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
