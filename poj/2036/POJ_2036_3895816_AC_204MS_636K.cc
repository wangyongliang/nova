#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct node
{
	double k,d;
	double min, max;
}a[11000];
double eps=1e-5;
bool cmp(const node &x,const node &y)
{
	if(fabs(x.k-y.k)<eps) 
	{
		if(fabs(x.d-y.d)<eps)
		{
			if(fabs(x.min-y.min)<eps) return x.max<y.max;
			else return x.min<y.min;
		}
		else return x.d<y.d;
	}
	else return x.k<y.k;
}
int main()
{
	int i,j,n;
	double x1,x2,y1,y2;

	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			if(fabs(x1-x2)<eps)
			{
				a[i].k=1e200;
				a[i].d=x1;
				a[i].min=y1;
				a[i].max=y2;
			}
			else 
			{
				double dx=x1-x2;
				double dy=y1-y2;
				a[i].k=dy/dx;
				a[i].d=y1-a[i].k*x1;
				a[i].min=x1;
				a[i].max=x2;
			}
			if(a[i].min>a[i].max) swap(a[i].min,a[i].max);
		//	if(fabs(a[i].k)<eps&&fabs(a[i].d-6.58)<eps)
		//		printf("%.2lf %.2lf\n",a[i].k,a[i].d);
		}
		sort(a,a+n,cmp);
		int sum=1;
		double min,max;
		max=a[0].max;
		for(i=1;i<n;i++)
		{
			if(fabs(a[i].k-a[i-1].k)<eps&&fabs(a[i].d-a[i-1].d)<eps)
			{
				if(a[i].min<max+eps) max=a[i].max>max?a[i].max:max;
				else
				{
					sum++;
					min=a[i].min;
					max=a[i].max;
				}
			}
			else 
			{
				sum++;
				max=a[i].max;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}