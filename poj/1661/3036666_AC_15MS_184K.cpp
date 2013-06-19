#include<stdio.h>
#include<algorithm>
using namespace std;
#define size 1000+10
bool b[size][2];
struct node
{
	int h,x,y;
}a[size];
bool cmp(const node &i,const node &j)
{
	return i.h>j.h;
}
__int64 ans[size][2];
int main()
{
	int n,i,j;
	int t;
	__int64 inf,max;
	scanf("%d",&t);
	inf=1;
	inf<<=60;
	while(t--)
	{
		scanf("%d%d%d%I64d",&n,&a[0].x,&a[0].h,&max);
		a[0].y=a[0].x;
		ans[0][0]=ans[0][1]=0;
		for(i=0;i<=n+1;i++) b[i][0]=b[i][1]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].h);
			if(a[i].h==0) while(1);
		}
		sort(a,a+n+1,cmp);
		for(i=1;i<=n;i++)
		{
			ans[i][0]=ans[i][1]=inf;
			for(j=0;j<i;j++)
			{
				if(a[j].h==a[i].h||a[j].h-a[i].h>max) continue;
				if(a[j].x>=a[i].x&&a[j].x<=a[i].y&&b[j][0]==0)
				{
					b[j][0]=1;
					if(ans[i][0]>ans[j][0]+a[j].h-a[i].h+a[j].x-a[i].x) 
						ans[i][0]=ans[j][0]+a[j].h-a[i].h+a[j].x-a[i].x;
					if(ans[i][1]>ans[j][0]+a[j].h-a[i].h+a[i].y-a[j].x)
						ans[i][1]=ans[j][0]+a[j].h-a[i].h+a[i].y-a[j].x;
				}
				if(a[j].y>=a[i].x&&a[j].y<=a[i].y&&b[j][1]==0)
				{
					b[j][1]=1;
					if(ans[i][0]>ans[j][1]+a[j].h-a[i].h+a[j].y-a[i].x)
						ans[i][0]=ans[j][1]+a[j].h-a[i].h+a[j].y-a[i].x;
					if(ans[i][1]>ans[j][1]+a[j].h-a[i].h+a[i].y-a[j].y)
						ans[i][1]=ans[j][1]+a[j].h-a[i].h+a[i].y-a[j].y;
				}
			}
		}
		__int64 min=inf;
		for(i=0;i<=n;i++)
		{
			if(b[i][0]==0&&a[i].h<=max) min=min>ans[i][0]+a[i].h?ans[i][0]+a[i].h:min;
			if(b[i][1]==0&&a[i].h<=max) min=min>ans[i][1]+a[i].h?ans[i][1]+a[i].h:min;
		}
		printf("%I64d\n",min);
	}
	return 0;
}