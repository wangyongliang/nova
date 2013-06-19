#include<stdio.h>
#define inf 1000000
struct node
{
	int x;
	int y;
	int z;
}a[2600],b[2600];
int main()
{
	int i,j,t,n,m,w;
	int x,y;
	int ans[600];
	int cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&w);
		for(i=1;i<=n;i++) ans[i]=inf;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		for(j=0;j<w;j++) scanf("%d%d%d",&b[j].x,&b[j].y,&b[j].z);
		for(i=1;i<=n;i++)
		{
			cnt=0;
			for(j=0;j<m;j++)
			{
				x=a[j].x;
				y=a[j].y;
				if(ans[x]>ans[y])
				{
					if(ans[x]>ans[y]+a[j].z) ans[x]=ans[y]+a[j].z,cnt++;
				}
				else
				{
					if(ans[y]>ans[x]+a[j].z) ans[y]=ans[x]+a[j].z,cnt++;
				}
			}
			for(j=0;j<w;j++)
			{
				x=b[j].x;
				y=b[j].y;
				if(ans[y]>ans[x]-b[j].z) ans[y]=ans[x]-b[j].z,cnt++;
			}
			if(cnt==0)
			{
				printf("NO\n");
				goto line;
			}
		}
		for(j=0;j<m;j++)
		{
			x=a[j].x;
			y=a[j].y;
			if(ans[x]>ans[y])
			{
				if(ans[x]>ans[y]+a[j].z) break;
			}
			else
			{
				if(ans[y]>ans[x]+a[j].z) break;
			}
		}
		if(j<m) printf("YES\n");
		else
		{
		
		for(j=0;j<w;j++)
		{
			x=b[j].x;
			y=b[j].y;
			if(ans[y]>ans[x]-b[j].z) break;
		}
		if(j<w) printf("YES\n");
		else printf("NO\n");
		}
line:;
	}
	return 0;
}


