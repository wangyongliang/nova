#include<stdio.h>
#include<vector>

using namespace std;

#define maxn 200000+100
vector<int> a[maxn],b[maxn];
int n,cnt[maxn];
int flag[maxn];
int q[maxn],qq,p[maxn],pp;
void dfs1(int x)
{
	int i;
	flag[x]=1;
	for(i=0;i<a[x].size();i++)
	{
		if(flag[a[x][i]]==0)
		{
			dfs1(a[x][i]);
		}
	}
	q[qq++]=x;
}
void dfs2(int x)
{
	int i;
	flag[x]=2;
	for(i=0;i<b[x].size();i++)
	{
		if(flag[b[x][i]]==1)
		{
			dfs2(b[x][i]);
		}
	}
	p[pp++]=x;
}
int ID[maxn];
int dp[maxn],ans[maxn];
int find(int x)
{
	int y=x,z;
	while(ID[y]!=y) y=ID[y];
	while(ID[x]!=x)
	{
		z=x;
		x=ID[x];
		ID[z]=y;
	}
	return y;
}

void dfs3(int x)
{
	int max=0,i;
	flag[x]=1;
	for(i=0;i<b[x].size();i++)
	{
		if(flag[b[x][i]]==0) dfs3(b[x][i]);
	}
	ans[x]=dp[x];
	for(i=0;i<b[x].size();i++)
	{
		ans[x]+=ans[b[x][i]];
	}
}
int scc()
{
	int i,j,x,y;
	for(i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			qq=0;
			dfs1(i);
			for(j=qq-1;j>=0;j--)
			{
				if(flag[q[j]]==1)
				{
					pp=0;
					dfs2(q[j]);
					x=find(p[pp-1]);
					dp[x]=pp;
					for(pp-=2;pp>=0;pp--)
					{
						y=find(p[pp]);
						ID[y]=x;
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++) 
	{
		x=find(i);
		b[i].clear();
	}
	for(i=1;i<=n;i++)
	{
		x=ID[i];
		flag[i]=0;
		for(j=0;j<a[i].size();j++)
		{
			y=ID[a[i][j]];
			if(x!=y)	b[y].push_back(x);
		}
	}
	int ret=0;
	for(i=1;i<=n;i++)
	{
		if(flag[i]==0) dfs3(i);
		if(ans[i]==n) ret+=dp[i];
	}
	return ret;
}
int main()
{
	int m,i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			a[i].clear(),b[i].clear();
			ans[i]=flag[i]=dp[i]=0;
			ID[i]=i;
		}
		while(m--)
		{
			scanf("%d%d",&i,&j);
			a[i].push_back(j);
			b[j].push_back(i);
		}
		m=scc();
		printf("%d\n",m);
	}
	return 0;
}