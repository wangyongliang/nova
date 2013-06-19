#include<stdio.h>
#define inf 1e-8
struct node
{
	int x;
	int y;
	double rat1,rat2,c1,c2;
}a[200];
int main()
{
	int n,m,i,j,s;
	int flag=0;
	int x,y;
	double ans[200];
	double tmp;
	while(scanf("%d%d%d%lf",&n,&m,&s,&tmp)!=EOF)
	{
		flag=0;
		if(tmp-inf<0.0) 
		{
			flag=1;
		}
		for(i=1;i<=n;i++) ans[i]=0.0;
		ans[s]=tmp;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%lf%lf%lf%lf",&a[i].x,&a[i].y,&a[i].rat1,&a[i].c1,&a[i].rat2,&a[i].c2);
		}
		if(flag)
		{
			printf("NO\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<m;j++)
			{
				x=a[j].x;
				y=a[j].y;
				if(ans[x]<(ans[y]-a[j].c2)*a[j].rat2) ans[x]=(ans[y]-a[j].c2)*a[j].rat2;
				if(ans[y]<(ans[x]-a[j].c1)*a[j].rat1) ans[y]=(ans[x]-a[j].c1)*a[j].rat1;
			}
		}
		for(j=0;j<m;j++)
		{
			x=a[j].x;
			y=a[j].y;
			if(ans[x]<(ans[y]-a[j].c2)*a[j].rat2) break;
			if(ans[y]<(ans[x]-a[j].c1)*a[j].rat1) break;
		}
		if(j==m) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
