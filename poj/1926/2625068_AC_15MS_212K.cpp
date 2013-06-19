#include<stdio.h>
int a[110];
int mp[110][110]={0},n;
bool flag[110];
double b[110];
double ans[110];
void dfs(int x)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(mp[x][i])
		{
			flag[i]=1;
			mp[x][i]=mp[i][x]=0;
			dfs(i);
		}
	}
}
int main()
{
	int i,j,x,y,m;
	double sum,cnt;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++) mp[i][j]=0;
		}
		for(i=1;i<=n;i++) 
		{
			scanf("%lf",&b[i] );
			a[i]=0;
			ans[i]=0;
		}
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			mp[x][y]=1;
			mp[y][x]=1;
			a[x]++;
			a[y]++;
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]>0)
			{
				for(j=1;j<=n;j++) flag[j]=0;
				flag[i]=1;
				dfs(i);
				sum=cnt=0.0;
				for(j=1;j<=n;j++)
				{
					if(flag[j])
					{
						sum+=b[j];
						cnt+=a[j];
					}
				}
				for(j=1;j<=n;j++)
				{
					if(flag[j])
					{
						ans[j]=sum*a[j]/cnt;
						a[j]=-1;
					}
				}
			}
			else if(a[i]==0) ans[i]=b[i];
		}
		for(i=1;i<=n;i++) printf("%.3lf\n",ans[i]);
	printf("\n");
	}
	return 0;
}
