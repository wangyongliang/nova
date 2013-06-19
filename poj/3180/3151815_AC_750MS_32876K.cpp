
#include<stdio.h>
#include<vector>
using namespace std;
#define maxn 1000000
vector<int> a[maxn],b[maxn];
int n,m,cnt;
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
void scc()
{
	int i,j;
	for(i=1;i<=n;i++) flag[i]=0;
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
					cnt+=(pp>1);
				}
			}
		}
	}
}
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		cnt=0;
		for(i=1;i<=n;i++) a[i].clear(),b[i].clear();
		while(m--)
		{
			scanf("%d%d",&i,&j);
			a[i].push_back(j);
			b[j].push_back(i);
		}
		scc();
		printf("%d\n",cnt);
	}
	return  0;
}