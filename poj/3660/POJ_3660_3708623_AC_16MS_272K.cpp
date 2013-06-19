#include<stdio.h>
#define maxn 110
int a[maxn][maxn];
int b[maxn][maxn];
int flag[maxn];
int n;
void dfs(int x)
{
	if(flag[x]) return ;
	else
	{
		flag[x]=1;
		int i;
		for(i=1;i<=n;i++)
		{
			if(a[x][i]&&flag[i]==0) dfs(i);
		}
	}
}
void dfs1(int x)
{
	if(flag[x]) return ;
	else
	{
		flag[x]=1;
		int i;
		for(i=1;i<=n;i++)
		{
			if(b[x][i]&&flag[i]==0) dfs1(i);
		}
	}
}
int main()
{
	int m,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) a[i][j]=b[i][j]=0;
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			a[i][j]=b[j][i]=1;
		}
		int cnt,ans=0;;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++) flag[j]=0;
			cnt=0;
			dfs(i);
			for(j=1;j<=n;j++)
			{
				cnt+=flag[j];
				flag[j]=0;
			}
			dfs1(i);
			for(j=1;j<=n;j++) cnt+=flag[j];
			if(cnt==n+1) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}