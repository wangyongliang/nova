#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct node
{
	double x1,y1,x2,y2;
}a[1000];
double inf=1e-6;
bool cmp(const node &x,const node &y)
{
	if(fabs(x.y1-y.y1)<inf) return x.y2<y.y2;
	else return x.y1<y.y1;
}
double x[1000];
int main()
{
	int n,i,j;
	int t=1;
//	freopen("atlantis.in","r",stdin);
//	freopen("atlantis.out","w",stdout);
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) 
		{
			scanf("%lf%lf%lf%lf",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
			x[i*2]=a[i].x1;
			x[i*2+1]=a[i].x2;
		}
		sort(x,x+2*n);
		sort(a,a+n,cmp);
		double ans=0.0,tp,y1,y2;
		for(i=0;i<n*2-1;i++)
		{
			y1=y2=0.0;
			tp=0.0;
			for(j=0;j<n;j++)
			{
				if(a[j].x1<x[i]+inf&&a[j].x2>x[i+1]-inf){
				if(a[j].y1>y2)
				{
					tp+=(x[i+1]-x[i])*(y2-y1);
					y1=a[j].y1;
					y2=a[j].y2;
				}
				else y2=a[j].y2;
				}
			}
			tp+=(x[i+1]-x[i])*(y2-y1);
			ans+=tp;
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",t++,ans);
	//	printf("%.2lf\n",ans);

	}
	return 0;
}
