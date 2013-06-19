#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const int maxn = 2000;
struct point
{
    double x, y;
};
struct cp
{
    int n;
    point p[maxn];
};
double dist(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
point intersectL(double a1, double b1, double c1, double a2, double b2, double c2)
{
    point ret;
    ret.y=(a1*c2-c1*a2)/(b1*a2-a1*b2);
    if(fabs(a2) < eps)    ret.x = -(b1 * ret.y + c1) / a1;
    else
        ret.x = -(b2 * ret.y + c2) / a2;
    return ret;
}
double Cross(point inpA, point inpB, point inpC)
{
    return (inpB.x - inpA.x) * (inpC.y - inpA.y) - (inpC.x - inpA.x) * (inpB.y - inpA.y);
}
void get_line(point inpA, point inpB, double &a1, double &b1, double &c1)
{
    a1 = inpB.y - inpA.y;
    b1 = inpA.x - inpB.x;
    c1 = inpA.y * (inpB.x - inpA.x) - inpA.x * (inpB.y - inpA.y);
}
cp cut(point inpA, point inpB, cp incp)
{
    cp ret;
    point cross;
    int i, j;
    double t1, t2;
    double a1, b1, c1, a2, b2, c2;  
    ret.n = 0;
    for (i = 0; i < incp.n; i++)
    {
        j = i + 1;
        t1 = Cross(inpA, inpB, incp.p[i]);
        t2 = Cross(inpA, inpB, incp.p[j]);
        if (t1 < eps && t2 < eps)
        {
            ret.p[ret.n++] = incp.p[i];
            ret.p[ret.n++] = incp.p[j];
        }
        else if (t1 > eps && t2 > eps)    continue;
        else
        {
            get_line(inpA, inpB, a1, b1, c1);
            get_line(incp.p[i], incp.p[j], a2, b2, c2);
            cross = intersectL(a1, b1, c1, a2, b2, c2);
            if (t1 < eps)
            {
                ret.p[ret.n++] = incp.p[i];
                ret.p[ret.n++] = cross;
            }
            else
            {
                ret.p[ret.n++] = cross;
                ret.p[ret.n++] = incp.p[j];
            }
        }
    }
    if (ret.n == 0)    return ret;
	ret.p[ret.n++]=ret.p[0];
	for(j=i=1;i<ret.n;i++)
	{
		if(dist(ret.p[i],ret.p[i-1])>eps) ret.p[j++]=ret.p[i];
	}
	ret.n=j-1;
    return ret;
}

double area(cp ret)
{
	int n,i;
	double ans=0.0;
	if(ret.n<3)return 0.0;
	point p0;
	p0.x=0.0;
	p0.y=0.0;
	n=ret.n;
	for(i=0;i<n;i++)
	{
		ans+=Cross(p0,ret.p[i],ret.p[i+1]);
	}
	return ans/2.0;
}


int main()
{
    int n, r;
	int i,j;
    cp input, ret;
	int t;
	point p1,p2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%lf%lf",&ret.p[i].x,&ret.p[i].y);
		ret.p[n]=ret.p[0];
		ret.n=n;
		double ans=area(ret);
		if(ans>0.0)
		{
			for(i=n-1,j=0;i>=0;i--,j++) input.p[j]=ret.p[i];
			input.p[n]=input.p[0];
			input.n=n;
		}
		else input=ret;
	//	input=ret;
		ret=input;
		for(i=0;i<n;i++)
		{
			p1=input.p[i];
			p2=input.p[i+1];
			ret=cut(p1,p2,ret);
			if(ret.n<3) break;
		}
		ans=area(ret);
		printf("%.2lf\n",fabs(ans));
	}
    return 0;
}