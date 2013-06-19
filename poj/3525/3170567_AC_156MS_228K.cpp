#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const int maxn = 400;
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
    ret.y = (a1 * c2 - c1 * a2) / (b1 * a2 - a1 * b2);
    if (fabs(a2) < eps)
        ret.x = -(b1 * ret.y + c1) / a1;
    else
        ret.x = -(b2 * ret.y + c2) / a2;
    return ret;
}

bool isEqual(point inpA, point inpB)
{
    return (fabs(inpA.x - inpB.x) < eps && fabs(inpA.y - inpB.y) < eps);
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
        else if (t1 > eps && t2 > eps)
            continue;
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
    if (ret.n == 0)
        return ret;
    for (i = 1, j = 1; i < ret.n; i++)
        if (!isEqual(ret.p[i - 1], ret.p[i]))
            ret.p[j++] = ret.p[i];
    ret.n = j;
    if (ret.n != 1 && isEqual(ret.p[ret.n - 1], ret.p[0]))
        ret.n--;
    ret.p[ret.n] = ret.p[0];
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
	return fabs(ans)/2.0;
}
int main()
{
    int n,i,j;
    cp input, ret;
	int flag;
	double min,max,mid,r;
	//freopen("I.in","r",stdin);
	//freopen("ii.out","w",stdout);
	while(scanf("%d",&n)&&n)
	{
		input.n=n;
		for(i=n-1;i>=0;i--) scanf("%lf%lf",&input.p[i].x,&input.p[i].y);
		input.p[n]=input.p[0];
		min=0.0;
		max=10000;
		while(max-min>1e-8)
		{
			mid=(min+max)/2.0;
			ret=input;
			flag=1;
			r=mid;
			for (int i = 0; i < n; i++)
			{
				point ta, tb, tt;
				tt.x = input.p[i + 1].y - input.p[i].y;
				tt.y = input.p[i].x - input.p[i + 1].x;
				double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);
				tt.x = tt.x * k;
				tt.y = tt.y * k;
				
				ta.x = input.p[i].x + tt.x;
				ta.y = input.p[i].y + tt.y;
				tb.x = input.p[i + 1].x + tt.x;
				tb.y = input.p[i + 1].y + tt.y;
				ret = cut(ta, tb, ret);
			}
			if(ret.n) min=mid;
			else max=mid;
		}
		printf("%.6lf\n",min);
	}
    return 0;
}
