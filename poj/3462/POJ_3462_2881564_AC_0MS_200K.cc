#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	double x1,x2;
}a[210];
double x,y;
double f(double xx,double yy)
{

		return -y*(x-xx)/(y-yy)+x;
}
bool cmp(const node &x1,const node &x2)
{
	return x1.x1<x2.x1;
}
int main()
{
	int t;
	int i,j,n;
	double temp;
	double xx,yy;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%lf%lf",&x,&y);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&xx,&yy);
			a[i].x1=f(xx,yy);
			scanf("%lf%lf",&xx,&yy);
			a[i].x2=f(xx,yy);
			if(a[i].x1>a[i].x2)
			{
				temp=a[i].x1;
				a[i].x1=a[i].x2;
				a[i].x2=temp;
			}
		}
		sort(a,a+n,cmp);
		int ans=2;
		double max,min;
		min=a[0].x1;
		max=a[0].x2;
		for(i=1;i<n;i++)
		{
			if(a[i].x1>max) 
			{
				ans++;
				min=a[i].x1;
				max=a[i].x2;
			}
			else 
			{
				max=max<a[i].x2?a[i].x2:max;
			}
		}
		if(n==0) printf("1\n");
		else 	printf("%d\n",ans);
	}
	return 0;
}
