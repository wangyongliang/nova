#include<stdio.h>
#define maxn 1000
#define inf 0x7ffffff
int n;
int a[maxn][maxn];
int flag[maxn];
int find(int x)
{
	int y=x,z;
	while(flag[y]!=y) y=flag[y];
	z=y;
	while(x!=flag[x])
	{
		y=x;
		x=flag[x];
		flag[y]=z;
	}
	return z;
}
int q[maxn],qq,p[maxn],pp;
int flg[maxn];
void dfs(int x)
{
	int i;
	flg[x]=1;
	for(i=1;i<=n;i++)
	{
		if(a[x][i]<inf&&flg[i]==0)
		{
			dfs(i);
		}
	}
	q[qq++]=x;
}
void dfs1(int x)
{
	int i;
	flg[x]=2;
	for(i=1;i<=n;i++)
	{
		if(a[i][x]<inf&&flg[i]==1)
		{
			dfs1(i);
		}
	}
	p[pp++]=x;
}
void scc()
{
	int i,j,k;
	for(i=1,qq=0;i<=n;i++) flg[i]=0;
	for(i=1;i<=n;i++)
	{
		if(flg[i]==0)
		{
			dfs(i);
			for(qq--;qq>=0;qq--)
			{
				if(flg[q[qq]]==1)
				{
					pp=0;
					dfs1(q[qq]);
					k=find(p[pp-1]);
					for(pp--;pp>=0;pp--)
					{
						j=find(p[pp]);
						flag[j]=k;
					}
				}
			}
		}
	}
	for(i=1;i<n;i++)
	{
		j=find(i);
	}
}
int dis[maxn];
int dij(int x,int y)
{
	int i,j,k;
	for(i=1;i<=n;i++) dis[i]=inf;
	dis[flag[x]]=0;
	y=flag[y];
	while(1)
	{
		for(i=1;i<=n&&dis[flag[i]]==-1;i++);
		for(j=i;i<=n;i++)
		{
			if(dis[flag[i]]!=-1&&dis[flag[i]]<dis[flag[j]]) j=i;
		}
		if(flag[j]==y) break;
		for(k=1;k<=n;k++)
		{
			if(flag[k]==flag[j]){
			for(i=1;i<=n;i++)
			{
				if(flag[i]!=flag[j]&&dis[flag[i]]!=-1)
				{
					if(dis[flag[i]]>dis[flag[j]]+a[k][i])
						dis[flag[i]]=dis[flag[j]]+a[k][i];
				}
			}
			}
		}
		dis[flag[j]]=-1;
	}
	if(dis[flag[j]]==inf) return -1;
	else return dis[flag[j]];
}
int main()
{
	int i,j,e,k,cnt=0;
	while(scanf("%d%d",&n,&e)&&(n+e))
	{
	//	if(cnt) printf("\n");
		cnt++;
		for(i=1;i<=n;i++) flag[i]=i;
		for(i=1;i<=n;i++) 
		{
			for(j=1;j<=n;j++) a[i][j]=inf;
		}
		while(e--)
		{
			scanf("%d%d%d",&i,&j,&k);
			a[i][j]=a[i][j]<k?a[i][j]:k;
		}
		scc();
	//	for(i=1;i<=n;i++) printf("%d ",flag[i]);
	//	printf("\n");
		scanf("%d",&e);
		while(e--)
		{
			scanf("%d%d",&i,&j);
			k=dij(i,j);
			if(k==-1) printf("Nao e possivel entregar a carta\n");
			else printf("%d\n",k);
		}
		printf("\n");
	}
	return 0;
}