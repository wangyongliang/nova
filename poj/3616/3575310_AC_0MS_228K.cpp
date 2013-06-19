#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
	int p;
}a[1100];
int ans[1100];
bool cmp(const node &x,const node &y)
{
	if(x.x==y.x) 
	{
		if(x.y==y.y) return x.p<y.p;
		else return x.y<y.y;
	}
	else return x.x<y.x;
}
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int n,m,r,i,j;
	while(scanf("%d%d%d",&n,&m,&r)!=EOF)
	{
		for(i=0;i<m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].p);
		sort(a,a+m,cmp);
		for(i=0;i<m;i++)
		{
			ans[i]=a[i].p;
			for(j=0;j<i;j++)
			{
				if(a[j].y+r<=a[i].x) ans[i]=max(ans[i],ans[j]+a[i].p);
			}
		}
		int tp=0;
		for(i=0;i<m;i++)
		{
		//	printf("%d ",ans[i]);
			if(a[i].y<=n) tp=max(tp,ans[i]);
		}
		printf("%d\n",tp);
	}
	return 0;

}